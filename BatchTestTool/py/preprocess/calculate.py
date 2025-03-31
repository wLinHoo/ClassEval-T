import json

# 读取 JSON 文件
def load_json_file(file_path):
    with open(file_path, 'r', encoding='utf-8') as f:
        data = json.load(f)
    return data

# 计算单个子字典的 success 比例的函数
def calculate_success_ratio_for_class(class_eval_value):
    total_tests = 0
    success_tests = 0

    # 遍历子字典中的每个字段
    for test_key, test_value in class_eval_value.items():
        # 跳过名称是 "TestClass" 或者以 "TEST" 或 "MAIN" 结尾的键
        if test_key == "TestClass" or test_key.endswith("Test") or test_key.endswith("Main"):
            continue

        # 获取该字段的 success 值
        success_count = test_value.get("success", 0)

        # 更新总测试次数
        total_tests += 1

        # 如果 success 大于 0，认为该测试成功
        if success_count > 0:
            success_tests += 1

    # 计算 success 占比
    if total_tests > 0:
        success_ratio = success_tests / total_tests
    else:
        success_ratio = 0

    return success_ratio, success_tests, total_tests

# 主函数：从 JSON 文件加载数据、计算 success 比例并将结果写入 txt 文件
def main():
    # 这里替换为你的 JSON 文件路径
    file_path = r"detailed_result.json"
    # 输出文件路径
    output_file_path = r"success_ratio_report.txt"

    # 加载 JSON 数据
    data = load_json_file(file_path)
    model_output = data.get("model_output", {})

    # 全局计数器，用于计算总的成功比例
    total_tests_global = 0
    success_tests_global = 0

    # 打开一个文件来写入结果
    with open(output_file_path, 'w', encoding='utf-8') as output_file:
        # 遍历每个子字典，如 ClassEval_0, ClassEval_1
        for class_eval_key, class_eval_value in model_output.items():
            success_ratio, success_tests, total_tests = calculate_success_ratio_for_class(class_eval_value)

            # 累加到全局计数器
            total_tests_global += total_tests
            success_tests_global += success_tests

            # 输出每个子字典的结果到文件
            output_file.write(f"{class_eval_key}:\n")
            output_file.write(f"成功的测试数: {success_tests}\n")
            output_file.write(f"总的测试数: {total_tests}\n")
            output_file.write(f"成功比例: {success_ratio:.2%}\n\n")

            # 同时在控制台打印每个子字典的结果
            print(f"{class_eval_key}:")
            print(f"成功的测试数: {success_tests}")
            print(f"总的测试数: {total_tests}")
            print(f"成功比例: {success_ratio:.2%}")
            print()

        # 计算全局成功比例
        if total_tests_global > 0:
            global_success_ratio = success_tests_global / total_tests_global
        else:
            global_success_ratio = 0

        # 将全局结果写入文件
        output_file.write(f"总的成功测试数: {success_tests_global}\n")
        output_file.write(f"总的测试数: {total_tests_global}\n")
        output_file.write(f"总的成功比例: {global_success_ratio:.2%}\n")

        # 同时在控制台打印全局结果
        print(f"总的成功测试数: {success_tests_global}")
        print(f"总的测试数: {total_tests_global}")
        print(f"总的成功比例: {global_success_ratio:.2%}")

    print(f"所有结果已写入文件: {output_file_path}")

# 执行主函数
if __name__ == "__main__":
    main()
