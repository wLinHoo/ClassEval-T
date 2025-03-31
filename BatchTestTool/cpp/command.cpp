#include"total.h"

// 函数：提取并显示错误信息
inline std::vector<std::string> extractErrors(const std::string& output) {
    size_t pos = 0;
    std::vector<std::string> ans;
    std::string keyword = "error";
    while ((pos = output.find(keyword, pos)) != std::string::npos) {
        size_t lineEnd = output.find("\n", pos);
        std::string errorLine = output.substr(pos, lineEnd - pos);
        //std::cout << "Error: " << errorLine << std::endl;
        ans.push_back(errorLine);
        pos = lineEnd;
    }
    return ans;
}

inline void load_json(int result, std::filesystem::path filepath)
{
    nlohmann::json test_results;
    std::string filename = filepath.filename().string();
    std::vector<std::string> error_message;
    test_results["cppName"] = filename.substr(0, filename.length() - 4);
    if (result) {
        std::string output = readFileContent("tmp.txt");
        extractErrors(output);
        error_message = extractErrors(output);  // 只提取并显示错误信息
        error_message.erase(error_message.begin());
        //std::cout << output << std::endl;
        test_results["errors"] = error_message;
        test_results["compile"] = "Fail";
    }
    else
    {
        test_results["compile"] = "Success";
        test_results["errors"] = error_message;
    }

    std::string jsonl_filepath = filepath.parent_path().string() + "\\result\\result_solution.jsonl";
    //std::cout << jsonl_filepath << std::endl;
    std::ofstream jsonl_file(jsonl_filepath, std::ios::app);
    if (jsonl_file.is_open())
    {
        jsonl_file << test_results.dump() << std::endl;
        jsonl_file.close();

    }
    else
    {
        std::cerr << "无法创建JSONL文件" << std::endl;
    }
}
