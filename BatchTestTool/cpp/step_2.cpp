#include "total.h"
#include "json1.cpp"
#include "json2.cpp"

namespace fs = std::filesystem;

inline void extractClassNames(const std::string& inputFilePath, const std::string& outputFilePath) {

    std::ifstream inputFile(inputFilePath);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file: " << inputFilePath << std::endl;
        return;
    }


    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        std::cerr << "Failed to open the output file: " << outputFilePath << std::endl;
        return;
    }


    std::regex classRegex(R"(class\s+(\w+)\s*:\s*public\s*::testing::Test\s*)");

    std::string line;
    while (std::getline(inputFile, line)) {
        std::smatch match;

        if (std::regex_search(line, match, classRegex)) {
            if (match.size() > 1) {

                outputFile << match[1] << std::endl;
            }
        }
    }


    inputFile.close();
    outputFile.close();
}

inline void read_files_in_order(const std::string& write_path, const std::string& directory_path1, const std::string& directory_path2, const std::string& output_file_path1, const std::string& output_file_path2)
{
    try {
        std::vector<fs::path> files1;
        std::vector<fs::path> files2;


        for (const auto& entry : fs::directory_iterator(directory_path1)) {
            if (fs::is_regular_file(entry.status())) {
                files1.push_back(entry.path());
            }
        }
        for (const auto& entry : fs::directory_iterator(directory_path2)) {
            if (fs::is_regular_file(entry.status())) {
                files2.push_back(entry.path());
            }
        }


        std::sort(files1.begin(), files1.end());
        std::sort(files2.begin(), files2.end());


        for (int i = 0; i < min(files1.size(), files2.size()); ++i)
        {
            auto& solution_path = files1[i];
            auto& test_path = files2[i];

            std::ifstream solution(solution_path);
            if (!solution.is_open()) {
                std::cerr << "无法打开文件: " << solution_path << std::endl;
                continue;
            }
            std::ifstream test(test_path);
            if (!test.is_open()) {
                std::cerr << "无法打开文件: " << test_path << std::endl;
                continue;
            }


            std::ofstream output_file1(output_file_path1, std::ios::trunc);
            if (!output_file1.is_open()) {
                std::cerr << "无法打开输出文件: " << output_file_path1 << std::endl;
                return;
            }
            std::ofstream output_file2(output_file_path2, std::ios::trunc);
            if (!output_file2.is_open()) {
                std::cerr << "无法打开输出文件: " << output_file_path2 << std::endl;
                return;
            }

            string adds = "#include<bits/stdc++.h>\nusing namespace std;\n";

            output_file1 << adds << solution.rdbuf();
            output_file2 << test.rdbuf();
            output_file1.close();
            output_file2.close();
            test.close();
            solution.close();
            clearFile("tmp.txt");
            int res = build_project();
            //system("pause");
            std::ifstream file("tmp.txt");
            string linee;
            bool isNormal = 0;
            while (std::getline(file, linee))
            {
                if (linee == "[----------] Global test environment tear-down")
                {
                    isNormal = 1;
                    break;
                }
            }
            if (!isNormal)
            {
                file.close();
                extractClassNames(test_file, "tmp.txt");
            }
            json_1(write_path);
            json_2(write_path);
            file.close();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "发生错误: " << e.what() << std::endl;
    }
}

inline int step_2() {

    std::string output_file_path1 = solution_file; // 输出文件路径
    std::string output_file_path2 = test_file; // 输出文件路径

    std::string tot_path = "Test\\compile_passed";
    
    std::string solution_path = tot_path + "\\solution";
    std::string test_path = tot_path + "\\test";
    std::string result_path = tot_path + "\\result";
    if (!fs::exists(result_path)) {
        fs::create_directory(result_path);
    }
    for (auto& entry : fs::directory_iterator(solution_path))
    {
        std::string Folder = entry.path().string();
        std::size_t pos = Folder.find_last_of("\\/");
        std::string folder_name = Folder.substr(pos + 1);
        std::string nowSolution = solution_path + "\\" + folder_name;
        std::string nowTest = test_path + "\\" + folder_name;
        std::string nowResult = result_path + "\\" + folder_name;
        if (!fs::exists(nowResult)) {
            fs::create_directory(nowResult);
        }
        read_files_in_order(nowResult, nowSolution, nowTest, output_file_path1, output_file_path2);
    }
    return 0;
}
