#include "pch.h"
#include <gtest/gtest.h>

class BalancedBracketsTestClearExpr : public ::testing::Test {};

TEST_F(BalancedBracketsTestClearExpr, test_clear_expr) {
    BalancedBrackets b("a(b)c");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), true);
}

TEST_F(BalancedBracketsTestClearExpr, test_clear_expr_2) {
    BalancedBrackets b("a(b){c}");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), true);
}

TEST_F(BalancedBracketsTestClearExpr, test_clear_expr_3) {
    BalancedBrackets b("[a](b){c}");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), true);
}

TEST_F(BalancedBracketsTestClearExpr, test_clear_expr_4) {
    BalancedBrackets b("[a(b){c}");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), false);
}

TEST_F(BalancedBracketsTestClearExpr, test_clear_expr_5) {
    BalancedBrackets b("a(b){c}]");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), false);
}

class BalancedBracketsTestCheckBalancedBrackets : public ::testing::Test {};

TEST_F(BalancedBracketsTestCheckBalancedBrackets, test_check_balanced_brackets) {
    BalancedBrackets b("a(b)c");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), true);
}

TEST_F(BalancedBracketsTestCheckBalancedBrackets, test_check_balanced_brackets_2) {
    BalancedBrackets b("a(b){c}");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), true);
}

TEST_F(BalancedBracketsTestCheckBalancedBrackets, test_check_balanced_brackets_3) {
    BalancedBrackets b("[a](b){c}");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), true);
}

TEST_F(BalancedBracketsTestCheckBalancedBrackets, test_check_balanced_brackets_4) {
    BalancedBrackets b("[a(b){c}");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), false);
}

TEST_F(BalancedBracketsTestCheckBalancedBrackets, test_check_balanced_brackets_5) {
    BalancedBrackets b("a(b{c}]");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), false);
}

TEST_F(BalancedBracketsTestCheckBalancedBrackets, test_check_balanced_brackets_6) {
    BalancedBrackets b("a(b{c]]");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), false);
}

TEST_F(BalancedBracketsTestCheckBalancedBrackets, test_check_balanced_brackets_7) {
    BalancedBrackets b("[a)(b){c}");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), false);
}

class BalancedBracketsTestMain : public ::testing::Test {};

TEST_F(BalancedBracketsTestMain, test_main) {
    BalancedBrackets b("a(b)c");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), true);
}

TEST_F(BalancedBracketsTestMain, test_main_2) {
    BalancedBrackets b("[a(b){c}");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), false);
}

TEST_F(BalancedBracketsTestMain, test_main_3) {
    BalancedBrackets b("a(b{c}]");
    b.clearExpr();
    EXPECT_EQ(b.check_balanced_brackets(), false);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
