#include "pch.h"
#include <gtest/gtest.h>

class BigNumCalculatorTestAdd : public ::testing::Test {};

TEST_F(BigNumCalculatorTestAdd, test_add) {
    ASSERT_EQ(BigNumCalculator::add("12345678901234567890", "98765432109876543210"), "111111111011111111100");
}

TEST_F(BigNumCalculatorTestAdd, test_add_2) {
    ASSERT_EQ(BigNumCalculator::add("123456789012345678922", "98765432109876543210"), "222222221122222222132");
}

TEST_F(BigNumCalculatorTestAdd, test_add_3) {
    ASSERT_EQ(BigNumCalculator::add("123456789012345678934", "98765432109876543210"), "222222221122222222144");
}

TEST_F(BigNumCalculatorTestAdd, test_add_4) {
    ASSERT_EQ(BigNumCalculator::add("123456789012345678946", "98765432109876543210"), "222222221122222222156");
}

TEST_F(BigNumCalculatorTestAdd, test_add_5) {
    ASSERT_EQ(BigNumCalculator::add("123456789012345678958", "98765432109876543210"), "222222221122222222168");
}

class BigNumCalculatorTestSubtract : public ::testing::Test {};

TEST_F(BigNumCalculatorTestSubtract, test_subtract) {
    ASSERT_EQ(BigNumCalculator::subtract("12345678901234567890", "98765432109876543210"), "-86419753208641975320");
}

TEST_F(BigNumCalculatorTestSubtract, test_subtract_2) {
    ASSERT_EQ(BigNumCalculator::subtract("123456789012345678922", "98765432109876543210"), "24691356902469135712");
}

TEST_F(BigNumCalculatorTestSubtract, test_subtract_3) {
    ASSERT_EQ(BigNumCalculator::subtract("123456789012345678934", "98765432109876543"), "123358023580235802391");
}

TEST_F(BigNumCalculatorTestSubtract, test_subtract_4) {
    ASSERT_EQ(BigNumCalculator::subtract("12345678901234567", "98765432109876543210"), "-98753086430975308643");
}

TEST_F(BigNumCalculatorTestSubtract, test_subtract_5) {
    ASSERT_EQ(BigNumCalculator::subtract("923456789", "187654321"), "735802468");
}

class BigNumCalculatorTestMultiply : public ::testing::Test {};

TEST_F(BigNumCalculatorTestMultiply, test_multiply) {
    ASSERT_EQ(BigNumCalculator::multiply("12345678901234567890", "98765432109876543210"), "1219326311370217952237463801111263526900");
}

TEST_F(BigNumCalculatorTestMultiply, test_multiply_2) {
    ASSERT_EQ(BigNumCalculator::multiply("123456789012345678922", "98765432109876543210"), "12193263113702179524547477517529919219620");
}

TEST_F(BigNumCalculatorTestMultiply, test_multiply_3) {
    ASSERT_EQ(BigNumCalculator::multiply("123456789012345678934", "98765432109876543"), "12193263113702179499806737010255845162");
}

TEST_F(BigNumCalculatorTestMultiply, test_multiply_4) {
    ASSERT_EQ(BigNumCalculator::multiply("12345678901234567", "98765432109876543210"), "1219326311370217864336229223321140070");
}

TEST_F(BigNumCalculatorTestMultiply, test_multiply_5) {
    ASSERT_EQ(BigNumCalculator::multiply("923456789", "187654321"), "173290656712635269");
}

TEST_F(BigNumCalculatorTestMultiply, test_multiply_6) {
    ASSERT_EQ(BigNumCalculator::multiply("000000001", "000000001"), "1");
}

class BigNumCalculatorTestMain : public ::testing::Test {};

TEST_F(BigNumCalculatorTestMain, test_main) {
    ASSERT_EQ(BigNumCalculator::add("12345678901234567890", "98765432109876543210"), "111111111011111111100");
    ASSERT_EQ(BigNumCalculator::subtract("12345678901234567890", "98765432109876543210"), "-86419753208641975320");
    ASSERT_EQ(BigNumCalculator::multiply("12345678901234567890", "98765432109876543210"), "1219326311370217952237463801111263526900");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
