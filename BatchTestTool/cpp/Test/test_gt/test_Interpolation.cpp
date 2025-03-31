#include <gtest/gtest.h>
#include "pch.h"  


class InterpolationTestInterpolate1d : public ::testing::Test {
protected:
    Interpolation interpolation;
};

TEST_F(InterpolationTestInterpolate1d, test_interpolate_1d) {
    std::vector<double> x = { 1, 2, 3 };
    std::vector<double> y = { 1, 2, 3 };
    std::vector<double> points = { 1.5, 2.5 };
    std::vector<double> expected = { 1.5, 2.5 };
    EXPECT_EQ(interpolation.interpolate_1d(x, y, points), expected);
}

TEST_F(InterpolationTestInterpolate1d, test_interpolate_1d_2) {
    std::vector<double> x = { 1, 6, 4 };
    std::vector<double> y = { 1, 2, 5 };
    std::vector<double> points = { 1.5, 2.5 };
    std::vector<double> expected = { 1.1, 1.3 };
    EXPECT_EQ(interpolation.interpolate_1d(x, y, points), expected);
}

TEST_F(InterpolationTestInterpolate1d, test_interpolate_1d_3) {
    std::vector<double> x = { 1, 6, 4 };
    std::vector<double> y = { 1, 7, 5 };
    std::vector<double> points = { 1.5, 2.5 };
    std::vector<double> expected = { 1.6, 2.8 };
    EXPECT_EQ(interpolation.interpolate_1d(x, y, points), expected);
}

TEST_F(InterpolationTestInterpolate1d, test_interpolate_1d_4) {
    std::vector<double> x = { 1, 6, 4 };
    std::vector<double> y = { 1, 2, 5 };
    std::vector<double> points = { 2, 3 };
    std::vector<double> expected = { 1.2, 1.4 };
    EXPECT_EQ(interpolation.interpolate_1d(x, y, points), expected);
}

TEST_F(InterpolationTestInterpolate1d, test_interpolate_1d_5) {
    std::vector<double> x = { 1, 6, 4 };
    std::vector<double> y = { 1, 7, 5 };
    std::vector<double> points = { 2, 3 };
    std::vector<double> expected = { 2.2, 3.4 };
    EXPECT_EQ(interpolation.interpolate_1d(x, y, points), expected);
}

TEST_F(InterpolationTestInterpolate1d, test_interpolate_1d_6) {
    std::vector<double> x = { 1, 6, 4 };
    std::vector<double> y = { 1, 7, 5 };
    std::vector<double> points = {};
    std::vector<double> expected = {};
    EXPECT_EQ(interpolation.interpolate_1d(x, y, points), expected);
}

TEST_F(InterpolationTestInterpolate1d, test_interpolate_1d_7) {
    std::vector<double> x = {};
    std::vector<double> y = {};
    std::vector<double> points = {};
    std::vector<double> expected = {};
    EXPECT_EQ(interpolation.interpolate_1d(x, y, points), expected);
}


class InterpolationTestInterpolate2d : public ::testing::Test {
protected:
    Interpolation interpolation;
};

TEST_F(InterpolationTestInterpolate2d, test_interpolate_2d) {
    std::vector<double> x = { 1, 2, 3 };
    std::vector<double> y = { 1, 2, 3 };
    std::vector<std::vector<double>> z = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::vector<double> x_points = { 1.5, 2.5 };
    std::vector<double> y_points = { 1.5, 2.5 };
    std::vector<double> expected = { 3.0, 7.0 };
    EXPECT_EQ(interpolation.interpolate_2d(x, y, z, x_points, y_points), expected);
}

TEST_F(InterpolationTestInterpolate2d, test_interpolate_2d_2) {
    std::vector<double> x = { 1, 2, 3 };
    std::vector<double> y = { 1, 2, 3 };
    std::vector<std::vector<double>> z = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::vector<double> x_points = { 1.5, 2.5 };
    std::vector<double> y_points = { 3, 4 };
    std::vector<double> expected = { 4.5 };
    EXPECT_EQ(interpolation.interpolate_2d(x, y, z, x_points, y_points), expected);
}

TEST_F(InterpolationTestInterpolate2d, test_interpolate_2d_3) {
    std::vector<double> x = { 1, 2, 3 };
    std::vector<double> y = { 1, 2, 3 };
    std::vector<std::vector<double>> z = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::vector<double> x_points = { 3, 4 };
    std::vector<double> y_points = { 1.5, 2.5 };
    std::vector<double> expected = { 7.5 };
    EXPECT_EQ(interpolation.interpolate_2d(x, y, z, x_points, y_points), expected);
}

TEST_F(InterpolationTestInterpolate2d, test_interpolate_2d_4) {
    std::vector<double> x = { 1, 2, 3 };
    std::vector<double> y = { 1, 2, 3 };
    std::vector<std::vector<double>> z = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::vector<double> x_points = { 3, 4 };
    std::vector<double> y_points = { 3, 4 };
    std::vector<double> expected = { 9.0 };
    EXPECT_EQ(interpolation.interpolate_2d(x, y, z, x_points, y_points), expected);
}

TEST_F(InterpolationTestInterpolate2d, test_interpolate_2d_5) {
    std::vector<double> x = { 1, 2, 3 };
    std::vector<double> y = { 1, 2, 3 };
    std::vector<std::vector<double>> z = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::vector<double> x_points = { 1.5, 2.5 };
    std::vector<double> y_points = { 1.5, 2.5 };
    std::vector<double> expected = { 3.0, 7.0 };
    EXPECT_EQ(interpolation.interpolate_2d(x, y, z, x_points, y_points), expected);
}


class InterpolationTestMain : public ::testing::Test {
protected:
    Interpolation interpolation;
};

TEST_F(InterpolationTestMain, test_main) {
    std::vector<double> x = { 1, 2, 3 };
    std::vector<double> y = { 1, 2, 3 };
    std::vector<double> points = { 1.5, 2.5 };
    std::vector<double> expected = { 1.5, 2.5 };
    EXPECT_EQ(interpolation.interpolate_1d(x, y, points), expected);

    std::vector<double> x_2d = { 1, 2, 3 };
    std::vector<double> y_2d = { 1, 2, 3 };
    std::vector<std::vector<double>> z_2d = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    std::vector<double> x_points_2d = { 1.5, 2.5 };
    std::vector<double> y_points_2d = { 1.5, 2.5 };
    std::vector<double> expected_2d = { 3.0, 7.0 };
    EXPECT_EQ(interpolation.interpolate_2d(x_2d, y_2d, z_2d, x_points_2d, y_points_2d), expected_2d);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}