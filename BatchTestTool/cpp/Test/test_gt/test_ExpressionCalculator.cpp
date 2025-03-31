#include <gtest/gtest.h>
#include <deque>
#include <string>
#include <stdexcept>
#include "pch.h" 

class ExpressionCalculatorTestCalculate : public ::testing::Test {
protected:
    ExpressionCalculator expression_calculator;

    void SetUp() override {
        
    }
};

TEST_F(ExpressionCalculatorTestCalculate, test_calculate_1) {
    double result = expression_calculator.calculate("2 + 3 * 4");
    EXPECT_EQ(result, 14.0);
}

TEST_F(ExpressionCalculatorTestCalculate, test_calculate_2) {
    double result = expression_calculator.calculate("2 + 3 + 4");
    EXPECT_EQ(result, 9.0);
}

TEST_F(ExpressionCalculatorTestCalculate, test_calculate_3) {
    double result = expression_calculator.calculate("2 * 3 * 4");
    EXPECT_EQ(result, 24.0);
}

TEST_F(ExpressionCalculatorTestCalculate, test_calculate_4) {
    double result = expression_calculator.calculate("2 + 4 / 4");
    EXPECT_EQ(result, 3.0);
}

TEST_F(ExpressionCalculatorTestCalculate, test_calculate_5) {
    double result = expression_calculator.calculate("(2 + 3) * 4");
    EXPECT_EQ(result, 20.0);
}

class ExpressionCalculatorTestPrepare : public ::testing::Test {
protected:
    ExpressionCalculator expression_calculator;

    void SetUp() override {
        
    }
};

TEST_F(ExpressionCalculatorTestPrepare, test_prepare_1) {
    expression_calculator.prepare("2+3*4");
    std::deque<std::string> expected = { "2", "3", "4", "*", "+" };
    EXPECT_EQ(expression_calculator.postfix_stack, expected);
}

TEST_F(ExpressionCalculatorTestPrepare, test_prepare_2) {
    expression_calculator.prepare("2+3/4");
    std::deque<std::string> expected = { "2", "3", "4", "/", "+" };
    EXPECT_EQ(expression_calculator.postfix_stack, expected);
}

TEST_F(ExpressionCalculatorTestPrepare, test_prepare_3) {
    expression_calculator.prepare("2-3*4");
    std::deque<std::string> expected = { "2", "3", "4", "*", "-" };
    EXPECT_EQ(expression_calculator.postfix_stack, expected);
}

TEST_F(ExpressionCalculatorTestPrepare, test_prepare_4) {
    expression_calculator.prepare("1+3*4");
    std::deque<std::string> expected = { "1", "3", "4", "*", "+" };
    EXPECT_EQ(expression_calculator.postfix_stack, expected);
}

TEST_F(ExpressionCalculatorTestPrepare, test_prepare_5) {
    expression_calculator.prepare("(2+3)*4");
    std::deque<std::string> expected = { "2", "3", "+", "4", "*" };
    EXPECT_EQ(expression_calculator.postfix_stack, expected);
}

TEST_F(ExpressionCalculatorTestPrepare, test_prepare_6) {
    expression_calculator.prepare("");
    std::deque<std::string> expected = {};
    EXPECT_EQ(expression_calculator.postfix_stack, expected);
}

class ExpressionCalculatorTestIsOperator : public ::testing::Test {
protected:
    ExpressionCalculator expression_calculator;

    void SetUp() override {
        
    }
};

TEST_F(ExpressionCalculatorTestIsOperator, test_is_operator_1) {
    EXPECT_TRUE(expression_calculator.is_operator("+"));
}

TEST_F(ExpressionCalculatorTestIsOperator, test_is_operator_2) {
    EXPECT_TRUE(expression_calculator.is_operator("-"));
}

TEST_F(ExpressionCalculatorTestIsOperator, test_is_operator_3) {
    EXPECT_TRUE(expression_calculator.is_operator("*"));
}

TEST_F(ExpressionCalculatorTestIsOperator, test_is_operator_4) {
    EXPECT_TRUE(expression_calculator.is_operator("/"));
}

TEST_F(ExpressionCalculatorTestIsOperator, test_is_operator_5) {
    EXPECT_FALSE(expression_calculator.is_operator("5"));
}

class ExpressionCalculatorTestCompare : public ::testing::Test {
protected:
    ExpressionCalculator expression_calculator;

    void SetUp() override {
        
    }
};

TEST_F(ExpressionCalculatorTestCompare, test_compare_1) {
    bool result = expression_calculator.compare("+", "-");
    EXPECT_TRUE(result);
}

TEST_F(ExpressionCalculatorTestCompare, test_compare_2) {
    bool result = expression_calculator.compare("*", "/");
    EXPECT_TRUE(result);
}

TEST_F(ExpressionCalculatorTestCompare, test_compare_3) {
    bool result = expression_calculator.compare("+", "*");
    EXPECT_TRUE(result);
}

TEST_F(ExpressionCalculatorTestCompare, test_compare_4) {
    bool result = expression_calculator.compare("*", "+");
    EXPECT_FALSE(result);
}

TEST_F(ExpressionCalculatorTestCompare, test_compare_5) {
    bool result = expression_calculator.compare("/", "+");
    EXPECT_FALSE(result);
}

TEST_F(ExpressionCalculatorTestCompare, test_compare_6) {
    bool result = expression_calculator.compare("%", "+");
    EXPECT_FALSE(result);
}

TEST_F(ExpressionCalculatorTestCompare, test_compare_7) {
    bool result = expression_calculator.compare("+", "%");
    EXPECT_TRUE(result);
}

class ExpressionCalculatorTestCalculateMethod : public ::testing::Test {
protected:
    ExpressionCalculator expression_calculator;

    void SetUp() override {
        
    }
};

TEST_F(ExpressionCalculatorTestCalculateMethod, test_calculate_method_1) {
    double result = expression_calculator._calculate("2", "3", "+");
    EXPECT_EQ(result, 5.0);
}

TEST_F(ExpressionCalculatorTestCalculateMethod, test_calculate_method_2) {
    double result = expression_calculator._calculate("3", "2", "-");
    EXPECT_EQ(result, 1.0);
}

TEST_F(ExpressionCalculatorTestCalculateMethod, test_calculate_method_3) {
    double result = expression_calculator._calculate("2", "3", "*");
    EXPECT_EQ(result, 6.0);
}

TEST_F(ExpressionCalculatorTestCalculateMethod, test_calculate_method_4) {
    double result = expression_calculator._calculate("3", "3", "/");
    EXPECT_EQ(result, 1.0);
}

TEST_F(ExpressionCalculatorTestCalculateMethod, test_calculate_method_5) {
    double result = expression_calculator._calculate("6", "2", "/");
    EXPECT_EQ(result, 3.0);
}

TEST_F(ExpressionCalculatorTestCalculateMethod, test_calculate_method_6) {
    double result = expression_calculator._calculate("6", "2", "%");
    EXPECT_EQ(result, 0.0);
}

TEST_F(ExpressionCalculatorTestCalculateMethod, test_calculate_method_7) {
    EXPECT_THROW({
        try {
            expression_calculator._calculate("6", "2", "??");
        }
 catch (const std::exception&) {
  throw;
}
        }, std::exception);
}

class ExpressionCalculatorTestTransform : public ::testing::Test {
protected:
    ExpressionCalculator expression_calculator;

    void SetUp() override {
        
    }
};

TEST_F(ExpressionCalculatorTestTransform, test_transform_1) {
    std::string result = expression_calculator.transform("2 + 3 * 4");
    EXPECT_EQ(result, "2+3*4");
}

TEST_F(ExpressionCalculatorTestTransform, test_transform_2) {
    std::string result = expression_calculator.transform("2 + 3 / 4");
    EXPECT_EQ(result, "2+3/4");
}

TEST_F(ExpressionCalculatorTestTransform, test_transform_3) {
    std::string result = expression_calculator.transform("2 - 3 * 4");
    EXPECT_EQ(result, "2-3*4");
}

TEST_F(ExpressionCalculatorTestTransform, test_transform_4) {
    std::string result = expression_calculator.transform("1 + 3 * 4");
    EXPECT_EQ(result, "1+3*4");
}

TEST_F(ExpressionCalculatorTestTransform, test_transform_5) {
    std::string result = expression_calculator.transform("-2 + (-3) * 4");
    EXPECT_EQ(result, "~2+(~3)*4");
}

TEST_F(ExpressionCalculatorTestTransform, test_transform_6) {
    std::string result = expression_calculator.transform("~(1 + 1)");
    EXPECT_EQ(result, "0-(1+1)");
}

class ExpressionCalculatorTest : public ::testing::Test {
protected:
    ExpressionCalculator expression_calculator;

    void SetUp() override {
        
    }
};

TEST_F(ExpressionCalculatorTest, test_ExpressionCalculator) {
    double result = expression_calculator.calculate("2 + 3 * 4");
    EXPECT_EQ(result, 14.0);

    expression_calculator.prepare("2+3*4");
    std::deque<std::string> expected = { "2", "3", "4", "*", "+" };
    EXPECT_EQ(expression_calculator.postfix_stack, expected);

    EXPECT_TRUE(expression_calculator.is_operator("+"));

    bool compare_result = expression_calculator.compare("+", "-");
    EXPECT_TRUE(compare_result);

    double calc_result = expression_calculator._calculate("2", "3", "+");
    EXPECT_EQ(calc_result, 5.0);

    std::string transform_result = expression_calculator.transform("2 + 3 * 4");
    EXPECT_EQ(transform_result, "2+3*4");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}