#include "total.h"

inline stack<string> work1()
{
    ifstream file("tmp.txt");
    stack<string> tot;
    if (!file.is_open())
    {
        cout << "�޷����ļ�" << endl;
        return tot;
    }

    string line;
    // ƥ�� "[----------] N test[s] from suiteName"
    regex suiteRegex(R"(\[\----------\] (\d+) test(?:s)? from (\w+))");
    smatch match;
    unordered_set<string> processedSuites; // ���ڸ����Ѵ���Ĳ����׼�
    map<string, int> suiteTestCounts;      // ��������ÿ�������׼������ֺͶ�Ӧ�Ĳ�����
    while (getline(file, line))
    {
        if (regex_search(line, match, suiteRegex))
        {
            // ��ȡ�����׼����ֺͲ�������
            int testCount = stoi(match[1].str());
            string suiteName = match[2].str();

            // ����Ƿ��Ѿ�������˲����׼�
            if (processedSuites.find(suiteName) == processedSuites.end())
            {
                processedSuites.insert(suiteName);
                suiteTestCounts[suiteName] = testCount;
                // ���ÿ�������׼������ֺͲ���������
                cout << "�����׼���: " << suiteName << ", ����������: " << testCount << endl;
                if (suiteName.find("Main") == string::npos) // ����main
                {
                    int nnnn = suiteName.size() - suiteName.find("Test");
                    if (nnnn != 4)
                    {
                        tot.push(suiteName);
                        cout << "YES!" << endl;
                    }
                }
            }
        }
    }

    file.close();

    return tot;
}


inline void json_2(const std::string& write_path)
{
    std::ifstream file("tmp.txt"); // �������txt�ļ���Ϊoutput.txt
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
    stack<string> now = work1();
    map<string, bool> failed;
    for (auto x : failed_test_cases)
    {
        size_t pos = x.find('.');
        if (pos != string::npos)
        {
            string suite_name = x.substr(0, pos);
            failed[suite_name] = 1;
        }
    }
    int tot = now.size();
    vector<string> yes, no;
    while (!now.empty())
    {
        auto x = now.top();
        now.pop();
        if (failed.find(x) != failed.end()) // fail
        {
            no.push_back(x);
        }
        else
        {
            yes.push_back(x);
        }
    }


    nlohmann::json test_resultss;
    if (compile)
    {
        test_resultss["num_tot"] = tot;
        test_resultss["num_pass"] = yes.size();
        test_resultss["num_fail"] = no.size();
        test_resultss["suites_passed"] = yes;
        test_resultss["suites_failed"] = no;
        test_resultss["class_name"] = class_name;
    }
    else
    {
        std::ifstream file("tmp.txt");
        std::regex pattern_2(R"((\w+)Test(?:\w*)?)"); // ƥ�� Test ǰ��� xxx������ Test �������ַ�
        std::string class_name2;
        while (std::getline(file, line))
        {
            if (line.find("Main") == string::npos) // ����main
            {
                int nnnn = line.size() - line.find("Test");
                if (nnnn != 4)
                {
                    no.push_back(line);
                }
            }
            if (std::regex_search(line, match, pattern_2) && class_name2.empty())
            {
                // std::cout << match[1] << std::endl;
                class_name2 = match[1];
            }
        }
        file.close();
        test_resultss["num_tot"] = no.size();
        test_resultss["num_pass"] = yes.size();
        test_resultss["num_fail"] = no.size();
        test_resultss["suites_passed"] = yes;
        test_resultss["suites_failed"] = no;
        test_resultss["class_name"] = class_name2;
    }

    // д��JSONL�ļ�
    std::string jsonl_path = write_path + "\\" + "results2.jsonl";
    std::ofstream jsonl_file(jsonl_path, std::ios::app);
    if (jsonl_file.is_open())
    {
        jsonl_file << test_resultss.dump() << std::endl; // д��һ��JSON
        jsonl_file.close();
    }
    else
    {
        std::cerr << "�޷�����JSONL�ļ�" << std::endl;
    }
}
