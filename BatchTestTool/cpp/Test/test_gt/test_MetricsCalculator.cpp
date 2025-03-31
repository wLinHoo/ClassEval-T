#include <gtest/gtest.h>
#include "pch.h"  

class MetricsCalculatorTestUpdate : public ::testing::Test {};

TEST(MetricsCalculatorTestUpdate, TestUpdate1) {
    MetricsCalculator mc;
    EXPECT_EQ(std::make_tuple(mc.true_positives, mc.false_positives, mc.false_negatives, mc.true_negatives), std::make_tuple(0, 0, 0, 0));

    mc.update({ 1, 1, 0, 0 }, { 1, 0, 0, 1 });
    EXPECT_EQ(std::make_tuple(mc.true_positives, mc.false_positives, mc.false_negatives, mc.true_negatives), std::make_tuple(1, 1, 1, 1));
}

TEST(MetricsCalculatorTestUpdate, TestUpdate2) {
    MetricsCalculator mc;
    EXPECT_EQ(std::make_tuple(mc.true_positives, mc.false_positives, mc.false_negatives, mc.true_negatives), std::make_tuple(0, 0, 0, 0));

    mc.update({ 1, 1, 1, 0 }, { 1, 0, 0, 1 });
    EXPECT_EQ(std::make_tuple(mc.true_positives, mc.false_positives, mc.false_negatives, mc.true_negatives), std::make_tuple(1, 2, 1, 0));
}

TEST(MetricsCalculatorTestUpdate, TestUpdate3) {
    MetricsCalculator mc;
    EXPECT_EQ(std::make_tuple(mc.true_positives, mc.false_positives, mc.false_negatives, mc.true_negatives), std::make_tuple(0, 0, 0, 0));

    mc.update({ 1, 1, 0, 1 }, { 1, 0, 0, 1 });
    EXPECT_EQ(std::make_tuple(mc.true_positives, mc.false_positives, mc.false_negatives, mc.true_negatives), std::make_tuple(2, 1, 0, 1));
}

TEST(MetricsCalculatorTestUpdate, TestUpdate4) {
    MetricsCalculator mc;
    EXPECT_EQ(std::make_tuple(mc.true_positives, mc.false_positives, mc.false_negatives, mc.true_negatives), std::make_tuple(0, 0, 0, 0));

    mc.update({ 1, 1, 0, 0 }, { 1, 1, 0, 1 });
    EXPECT_EQ(std::make_tuple(mc.true_positives, mc.false_positives, mc.false_negatives, mc.true_negatives), std::make_tuple(2, 0, 1, 1));
}

TEST(MetricsCalculatorTestUpdate, TestUpdate5) {
    MetricsCalculator mc;
    EXPECT_EQ(std::make_tuple(mc.true_positives, mc.false_positives, mc.false_negatives, mc.true_negatives), std::make_tuple(0, 0, 0, 0));

    mc.update({ 1, 1, 0, 0 }, { 1, 0, 1, 1 });
    EXPECT_EQ(std::make_tuple(mc.true_positives, mc.false_positives, mc.false_negatives, mc.true_negatives), std::make_tuple(1, 1, 2, 0));
}

class MetricsCalculatorTestPrecision : public ::testing::Test{};

TEST(MetricsCalculatorTestPrecision, TestPrecision1) {
    MetricsCalculator mc;
    double temp = mc.precision({ 1, 1, 0, 0 }, { 1, 0, 0, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.5);
}

TEST(MetricsCalculatorTestPrecision, TestPrecision2) {
    MetricsCalculator mc;
    double temp = mc.precision({ 1, 1, 1, 0 }, { 1, 0, 0, 1 });
    EXPECT_NEAR(temp, 0.3333333333333333, 1e-9);  
}

TEST(MetricsCalculatorTestPrecision, TestPrecision3) {
    MetricsCalculator mc;
    double temp = mc.precision({ 1, 1, 0, 1 }, { 1, 0, 0, 1 });
    EXPECT_NEAR(temp, 0.6666666666666666, 1e-9);  
}

TEST(MetricsCalculatorTestPrecision, TestPrecision4) {
    MetricsCalculator mc;
    double temp = mc.precision({ 1, 1, 0, 0 }, { 1, 1, 0, 1 });
    EXPECT_DOUBLE_EQ(temp, 1.0);
}

TEST(MetricsCalculatorTestPrecision, TestPrecision5) {
    MetricsCalculator mc;
    double temp = mc.precision({ 1, 1, 0, 0 }, { 1, 0, 1, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.5);
}

TEST(MetricsCalculatorTestPrecision, TestPrecision6) {
    MetricsCalculator mc;
    double temp = mc.precision({ 0, 0, 0, 0 }, { 1, 0, 1, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.0);
}

class MetricsCalculatorTestRecall : public ::testing::Test{};

TEST_F(MetricsCalculatorTestRecall, TestRecall1) {
    MetricsCalculator mc;
    double temp = mc.recall({ 1, 1, 0, 0 }, { 1, 0, 0, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.5);
}

TEST_F(MetricsCalculatorTestRecall, TestRecall2) {
    MetricsCalculator mc;
    double temp = mc.recall({ 1, 1, 1, 0 }, { 1, 0, 0, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.5);
}

TEST_F(MetricsCalculatorTestRecall, TestRecall3) {
    MetricsCalculator mc;
    double temp = mc.recall({ 1, 1, 0, 1 }, { 1, 0, 0, 1 });
    EXPECT_DOUBLE_EQ(temp, 1.0);
}

TEST_F(MetricsCalculatorTestRecall, TestRecall4) {
    MetricsCalculator mc;
    double temp = mc.recall({ 1, 1, 0, 0 }, { 1, 1, 0, 1 });
    EXPECT_NEAR(temp, 0.6666666666666666, 1e-9);  
}

TEST_F(MetricsCalculatorTestRecall, TestRecall5) {
    MetricsCalculator mc;
    double temp = mc.recall({ 1, 1, 0, 0 }, { 1, 0, 1, 1 });
    EXPECT_NEAR(temp, 0.3333333333333333, 1e-9);  
}

TEST_F(MetricsCalculatorTestRecall, TestRecall6) {
    MetricsCalculator mc;
    double temp = mc.recall({ 1, 1, 0, 0 }, { 0, 0, 0, 0 });
    EXPECT_DOUBLE_EQ(temp, 0.0);
}

class MetricsCalculatorTestF1Score : public ::testing::Test {};

TEST_F(MetricsCalculatorTestF1Score, TestF1Score1) {
    MetricsCalculator mc;
    double temp = mc.f1_score({ 1, 1, 0, 0 }, { 1, 0, 0, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.5);
}

TEST_F(MetricsCalculatorTestF1Score, TestF1Score2) {
    MetricsCalculator mc;
    double temp = mc.f1_score({ 1, 1, 1, 0 }, { 1, 0, 0, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.4);
}

TEST_F(MetricsCalculatorTestF1Score, TestF1Score3) {
    MetricsCalculator mc;
    double temp = mc.f1_score({ 1, 1, 0, 1 }, { 1, 0, 0, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.8);
}

TEST_F(MetricsCalculatorTestF1Score, TestF1Score4) {
    MetricsCalculator mc;
    double temp = mc.f1_score({ 1, 1, 0, 0 }, { 1, 1, 0, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.8);
}

TEST_F(MetricsCalculatorTestF1Score, TestF1Score5) {
    MetricsCalculator mc;
    double temp = mc.f1_score({ 1, 1, 0, 0 }, { 1, 0, 1, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.4);
}

TEST_F(MetricsCalculatorTestF1Score, TestF1Score6) {
    MetricsCalculator mc;
    double temp = mc.f1_score({ 0, 0, 0, 0 }, { 0, 0, 0, 0 });
    EXPECT_DOUBLE_EQ(temp, 0.0);
}

class MetricsCalculatorTestAccuracy : public ::testing::Test {};

TEST_F(MetricsCalculatorTestAccuracy, TestAccuracy1) {
    MetricsCalculator mc;
    double temp = mc.accuracy({ 1, 1, 0, 0 }, { 1, 0, 0, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.5);
}

TEST_F(MetricsCalculatorTestAccuracy, TestAccuracy2) {
    MetricsCalculator mc;
    double temp = mc.accuracy({ 1, 1, 2, 0 }, { 1, 0, 0, 1 });
    EXPECT_NEAR(temp, 0.3333333333333333, 1e-9);  
}

TEST_F(MetricsCalculatorTestAccuracy, TestAccuracy3) {
    MetricsCalculator mc;
    double temp = mc.accuracy({ 1, 1, 0, 1 }, { 1, 0, 0, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.75);
}

TEST_F(MetricsCalculatorTestAccuracy, TestAccuracy4) {
    MetricsCalculator mc;
    double temp = mc.accuracy({ 1, 1, 0, 0 }, { 1, 1, 0, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.75);
}

TEST_F(MetricsCalculatorTestAccuracy, TestAccuracy5) {
    MetricsCalculator mc;
    double temp = mc.accuracy({ 1, 1, 0, 0 }, { 1, 0, 1, 1 });
    EXPECT_DOUBLE_EQ(temp, 0.25);
}

TEST_F(MetricsCalculatorTestAccuracy, TestAccuracy6) {
    MetricsCalculator mc;
    double temp = mc.accuracy({}, {});
    EXPECT_DOUBLE_EQ(temp, 0.0);
}

class MetricsCalculatorTest : public ::testing::Test {};

TEST(MetricsCalculatorTest, TestMetricsCalculator) {
    MetricsCalculator mc;
    EXPECT_EQ(std::make_tuple(mc.true_positives, mc.false_positives, mc.false_negatives, mc.true_negatives), std::make_tuple(0, 0, 0, 0));

    mc.update({ 1, 1, 0, 0 }, { 1, 0, 0, 1 });
    EXPECT_EQ(std::make_tuple(mc.true_positives, mc.false_positives, mc.false_negatives, mc.true_negatives), std::make_tuple(1, 1, 1, 1));

    double temp = mc.precision({ 1, 1, 0, 0 }, { 1, 0, 0, 1 });
    EXPECT_EQ(temp, 0.5);

    temp = mc.recall({ 1, 1, 0, 0 }, { 1, 0, 0, 1 });
    EXPECT_EQ(temp, 0.5);

    temp = mc.f1_score({ 1, 1, 0, 0 }, { 1, 0, 0, 1 });
    EXPECT_EQ(temp, 0.5);

    temp = mc.accuracy({ 1, 1, 0, 0 }, { 1, 0, 0, 1 });
    EXPECT_EQ(temp, 0.5);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
