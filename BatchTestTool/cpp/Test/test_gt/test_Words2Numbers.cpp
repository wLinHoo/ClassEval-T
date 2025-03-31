#include <gtest/gtest.h>
#include "pch.h"  

class Words2NumbersTestText2Int : public ::testing::Test {
protected:
    Words2Numbers w2n;  
};

TEST_F(Words2NumbersTestText2Int, test_text2int) {
    EXPECT_EQ(w2n.text2int("thirty-two"), "32");
}

TEST_F(Words2NumbersTestText2Int, test_text2int2) {
    EXPECT_EQ(w2n.text2int("one hundred and twenty-three"), "123");
}

TEST_F(Words2NumbersTestText2Int, test_text2int3) {
    EXPECT_EQ(w2n.text2int("two thousand and nineteen"), "2019");
}

TEST_F(Words2NumbersTestText2Int, test_text2int4) {
    EXPECT_EQ(w2n.text2int("one hundred and one"), "101");
}

TEST_F(Words2NumbersTestText2Int, test_text2int5) {
    EXPECT_EQ(w2n.text2int("one million and eleven"), "1000011");
}

TEST_F(Words2NumbersTestText2Int, test_text2int6) {
    EXPECT_EQ(w2n.text2int("one million one hundred sixty-ninth"), "1000169");
}

class Words2NumbersTestIsValidInput : public ::testing::Test {
protected:
    Words2Numbers w2n;  
};

TEST_F(Words2NumbersTestIsValidInput, test_is_valid_input) {
    EXPECT_TRUE(w2n.is_valid_input("twenty-five thousand three hundred and forty-two"));
}

TEST_F(Words2NumbersTestIsValidInput, test_is_valid_input2) {
    EXPECT_TRUE(w2n.is_valid_input("second hundred and third"));
}

TEST_F(Words2NumbersTestIsValidInput, test_is_valid_input3) {
    EXPECT_TRUE(w2n.is_valid_input("twenty-fifth thousand three hundred and forty-second"));
}

TEST_F(Words2NumbersTestIsValidInput, test_is_valid_input4) {
    EXPECT_FALSE(w2n.is_valid_input("eleventy thousand and five"));
}

TEST_F(Words2NumbersTestIsValidInput, test_is_valid_input5) {
    EXPECT_TRUE(w2n.is_valid_input("seventy two thousand and hundred eleven"));
}

TEST_F(Words2NumbersTestIsValidInput, test_is_valid_input6) {
    EXPECT_TRUE(w2n.is_valid_input("fifteenth hundred"));
}

class Words2NumbersTestMain : public ::testing::Test {
protected:
    Words2Numbers w2n;  
};

TEST_F(Words2NumbersTestMain, test_main) {
    EXPECT_EQ(w2n.is_valid_input("seventy two thousand and hundred eleven"), true);
    EXPECT_EQ(w2n.text2int("seventy two thousand and hundred eleven"), "72011");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}