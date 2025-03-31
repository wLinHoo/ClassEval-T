#include "pch.h"
#include <gtest/gtest.h>

class ManacherTestPalindromicLength : public ::testing::Test {};

TEST_F(ManacherTestPalindromicLength, PalindromicLength) {
    Manacher manacher("ababa");
    EXPECT_EQ(manacher.palindromic_length(2, 1, "a|b|a|b|a"), 2);
}

TEST_F(ManacherTestPalindromicLength, PalindromicLength2) {
    Manacher manacher("ababaxse");
    EXPECT_EQ(manacher.palindromic_length(2, 1, "a|b|a|b|a|x|s|e"), 2);
}

TEST_F(ManacherTestPalindromicLength, PalindromicLength3) {
    Manacher manacher("ababax");
    EXPECT_EQ(manacher.palindromic_length(2, 3, "a|b|a|b|a|x"), 0);
}

TEST_F(ManacherTestPalindromicLength, PalindromicLength4) {
    Manacher manacher("ababax");
    EXPECT_EQ(manacher.palindromic_length(9, 2, "a|b|a|b|a|x"), 0);
}

TEST_F(ManacherTestPalindromicLength, PalindromicLength5) {
    Manacher manacher("ababax");
    EXPECT_EQ(manacher.palindromic_length(4, 1, "a|b|a|b|a|x"), 4);
}

class ManacherTestPalindromicString : public ::testing::Test {};

TEST_F(ManacherTestPalindromicString, PalindromicString) {
    Manacher manacher("ababaxse");
    EXPECT_EQ(manacher.palindromic_string(), "ababa");
}

TEST_F(ManacherTestPalindromicString, PalindromicString2) {
    Manacher manacher("ababax");
    EXPECT_EQ(manacher.palindromic_string(), "ababa");
}

TEST_F(ManacherTestPalindromicString, PalindromicString3) {
    Manacher manacher("ababax");
    EXPECT_EQ(manacher.palindromic_string(), "ababa");
}

TEST_F(ManacherTestPalindromicString, PalindromicString4) {
    Manacher manacher("ababaxssss");
    EXPECT_EQ(manacher.palindromic_string(), "ababa");
}

TEST_F(ManacherTestPalindromicString, PalindromicString5) {
    Manacher manacher("abab");
    EXPECT_EQ(manacher.palindromic_string(), "aba");
}

class ManacherTest : public ::testing::Test {};

TEST_F(ManacherTest, MainTest) {
    Manacher manacher("ababa");
    EXPECT_EQ(manacher.palindromic_length(2, 1, "a|b|a|b|a"), 2);
    EXPECT_EQ(manacher.palindromic_string(), "ababa");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
