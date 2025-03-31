#include "pch.h"
#include <gtest/gtest.h>

class DecryptionUtilsTestCaesarDecipher : public ::testing::Test {
protected:
    DecryptionUtils d = DecryptionUtils("key");
};

TEST_F(DecryptionUtilsTestCaesarDecipher, test_caesar_decipher) {
    EXPECT_EQ(d.caesar_decipher("ifmmp", 1), "hello");
}

TEST_F(DecryptionUtilsTestCaesarDecipher, test_caesar_decipher_2) {
    EXPECT_EQ(d.caesar_decipher("bcdyza", 27), "abcxyz");
}

TEST_F(DecryptionUtilsTestCaesarDecipher, test_caesar_decipher_3) {
    EXPECT_EQ(d.caesar_decipher("bcd", 0), "bcd");
}

TEST_F(DecryptionUtilsTestCaesarDecipher, test_caesar_decipher_4) {
    EXPECT_EQ(d.caesar_decipher("bcd", 26), "bcd");
}

TEST_F(DecryptionUtilsTestCaesarDecipher, test_caesar_decipher_5) {
    EXPECT_EQ(d.caesar_decipher("bcd", -26), "bcd");
}

TEST_F(DecryptionUtilsTestCaesarDecipher, test_caesar_decipher_6) {
    EXPECT_EQ(d.caesar_decipher("IFMMP", 1), "HELLO");
}

TEST_F(DecryptionUtilsTestCaesarDecipher, test_caesar_decipher_7) {
    EXPECT_EQ(d.caesar_decipher("123", 1), "123");
}

class DecryptionUtilsTestVigenereDecipher : public ::testing::Test {
protected:
    DecryptionUtils d = DecryptionUtils("key");
};

TEST_F(DecryptionUtilsTestVigenereDecipher, test_vigenere_decipher) {
    EXPECT_EQ(d.vigenere_decipher("ifmmp"), "ybocl");
}

TEST_F(DecryptionUtilsTestVigenereDecipher, test_vigenere_decipher_2) {
    EXPECT_EQ(d.vigenere_decipher("rijvs"), "hello");
}

TEST_F(DecryptionUtilsTestVigenereDecipher, test_vigenere_decipher_3) {
    DecryptionUtils d2 = DecryptionUtils("longkey");
    EXPECT_EQ(d2.vigenere_decipher("LpPjOjE"), "AbCdEfG");
}

TEST_F(DecryptionUtilsTestVigenereDecipher, test_vigenere_decipher_4) {
    EXPECT_EQ(d.vigenere_decipher("bcd"), "ryf");
}

TEST_F(DecryptionUtilsTestVigenereDecipher, test_vigenere_decipher_5) {
    EXPECT_EQ(d.vigenere_decipher("bcdaa"), "ryfqw");
}

TEST_F(DecryptionUtilsTestVigenereDecipher, test_vigenere_decipher_6) {
    EXPECT_EQ(d.vigenere_decipher("123"), "123");
}

class DecryptionUtilsTestRailFenceDecipher : public ::testing::Test {
protected:
    DecryptionUtils d = DecryptionUtils("key");
};

TEST_F(DecryptionUtilsTestRailFenceDecipher, test_rail_fence_decipher) {
    EXPECT_EQ(d.rail_fence_decipher("Hoo!el,Wrdl l", 3), "Hello, World!");
}

TEST_F(DecryptionUtilsTestRailFenceDecipher, test_rail_fence_decipher_2) {
    EXPECT_EQ(d.rail_fence_decipher("Hoo!el,Wrdl l", 4), "H!W reoldll,o");
}

TEST_F(DecryptionUtilsTestRailFenceDecipher, test_rail_fence_decipher_3) {
    EXPECT_EQ(d.rail_fence_decipher("Hoo!el,Wrdl l", 5), "Holr d,!oeWll");
}

TEST_F(DecryptionUtilsTestRailFenceDecipher, test_rail_fence_decipher_4) {
    EXPECT_EQ(d.rail_fence_decipher("Hoo!el,Wrdl l", 6), "Holrll d,!oeW");
}

TEST_F(DecryptionUtilsTestRailFenceDecipher, test_rail_fence_decipher_5) {
    EXPECT_EQ(d.rail_fence_decipher("Hoo!el,Wrdl l", 7), "Hoe,rll dWl!o");
}

class DecryptionUtilsTestMain : public ::testing::Test {
protected:
    DecryptionUtils d = DecryptionUtils("key");
};

TEST_F(DecryptionUtilsTestMain, test_main) {
    EXPECT_EQ(d.caesar_decipher("ifmmp", 1), "hello");
    EXPECT_EQ(d.vigenere_decipher("ifmmp"), "ybocl");
    EXPECT_EQ(d.rail_fence_decipher("Hoo!el,Wrdl l", 3), "Hello, World!");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
