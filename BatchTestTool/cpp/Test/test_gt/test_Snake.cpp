#include <gtest/gtest.h>
#include "pch.h"

class SnakeTestMove : public ::testing::Test {};

TEST_F(SnakeTestMove, test_move_1) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    snake.move(std::make_pair(1, 1));
    EXPECT_EQ(snake.get_length(), 2);
    EXPECT_EQ(snake.positions[0], std::make_pair(51, 51));
    EXPECT_EQ(snake.positions[1], std::make_pair(50, 50));
    EXPECT_EQ(snake.get_score(), 100);
}

TEST_F(SnakeTestMove, test_move_2) {
    Snake snake(100, 100, 1, std::make_pair(80, 80));
    snake.move(std::make_pair(1, 1));
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.positions[0], std::make_pair(51, 51));
    EXPECT_EQ(snake.get_score(), 0);
}

TEST_F(SnakeTestMove, test_move_3) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    snake.move(std::make_pair(1, 0));
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.positions[0], std::make_pair(51, 50));
    EXPECT_EQ(snake.get_score(), 0);
}

TEST_F(SnakeTestMove, test_move_4) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    snake.move(std::make_pair(0, 0));
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.positions[0], std::make_pair(50, 50));
    EXPECT_EQ(snake.get_score(), 0);
}

TEST_F(SnakeTestMove, test_move_5) {
    Snake snake(100, 100, 1, std::make_pair(99, 99));
    snake.move(std::make_pair(1, 0));
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.positions[0], std::make_pair(51, 50));
    EXPECT_EQ(snake.get_score(), 0);
}

class SnakeTestRandomFoodPosition : public ::testing::Test {};

TEST_F(SnakeTestRandomFoodPosition, test_random_food_position_1) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    EXPECT_EQ(snake.food_position, std::make_pair(51, 51));
    snake.random_food_position();
    EXPECT_EQ(std::find(snake.positions.begin(), snake.positions.end(), snake.food_position), snake.positions.end());
    EXPECT_GE(snake.food_position.first, 0);
    EXPECT_GE(snake.food_position.second, 0);
    EXPECT_LE(snake.food_position.first, 100);
    EXPECT_LE(snake.food_position.second, 100);
}

TEST_F(SnakeTestRandomFoodPosition, test_random_food_position_2) {
    Snake snake(100, 100, 1, std::make_pair(99, 99));
    EXPECT_EQ(snake.food_position, std::make_pair(99, 99));
    snake.random_food_position();
    EXPECT_EQ(std::find(snake.positions.begin(), snake.positions.end(), snake.food_position), snake.positions.end());
    EXPECT_GE(snake.food_position.first, 0);
    EXPECT_GE(snake.food_position.second, 0);
    EXPECT_LE(snake.food_position.first, 100);
    EXPECT_LE(snake.food_position.second, 100);
}

TEST_F(SnakeTestRandomFoodPosition, test_random_food_position_3) {
    Snake snake(100, 100, 1, std::make_pair(0, 0));
    EXPECT_EQ(snake.food_position, std::make_pair(0, 0));
    snake.random_food_position();
    EXPECT_EQ(std::find(snake.positions.begin(), snake.positions.end(), snake.food_position), snake.positions.end());
    EXPECT_GE(snake.food_position.first, 0);
    EXPECT_GE(snake.food_position.second, 0);
    EXPECT_LE(snake.food_position.first, 100);
    EXPECT_LE(snake.food_position.second, 100);
}

TEST_F(SnakeTestRandomFoodPosition, test_random_food_position_4) {
    Snake snake(100, 100, 1, std::make_pair(40, 40));
    EXPECT_EQ(snake.food_position, std::make_pair(40, 40));
    snake.random_food_position();
    EXPECT_EQ(std::find(snake.positions.begin(), snake.positions.end(), snake.food_position), snake.positions.end());
    EXPECT_GE(snake.food_position.first, 0);
    EXPECT_GE(snake.food_position.second, 0);
    EXPECT_LE(snake.food_position.first, 100);
    EXPECT_LE(snake.food_position.second, 100);
}

TEST_F(SnakeTestRandomFoodPosition, test_random_food_position_5) {
    Snake snake(100, 100, 1, std::make_pair(60, 60));
    EXPECT_EQ(snake.food_position, std::make_pair(60, 60));
    snake.random_food_position();
    EXPECT_EQ(std::find(snake.positions.begin(), snake.positions.end(), snake.food_position), snake.positions.end());
    EXPECT_GE(snake.food_position.first, 0);
    EXPECT_GE(snake.food_position.second, 0);
    EXPECT_LE(snake.food_position.first, 100);
    EXPECT_LE(snake.food_position.second, 100);
}

class SnakeTestReset : public ::testing::Test {};

TEST_F(SnakeTestReset, test_reset_1) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    snake.move(std::make_pair(1, 1));
    snake.reset();
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.positions[0], std::make_pair(50, 50));
    EXPECT_EQ(snake.get_score(), 0);
}

TEST_F(SnakeTestReset, test_reset_2) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    snake.move(std::make_pair(0, 1));
    snake.reset();
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.positions[0], std::make_pair(50, 50));
    EXPECT_EQ(snake.get_score(), 0);
}

TEST_F(SnakeTestReset, test_reset_3) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    snake.move(std::make_pair(0, -1));
    snake.reset();
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.positions[0], std::make_pair(50, 50));
    EXPECT_EQ(snake.get_score(), 0);
}

TEST_F(SnakeTestReset, test_reset_4) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    snake.move(std::make_pair(-1, 0));
    snake.reset();
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.positions[0], std::make_pair(50, 50));
    EXPECT_EQ(snake.get_score(), 0);
}

TEST_F(SnakeTestReset, test_reset_5) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    snake.move(std::make_pair(1, 0));
    snake.reset();
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.positions[0], std::make_pair(50, 50));
    EXPECT_EQ(snake.get_score(), 0);
}

class SnakeTestEatFood : public ::testing::Test {};

TEST_F(SnakeTestEatFood, test_eat_food_1) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.get_score(), 0);
    snake.eat_food();
    EXPECT_EQ(snake.get_length(), 2);
    EXPECT_EQ(snake.get_score(), 100);
}

TEST_F(SnakeTestEatFood, test_eat_food_2) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.get_score(), 0);
    snake.eat_food();
    snake.eat_food();
    EXPECT_EQ(snake.get_length(), 3);
    EXPECT_EQ(snake.get_score(), 200);
}

TEST_F(SnakeTestEatFood, test_eat_food_3) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.get_score(), 0);
    snake.eat_food();
    snake.eat_food();
    snake.eat_food();
    EXPECT_EQ(snake.get_length(), 4);
    EXPECT_EQ(snake.get_score(), 300);
}

TEST_F(SnakeTestEatFood, test_eat_food_4) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.get_score(), 0);
    snake.eat_food();
    snake.eat_food();
    snake.eat_food();
    snake.eat_food();
    EXPECT_EQ(snake.get_length(), 5);
    EXPECT_EQ(snake.get_score(), 400);
}

TEST_F(SnakeTestEatFood, test_eat_food_5) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.get_score(), 0);
    snake.eat_food();
    snake.eat_food();
    snake.eat_food();
    snake.eat_food();
    snake.eat_food();
    EXPECT_EQ(snake.get_length(), 6);
    EXPECT_EQ(snake.get_score(), 500);
}

class SnakeTest : public ::testing::Test {};

TEST_F(SnakeTest, test_snake) {
    Snake snake(100, 100, 1, std::make_pair(51, 51));
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.get_SCREEN_WIDTH(), 100);
    EXPECT_EQ(snake.get_SCREEN_HEIGHT(), 100);
    EXPECT_EQ(snake.get_BLOCK_SIZE(), 1);
    EXPECT_EQ(snake.positions[0], std::make_pair(50, 50));
    EXPECT_EQ(snake.get_score(), 0);
    EXPECT_EQ(snake.food_position, std::make_pair(51, 51));
    snake.move(std::make_pair(1, 1));
    EXPECT_EQ(snake.get_length(), 2);
    EXPECT_EQ(snake.positions[0], std::make_pair(51, 51));
    EXPECT_EQ(snake.get_score(), 100);
    snake.random_food_position();
    EXPECT_EQ(std::find(snake.positions.begin(), snake.positions.end(), snake.food_position), snake.positions.end());
    snake.reset();
    EXPECT_EQ(snake.get_length(), 1);
    EXPECT_EQ(snake.positions[0], std::make_pair(50, 50));
    EXPECT_EQ(snake.get_score(), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}