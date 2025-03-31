import os
import re
from tree_sitter import Language, Parser
import tree_sitter_cpp as tscpp

# 加载 C++ 语言
CPP_LANGUAGE = Language(tscpp.language())

# 创建解析器并设置语言为 C++
parser = Parser(CPP_LANGUAGE)


def remove_class_scope(code):
    # 匹配并移除自定义类范围（如 AssessmentSystem::），保留 std:: 和 boost:: 前缀
    return re.sub(r'\b(?!std::|boost::)\w+::', '', code)



def normalize_name(name):
    # 如果name以" const"结尾，去掉它
    if name.endswith(' const') or name.endswith(' throw'):
        name = name[:-6]  # 去掉结尾的" const"

    # 使用正则表达式将非字母和数字字符替换为空字符
    pattern = r'::([^:]+)$'

    # 使用正则表达式进行匹配
    match = re.search(pattern, name)
    if match:
        cleaned_text = re.sub(r'[^a-zA-Z0-9]', '', match.group(1))
    else:
        cleaned_text = re.sub(r'[^a-zA-Z0-9]', '', name)

    # 将文本转为小写
    lowercase_text = cleaned_text.lower()
    return lowercase_text


def extract_function_bodies(node, source_code, functions, target_function_name):
    """
    根据节点提取与文件名模糊匹配的函数体，增加调试输出。
    """
    if node.type == "function_definition":
        func_name_node = node.child_by_field_name('declarator')
        if func_name_node is not None:
            func_name = source_code[func_name_node.start_byte:func_name_node.end_byte].decode('utf8')
            func_name1 = re.sub(r'\([^)]*\)', '', func_name)
            normalized_func_name = normalize_name(func_name1)  # 标准化函数名

            #print(f"[DEBUG] 发现函数: {func_name1}")

            if normalized_func_name == target_function_name:
                function_body = source_code[node.start_byte:node.end_byte].decode('utf8')
                function_body = remove_class_scope(function_body)
                functions.append(function_body)
                return  # 只提取与文件名模糊匹配的函数
    for child in node.children:
        extract_function_bodies(child, source_code, functions, target_function_name)


def extract_functions_from_file(file_path, target_function_name):
    """
    从文件中提取与文件名模糊匹配的函数定义，并增加调试信息。
    """
    #print(f"处理文件: {file_path}")
    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
        source_code = f.read()

    source_code_bytes = source_code.encode('utf8')
    tree = parser.parse(source_code_bytes)
    root_node = tree.root_node

    functions = []
    extract_function_bodies(root_node, source_code_bytes, functions, target_function_name)

    if not functions:
        print(f"{file_path} : 未找到与文件名 {target_function_name} 对应的函数。")
    #else:
    #print(f"提取的函数: {functions}")

    return functions


def generate_function_declarations(functions):
    """
    根据函数体生成对应的函数声明。
    """
    declarations = []
    for func in functions:
        # 查找函数定义的第一行作为声明
        first_line = func.strip().split('\n')[0]
        if first_line.endswith('{'):
            first_line = first_line[:-1].strip() + ';'  # 将 '{' 替换为 ';'
        declarations.append(first_line)
    return declarations


def insert_declarations_after_public(class_code, declarations):
    """
    将函数声明插入到类的 public 部分下面。
    """
    public_pos = class_code.find('public:')
    if public_pos == -1:
        class_end_pattern = r'(};\s*)$'

        # 将函数列表转换为单个字符串，确保每个函数占一行
        # 这里使用 re.escape 来避免转义字符引发的错误
        functions_code = '\n'.join([re.escape(func) for func in declarations])

        # 使用正则表达式查找类定义的结束部分，并在结束花括号之前插入所有函数代码
        modified_code = re.sub(class_end_pattern, f'{functions_code}\n\\1', class_code)

        return modified_code

    # 查找 public: 后的第一行，用于插入声明
    insertion_pos = class_code.find('\n', public_pos) + 1
    new_class_code = class_code[:insertion_pos] + '\n'.join(declarations) + '\n' + class_code[insertion_pos:]
    return new_class_code


def insert_functions_at_file_end(file_code, functions):
    """
    将函数插入到文件的末尾。
    """
    return file_code + '\n\n' + '\n\n'.join(functions) + '\n'


def remove_prefix(a, b):
    prefix = f"{a}_"
    if b.startswith(prefix):
        return b[len(prefix):]
    return b


def process_folder(main_folder, output_folder):
    """
    处理主文件夹，将函数声明插入到类的 public 部分下面，并将函数插入到文件的末尾。
    """
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    for class_name in os.listdir(main_folder):
        subfolder_path = os.path.join(main_folder, class_name)
        if os.path.isdir(subfolder_path):
            class_file_name = f"{class_name}.cpp"  # 假设主类定义在 .cpp 文件中
            class_file_path = os.path.join(subfolder_path, class_file_name)

            if not os.path.exists(class_file_path):
                print(f"类文件 {class_file_name} 在 {subfolder_path} 中不存在，跳过该文件夹。")
                continue

            # 读取主类代码
            with open(class_file_path, 'r', encoding='utf-8', errors='ignore') as f:
                class_code = f.read()

            # 提取与文件名模糊匹配的函数
            functions = []
            for file_name in os.listdir(subfolder_path):
                if file_name.endswith('.cpp') and file_name != class_file_name:
                    file_path = os.path.join(subfolder_path, file_name)
                    real_file_name = remove_prefix(class_name, file_name)
                    function_name = normalize_name(os.path.splitext(real_file_name)[0])  # 标准化文件名作为函数名
                    #print(f"[DEBUG] 尝试匹配函数 {function_name} ...")
                    funcs = extract_functions_from_file(file_path, function_name)
                    functions.extend(funcs)

            # 如果找到函数，将声明插入到 public 下面，函数体插入文件末尾
            if functions:
                # 插入声明到类 public 部分下

                new_class_code = insert_declarations_after_public(class_code, functions)

                # 保存到输出文件夹
                output_subfolder = os.path.join(output_folder, class_name)
                if not os.path.exists(output_subfolder):
                    os.makedirs(output_subfolder)
                output_file_path = os.path.join(output_subfolder, class_file_name)

                with open(output_file_path, 'w', encoding='utf-8', errors='ignore') as f:
                    f.write(new_class_code)

                #print(f"已处理类 {class_name}，生成的新文件位于 {output_file_path}")
            else:
                print(f"类 {class_name} 中没有插入任何函数。")


# 设置主文件夹和输出文件夹的路径
main_folder = "path_main"  # 替换为您的主文件夹路径
out_folder = "path_out"
for sub_name in os.listdir(main_folder):
    sub_path = os.path.join(main_folder, sub_name)
    sub_out_path = os.path.join(out_folder, sub_name)
    if os.path.isdir(sub_path):
        process_folder(sub_path, sub_out_path)
