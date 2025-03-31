#include <gtest/gtest.h>
#include "pch.h" 


class DataStatisticsTestMean : public ::testing::Test {
protected:
    DataStatistics ds;
};

TEST_F(DataStatisticsTestMean, test_mean_1) {
    std::vector<double> data = { 1, 2, 3, 4, 5 };
    double res = ds.mean(data);
    EXPECT_NEAR(res, 3.00, 0.01);
}

TEST_F(DataStatisticsTestMean, test_mean_2) {
    std::vector<double> data = { 1, 2, 3, 4, 5, 6 };
    double res = ds.mean(data);
    EXPECT_NEAR(res, 3.50, 0.01);
}

TEST_F(DataStatisticsTestMean, test_mean_3) {
    std::vector<double> data = { 1, 2, 4, 5, 6, 7 };
    double res = ds.mean(data);
    EXPECT_NEAR(res, 4.17, 0.01);
}

TEST_F(DataStatisticsTestMean, test_mean_4) {
    std::vector<double> data = { 1, 2, 4, 5, 6, 7, 8 };
    double res = ds.mean(data);
    EXPECT_NEAR(res, 4.71, 0.01);
}

TEST_F(DataStatisticsTestMean, test_mean_5) {
    std::vector<double> data = { 1, 2, 4, 5, 6, 7, 8, 9 };
    double res = ds.mean(data);
    EXPECT_NEAR(res, 5.25, 0.01);
}


class DataStatisticsTestMedian : public ::testing::Test {
protected:
    DataStatistics ds;
};

TEST_F(DataStatisticsTestMedian, test_median_1) {
    std::vector<double> data = { 2, 5, 1, 3, 4 };
    double res = ds.median(data);
    EXPECT_EQ(res, 3);
}

TEST_F(DataStatisticsTestMedian, test_median_2) {
    std::vector<double> data = { 2, 5, 1, 3, 4, 6 };
    double res = ds.median(data);
    EXPECT_NEAR(res, 3.50, 0.01);
}

TEST_F(DataStatisticsTestMedian, test_median_3) {
    std::vector<double> data = { 2, 5, 1, 4, 6, 7 };
    double res = ds.median(data);
    EXPECT_NEAR(res, 4.5, 0.01);
}

TEST_F(DataStatisticsTestMedian, test_median_4) {
    std::vector<double> data = { 2, 5, 1, 4, 6, 7, 8 };
    double res = ds.median(data);
    EXPECT_EQ(res, 5);
}

TEST_F(DataStatisticsTestMedian, test_median_5) {
    std::vector<double> data = { 2, 5, 1, 4, 6, 7, 8, 9 };
    double res = ds.median(data);
    EXPECT_NEAR(res, 5.5, 0.01);
}


class DataStatisticsTestMode : public ::testing::Test {
protected:
    DataStatistics ds;
};

TEST_F(DataStatisticsTestMode, test_mode_1) {
    std::vector<int> data = { 2, 2, 3, 3, 4 };
    std::vector<int> res = ds.mode(data);
    std::vector<int> expected = { 2, 3 };
    EXPECT_EQ(res, expected);
}

TEST_F(DataStatisticsTestMode, test_mode_2) {
    std::vector<int> data = { 2, 2, 2, 3, 3, 4 };
    std::vector<int> res = ds.mode(data);
    std::vector<int> expected = { 2 };
    EXPECT_EQ(res, expected);
}

TEST_F(DataStatisticsTestMode, test_mode_3) {
    std::vector<int> data = { 2, 2, 3, 3, 4, 4 };
    std::vector<int> res = ds.mode(data);
    std::vector<int> expected = { 2, 3, 4 };
    EXPECT_EQ(res, expected);
}

TEST_F(DataStatisticsTestMode, test_mode_4) {
    std::vector<int> data = { 2, 2, 3, 3, 4, 4, 4 };
    std::vector<int> res = ds.mode(data);
    std::vector<int> expected = { 4 };
    EXPECT_EQ(res, expected);
}

TEST_F(DataStatisticsTestMode, test_mode_5) {
    std::vector<int> data = { 2, 2, 3, 3, 4, 4, 4, 5 };
    std::vector<int> res = ds.mode(data);
    std::vector<int> expected = { 4 };
    EXPECT_EQ(res, expected);
}


class DataStatisticsTest : public ::testing::Test {
protected:
    DataStatistics ds;
};

TEST_F(DataStatisticsTest, test_datastatistics) {
    std::vector<double> data_mean = { 1, 2, 3, 4, 5 };
    double res_mean = ds.mean(data_mean);
    EXPECT_NEAR(res_mean, 3.00, 0.01);

    std::vector<double> data_median = { 2, 5, 1, 3, 4 };
    double res_median = ds.median(data_median);
    EXPECT_EQ(res_median, 3.00);

    std::vector<int> data_mode = { 2, 2, 3, 3, 4 };
    std::vector<int> res_mode = ds.mode(data_mode);
    std::vector<int> expected_mode = { 2, 3 };
    EXPECT_EQ(res_mode, expected_mode);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}