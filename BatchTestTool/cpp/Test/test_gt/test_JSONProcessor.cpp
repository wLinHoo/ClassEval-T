#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include <gtest/gtest.h>
#include "pch.h"
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>

using json = nlohmann::json;

class JSONProcessorTestReadJson : public ::testing::Test {
protected:
    void SetUp() override {
        processor = JSONProcessor();
        test_data = {
            {"key1", "value1"},
            {"key2", "value2"},
            {"key3", "value3"}
        };
        file_path = "test.json";
    }

    void TearDown() override {
        if (std::ifstream(file_path)) {
            std::remove(file_path.c_str());
        }
    }

    JSONProcessor processor;
    json test_data;
    std::string file_path;
};


TEST_F(JSONProcessorTestReadJson, test_read_json_1) {
    std::ofstream file(file_path);
    file << test_data.dump();  
    file.close();

    nlohmann::json result;
    int status = processor.read_json(file_path, result);
    EXPECT_EQ(status, 1);  
    EXPECT_EQ(result, test_data);  
}


TEST_F(JSONProcessorTestReadJson, test_read_json_2) {
    nlohmann::json result;
    int status = processor.read_json(file_path, result);
    EXPECT_EQ(status, 0);  
    EXPECT_TRUE(result.is_null());  
}



TEST_F(JSONProcessorTestReadJson, test_read_json_3) {
    std::ofstream file(file_path);
    file << "Invalid JSON";
    file.close();

    nlohmann::json result;
    int status = processor.read_json(file_path, result);
    EXPECT_EQ(status, -1);
}


TEST_F(JSONProcessorTestReadJson, test_read_json_4) {
    nlohmann::json result;
    int status = processor.read_json("wrong", result);
    EXPECT_EQ(status, 0);
}


TEST_F(JSONProcessorTestReadJson, test_read_json_5) {
    nlohmann::json result;
    int status = processor.read_json("abcd", result);
    EXPECT_EQ(status, 0);
}

class JSONProcessorTestWriteJson : public ::testing::Test {
protected:
    void SetUp() override {
        processor = JSONProcessor();
        test_data = {
            {"key1", "value1"},
            {"key2", "value2"},
            {"key3", "value3"}
        };
        file_path = "test.json";

        
        file_path_only_read = "test_only_read.json";
        std::ofstream file(file_path_only_read);
        file << R"({"key1": "value1"})";
        file.close();

        
        
        _chmod(file_path_only_read.c_str(), 0444);
    }
    
    void TearDown() override {
        if (std::ifstream(file_path)) {
            std::remove(file_path.c_str());
        }
        if (std::ifstream(file_path_only_read)) {
            
            chmod(file_path_only_read.c_str(), 0666);
            std::remove(file_path_only_read.c_str());
        }
    }

    JSONProcessor processor;
    json test_data;
    std::string file_path;
    std::string file_path_only_read;
};


TEST_F(JSONProcessorTestWriteJson, test_write_json_1) {
    int result = processor.write_json(test_data, file_path);
    EXPECT_EQ(result, 1);

    std::ifstream file(file_path);
    json written_data;
    file >> written_data;
    file.close();

    EXPECT_EQ(written_data, test_data);
}


TEST_F(JSONProcessorTestWriteJson, test_write_json_2) {
    int result = processor.write_json(test_data, file_path_only_read);
    EXPECT_EQ(result, -1);
}


TEST_F(JSONProcessorTestWriteJson, test_write_json_3) {
    int result = processor.write_json(json::array(), file_path_only_read);
    EXPECT_EQ(result, -1);
}


TEST_F(JSONProcessorTestWriteJson, test_write_json_4) {
    int result = processor.write_json(test_data, "");
    EXPECT_EQ(result, -1);
}


TEST_F(JSONProcessorTestWriteJson, test_write_json_5) {
    int result = processor.write_json(json::array(), "");
    EXPECT_EQ(result, -1);
}


class JSONProcessorTestProcessJsonExistingKey : public ::testing::Test {
protected:
    void SetUp() override {
        processor = JSONProcessor();
        test_data = {
            {"key1", "value1"},
            {"key2", "value2"},
            {"key3", "value3"}
        };
        file_path = "test.json";
    }

    void TearDown() override {
        if (std::ifstream(file_path)) {
            std::remove(file_path.c_str());
        }
    }

    JSONProcessor processor;
    json test_data;
    std::string file_path;
};


TEST_F(JSONProcessorTestProcessJsonExistingKey, test_process_json_1) {
    std::ofstream file(file_path);
    file << test_data.dump();
    file.close();

    std::string remove_key = "key2";
    processor.process_json(file_path, remove_key);

    std::ifstream input_file(file_path);
    json processed_data;
    input_file >> processed_data;
    input_file.close();

    json expected_data = {
        {"key1", "value1"},
        {"key3", "value3"}
    };

    EXPECT_EQ(processed_data, expected_data);
}


TEST_F(JSONProcessorTestProcessJsonExistingKey, test_process_json_2) {
    std::ofstream file(file_path);
    file << test_data.dump();
    file.close();

    std::string remove_key = "nonexistent_key";
    processor.process_json(file_path, remove_key);

    std::ifstream input_file(file_path);
    json processed_data;
    input_file >> processed_data;
    input_file.close();

    EXPECT_EQ(processed_data, test_data);
}


TEST_F(JSONProcessorTestProcessJsonExistingKey, test_process_json_3) {
    std::ofstream file(file_path); 
    file.close();

    std::string remove_key = "key1";
    EXPECT_EQ(processor.process_json(file_path, remove_key), 0);
}


TEST_F(JSONProcessorTestProcessJsonExistingKey, test_process_json_4) {
    std::ofstream file(file_path);
    file << test_data.dump();
    file.close();

    std::string remove_key = "aaa";
    processor.process_json(file_path, remove_key);

    std::ifstream input_file(file_path);
    json processed_data;
    input_file >> processed_data;
    input_file.close();

    EXPECT_EQ(processed_data, test_data);
}


TEST_F(JSONProcessorTestProcessJsonExistingKey, test_process_json_5) {
    std::ofstream file(file_path);
    file << test_data.dump();
    file.close();

    std::string remove_key = "bbb";
    processor.process_json(file_path, remove_key);

    std::ifstream input_file(file_path);
    json processed_data;
    input_file >> processed_data;
    input_file.close();

    EXPECT_EQ(processed_data, test_data);
}

class JSONProcessorTestMain : public ::testing::Test {
protected:
    void SetUp() override {
        processor = JSONProcessor();
        test_data = {
            {"key1", "value1"},
            {"key2", "value2"},
            {"key3", "value3"}
        };
        file_path = "test.json";
    }

    void TearDown() override {
        if (std::ifstream(file_path)) {
            std::remove(file_path.c_str());
        }
    }

    JSONProcessor processor;
    json test_data;
    std::string file_path;
};


TEST_F(JSONProcessorTestMain, test_main) {
    
    int result = processor.write_json(test_data, file_path);
    EXPECT_EQ(result, 1);

    std::ifstream file(file_path);
    json written_data;
    file >> written_data;
    file.close();
    EXPECT_EQ(written_data, test_data);

    
    nlohmann::json read_data;
    int status = processor.read_json(file_path, read_data);
    EXPECT_EQ(read_data, test_data);

    
    std::string remove_key = "key2";
    processor.process_json(file_path, remove_key);

    std::ifstream input_file(file_path);
    json processed_data;
    input_file >> processed_data;
    input_file.close();

    json expected_data = {
        {"key1", "value1"},
        {"key3", "value3"}
    };
    EXPECT_EQ(processed_data, expected_data);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}