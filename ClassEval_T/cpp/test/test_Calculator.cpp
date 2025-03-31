#include "pch.h"
#include <gtest/gtest.h>

std::vector<char> stv(std::stack<char> stack)
{
    std::vector<char> st;
    while (!stack.empty())
    {
        st.push_back(stack.top());
        stack.pop();
    }
    return st;
}

class CalculatorTestCalculate : public ::testing::Test {
protected:
    Calculator calculator;
};

TEST_F(CalculatorTestCalculate, TestCalculate1) {
    EXPECT_DOUBLE_EQ(calculator.calculate("1+2"), 3.0);
}

TEST_F(CalculatorTestCalculate, TestCalculate2) {
    EXPECT_DOUBLE_EQ(calculator.calculate("1+2*3"), 7.0);
}

TEST_F(CalculatorTestCalculate, TestCalculate3) {
    EXPECT_DOUBLE_EQ(calculator.calculate("1+2*3+4"), 11.0);
}

TEST_F(CalculatorTestCalculate, TestCalculate4) {
    EXPECT_DOUBLE_EQ(calculator.calculate("1+2^3*2+4*5"), 37.0);
}

TEST_F(CalculatorTestCalculate, TestCalculate5) {
    EXPECT_DOUBLE_EQ(calculator.calculate("1+2+3"), 6.0);
}

TEST_F(CalculatorTestCalculate, TestCalculate6) {
    EXPECT_DOUBLE_EQ(calculator.calculate("(1+2)+3"), 6.0);
}

TEST_F(CalculatorTestCalculate, TestCalculate7) {
    EXPECT_DOUBLE_EQ(calculator.calculate(""), 0.0);
}

TEST_F(CalculatorTestCalculate, TestCalculate8) {
    
    
    EXPECT_DOUBLE_EQ(calculator.calculate("1+2?"), 3.0);
}

class CalculatorTestPrecedence : public ::testing::Test {
protected:
    Calculator calculator;
};

TEST_F(CalculatorTestPrecedence, TestPrecedence1) {
    EXPECT_EQ(calculator.precedence('+'), calculator.precedence('-'));
}

TEST_F(CalculatorTestPrecedence, TestPrecedence2) {
    EXPECT_EQ(calculator.precedence('*'), calculator.precedence('/'));
}

TEST_F(CalculatorTestPrecedence, TestPrecedence3) {
    EXPECT_NE(calculator.precedence('+'), calculator.precedence('/'));
}

TEST_F(CalculatorTestPrecedence, TestPrecedence4) {
    EXPECT_NE(calculator.precedence('+'), calculator.precedence('/'));
}

TEST_F(CalculatorTestPrecedence, TestPrecedence5) {
    EXPECT_NE(calculator.precedence('*'), calculator.precedence('-'));
}

class CalculatorTestApplyOperator : public ::testing::Test {
protected:
    Calculator calculator;
};

TEST_F(CalculatorTestApplyOperator, TestApplyOperator1) {
    std::stack<double> operand_stack;
    std::stack<char> operator_stack;

    operand_stack.push(1);
    operand_stack.push(2);
    operand_stack.push(3);

    operator_stack.push('+');
    operator_stack.push('-');

    std::tie(operand_stack, operator_stack) = calculator.apply_operator(operand_stack, operator_stack);

    EXPECT_EQ(operand_stack.top(), -1);
    operand_stack.pop();
    EXPECT_EQ(operand_stack.top(), 1);
    operand_stack.pop();
    std::vector<char> expected_stack = { '+' };
    std::vector<char> result_stack = stv(operator_stack);
    EXPECT_EQ(result_stack, expected_stack);
}

TEST_F(CalculatorTestApplyOperator, TestApplyOperator2) {
    std::stack<double> operand_stack;
    std::stack<char> operator_stack;

    operand_stack.push(1);
    operand_stack.push(2);
    operand_stack.push(3);

    operator_stack.push('+');
    operator_stack.push('*');

    std::tie(operand_stack, operator_stack) = calculator.apply_operator(operand_stack, operator_stack);

    EXPECT_EQ(operand_stack.top(), 6);
    operand_stack.pop();
    EXPECT_EQ(operand_stack.top(), 1);
    operand_stack.pop();
    std::vector<char> expected_stack = { '+' };
    std::vector<char> result_stack = stv(operator_stack);
    EXPECT_EQ(result_stack, expected_stack);
}

TEST_F(CalculatorTestApplyOperator, TestApplyOperator3) {
    std::stack<double> operand_stack;
    std::stack<char> operator_stack;

    operand_stack.push(6);
    operand_stack.push(3);
    operand_stack.push(3);

    operator_stack.push('+');
    operator_stack.push('/');

    std::tie(operand_stack, operator_stack) = calculator.apply_operator(operand_stack, operator_stack);

    EXPECT_EQ(operand_stack.top(), 1);
    operand_stack.pop();
    EXPECT_EQ(operand_stack.top(), 6);
    operand_stack.pop();
    std::vector<char> expected_stack = { '+' };
    std::vector<char> result_stack = stv(operator_stack);
    EXPECT_EQ(result_stack, expected_stack);
}

TEST_F(CalculatorTestApplyOperator, TestApplyOperator4) {
    std::stack<double> operand_stack;
    std::stack<char> operator_stack;

    operand_stack.push(1);
    operand_stack.push(2);
    operand_stack.push(3);

    operator_stack.push('+');
    operator_stack.push('^');

    std::tie(operand_stack, operator_stack) = calculator.apply_operator(operand_stack, operator_stack);

    EXPECT_EQ(operand_stack.top(), 8);
    operand_stack.pop();
    EXPECT_EQ(operand_stack.top(), 1);
    operand_stack.pop();
    std::vector<char> expected_stack = { '+' };
    std::vector<char> result_stack = stv(operator_stack);
    EXPECT_EQ(result_stack, expected_stack);
}

TEST_F(CalculatorTestApplyOperator, TestApplyOperator5) {
    std::stack<double> operand_stack;
    std::stack<char> operator_stack;

    operand_stack.push(1);
    operand_stack.push(2);
    operand_stack.push(3);

    operator_stack.push('+');
    operator_stack.push('+');

    std::tie(operand_stack, operator_stack) = calculator.apply_operator(operand_stack, operator_stack);

    EXPECT_EQ(operand_stack.top(), 5);
    operand_stack.pop();
    EXPECT_EQ(operand_stack.top(), 1);
    operand_stack.pop();
    std::vector<char> expected_stack = { '+' };
    std::vector<char> result_stack = stv(operator_stack);
    EXPECT_EQ(result_stack, expected_stack);
}

class CalculatorTest : public ::testing::Test {
protected:
    Calculator calculator;
};

TEST_F(CalculatorTest, TestCalculator) {
    EXPECT_DOUBLE_EQ(calculator.calculate("1+2"), 3.0);
    EXPECT_EQ(calculator.precedence('+'), calculator.precedence('-'));
    EXPECT_EQ(calculator.precedence('*'), calculator.precedence('/'));
    EXPECT_GT(calculator.precedence('*'), calculator.precedence('+'));
    EXPECT_GT(calculator.precedence('^'), calculator.precedence('*'));

    std::stack<double> operand_stack;
    std::stack<char> operator_stack;

    operand_stack.push(1);
    operand_stack.push(2);
    operand_stack.push(3);

    operator_stack.push('+');
    operator_stack.push('-');

    std::tie(operand_stack, operator_stack) = calculator.apply_operator(operand_stack, operator_stack);

    EXPECT_EQ(operand_stack.top(), -1);
    operand_stack.pop();
    EXPECT_EQ(operand_stack.top(), 1);
    operand_stack.pop();
    std::vector<char> expected_stack = { '+' };
    std::vector<char> result_stack = stv(operator_stack);
    EXPECT_EQ(result_stack, expected_stack);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}