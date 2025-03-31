#include <gtest/gtest.h>
#include <vector>
#include "pch.h" 

class DataStatistics2TestGetSum : public ::testing::Test {};

TEST_F(DataStatistics2TestGetSum, test_get_sum_1) {
    DataStatistics2 ds2({ 1, 2, 3, 4 });
    auto res = ds2.get_sum();
    EXPECT_EQ(res, 10);
}

TEST_F(DataStatistics2TestGetSum, test_get_sum_2) {
    DataStatistics2 ds2({ 1, 2, 203, 4 });
    auto res = ds2.get_sum();
    EXPECT_EQ(res, 210);
}

TEST_F(DataStatistics2TestGetSum, test_get_sum_3) {
    DataStatistics2 ds2({ 1, 2, 33, 4 });
    auto res = ds2.get_sum();
    EXPECT_EQ(res, 40);
}

TEST_F(DataStatistics2TestGetSum, test_get_sum_4) {
    DataStatistics2 ds2({ 1, 2, 333, 4 });
    auto res = ds2.get_sum();
    EXPECT_EQ(res, 340);
}

TEST_F(DataStatistics2TestGetSum, test_get_sum_5) {
    DataStatistics2 ds2({ 1, 2, 6, 4 });
    auto res = ds2.get_sum();
    EXPECT_EQ(res, 13);
}

class DataStatistics2TestGetMin : public ::testing::Test {};

TEST_F(DataStatistics2TestGetMin, test_get_min_1) {
    DataStatistics2 ds2({ 1, 2, 3, 4 });
    auto res = ds2.get_min();
    EXPECT_EQ(res, 1);
}

TEST_F(DataStatistics2TestGetMin, test_get_min_2) {
    DataStatistics2 ds2({ 1, 2, 203, 4 });
    auto res = ds2.get_min();
    EXPECT_EQ(res, 1);
}

TEST_F(DataStatistics2TestGetMin, test_get_min_3) {
    DataStatistics2 ds2({ 0, -1, -3, 2 });
    auto res = ds2.get_min();
    EXPECT_EQ(res, -3);
}

TEST_F(DataStatistics2TestGetMin, test_get_min_4) {
    DataStatistics2 ds2({ -111, -1, -3, 2 });
    auto res = ds2.get_min();
    EXPECT_EQ(res, -111);
}

TEST_F(DataStatistics2TestGetMin, test_get_min_5) {
    DataStatistics2 ds2({ 0, -1111, -3, 2 });
    auto res = ds2.get_min();
    EXPECT_EQ(res, -1111);
}

class DataStatistics2TestGetMax : public ::testing::Test {};

TEST_F(DataStatistics2TestGetMax, test_get_max_1) {
    DataStatistics2 ds2({ 1, 2, 3, 4 });
    auto res = ds2.get_max();
    EXPECT_EQ(res, 4);
}

TEST_F(DataStatistics2TestGetMax, test_get_max_2) {
    DataStatistics2 ds2({ 1, 2, 203, 4 });
    auto res = ds2.get_max();
    EXPECT_EQ(res, 203);
}

TEST_F(DataStatistics2TestGetMax, test_get_max_3) {
    DataStatistics2 ds2({ -1, -4, 3, 2 });
    auto res = ds2.get_max();
    EXPECT_EQ(res, 3);
}

TEST_F(DataStatistics2TestGetMax, test_get_max_4) {
    DataStatistics2 ds2({ -1, 4, 3, 2 });
    auto res = ds2.get_max();
    EXPECT_EQ(res, 4);
}

TEST_F(DataStatistics2TestGetMax, test_get_max_5) {
    DataStatistics2 ds2({ -1, 444, 3, 2 });
    auto res = ds2.get_max();
    EXPECT_EQ(res, 444);
}

class DataStatistics2TestGetVariance : public ::testing::Test {};

TEST_F(DataStatistics2TestGetVariance, test_get_variance_1) {
    DataStatistics2 ds2({ 1, 2, 3, 4 });
    auto res = ds2.get_variance();
    EXPECT_EQ(res, 1.25);
}

TEST_F(DataStatistics2TestGetVariance, test_get_variance_2) {
    DataStatistics2 ds2({ 1, 2, 203, 4 });
    auto res = ds2.get_variance();
    EXPECT_EQ(res, 7551.25);
}

TEST_F(DataStatistics2TestGetVariance, test_get_variance_3) {
    DataStatistics2 ds2({ 1, 4, 3, 2 });
    auto res = ds2.get_variance();
    EXPECT_EQ(res, 1.25);
}

TEST_F(DataStatistics2TestGetVariance, test_get_variance_4) {
    DataStatistics2 ds2({ 11, 14, 13, 12 });
    auto res = ds2.get_variance();
    EXPECT_EQ(res, 1.25);
}

TEST_F(DataStatistics2TestGetVariance, test_get_variance_5) {
    DataStatistics2 ds2({ 111, 114, 113, 112 });
    auto res = ds2.get_variance();
    EXPECT_EQ(res, 1.25);
}

class DataStatistics2TestGetStdDeviation : public ::testing::Test {};

TEST_F(DataStatistics2TestGetStdDeviation, test_get_std_deviation_1) {
    DataStatistics2 ds2({ 1, 2, 3, 4 });
    auto res = ds2.get_std_deviation();
    EXPECT_EQ(res, 1.12);
}

TEST_F(DataStatistics2TestGetStdDeviation, test_get_std_deviation_2) {
    DataStatistics2 ds2({ 1, 2, 203, 4 });
    auto res = ds2.get_std_deviation();
    EXPECT_EQ(res, 86.9);
}

TEST_F(DataStatistics2TestGetStdDeviation, test_get_std_deviation_3) {
    DataStatistics2 ds2({ 1, 4, 3, 2 });
    auto res = ds2.get_std_deviation();
    EXPECT_EQ(res, 1.12);
}

TEST_F(DataStatistics2TestGetStdDeviation, test_get_std_deviation_4) {
    DataStatistics2 ds2({ 11, 14, 13, 12 });
    auto res = ds2.get_std_deviation();
    EXPECT_EQ(res, 1.12);
}

TEST_F(DataStatistics2TestGetStdDeviation, test_get_std_deviation_5) {
    DataStatistics2 ds2({ 111, 114, 113, 112 });
    auto res = ds2.get_std_deviation();
    EXPECT_EQ(res, 1.12);
}

class DataStatistics2TestGetCorrelation : public ::testing::Test {};

TEST_F(DataStatistics2TestGetCorrelation, test_get_correlation_1) {
    DataStatistics2 ds2({ 1, 2, 3, 4 });
    auto res = ds2.get_correlation();
    EXPECT_EQ(res, 1.0);
}

TEST_F(DataStatistics2TestGetCorrelation, test_get_correlation_2) {
    DataStatistics2 ds2({ 1, 2, 203, 4 });
    auto res = ds2.get_correlation();
    EXPECT_EQ(res, 1.0);
}

TEST_F(DataStatistics2TestGetCorrelation, test_get_correlation_3) {
    DataStatistics2 ds2({ 1, 4, 3, 2 });
    auto res = ds2.get_correlation();
    EXPECT_EQ(res, 1.0);
}

TEST_F(DataStatistics2TestGetCorrelation, test_get_correlation_4) {
    DataStatistics2 ds2({ 11, 14, 13, 12 });
    auto res = ds2.get_correlation();
    EXPECT_EQ(res, 1.0);
}

TEST_F(DataStatistics2TestGetCorrelation, test_get_correlation_5) {
    DataStatistics2 ds2({ 111, 114, 113, 112 });
    auto res = ds2.get_correlation();
    EXPECT_EQ(res, 1.0);
}

class DataStatistics2Test : public ::testing::Test {};

TEST_F(DataStatistics2Test, test_datastatistics2) {
    DataStatistics2 ds2({ 1, 2, 3, 4 });

    auto res = ds2.get_sum();
    EXPECT_EQ(res, 10);

    res = ds2.get_min();
    EXPECT_EQ(res, 1);

    res = ds2.get_max();
    EXPECT_EQ(res, 4);

    res = ds2.get_variance();
    EXPECT_EQ(res, 1.25);

    res = ds2.get_std_deviation();
    EXPECT_EQ(res, 1.12);

    res = ds2.get_correlation();
    EXPECT_EQ(res, 1.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}