#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <nlohmann/json.hpp>  
#include <codecvt>
#include <cstdlib> // For std::system
#include <regex>
#include <array>
#include <memory>
#include <stdexcept>
#include <vector>
#include <unordered_set>
#include <map>
#include <stack>
namespace fs = std::filesystem;
using json = nlohmann::json;
using namespace std;

const string solution_file = "D:\\C++ programs\\project\\Sample-Test3\\Sample-Test3\\pch.h";
const string test_file = "D:\\C++ programs\\project\\Sample-Test3\\Sample-Test3\\test.cpp";



inline void clearFile(const std::string& filePath) {
    // 以覆盖模式打开文件
    std::ofstream file(filePath, std::ios::trunc);
    if (!file) {
        std::cerr << "无法打开文件: " << filePath << std::endl;
    }
    // 文件打开成功，文件内容被清空
    std::cout << "文件内容已清空: " << filePath << std::endl;
    file.close();
}

inline bool isFileEmpty(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary); // 以二进制模式打开文件

    if (file.is_open())
    {
        // 将文件指针移动到文件末尾
        file.seekg(0, std::ios::end);
        // 获取文件当前指针的位置（即文件大小）
        std::streampos fileSize = file.tellg();
        file.close();         // 关闭文件
        return fileSize == 0; // 文件大小为0则文件为空
    }
    else
    {
        std::cerr << "无法打开文件: " << filename << std::endl;
        return false; // 无法打开文件时返回false（可以根据需求更改为true或抛出异常）
    }
}
inline int safe_stoi(const std::string& str)
{
    try
    {
        return std::stoi(str);
    }
    catch (const std::invalid_argument&)
    {
        std::cerr << "错误: '" << str << "' 不是有效的整数。" << std::endl;
        return 0;
    }
}

// 函数：运行命令并将输出重定向到文件
inline int runCommandAndCaptureOutput(const std::string& command, const std::string& outputFile) {
    std::string fullCommand = "chcp 65001 & " + command + " > " + outputFile + " 2>&1" + " && exit";
    return std::system(fullCommand.c_str());
}

inline int build_project()
{
    std::string vs_cmd_prompt = "\"D:\\Visual Studio 2022\\Community\\Common7\\Tools\\VsDevCmd.bat\"";

    // 切换目录和编译运行命令
    std::string cd_to_project = "cd /d \"D:\\C++ programs\\project\\Sample-Test3\"";
    std::string cd_to_build = "cd /d \"D:\\C++ programs\\project\\Sample-Test3\\x64\\Debug\"";
    std::string build_command = "msbuild Sample-Test3.sln /p:Configuration=Debug /p:Platform=x64";
    std::string print_command = "Sample-Test3.exe";

    std::string command = "cmd /c \"" + vs_cmd_prompt + " && " + cd_to_project + " && " + build_command + " && " + cd_to_build + " && " + print_command + "\"";

    // 执行命令
    int result = runCommandAndCaptureOutput(command.c_str(), "tmp.txt");

    return result;
}

// 函数：读取文件内容并返回为字符串
inline std::string readFileContent(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string content((std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());
    return content;
}