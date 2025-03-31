#include <gtest/gtest.h>
#include "pch.h" 

class ComplexCalculatorTestAdd : public ::testing::Test {
protected:
    ComplexCalculator complexCalculator;
};

TEST_F(ComplexCalculatorTestAdd, test_add) {
    EXPECT_EQ(complexCalculator.add({ 1, 2 }, { 3, 4 }), std::complex<double>(4, 6));
}

TEST_F(ComplexCalculatorTestAdd, test_add_2) {
    EXPECT_EQ(complexCalculator.add({ -1, -2 }, { -3, -4 }), std::complex<double>(-4, -6));
}

TEST_F(ComplexCalculatorTestAdd, test_add_3) {
    EXPECT_EQ(complexCalculator.add({ 1, -2 }, { 3, -4 }), std::complex<double>(4, -6));
}

TEST_F(ComplexCalculatorTestAdd, test_add_4) {
    EXPECT_EQ(complexCalculator.add({ -1, 2 }, { -3, 4 }), std::complex<double>(-4, 6));
}

TEST_F(ComplexCalculatorTestAdd, test_add_5) {
    EXPECT_EQ(complexCalculator.add({ 1, 2 }, { -1, -2 }), std::complex<double>(0, 0));
}

class ComplexCalculatorTestSubtract : public ::testing::Test {
protected:
    ComplexCalculator complexCalculator;
};

TEST_F(ComplexCalculatorTestSubtract, test_subtract) {
    EXPECT_EQ(complexCalculator.subtract({ 1, 2 }, { 3, 4 }), std::complex<double>(-2, -2));
}

TEST_F(ComplexCalculatorTestSubtract, test_subtract_2) {
    EXPECT_EQ(complexCalculator.subtract({ -1, -2 }, { -3, -4 }), std::complex<double>(2, 2));
}

TEST_F(ComplexCalculatorTestSubtract, test_subtract_3) {
    EXPECT_EQ(complexCalculator.subtract({ 1, -2 }, { 3, -4 }), std::complex<double>(-2, 2));
}

TEST_F(ComplexCalculatorTestSubtract, test_subtract_4) {
    EXPECT_EQ(complexCalculator.subtract({ -1, 2 }, { -3, 4 }), std::complex<double>(2, -2));
}

TEST_F(ComplexCalculatorTestSubtract, test_subtract_5) {
    EXPECT_EQ(complexCalculator.subtract({ 1, 2 }, { 1, 2 }), std::complex<double>(0, 0));
}

class ComplexCalculatorTestMultiply : public ::testing::Test {
protected:
    ComplexCalculator complexCalculator;
};

TEST_F(ComplexCalculatorTestMultiply, test_multiply) {
    EXPECT_EQ(complexCalculator.multiply({ 1, 2 }, { 3, 4 }), std::complex<double>(-5, 10));
}

TEST_F(ComplexCalculatorTestMultiply, test_multiply_2) {
    EXPECT_EQ(complexCalculator.multiply({ -1, -2 }, { -3, -4 }), std::complex<double>(-5, 10));
}

TEST_F(ComplexCalculatorTestMultiply, test_multiply_3) {
    EXPECT_EQ(complexCalculator.multiply({ 1, -2 }, { 3, -4 }), std::complex<double>(-5, -10));
}

TEST_F(ComplexCalculatorTestMultiply, test_multiply_4) {
    EXPECT_EQ(complexCalculator.multiply({ -1, 2 }, { -3, 4 }), std::complex<double>(-5, -10));
}

TEST_F(ComplexCalculatorTestMultiply, test_multiply_5) {
    EXPECT_EQ(complexCalculator.multiply({ 1, 2 }, { -1, -2 }), std::complex<double>(3, -4));
}

class ComplexCalculatorTestDivide : public ::testing::Test {
protected:
    ComplexCalculator complexCalculator;
};

TEST_F(ComplexCalculatorTestDivide, test_divide) {
    EXPECT_EQ(complexCalculator.divide({ 1, 2 }, { 3, 4 }), std::complex<double>(0.44, 0.08));
}

TEST_F(ComplexCalculatorTestDivide, test_divide_2) {
    EXPECT_EQ(complexCalculator.divide({ -1, -2 }, { -3, -4 }), std::complex<double>(0.44, 0.08));
}

TEST_F(ComplexCalculatorTestDivide, test_divide_3) {
    EXPECT_EQ(complexCalculator.divide({ 1, -2 }, { 3, -4 }), std::complex<double>(0.44, -0.08));
}

TEST_F(ComplexCalculatorTestDivide, test_divide_4) {
    EXPECT_EQ(complexCalculator.divide({ -1, 2 }, { -3, 4 }), std::complex<double>(0.44, -0.08));
}

TEST_F(ComplexCalculatorTestDivide, test_divide_5) {
    EXPECT_EQ(complexCalculator.divide({ 1, 2 }, { -1, -2 }), std::complex<double>(-1, 0));
}

class ComplexCalculatorTestMain : public ::testing::Test {
protected:
    ComplexCalculator complexCalculator;
};

TEST_F(ComplexCalculatorTestMain, test_main) {
    EXPECT_EQ(complexCalculator.add({ 1, 2 }, { 3, 4 }), std::complex<double>(4, 6));
    EXPECT_EQ(complexCalculator.subtract({ 1, 2 }, { 3, 4 }), std::complex<double>(-2, -2));
    EXPECT_EQ(complexCalculator.multiply({ 1, 2 }, { 3, 4 }), std::complex<double>(-5, 10));
    EXPECT_EQ(complexCalculator.divide({ 1, 2 }, { 3, 4 }), std::complex<double>(0.44, 0.08));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}