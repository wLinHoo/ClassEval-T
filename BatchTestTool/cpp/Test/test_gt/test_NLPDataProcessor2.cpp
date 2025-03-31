#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "pch.h"

class NLPDataProcessor2TestProcessData : public ::testing::Test {
protected:
    NLPDataProcessor2 processor;

    void SetUp() override {
        processor = NLPDataProcessor2();
    }
};

TEST_F(NLPDataProcessor2TestProcessData, TestProcessData) {
    std::vector<std::string> string_list = { "Hello World!", "This is a test." };
    std::vector<std::vector<std::string>> expected_output = { {"hello", "world"}, {"this", "is", "a", "test"} };
    ASSERT_EQ(processor.process_data(string_list), expected_output);
}

TEST_F(NLPDataProcessor2TestProcessData, TestProcessData2) {
    std::vector<std::string> string_list = { "12345", "Special@Characters" };
    std::vector<std::vector<std::string>> expected_output = { {}, {"specialcharacters"} };
    ASSERT_EQ(processor.process_data(string_list), expected_output);
}

TEST_F(NLPDataProcessor2TestProcessData, TestProcessData3) {
    std::vector<std::string> string_list = {};
    std::vector<std::vector<std::string>> expected_output = {};
    ASSERT_EQ(processor.process_data(string_list), expected_output);
}

TEST_F(NLPDataProcessor2TestProcessData, TestProcessData4) {
    std::vector<std::string> string_list = { "Hello World!", "This is a test.", "12345", "Special@Characters" };
    std::vector<std::vector<std::string>> expected_output = { {"hello", "world"}, {"this", "is", "a", "test"}, {}, {"specialcharacters"} };
    ASSERT_EQ(processor.process_data(string_list), expected_output);
}

TEST_F(NLPDataProcessor2TestProcessData, TestProcessData5) {
    std::vector<std::string> string_list = { "Hello World!", "This is a test.", "12345", "Special@Characters", "Hello World!", "This is a test.", "12345", "Special@Characters" };
    std::vector<std::vector<std::string>> expected_output = { {"hello", "world"}, {"this", "is", "a", "test"}, {}, {"specialcharacters"}, {"hello", "world"}, {"this", "is", "a", "test"}, {}, {"specialcharacters"} };
    ASSERT_EQ(processor.process_data(string_list), expected_output);
}

class NLPDataProcessor2TestCalculate : public ::testing::Test {
protected:
    NLPDataProcessor2 processor;

    void SetUp() override {
        processor = NLPDataProcessor2();
    }
};

TEST_F(NLPDataProcessor2TestCalculate, TestCalculateWordFrequency) {
    std::vector<std::vector<std::string>> words_list = { {"hello", "world"}, {"this", "is", "a", "test"}, {"hello", "world", "this", "is", "another", "test"},
                                                        {"hello", "hello", "world"} };
    std::map<std::string, int> expected_output = { {"hello", 4}, {"world", 3}, {"this", 2}, {"is", 2}, {"test", 2} };
    ASSERT_EQ(processor.calculate_word_frequency(words_list), expected_output);
}

TEST_F(NLPDataProcessor2TestCalculate, TestCalculateWordFrequency2) {
    std::vector<std::vector<std::string>> words_list = { {"hello", "world"}, {"this", "is", "a", "test"}, {"hello", "world", "this", "is", "another", "test"},
                                                        {"hello", "hello", "world"}, {"world", "world", "world"} };
    std::map<std::string, int> expected_output = { {"world", 6}, {"hello", 4}, {"this", 2}, {"is", 2}, {"test", 2} };
    ASSERT_EQ(processor.calculate_word_frequency(words_list), expected_output);
}

TEST_F(NLPDataProcessor2TestCalculate, TestCalculateWordFrequency3) {
    std::vector<std::vector<std::string>> words_list = { {"hello", "world"}, {"hello", "hello", "world"}, {"world", "world"} };
    std::map<std::string, int> expected_output = { {"world", 4}, {"hello", 3} };
    ASSERT_EQ(processor.calculate_word_frequency(words_list), expected_output);
}

TEST_F(NLPDataProcessor2TestCalculate, TestCalculateWordFrequency4) {
    std::vector<std::vector<std::string>> words_list = { {"hello", "world"}, {"this", "is", "a", "%%%"}, {"hello", "world", "this", "is", "another", "%%%"},
                                                        {"hello", "hello", "world"}, {"%%%", "world", "a", "%%%"}, {"%%%", "hello", "%%%"} };
    std::map<std::string, int> expected_output = { {"%%%", 6}, {"hello", 5}, {"world", 4}, {"is", 2}, {"this", 2} };
    ASSERT_EQ(processor.calculate_word_frequency(words_list), expected_output);
}

TEST_F(NLPDataProcessor2TestCalculate, TestCalculateWordFrequency5) {
    std::vector<std::vector<std::string>> words_list = { {"hello", "world"}, {"this", "is", "a", "%%%"}, {"hello", "world", "this", "is", "another", "%%%"},
                                                        {"hello", "hello", "world"}, {"%%%", "world", "a", "%%%"}, {"%%%", "hello", "%%%"}, {"hello", "world"},
                                                        {"this", "is", "a", "%%%"}, {"hello", "world", "this", "is", "another", "%%%"},
                                                        {"hello", "hello", "world"}, {"%%%", "world", "a", "%%%"}, {"%%%", "hello", "%%%"} };
    std::map<std::string, int> expected_output = { {"%%%", 12}, {"hello", 10}, {"world", 8}, {"is", 4}, {"this", 4} };
    ASSERT_EQ(processor.calculate_word_frequency(words_list), expected_output);
}

class NLPDataProcessor2TestProcess : public ::testing::Test {
protected:
    NLPDataProcessor2 processor;

    void SetUp() override {
        processor = NLPDataProcessor2();
    }
};

TEST_F(NLPDataProcessor2TestProcess, TestProcess) {
    std::vector<std::string> string_list = { "Hello World!", "This is a test.", "Hello World, this is a test." };
    std::map<std::string, int> expected_output = { {"hello", 2}, {"world", 2}, {"this", 2}, {"is", 2}, {"a", 2} };
    ASSERT_EQ(processor.process(string_list), expected_output);
}

TEST_F(NLPDataProcessor2TestProcess, TestProcess2) {
    std::vector<std::string> string_list = {};
    std::vector<std::vector<std::string>> expected_output = {};
    ASSERT_EQ(processor.process_data(string_list), expected_output);
}

TEST_F(NLPDataProcessor2TestProcess, TestCalculate3) {
    std::vector<std::vector<std::string>> words_list = {};
    std::map<std::string, int> expected_output = {};
    ASSERT_EQ(processor.calculate_word_frequency(words_list), expected_output);
}

TEST_F(NLPDataProcessor2TestProcess, TestProcess4) {
    std::vector<std::string> string_list = { "@#$%^&*", "Special_Characters", "12345" };
    std::vector<std::vector<std::string>> expected_output = { {}, {"specialcharacters"}, {} };
    ASSERT_EQ(processor.process_data(string_list), expected_output);
}

TEST_F(NLPDataProcessor2TestProcess, TestProcess5) {
    std::vector<std::string> string_list = { "Hello World! %%%", "This is a %%% test. %%% ", "Hello World, this is a test. %%%" };
    std::map<std::string, int> expected_output = { {"hello", 2}, {"world", 2}, {"this", 2}, {"is", 2}, {"a", 2} };
    ASSERT_EQ(processor.process(string_list), expected_output);
}

TEST_F(NLPDataProcessor2TestProcess, TestProcess6) {
    std::vector<std::string> string_list = { "12345", "67890", "98765" };
    std::vector<std::vector<std::string>> expected_output = { {}, {}, {} };
    ASSERT_EQ(processor.process_data(string_list), expected_output);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}