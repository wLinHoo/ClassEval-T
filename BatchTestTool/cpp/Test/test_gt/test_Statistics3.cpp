#include <gtest/gtest.h>  
#include "pch.h"  

bool are_all_elements_nan(const std::vector<double>& vec) {
    for (double value : vec) {
        if (!std::isnan(value)) {
            return false;
        }
    }
    return true;
}

bool are_vectors_equal(const std::vector<std::vector<double>>& v1, const std::vector<std::vector<double>>& v2) {
    if (v1.size() != v2.size()) return false;
    for (size_t i = 0; i < v1.size(); ++i) {
        if (v1[i].size() != v2[i].size()) return false;
        for (size_t j = 0; j < v1[i].size(); ++j) {
            if (std::isnan(v1[i][j]) && std::isnan(v2[i][j])) continue; 
            if (v1[i][j] != v2[i][j]) return false; 
        }
    }
    return true;
}

class Statistics3Test : public ::testing::Test {
protected:
    Statistics3 statistics3;
};

class Statistics3TestMedian : public ::testing::Test {
protected:
    Statistics3 statistics3;
};

class Statistics3TestMode : public ::testing::Test {
protected:
    Statistics3 statistics3;
};

class Statistics3TestCorrelation : public ::testing::Test {
protected:
    Statistics3 statistics3;
};

class Statistics3TestMean : public ::testing::Test {
protected:
    Statistics3 statistics3;
};

class Statistics3TestCorrelationMatrix : public ::testing::Test {
protected:
    Statistics3 statistics3;
};

class Statistics3TestStandardDeviation : public ::testing::Test {
protected:
    Statistics3 statistics3;
};

class Statistics3TestZScore : public ::testing::Test {
protected:
    Statistics3 statistics3;
};

TEST_F(Statistics3Test, TestMain) {
    
    EXPECT_DOUBLE_EQ(statistics3.median({ 1, 2, 3, 4 }), 2.5);

    
    std::vector<int> mode_result = statistics3.mode({ 1, 2, 3, 3 });
    EXPECT_EQ(mode_result, std::vector<int>({ 3 }));

    
    EXPECT_DOUBLE_EQ(statistics3.correlation({ 1, 2, 3 }, { 4, 5, 6 }), 1.0);

    
    EXPECT_DOUBLE_EQ(statistics3.mean({ 1, 2, 3 }), 2.0);

    
    std::vector<std::vector<double>> corr_matrix = statistics3.correlation_matrix(
        { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
    std::vector<std::vector<double>> expected_corr_matrix =
    { {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0} };
    EXPECT_EQ(corr_matrix, expected_corr_matrix);

    
    EXPECT_DOUBLE_EQ(statistics3.standard_deviation({ 1, 2, 3 }), 1.0);

    
    std::vector<double> z_scores = statistics3.z_score({ 1, 2, 3, 4 });
    std::vector<double> expected_z_scores =
    { -1.161895003862225, -0.3872983346207417, 0.3872983346207417, 1.161895003862225 };
    EXPECT_EQ(z_scores, expected_z_scores);
}

TEST_F(Statistics3TestMedian, TestMedian) {
    EXPECT_DOUBLE_EQ(statistics3.median({ 1, 2, 3, 4 }), 2.5);
}

TEST_F(Statistics3TestMedian, TestMedian2) {
    EXPECT_DOUBLE_EQ(statistics3.median({ 1, 2, 3, 4, 5 }), 3);
}

TEST_F(Statistics3TestMedian, TestMedian3) {
    EXPECT_DOUBLE_EQ(statistics3.median({ 1, 2, 3, 4, 5, 6 }), 3.5);
}

TEST_F(Statistics3TestMedian, TestMedian4) {
    EXPECT_DOUBLE_EQ(statistics3.median({ 1, 2, 3, 4, 5, 6, 7 }), 4);
}

TEST_F(Statistics3TestMedian, TestMedian5) {
    EXPECT_DOUBLE_EQ(statistics3.median({ 1, 2, 3, 4, 5, 6, 7, 8 }), 4.5);
}


TEST_F(Statistics3TestMode, TestMode) {
    std::vector<int> result = statistics3.mode({ 1, 2, 3, 3 });
    std::vector<int> expected = { 3 };
    EXPECT_EQ(result, expected);
}

TEST_F(Statistics3TestMode, TestMode2) {
    std::vector<int> result = statistics3.mode({ 1, 2, 3, 3, 4, 4 });
    std::vector<int> expected = { 3, 4 };
    EXPECT_EQ(result, expected);
}

TEST_F(Statistics3TestMode, TestMode3) {
    std::vector<int> result = statistics3.mode({ 1, 2, 3, 3, 4, 4, 5 });
    std::vector<int> expected = { 3, 4 };
    EXPECT_EQ(result, expected);
}

TEST_F(Statistics3TestMode, TestMode4) {
    std::vector<int> result = statistics3.mode({ 1, 2, 3, 3, 4, 4, 5, 5 });
    std::vector<int> expected = { 3, 4, 5 };
    EXPECT_EQ(result, expected);
}

TEST_F(Statistics3TestMode, TestMode5) {
    std::vector<int> result = statistics3.mode({ 1, 2, 3, 3, 4, 4, 5, 5, 6 });
    std::vector<int> expected = { 3, 4, 5 };
    EXPECT_EQ(result, expected);
}

TEST_F(Statistics3TestCorrelation, TestCorrelation) {
    EXPECT_DOUBLE_EQ(statistics3.correlation({ 1, 2, 3 }, { 4, 5, 6 }), 1.0);
}

TEST_F(Statistics3TestCorrelation, TestCorrelation2) {
    EXPECT_DOUBLE_EQ(statistics3.correlation({ 1, 2, 3, 4 }, { 5, 6, 7, 8 }), 1.0);
}

TEST_F(Statistics3TestCorrelation, TestCorrelation3) {
    EXPECT_DOUBLE_EQ(statistics3.correlation({ 1, 2, 3 }, { 1, 2, 3 }), 1.0);
}

TEST_F(Statistics3TestCorrelation, TestCorrelation4) {
    EXPECT_TRUE(std::isnan(statistics3.correlation({ 1, 1, 1 }, { 2, 2, 2 })));
}

TEST_F(Statistics3TestCorrelation, TestCorrelation5) {
    EXPECT_TRUE(std::isnan(statistics3.correlation({ 1, 1, 1 }, { 1, 1, 1 })));
}


TEST_F(Statistics3TestMean, TestMean) {
    EXPECT_DOUBLE_EQ(statistics3.mean({ 1, 2, 3 }), 2.0);
}

TEST_F(Statistics3TestMean, TestMean2) {
    EXPECT_TRUE(std::isnan(statistics3.mean({})));
}

TEST_F(Statistics3TestMean, TestMean3) {
    EXPECT_DOUBLE_EQ(statistics3.mean({ 1, 1, 1 }), 1.0);
}

TEST_F(Statistics3TestMean, TestMean4) {
    EXPECT_DOUBLE_EQ(statistics3.mean({ 1, 1, 1, 1 }), 1.0);
}

TEST_F(Statistics3TestMean, TestMean5) {
    EXPECT_DOUBLE_EQ(statistics3.mean({ 1, 1, 1, 1, 1 }), 1.0);
}


TEST_F(Statistics3TestCorrelationMatrix, TestCorrelationMatrix) {
    std::vector<std::vector<double>> result = statistics3.correlation_matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
    std::vector<std::vector<double>> expected = { {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0} };
    EXPECT_TRUE(are_vectors_equal(result, expected));
}

TEST_F(Statistics3TestCorrelationMatrix, TestCorrelationMatrix2) {
    std::vector<std::vector<double>> result = statistics3.correlation_matrix({ {1, 2, 3}, {4, 5, 6} });
    std::vector<std::vector<double>> expected = { {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0} };
    EXPECT_TRUE(are_vectors_equal(result, expected));
}

TEST_F(Statistics3TestCorrelationMatrix, TestCorrelationMatrix3) {
    std::vector<std::vector<double>> result = statistics3.correlation_matrix({ {1, 2, 3} });
    std::vector<std::vector<double>> expected = { {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()},
                                                {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()},
                                                {std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN()} };
    EXPECT_TRUE(are_vectors_equal(result, expected));
}

TEST_F(Statistics3TestCorrelationMatrix, TestCorrelationMatrix4) {
    std::vector<std::vector<double>> result = statistics3.correlation_matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} });
    std::vector<std::vector<double>> expected = { {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0} };
    EXPECT_TRUE(are_vectors_equal(result, expected));
}

TEST_F(Statistics3TestCorrelationMatrix, TestCorrelationMatrix5) {
    std::vector<std::vector<double>> result = statistics3.correlation_matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15} });
    std::vector<std::vector<double>> expected = { {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0} };
    EXPECT_TRUE(are_vectors_equal(result, expected));
}


TEST_F(Statistics3TestStandardDeviation, TestStandardDeviation) {
    EXPECT_DOUBLE_EQ(statistics3.standard_deviation({ 1, 2, 3 }), 1.0);
}

TEST_F(Statistics3TestStandardDeviation, TestStandardDeviation2) {
    EXPECT_DOUBLE_EQ(statistics3.standard_deviation({ 1, 1, 1 }), 0.0);
}

TEST_F(Statistics3TestStandardDeviation, TestStandardDeviation3) {
    EXPECT_DOUBLE_EQ(statistics3.standard_deviation({ 1, 1 }), 0.0);
}

TEST_F(Statistics3TestStandardDeviation, TestStandardDeviation4) {
    EXPECT_DOUBLE_EQ(statistics3.standard_deviation({ 1, 1, 1, 1 }), 0.0);
}

TEST_F(Statistics3TestStandardDeviation, TestStandardDeviation5) {
    EXPECT_DOUBLE_EQ(statistics3.standard_deviation({ 1, 1, 2, 1, 4 }), 1.3038404810405297);
}


TEST_F(Statistics3TestZScore, TestZScore) {
    std::vector<double> result = statistics3.z_score({1, 2, 3, 4});
    std::vector<double> expected = {-1.161895003862225, -0.3872983346207417, 0.3872983346207417, 1.161895003862225};
    EXPECT_EQ(result, expected);
}

TEST_F(Statistics3TestZScore, TestZScore2) {
    std::vector<double> result = statistics3.z_score({1, 1, 1, 1});
    EXPECT_TRUE(are_all_elements_nan(result));
}

TEST_F(Statistics3TestZScore, TestZScore3) {
    std::vector<double> result = statistics3.z_score({1});
    EXPECT_TRUE(are_all_elements_nan(result));
}

TEST_F(Statistics3TestZScore, TestZScore4) {
    std::vector<double> result = statistics3.z_score({1, 1, 2, 3});
    std::vector<double> expected = {-0.7833494518006403, -0.7833494518006403, 0.26111648393354675, 1.3055824196677337};
    EXPECT_EQ(result, expected);
}

TEST_F(Statistics3TestZScore, TestZScore5) {
    std::vector<double> result = statistics3.z_score({1, 1, 1, 1, 1});
    EXPECT_TRUE(are_all_elements_nan(result));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}