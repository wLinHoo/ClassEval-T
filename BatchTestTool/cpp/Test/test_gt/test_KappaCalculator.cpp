#include <gtest/gtest.h>
#include "pch.h"

class KappaCalculatorTestKappa : public ::testing::Test {
protected:
    void SetUp() override {
        
    }

    void TearDown() override {
        
    }
};

TEST_F(KappaCalculatorTestKappa, test_kappa_1) {
    EXPECT_DOUBLE_EQ(KappaCalculator::kappa({ {2, 1, 1}, {1, 2, 1}, {1, 1, 2} }, 3), 0.25);
}

TEST_F(KappaCalculatorTestKappa, test_kappa_2) {
    EXPECT_NEAR(KappaCalculator::kappa({ {2, 2, 1}, {1, 2, 1}, {1, 1, 2} }, 3), 0.19469026548672572, 1e-9);
}

TEST_F(KappaCalculatorTestKappa, test_kappa_3) {
    EXPECT_NEAR(KappaCalculator::kappa({ {2, 1, 2}, {1, 2, 1}, {1, 1, 2} }, 3), 0.19469026548672572, 1e-9);
}

TEST_F(KappaCalculatorTestKappa, test_kappa_4) {
    EXPECT_NEAR(KappaCalculator::kappa({ {2, 1, 1}, {2, 2, 1}, {1, 1, 2} }, 3), 0.19469026548672572, 1e-9);
}

TEST_F(KappaCalculatorTestKappa, test_kappa_5) {
    EXPECT_NEAR(KappaCalculator::kappa({ {2, 1, 1}, {1, 2, 2}, {1, 1, 2} }, 3), 0.19469026548672572, 1e-9);
}

class KappaCalculatorTestFleissKappa : public ::testing::Test {
protected:
    void SetUp() override {
        
    }

    void TearDown() override {
        
    }
};

TEST_F(KappaCalculatorTestFleissKappa, test_fleiss_kappa_1) {
    EXPECT_DOUBLE_EQ(KappaCalculator::fleiss_kappa({
        {0, 0, 0, 0, 14},
        {0, 2, 6, 4, 2},
        {0, 0, 3, 5, 6},
        {0, 3, 9, 2, 0},
        {2, 2, 8, 1, 1},
        {7, 7, 0, 0, 0},
        {3, 2, 6, 3, 0},
        {2, 5, 3, 2, 2},
        {6, 5, 2, 1, 0},
        {0, 2, 2, 3, 7}
        }, 10, 5, 14), 0.20993070442195522);
}

TEST_F(KappaCalculatorTestFleissKappa, test_fleiss_kappa_2) {
    EXPECT_DOUBLE_EQ(KappaCalculator::fleiss_kappa({
        {1, 0, 0, 0, 14},
        {0, 2, 6, 4, 2},
        {0, 0, 3, 5, 6},
        {0, 3, 9, 2, 0},
        {2, 2, 8, 1, 1},
        {7, 7, 0, 0, 0},
        {3, 2, 6, 3, 0},
        {2, 5, 3, 2, 2},
        {6, 5, 2, 1, 0},
        {0, 2, 2, 3, 7}
        }, 10, 5, 14), 0.2115748928799344);
}

TEST_F(KappaCalculatorTestFleissKappa, test_fleiss_kappa_3) {
    EXPECT_DOUBLE_EQ(KappaCalculator::fleiss_kappa({
        {0, 1, 0, 0, 14},
        {0, 2, 6, 4, 2},
        {0, 0, 3, 5, 6},
        {0, 3, 9, 2, 0},
        {2, 2, 8, 1, 1},
        {7, 7, 0, 0, 0},
        {3, 2, 6, 3, 0},
        {2, 5, 3, 2, 2},
        {6, 5, 2, 1, 0},
        {0, 2, 2, 3, 7}
        }, 10, 5, 14), 0.21076904123090398);
}

TEST_F(KappaCalculatorTestFleissKappa, test_fleiss_kappa_4) {
    EXPECT_DOUBLE_EQ(KappaCalculator::fleiss_kappa({
        {0, 0, 1, 0, 14},
        {0, 2, 6, 4, 2},
        {0, 0, 3, 5, 6},
        {0, 3, 9, 2, 0},
        {2, 2, 8, 1, 1},
        {7, 7, 0, 0, 0},
        {3, 2, 6, 3, 0},
        {2, 5, 3, 2, 2},
        {6, 5, 2, 1, 0},
        {0, 2, 2, 3, 7}
        }, 10, 5, 14), 0.2096583016522883);
}

TEST_F(KappaCalculatorTestFleissKappa, test_fleiss_kappa_5) {
    EXPECT_DOUBLE_EQ(KappaCalculator::fleiss_kappa({
        {0, 0, 0, 1, 14},
        {0, 2, 6, 4, 2},
        {0, 0, 3, 5, 6},
        {0, 3, 9, 2, 0},
        {2, 2, 8, 1, 1},
        {7, 7, 0, 0, 0},
        {3, 2, 6, 3, 0},
        {2, 5, 3, 2, 2},
        {6, 5, 2, 1, 0},
        {0, 2, 2, 3, 7}
        }, 10, 5, 14), 0.21147425143148907);
}

class KappaCalculatorTest : public ::testing::Test {
protected:
    void SetUp() override {
        
    }

    void TearDown() override {
        
    }
};

TEST_F(KappaCalculatorTest, test_kappacalculator) {
    EXPECT_DOUBLE_EQ(KappaCalculator::kappa({
        {2, 1, 1},
        {1, 2, 1},
        {1, 1, 2}
        }, 3), 0.25);

    EXPECT_DOUBLE_EQ(KappaCalculator::fleiss_kappa({
        {0, 0, 0, 0, 14},
        {0, 2, 6, 4, 2},
        {0, 0, 3, 5, 6},
        {0, 3, 9, 2, 0},
        {2, 2, 8, 1, 1},
        {7, 7, 0, 0, 0},
        {3, 2, 6, 3, 0},
        {2, 5, 3, 2, 2},
        {6, 5, 2, 1, 0},
        {0, 2, 2, 3, 7}
        }, 10, 5, 14), 0.20993070442195522);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}