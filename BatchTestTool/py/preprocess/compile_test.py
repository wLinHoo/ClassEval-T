import os
import json
import subprocess

def execute_python_files(directory, output_file):
    results = []
    total_files = 0
    successful_files = 0

    # 遍历指定目录下的所有文件（不遍历子目录）
    for file in os.listdir(directory):
        if file.endswith(".py"):
            total_files += 1
            file_path = os.path.join(directory, file)
            result = {
                "file": file_path,
                "status": "success",
                "output": "",
                "error": ""
            }

            try:
                # 使用subprocess.Popen执行Python文件
                process = subprocess.Popen(
                    ["python", file_path],
                    stdout=subprocess.PIPE,
                    stderr=subprocess.PIPE,
                    text=True
                )
                stdout, stderr = process.communicate(timeout=20)  # 设置超时时间，防止无限循环
                result["output"] = stdout
                result["error"] = stderr
                if process.returncode == 0:
                    successful_files += 1  # 计数成功编译的文件
                else:
                    result["status"] = "error"
            except subprocess.TimeoutExpired as e:
                result["status"] = "timeout"
                result["error"] = str(e)
            except subprocess.CalledProcessError as e:
                result["status"] = "error"
                result["error"] = str(e)
            except Exception as e:
                result["status"] = "error"
                result["error"] = str(e)

            # 将结果写入JSON Lines文件
            with open(output_file, "a") as f:
                f.write(json.dumps(result) + "\n")

            results.append(result)

    # 计算成功率
    success_rate = (successful_files / total_files) * 100 if total_files > 0 else 0
    print("编译测试:")
    print(f"Total files: {total_files}")
    print(f"Successful files: {successful_files}")
    print(f"Success rate: {success_rate:.2f}%")

    return results

if __name__ == "__main__":
    directory = r"your_folder_path"  # 替换为你要遍历的目录
    output_file = r"execution_results.jsonl"  # 输出文件名

    execute_python_files(directory, output_file)
    print(f"Execution results have been saved to {output_file}")
