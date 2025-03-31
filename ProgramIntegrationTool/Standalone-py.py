import os
import re
from tree_sitter import Language, Parser
import tree_sitter_python as tspython
import textwrap

# 加载 Python 语言
PY_LANGUAGE = Language(tspython.language())

# 创建解析器并设置语言为 Python
parser = Parser(PY_LANGUAGE)


def normalize_name(name):
    # 使用正则表达式将非字母和数字字符替换为空字符
    cleaned_text = re.sub(r'[^a-zA-Z0-9]', '', name)
    # 将文本转为小写
    lowercase_text = cleaned_text.lower()
    return lowercase_text


def extract_function_bodies(node, source_code, functions, target_function_name):
    """
    根据节点提取与文件名模糊匹配的函数体。
    """
    if node.type == "function_definition" or node.type == "decorated_definition":
        func_name_node = node.child_by_field_name('name')
        if func_name_node is not None:
            func_name = source_code[func_name_node.start_byte:func_name_node.end_byte].decode('utf8')
            normalized_func_name = normalize_name(func_name)  # 标准化函数名

            if normalized_func_name == target_function_name:
                function_body = source_code[node.start_byte:node.end_byte].decode('utf8')
                functions.append(function_body)
                print(f"提取函数体: {function_body}")
                return  # 只提取与文件名模糊匹配的函数
    for child in node.children:
        extract_function_bodies(child, source_code, functions, target_function_name)


def extract_functions_from_file(file_path, target_function_name):
    """
    从文件中提取与文件名模糊匹配的函数定义。
    """
    print(f"处理文件: {file_path}")
    with open(file_path, 'r', encoding='utf-8') as f:
        source_code = f.read()

    source_code_bytes = source_code.encode('utf8')
    tree = parser.parse(source_code_bytes)
    root_node = tree.root_node

    functions = []
    extract_function_bodies(root_node, source_code_bytes, functions, target_function_name)

    if not functions:
        print(f"未找到与文件名 {target_function_name} 对应的函数。")
    else:
        print(f"提取的函数: {functions}")

    return functions


def insert_functions_into_class(class_code, functions, class_name):
    """
    将函数列表插入到主类中。
    """
    source_code_bytes = class_code.encode('utf8')
    tree = parser.parse(source_code_bytes)
    root_node = tree.root_node

    # 查找类定义节点
    class_node = None
    for node in root_node.children:
        if node.type == 'class_definition':
            name_node = node.child_by_field_name('name')
            if name_node is not None:
                name = source_code_bytes[name_node.start_byte:name_node.end_byte].decode('utf8')
                if name == class_name:
                    class_node = node
                    break

    if class_node is None:
        print(f"未找到类 {class_name}，直接添加函数到类定义外部。")
        return class_code + '\n' + '\n'.join(functions)

    # 获取类体的 body 节点
    body_node = class_node.child_by_field_name('body')
    if not body_node:
        print(f"类 {class_name} 没有主体，直接在类定义后添加函数。")
        return class_code + '\n' + '\n'.join(functions)

    # 获取类体代码及缩进
    class_body_code = source_code_bytes[body_node.start_byte:body_node.end_byte].decode('utf8')
    body_lines = class_body_code.split('\n')
    body_indentation = ''
    for line in body_lines:
        if line.strip():
            body_indentation = re.match(r'^(\s*)', line).group(1)
            break

    # 插入函数
    new_class_body_code = class_body_code.rstrip() + '\n' + '\n'.join(
        [textwrap.indent(func, body_indentation + '    ') for func in functions]) + '\n'

    # 重建类代码
    class_header_code = source_code_bytes[class_node.start_byte:body_node.start_byte].decode('utf8')
    before_class_code = source_code_bytes[:class_node.start_byte].decode('utf8')
    after_class_code = source_code_bytes[class_node.end_byte:].decode('utf8')

    final_code = before_class_code + class_header_code + new_class_body_code + after_class_code
    return final_code


def process_folder(main_folder, output_folder):
    """
    处理主文件夹，将函数插入指定类中并输出到新文件夹。
    """
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    for class_name in os.listdir(main_folder):
        subfolder_path = os.path.join(main_folder, class_name)
        if os.path.isdir(subfolder_path):
            class_file_name = f"{class_name}.py"
            class_file_path = os.path.join(subfolder_path, class_file_name)

            if not os.path.exists(class_file_path):
                print(f"类文件 {class_file_name} 在 {subfolder_path} 中不存在，跳过该文件夹。")
                continue

            # 读取主类代码
            with open(class_file_path, 'r', encoding='utf-8') as f:
                class_code = f.read()

            # 提取与文件名模糊匹配的函数
            functions = []
            for file_name in os.listdir(subfolder_path):
                if file_name.endswith('.py') and file_name != class_file_name:
                    file_path = os.path.join(subfolder_path, file_name)
                    function_name = normalize_name(os.path.splitext(file_name)[0])  # 标准化文件名作为函数名
                    funcs = extract_functions_from_file(file_path, function_name)
                    functions.extend(funcs)

            # 将函数插入主类
            if functions:
                new_class_code = insert_functions_into_class(class_code, functions, class_name)

                # 保存到输出文件夹
                output_subfolder = os.path.join(output_folder, class_name)
                if not os.path.exists(output_subfolder):
                    os.makedirs(output_subfolder)
                output_file_path = os.path.join(output_subfolder, class_file_name)

                with open(output_file_path, 'w', encoding='utf-8') as f:
                    f.write(new_class_code)

                print(f"已处理类 {class_name}，生成的新文件位于 {output_file_path}")
            else:
                print(f"类 {class_name} 中没有插入任何函数。")


# 设置主文件夹和输出文件夹的路径
main_folder = "cpp2py"  # 替换为您的主文件夹路径
output_folder = "cpp2py_merge"  # 替换为您的输出文件夹路径

process_folder(main_folder, output_folder)
