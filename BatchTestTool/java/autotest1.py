import pyautogui
import pytesseract
import cv2
import numpy as np
from datetime import datetime
import time
import os
import re
from difflib import get_close_matches

# 配置Tesseract路径（根据实际情况修改）
pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'

# 预配置文件名列表（去掉.java后缀）
original_filenames = [
    "AccessGatewayFilterTest", "AreaCalculatorTest", "ArgumentParserTest",
    "ArrangementCalculatorTest", "AssessmentSystemTest", "AutomaticGuitarSimulatorTest",
    "AvgPartitionTest", "BalancedBracketsTest", "BankAccountTest", "BigNumCalculatorTest",
    "BinaryDataProcessorTest", "BitStatusUtilTest", "BlackjackGameTest", "BookManagementDBTest",
    "BookManagementTest", "BoyerMooreSearchTest", "CalculatorTest", "CalendarUtilTest",
    "CamelCaseMapTest", "ChandrasekharSieveTest", "ChatTest", "ClassRegistrationSystemTest",
    "ClassroomTest", "CombinationCalculatorTest", "ComplexCalculatorTest", "CookiesUtilTest",
    "CSVProcessorTest", "CurrencyConverterTest", "DatabaseProcessorTest", "DataStatistics2Test",
    "DataStatistics4Test", "DataStatisticsTest", "DecryptionUtilsTest", "DiscountStrategyTest",
    "EightPuzzleTest", "EmailClientTest", "EncryptionUtilsTest", "ExcelProcessorTest",
    "ExpressionCalculatorTest", "FitnessTrackerTest", "GomokuGameTest", "HotelTest",
    "HRManagementSystemTest", "InterpolationTest", "IPAddressTest", "IpUtilTest",
    "JobMarketplaceTest", "JSONProcessorTest", "KappaCalculatorTest", "LongestWordTest",
    "MahjongConnectTest", "ManacherTest", "MetricsCalculator2Test", "MetricsCalculatorTest",
    "MovieBookingSystemTest", "MovieTicketDBTest", "MusicPlayerTest", "NLPDataProcessor2Test",
    "NLPDataProcessorTest", "NumberConverterTest", "NumberWordFormatterTest",
    "NumericEntityUnescaperTest", "OrderTest", "PageUtilTest", "PersonRequestTest",
    "PushBoxGameTest", "RegexUtilsTest", "RPGCharacterTest", "ServerTest", "ShoppingCartTest",
    "SignInSystemTest", "SnakeTest", "SplitSentenceTest", "SQLGeneratorTest", "SQLQueryBuilderTest",
    "Statistics3Test", "StockPortfolioTrackerTest", "StudentDatabaseProcessorTest",
    "TextFileProcessorTest", "ThermostatTest", "TicTacToeTest", "TimeUtilsTest", "TriCalculatorTest",
    "TwentyFourPointGameTest", "URLHandlerTest", "UrlPathTest", "UserLoginDBTest",
    "VectorUtilTest", "VendingMachineTest", "WarehouseTest", "WeatherSystemTest",
    "Words2NumbersTest", "XMLProcessorTest", "ZipFileProcessorTest"
]

# 屏幕区域配置
TEXT_DETECTION_REGION = (189, 1167, 400, 300)
TEXT_RECORD_REGION = (1008, 248, 800, 50)
OUTPUT_FOLDER = r'D:\LLMS search\ISTTA大修\recorded_texts'
CHECK_INTERVAL = 2


def preprocess_image(image):
    """优化代码识别的预处理"""
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    # 增强对比度
    clahe = cv2.createCLAHE(clipLimit=3.0, tileGridSize=(8, 8))
    enhanced = clahe.apply(gray)
    # 二值化处理
    _, thresh = cv2.threshold(enhanced, 150, 255, cv2.THRESH_BINARY)
    return thresh


def match_classname(text):
    """从文本中匹配类名并查找最相似文件名"""
    # 使用正则表达式匹配类声明
    match = re.search(r'public class (\w+)', text)
    if not match:
        return None

    class_name = match.group(1)
    # 使用模糊匹配查找最接近的文件名
    matches = get_close_matches(class_name, original_filenames, n=1, cutoff=0.7)
    return matches[0] + ".java" if matches else None

def safe_hotkey():
    """安全的热键操作函数（新增）"""
    try:
        pyautogui.hotkey('ctrl', 'f4')
        time.sleep(0.8)  # 确保窗口关闭完成
        print("成功执行 Ctrl+F4 操作")
        return True
    except pyautogui.FailSafeException:
        print("安全警告：鼠标位于屏幕角落，触发保护机制")
        return False
    except Exception as e:
        print(f"热键操作异常：{str(e)}")
        return False

def monitor_process(cycles=94):
    os.makedirs(OUTPUT_FOLDER, exist_ok=True)
    merged_file = os.path.join(OUTPUT_FOLDER, 'class_matching_log.txt')

    # 新增清空日志文件的逻辑（使用'w'模式覆盖）
    with open(merged_file, 'w', encoding='utf-8') as f:
        f.write("")  # 写入空内容清空文件

    print(f"启动类名匹配监控，共执行 {cycles} 次操作")
    for i in range(cycles):
        print(f"\n正在处理第 {i + 1} 次操作")
        time.sleep(CHECK_INTERVAL)

        try:
            # 检测区域处理
            detection_img = np.array(pyautogui.screenshot(region=TEXT_DETECTION_REGION))
            processed_detect = preprocess_image(detection_img)

            # 使用更适合代码识别的配置
            detect_config = r'--oem 3 --psm 6 -l eng'
            detection_text = pytesseract.image_to_string(processed_detect, config=detect_config)

            if not detection_text.strip():
                # 记录区域处理
                record_img = np.array(pyautogui.screenshot(region=TEXT_RECORD_REGION))
                processed_record = preprocess_image(record_img)

                # 优化代码识别的OCR配置
                record_config = r'--oem 3 --psm 6 -l eng'
                record_text = pytesseract.image_to_string(processed_record, config=record_config)

                # 匹配类名
                matched_file = match_classname(record_text)
                status = matched_file if matched_file else "未匹配到有效类名"

                # 记录日志（保持追加模式）
                timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
                log_content = f"""操作次数: {i + 1}
记录时间: {timestamp}
匹配结果: {status}
原始内容: {record_text.strip() or '无有效内容'}
------------------------
"""
                with open(merged_file, 'a', encoding='utf-8') as f:
                    f.write(log_content)

                # 执行热键操作
                safe_hotkey()

            else:
                print(f"检测到内容，跳过记录: {detection_text[:30]}...")
                safe_hotkey()

        except Exception as e:
            print(f"操作异常: {str(e)[:100]}")
            safe_hotkey()

    print("\n类名匹配任务完成")

# 其他原有函数保持相同（safe_hotkey等）

if __name__ == "__main__":
    monitor_process(cycles=94)