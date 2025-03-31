#include "pch.h"
#include <gtest/gtest.h>

class AvgPartitionTestSetNum : public ::testing::Test {};

TEST_F(AvgPartitionTestSetNum, test_set_num) {
    AvgPartition a({1, 2, 3, 4}, 2);
    auto result = a.set_num();
    EXPECT_EQ(result.first, 2);
    EXPECT_EQ(result.second, 0);
}

TEST_F(AvgPartitionTestSetNum, test_set_num_2) {
    AvgPartition a({1, 2, 3, 4, 5}, 2);
    auto result = a.set_num();
    EXPECT_EQ(result.first, 2);
    EXPECT_EQ(result.second, 1);
}

TEST_F(AvgPartitionTestSetNum, test_set_num_3) {
    AvgPartition a({1, 2, 3, 4, 5}, 3);
    auto result = a.set_num();
    EXPECT_EQ(result.first, 1);
    EXPECT_EQ(result.second, 2);
}

TEST_F(AvgPartitionTestSetNum, test_set_num_4) {
    AvgPartition a({1, 2, 3, 4, 5}, 4);
    auto result = a.set_num();
    EXPECT_EQ(result.first, 1);
    EXPECT_EQ(result.second, 1);
}

TEST_F(AvgPartitionTestSetNum, test_set_num_5) {
    AvgPartition a({1, 2, 3, 4, 5}, 5);
    auto result = a.set_num();
    EXPECT_EQ(result.first, 1);
    EXPECT_EQ(result.second, 0);
}

class AvgPartitionTestGet : public ::testing::Test {};

TEST_F(AvgPartitionTestGet, test_get) {
    AvgPartition a({1, 2, 3, 4}, 2);
    auto result = a.get(0);
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(result, expected);
}

TEST_F(AvgPartitionTestGet, test_get_2) {
    AvgPartition a({1, 2, 3, 4}, 2);
    auto result = a.get(1);
    std::vector<int> expected = {3, 4};
    EXPECT_EQ(result, expected);
}

TEST_F(AvgPartitionTestGet, test_get_3) {
    AvgPartition a({1, 2, 3, 4, 5}, 2);
    auto result = a.get(0);
    std::vector<int> expected = {1, 2, 3};
    EXPECT_EQ(result, expected);
}

TEST_F(AvgPartitionTestGet, test_get_4) {
    AvgPartition a({1, 2, 3, 4, 5}, 2);
    auto result = a.get(1);
    std::vector<int> expected = {4, 5};
    EXPECT_EQ(result, expected);
}

TEST_F(AvgPartitionTestGet, test_get_5) {
    AvgPartition a({1, 2, 3, 4, 5}, 3);
    auto result = a.get(0);
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(result, expected);
}

class AvgPartitionTestMain : public ::testing::Test {};

TEST_F(AvgPartitionTestMain, test_main) {
    AvgPartition a({1, 2, 3, 4}, 2);
    auto result = a.set_num();
    EXPECT_EQ(result.first, 2);
    EXPECT_EQ(result.second, 0);
    auto list = a.get(0);
    std::vector<int> expected = {1, 2};
    EXPECT_EQ(list, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
