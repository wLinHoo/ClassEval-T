#include"total.h"

inline void copyCppFiles(const std::string& jsonlFilePath, const std::string& sourceFolder, const std::string& destinationFolder) {
    // 打开result_solution.jsonl文件
    std::ifstream jsonlFile(jsonlFilePath);
    if (!jsonlFile.is_open()) {
        std::cerr << "Failed to open JSONL file: " << jsonlFilePath << std::endl;
        return;
    }

    // 创建目标文件夹，如果不存在则创建
    if (!fs::exists(destinationFolder)) {
        fs::create_directory(destinationFolder);
    }

    std::string line;
    // 逐行读取jsonl文件
    while (std::getline(jsonlFile, line)) {
        try {
            // 解析每一行的 JSON 数据
            auto jsonObject = json::parse(line);
            std::string compileStatus = jsonObject["compile"];
            std::string cppName = jsonObject["cppName"];

            // 判断 compile 是否为 Success
            if (compileStatus == "Success") {
                std::string sourceCppFile = sourceFolder + "/" + cppName + ".cpp";
                std::string destinationCppFile = destinationFolder + "/" + cppName + ".cpp";

                // 复制文件
                if (fs::exists(sourceCppFile)) {
                    try {
                        fs::copy(sourceCppFile, destinationCppFile, fs::copy_options::overwrite_existing);
                        //std::cout << "Copied: " << sourceCppFile << " to " << destinationCppFile << std::endl;
                    }
                    catch (fs::filesystem_error& e) {
                        std::cerr << "Error copying file " << sourceCppFile << ": " << e.what() << std::endl;
                    }
                }
                else {
                    std::cerr << "Source file does not exist: " << sourceCppFile << std::endl;
                }
            }
        }
        catch (json::parse_error& e) {
            std::cerr << "JSON parse error: " << e.what() << std::endl;
            continue;
        }
    }

    jsonlFile.close();
}

inline void copyMatchingTests(const std::string& folder1, const std::string& folder2, const std::string& folder3) {
    if (!fs::exists(folder3)) {
        fs::create_directory(folder3);
    }

    // 遍历文件夹1中的所有.cpp文件
    for (const auto& entry : fs::directory_iterator(folder1)) {
        if (entry.is_regular_file() && entry.path().extension() == ".cpp") {
            std::string filename = entry.path().filename().stem().string();  // 获取文件名（不带扩展名）
            std::string targetFilename = "test_" + filename + ".cpp";  // 在文件夹2中寻找对应的文件

            // 检查文件夹2中是否存在对应的文件
            fs::path sourceFile = folder2 + "/" + targetFilename;
            if (fs::exists(sourceFile)) {
                fs::path destinationFile = folder3 + "/" + targetFilename;

                try {
                    // 复制文件到文件夹3
                    fs::copy(sourceFile, destinationFile, fs::copy_options::overwrite_existing);
                    //std::cout << "Copied: " << sourceFile << " to " << destinationFile << std::endl;
                }
                catch (const fs::filesystem_error& e) {
                    std::cerr << "Error copying file: " << e.what() << " " << folder1 << std::endl;
                }
            }
            else {
                std::cout << "File not found in folder2: " << targetFilename << " " << folder1 << std::endl;
            }
        }
    }
}

inline void extract()
{
    std::string from_dir = "Test\\to_be_tested";
    std::string tot_dir = "Test\\compile_passed";
    if (!fs::exists(tot_dir)) {
        fs::create_directory(tot_dir);
    }
    std::string tot_dir_solution = "Test\\compile_passed\\solution";
    for (const auto& entry : fs::directory_iterator(from_dir)) {
        if (fs::is_directory(entry))
        {
            std::string sourceFolder = entry.path().string();
            std::string jsonlFilePath = sourceFolder + "\\result\\result_solution.jsonl";
            std::string solution_dir = tot_dir + "\\solution";
            if (!fs::exists(solution_dir)) {
                fs::create_directory(solution_dir);
            }
            std::size_t pos = sourceFolder.find_last_of("\\/");
            std::string folder_name = sourceFolder.substr(pos + 1);
            std::string realEnd = solution_dir + "\\" + folder_name;
            copyCppFiles(jsonlFilePath, sourceFolder, realEnd);
        }
    }

    std::string test_folder = "Test\\test_gt";
    for (const auto& entry : fs::directory_iterator(tot_dir_solution)) {
        if (fs::is_directory(entry))
        {
            std::string sourceFolder = entry.path().string();
            std::string test_dir = tot_dir + "\\test";
            if (!fs::exists(test_dir)) {
                fs::create_directory(test_dir);
            }
            std::size_t pos = sourceFolder.find_last_of("\\/");
            std::string folder_name = sourceFolder.substr(pos + 1);
            std::string realEnd = test_dir + "\\" + folder_name;
            copyMatchingTests(sourceFolder, test_folder, realEnd);
        }
    }
}


