#include"total.h"

inline void json_1(const std::string& write_path)
{
    std::ifstream file("tmp.txt");
    if (!file.is_open())
    {
        std::cerr << "�޷����ļ�" << std::endl;
        return;
    }

    std::string line;
    int total_tests = 0;
    int passed_tests = 0;
    std::vector<std::string> failed_test_cases;
    bool start = false, compile = false;
    std::regex pattern(R"(\[\----------\]\s+\d+\s+test[s]?\s+from\s+(\w+)Test(?:\w*)?)");
    std::smatch match;
    std::string class_name;
    while (std::getline(file, line))
    {
        if (std::regex_search(line, match, pattern) && class_name.empty())
        {
            class_name = match[1];
        }
        if (line == "[----------] Global test environment tear-down")
        {
            start = true;
            compile = true;
        }
        else if (line.find("[==========]") != std::string::npos)
        {
            // �ҵ��ܲ�����
            compile = true;
            size_t pos = line.find("Running ");
            size_t endPos = line.find(" tests", pos);
            if (pos != std::string::npos && endPos != std::string::npos)
            {
                total_tests = safe_stoi(line.substr(pos + 8, endPos - (pos + 8)));
            }
        }
        else if (start && line.find("[  PASSED  ]") != std::string::npos && line.find("tests.") != std::string::npos)
        {
            // �ҵ�ͨ��������
            compile = true;
            size_t pos = line.find("[  PASSED  ] ");
            if (pos != std::string::npos)
            {
                passed_tests = safe_stoi(line.substr(pos + 13));
            }
        }
        else if (start && line.find("[  FAILED  ]") != std::string::npos)
        {
            // �ҵ�������ͨ���Ĳ�������
            compile = true;
            if (line.find("tests, listed below:") == std::string::npos &&
                line.find("test, listed below:") == std::string::npos)
            {
                failed_test_cases.push_back(line.substr(13)); // ����"[  FAILED  ] "����
            }
        }
    }

    file.close();

    // ����JSON����
    nlohmann::json test_results;
    if (compile)
    {
        test_results["num_tot"] = total_tests;
        test_results["num_pass"] = passed_tests;
        test_results["num_fail"] = total_tests - passed_tests;
        test_results["class_name"] = class_name;
        test_results["test_cases_failed"] = failed_test_cases;
    }
    else
    {
        test_results["compilation_result"] = compile;
        std::regex pattern_2(R"((\w+)Test(?:\w*)?)"); // ƥ�� Test ǰ��� xxx������ Test �������ַ�
        std::string class_name2;
        std::ifstream file("tmp.txt");
        while (std::getline(file, line))
        {
            if (std::regex_search(line, match, pattern_2) && class_name2.empty())
            {
                //std::cout << match[1] << std::endl;
                class_name2 = match[1];
            }
        }
        test_results["class_name"] = class_name2;
        std::ifstream file2(test_file);
        int failnum = 0;
        while (std::getline(file2, line))
        {
            if (strstr(line.c_str(), "TEST_F"))
            {
                failnum++;
            }
        }
        test_results["num_tot"] = failnum;
        test_results["num_fail"] = failnum;
        test_results["num_pass"] = 0;
    }

    // д��JSONL�ļ�
    std::string jsonl_path = write_path + "\\" + "results.jsonl";
    std::ofstream jsonl_file(jsonl_path, std::ios::app);
    if (jsonl_file.is_open())
    {
        jsonl_file << test_results.dump() << std::endl; // д��һ��JSON
        jsonl_file.close();

    }
    else
    {
        std::cerr << "�޷�����JSONL�ļ�" << std::endl;
    }
}