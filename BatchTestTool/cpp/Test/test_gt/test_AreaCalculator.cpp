#include <gtest/gtest.h>
#include "pch.h"
#include <cmath>


class AreaCalculatorTestCalculateCircleArea : public ::testing::Test {
protected:
    AreaCalculatorTestCalculateCircleArea() : calculator(0) {}

    AreaCalculator create_calculator(double radius) {
        return AreaCalculator(radius);
    }

    void SetUp() override {
        
        calculator = AreaCalculator(5.0);
    }

    AreaCalculator calculator;
};


TEST_F(AreaCalculatorTestCalculateCircleArea, TestCalculateCircleArea) {
    AreaCalculator ac = create_calculator(2.0);
    EXPECT_NEAR(ac.calculate_circle_area(), 12.56, 0.01);
}

TEST_F(AreaCalculatorTestCalculateCircleArea, TestCalculateCircleArea2) {
    AreaCalculator ac = create_calculator(2.5);
    EXPECT_NEAR(ac.calculate_circle_area(), 19.63, 0.01);
}

TEST_F(AreaCalculatorTestCalculateCircleArea, TestCalculateCircleArea3) {
    AreaCalculator ac = create_calculator(2000.0);
    EXPECT_NEAR(ac.calculate_circle_area(), 12566370.61, 0.01);
}

TEST_F(AreaCalculatorTestCalculateCircleArea, TestCalculateCircleArea4) {
    AreaCalculator ac = create_calculator(0.0);
    EXPECT_NEAR(ac.calculate_circle_area(), 0.0, 0.01);
}

TEST_F(AreaCalculatorTestCalculateCircleArea, TestCalculateCircleArea5) {
    AreaCalculator ac = create_calculator(0.1);
    EXPECT_NEAR(ac.calculate_circle_area(), 0.031, 0.01);
}

class AreaCalculatorTestCalculateSphereArea : public ::testing::Test {
protected:
    AreaCalculatorTestCalculateSphereArea() : calculator(0) {}

    AreaCalculator create_calculator(double radius) {
        return AreaCalculator(radius);
    }

    void SetUp() override {
        
        calculator = AreaCalculator(5.0);
    }

    AreaCalculator calculator;
};


TEST_F(AreaCalculatorTestCalculateSphereArea, TestCalculateSphereArea) {
    AreaCalculator ac = create_calculator(2.0);
    EXPECT_NEAR(ac.calculate_sphere_area(), 50.27, 0.01);
}

TEST_F(AreaCalculatorTestCalculateSphereArea, TestCalculateSphereArea2) {
    AreaCalculator ac = create_calculator(2.5);
    EXPECT_NEAR(ac.calculate_sphere_area(), 78.54, 0.01);
}

TEST_F(AreaCalculatorTestCalculateSphereArea, TestCalculateSphereArea3) {
    AreaCalculator ac = create_calculator(2000.0);
    EXPECT_NEAR(ac.calculate_sphere_area(), 50265482.46, 0.01);
}

TEST_F(AreaCalculatorTestCalculateSphereArea, TestCalculateSphereArea4) {
    AreaCalculator ac = create_calculator(0.0);
    EXPECT_NEAR(ac.calculate_sphere_area(), 0.0, 0.01);
}

TEST_F(AreaCalculatorTestCalculateSphereArea, TestCalculateSphereArea5) {
    AreaCalculator ac = create_calculator(0.1);
    EXPECT_NEAR(ac.calculate_sphere_area(), 0.126, 0.01);
}

class AreaCalculatorTestCalculateCylinderArea : public ::testing::Test {
protected:
    AreaCalculatorTestCalculateCylinderArea() : calculator(0) {}

    AreaCalculator create_calculator(double radius) {
        return AreaCalculator(radius);
    }

    void SetUp() override {
        
        calculator = AreaCalculator(5.0);
    }

    AreaCalculator calculator;
};


TEST_F(AreaCalculatorTestCalculateCylinderArea, TestCalculateCylinderArea) {
    AreaCalculator ac = create_calculator(2.0);
    EXPECT_NEAR(ac.calculate_cylinder_area(2.0), 50.27, 0.01);
}

TEST_F(AreaCalculatorTestCalculateCylinderArea, TestCalculateCylinderArea2) {
    AreaCalculator ac = create_calculator(2.0);
    EXPECT_NEAR(ac.calculate_cylinder_area(0.0), 25.13, 0.01);
}

TEST_F(AreaCalculatorTestCalculateCylinderArea, TestCalculateCylinderArea3) {
    AreaCalculator ac = create_calculator(0.0);
    EXPECT_NEAR(ac.calculate_cylinder_area(2000.0), 0.0, 0.01);
}

TEST_F(AreaCalculatorTestCalculateCylinderArea, TestCalculateCylinderArea4) {
    AreaCalculator ac = create_calculator(2.5);
    EXPECT_NEAR(ac.calculate_cylinder_area(2.0), 70.68, 0.01);
}

TEST_F(AreaCalculatorTestCalculateCylinderArea, TestCalculateCylinderArea5) {
    AreaCalculator ac = create_calculator(2.5);
    EXPECT_NEAR(ac.calculate_cylinder_area(1.5), 62.83, 0.01);
}

class AreaCalculatorTestCalculateSectorArea : public ::testing::Test {
protected:
    AreaCalculatorTestCalculateSectorArea() : calculator(0) {}

    AreaCalculator create_calculator(double radius) {
        return AreaCalculator(radius);
    }

    void SetUp() override {
        
        calculator = AreaCalculator(5.0);
    }

    AreaCalculator calculator;
};


TEST_F(AreaCalculatorTestCalculateSectorArea, TestCalculateSectorArea) {
    AreaCalculator ac = create_calculator(1.5);
    EXPECT_NEAR(ac.calculate_sector_area(M_PI), 3.53, 0.01);
}

TEST_F(AreaCalculatorTestCalculateSectorArea, TestCalculateSectorArea2) {
    AreaCalculator ac = create_calculator(2.0);
    EXPECT_NEAR(ac.calculate_sector_area(M_PI / 2), 3.14, 0.01);
}

TEST_F(AreaCalculatorTestCalculateSectorArea, TestCalculateSectorArea3) {
    AreaCalculator ac = create_calculator(2.0);
    EXPECT_NEAR(ac.calculate_sector_area(0.0), 0.0, 0.01);
}

TEST_F(AreaCalculatorTestCalculateSectorArea, TestCalculateSectorArea4) {
    AreaCalculator ac = create_calculator(2.0);
    EXPECT_NEAR(ac.calculate_sector_area(2 * M_PI), 12.56, 0.01);
}

TEST_F(AreaCalculatorTestCalculateSectorArea, TestCalculateSectorArea5) {
    AreaCalculator ac = create_calculator(0.0);
    EXPECT_NEAR(ac.calculate_sector_area(M_PI), 0.0, 0.01);
}

class AreaCalculatorTestCalculateAnnulusArea : public ::testing::Test {
protected:
    AreaCalculatorTestCalculateAnnulusArea() : calculator(0) {}

    AreaCalculator create_calculator(double radius) {
        return AreaCalculator(radius);
    }

    void SetUp() override {
        
        calculator = AreaCalculator(5.0);
    }

    AreaCalculator calculator;
};


TEST_F(AreaCalculatorTestCalculateAnnulusArea, TestCalculateAnnulusArea) {
    AreaCalculator ac = create_calculator(2.0);
    EXPECT_NEAR(ac.calculate_annulus_area(1.0, 3.0), 25.13, 0.01);
}

TEST_F(AreaCalculatorTestCalculateAnnulusArea, TestCalculateAnnulusArea2) {
    AreaCalculator ac = create_calculator(2.5);
    EXPECT_NEAR(ac.calculate_annulus_area(3.0, 3.0), 0.0, 0.01);
}

TEST_F(AreaCalculatorTestCalculateAnnulusArea, TestCalculateAnnulusArea3) {
    AreaCalculator ac = create_calculator(2000.0);
    EXPECT_NEAR(ac.calculate_annulus_area(0.0, 1.0), 3.14, 0.01);
}

TEST_F(AreaCalculatorTestCalculateAnnulusArea, TestCalculateAnnulusArea4) {
    AreaCalculator ac = create_calculator(0.0);
    EXPECT_NEAR(ac.calculate_annulus_area(1.0, 3.0), 25.13, 0.01);
}

TEST_F(AreaCalculatorTestCalculateAnnulusArea, TestCalculateAnnulusArea5) {
    AreaCalculator ac = create_calculator(2.5);
    EXPECT_NEAR(ac.calculate_annulus_area(1.0, 3.0), 25.13, 0.01);
}

class AreaCalculatorTestMain : public ::testing::Test {
protected:
    AreaCalculatorTestMain() : calculator(0) {}

    AreaCalculator create_calculator(double radius) {
        return AreaCalculator(radius);
    }

    void SetUp() override {
        
        calculator = AreaCalculator(5.0);
    }

    AreaCalculator calculator;
};


TEST_F(AreaCalculatorTestMain, TestMain) {
    AreaCalculator ac = create_calculator(2.0);
    EXPECT_NEAR(ac.calculate_circle_area(), 12.56, 0.01);
    EXPECT_NEAR(ac.calculate_sphere_area(), 50.27, 0.01);
    EXPECT_NEAR(ac.calculate_cylinder_area(2.0), 50.27, 0.01);
    EXPECT_NEAR(ac.calculate_sector_area(M_PI), 6.28, 0.01);
    EXPECT_NEAR(ac.calculate_annulus_area(1.0, 3.0), 25.13, 0.01);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}