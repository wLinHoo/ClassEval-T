#include <gtest/gtest.h>
#include <string>
#include "pch.h"

class NumberConverterTestDecimalToBinary : public ::testing::Test {};

TEST_F(NumberConverterTestDecimalToBinary, TestDecimalToBinary) {
    ASSERT_EQ("1010010110110111", NumberConverter::decimal_to_binary(42423));
}

TEST_F(NumberConverterTestDecimalToBinary, TestDecimalToBinary2) {
    ASSERT_EQ("101001100010111", NumberConverter::decimal_to_binary(21271));
}

TEST_F(NumberConverterTestDecimalToBinary, TestDecimalToBinary3) {
    ASSERT_EQ("1010010111010111", NumberConverter::decimal_to_binary(42455));
}

TEST_F(NumberConverterTestDecimalToBinary, TestDecimalToBinary4) {
    ASSERT_EQ("10100101110101011", NumberConverter::decimal_to_binary(84907));
}

TEST_F(NumberConverterTestDecimalToBinary, TestDecimalToBinary5) {
    ASSERT_EQ("101001011101010111", NumberConverter::decimal_to_binary(169815));
}

class NumberConverterTestBinaryToDecimal : public ::testing::Test {};

TEST_F(NumberConverterTestBinaryToDecimal, TestBinaryToDecimal) {
    ASSERT_EQ(42423, NumberConverter::binary_to_decimal("1010010110110111"));
}

TEST_F(NumberConverterTestBinaryToDecimal, TestBinaryToDecimal2) {
    ASSERT_EQ(10615, NumberConverter::binary_to_decimal("10100101110111"));
}

TEST_F(NumberConverterTestBinaryToDecimal, TestBinaryToDecimal3) {
    ASSERT_EQ(42455, NumberConverter::binary_to_decimal("1010010111010111"));
}

TEST_F(NumberConverterTestBinaryToDecimal, TestBinaryToDecimal4) {
    ASSERT_EQ(169819, NumberConverter::binary_to_decimal("101001011101011011"));
}

TEST_F(NumberConverterTestBinaryToDecimal, TestBinaryToDecimal5) {
    ASSERT_EQ(339639, NumberConverter::binary_to_decimal("1010010111010110111"));
}

class NumberConverterTestDecimalToOctal : public ::testing::Test {};

TEST_F(NumberConverterTestDecimalToOctal, TestDecimalToOctal) {
    ASSERT_EQ("122667", NumberConverter::decimal_to_octal(42423));
}

TEST_F(NumberConverterTestDecimalToOctal, TestDecimalToOctal2) {
    ASSERT_EQ("51427", NumberConverter::decimal_to_octal(21271));
}

TEST_F(NumberConverterTestDecimalToOctal, TestDecimalToOctal3) {
    ASSERT_EQ("245653", NumberConverter::decimal_to_octal(84907));
}

TEST_F(NumberConverterTestDecimalToOctal, TestDecimalToOctal4) {
    ASSERT_EQ("513527", NumberConverter::decimal_to_octal(169815));
}

TEST_F(NumberConverterTestDecimalToOctal, TestDecimalToOctal5) {
    ASSERT_EQ("1227256", NumberConverter::decimal_to_octal(339630));
}

class NumberConverterTestOctalToDecimal : public ::testing::Test {};

TEST_F(NumberConverterTestOctalToDecimal, TestOctalToDecimal) {
    ASSERT_EQ(42423, NumberConverter::octal_to_decimal("122667"));
}

TEST_F(NumberConverterTestOctalToDecimal, TestOctalToDecimal2) {
    ASSERT_EQ(21271, NumberConverter::octal_to_decimal("51427"));
}

TEST_F(NumberConverterTestOctalToDecimal, TestOctalToDecimal3) {
    ASSERT_EQ(84907, NumberConverter::octal_to_decimal("245653"));
}

TEST_F(NumberConverterTestOctalToDecimal, TestOctalToDecimal4) {
    ASSERT_EQ(169815, NumberConverter::octal_to_decimal("513527"));
}

TEST_F(NumberConverterTestOctalToDecimal, TestOctalToDecimal5) {
    ASSERT_EQ(339630, NumberConverter::octal_to_decimal("1227256"));
}

class NumberConverterTestDecimalToHex : public ::testing::Test {};

TEST_F(NumberConverterTestDecimalToHex, TestDecimalToHex) {
    ASSERT_EQ("a5b7", NumberConverter::decimal_to_hex(42423));
}

TEST_F(NumberConverterTestDecimalToHex, TestDecimalToHex2) {
    ASSERT_EQ("5317", NumberConverter::decimal_to_hex(21271));
}

TEST_F(NumberConverterTestDecimalToHex, TestDecimalToHex3) {
    ASSERT_EQ("14bab", NumberConverter::decimal_to_hex(84907));
}

TEST_F(NumberConverterTestDecimalToHex, TestDecimalToHex4) {
    ASSERT_EQ("29757", NumberConverter::decimal_to_hex(169815));
}

TEST_F(NumberConverterTestDecimalToHex, TestDecimalToHex5) {
    ASSERT_EQ("52eb7", NumberConverter::decimal_to_hex(339639));
}

class NumberConverterTestHexToDecimal : public ::testing::Test {};

TEST_F(NumberConverterTestHexToDecimal, TestHexToDecimal) {
    ASSERT_EQ(42423, NumberConverter::hex_to_decimal("a5b7"));
}

TEST_F(NumberConverterTestHexToDecimal, TestHexToDecimal2) {
    ASSERT_EQ(21207, NumberConverter::hex_to_decimal("52d7"));
}

TEST_F(NumberConverterTestHexToDecimal, TestHexToDecimal3) {
    ASSERT_EQ(84627, NumberConverter::hex_to_decimal("14a93"));
}

TEST_F(NumberConverterTestHexToDecimal, TestHexToDecimal4) {
    ASSERT_EQ(170615, NumberConverter::hex_to_decimal("29a77"));
}

TEST_F(NumberConverterTestHexToDecimal, TestHexToDecimal5) {
    ASSERT_EQ(342647, NumberConverter::hex_to_decimal("53a77"));
}

class NumberConverterTestMain : public ::testing::Test {};

TEST_F(NumberConverterTestMain, TestMain) {
    ASSERT_EQ("1010010110110111", NumberConverter::decimal_to_binary(42423));
    ASSERT_EQ(42423, NumberConverter::binary_to_decimal("1010010110110111"));
    ASSERT_EQ("122667", NumberConverter::decimal_to_octal(42423));
    ASSERT_EQ("122667", NumberConverter::decimal_to_octal(42423));
    ASSERT_EQ("a5b7", NumberConverter::decimal_to_hex(42423));
    ASSERT_EQ(42423, NumberConverter::hex_to_decimal("a5b7"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}