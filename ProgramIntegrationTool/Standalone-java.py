import os
import re
from tree_sitter import Language, Parser
import tree_sitter_java as tsjava
import textwrap

# 加载 Java 语言
JAVA_LANGUAGE = Language(tsjava.language())

# 创建解析器并设置语言为 Java
parser = Parser(JAVA_LANGUAGE)

def normalize_name(name):
    # 使用正则表达式将非字母和数字字符替换为空字符
    cleaned_text = re.sub(r'[^a-zA-Z0-9]', '', name)
    # 将文本转为小写
    lowercase_text = cleaned_text.lower()
    return lowercase_text

def extract_function_bodies(node, java_code, target_function_name):
    """
    从节点中提取与文件名模糊匹配的函数体。
    """
    if node.type == 'method_declaration':
        method_name_node = node.child_by_field_name('name')
        if method_name_node is not None:
            method_name = java_code[method_name_node.start_byte:method_name_node.end_byte].decode('utf-8')
            normalized_method_name = normalize_name(method_name)
            if normalized_method_name == target_function_name:
                method_code = java_code[node.start_byte:node.end_byte].decode('utf-8')
                print(f"[DEBUG] 找到与文件名模糊匹配的函数: {method_name}")
                return method_code
    for child in node.children:
        result = extract_function_bodies(child, java_code, target_function_name)
        if result:
            return result
    return None


def extract_function_from_file(file_path, target_function_name):
    """
    从文件中提取与文件名模糊匹配的函数。
    """
    print(f"[DEBUG] 处理文件: {file_path}")
    with open(file_path, 'r', encoding='utf-8') as f:
        java_code = f.read()

    java_code_bytes = java_code.encode('utf-8')
    tree = parser.parse(java_code_bytes)
    root_node = tree.root_node

    method_code = extract_function_bodies(root_node, java_code_bytes, target_function_name)

    if method_code:
        print(f"[DEBUG] 提取到的方法代码:\n{method_code}")
    else:
        print(f"[DEBUG] 未找到与文件名模糊匹配的函数: {target_function_name}")

    return method_code


def extract_class_structure_with_treesitter(class_code, class_name):
    """
    提取类结构并删除指定的实例方法。
    """
    tree = parser.parse(class_code.encode())
    root_node = tree.root_node
    modified_code = class_code  # 初始为完整代码
    methods_to_remove = []
    main_class_body_range = None
    first_class_body = None  # 记录第一个找到的类体
    first_class_name = None  # 记录第一个找到的类名

    # 遍历 AST 查找类的声明
    for child in root_node.children:
        if child.type == 'class_declaration':
            class_identifier = child.child_by_field_name('name').text.decode('utf-8')

            # 如果找到了指定的主类
            if class_identifier == class_name:
                print(f'[DEBUG] 找到指定的主类: {class_identifier}')
                class_body = child.child_by_field_name('body')
                if class_body:
                    main_class_body_range = (class_body.start_byte, class_body.end_byte)
                else:
                    print(f'[DEBUG] 无法找到主类 {class_name} 的类体')
                    continue

                # 遍历类体，查找方法
                for element in class_body.children:
                    if element.type == 'method_declaration':
                        modifiers = element.child_by_field_name('modifiers')
                        is_static = False
                        if modifiers:
                            for modifier in modifiers.children:
                                if modifier.text.decode('utf-8') == 'static':
                                    is_static = True
                                    break
                        if not is_static:
                            methods_to_remove.append((element.start_byte, element.end_byte))
                            method_name = element.child_by_field_name('name').text.decode('utf-8')
                            print(f'[DEBUG] 找到需要删除的实例方法: {method_name}')
                break  # 找到主类后可以退出循环

            # 如果没有找到主类，记录第一个类的类体和类名
            if not first_class_body:
                print(f'[DEBUG] 记录第一个类: {class_identifier}')
                first_class_body = child.child_by_field_name('body')
                first_class_name = class_identifier

    # 如果没有找到指定的主类，使用第一个类作为默认主类
    if main_class_body_range is None and first_class_body is not None:
        print(f'[DEBUG] 未找到指定的主类 {class_name}，使用第一个类 {first_class_name} 作为默认主类')
        main_class_body_range = (first_class_body.start_byte, first_class_body.end_byte)

        # 遍历第一个类，查找实例方法
        for element in first_class_body.children:
            if element.type == 'method_declaration':
                modifiers = element.child_by_field_name('modifiers')
                is_static = False
                if modifiers:
                    for modifier in modifiers.children:
                        if modifier.text.decode('utf-8') == 'static':
                            is_static = True
                            break
                if not is_static:
                    methods_to_remove.append((element.start_byte, element.end_byte))
                    method_name = element.child_by_field_name('name').text.decode('utf-8')
                    print(f'[DEBUG] 找到默认主类中需要删除的实例方法: {method_name}')

    if main_class_body_range is None:
        print(f'[ERROR] 无法找到任何类体.')
        return modified_code, None

    # 删除主类中的实例方法
    print(f'[DEBUG] 正在从类中删除 {len(methods_to_remove)} 个实例方法.')
    for start_byte, end_byte in sorted(methods_to_remove, reverse=True):
        print(f'[DEBUG] 删除方法位置从 {start_byte} 到 {end_byte}')
        modified_code = modified_code[:start_byte] + modified_code[end_byte:]

    print(f'[DEBUG] 修改后的类结构:\n{modified_code}')
    return modified_code, main_class_body_range


def insert_methods_into_class(class_code, methods, main_class_body_range):
    """
    将函数插入主类中，放置到合适的位置。
    """
    if not methods:
        print("[DEBUG] 没有方法需要插入.")
        return class_code

    start_byte, end_byte = main_class_body_range
    class_body = class_code[start_byte:end_byte]

    # 使用栈匹配大括号，找到类体的结束大括号
    stack = []
    insert_pos = -1
    for i, char in enumerate(class_body):
        if char == '{':
            stack.append('{')
        elif char == '}':
            if stack:
                stack.pop()
            if not stack:  # 栈为空，表示找到类体的结束位置
                insert_pos = i + start_byte
                break

    if insert_pos == -1:
        print("[DEBUG] 未找到插入位置.")
        return class_code

    print(f"[DEBUG] 在位置 {insert_pos} 插入方法.")

    # 将提取的方法插入到类体的最后一个大括号前
    methods_code = '\n'.join([method_code for method_code in methods])
    new_class_content = class_code[:insert_pos] + '\n' + methods_code + '\n' + class_code[insert_pos:]

    return new_class_content


def process_folders(input_folder, output_folder):
    """
    处理文件夹中的主类和其他方法文件，只提取与文件名模糊匹配的函数。
    """
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    for subdir, _, files in os.walk(input_folder):
        class_name = os.path.basename(subdir)
        class_file_path = os.path.join(subdir, class_name + '.java')
        methods = []

        # 处理主类文件
        if os.path.exists(class_file_path):
            # 读取主类文件
            with open(class_file_path, 'r', encoding='utf-8') as class_file:
                class_code = class_file.read()
            modified_code, main_class_body_range = extract_class_structure_with_treesitter(class_code, class_name)

            # 提取其他文件中的方法
            for file_name in files:
                if file_name != class_name + '.java' and file_name.endswith('.java'):
                    function_name = normalize_name(os.path.splitext(file_name)[0])
                    print(function_name)# 文件名标准化
                    method_code = extract_function_from_file(os.path.join(subdir, file_name), function_name)
                    if method_code:
                        methods.append(method_code)

            # 将提取的方法插入主类中
            if methods:
                new_class_content = insert_methods_into_class(modified_code, methods, main_class_body_range)

                # 输出到指定文件夹
                output_class_file = os.path.join(output_folder, class_name + '.java')
                with open(output_class_file, 'w', encoding='utf-8') as output_file:
                    output_file.write(new_class_content)
                print(f"[DEBUG] 已处理类 {class_name}，生成的新文件位于 {output_class_file}")
            else:
                print(f"[DEBUG] 类 {class_name} 中没有插入任何方法.")
        else:
            print(f"[DEBUG] 未找到类文件 {class_name}.java 在 {subdir} 中.")


# 设置输入和输出文件夹路径
input_folder = "codegemma\py2java"  # 输入文件夹路径
output_folder = "cpp2java_merge"  # 输出文件夹路径

process_folders(input_folder, output_folder)
