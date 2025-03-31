
#include <OpenXLSX.hpp>
#include <iostream>
#include <variant>
#include <string>
#include <vector>

#include <string>
#include <vector>
#include <variant>

class ExcelProcessor {
public:
    ExcelProcessor() = default;

    std::vector<std::vector<std::variant<std::string, int>>> read_excel(const std::string& file_name);

    int write_excel(const std::vector<std::vector<std::variant<std::string, int>>>& data, const std::string& file_name);

    std::pair<int, std::string> process_excel_data(size_t N, const std::string& save_file_name);
};

std::vector<std::vector<std::variant<std::string, int>>> ExcelProcessor::read_excel(const std::string& file_name) {
    std::vector<std::vector<std::variant<std::string, int>>> data;
    try {
        OpenXLSX::XLDocument doc;
        doc.open(file_name);
        auto sheet = doc.workbook().worksheet("Sheet1");

        unsigned int rowCount = sheet.rowCount();
        unsigned int colCount = sheet.columnCount();

        for (unsigned int rowIndex = 1; rowIndex <= rowCount; ++rowIndex) {
            std::vector<std::variant<std::string, int>> rowData;
            for (unsigned int colIndex = 1; colIndex <= colCount; ++colIndex) {
                auto cell = sheet.cell(rowIndex, colIndex);

                if (cell.value().type() == OpenXLSX::XLValueType::Integer) {
                    rowData.emplace_back(static_cast<int>(cell.value().get<int64_t>()));
                }
                else if (cell.value().type() == OpenXLSX::XLValueType::String) {
                    rowData.emplace_back(cell.value().get<std::string>());
                }
            }
            data.push_back(rowData);
        }
        doc.close();
    }
    catch (...) {
        return {};
    }
    return data;
}

int ExcelProcessor::write_excel(const std::vector<std::vector<std::variant<std::string, int>>>& data, const std::string& file_name) {
    try {
        OpenXLSX::XLDocument doc;
        doc.create(file_name);
        auto sheet = doc.workbook().worksheet("Sheet1");

        for (unsigned int rowIndex = 0; rowIndex < data.size(); ++rowIndex) {
            for (unsigned int colIndex = 0; colIndex < data[rowIndex].size(); ++colIndex) {
                auto cell = sheet.cell(rowIndex + 1, colIndex + 1);
                if (std::holds_alternative<int>(data[rowIndex][colIndex])) {
                    cell.value() = std::get<int>(data[rowIndex][colIndex]);
                }
                else {
                    cell.value() = std::get<std::string>(data[rowIndex][colIndex]);
                }
            }
        }
        doc.save();
        doc.close();
        return 1;
    }
    catch (...) {
        return 0;
    }
}

std::pair<int, std::string> ExcelProcessor::process_excel_data(size_t N, const std::string& save_file_name) {
    auto data = read_excel(save_file_name);
    if (data.empty() || N >= data[0].size()) {
        return { 0, "" };
    }

    std::vector<std::vector<std::variant<std::string, int>>> new_data;
    for (const auto& row : data) {
        std::vector<std::variant<std::string, int>> new_row(row);
        if (auto value = std::get_if<std::string>(&row[N])) {
            if (!std::isdigit((*value)[0])) {
                std::string now = *value;
                for (int i = 0; i < now.size(); ++i)
                {
                    if (now[i] > 'Z')
                    {
                        now[i] -= 32;
                    }
                }
                new_row.emplace_back(now);
            }
            else {
                new_row.emplace_back(value->substr(0, 1));
            }
        }
        else {
            new_row.emplace_back(std::get<int>(row[N]));
        }
        new_data.push_back(new_row);
    }

    std::string new_file_name = save_file_name.substr(0, save_file_name.find_last_of('.')) + "_process.xlsx";
    int success = write_excel(new_data, new_file_name);
    return { success, new_file_name };
}
