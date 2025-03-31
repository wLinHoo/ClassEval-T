#include <gtest/gtest.h>
#include "pch.h"

class NLPDataProcessorTestConstruct : public ::testing::Test {
protected:
    void SetUp() override {
        processor = new NLPDataProcessor();
    }

    void TearDown() override {
        delete processor;
    }

    NLPDataProcessor* processor;
};

TEST_F(NLPDataProcessorTestConstruct, test_construct_stop_word_list) {
    std::vector<std::string> stop_word_list = processor->construct_stop_word_list();
    std::vector<std::string> expected_stop_words = { "a", "an", "the" };
    EXPECT_EQ(stop_word_list, expected_stop_words);
}

class NLPDataProcessorTestRemove : public ::testing::Test {
protected:
    void SetUp() override {
        processor = new NLPDataProcessor();
    }

    void TearDown() override {
        delete processor;
    }

    NLPDataProcessor* processor;
};

TEST_F(NLPDataProcessorTestRemove, test_remove_stop_words) {
    std::vector<std::string> string_list = { "This is a test", "This is an apple", "This is the dog" };
    std::vector<std::string> stop_word_list = { "a", "an", "the" };
    std::vector<std::vector<std::string>> words_list = processor->remove_stop_words(string_list, stop_word_list);
    std::vector<std::vector<std::string>> expected_words_list = { {"This", "is", "test"}, {"This", "is", "apple"}, {"This", "is", "dog"} };
    EXPECT_EQ(words_list, expected_words_list);
}

TEST_F(NLPDataProcessorTestRemove, test_remove_stop_words_2) {
    std::vector<std::string> string_list = { "a", "an", "the" };
    std::vector<std::string> stop_word_list = { "a", "an", "the" };
    std::vector<std::vector<std::string>> words_list = processor->remove_stop_words(string_list, stop_word_list);
    std::vector<std::vector<std::string>> expected_words_list = { {}, {}, {} };
    EXPECT_EQ(words_list, expected_words_list);
}

TEST_F(NLPDataProcessorTestRemove, test_remove_stop_words_3) {
    std::vector<std::string> string_list = {};
    std::vector<std::string> stop_word_list = { "a", "an", "the" };
    std::vector<std::vector<std::string>> words_list = processor->remove_stop_words(string_list, stop_word_list);
    std::vector<std::vector<std::string>> expected_words_list = {};
    EXPECT_EQ(words_list, expected_words_list);
}

TEST_F(NLPDataProcessorTestRemove, test_remove_stop_words_4) {
    std::vector<std::string> string_list = { "This is a test", "This is an apple", "This is the dog" };
    std::vector<std::string> stop_word_list = {};
    std::vector<std::vector<std::string>> words_list = processor->remove_stop_words(string_list, stop_word_list);
    std::vector<std::vector<std::string>> expected_words_list = { {"This", "is", "a", "test"}, {"This", "is", "an", "apple"}, {"This", "is", "the", "dog"} };
    EXPECT_EQ(words_list, expected_words_list);
}

TEST_F(NLPDataProcessorTestRemove, test_remove_stop_words_5) {
    std::vector<std::string> string_list = { "This is a test", "This is an apple", "This is the dog" };
    std::vector<std::string> stop_word_list = { "a", "an", "the", "This", "is" };
    std::vector<std::vector<std::string>> words_list = processor->remove_stop_words(string_list, stop_word_list);
    std::vector<std::vector<std::string>> expected_words_list = { {"test"}, {"apple"}, {"dog"} };
    EXPECT_EQ(words_list, expected_words_list);
}

class NLPDataProcessorTestProcess : public ::testing::Test {
protected:
    void SetUp() override {
        processor = new NLPDataProcessor();
    }

    void TearDown() override {
        delete processor;
    }

    NLPDataProcessor* processor;
};

TEST_F(NLPDataProcessorTestProcess, test_process) {
    std::vector<std::string> string_list = { "This is a test.", "This is an apple.", "This is the dog." };
    std::vector<std::vector<std::string>> words_list = processor->process(string_list);
    std::vector<std::vector<std::string>> expected_words_list = { {"This", "is", "test."}, {"This", "is", "apple."}, {"This", "is", "dog."} };
    EXPECT_EQ(words_list, expected_words_list);
}

TEST_F(NLPDataProcessorTestProcess, test_process_with_empty_string_list) {
    std::vector<std::string> string_list = {};
    std::vector<std::vector<std::string>> words_list = processor->process(string_list);
    std::vector<std::vector<std::string>> expected_words_list = {};
    EXPECT_EQ(words_list, expected_words_list);
}

TEST_F(NLPDataProcessorTestProcess, test_process_with_single_word_sentences) {
    std::vector<std::string> string_list = { "Hello aa", "World" };
    std::vector<std::vector<std::string>> words_list = processor->process(string_list);
    std::vector<std::vector<std::string>> expected_words_list = { {"Hello", "aa"}, {"World"} };
    EXPECT_EQ(words_list, expected_words_list);
}

TEST_F(NLPDataProcessorTestProcess, test_process_with_stop_words_only) {
    std::vector<std::string> string_list = { "a", "an", "the" };
    std::vector<std::vector<std::string>> words_list = processor->process(string_list);
    std::vector<std::vector<std::string>> expected_words_list = { {}, {}, {} };
    EXPECT_EQ(words_list, expected_words_list);
}

TEST_F(NLPDataProcessorTestProcess, test_process_with_stop_words_only_2) {
    std::vector<std::string> string_list = { "a", "an", "the", "This" };
    std::vector<std::vector<std::string>> words_list = processor->process(string_list);
    std::vector<std::vector<std::string>> expected_words_list = { {}, {}, {}, {"This"} };
    EXPECT_EQ(words_list, expected_words_list);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}