#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include <cstdio>
#include <filesystem>
#include <cstdio>
#include "pch.h"

namespace fs = std::filesystem;

class ExcelProcessorTestReadExcel : public ::testing::Test {
protected:
    std::string test_file_name;

    void SetUp() override {
        
    }

    void TearDown() override {
        
        if (!test_file_name.empty() && fs::exists(test_file_name)) {
            fs::remove(test_file_name);
        }
    }
};

TEST_F(ExcelProcessorTestReadExcel, test_read_excel_1) {
    test_file_name = "test_data.xlsx";
    std::vector<std::vector<std::variant<std::string, int>>> data = {
        {"Name", "Age", "Country"},
        {"John", 25, "USA"},
        {"Alice", 30, "Canada"},
        {"Bob", 35, "Australia"}
    };

    
    ExcelProcessor processor;
    processor.write_excel(data, test_file_name);

    auto read_data = processor.read_excel(test_file_name);
    std::vector<std::vector<std::variant<std::string, int>>> expected_data = {
        {"Name", "Age", "Country"},
        {"John", 25, "USA"},
        {"Alice", 30, "Canada"},
        {"Bob", 35, "Australia"}
    };
    ASSERT_EQ(read_data, expected_data);
}

TEST_F(ExcelProcessorTestReadExcel, test_read_excel_2) {
    test_file_name = "test_data.xlsx";
    std::vector<std::vector<std::variant<std::string, int>>> data = {
        {"Name", "Age"},
        {"John", 25},
        {"Alice", 30},
        {"Bob", 35}
    };

    ExcelProcessor processor;
    processor.write_excel(data, test_file_name);

    auto read_data = processor.read_excel(test_file_name);
    std::vector<std::vector<std::variant<std::string, int>>> expected_data = {
        {"Name", "Age"},
        {"John", 25},
        {"Alice", 30},
        {"Bob", 35}
    };
    ASSERT_EQ(read_data, expected_data);
}

TEST_F(ExcelProcessorTestReadExcel, test_read_excel_3) {
    test_file_name = "test_data.xlsx";
    std::vector<std::vector<std::variant<std::string, int>>> data = {
        {"Name"},
        {"John"},
        {"Alice"},
        {"Bob"}
    };

    ExcelProcessor processor;
    processor.write_excel(data, test_file_name);

    auto read_data = processor.read_excel(test_file_name);
    std::vector<std::vector<std::variant<std::string, int>>> expected_data = {
        {"Name"},
        {"John"},
        {"Alice"},
        {"Bob"}
    };
    ASSERT_EQ(read_data, expected_data);
}

TEST_F(ExcelProcessorTestReadExcel, test_read_excel_4) {
    test_file_name = "test_data.xlsx";
    std::vector<std::vector<std::variant<std::string, int>>> data = {
        {"Name", "Country"},
        {"John", "USA"},
        {"Alice", "Canada"},
        {"Bob", "Australia"}
    };

    ExcelProcessor processor;
    processor.write_excel(data, test_file_name);

    auto read_data = processor.read_excel(test_file_name);
    std::vector<std::vector<std::variant<std::string, int>>> expected_data = {
        {"Name", "Country"},
        {"John", "USA"},
        {"Alice", "Canada"},
        {"Bob", "Australia"}
    };
    ASSERT_EQ(read_data, expected_data);
}

TEST_F(ExcelProcessorTestReadExcel, test_read_excel_5) {
    test_file_name = "test_data.xlsx";
    std::vector<std::vector<std::variant<std::string, int>>> data = {
        {"Name", "Country"},
        {"John", "USA"}
    };

    ExcelProcessor processor;
    processor.write_excel(data, test_file_name);

    auto read_data = processor.read_excel(test_file_name);
    std::vector<std::vector<std::variant<std::string, int>>> expected_data = {
        {"Name", "Country"},
        {"John", "USA"}
    };
    ASSERT_EQ(read_data, expected_data);
}

TEST_F(ExcelProcessorTestReadExcel, test_read_excel_6) {
    test_file_name = "";
    ExcelProcessor processor;
    auto res = processor.read_excel(test_file_name);
    std::vector<std::vector<std::variant<std::string, int>>> now{};
    ASSERT_EQ(res, now);
}

class ExcelProcessorTestWriteExcel : public ::testing::Test {
protected:
    void TearDown() override {
        
        std::filesystem::remove("test_output.xlsx");
    }
};

TEST_F(ExcelProcessorTestWriteExcel, test_write_excel_1) {
    ExcelProcessor processor;
    std::vector<std::vector<std::variant<std::string, int>>> new_data = {
        {"Name", "Age", "Country"},
        {"John", 25, "USA"},
        {"Alice", 30, "Canada"},
        {"Bob", 35, "Australia"},
        {"Julia", 28, "Germany"}
    };
    std::string save_file_name = "test_output.xlsx";
    bool success = processor.write_excel(new_data, save_file_name);
    EXPECT_TRUE(success);
    EXPECT_TRUE(std::filesystem::exists(save_file_name));
    auto saved_data = processor.read_excel(save_file_name);
    EXPECT_EQ(saved_data, new_data);
}

TEST_F(ExcelProcessorTestWriteExcel, test_write_excel_2) {
    ExcelProcessor processor;
    std::vector<std::vector<std::variant<std::string, int>>> new_data = {
        {"Name", "Age"},
        {"John", 25},
        {"Alice", 30},
        {"Bob", 35},
        {"Julia", 28}
    };
    std::string save_file_name = "test_output.xlsx";
    bool success = processor.write_excel(new_data, save_file_name);
    EXPECT_TRUE(success);
    EXPECT_TRUE(std::filesystem::exists(save_file_name));
    auto saved_data = processor.read_excel(save_file_name);
    EXPECT_EQ(saved_data, new_data);
}

TEST_F(ExcelProcessorTestWriteExcel, test_write_excel_3) {
    ExcelProcessor processor;
    std::vector<std::vector<std::variant<std::string, int>>> new_data = {
        {"Name", "Age", "Country"},
        {"John", 25, "USA"},
        {"Alice", 30, "Canada"},
        {"Bob", 35, "Australia"}
    };
    std::string save_file_name = "test_output.xlsx";
    bool success = processor.write_excel(new_data, save_file_name);
    EXPECT_TRUE(success);
    EXPECT_TRUE(std::filesystem::exists(save_file_name));
    auto saved_data = processor.read_excel(save_file_name);
    EXPECT_EQ(saved_data, new_data);
}

TEST_F(ExcelProcessorTestWriteExcel, test_write_excel_4) {
    ExcelProcessor processor;
    std::vector<std::vector<std::variant<std::string, int>>> new_data = {
        {"Name", "Age", "Country"},
        {"John", 25, "USA"},
        {"Alice", 30, "Canada"}
    };
    std::string save_file_name = "test_output.xlsx";
    bool success = processor.write_excel(new_data, save_file_name);
    EXPECT_TRUE(success);
    EXPECT_TRUE(std::filesystem::exists(save_file_name));
    auto saved_data = processor.read_excel(save_file_name);
    EXPECT_EQ(saved_data, new_data);
}

TEST_F(ExcelProcessorTestWriteExcel, test_write_excel_5) {
    ExcelProcessor processor;
    std::vector<std::vector<std::variant<std::string, int>>> new_data = {
        {"Name", "Age", "Country"},
        {"John", 25, "USA"}
    };
    std::string save_file_name = "test_output.xlsx";
    bool success = processor.write_excel(new_data, save_file_name);
    EXPECT_TRUE(success);
    EXPECT_TRUE(std::filesystem::exists(save_file_name));
    auto saved_data = processor.read_excel(save_file_name);
    EXPECT_EQ(saved_data, new_data);
}

TEST_F(ExcelProcessorTestWriteExcel, test_write_excel_6) {
    ExcelProcessor processor;
    std::vector<std::vector<std::variant<std::string, int>>> new_data = {
        {"Name", "Age", "Country"},
        {"John", 25, "USA"}
    };
    std::string save_file_name = "";
    bool success = processor.write_excel(new_data, save_file_name);
    EXPECT_EQ(success, 0);
}

class ExcelProcessorTestProcessExcelData : public ::testing::Test {
protected:
    std::string test_file_name;

    void SetUp() override {

    }

    void TearDown() override {
        
        std::filesystem::remove(test_file_name);
        std::filesystem::remove("test_data_process.xlsx");
    }
};

TEST_F(ExcelProcessorTestProcessExcelData, test_process_excel_data_1) {
    ExcelProcessor processor;
    test_file_name = "test_data.xlsx";
    std::vector<std::vector<std::variant<std::string, int>>> data = {
        {"Name", "Age", "Country"},
        {"John", 25, "USA"},
        {"Alice", 30, "Canada"},
        {"Bob", 35, "Australia"}
    };
    processor.write_excel(data, test_file_name);
    int N = 1;
    auto [success, output_file] = processor.process_excel_data(N, test_file_name);
    EXPECT_TRUE(success);
    EXPECT_TRUE(std::filesystem::exists(output_file));
    auto processed_data = processor.read_excel(output_file);

    std::vector<std::vector<std::variant<std::string, int>>> expected_processed_data = {
        {"Name", "Age", "Country", "AGE"},
        {"John", 25, "USA", 25},
        {"Alice", 30, "Canada", 30},
        {"Bob", 35, "Australia", 35}
    };

    ASSERT_EQ(processed_data.size(), expected_processed_data.size());
    for (size_t i = 0; i < processed_data.size(); ++i) {
        ASSERT_EQ(processed_data[i].size(), expected_processed_data[i].size());
        for (size_t j = 0; j < processed_data[i].size(); ++j) {
            if (std::holds_alternative<std::string>(processed_data[i][j])) {
                EXPECT_EQ(std::get<std::string>(processed_data[i][j]), std::get<std::string>(expected_processed_data[i][j]));
            }
            else {
                EXPECT_EQ(std::get<int>(processed_data[i][j]), std::get<int>(expected_processed_data[i][j]));
            }
        }
    }
}


TEST_F(ExcelProcessorTestProcessExcelData, test_process_excel_data_2) {
    ExcelProcessor processor;
    test_file_name = "test_data.xlsx";
    std::vector<std::vector<std::variant<std::string, int>>> data = {
        {"Name", "Age", "Country"},
        {"John", 25, "USA"},
        {"Alice", 30, "Canada"},
        {"Bob", 35, "Australia"}
    };
    processor.write_excel(data, test_file_name);
    int N = 0;
    auto [success, output_file] = processor.process_excel_data(N, test_file_name);
    EXPECT_TRUE(success);
    EXPECT_TRUE(std::filesystem::exists(output_file));
    auto processed_data = processor.read_excel(output_file);

    std::vector<std::vector<std::variant<std::string, int>>> expected_processed_data = {
        {"Name", "Age", "Country", "NAME"},
        {"John", 25, "USA", "JOHN"},
        {"Alice", 30, "Canada", "ALICE"},
        {"Bob", 35, "Australia", "BOB"}
    };

    ASSERT_EQ(processed_data.size(), expected_processed_data.size());
    for (size_t i = 0; i < processed_data.size(); ++i) {
        ASSERT_EQ(processed_data[i].size(), expected_processed_data[i].size());
        for (size_t j = 0; j < processed_data[i].size(); ++j) {
            if (std::holds_alternative<std::string>(processed_data[i][j])) {
                EXPECT_EQ(std::get<std::string>(processed_data[i][j]), std::get<std::string>(expected_processed_data[i][j]));
            }
            else {
                EXPECT_EQ(std::get<int>(processed_data[i][j]), std::get<int>(expected_processed_data[i][j]));
            }
        }
    }
}


TEST_F(ExcelProcessorTestProcessExcelData, test_process_excel_data_3) {
    ExcelProcessor processor;
    test_file_name = "test_data.xlsx";
    std::vector<std::vector<std::variant<std::string, int>>> data = {
        {"Name", "Age", "Country"},
        {"John", 25, "USA"},
        {"Alice", 30, "Canada"},
        {"Bob", 35, "Australia"}
    };
    processor.write_excel(data, test_file_name);
    int N = 2;
    auto [success, output_file] = processor.process_excel_data(N, test_file_name);
    EXPECT_TRUE(success);
    EXPECT_TRUE(std::filesystem::exists(output_file));
    auto processed_data = processor.read_excel(output_file);

    std::vector<std::vector<std::variant<std::string, int>>> expected_processed_data = {
        {"Name", "Age", "Country", "COUNTRY"},
        {"John", 25, "USA", "USA"},
        {"Alice", 30, "Canada", "CANADA"},
        {"Bob", 35, "Australia", "AUSTRALIA"}
    };

    ASSERT_EQ(processed_data.size(), expected_processed_data.size());
    for (size_t i = 0; i < processed_data.size(); ++i) {
        ASSERT_EQ(processed_data[i].size(), expected_processed_data[i].size());
        for (size_t j = 0; j < processed_data[i].size(); ++j) {
            if (std::holds_alternative<std::string>(processed_data[i][j])) {
                EXPECT_EQ(std::get<std::string>(processed_data[i][j]), std::get<std::string>(expected_processed_data[i][j]));
            }
            else {
                EXPECT_EQ(std::get<int>(processed_data[i][j]), std::get<int>(expected_processed_data[i][j]));
            }
        }
    }
}


TEST_F(ExcelProcessorTestProcessExcelData, test_process_excel_data_4) {
    ExcelProcessor processor;
    test_file_name = "test_data.xlsx";
    std::vector<std::vector<std::variant<std::string, int>>> data = {
        {"Name", "Age", "COUNTRY"},
        {"John", 25, "USA"},
        {"Alice", 30, "CANADA"},
        {"Bob", 35, "AUSTRALIA"}
    };
    processor.write_excel(data, test_file_name);
    int N = 2;
    auto [success, output_file] = processor.process_excel_data(N, test_file_name);
    EXPECT_TRUE(success);
    EXPECT_TRUE(std::filesystem::exists(output_file));
    auto processed_data = processor.read_excel(output_file);

    std::vector<std::vector<std::variant<std::string, int>>> expected_processed_data = {
        {"Name", "Age", "COUNTRY","COUNTRY"},
        {"John", 25, "USA","USA"},
        {"Alice", 30, "CANADA","CANADA"},
        {"Bob", 35, "AUSTRALIA","AUSTRALIA"}
    };

    ASSERT_EQ(processed_data.size(), expected_processed_data.size());
    for (size_t i = 0; i < processed_data.size(); ++i) {
        ASSERT_EQ(processed_data[i].size(), expected_processed_data[i].size());
        for (size_t j = 0; j < processed_data[i].size(); ++j) {
            if (std::holds_alternative<std::string>(processed_data[i][j])) {
                EXPECT_EQ(std::get<std::string>(processed_data[i][j]), std::get<std::string>(expected_processed_data[i][j]));
            }
            else {
                EXPECT_EQ(std::get<int>(processed_data[i][j]), std::get<int>(expected_processed_data[i][j]));
            }
        }
    }
}


TEST_F(ExcelProcessorTestProcessExcelData, test_process_excel_data_5) {
    ExcelProcessor processor;
    test_file_name = "test_data.xlsx";
    std::vector<std::vector<std::variant<std::string, int>>> data = {
        {"Name", "AGE", "COUNTRY"},
        {"John", 25, "USA"},
        {"Alice", 30, "CANADA"},
        {"Bob", 35, "AUSTRALIA"}
    };
    processor.write_excel(data, test_file_name);
    int N = 1;
    auto [success, output_file] = processor.process_excel_data(N, test_file_name);
    EXPECT_TRUE(success);
    EXPECT_TRUE(std::filesystem::exists(output_file));
    auto processed_data = processor.read_excel(output_file);

    std::vector<std::vector<std::variant<std::string, int>>> expected_processed_data = {
        {"Name", "AGE", "COUNTRY","AGE"},
        {"John", 25, "USA",25},
        {"Alice", 30, "CANADA",30},
        {"Bob", 35, "AUSTRALIA",35}
    };

    ASSERT_EQ(processed_data.size(), expected_processed_data.size());
    for (size_t i = 0; i < processed_data.size(); ++i) {
        ASSERT_EQ(processed_data[i].size(), expected_processed_data[i].size());
        for (size_t j = 0; j < processed_data[i].size(); ++j) {
            if (std::holds_alternative<std::string>(processed_data[i][j])) {
                EXPECT_EQ(std::get<std::string>(processed_data[i][j]), std::get<std::string>(expected_processed_data[i][j]));
            }
            else {
                EXPECT_EQ(std::get<int>(processed_data[i][j]), std::get<int>(expected_processed_data[i][j]));
            }
        }
    }
}


TEST_F(ExcelProcessorTestProcessExcelData, test_process_excel_data_6) {
    ExcelProcessor processor;
    test_file_name = "test_data.xlsx";
    std::vector<std::vector<std::variant<std::string, int>>> data = {
        {"Name", "AGE", "COUNTRY"},
        {"John", 25, "USA"},
        {"Alice", 30, "CANADA"},
        {"Bob", 35, "AUSTRALIA"}
    };
    int N = 100;
    int res = processor.process_excel_data(N, test_file_name).first;
    EXPECT_EQ(res, 0);

}

class ExcelProcessorTest : public ::testing::Test {
protected:
    std::string test_file_name;
    ExcelProcessor processor;

    void SetUp() override {
        test_file_name = "test_data.xlsx";
        std::vector<std::vector<std::variant<std::string, int>>> data = {
            {"Name", "Age", "Country"},
            {"John", 25, "USA"},
            {"Alice", 30, "Canada"},
            {"Bob", 35, "Australia"}
        };
        processor.write_excel(data, test_file_name);
    }

    void TearDown() override {
        std::filesystem::remove(test_file_name);
    }
};

TEST_F(ExcelProcessorTest, test_ExcelProcessor) {
    
    auto data = processor.read_excel(test_file_name);
    std::vector<std::vector<std::variant<std::string, int>>> expected_data = {
        {"Name", "Age", "Country"},
        {"John", 25, "USA"},
        {"Alice", 30, "Canada"},
        {"Bob", 35, "Australia"}
    };
    EXPECT_EQ(data, expected_data);

    
    std::vector<std::vector<std::variant<std::string, int>>> new_data = {
        {"Name", "Age", "Country"},
        {"John", 25, "USA"},
        {"Alice", 30, "Canada"},
        {"Bob", 35, "Australia"},
        {"Julia", 28, "Germany"}
    };
    std::string save_file_name = "test_output.xlsx";
    bool success = processor.write_excel(new_data, save_file_name);
    EXPECT_TRUE(success);
    EXPECT_TRUE(std::filesystem::exists(save_file_name));
    auto saved_data = processor.read_excel(save_file_name);
    EXPECT_EQ(saved_data, new_data);
    std::filesystem::remove(save_file_name);

    
    int N = 1;
    auto [success1, output_file1] = processor.process_excel_data(1, test_file_name);
    EXPECT_TRUE(success1);
    EXPECT_TRUE(std::filesystem::exists(output_file1));
    auto processed_data1 = processor.read_excel(output_file1);

    std::vector<std::vector<std::variant<std::string, int>>> expected_data1 = {
        {"Name", "Age", "Country", "AGE"},
        {"John", 25, "USA", 25},
        {"Alice", 30, "Canada", 30},
        {"Bob", 35, "Australia", 35}
    };

    ASSERT_EQ(processed_data1.size(), expected_data1.size());
    for (size_t i = 0; i < processed_data1.size(); ++i) {
        ASSERT_EQ(processed_data1[i].size(), expected_data1[i].size());
        for (size_t j = 0; j < processed_data1[i].size(); ++j) {
            if (std::holds_alternative<std::string>(processed_data1[i][j])) {
                EXPECT_EQ(std::get<std::string>(processed_data1[i][j]), std::get<std::string>(expected_data1[i][j]));
            }
            else {
                EXPECT_EQ(std::get<int>(processed_data1[i][j]), std::get<int>(expected_data1[i][j]));
            }
        }
    }

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}