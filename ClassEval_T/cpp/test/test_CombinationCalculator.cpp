#include <gtest/gtest.h>
#include "pch.h"

class CombinationCalculatorTestCount : public ::testing::Test {};

TEST_F(CombinationCalculatorTestCount, test_count) {
    EXPECT_EQ(CombinationCalculator::count(4, 2), 6);
}

TEST_F(CombinationCalculatorTestCount, test_count_2) {
    EXPECT_EQ(CombinationCalculator::count(5, 3), 10);
}

TEST_F(CombinationCalculatorTestCount, test_count_3) {
    EXPECT_EQ(CombinationCalculator::count(6, 6), 1);
}

TEST_F(CombinationCalculatorTestCount, test_count_4) {
    EXPECT_EQ(CombinationCalculator::count(6, 0), 1);
}

TEST_F(CombinationCalculatorTestCount, test_count_5) {
    EXPECT_EQ(CombinationCalculator::count(6, 3), 20);
}

class CombinationCalculatorTestCountAll : public ::testing::Test {};

TEST_F(CombinationCalculatorTestCountAll, test_count_all) {
    EXPECT_EQ(CombinationCalculator::count_all(4), 15);
}

TEST_F(CombinationCalculatorTestCountAll, test_count_all_2) {
    double result = CombinationCalculator::count_all(-1);
    EXPECT_TRUE(std::isnan(result));
}

TEST_F(CombinationCalculatorTestCountAll, test_count_all_3) {
    double result = CombinationCalculator::count_all(65);
    EXPECT_TRUE(std::isinf(result) && result > 0);
}

TEST_F(CombinationCalculatorTestCountAll, test_count_all_4) {
    EXPECT_EQ(CombinationCalculator::count_all(0), 0);
}

TEST_F(CombinationCalculatorTestCountAll, test_count_all_5) {
    EXPECT_EQ(CombinationCalculator::count_all(63), std::numeric_limits<double>::infinity());
}

class CombinationCalculatorTestSelect : public ::testing::Test {};

TEST_F(CombinationCalculatorTestSelect, test_select) {
    CombinationCalculator calc({ "A", "B", "C", "D" });
    EXPECT_EQ(calc.count(4, 2), 6);
}

TEST_F(CombinationCalculatorTestSelect, test_select_2) {
    CombinationCalculator calc({ "A", "B", "C", "D" });
    EXPECT_EQ(calc.count(5, 3), 10);
}

TEST_F(CombinationCalculatorTestSelect, test_select_3) {
    CombinationCalculator calc({ "A", "B", "C", "D" });
    EXPECT_EQ(calc.count(6, 6), 1);
}

TEST_F(CombinationCalculatorTestSelect, test_select_4) {
    CombinationCalculator calc({ "A", "B", "C", "D" });
    EXPECT_EQ(calc.count(6, 0), 1);
}

TEST_F(CombinationCalculatorTestSelect, test_select_5) {
    CombinationCalculator calc({ "A", "B", "C", "D" });
    EXPECT_EQ(calc.count(6, 3), 20);
}

class CombinationCalculatorTestSelectAll : public ::testing::Test {};

TEST_F(CombinationCalculatorTestSelectAll, test_select_all) {
    CombinationCalculator calc({ "A" });
    std::vector<std::vector<std::string>> expected = { {"A"} };
    EXPECT_EQ(calc.select_all(), expected);
}

TEST_F(CombinationCalculatorTestSelectAll, test_select_all_2) {
    CombinationCalculator calc({ "A", "B" });
    std::vector<std::vector<std::string>> expected = { {"A"}, {"B"}, {"A", "B"} };
    EXPECT_EQ(calc.select_all(), expected);
}

TEST_F(CombinationCalculatorTestSelectAll, test_select_all_3) {
    CombinationCalculator calc({ "A", "B", "C" });
    std::vector<std::vector<std::string>> expected = {
        {"A"}, {"B"}, {"C"}, {"A", "B"}, {"A", "C"}, {"B", "C"}, {"A", "B", "C"}
    };
    EXPECT_EQ(calc.select_all(), expected);
}

TEST_F(CombinationCalculatorTestSelectAll, test_select_all_4) {
    CombinationCalculator calc({});
    std::vector<std::vector<std::string>> expected = {};
    EXPECT_EQ(calc.select_all(), expected);
}

TEST_F(CombinationCalculatorTestSelectAll, test_select_all_5) {
    CombinationCalculator calc({ "B" });
    std::vector<std::vector<std::string>> expected = { {"B"} };
    EXPECT_EQ(calc.select_all(), expected);
}

class CombinationCalculatorTestSelect2 : public ::testing::Test {};

TEST_F(CombinationCalculatorTestSelect2, test_select2) {
    CombinationCalculator calc({ "A", "B", "C", "D" });
    std::vector<std::vector<std::string>> expected = {
        {"A", "B"}, {"A", "C"}, {"A", "D"}, {"B", "C"}, {"B", "D"}, {"C", "D"}
    };
    std::vector<std::string> resultList(2);
    std::vector<std::vector<std::string>> result;
    calc._select(0, resultList, 0, result);
    EXPECT_EQ(result, expected);
}

TEST_F(CombinationCalculatorTestSelect2, test_select2_2) {
    CombinationCalculator calc({ "A", "B", "C", "D" });
    std::vector<std::vector<std::string>> expected = {
        {"A", "B", "C"}, {"A", "B", "D"}, {"A", "C", "D"}, {"B", "C", "D"}
    };
    std::vector<std::string> resultList(3);
    std::vector<std::vector<std::string>> result;
    calc._select(0, resultList, 0, result);
    EXPECT_EQ(result, expected);
}

TEST_F(CombinationCalculatorTestSelect2, test_select2_3) {
    CombinationCalculator calc({ "A", "B", "C", "D" });
    std::vector<std::vector<std::string>> expected = {
        {"A"}, {"B"}, {"C"}, {"D"}
    };
    std::vector<std::string> resultList(1);
    std::vector<std::vector<std::string>> result;
    calc._select(0, resultList, 0, result);
    EXPECT_EQ(result, expected);
}

TEST_F(CombinationCalculatorTestSelect2, test_select2_4) {
    CombinationCalculator calc({ "A", "B", "C", "D" });
    std::vector<std::vector<std::string>> expected = {
        {}
    };
    std::vector<std::string> resultList(0);
    std::vector<std::vector<std::string>> result;
    calc._select(0, resultList, 0, result);
    EXPECT_EQ(result, expected);
}

TEST_F(CombinationCalculatorTestSelect2, test_select2_5) {
    CombinationCalculator calc({ "A", "B", "C", "D" });
    std::vector<std::vector<std::string>> expected = {
        {"A", "B", "C", "D"}
    };
    std::vector<std::string> resultList(4);
    std::vector<std::vector<std::string>> result;
    calc._select(0, resultList, 0, result);
    EXPECT_EQ(result, expected);
}

class CombinationCalculatorTestMain : public ::testing::Test {};

TEST_F(CombinationCalculatorTestMain, test_main) {
    CombinationCalculator calc({ "A", "B", "C", "D" });

    EXPECT_EQ(calc.count(4, 2), 6);
    EXPECT_EQ(calc.count_all(4), 15);

    std::vector<std::vector<std::string>> expectedSelect = {
        {"A", "B"}, {"A", "C"}, {"A", "D"}, {"B", "C"}, {"B", "D"}, {"C", "D"}
    };
    EXPECT_EQ(calc.select(2), expectedSelect);

    std::vector<std::vector<std::string>> expectedSelectAll = {
        {"A"}, {"B"}, {"C"}, {"D"}, {"A", "B"}, {"A", "C"}, {"A", "D"}, {"B", "C"}, {"B", "D"}, {"C", "D"},
        {"A", "B", "C"}, {"A", "B", "D"}, {"A", "C", "D"}, {"B", "C", "D"}, {"A", "B", "C", "D"}
    };
    EXPECT_EQ(calc.select_all(), expectedSelectAll);

    std::vector<std::vector<std::string>> expectedSelect2 = {
        {"A", "B"}, {"A", "C"}, {"A", "D"}, {"B", "C"}, {"B", "D"}, {"C", "D"}
    };
    std::vector<std::string> resultList(2);
    std::vector<std::vector<std::string>> result;
    calc._select(0, resultList, 0, result);
    EXPECT_EQ(result, expectedSelect2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}