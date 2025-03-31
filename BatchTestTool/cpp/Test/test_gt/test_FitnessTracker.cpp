#include <gtest/gtest.h>
#include "pch.h" 


class FitnessTrackerTestGetBMI : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(FitnessTrackerTestGetBMI, test_get_BMI) {
    FitnessTracker fitnessTracker(1.8, 70, 20, "male");
    EXPECT_NEAR(fitnessTracker.get_BMI(), 21.604938271604937, 1e-9);
}

TEST_F(FitnessTrackerTestGetBMI, test_get_BMI_2) {
    FitnessTracker fitnessTracker(1.8, 50, 20, "male");
    EXPECT_NEAR(fitnessTracker.get_BMI(), 15.432098765432098, 1e-9);
}

TEST_F(FitnessTrackerTestGetBMI, test_get_BMI_3) {
    FitnessTracker fitnessTracker(1.72, 53, 20, "male");
    EXPECT_NEAR(fitnessTracker.get_BMI(), 17.915089237425637, 1e-9);
}

TEST_F(FitnessTrackerTestGetBMI, test_get_BMI_4) {
    FitnessTracker fitnessTracker(1.72, 60, 20, "male");
    EXPECT_NEAR(fitnessTracker.get_BMI(), 20.281233098972418, 1e-9);
}

TEST_F(FitnessTrackerTestGetBMI, test_get_BMI_5) {
    FitnessTracker fitnessTracker(1.72, 65, 20, "male");
    EXPECT_NEAR(fitnessTracker.get_BMI(), 21.971335857220122, 1e-9);
}


class FitnessTrackerTestConditionJudge : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(FitnessTrackerTestConditionJudge, test_condition_judge) {
    FitnessTracker fitnessTracker(1.8, 45, 20, "female");
    EXPECT_EQ(fitnessTracker.condition_judge(), -1);
}

TEST_F(FitnessTrackerTestConditionJudge, test_condition_judge_2) {
    FitnessTracker fitnessTracker(1.72, 80, 22, "female");
    EXPECT_EQ(fitnessTracker.condition_judge(), 1);
}

TEST_F(FitnessTrackerTestConditionJudge, test_condition_judge_3) {
    FitnessTracker fitnessTracker(1.72, 53, 22, "male");
    EXPECT_EQ(fitnessTracker.condition_judge(), -1);
}

TEST_F(FitnessTrackerTestConditionJudge, test_condition_judge_4) {
    FitnessTracker fitnessTracker(1.72, 60, 22, "male");
    EXPECT_EQ(fitnessTracker.condition_judge(), 0);
}

TEST_F(FitnessTrackerTestConditionJudge, test_condition_judge_5) {
    FitnessTracker fitnessTracker(1.72, 75, 22, "male");
    EXPECT_EQ(fitnessTracker.condition_judge(), 1);
}


class FitnessTrackerTestCalculateCalorieIntake : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(FitnessTrackerTestCalculateCalorieIntake, test_calculate_calorie_intake) {
    FitnessTracker fitnessTracker(1.8, 70, 20, "female");
    EXPECT_NEAR(fitnessTracker.calculate_calorie_intake(), 630.3499999999999, 1e-9);
}

TEST_F(FitnessTrackerTestCalculateCalorieIntake, test_calculate_calorie_intake_2) {
    FitnessTracker fitnessTracker(1.72, 80, 22, "female");
    EXPECT_NEAR(fitnessTracker.calculate_calorie_intake(), 647.6999999999999, 1e-9);
}

TEST_F(FitnessTrackerTestCalculateCalorieIntake, test_calculate_calorie_intake_3) {
    FitnessTracker fitnessTracker(1.72, 53, 22, "male");
    EXPECT_NEAR(fitnessTracker.calculate_calorie_intake(), 697.2, 1e-9);
}

TEST_F(FitnessTrackerTestCalculateCalorieIntake, test_calculate_calorie_intake_4) {
    FitnessTracker fitnessTracker(1.72, 60, 22, "male");
    EXPECT_NEAR(fitnessTracker.calculate_calorie_intake(), 708.05, 1e-9);
}

TEST_F(FitnessTrackerTestCalculateCalorieIntake, test_calculate_calorie_intake_5) {
    FitnessTracker fitnessTracker(1.72, 75, 22, "male");
    EXPECT_NEAR(fitnessTracker.calculate_calorie_intake(), 786.9, 1e-9);
}


class FitnessTrackerTestMain : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(FitnessTrackerTestMain, test_main) {
    FitnessTracker fitnessTracker(1.8, 70, 20, "male");
    EXPECT_NEAR(fitnessTracker.get_BMI(), 21.604938271604937, 1e-9);
    EXPECT_EQ(fitnessTracker.condition_judge(), 0);
    EXPECT_NEAR(fitnessTracker.calculate_calorie_intake(), 862.75, 1e-9);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}