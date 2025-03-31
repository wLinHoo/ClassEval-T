import os
import shutil
import re

def extract_class_names(text_file):
    """从文本文件中提取所有类名"""
    class_names = []
    with open(text_file, 'r', encoding='utf-8') as f:
        for line in f:
            # 增强正则表达式匹配能力
            match = re.search(r'\b(?:class|public\s+class)\s+(\w+)', line)
            if match:
                class_names.append(match.group(1))
    return list(set(class_names))  # 去重处理

def copy_files(class_names, main_source, test_source, target_main_dir, target_test_dir):
    """将主类和测试类分别复制到不同目录（主类缺失时不复制测试类）"""
    os.makedirs(target_main_dir, exist_ok=True)
    os.makedirs(target_test_dir, exist_ok=True)

    test_classes = [name for name in class_names if name.endswith("Test")]
    copied_pairs = 0
    error_log = []

    for test_class in test_classes:
        base_class = test_class[:-4] if test_class.endswith("Test") else test_class
        main_class_src = os.path.join(main_source, f"{base_class}.java")
        test_class_src = os.path.join(test_source, f"{test_class}.java")

        # 第一步：检查主类是否存在
        if not os.path.exists(main_class_src):
            error_log.append(f"主类缺失，跳过测试类: {base_class}.java → {test_class}.java")
            continue  # 跳过后续操作

        main_class_dst = os.path.join(target_main_dir, f"{base_class}.java")
        test_class_dst = os.path.join(target_test_dir, f"{test_class}.java")

        main_copied = False
        test_copied = False

        try:
            # 第二步：尝试复制主类
            shutil.copy2(main_class_src, main_class_dst)
            main_copied = True
            print(f"已复制主类: {base_class}.java -> {target_main_dir}")

            # 第三步：主类复制成功后检查测试类
            if os.path.exists(test_class_src):
                shutil.copy2(test_class_src, test_class_dst)
                test_copied = True
                print(f"已复制测试类: {test_class}.java -> {target_test_dir}")
                copied_pairs += 1  # 只有主类和测试类都复制成功才算配对
            else:
                error_log.append(f"测试类缺失: {test_class}.java")
                # 回滚已复制的主类
                if main_copied:
                    os.remove(main_class_dst)
                    print(f"已回滚主类: {base_class}.java")

        except Exception as e:
            # 异常处理时回滚文件
            if main_copied and os.path.exists(main_class_dst):
                os.remove(main_class_dst)
            if test_copied and os.path.exists(test_class_dst):
                os.remove(test_class_dst)
            error_log.append(f"复制失败 {base_class}：{str(e)}")

    # 输出统计报告
    print(f"\n操作完成统计:")
    print(f"成功复制配对数量: {copied_pairs}")
    print(f"失败/缺失情况: {len(error_log)}")

    if error_log:
        print("\n详细错误信息:")
        for error in error_log:
            print(f" - {error}")

# 配置路径参数（保持相同）
text_file = r'D:\LLMS search\ISTTA大修\recorded_texts\class_matching_log.txt'
main_source_dir = r'C:\Users\admin\Desktop\java\111\untitled2\Test\to_be_tested'
test_source_dir = r'C:\Users\admin\Desktop\java\111\untitled2\Test\test_cases'
target_main_dir = r'C:\Users\admin\Desktop\java\111\untitled3\src\main\java'
target_test_dir = r'C:\Users\admin\Desktop\java\111\untitled3\src\test\java'

# 执行复制操作
all_classes = extract_class_names(text_file)
copy_files(all_classes, main_source_dir, test_source_dir, target_main_dir, target_test_dir)