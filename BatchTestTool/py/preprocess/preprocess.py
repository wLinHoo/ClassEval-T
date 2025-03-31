import json

ground_path = r"output\model_output\model_output_ground.json"
input_path = r"output.json"
output_path = r"model_output.json"

# 读取第一个JSON文件
with open(ground_path, 'r', encoding='utf-8') as file1:
    data1 = json.load(file1)

# 读取第二个JSON文件
with open(input_path, 'r', encoding='utf-8') as file2:
    data2 = json.load(file2)

# 遍历第一个JSON中的列表，检查class_name是否在第二个JSON中匹配
for item in data1:
    class_name = item.get('class_name')  # 获取class_name
    if class_name in data2:  # 如果第二个JSON中的键匹配class_name
        item['predict'] = [data2[class_name]]  # 替换predict字段的内容

# 将修改后的结果保存到新的JSON文件
with open(output_path, 'w', encoding='utf-8') as updated_file:
    json.dump(data1, updated_file, ensure_ascii=False, indent=4)

print("处理完成，结果已保存")
