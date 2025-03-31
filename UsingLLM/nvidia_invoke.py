import os
import openai

# 设置DeepSeek API密钥
openai.api_key = "nvapi-xxxxxxxxxxxxxxxxxxxxxxxx"
openai.api_base = "https://integrate.api.nvidia.com/v1"

# 定义输入和输出文件夹路径
input_folder = "cpp"  # 替换为实际的文件夹路径
output_folder = "java"  # 替换为目标输出文件夹路径

# 如果输出文件夹不存在，创建该文件夹
if not os.path.exists(output_folder):
    os.makedirs(output_folder)

def translate_file(filename):
    with open(os.path.join(input_folder, filename), 'r', encoding='utf-8') as file:
        python_code = file.read()

    # 调用DeepSeek API进行代码转换
    response = openai.ChatCompletion.create(
        model="google/gemma-7b",
        messages=[
            {"role": "system", "content": "You are a helpful assistant."},
            {"role": "user", "content": f"Translate the following C++ code to Java:\n\n{python_code}"}
        ],
        temperature=0.8,  # Adjust the temperature value as needed
        top_p=0.95,        # Adjust the top_p value as needed
        #top_k=50           # Adjust the top_k value as needed
        max_tokens=1000,
    )

    # 获取转换后的代码
    translated_code = response.choices[0].message.content

    # 将转换后的代码保存到目标文件夹中
    output_filename = os.path.splitext(filename)[0] + ".java"
    with open(os.path.join(output_folder, output_filename), 'w', encoding='utf-8') as output_file:
        output_file.write(translated_code)

    return f"Translated {filename} to {output_filename} and saved to {output_folder}"

# 按顺序处理每个Python文件
for filename in os.listdir(input_folder):
    if filename.endswith(".h"):  # 仅处理Python文件
        output_filename = os.path.splitext(filename)[0] + ".py"
        output_path = os.path.join(output_folder, output_filename)

        # 检查目标文件夹中是否已有同名文件
        if os.path.exists(output_path):
            print(f"Skipping {filename}, already translated.")
            continue

        # 如果没有同名文件，则进行翻译
        result = translate_file(filename)
        print(result)

print("All files have been processed.")
