#include <gtest/gtest.h>
#include "pch.h"
#include<iostream>


class TriCalculatorTestCos : public ::testing::Test {
protected:
    TriCalculator tricalculator;
};

TEST_F(TriCalculatorTestCos, test_cos_1) {
    EXPECT_NEAR(tricalculator.cos(60), 0.5, 4e-9);
}

TEST_F(TriCalculatorTestCos, test_cos_2) {
    EXPECT_NEAR(tricalculator.cos(30), 0.8660254038, 1e-9);
}

TEST_F(TriCalculatorTestCos, test_cos_3) {
    EXPECT_EQ(tricalculator.cos(0), 1.0);
}

TEST_F(TriCalculatorTestCos, test_cos_4) {
    EXPECT_NEAR(tricalculator.cos(90), 0.0, 1e-2);
}

TEST_F(TriCalculatorTestCos, test_cos_5) {
    EXPECT_NEAR(tricalculator.cos(45), 0.7071067812, 1e-9);
}


class TriCalculatorTestFactorial : public ::testing::Test {
protected:
    TriCalculator tricalculator;
};

TEST_F(TriCalculatorTestFactorial, test_factorial_1) {
    EXPECT_EQ(tricalculator.factorial(5), 120);
}

TEST_F(TriCalculatorTestFactorial, test_factorial_2) {
    EXPECT_EQ(tricalculator.factorial(4), 24);
}

TEST_F(TriCalculatorTestFactorial, test_factorial_3) {
    EXPECT_EQ(tricalculator.factorial(3), 6);
}

TEST_F(TriCalculatorTestFactorial, test_factorial_4) {
    EXPECT_EQ(tricalculator.factorial(2), 2);
}

TEST_F(TriCalculatorTestFactorial, test_factorial_5) {
    EXPECT_EQ(tricalculator.factorial(1), 1);
}


class TriCalculatorTestTaylor : public ::testing::Test {
protected:
    TriCalculator tricalculator;
};

TEST_F(TriCalculatorTestTaylor, test_taylor_1) {
    EXPECT_NEAR(tricalculator.taylor(60, 17), 0.5, 4e-9);
}

TEST_F(TriCalculatorTestTaylor, test_taylor_2) {
    EXPECT_NEAR(tricalculator.taylor(30, 17), 0.8660254037844386, 1e-9);
}

TEST_F(TriCalculatorTestTaylor, test_taylor_3) {
    EXPECT_NEAR(tricalculator.taylor(90, 17), 0.0, 1e-2);
}

TEST_F(TriCalculatorTestTaylor, test_taylor_4) {
    EXPECT_NEAR(tricalculator.taylor(0, 17), 1.0, 1e-9);
}

TEST_F(TriCalculatorTestTaylor, test_taylor_5) {
    EXPECT_NEAR(tricalculator.taylor(45, 17), 0.7071067811865475, 1e-9);
}


class TriCalculatorTestSin : public ::testing::Test {
protected:
    TriCalculator tricalculator;
};

TEST_F(TriCalculatorTestSin, test_sin_1) {
    EXPECT_EQ(tricalculator.sin(30), 0.5);
}

TEST_F(TriCalculatorTestSin, test_sin_2) {
    EXPECT_NEAR(tricalculator.sin(60), 0.8660254038, 1e-9);
}

TEST_F(TriCalculatorTestSin, test_sin_3) {
    EXPECT_EQ(tricalculator.sin(0), 0.0);
}

TEST_F(TriCalculatorTestSin, test_sin_4) {
    EXPECT_EQ(tricalculator.sin(90), 1.0);
}

TEST_F(TriCalculatorTestSin, test_sin_5) {
    EXPECT_NEAR(tricalculator.sin(45), 0.7071067812, 1e-9);
}


class TriCalculatorTestTan : public ::testing::Test {
protected:
    TriCalculator tricalculator;
};

TEST_F(TriCalculatorTestTan, test_tan_1) {
    EXPECT_EQ(tricalculator.tan(45), 1.0);
}

TEST_F(TriCalculatorTestTan, test_tan_2) {
    EXPECT_TRUE(std::isnan(tricalculator.tan(90)));
}

TEST_F(TriCalculatorTestTan, test_tan_3) {
    EXPECT_NEAR(tricalculator.tan(30), 0.5773502692, 1e-9);
}

TEST_F(TriCalculatorTestTan, test_tan_4) {
    EXPECT_NEAR(tricalculator.tan(60), 1.7320508076, 2e-8);
}

TEST_F(TriCalculatorTestTan, test_tan_5) {
    EXPECT_EQ(tricalculator.tan(0), 0.0);
}


class TriCalculatorTest : public ::testing::Test {
protected:
    TriCalculator tricalculator;
};

TEST_F(TriCalculatorTest, test_tricalculator) {
    EXPECT_NEAR(tricalculator.cos(60), 0.5, 4e-9);
    EXPECT_NEAR(tricalculator.taylor(60, 17), 0.5, 4e-9);
    EXPECT_EQ(tricalculator.sin(30), 0.5);
    EXPECT_EQ(tricalculator.tan(45), 1.0);
    EXPECT_TRUE(std::isnan(tricalculator.tan(90)));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}