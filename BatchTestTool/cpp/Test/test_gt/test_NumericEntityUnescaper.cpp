#include <gtest/gtest.h>
#include "pch.h" 

class NumericEntityUnescaperTestReplace : public ::testing::Test {
protected:
    NumericEntityUnescaper unescaper;
};

TEST_F(NumericEntityUnescaperTestReplace, test_replace_1) {
    std::string res = unescaper.replace("&#65;&#66;&#67;");
    EXPECT_EQ(res, "ABC");
}

TEST_F(NumericEntityUnescaperTestReplace, test_replace_2) {
    std::string res = unescaper.replace("&#65;&#65;&#65;");
    EXPECT_EQ(res, "AAA");
}

TEST_F(NumericEntityUnescaperTestReplace, test_replace_3) {
    std::string res = unescaper.replace("&#66;&#66;&#66;");
    EXPECT_EQ(res, "BBB");
}

TEST_F(NumericEntityUnescaperTestReplace, test_replace_4) {
    std::string res = unescaper.replace("&#67;&#67;&#67;");
    EXPECT_EQ(res, "CCC");
}

TEST_F(NumericEntityUnescaperTestReplace, test_replace_5) {
    std::string res = unescaper.replace("");
    EXPECT_EQ(res, "");
}

TEST_F(NumericEntityUnescaperTestReplace, test_replace_6) {
    std::string res = unescaper.replace("&#");
    EXPECT_EQ(res, "");
}

TEST_F(NumericEntityUnescaperTestReplace, test_replace_7) {
    std::string res = unescaper.replace("&#X65;&#66;&#67;");
    EXPECT_EQ(res, "eBC");
}

TEST_F(NumericEntityUnescaperTestReplace, test_replace_8) {
    std::string res = unescaper.replace("&#???;&#66;&#67;");
    EXPECT_EQ(res, "&#???;BC");
}

TEST_F(NumericEntityUnescaperTestReplace, test_replace_9) {
    std::string res = unescaper.replace("&#67;&#67;&#67;;");
    EXPECT_EQ(res, "CCC");
}

TEST_F(NumericEntityUnescaperTestReplace, test_replace_10) {
    std::string res = unescaper.replace("&#X");
    EXPECT_EQ(res, "");
}

TEST_F(NumericEntityUnescaperTestReplace, test_replace_11) {
    std::string res = unescaper.replace("&#c1d;&#66;&#67;");
    EXPECT_EQ(res, "");
}

class NumericEntityUnescaperTestIsHexChar : public ::testing::Test {
protected:
    NumericEntityUnescaper unescaper;
};

TEST_F(NumericEntityUnescaperTestIsHexChar, test_is_hex_char_1) {
    bool res = unescaper.is_hex_char('0');
    EXPECT_EQ(res, true);
}

TEST_F(NumericEntityUnescaperTestIsHexChar, test_is_hex_char_2) {
    bool res = unescaper.is_hex_char('F');
    EXPECT_EQ(res, true);
}

TEST_F(NumericEntityUnescaperTestIsHexChar, test_is_hex_char_3) {
    bool res = unescaper.is_hex_char('G');
    EXPECT_EQ(res, false);
}

TEST_F(NumericEntityUnescaperTestIsHexChar, test_is_hex_char_4) {
    bool res = unescaper.is_hex_char('X');
    EXPECT_EQ(res, false);
}

TEST_F(NumericEntityUnescaperTestIsHexChar, test_is_hex_char_5) {
    bool res = unescaper.is_hex_char('Z');
    EXPECT_EQ(res, false);
}

class UnescaperTest : public ::testing::Test {
protected:
    NumericEntityUnescaper unescaper;
};

TEST_F(UnescaperTest, test_numericentityunescaper) {
    std::string res = unescaper.replace("&#65;&#66;&#67;");
    EXPECT_EQ(res, "ABC");

    bool is_hex = unescaper.is_hex_char('0');
    EXPECT_EQ(is_hex, true);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}