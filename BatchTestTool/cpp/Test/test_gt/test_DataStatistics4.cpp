#include "gtest/gtest.h"
#include "pch.h"
#include <cmath>
#include <vector>

class DataStatistics4TestCorrelationCoefficient : public ::testing::Test {
protected:
    DataStatistics4TestCorrelationCoefficient() {}
    ~DataStatistics4TestCorrelationCoefficient() override {}
};

TEST_F(DataStatistics4TestCorrelationCoefficient, test_correlation_coefficient) {
    EXPECT_DOUBLE_EQ(DataStatistics4::correlation_coefficient({ 1, 2, 3 }, { 4, 5, 6 }), 0.9999999999999998);
}

TEST_F(DataStatistics4TestCorrelationCoefficient, test_correlation_coefficient_2) {
    EXPECT_DOUBLE_EQ(DataStatistics4::correlation_coefficient({ 1, 1, 1 }, { 2, 2, 2 }), 0);
}

TEST_F(DataStatistics4TestCorrelationCoefficient, test_correlation_coefficient_3) {
    EXPECT_DOUBLE_EQ(DataStatistics4::correlation_coefficient({ 1, 2, 3 }, { 1, 2, 3 }), 0.9999999999999998);
}

TEST_F(DataStatistics4TestCorrelationCoefficient, test_correlation_coefficient_4) {
    EXPECT_DOUBLE_EQ(DataStatistics4::correlation_coefficient({ 1, 2, 3 }, { 1, 2, 4 }), 0.9819805060619659);
}

TEST_F(DataStatistics4TestCorrelationCoefficient, test_correlation_coefficient_5) {
    EXPECT_DOUBLE_EQ(DataStatistics4::correlation_coefficient({ 1, 2, 3 }, { 1, 5, 3 }), 0.4999999999999999);
}

class DataStatistics4TestSkewness : public ::testing::Test {
protected:
    DataStatistics4TestSkewness() {}
    ~DataStatistics4TestSkewness() override {}
};

TEST_F(DataStatistics4TestSkewness, test_skewness) {
    EXPECT_DOUBLE_EQ(DataStatistics4::skewness({ 1, 2, 5 }), 2.3760224064818463);
}

TEST_F(DataStatistics4TestSkewness, test_skewness_2) {
    EXPECT_DOUBLE_EQ(DataStatistics4::skewness({ 1, 1, 1 }), 0);
}

TEST_F(DataStatistics4TestSkewness, test_skewness_3) {
    EXPECT_DOUBLE_EQ(DataStatistics4::skewness({ 1, 2, 3 }), 0);
}

TEST_F(DataStatistics4TestSkewness, test_skewness_4) {
    EXPECT_DOUBLE_EQ(DataStatistics4::skewness({ 1, 2, 4 }), 1.7181079837227264);
}

TEST_F(DataStatistics4TestSkewness, test_skewness_5) {
    EXPECT_DOUBLE_EQ(DataStatistics4::skewness({ 1, 5, 3 }), 0.0);
}

class DataStatistics4TestKurtosis : public ::testing::Test {
protected:
    DataStatistics4TestKurtosis() {}
    ~DataStatistics4TestKurtosis() override {}
};

TEST_F(DataStatistics4TestKurtosis, test_kurtosis) {
    EXPECT_DOUBLE_EQ(DataStatistics4::kurtosis({ 1, 2, 5 }), -1.5000000000000002);
}

TEST_F(DataStatistics4TestKurtosis, test_kurtosis_2) {
    EXPECT_TRUE(std::isnan(DataStatistics4::kurtosis({ 1, 1, 1 })));
}

TEST_F(DataStatistics4TestKurtosis, test_kurtosis_3) {
    EXPECT_DOUBLE_EQ(DataStatistics4::kurtosis({ 1, 2, 3 }), -1.5000000000000002);
}

TEST_F(DataStatistics4TestKurtosis, test_kurtosis_4) {
    EXPECT_DOUBLE_EQ(DataStatistics4::kurtosis({ 1, 2, 4 }), -1.4999999999999996);
}

TEST_F(DataStatistics4TestKurtosis, test_kurtosis_5) {
    EXPECT_DOUBLE_EQ(DataStatistics4::kurtosis({ 1, 5, 3 }), -1.5000000000000002);
}

class DataStatistics4TestPDF : public ::testing::Test {
protected:
    DataStatistics4TestPDF() {}
    ~DataStatistics4TestPDF() override {}
};

TEST_F(DataStatistics4TestPDF, test_pdf) {
    std::vector<double> expected = { 0.3989422804014327, 0.24197072451914337, 0.05399096651318806 };
    EXPECT_EQ(DataStatistics4::pdf({ 1, 2, 3 }, 1, 1), expected);
}

TEST_F(DataStatistics4TestPDF, test_pdf_2) {
    std::vector<double> expected = { 0.3989422804014327, 0.3989422804014327, 0.3989422804014327 };
    EXPECT_EQ(DataStatistics4::pdf({ 1, 1, 1 }, 1, 1), expected);
}

TEST_F(DataStatistics4TestPDF, test_pdf_3) {
    std::vector<double> expected = { 0.24197072451914337, 0.3989422804014327, 0.24197072451914337 };
    EXPECT_EQ(DataStatistics4::pdf({ 1, 2, 3 }, 2, 1), expected);
}

TEST_F(DataStatistics4TestPDF, test_pdf_4) {
    std::vector<double> expected = { 0.19947114020071635, 0.17603266338214976, 0.12098536225957168 };
    EXPECT_EQ(DataStatistics4::pdf({ 1, 2, 3 }, 1, 2), expected);
}

TEST_F(DataStatistics4TestPDF, test_pdf_5) {
    std::vector<double> expected = { 0.17603266338214976, 0.19947114020071635, 0.17603266338214976 };
    EXPECT_EQ(DataStatistics4::pdf({ 1, 2, 3 }, 2, 2), expected);
}

class DataStatistics4TestMain : public ::testing::Test {
protected:
    DataStatistics4TestMain() {}
    ~DataStatistics4TestMain() override {}
};

TEST_F(DataStatistics4TestMain, test_main) {
    EXPECT_DOUBLE_EQ(DataStatistics4::correlation_coefficient({ 1, 2, 3 }, { 4, 5, 6 }), 0.9999999999999998);
    EXPECT_DOUBLE_EQ(DataStatistics4::skewness({ 1, 2, 5 }), 2.3760224064818463);
    EXPECT_DOUBLE_EQ(DataStatistics4::kurtosis({ 1, 2, 5 }), -1.5000000000000002);
    std::vector<double> expected = { 0.3989422804014327, 0.24197072451914337, 0.05399096651318806 };
    EXPECT_EQ(DataStatistics4::pdf({ 1, 2, 3 }, 1, 1), expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}