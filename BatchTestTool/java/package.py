import os


def add_package_to_java_files(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".java"):
                file_path = os.path.join(root, file)
                try:
                    # 读取文件内容
                    with open(file_path, 'r', encoding='utf-8') as f:
                        content = f.readlines()

                    # 插入新包声明到第一行
                    new_content = []
                    new_content.append("package to_be_tested;\n\n")  # 添加空行保持格式
                    new_content.extend(content)

                    # 写入修改后的内容
                    with open(file_path, 'w', encoding='utf-8') as f:
                        f.writelines(new_content)

                    print(f"Updated: {file_path}")

                except Exception as e:
                    print(f"Error processing {file_path}: {str(e)}")


if __name__ == "__main__":
    # 设置目标目录 (修改为你的Java代码目录)
    target_dir = "C:/Users/admin\Desktop\java/111/untitled2\Test/to_be_tested"
    add_package_to_java_files(target_dir)