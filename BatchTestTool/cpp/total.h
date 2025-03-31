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
    // �Ը���ģʽ���ļ�
    std::ofstream file(filePath, std::ios::trunc);
    if (!file) {
        std::cerr << "�޷����ļ�: " << filePath << std::endl;
    }
    // �ļ��򿪳ɹ����ļ����ݱ����
    std::cout << "�ļ����������: " << filePath << std::endl;
    file.close();
}

inline bool isFileEmpty(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in | std::ios::binary); // �Զ�����ģʽ���ļ�

    if (file.is_open())
    {
        // ���ļ�ָ���ƶ����ļ�ĩβ
        file.seekg(0, std::ios::end);
        // ��ȡ�ļ���ǰָ���λ�ã����ļ���С��
        std::streampos fileSize = file.tellg();
        file.close();         // �ر��ļ�
        return fileSize == 0; // �ļ���СΪ0���ļ�Ϊ��
    }
    else
    {
        std::cerr << "�޷����ļ�: " << filename << std::endl;
        return false; // �޷����ļ�ʱ����false�����Ը����������Ϊtrue���׳��쳣��
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
        std::cerr << "����: '" << str << "' ������Ч��������" << std::endl;
        return 0;
    }
}

// �������������������ض����ļ�
inline int runCommandAndCaptureOutput(const std::string& command, const std::string& outputFile) {
    std::string fullCommand = "chcp 65001 & " + command + " > " + outputFile + " 2>&1" + " && exit";
    return std::system(fullCommand.c_str());
}

inline int build_project()
{
    std::string vs_cmd_prompt = "\"D:\\Visual Studio 2022\\Community\\Common7\\Tools\\VsDevCmd.bat\"";

    // �л�Ŀ¼�ͱ�����������
    std::string cd_to_project = "cd /d \"D:\\C++ programs\\project\\Sample-Test3\"";
    std::string cd_to_build = "cd /d \"D:\\C++ programs\\project\\Sample-Test3\\x64\\Debug\"";
    std::string build_command = "msbuild Sample-Test3.sln /p:Configuration=Debug /p:Platform=x64";
    std::string print_command = "Sample-Test3.exe";

    std::string command = "cmd /c \"" + vs_cmd_prompt + " && " + cd_to_project + " && " + build_command + " && " + cd_to_build + " && " + print_command + "\"";

    // ִ������
    int result = runCommandAndCaptureOutput(command.c_str(), "tmp.txt");

    return result;
}

// ��������ȡ�ļ����ݲ�����Ϊ�ַ���
inline std::string readFileContent(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string content((std::istreambuf_iterator<char>(file)),
        std::istreambuf_iterator<char>());
    return content;
}