#include "pch.h"
#include <gtest/gtest.h>


class ArrangementCalculatorTestCount : public ::testing::Test
{
};

TEST_F(ArrangementCalculatorTestCount, Test1)
{
    EXPECT_EQ(ArrangementCalculator::count(5, 3), 60);
}

TEST_F(ArrangementCalculatorTestCount, Test2)
{
    EXPECT_EQ(ArrangementCalculator::count(4, 3), 24);
}

TEST_F(ArrangementCalculatorTestCount, Test3)
{
    EXPECT_EQ(ArrangementCalculator::count(6, 3), 120);
}

TEST_F(ArrangementCalculatorTestCount, Test4)
{
    EXPECT_EQ(ArrangementCalculator::count(7, 3), 210);
}

TEST_F(ArrangementCalculatorTestCount, Test5)
{
    EXPECT_EQ(ArrangementCalculator::count(4, 4), 24);
}

class ArrangementCalculatorTestCountAll : public ::testing::Test
{
};

TEST_F(ArrangementCalculatorTestCountAll, Test1)
{
    EXPECT_EQ(ArrangementCalculator::count_all(4), 64);
}

TEST_F(ArrangementCalculatorTestCountAll, Test2)
{
    EXPECT_EQ(ArrangementCalculator::count_all(1), 1);
}

TEST_F(ArrangementCalculatorTestCountAll, Test3)
{
    EXPECT_EQ(ArrangementCalculator::count_all(2), 4);
}

TEST_F(ArrangementCalculatorTestCountAll, Test4)
{
    EXPECT_EQ(ArrangementCalculator::count_all(3), 15);
}

TEST_F(ArrangementCalculatorTestCountAll, Test5)
{
    EXPECT_EQ(ArrangementCalculator::count_all(5), 325);
}


class ArrangementCalculatorTestSelect : public ::testing::Test
{
};

TEST_F(ArrangementCalculatorTestSelect, Test1)
{
    ArrangementCalculator ac({"1", "2", "3", "4"});
    auto res = ac.select(2);
    std::vector<std::vector<std::string>> expected = {{"1", "2"}, {"1", "3"}, {"1", "4"}, {"2", "1"}, {"2", "3"}, {"2", "4"}, {"3", "1"}, {"3", "2"}, {"3", "4"}, {"4", "1"}, {"4", "2"}, {"4", "3"}};
    EXPECT_EQ(res, expected);
}

TEST_F(ArrangementCalculatorTestSelect, Test2)
{
    ArrangementCalculator ac({"1", "2", "3"});
    auto res = ac.select(2);
    std::vector<std::vector<std::string>> expected = {{"1", "2"}, {"1", "3"}, {"2", "1"}, {"2", "3"}, {"3", "1"}, {"3", "2"}};
    EXPECT_EQ(res, expected);
}

TEST_F(ArrangementCalculatorTestSelect, Test3)
{
    ArrangementCalculator ac({"2", "3", "4"});
    auto res = ac.select(2);
    std::vector<std::vector<std::string>> expected = {{"2", "3"}, {"2", "4"}, {"3", "2"}, {"3", "4"}, {"4", "2"}, {"4", "3"}};
    EXPECT_EQ(res, expected);
}

TEST_F(ArrangementCalculatorTestSelect, Test4)
{
    ArrangementCalculator ac({"1", "2"});
    auto res = ac.select(2);
    std::vector<std::vector<std::string>> expected = {{"1", "2"}, {"2", "1"}};
    EXPECT_EQ(res, expected);
}

TEST_F(ArrangementCalculatorTestSelect, Test5)
{
    ArrangementCalculator ac({"1", "2", "3", "4"});
    auto res = ac.select(1);
    std::vector<std::vector<std::string>> expected = {{"1"}, {"2"}, {"3"}, {"4"}};
    EXPECT_EQ(res, expected);
}

TEST_F(ArrangementCalculatorTestSelect, Test6)
{
    ArrangementCalculator ac({"1", "2"});
    auto res = ac.select();
    std::vector<std::vector<std::string>> expected = {{"1", "2"}, {"2", "1"}};
    EXPECT_EQ(res, expected);
}


class ArrangementCalculatorTestSelectAll : public ::testing::Test
{
};

TEST_F(ArrangementCalculatorTestSelectAll, Test1)
{
    ArrangementCalculator ac({"1", "2", "3"});
    auto res = ac.select_all();
    std::vector<std::vector<std::string>> expected = {{"1"}, {"2"}, {"3"}, {"1", "2"}, {"1", "3"}, {"2", "1"}, {"2", "3"}, {"3", "1"}, {"3", "2"}, {"1", "2", "3"}, {"1", "3", "2"}, {"2", "1", "3"}, {"2", "3", "1"}, {"3", "1", "2"}, {"3", "2", "1"}};
    EXPECT_EQ(res, expected);
}

TEST_F(ArrangementCalculatorTestSelectAll, Test2)
{
    ArrangementCalculator ac({"1", "2", "4"});
    auto res = ac.select_all();
    std::vector<std::vector<std::string>> expected = {{"1"}, {"2"}, {"4"}, {"1", "2"}, {"1", "4"}, {"2", "1"}, {"2", "4"}, {"4", "1"}, {"4", "2"}, {"1", "2", "4"}, {"1", "4", "2"}, {"2", "1", "4"}, {"2", "4", "1"}, {"4", "1", "2"}, {"4", "2", "1"}};
    EXPECT_EQ(res, expected);
}

TEST_F(ArrangementCalculatorTestSelectAll, Test3)
{
    ArrangementCalculator ac({"1", "2"});
    auto res = ac.select_all();
    std::vector<std::vector<std::string>> expected = {{"1"}, {"2"}, {"1", "2"}, {"2", "1"}};
    EXPECT_EQ(res, expected);
}

TEST_F(ArrangementCalculatorTestSelectAll, Test4)
{
    ArrangementCalculator ac({"1", "3"});
    auto res = ac.select_all();
    std::vector<std::vector<std::string>> expected = {{"1"}, {"3"}, {"1", "3"}, {"3", "1"}};
    EXPECT_EQ(res, expected);
}

TEST_F(ArrangementCalculatorTestSelectAll, Test5)
{
    ArrangementCalculator ac({"1"});
    auto res = ac.select_all();
    std::vector<std::vector<std::string>> expected = {{"1"}};
    EXPECT_EQ(res, expected);
}


class ArrangementCalculatorTestFactorial : public ::testing::Test
{
};

TEST_F(ArrangementCalculatorTestFactorial, Test1)
{
    EXPECT_EQ(ArrangementCalculator::factorial(4), 24);
}

TEST_F(ArrangementCalculatorTestFactorial, Test2)
{
    EXPECT_EQ(ArrangementCalculator::factorial(5), 120);
}

TEST_F(ArrangementCalculatorTestFactorial, Test3)
{
    EXPECT_EQ(ArrangementCalculator::factorial(3), 6);
}

TEST_F(ArrangementCalculatorTestFactorial, Test4)
{
    EXPECT_EQ(ArrangementCalculator::factorial(2), 2);
}

TEST_F(ArrangementCalculatorTestFactorial, Test5)
{
    EXPECT_EQ(ArrangementCalculator::factorial(1), 1);
}


class ArrangementCalculatorTest : public ::testing::Test
{
};

TEST_F(ArrangementCalculatorTest, TestAll)
{
    EXPECT_EQ(ArrangementCalculator::count(5, 3), 60);
    EXPECT_EQ(ArrangementCalculator::count_all(4), 64);

    ArrangementCalculator ac1({"1", "2", "3", "4"});
    auto res1 = ac1.select(2);
    std::vector<std::vector<std::string>> expected1 = {{"1", "2"}, {"1", "3"}, {"1", "4"}, {"2", "1"}, {"2", "3"}, {"2", "4"}, {"3", "1"}, {"3", "2"}, {"3", "4"}, {"4", "1"}, {"4", "2"}, {"4", "3"}};
    EXPECT_EQ(res1, expected1);

    ArrangementCalculator ac2({"1", "2", "3"});
    auto res2 = ac2.select_all();
    std::vector<std::vector<std::string>> expected2 = {{"1"}, {"2"}, {"3"}, {"1", "2"}, {"1", "3"}, {"2", "1"}, {"2", "3"}, {"3", "1"}, {"3", "2"}, {"1", "2", "3"}, {"1", "3", "2"}, {"2", "1", "3"}, {"2", "3", "1"}, {"3", "1", "2"}, {"3", "2", "1"}};
    EXPECT_EQ(res2, expected2);

    EXPECT_EQ(ArrangementCalculator::factorial(4), 24);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
