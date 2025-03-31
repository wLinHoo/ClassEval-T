import os
import openai
import re
import time
def translate_code_snippets(src_dir, dest_dir, target_language, api_key):
    # 初始化 OpenAI 客户端
    openai.api_key = api_key
    openai.api_base = "https://api.deepseek.com"

    # 遍历源目录
    for root, dirs, files in os.walk(src_dir):
        # 在目标目录中重建目录结构
        dest_root = os.path.join(dest_dir, os.path.relpath(root, src_dir))
        os.makedirs(dest_root, exist_ok=True)

        for file in files:
            src_file_path = os.path.join(root, file)

            # 读取代码片段
            with open(src_file_path, 'r', encoding='utf-8') as f:
                code_snippet = f.read()

            # 根据文件扩展名确定源语言
            src_extension = os.path.splitext(file)[1].lower()
            if src_extension == '.py':
                source_language = 'Python'
            elif src_extension == '.java':
                source_language = 'Java'
            elif src_extension in [ '.h']:
                source_language = 'C++'
            else:
                # 跳过不支持的文件
                continue

            # 如果源语言和目标语言相同，跳过
            if source_language.lower() == target_language.lower():
                continue

            # 确定目标语言的文件扩展名
            if target_language.lower() == 'python':
                target_extension = '.py'
                target_language1 = 'python'
            elif target_language.lower() == 'java':
                target_extension = '.java'
                target_language1 = 'java'
            elif target_language.lower() == 'c++':
                target_extension = '.cpp'
                target_language1 = 'cpp'
            else:
                # 不支持的目标语言
                print(f"不支持的目标语言：{target_language}")
                return

            # 构建目标文件路径
            dest_file_name = os.path.splitext(file)[0] + target_extension
            dest_file_path = os.path.join(dest_root, dest_file_name)

            # 如果目标文件已存在，跳过
            if os.path.exists(dest_file_path):
                print(f"目标文件已存在，跳过：{dest_file_path}")
                continue

            # 准备 API 的用户提示
            prompt = f"Translate the following {source_language} code to {target_language}：\n\n```{source_language.lower()}\n{code_snippet}\n```"

            # 调用 API
            try:
                response = openai.ChatCompletion.create(
                    model="deepseek-chat",
                    messages=[
                        {"role": "system", "content": "You are a helpful assistant"},
                        {"role": "user", "content": prompt},
                    ],
                    stream=False
                )

                # 获取 API 的响应内容
                output_content = response.choices[0].message.content

                # 从 Markdown 输出中提取代码块
                code_block_pattern = rf"```{target_language1}\n([\s\S]*?)\n```"
                match = re.search(code_block_pattern, output_content, re.IGNORECASE)
                if match:
                    translated_code = match.group(1)
                else:
                    # 如果未找到代码块，则使用整个输出内容
                    translated_code = output_content

                # 保存翻译后的代码
                with open(dest_file_path, 'w', encoding='utf-8') as f:
                    f.write(translated_code)

                print(f"已将 {src_file_path} 翻译并保存到 {dest_file_path}")

            except Exception as e:
                print(f"翻译 {src_file_path} 时出错：{e}")


def retry_translate_code_snippets(source_dir, target_dir, target_language, api_key, max_retries=10, delay=5):
    retries = 0
    while retries < max_retries:
        try:
            translate_code_snippets(source_dir, target_dir, target_language, api_key)
            #print(f"Translation from {source_dir} to {target_dir} completed successfully.")
            break  # 如果成功，跳出循环
        except Exception as e:
            retries += 1
            print(f"Error occurred during translation from {source_dir} to {target_dir}: {e}")
            if retries < max_retries:
                print(f"Retrying in {delay} seconds...")
                time.sleep(delay)
            else:
                print(f"Max retries reached. Translation from {source_dir} to {target_dir} failed.")

# 示例用法
retry_translate_code_snippets('py', 'py2java', 'Java', 'sk-xxxxxxxxxxx')
