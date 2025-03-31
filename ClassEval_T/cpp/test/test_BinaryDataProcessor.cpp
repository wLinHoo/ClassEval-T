#include "pch.h"
#include <gtest/gtest.h>

class BinaryDataProcessorTestCleanNonBinaryChars : public ::testing::Test {};

TEST_F(BinaryDataProcessorTestCleanNonBinaryChars, TestCleanNonBinaryChars) {
    BinaryDataProcessor bdp("01101000daf3e4r01100101011011000110110001101111");
    EXPECT_EQ(bdp.binary_string, "0110100001100101011011000110110001101111");
}

TEST_F(BinaryDataProcessorTestCleanNonBinaryChars, TestCleanNonBinaryChars2) {
    BinaryDataProcessor bdp("01101000daf3e4r01100101011011addf0110001d1111");
    EXPECT_EQ(bdp.binary_string, "011010000110010101101101100011111");
}

TEST_F(BinaryDataProcessorTestCleanNonBinaryChars, TestCleanNonBinaryChars3) {
    BinaryDataProcessor bdp("0sd1000daf3e4r01100101011011addf0110001d1111");
    EXPECT_EQ(bdp.binary_string, "010000110010101101101100011111");
}

TEST_F(BinaryDataProcessorTestCleanNonBinaryChars, TestCleanNonBinaryChars4) {
    BinaryDataProcessor bdp("sdsdf");
    EXPECT_EQ(bdp.binary_string, "");
}

TEST_F(BinaryDataProcessorTestCleanNonBinaryChars, TestCleanNonBinaryChars5) {
    BinaryDataProcessor bdp("0");
    EXPECT_EQ(bdp.binary_string, "0");
}

class BinaryDataProcessorTestCalculateBinaryInfo : public ::testing::Test {};

TEST_F(BinaryDataProcessorTestCalculateBinaryInfo, TestCalculateBinaryInfo) {
    BinaryDataProcessor bdp("0110100001100101011011000110110001101111");
    auto result = bdp.calculate_binary_info();
    EXPECT_EQ(result["Zeroes"], 0.475);
    EXPECT_EQ(result["Ones"], 0.525);
    EXPECT_EQ(result["Bit length"], 40);
}

TEST_F(BinaryDataProcessorTestCalculateBinaryInfo, TestCalculateBinaryInfo2) {
    BinaryDataProcessor bdp("0110100001100101011010011111");
    auto result = bdp.calculate_binary_info();
    EXPECT_EQ(result["Bit length"], 28);
    EXPECT_NEAR(result["Ones"], 0.5357142857142857, 1e-9);
    EXPECT_NEAR(result["Zeroes"], 0.4642857142857143, 1e-9);
}

TEST_F(BinaryDataProcessorTestCalculateBinaryInfo, TestCalculateBinaryInfo3) {
    BinaryDataProcessor bdp("01101001111100101011010011111");
    auto result = bdp.calculate_binary_info();
    EXPECT_EQ(result["Bit length"], 29);
    EXPECT_NEAR(result["Ones"], 0.6206896551724138, 1e-9);
    EXPECT_NEAR(result["Zeroes"], 0.3793103448275862, 1e-9);
}

TEST_F(BinaryDataProcessorTestCalculateBinaryInfo, TestCalculateBinaryInfo4) {
    BinaryDataProcessor bdp("011010011111001");
    auto result = bdp.calculate_binary_info();
    EXPECT_EQ(result["Bit length"], 15);
    EXPECT_EQ(result["Ones"], 0.6);
    EXPECT_EQ(result["Zeroes"], 0.4);
}

TEST_F(BinaryDataProcessorTestCalculateBinaryInfo, TestCalculateBinaryInfo5) {
    BinaryDataProcessor bdp("0110100111110010");
    auto result = bdp.calculate_binary_info();
    EXPECT_EQ(result["Bit length"], 16);
    EXPECT_EQ(result["Ones"], 0.5625);
    EXPECT_EQ(result["Zeroes"], 0.4375);
}

class BinaryDataProcessorTestConvertToAscii : public ::testing::Test {};

TEST_F(BinaryDataProcessorTestConvertToAscii, TestConvertToAscii) {
    BinaryDataProcessor bdp("0110100001100101011011000110110001101111");
    EXPECT_EQ(bdp.convert_to_ascii(), "hello");
}

TEST_F(BinaryDataProcessorTestConvertToAscii, TestConvertToAscii2) {
    BinaryDataProcessor bdp("0110100000100101011011000110110001101111");
    EXPECT_EQ(bdp.convert_to_ascii(), "h%llo");
}

TEST_F(BinaryDataProcessorTestConvertToAscii, TestConvertToAscii3) {
    BinaryDataProcessor bdp("01101000011011010110001001101111");
    EXPECT_EQ(bdp.convert_to_ascii(), "hmbo");
}

TEST_F(BinaryDataProcessorTestConvertToAscii, TestConvertToAscii4) {
    BinaryDataProcessor bdp("01101000011001010110001001101111");
    EXPECT_EQ(bdp.convert_to_ascii(), "hebo");
}

TEST_F(BinaryDataProcessorTestConvertToAscii, TestConvertToAscii5) {
    BinaryDataProcessor bdp("0110100001100101011011000110110001101111");
    EXPECT_EQ(bdp.convert_to_ascii(), "hello");
}

class BinaryDataProcessorTestConvertToUtf8 : public ::testing::Test {};

TEST_F(BinaryDataProcessorTestConvertToUtf8, TestConvertToUtf8) {
    BinaryDataProcessor bdp("0110100001100101011011000110110001101111");
    EXPECT_EQ(bdp.convert_to_utf8(), "hello");
}

TEST_F(BinaryDataProcessorTestConvertToUtf8, TestConvertToUtf8_2) {
    BinaryDataProcessor bdp("0110100001100101011011000110110001101001");
    EXPECT_EQ(bdp.convert_to_utf8(), "helli");
}

TEST_F(BinaryDataProcessorTestConvertToUtf8, TestConvertToUtf8_3) {
    BinaryDataProcessor bdp("0110000001100101011011000110110001101111");
    EXPECT_EQ(bdp.convert_to_utf8(), "`ello");
}

TEST_F(BinaryDataProcessorTestConvertToUtf8, TestConvertToUtf8_4) {
    BinaryDataProcessor bdp("0110101101100101011011000110110001101111");
    EXPECT_EQ(bdp.convert_to_utf8(), "kello");
}

TEST_F(BinaryDataProcessorTestConvertToUtf8, TestConvertToUtf8_5) {
    BinaryDataProcessor bdp("0110101101100100011011000110110001101111");
    EXPECT_EQ(bdp.convert_to_utf8(), "kdllo");
}

class BinaryDataProcessorTestMain : public ::testing::Test {};

TEST_F(BinaryDataProcessorTestMain, TestMain) {
    BinaryDataProcessor bdp("01101000daf3e4r01100101011011000110110001101111");
    EXPECT_EQ(bdp.binary_string, "0110100001100101011011000110110001101111");
    auto result = bdp.calculate_binary_info();
    EXPECT_EQ(result["Zeroes"], 0.475);
    EXPECT_EQ(result["Ones"], 0.525);
    EXPECT_EQ(result["Bit length"], 40);
    EXPECT_EQ(bdp.convert_to_ascii(), "hello");
    EXPECT_EQ(bdp.convert_to_utf8(), "hello");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}