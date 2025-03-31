import os
import shutil


def clear_code_files(directory):
    """清空指定目录及其子目录中的所有.java文件"""
    deleted_files = 0
    error_files = []

    # 验证目录是否存在
    if not os.path.exists(directory):
        print(f"警告：目录不存在 {directory}")
        return deleted_files, error_files

    try:
        # 递归遍历目录
        for root, dirs, files in os.walk(directory):
            for file in files:
                if file.endswith(".java"):
                    file_path = os.path.join(root, file)
                    try:
                        os.remove(file_path)
                        deleted_files += 1
                        print(f"已删除：{file_path}")
                    except Exception as e:
                        error_files.append((file_path, str(e)))
    except Exception as e:
        print(f"遍历目录失败：{directory}\n错误信息：{str(e)}")

    return deleted_files, error_files


def confirm_operation():
    """操作确认提示"""
    print("即将执行以下操作：")
    print(f"1. 清空目录：{target_main_dir}")
    print(f"2. 清空目录：{target_test_dir}")
    choice = input("\n确认执行操作吗？(y/n): ").lower()
    return choice == 'y'


if __name__ == "__main__":
    # 配置目标目录
    target_main_dir = r'C:\Users\admin\Desktop\java\111\untitled3\src\main\java'
    target_test_dir = r'C:\Users\admin\Desktop\java\111\untitled3\src\test\java'

    if not confirm_operation():
        print("操作已取消")
        exit()

    print("\n开始清理主代码目录...")
    main_deleted, main_errors = clear_code_files(target_main_dir)

    print("\n开始清理测试代码目录...")
    test_deleted, test_errors = clear_code_files(target_test_dir)

    # 输出统计报告
    print("\n清理完成统计：")
    print(f"主目录删除文件数：{main_deleted}")
    print(f"测试目录删除文件数：{test_deleted}")
    print(f"总删除文件数：{main_deleted + test_deleted}")
    print(f"失败操作数：{len(main_errors) + len(test_errors)}")

    # 显示错误详情
    if main_errors or test_errors:
        print("\n错误详情：")
        for path, err in main_errors + test_errors:
            print(f"- 文件：{path}")
            print(f"  错误：{err}")