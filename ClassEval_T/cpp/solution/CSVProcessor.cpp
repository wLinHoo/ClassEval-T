#include <fstream>
#include <sstream>
#include <algorithm>

#include <vector>
#include <string>
#include <utility>
#include<algorithm>

class CSVProcessor {
public:
    CSVProcessor();
    std::pair<std::vector<std::string>, std::vector<std::vector<std::string>>> read_csv(const std::string& file_name);
    int write_csv(const std::vector<std::vector<std::string>>& data, const std::string& file_name);
    int process_csv_data(int N, const std::string& save_file_name);
};

CSVProcessor::CSVProcessor() {}

std::pair<std::vector<std::string>, std::vector<std::vector<std::string>>> CSVProcessor::read_csv(const std::string& file_name) {
    std::ifstream file(file_name);
    std::vector<std::string> title;
    std::vector<std::vector<std::string>> data;

    if (!file.is_open()) {
        return { title, data };
    }

    std::string line;
    std::getline(file, line);
    std::istringstream s(line);
    std::string item;
    while (std::getline(s, item, ',')) {
        title.push_back(item);
    }

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::vector<std::string> row;
        while (std::getline(ss, item, ',')) {
            row.push_back(item);
        }
        data.push_back(row);
    }

    file.close();
    return { title, data };
}

int CSVProcessor::write_csv(const std::vector<std::vector<std::string>>& data, const std::string& file_name) {
    std::ofstream file(file_name);

    if (!file.is_open()) {
        return 0;
    }

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << row[i];
            if (i < row.size() - 1) {
                file << ",";
            }
        }
        file << "\n";
    }

    file.close();
    return 1;
}

int CSVProcessor::process_csv_data(int N, const std::string& save_file_name) {
    auto [title, data] = read_csv(save_file_name);
    if (N >= data[0].size()) {
        return 0;
    }

    std::vector<std::string> column_data;
    for (const auto& row : data) {
        if (N < row.size()) {
            std::string upper_str = row[N];
            std::transform(upper_str.begin(), upper_str.end(), upper_str.begin(), ::toupper);
            column_data.push_back(upper_str);
        }
    }

    std::vector<std::vector<std::string>> new_data = { title, column_data };
    return write_csv(new_data, save_file_name.substr(0, save_file_name.find_last_of('.')) + "_process.csv");
}


