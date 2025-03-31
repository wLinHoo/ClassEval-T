#include <gtest/gtest.h>
#include <fstream>
#include <vector>
#include <string>
#include "pch.h"
class CSVProcessorTestReadCSV : public ::testing::Test {
protected:
    void SetUp() override {
        file = "read_test.csv";
    }

    std::string file;
    CSVProcessor csvProcessor;
};

TEST_F(CSVProcessorTestReadCSV, test_read_csv_1) {
    std::ofstream f(file);
    f << "a,b,c,d\nhElLo,YoU,ME,LoW";
    f.close();

    std::vector<std::string> expected_title = { "a", "b", "c", "d" };
    std::vector<std::vector<std::string>> expected_data = { {"hElLo", "YoU", "ME", "LoW"} };
    auto [title, data] = csvProcessor.read_csv(file);

    ASSERT_EQ(expected_data, data);
    ASSERT_EQ(expected_title, title);
}

TEST_F(CSVProcessorTestReadCSV, test_read_csv_2) {
    std::ofstream f(file);
    f << "1234\nhElLo,YoU,ME,LoW";
    f.close();

    std::vector<std::string> expected_title = { "1234" };
    std::vector<std::vector<std::string>> expected_data = { {"hElLo", "YoU", "ME", "LoW"} };
    auto [title, data] = csvProcessor.read_csv(file);

    ASSERT_EQ(expected_data, data);
    ASSERT_EQ(expected_title, title);
}

TEST_F(CSVProcessorTestReadCSV, test_read_csv_3) {
    std::ofstream f(file);
    f << "title\nhElLo,YoU,ME,LoW";
    f.close();

    std::vector<std::string> expected_title = { "title" };
    std::vector<std::vector<std::string>> expected_data = { {"hElLo", "YoU", "ME", "LoW"} };
    auto [title, data] = csvProcessor.read_csv(file);

    ASSERT_EQ(expected_data, data);
    ASSERT_EQ(expected_title, title);
}

TEST_F(CSVProcessorTestReadCSV, test_read_csv_4) {
    std::ofstream f(file);
    f << "title4\nhElLo,YoU,ME,LoW";
    f.close();

    std::vector<std::string> expected_title = { "title4" };
    std::vector<std::vector<std::string>> expected_data = { {"hElLo", "YoU", "ME", "LoW"} };
    auto [title, data] = csvProcessor.read_csv(file);

    ASSERT_EQ(expected_data, data);
    ASSERT_EQ(expected_title, title);
}

TEST_F(CSVProcessorTestReadCSV, test_read_csv_5) {
    std::ofstream f(file);
    f << "title5\nhElLo,YoU,ME,LoW";
    f.close();

    std::vector<std::string> expected_title = { "title5" };
    std::vector<std::vector<std::string>> expected_data = { {"hElLo", "YoU", "ME", "LoW"} };
    auto [title, data] = csvProcessor.read_csv(file);

    ASSERT_EQ(expected_data, data);
    ASSERT_EQ(expected_title, title);
}

class CSVProcessorTestWriteCSV : public ::testing::Test {
protected:
    void SetUp() override {
        file = "read_test.csv";
    }

    std::string file;
    CSVProcessor csvProcessor;
};

TEST_F(CSVProcessorTestWriteCSV, test_write_csv_1) {
    std::vector<std::vector<std::string>> data = { {"a", "b", "c", "d"}, {"1", "2", "3", "4"} };
    ASSERT_EQ(1, csvProcessor.write_csv(data, file));

    auto [read_title, read_data] = csvProcessor.read_csv(file);
    ASSERT_EQ(read_title, data[0]);
    ASSERT_EQ(read_data[0], data[1]);
    std::remove(file.c_str());
}

TEST_F(CSVProcessorTestWriteCSV, test_write_csv_2) {
    std::vector<std::vector<std::string>> data = { {"aa", "bb", "cc", "dd"}, {"1", "2", "3", "4"} };
    ASSERT_EQ(1, csvProcessor.write_csv(data, file));

    auto [read_title, read_data] = csvProcessor.read_csv(file);
    ASSERT_EQ(read_title, data[0]);
    ASSERT_EQ(read_data[0], data[1]);
    std::remove(file.c_str());
}

TEST_F(CSVProcessorTestWriteCSV, test_write_csv_3) {
    std::vector<std::vector<std::string>> data = { {"a", "b", "c", "d"}, {"11", "22", "33", "44"} };
    ASSERT_EQ(1, csvProcessor.write_csv(data, file));

    auto [read_title, read_data] = csvProcessor.read_csv(file);
    ASSERT_EQ(read_title, data[0]);
    ASSERT_EQ(read_data[0], data[1]);
    std::remove(file.c_str());
}

TEST_F(CSVProcessorTestWriteCSV, test_write_csv_4) {
    std::vector<std::vector<std::string>> data = { {"e", "f", "g", "h"}, {"1", "2", "3", "4"} };
    ASSERT_EQ(1, csvProcessor.write_csv(data, file));

    auto [read_title, read_data] = csvProcessor.read_csv(file);
    ASSERT_EQ(read_title, data[0]);
    ASSERT_EQ(read_data[0], data[1]);
    std::remove(file.c_str());
}

TEST_F(CSVProcessorTestWriteCSV, test_write_csv_5) {
    std::vector<std::vector<std::string>> data = { {"a", "b", "c", "d"}, {"5", "6", "7", "8"} };
    ASSERT_EQ(1, csvProcessor.write_csv(data, file));

    auto [read_title, read_data] = csvProcessor.read_csv(file);
    ASSERT_EQ(read_title, data[0]);
    ASSERT_EQ(read_data[0], data[1]);
    std::remove(file.c_str());
}

TEST_F(CSVProcessorTestWriteCSV, test_write_csv_6) {
    std::vector<std::vector<std::string>> data;
    file = "";
    ASSERT_EQ(0, csvProcessor.write_csv(data, file));
}

class CSVProcessorTestProcessCSVData : public ::testing::Test {
protected:
    void SetUp() override {
        file = "read_test.csv";
        file_process = "read_test_process.csv";
        std::ofstream f(file);
        f << "a,b,c,d\nhElLo,YoU,ME,LoW,aBc";
        f.close();
    }

    std::string file;
    std::string file_process;
    CSVProcessor csvProcessor;
};

TEST_F(CSVProcessorTestProcessCSVData, test_process_csv_data_1) {
    std::vector<std::string> title = { "a", "b", "c", "d" };
    std::vector<std::string> data = { "HELLO" };
    ASSERT_EQ(1, csvProcessor.process_csv_data(0, file));

    auto [read_title, read_data] = csvProcessor.read_csv(file_process);
    ASSERT_EQ(read_title, title);
    ASSERT_EQ(read_data[0], data);
}

TEST_F(CSVProcessorTestProcessCSVData, test_process_csv_data_2) {
    std::vector<std::string> title = { "a", "b", "c", "d" };
    std::vector<std::string> data = { "YOU" };
    ASSERT_EQ(1, csvProcessor.process_csv_data(1, file));

    auto [read_title, read_data] = csvProcessor.read_csv(file_process);
    ASSERT_EQ(read_title, title);
    ASSERT_EQ(read_data[0], data);
}

TEST_F(CSVProcessorTestProcessCSVData, test_process_csv_data_3) {
    std::vector<std::string> title = { "a", "b", "c", "d" };
    std::vector<std::string> data = { "ME" };
    ASSERT_EQ(1, csvProcessor.process_csv_data(2, file));

    auto [read_title, read_data] = csvProcessor.read_csv(file_process);
    ASSERT_EQ(read_title, title);
    ASSERT_EQ(read_data[0], data);
}

TEST_F(CSVProcessorTestProcessCSVData, test_process_csv_data_4) {
    std::vector<std::string> title = { "a", "b", "c", "d" };
    std::vector<std::string> data = { "LOW" };
    ASSERT_EQ(1, csvProcessor.process_csv_data(3, file));

    auto [read_title, read_data] = csvProcessor.read_csv(file_process);
    ASSERT_EQ(read_title, title);
    ASSERT_EQ(read_data[0], data);
}

TEST_F(CSVProcessorTestProcessCSVData, test_process_csv_data_5) {
    std::vector<std::string> title = { "a", "b", "c", "d" };
    std::vector<std::string> data = { "ABC" };
    ASSERT_EQ(1, csvProcessor.process_csv_data(4, file));
    auto [read_title, read_data] = csvProcessor.read_csv(file_process);
    ASSERT_EQ(title, read_title); 
    ASSERT_EQ(data, read_data[0]); 
}

class CSVProcessorTestMain : public ::testing::Test {
protected:
    void SetUp() override {
        file = "test.csv";
        file_process = "test_process.csv";
        std::ofstream f(file);
        f << "a,b,c,d\nhElLo,YoU,ME,LoW";
        f.close();
    }

    std::string file;
    std::string file_process;
    CSVProcessor csvProcessor;
};

TEST_F(CSVProcessorTestMain, test_main) {
    std::vector<std::vector<std::string>> data = { {"a", "b", "c", "d"}, {"hElLo", "YoU", "ME", "LoW"} };
    ASSERT_EQ(1, csvProcessor.write_csv(data, file));

    std::vector<std::string> expected_title = { "a", "b", "c", "d" };
    std::vector<std::vector<std::string>> expected_data = { {"hElLo", "YoU", "ME", "LoW"} };

    
    std::pair<std::vector<std::string>, std::vector<std::vector<std::string>>> now = csvProcessor.read_csv(file);
    auto title = now.first;
    auto dataa = now.second;

    ASSERT_EQ(expected_data, dataa);
    ASSERT_EQ(expected_title, title);

    std::vector<std::string> process_title = { "a", "b", "c", "d" };
    std::vector<std::string> process_data = { "HELLO" };
    ASSERT_EQ(1, csvProcessor.process_csv_data(0, file));

    auto [read_title, read_data] = csvProcessor.read_csv(file_process);
    ASSERT_EQ(process_title, read_title);
    ASSERT_EQ(process_data, read_data[0]);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}