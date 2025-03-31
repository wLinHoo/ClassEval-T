import os
import re
from tree_sitter import Language, Parser
import tree_sitter_python as tspython
import textwrap

# 加载 Python 语言
PY_LANGUAGE = Language(tspython.language())
# 创建解析器并设置语言为 Python
parser = Parser(PY_LANGUAGE)

def extract_function_bodies(node, source_code, functions):
    if node.type == "function_definition" or node.type == "decorated_definition":
        function_body = source_code[node.start_byte:node.end_byte].decode('utf8')
        functions.append(function_body)
    for child in node.children:
        extract_function_bodies(child, source_code, functions)


def extract_functions_from_file(file_path):
    """
    从给定的 Python 文件中提取所有函数定义。
    """
    with open(file_path, 'r', encoding='utf-8') as f:
        source_code = f.read()

    source_code_bytes = source_code.encode('utf8')
    tree = parser.parse(source_code_bytes)
    root_node = tree.root_node

    functions = []
    extract_function_bodies(root_node, source_code_bytes, functions)
    return functions


def find_class_node(root_node, class_name, source_code_bytes):
    """
    在语法树中查找指定名称的类节点。
    """
    for node in root_node.children:
        if node.type == 'class_definition':
            name_node = node.child_by_field_name('name')
            if name_node:
                name = source_code_bytes[name_node.start_byte:name_node.end_byte].decode('utf8')
                if name == class_name:
                    return node
    return None


def remove_instance_methods_from_class(class_code, class_name):
    """
    删除指定类中所有的实例方法，除了特殊方法（例如 __init__）。
    """
    source_code_bytes = class_code.encode('utf8')
    tree = parser.parse(source_code_bytes)
    root_node = tree.root_node

    # 查找指定名称的类定义节点
    class_node = find_class_node(root_node, class_name, source_code_bytes)
    if not class_node:
        # 没有找到类定义，返回原始代码
        return class_code

    # 获取类代码，包括类头和类体
    class_code_full = source_code_bytes[class_node.start_byte:class_node.end_byte].decode('utf8')

    # 获取类体的 body 节点
    body_node = class_node.child_by_field_name('body')
    if not body_node:
        # 没有找到类的主体，返回原始代码
        return class_code

    # 获取类头代码
    class_header_code = source_code_bytes[class_node.start_byte:body_node.start_byte].decode('utf8')

    # 获取类体代码
    class_body_code = source_code_bytes[body_node.start_byte:body_node.end_byte].decode('utf8')

    # 获取类体缩进
    body_lines = class_body_code.split('\n')
    body_indentation = ''
    for line in body_lines:
        if line.strip():
            body_indentation = re.match(r'^(\s*)', line).group(1)
            break

    # 处理类体，保留特殊方法和非函数的内容
    # 解析类体代码
    body_source_bytes = class_body_code.encode('utf8')
    body_tree = parser.parse(body_source_bytes)
    body_root_node = body_tree.root_node

    new_body_statements = []

    for child in body_root_node.children:
        node_to_check = child
        # 处理装饰器
        if child.type == 'decorated_definition':
            node_to_check = child.named_children[-1]

        if node_to_check.type == 'function_definition':
            # 获取函数名
            func_name_node = node_to_check.child_by_field_name('name')
            func_name = body_source_bytes[func_name_node.start_byte:func_name_node.end_byte].decode('utf8')
            if func_name in ['__init__', '__str__', '__repr__', '__call__']:
                # 保留特殊方法
                method_code = body_source_bytes[child.start_byte:child.end_byte].decode('utf8')
                new_body_statements.append(method_code)
            else:
                # 删除普通实例方法
                continue
        else:
            # 保留非函数的内容（如类变量）
            statement_code = body_source_bytes[child.start_byte:child.end_byte].decode('utf8')
            new_body_statements.append(statement_code)

    # 重新构建类体代码
    new_class_body_code = ''
    for statement in new_body_statements:
        # 去除多余缩进，然后重新缩进
        dedented_statement = textwrap.dedent(statement)
        indented_statement = textwrap.indent(dedented_statement, body_indentation)
        new_class_body_code += indented_statement + '\n'

    # 重新构建类代码
    new_class_code = class_header_code + new_class_body_code

    # 替换原始类代码
    before_class_code = source_code_bytes[:class_node.start_byte].decode('utf8')
    after_class_code = source_code_bytes[class_node.end_byte:].decode('utf8')

    final_code = before_class_code + new_class_code + after_class_code

    return final_code

def insert_functions_into_class(class_code, functions, class_name):
    """
    将函数列表插入到指定类的代码中，保证缩进合理，避免重复特殊方法。
    """
    source_code_bytes = class_code.encode('utf8')
    tree = parser.parse(source_code_bytes)
    root_node = tree.root_node

    # 查找指定名称的类定义节点
    class_node = find_class_node(root_node, class_name, source_code_bytes)
    if not class_node:
        # 没有找到类定义，直接在末尾添加函数
        class_code += '\n' + '\n'.join(functions)
        return class_code

    # 获取类代码，包括类头和类体
    class_code_full = source_code_bytes[class_node.start_byte:class_node.end_byte].decode('utf8')

    # 获取类体的 body 节点
    body_node = class_node.child_by_field_name('body')
    if not body_node:
        # 没有找到类的主体，直接在类定义后添加函数
        class_code += '\n' + '\n'.join(functions)
        return class_code

    # 获取类头代码
    class_header_code = source_code_bytes[class_node.start_byte:body_node.start_byte].decode('utf8')

    # 获取类体代码
    class_body_code = source_code_bytes[body_node.start_byte:body_node.end_byte].decode('utf8')

    # 获取类体缩进
    body_lines = class_body_code.split('\n')
    body_indentation = ''
    for line in body_lines:
        if line.strip():
            body_indentation = re.match(r'^(\s*)', line).group(1)
            break

    # 获取已存在的方法名，避免重复
    body_source_bytes = class_body_code.encode('utf8')
    body_tree = parser.parse(body_source_bytes)
    body_root_node = body_tree.root_node

    existing_methods = set()
    for child in body_root_node.children:
        node_to_check = child
        # 处理装饰器
        if child.type == 'decorated_definition':
            node_to_check = child.named_children[-1]

        if node_to_check.type == 'function_definition':
            func_name_node = node_to_check.child_by_field_name('name')
            func_name = body_source_bytes[func_name_node.start_byte:func_name_node.end_byte].decode('utf8')
            existing_methods.add(func_name)

    # 调整函数的缩进，避免重复特殊方法
    adjusted_functions = []
    for func_body in functions:
        # 解析函数名
        func_source_bytes = func_body.encode('utf8')
        func_tree = parser.parse(func_source_bytes)
        func_root = func_tree.root_node

        func_def_node = None
        # 处理装饰器
        for node in func_root.named_children:
            if node.type == 'function_definition':
                func_def_node = node
                break
            elif node.type == 'decorated_definition':
                func_def_node = node.named_children[-1]
                break

        if not func_def_node or func_def_node.type != 'function_definition':
            continue  # 跳过非函数定义

        func_name_node = func_def_node.child_by_field_name('name')
        func_name = func_source_bytes[func_name_node.start_byte:func_name_node.end_byte].decode('utf8')

        if func_name in existing_methods and func_name in ['__init__', '__str__', '__repr__', '__call__']:
            continue  # 跳过重复的特殊方法
        existing_methods.add(func_name)

        # 去除多余缩进，然后重新缩进
        dedented_func = textwrap.dedent(func_body)
        indented_func = textwrap.indent(dedented_func, body_indentation + '    ')  # 额外增加缩进
        adjusted_functions.append(indented_func)

    # 在类体末尾插入新的函数
    new_class_body_code = class_body_code.rstrip() + '\n' + '\n'.join(adjusted_functions) + '\n'

    # 重新构建类代码
    new_class_code = class_header_code + new_class_body_code

    # 替换原始类代码
    before_class_code = source_code_bytes[:class_node.start_byte].decode('utf8')
    after_class_code = source_code_bytes[class_node.end_byte:].decode('utf8')

    final_code = before_class_code + new_class_code + after_class_code

    return final_code


def get_main_class_file(subfolder_path, class_name):
    """
    获取主类文件的路径。如果有 main1 文件优先选择 main1，否则选择文件夹名对应的文件。
    """
    main1_file = None
    class_file = None

    # 优先寻找 main1.* 文件
    for file_name in os.listdir(subfolder_path):
        if file_name.startswith('main1.') and file_name.endswith('.py'):
            main1_file = os.path.join(subfolder_path, file_name)
            break

    # 如果找不到 main1，则选择文件夹名对应的文件
    class_file_name = f"{class_name}.py"
    class_file = os.path.join(subfolder_path, class_file_name)

    if main1_file:
        return main1_file
    elif os.path.exists(class_file):
        return class_file
    else:
        return None


def process_folder(main_folder, output_folder):
    """
    处理主文件夹，将函数插入指定类中并输出到新文件夹。
    """
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    for class_name in os.listdir(main_folder):
        subfolder_path = os.path.join(main_folder, class_name)
        if os.path.isdir(subfolder_path):
            # 获取主类文件路径
            class_file_path = get_main_class_file(subfolder_path, class_name)

            if not class_file_path:
                print(f"在 {subfolder_path} 中找不到类文件，跳过该文件夹。")
                continue

            # 读取类的框架代码
            with open(class_file_path, 'r', encoding='utf-8') as f:
                class_code = f.read()

            # 先删除指定类中所有的实例函数（除特殊方法外）
            class_code = remove_instance_methods_from_class(class_code, class_name)

            # 收集函数文件中的所有函数
            functions = []
            for file_name in os.listdir(subfolder_path):
                if file_name.endswith('.py') and file_name != os.path.basename(class_file_path):
                    file_path = os.path.join(subfolder_path, file_name)
                    funcs = extract_functions_from_file(file_path)
                    functions.extend(funcs)

            # 将函数插入指定的类中
            new_class_code = insert_functions_into_class(class_code, functions, class_name)

            # 将新文件写入输出文件夹，文件名统一为文件夹名.py
            output_subfolder = os.path.join(output_folder, class_name)
            if not os.path.exists(output_subfolder):
                os.makedirs(output_subfolder)
            output_file_path = os.path.join(output_subfolder, f"{class_name}.py")

            with open(output_file_path, 'w', encoding='utf-8') as f:
                f.write(new_class_code)

            print(f"已处理类 {class_name}，生成的新文件位于 {output_file_path}")


# 设置主文件夹和输出文件夹的路径
main_folder = "cpp3py"   # 替换为您的主文件夹路径
output_folder = "cpp3py_merge"  # 替换为您的输出文件夹路径

process_folder(main_folder, output_folder)
