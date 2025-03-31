#include <gtest/gtest.h>
#include "pch.h"  

class SplitSentenceTestSplitSentences : public ::testing::Test {
protected:
    SplitSentence ss;
};

TEST_F(SplitSentenceTestSplitSentences, test_split_sentences_1) {
    std::vector<std::string> lst = ss.split_sentences("aaa aaaa. bb bbbb bbb? cccc cccc. dd ddd?");
    std::vector<std::string> expected = { "aaa aaaa.", "bb bbbb bbb?", "cccc cccc.", "dd ddd?" };
    EXPECT_EQ(lst, expected);
}

TEST_F(SplitSentenceTestSplitSentences, test_split_sentences_2) {
    std::vector<std::string> lst = ss.split_sentences("Who is Mr. Smith? He is a teacher.");
    std::vector<std::string> expected = { "Who is Mr. Smith?", "He is a teacher." };
    EXPECT_EQ(lst, expected);
}

TEST_F(SplitSentenceTestSplitSentences, test_split_sentences_3) {
    std::vector<std::string> lst = ss.split_sentences("Who is A.B.C.? He is a teacher.");
    std::vector<std::string> expected = { "Who is A.B.C.?", "He is a teacher." };
    EXPECT_EQ(lst, expected);
}

TEST_F(SplitSentenceTestSplitSentences, test_split_sentences_4) {
    std::vector<std::string> lst = ss.split_sentences("aaa aaaa. bb bbbb bbb? cccc cccc.");
    std::vector<std::string> expected = { "aaa aaaa.", "bb bbbb bbb?", "cccc cccc." };
    EXPECT_EQ(lst, expected);
}

TEST_F(SplitSentenceTestSplitSentences, test_split_sentences_5) {
    std::vector<std::string> lst = ss.split_sentences("aaa aaaa. bb bbbb bbb?");
    std::vector<std::string> expected = { "aaa aaaa.", "bb bbbb bbb?" };
    EXPECT_EQ(lst, expected);
}

class SplitSentenceTestCountWords : public ::testing::Test {
protected:
    SplitSentence ss;
};

TEST_F(SplitSentenceTestCountWords, test_count_words_1) {
    int cnt = ss.count_words("abc def");
    EXPECT_EQ(cnt, 2);
}

TEST_F(SplitSentenceTestCountWords, test_count_words_2) {
    int cnt = ss.count_words("abc def 1");
    EXPECT_EQ(cnt, 2);
}

TEST_F(SplitSentenceTestCountWords, test_count_words_3) {
    int cnt = ss.count_words("abc 1");
    EXPECT_EQ(cnt, 1);
}

TEST_F(SplitSentenceTestCountWords, test_count_words_4) {
    int cnt = ss.count_words("abc def bbb1");
    EXPECT_EQ(cnt, 3);
}

TEST_F(SplitSentenceTestCountWords, test_count_words_5) {
    int cnt = ss.count_words("abc def 111");
    EXPECT_EQ(cnt, 2);
}

class SplitSentenceTestProcessTextFile : public ::testing::Test {
protected:
    SplitSentence ss;
};

TEST_F(SplitSentenceTestProcessTextFile, test_process_text_file_1) {
    int cnt = ss.process_text_file("aaa aaaa. bb bbbb bbb? cccc ccccccc cc ccc.");
    EXPECT_EQ(cnt, 4);
}

TEST_F(SplitSentenceTestProcessTextFile, test_process_text_file_2) {
    int cnt = ss.process_text_file("Mr. Smith is a teacher. Yes.");
    EXPECT_EQ(cnt, 5);
}

TEST_F(SplitSentenceTestProcessTextFile, test_process_text_file_3) {
    int cnt = ss.process_text_file("Mr. Smith is a teacher. Yes 1 2 3 4 5 6.");
    EXPECT_EQ(cnt, 5);
}

TEST_F(SplitSentenceTestProcessTextFile, test_process_text_file_4) {
    int cnt = ss.process_text_file("aaa aaaa. bb bbbb bbb? cccc ccccccc cc ccc.");
    EXPECT_EQ(cnt, 4);
}

TEST_F(SplitSentenceTestProcessTextFile, test_process_text_file_5) {
    int cnt = ss.process_text_file("aaa aaaa. bb bbbb bbb?");
    EXPECT_EQ(cnt, 3);
}

class SplitSentenceTest : public ::testing::Test {
protected:
    SplitSentence ss;
};

TEST_F(SplitSentenceTest, test_SplitSentence) {
    std::vector<std::string> lst = ss.split_sentences("aaa aaaa. bb bbbb bbb? cccc cccc. dd ddd?");
    std::vector<std::string> expected = { "aaa aaaa.", "bb bbbb bbb?", "cccc cccc.", "dd ddd?" };
    EXPECT_EQ(lst, expected);

    int cnt = ss.count_words("abc def");
    EXPECT_EQ(cnt, 2);

    cnt = ss.process_text_file("aaa aaaa. bb bbbb bbb? cccc ccccccc cc ccc. dd ddd?");
    EXPECT_EQ(cnt, 4);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}