#include "command.cpp"

namespace fs = std::filesystem;

inline void read_files_in_order_1(const std::string& directory_path1, const std::string& directory_path2, const std::string& output_file_path1, const std::string& output_file_path2)
{
    try {
        std::vector<fs::path> files1;
        std::vector<fs::path> files2;

        // ����Ŀ¼���ռ��ļ�
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

        // ���ļ�������
        std::sort(files1.begin(), files1.end());
        std::sort(files2.begin(), files2.end());

        // ��ȡÿ���ļ������ݲ�д������ļ�
        std::string newdir = directory_path1 + "\\result";
        std::filesystem::create_directory(newdir);
        std::string jsonl_filepathj = newdir + "\\result_solution.jsonl";
        clearFile(jsonl_filepathj);
        for (int i = 0; i < std::min(files1.size(), files2.size()); ++i)
        {
            std::string filePathh3 = "tmp.txt"; // �滻Ϊ����ļ�·��
            clearFile(filePathh3);
            auto& solution_path = files1[i];
            auto& test_path = files2[i];

            std::ifstream solution(solution_path);
            if (!solution.is_open()) {
                std::cerr << "�޷����ļ�: " << solution_path << std::endl;
                continue;
            }
            std::ifstream test(test_path);
            if (!test.is_open()) {
                std::cerr << "�޷����ļ�: " << test_path << std::endl;
                continue;
            }

            // �Ը���ģʽ������ļ�
            std::cout << solution_path << std::endl;
            std::cout << solution_path.filename().string() << std::endl;
            std::ofstream output_file1(output_file_path1, std::ios::trunc);
            if (!output_file1.is_open()) {
                std::cerr << "�޷�������ļ�: " << output_file_path1 << std::endl;
                return;
            }
            std::ofstream output_file2(output_file_path2, std::ios::trunc);
            if (!output_file2.is_open()) {
                std::cerr << "�޷�������ļ�: " << output_file_path2 << std::endl;
                return;
            }

            // ����ǰ�ļ�����д������ļ�
            output_file1 << solution.rdbuf();
            output_file2 << test.rdbuf();
            output_file1.close();
            output_file2.close();
            test.close();
            solution.close();
            // �ļ�������һ��ѭ��ʱ������
            if (solution_path.filename().string().substr(solution_path.filename().string().length() - 3, 3) == "cpp")
            {
                int res = build_project();
                load_json(res, solution_path);
            }
                

        }
    }
    catch (const std::exception& e) {
        std::cerr << "��������: " << e.what() << std::endl;
    }
}

inline void step_1() {

    std::string filePathh2 = "tmp.txt";
    clearFile(filePathh2);
    std::string tot_dir = "Test\\to_be_tested";
    std::string directory_path2 = "Test\\test_step1";
    std::string output_file_path1 = solution_file; // ����ļ�·��
    std::string output_file_path2 = test_file; // ����ļ�·��
    for (const auto& entry : fs::directory_iterator(tot_dir)) {
        if (fs::is_directory(entry)) { // ����Ƿ�ΪĿ¼
            read_files_in_order_1(entry.path().string(), directory_path2, output_file_path1, output_file_path2);
        }
    }
}
