import os
import re
from tree_sitter import Language, Parser
import tree_sitter_java as tspython
import textwrap

# 加载 Python 语言
PY_LANGUAGE = Language(tspython.language())

# 创建解析器并设置语言为 Python
parser = Parser(PY_LANGUAGE)
def extract_class_structure_with_treesitter(class_code, class_name):
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


# 递归查找并提取方法
def find_methods(node, java_code):
    methods = []
    # 遍历当前节点的所有子节点
    for child in node.children:
        # 如果当前节点是方法声明，则提取方法
        if child.type == 'method_declaration':
            method_code = java_code[child.start_byte:child.end_byte]
            method_name = child.child_by_field_name('name').text.decode('utf-8')
            methods.append((method_name, method_code))
            print(f'[DEBUG] 提取方法: {method_name}')
        else:
            # 如果不是方法声明，递归地检查子节点
            methods.extend(find_methods(child, java_code))

    return methods


# 提取方法的主函数
def extract_methods_with_treesitter(java_code, file_name):
    print(f'[DEBUG] 处理文件: {file_name}')
    tree = parser.parse(java_code.encode())
    root_node = tree.root_node

    # 从根节点开始遍历，查找方法
    methods = find_methods(root_node, java_code)
    if not methods:
        print('[DEBUG] 未找到任何方法.')

    return methods


# 使用栈匹配大括号并将方法插入到主类的大括号内部
def merge_class_and_methods(class_structure, methods, main_class_body_range):
    if not methods:
        print('[DEBUG] 没有方法需要插入.')
        return class_structure

    start_byte, end_byte = main_class_body_range
    class_body = class_structure[start_byte:end_byte]

    # 使用栈匹配大括号来找到主类的结束大括号位置
    stack = []
    insert_pos = -1
    for i, char in enumerate(class_body):
        if char == '{':
            stack.append('{')
        elif char == '}':
            if stack:
                stack.pop()
            if not stack:  # 当栈为空时，找到匹配的结束大括号
                insert_pos = i + start_byte  # 全局位置
                break

    if insert_pos == -1:
        print('[DEBUG] 无法找到主类中的正确插入位置.')
        return class_structure

    print(f'[DEBUG] 找到插入位置: {insert_pos}')

    # 合并类的框架和方法体
    methods_code = '\n'.join([method_code for _, method_code in methods])
    new_class_content = class_structure[:insert_pos] + '\n' + methods_code + '\n' + class_structure[insert_pos:]
    print(f'[DEBUG] 将方法合并到类中:\n{new_class_content}')

    return new_class_content


# 处理文件夹中的主类和其他方法
def process_folders(input_folder, output_folder):
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    for subdir, _, files in os.walk(input_folder):
        class_name = os.path.basename(subdir)
        class_file_path = os.path.join(subdir, class_name + '.java')
        methods = []

        # 找到类文件并处理主类
        if os.path.exists(class_file_path):
            # 解决编码问题，使用 utf-8 读取文件
            with open(class_file_path, 'r', encoding='utf-8') as class_file:
                class_code = class_file.read()
            # 保留文件的所有内容，但删除主类中的实例方法
            modified_code, main_class_body_range = extract_class_structure_with_treesitter(class_code, class_name)

            # 遍历其他 Java 文件提取方法体
            for file_name in files:
                if file_name != class_name + '.java' and file_name.endswith('.java'):
                    with open(os.path.join(subdir, file_name), 'r', encoding='utf-8') as method_file:
                        java_code = method_file.read()
                    methods.extend(extract_methods_with_treesitter(java_code, file_name))  # 提取方法

            # 合并主类框架和提取的方法
            merged_content = merge_class_and_methods(modified_code, methods, main_class_body_range)

            # 输出修改后的文件到指定文件夹
            output_class_file = os.path.join(output_folder, class_name + '.java')
            with open(output_class_file, 'w', encoding='utf-8') as output_file:
                output_file.write(merged_content)
            print(f'[DEBUG] 处理完成的类: {class_name}')
        else:
            print(f'[DEBUG] 在 {subdir} 中未找到类文件 {class_name}')


# 调用函数进行处理
input_folder = 'cpp3java'  # 输入文件夹路径
output_folder = 'cpp3java_merge'  # 输出文件夹路径
process_folders(input_folder, output_folder)
