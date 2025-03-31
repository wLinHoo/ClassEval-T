#include <gtest/gtest.h>
#include <vector>
#include <utility> 
#include <stdexcept> 

#include "pch.h"  

class MetricsCalculator2TestMrr : public ::testing::Test {
protected:
    MetricsCalculator2 mc2;  
};

TEST_F(MetricsCalculator2TestMrr, test_mrr_1) {
    auto [res1, res2] = MetricsCalculator2::mrr({ {std::vector<int>{1, 0, 1, 0}, 4} });
    EXPECT_DOUBLE_EQ(res1, 1.0);
    EXPECT_EQ(res2, std::vector<double>{1.0});
}

TEST_F(MetricsCalculator2TestMrr, test_mrr_2) {
    auto [res1, res2] = MetricsCalculator2::mrr({ {std::vector<int>{0, 0, 0, 1}, 4} });
    EXPECT_DOUBLE_EQ(res1, 0.25);
    EXPECT_EQ(res2, std::vector<double>{0.25});
}

TEST_F(MetricsCalculator2TestMrr, test_mrr_3) {
    auto [res1, res2] = MetricsCalculator2::mrr({
        {std::vector<int>{1, 0, 1, 0}, 4},
        {std::vector<int>{0, 1, 0, 1}, 4}
        });
    EXPECT_DOUBLE_EQ(res1, 0.75);
    std::vector<double> l{ 1.0, 0.5 };
    EXPECT_EQ(res2, l);
}

TEST_F(MetricsCalculator2TestMrr, test_mrr_4) {
    auto [res1, res2] = MetricsCalculator2::mrr({
        {std::vector<int>{1, 1, 1, 0}, 4},
        {std::vector<int>{0, 0, 0, 1}, 4}
        });
    EXPECT_DOUBLE_EQ(res1, 0.625);
    std::vector<double> l{1.0, 0.25};
    EXPECT_EQ(res2, l);
}

TEST_F(MetricsCalculator2TestMrr, test_mrr_5) {
    auto [res1, res2] = MetricsCalculator2::mrr({
        {std::vector<int>{1, 0, 1, 1}, 4},
        {std::vector<int>{0, 1, 0, 0}, 4}
        });
    EXPECT_DOUBLE_EQ(res1, 0.75);
    std::vector<double> l{ 1.0, 0.5 };
    EXPECT_EQ(res2, l);
}



TEST_F(MetricsCalculator2TestMrr, test_mrr_7) {
    auto [res1, res2] = MetricsCalculator2::mrr({});
    EXPECT_DOUBLE_EQ(res1, 0.0);
    EXPECT_EQ(res2, std::vector<double>{0.0});
}

TEST_F(MetricsCalculator2TestMrr, test_mrr_8) {
    auto [res1, res2] = MetricsCalculator2::mrr({
        {std::vector<int>{1, 0, 1, 1}, 0},
        {std::vector<int>{0, 1, 0, 0}, 0}
        });
    EXPECT_DOUBLE_EQ(res1, 0.0);
    std::vector<double> l{ 0.0,0.0 };
    EXPECT_EQ(res2, l);
}

class MetricsCalculator2TestMap : public ::testing::Test {
protected:
    MetricsCalculator2 mc2;  
};

TEST_F(MetricsCalculator2TestMap, test_map_1) {
    auto [res1, res2] = MetricsCalculator2::map({ {std::vector<int>{1, 0, 1, 0}, 4} });
    EXPECT_DOUBLE_EQ(res1, 0.41666666666666663);
    EXPECT_EQ(res2, std::vector<double>{0.41666666666666663});
}

TEST_F(MetricsCalculator2TestMap, test_map_2) {
    auto [res1, res2] = MetricsCalculator2::map({ {std::vector<int>{0, 0, 0, 1}, 4} });
    EXPECT_DOUBLE_EQ(res1, 0.0625);
    EXPECT_EQ(res2, std::vector<double>{0.0625});
}

TEST_F(MetricsCalculator2TestMap, test_map_3) {
    auto [res1, res2] = MetricsCalculator2::map({
        {std::vector<int>{1, 0, 1, 0}, 4},
        {std::vector<int>{0, 1, 0, 1}, 4}
        });
    EXPECT_DOUBLE_EQ(res1, 0.3333333333333333);
    std::vector<double> l{0.41666666666666663, 0.25};
    EXPECT_EQ(res2, l);
}

TEST_F(MetricsCalculator2TestMap, test_map_4) {
    auto [res1, res2] = MetricsCalculator2::map({
        {std::vector<int>{1, 1, 1, 0}, 4},
        {std::vector<int>{0, 0, 0, 1}, 4}
        });
    EXPECT_DOUBLE_EQ(res1, 0.40625);
    std::vector<double> l{ 0.75, 0.0625 };
    EXPECT_EQ(res2, l);
}

TEST_F(MetricsCalculator2TestMap, test_map_5) {
    auto [res1, res2] = MetricsCalculator2::map({
        {std::vector<int>{1, 0, 1, 1}, 4},
        {std::vector<int>{0, 1, 0, 0}, 4}
        });
    EXPECT_DOUBLE_EQ(res1, 0.3645833333333333);
    std::vector<double> l{0.6041666666666666, 0.125};
    EXPECT_EQ(res2, l);
}

TEST_F(MetricsCalculator2TestMap, test_map_7) {
    auto [res1, res2] = MetricsCalculator2::map({});
    EXPECT_DOUBLE_EQ(res1, 0.0);
    EXPECT_EQ(res2, std::vector<double>{0.0});
}

TEST_F(MetricsCalculator2TestMap, test_map_8) {
    auto [res1, res2] = MetricsCalculator2::map({
        {std::vector<int>{1, 0, 1, 1}, 0},
        {std::vector<int>{0, 1, 0, 0}, 0}
        });
    EXPECT_DOUBLE_EQ(res1, 0.0);
    std::vector<double> l{0.0, 0.0}; 
    EXPECT_EQ(res2, l);
}

class MetricsCalculator2Test : public ::testing::Test {
protected:
    MetricsCalculator2 mc2;  
};

TEST_F(MetricsCalculator2Test, test_metricscalculator2_1) {
    auto [res1, res2] = MetricsCalculator2::mrr({ {std::vector<int>{1, 0, 1, 0}, 4} });
    EXPECT_DOUBLE_EQ(res1, 1.0);
    EXPECT_EQ(res2, std::vector<double>{1.0});
}

TEST_F(MetricsCalculator2Test, test_metricscalculator2_2) {
    auto [res1, res2] = MetricsCalculator2::mrr({
        {std::vector<int>{1, 0, 1, 0}, 4},
        {std::vector<int>{0, 1, 0, 1}, 4}
        });
    EXPECT_DOUBLE_EQ(res1, 0.75);
    std::vector<double> l{1.0, 0.5};
    EXPECT_EQ(res2, l);
}

TEST_F(MetricsCalculator2Test, test_metricscalculator2_3) {
    auto [res1, res2] = MetricsCalculator2::map({ {std::vector<int>{1, 0, 1, 0}, 4} });
    EXPECT_DOUBLE_EQ(res1, 0.41666666666666663);
    EXPECT_EQ(res2, std::vector<double>{0.41666666666666663});
}

TEST_F(MetricsCalculator2Test, test_metricscalculator2_4) {
    auto [res1, res2] = MetricsCalculator2::map({
        {std::vector<int>{1, 0, 1, 0}, 4},
        {std::vector<int>{0, 1, 0, 1}, 4}
        });
    EXPECT_DOUBLE_EQ(res1, 0.3333333333333333);
    std::vector<double> r{0.41666666666666663, 0.25};
    EXPECT_EQ(res2, r);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}