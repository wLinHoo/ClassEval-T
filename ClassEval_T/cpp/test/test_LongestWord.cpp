#include <gtest/gtest.h>
#include <vector>
#include <string>
#include <algorithm>
#include "pch.h" 

class LongestWordTestAddWord : public ::testing::Test {
protected:
    LongestWord longestWord;
};

TEST_F(LongestWordTestAddWord, test_add_word_1) {
    longestWord.add_word("hello");
    std::vector<std::string> expected = { "hello" };
    EXPECT_EQ(expected, longestWord.get_word_list());
}

TEST_F(LongestWordTestAddWord, test_add_word_2) {
    longestWord.add_word("hello");
    longestWord.add_word("world");
    std::vector<std::string> expected = { "hello", "world" };
    EXPECT_EQ(expected, longestWord.get_word_list());
}

TEST_F(LongestWordTestAddWord, test_add_word_3) {
    longestWord.add_word("hello");
    longestWord.add_word("world");
    longestWord.add_word("!");
    std::vector<std::string> expected = { "hello", "world", "!" };
    EXPECT_EQ(expected, longestWord.get_word_list());
}

TEST_F(LongestWordTestAddWord, test_add_word_4) {
    longestWord.add_word("hello");
    longestWord.add_word("world");
    longestWord.add_word("!");
    longestWord.add_word("!");
    std::vector<std::string> expected = { "hello", "world", "!", "!" };
    EXPECT_EQ(expected, longestWord.get_word_list());
}

TEST_F(LongestWordTestAddWord, test_add_word_5) {
    longestWord.add_word("hello");
    longestWord.add_word("world");
    longestWord.add_word("!");
    longestWord.add_word("!");
    longestWord.add_word("!");
    std::vector<std::string> expected = { "hello", "world", "!", "!", "!" };
    EXPECT_EQ(expected, longestWord.get_word_list());
}

class LongestWordTestFindLongestWord : public ::testing::Test {
protected:
    LongestWord longestWord;
};

TEST_F(LongestWordTestFindLongestWord, test_find_longest_word_1) {
    longestWord.add_word("a");
    std::string sentence = "I am a student.";
    EXPECT_EQ("a", longestWord.find_longest_word(sentence));
}

TEST_F(LongestWordTestFindLongestWord, test_find_longest_word_2) {
    std::string sentence = "I am a student.";
    EXPECT_EQ("", longestWord.find_longest_word(sentence));
}

TEST_F(LongestWordTestFindLongestWord, test_find_longest_word_3) {
    longestWord.add_word("student");
    std::string sentence = "I am a student.";
    EXPECT_EQ("student", longestWord.find_longest_word(sentence));
}

TEST_F(LongestWordTestFindLongestWord, test_find_longest_word_4) {
    longestWord.add_word("apple");
    std::string sentence = "Apple is red.";
    EXPECT_EQ("apple", longestWord.find_longest_word(sentence));
}

TEST_F(LongestWordTestFindLongestWord, test_find_longest_word_5) {
    longestWord.add_word("apple");
    longestWord.add_word("red");
    std::string sentence = "Apple is red.";
    EXPECT_EQ("apple", longestWord.find_longest_word(sentence));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}