import os
import qianfan

# 设置Qianfan API密钥
os.environ["QIANFAN_ACCESS_KEY"] = "xxxxxxxxxxxxxx"
os.environ["QIANFAN_SECRET_KEY"] = "xxxxxxxxxxxx"

# 初始化Qianfan大模型
chat_comp = qianfan.ChatCompletion()

# 定义输入和输出文件夹路径
input_folder = "solution_py"  # 替换为实际的Python文件夹路径
output_folder = "py2cpp"  # 替换为目标输出文件夹路径

# 如果输出文件夹不存在，创建该文件夹
if not os.path.exists(output_folder):
    os.makedirs(output_folder)

# 遍历输入文件夹中的所有Python文件
for filename in os.listdir(input_folder):
    if filename.endswith(".py"):  # 仅处理Python文件
        output_filename = os.path.splitext(filename)[0] + ".cpp"  # 目标文件名

        # 检查目标文件夹中是否已有相同名称的文件
        if os.path.exists(os.path.join(output_folder, output_filename)):
            print(f"Skipping {filename}, already translated.")
            continue

        # 读取Python文件内容
        with open(os.path.join(input_folder, filename), 'r', encoding='utf-8') as file:
            python_code = file.read()

        # 调用Qianfan大模型进行代码转换（C++）
        conversion_target = "C++"
        resp = chat_comp.do(model="Meta-Llama-3-70B", messages=[{
            "role": "user",
            "content": f"Translate the following Python code to {conversion_target}:\n\n{python_code}"
        }],temperature=0.8,top_p=0.95)

        # 获取转换后的代码
        translated_code = resp["body"]["result"]

        # 将转换后的代码保存到目标文件夹中
        with open(os.path.join(output_folder, output_filename), 'w', encoding='utf-8') as output_file:
            output_file.write(translated_code)

        print(f"Translated {filename} to {output_filename} and saved to {output_folder}")

print("All files have been processed.")
