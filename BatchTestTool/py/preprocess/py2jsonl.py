import os
import json

# 设定你的文件夹路径
folder_path = r"your_fold_path"  # 替换为你的文件夹路径

# 存储所有文件内容的字典
data = {}

# 遍历文件夹中的所有文件
for filename in os.listdir(folder_path):
    # 只处理 .py 文件
    if filename.endswith('.py'):
        # 去除文件的后缀名，保留前缀作为字典的键
        file_key = os.path.splitext(filename)[0]

        # 构建文件的完整路径
        file_path = os.path.join(folder_path, filename)

        # 读取文件内容，并确保保留换行符
        with open(file_path, 'r', encoding='utf-8') as file:
            file_content = file.read()  # 保留代码的换行符

        # 将文件内容添加到字典中
        data[file_key] = file_content

# 将结果保存为 JSON 文件
output_path = r"output.jsonl"
with open(output_path, 'w', encoding='utf-8') as json_file:
    json.dump(data, json_file, ensure_ascii=False, indent=4)

print(f"处理完成，结果已存储到 {output_path}")
