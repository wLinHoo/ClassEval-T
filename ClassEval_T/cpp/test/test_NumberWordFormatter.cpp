#include <gtest/gtest.h>
#include "pch.h" 

class NumberWordFormatterTestFormat : public ::testing::Test {
protected:
    NumberWordFormatter formatter;
};

TEST_F(NumberWordFormatterTestFormat, test_format_1) {
    EXPECT_EQ(formatter.format(123456),
        "ONE HUNDRED AND TWENTY THREE THOUSAND FOUR HUNDRED AND FIFTY SIX ONLY");
}

TEST_F(NumberWordFormatterTestFormat, test_format_2) {
    EXPECT_EQ(formatter.format(1000), "ONE THOUSAND ONLY");
}

TEST_F(NumberWordFormatterTestFormat, test_format_3) {
    EXPECT_EQ(formatter.format(1000000), "ONE MILLION ONLY");
}

TEST_F(NumberWordFormatterTestFormat, test_format_4) {
    EXPECT_EQ(formatter.format(1.23), "ONE AND CENTS TWENTY THREE ONLY");
}

TEST_F(NumberWordFormatterTestFormat, test_format_5) {
    EXPECT_EQ(formatter.format(0), "ZERO ONLY");
}

TEST_F(NumberWordFormatterTestFormat, test_format_6) {
    EXPECT_EQ(formatter.format(nullptr), "");
}

class NumberWordFormatterTestFormatString : public ::testing::Test {
protected:
    NumberWordFormatter formatter;
};

TEST_F(NumberWordFormatterTestFormatString, test_format_string_1) {
    EXPECT_EQ(formatter.format("123456"),
        "ONE HUNDRED AND TWENTY THREE THOUSAND FOUR HUNDRED AND FIFTY SIX ONLY");
}

TEST_F(NumberWordFormatterTestFormatString, test_format_string_2) {
    EXPECT_EQ(formatter.format("1000"), "ONE THOUSAND ONLY");
}

TEST_F(NumberWordFormatterTestFormatString, test_format_string_3) {
    EXPECT_EQ(formatter.format("1000000"), "ONE MILLION ONLY");
}

TEST_F(NumberWordFormatterTestFormatString, test_format_string_4) {
    EXPECT_EQ(formatter.format("1.23"), "ONE AND CENTS TWENTY THREE ONLY");
}

TEST_F(NumberWordFormatterTestFormatString, test_format_string_5) {
    EXPECT_EQ(formatter.format("0"), "ZERO ONLY");
}

TEST_F(NumberWordFormatterTestFormatString, test_format_string_6) {
    EXPECT_EQ(formatter.format("10"), "TEN ONLY");
}

class NumberWordFormatterTestTransTwo : public ::testing::Test {
protected:
    NumberWordFormatter formatter;
};

TEST_F(NumberWordFormatterTestTransTwo, test_trans_two_1) {
    EXPECT_EQ(formatter.trans_two("23"), "TWENTY THREE");
}

TEST_F(NumberWordFormatterTestTransTwo, test_trans_two_2) {
    EXPECT_EQ(formatter.trans_two("10"), "TEN");
}

TEST_F(NumberWordFormatterTestTransTwo, test_trans_two_3) {
    EXPECT_EQ(formatter.trans_two("05"), "FIVE");
}

TEST_F(NumberWordFormatterTestTransTwo, test_trans_two_4) {
    EXPECT_EQ(formatter.trans_two("00"), "");
}

TEST_F(NumberWordFormatterTestTransTwo, test_trans_two_5) {
    EXPECT_EQ(formatter.trans_two("01"), "ONE");
}

TEST_F(NumberWordFormatterTestTransTwo, test_trans_two_6) {
    EXPECT_EQ(formatter.trans_two("80"), "EIGHTY");
}

class NumberWordFormatterTestTransThree : public ::testing::Test {
protected:
    NumberWordFormatter formatter;
};

TEST_F(NumberWordFormatterTestTransThree, test_trans_three_1) {
    EXPECT_EQ(formatter.trans_three("123"), "ONE HUNDRED AND TWENTY THREE");
}

TEST_F(NumberWordFormatterTestTransThree, test_trans_three_2) {
    EXPECT_EQ(formatter.trans_three("900"), "NINE HUNDRED");
}

TEST_F(NumberWordFormatterTestTransThree, test_trans_three_3) {
    EXPECT_EQ(formatter.trans_three("007"), "SEVEN");
}

TEST_F(NumberWordFormatterTestTransThree, test_trans_three_4) {
    EXPECT_EQ(formatter.trans_three("001"), "ONE");
}

TEST_F(NumberWordFormatterTestTransThree, test_trans_three_5) {
    EXPECT_EQ(formatter.trans_three("006"), "SIX");
}

class NumberWordFormatterTestParseMore : public ::testing::Test {
protected:
    NumberWordFormatter formatter;
};

TEST_F(NumberWordFormatterTestParseMore, test_parse_more_1) {
    EXPECT_EQ(formatter.parse_more(0), "");
}

TEST_F(NumberWordFormatterTestParseMore, test_parse_more_2) {
    EXPECT_EQ(formatter.parse_more(1), "THOUSAND");
}

TEST_F(NumberWordFormatterTestParseMore, test_parse_more_3) {
    EXPECT_EQ(formatter.parse_more(2), "MILLION");
}

TEST_F(NumberWordFormatterTestParseMore, test_parse_more_4) {
    EXPECT_EQ(formatter.parse_more(3), "BILLION");
}

class NumberWordFormatterTest : public ::testing::Test {
protected:
    NumberWordFormatter formatter;
};

TEST_F(NumberWordFormatterTest, test_NumberWordFormatter) {
    EXPECT_EQ(formatter.format(123456),
        "ONE HUNDRED AND TWENTY THREE THOUSAND FOUR HUNDRED AND FIFTY SIX ONLY");

    EXPECT_EQ(formatter.format("123456"),
        "ONE HUNDRED AND TWENTY THREE THOUSAND FOUR HUNDRED AND FIFTY SIX ONLY");

    EXPECT_EQ(formatter.trans_two("23"), "TWENTY THREE");

    EXPECT_EQ(formatter.trans_three("123"), "ONE HUNDRED AND TWENTY THREE");

    EXPECT_EQ(formatter.parse_more(1), "THOUSAND");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}