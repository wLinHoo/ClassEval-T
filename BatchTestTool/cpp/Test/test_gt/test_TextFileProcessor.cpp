#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include <cctype>    
#include <nlohmann/json.hpp> 
#include "pch.h"

using json = nlohmann::json;
using namespace std;

class TextFileProcessorTestReadFileAsJson : public ::testing::Test {
protected:
    void SetUp() override {
        files = { "test_1.txt", "test_2.txt", "test_3.txt", "test_4.txt", "test_5.txt" };
        contents = {
            "{\n    \"name\": \"test\",\n    \"age\": 12\n}",
            "12345",
            "\"hello\"",
            "\"aaa\"",
            "\"bbb\""
        };
        for (size_t i = 0; i < files.size(); ++i) {
            ofstream file(files[i]);
            file << contents[i];
        }
    }

    vector<string> files;
    vector<string> contents;
};

TEST_F(TextFileProcessorTestReadFileAsJson, test_read_file_as_json_1) {
    TextFileProcessor textFileProcessor(files[0]);
    json data = textFileProcessor.read_file_as_json();
    json expected = { {"name", "test"}, {"age", 12} };
    EXPECT_EQ(expected, data);
    EXPECT_TRUE(data.is_object());
}

TEST_F(TextFileProcessorTestReadFileAsJson, test_read_file_as_json_2) {
    TextFileProcessor textFileProcessor(files[1]);
    json data = textFileProcessor.read_file_as_json();
    int expected = 12345;
    EXPECT_EQ(expected, data.get<int>());
    EXPECT_TRUE(data.is_number_integer());
}

TEST_F(TextFileProcessorTestReadFileAsJson, test_read_file_as_json_3) {
    TextFileProcessor textFileProcessor(files[2]);
    json data = textFileProcessor.read_file_as_json();
    string expected = "hello";
    EXPECT_EQ(expected, data.get<string>());
    EXPECT_TRUE(data.is_string());
}

TEST_F(TextFileProcessorTestReadFileAsJson, test_read_file_as_json_4) {
    TextFileProcessor textFileProcessor(files[3]);
    json data = textFileProcessor.read_file_as_json();
    string expected = "aaa";
    EXPECT_EQ(expected, data.get<string>());
    EXPECT_TRUE(data.is_string());
}

TEST_F(TextFileProcessorTestReadFileAsJson, test_read_file_as_json_5) {
    TextFileProcessor textFileProcessor(files[4]);
    json data = textFileProcessor.read_file_as_json();
    string expected = "bbb";
    EXPECT_EQ(expected, data.get<string>());
    EXPECT_TRUE(data.is_string());
}

class TextFileProcessorTestReadFile : public ::testing::Test {
protected:
    void SetUp() override {
        files = { "test_1.txt", "test_2.txt", "test_3.txt", "test_4.txt", "test_5.txt" };
        contents = { "123aac\n&^(*&43)", "12345", "aaa", "bbb", "ccc" };
        for (size_t i = 0; i < files.size(); ++i) {
            ofstream file(files[i]);
            file << contents[i];
        }
    }

    vector<string> files;
    vector<string> contents;
};

TEST_F(TextFileProcessorTestReadFile, test_read_file_1) {
    TextFileProcessor textFileProcessor(files[0]);
    string data = textFileProcessor.read_file();
    EXPECT_EQ(data, contents[0]);
}

TEST_F(TextFileProcessorTestReadFile, test_read_file_2) {
    TextFileProcessor textFileProcessor(files[1]);
    string data = textFileProcessor.read_file();
    EXPECT_EQ(data, contents[1]);
}

TEST_F(TextFileProcessorTestReadFile, test_read_file_3) {
    TextFileProcessor textFileProcessor(files[2]);
    string data = textFileProcessor.read_file();
    EXPECT_EQ(data, contents[2]);
}

TEST_F(TextFileProcessorTestReadFile, test_read_file_4) {
    TextFileProcessor textFileProcessor(files[3]);
    string data = textFileProcessor.read_file();
    EXPECT_EQ(data, contents[3]);
}

TEST_F(TextFileProcessorTestReadFile, test_read_file_5) {
    TextFileProcessor textFileProcessor(files[4]);
    string data = textFileProcessor.read_file();
    EXPECT_EQ(data, contents[4]);
}

class TextFileProcessorTestWriteFile : public ::testing::Test {
protected:
    void SetUp() override {
        files = { "test_1.txt", "test_2.txt", "test_3.txt", "test_4.txt", "test_5.txt" };
        contents = { "123aac\n&^(*&43)", "12345", "aaa", "bbb", "ccc" };
    }

    void TearDown() override {
        for (const auto& file : files) {
            if (std::filesystem::exists(file)) {
                std::filesystem::remove(file);
            }
        }
    }

    vector<string> files;
    vector<string> contents;
};

TEST_F(TextFileProcessorTestWriteFile, test_write_file_1) {
    TextFileProcessor textFileProcessor(files[0]);
    textFileProcessor.write_file(contents[0]);
    ifstream file(files[0]);
    string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    EXPECT_EQ(data, contents[0]);
}

TEST_F(TextFileProcessorTestWriteFile, test_write_file_2) {
    TextFileProcessor textFileProcessor(files[1]);
    textFileProcessor.write_file(contents[1]);
    ifstream file(files[1]);
    string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    EXPECT_EQ(data, contents[1]);
}

TEST_F(TextFileProcessorTestWriteFile, test_write_file_3) {
    TextFileProcessor textFileProcessor(files[2]);
    textFileProcessor.write_file(contents[2]);
    ifstream file(files[2]);
    string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    EXPECT_EQ(data, contents[2]);
}

TEST_F(TextFileProcessorTestWriteFile, test_write_file_4) {
    TextFileProcessor textFileProcessor(files[3]);
    textFileProcessor.write_file(contents[3]);
    ifstream file(files[3]);
    string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    EXPECT_EQ(data, contents[3]);
}

TEST_F(TextFileProcessorTestWriteFile, test_write_file_5) {
    TextFileProcessor textFileProcessor(files[4]);
    textFileProcessor.write_file(contents[4]);
    ifstream file(files[4]);
    string data((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    EXPECT_EQ(data, contents[4]);
}


class TextFileProcessorTestMain : public ::testing::Test {
protected:
    void SetUp() override {
        file = "test.txt";
        content = "{\n    \"name\": \"test\",\n    \"age\": 12\n}";
        ofstream f(file);
        f << content;
    }

    string file;
    string content;
};

TEST_F(TextFileProcessorTestMain, test_main) {
    TextFileProcessor textFileProcessor(file);

    
    json data1 = textFileProcessor.read_file_as_json();
    json expected1 = { {"name", "test"}, {"age", 12} };
    EXPECT_EQ(expected1, data1);
    EXPECT_TRUE(data1.is_object());

    
    textFileProcessor.write_file(content);
    string data2 = textFileProcessor.read_file();
    EXPECT_EQ(content, data2);

    
    string data3 = textFileProcessor.process_file();
    string expected2 = "nametestage";
    EXPECT_EQ(expected2, data3);
}

class MockTextFileProcessor : public TextFileProcessor {
public:
    MockTextFileProcessor(const std::string& file) : TextFileProcessor(file) {}

    MOCK_METHOD(std::string, read_file, (), (const, override));
    MOCK_METHOD(void, write_file, (const std::string& content), (override));
};


TEST(TextFileProcessorTest, test_process_file_1) {
    std::string file = "test.txt";
    std::string content = "Hello, 123 World!";
    std::string expected_result = "HelloWorld";

    MockTextFileProcessor textFileProcessor(file);
    EXPECT_CALL(textFileProcessor, read_file())
        .WillOnce(::testing::Return(content));
    EXPECT_CALL(textFileProcessor, write_file(expected_result))
        .Times(1);

    std::string result = textFileProcessor.process_file();
    EXPECT_EQ(result, expected_result);
}

TEST(TextFileProcessorTest, test_process_file_2) {
    std::string file = "test.txt";
    std::string content = "Hello, abc World!";
    std::string expected_result = "HelloabcWorld";

    MockTextFileProcessor textFileProcessor(file);
    EXPECT_CALL(textFileProcessor, read_file())
        .WillOnce(::testing::Return(content));
    EXPECT_CALL(textFileProcessor, write_file(expected_result))
        .Times(1);

    std::string result = textFileProcessor.process_file();
    EXPECT_EQ(result, expected_result);
}

TEST(TextFileProcessorTest, test_process_file_3) {
    std::string file = "test.txt";
    std::string content = ", 123 !";
    std::string expected_result = "";

    MockTextFileProcessor textFileProcessor(file);
    EXPECT_CALL(textFileProcessor, read_file())
        .WillOnce(::testing::Return(content));
    EXPECT_CALL(textFileProcessor, write_file(expected_result))
        .Times(1);

    std::string result = textFileProcessor.process_file();
    EXPECT_EQ(result, expected_result);
}

TEST(TextFileProcessorTest, test_process_file_4) {
    std::string file = "test.txt";
    std::string content = "Hello, World!";
    std::string expected_result = "HelloWorld";

    MockTextFileProcessor textFileProcessor(file);
    EXPECT_CALL(textFileProcessor, read_file())
        .WillOnce(::testing::Return(content));
    EXPECT_CALL(textFileProcessor, write_file(expected_result))
        .Times(1);

    std::string result = textFileProcessor.process_file();
    EXPECT_EQ(result, expected_result);
}

TEST(TextFileProcessorTest, test_process_file_5) {
    std::string file = "test.txt";
    std::string content = "Hello, 123a World!";
    std::string expected_result = "HelloaWorld";

    MockTextFileProcessor textFileProcessor(file);
    EXPECT_CALL(textFileProcessor, read_file())
        .WillOnce(::testing::Return(content));
    EXPECT_CALL(textFileProcessor, write_file(expected_result))
        .Times(1);

    std::string result = textFileProcessor.process_file();
    EXPECT_EQ(result, expected_result);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}