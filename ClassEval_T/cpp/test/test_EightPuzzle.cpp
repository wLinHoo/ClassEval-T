#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "pch.h"
#include <optional>
class EightPuzzleTestFindBlank : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(EightPuzzleTestFindBlank, test_find_blank_1) {
    std::vector<std::vector<int>> state = { {2, 3, 4}, {5, 8, 1}, {6, 0, 7} };
    EightPuzzle eightPuzzle(state);
    EXPECT_EQ(eightPuzzle.find_blank(state), std::make_pair(2, 1));
}

TEST_F(EightPuzzleTestFindBlank, test_find_blank_2) {
    std::vector<std::vector<int>> state = { {2, 3, 4}, {5, 0, 1}, {6, 8, 7} };
    EightPuzzle eightPuzzle(state);
    EXPECT_EQ(eightPuzzle.find_blank(state), std::make_pair(1, 1));
}

TEST_F(EightPuzzleTestFindBlank, test_find_blank_3) {
    std::vector<std::vector<int>> state = { {2, 3, 4}, {5, 8, 1}, {6, 8, 7} };
    EightPuzzle eightPuzzle(state);
    std::pair<int, int> kkk{ -1,-1 };
    EXPECT_EQ(eightPuzzle.find_blank(state), kkk);
}

TEST_F(EightPuzzleTestFindBlank, test_find_blank_4) {
    std::vector<std::vector<int>> state = { {2, 3, 4}, {5, 8, 1}, {6, 8, 7} };
    EightPuzzle eightPuzzle(state);
    std::pair<int, int> kkk{ -1,-1 };
    EXPECT_EQ(eightPuzzle.find_blank(state), kkk);
}

TEST_F(EightPuzzleTestFindBlank, test_find_blank_5) {
    std::vector<std::vector<int>> state = { {2, 3, 4}, {5, 8, 1}, {6, 8, 7} };
    EightPuzzle eightPuzzle(state);
    std::pair<int, int> kkk{ -1,-1 };
    EXPECT_EQ(eightPuzzle.find_blank(state), kkk);
}

class EightPuzzleTestMove : public ::testing::Test {
protected:
    std::vector<std::vector<int>> initial_state;
    EightPuzzle eightPuzzle;

    void SetUp() override {
        initial_state = { {2, 3, 4}, {5, 0, 1}, {6, 8, 7} };
        eightPuzzle = (initial_state);
    }
};

TEST_F(EightPuzzleTestMove, test_move_1) {
    auto result = eightPuzzle.move(initial_state, "up");
    std::vector<std::vector<int>> expected = { {2, 0, 4}, {5, 3, 1}, {6, 8, 7} };
    EXPECT_EQ(result, expected);
}

TEST_F(EightPuzzleTestMove, test_move_2) {
    auto result = eightPuzzle.move(initial_state, "down");
    std::vector<std::vector<int>> expected = { {2, 3, 4}, {5, 8, 1}, {6, 0, 7} };
    EXPECT_EQ(result, expected);
}

TEST_F(EightPuzzleTestMove, test_move_3) {
    auto result = eightPuzzle.move(initial_state, "left");
    std::vector<std::vector<int>> expected = { {2, 3, 4}, {0, 5, 1}, {6, 8, 7} };
    EXPECT_EQ(result, expected);
}

TEST_F(EightPuzzleTestMove, test_move_4) {
    auto result = eightPuzzle.move(initial_state, "right");
    std::vector<std::vector<int>> expected = { {2, 3, 4}, {5, 1, 0}, {6, 8, 7} };
    EXPECT_EQ(result, expected);
}

TEST_F(EightPuzzleTestMove, test_move_5) {
    auto result = eightPuzzle.move(initial_state, "???");
    std::vector<std::vector<int>> expected = { {2, 3, 4}, {5, 0, 1}, {6, 8, 7} };
    EXPECT_EQ(result, expected);
}

class EightPuzzleTestGetPossibleMoves : public ::testing::Test {
protected:
    void SetUp() override {}
};

TEST_F(EightPuzzleTestGetPossibleMoves, test_get_possible_moves_1) {
    EightPuzzle eightPuzzle;
    std::vector<std::vector<int>> state = { {2, 3, 4}, {5, 0, 1}, {6, 8, 7} };
    auto result = eightPuzzle.get_possible_moves(state);
    std::vector<std::string> expected = { "up", "down", "left", "right" };
    for (const auto& direction : result) {
        EXPECT_NE(std::find(expected.begin(), expected.end(), direction), expected.end());
    }
}

TEST_F(EightPuzzleTestGetPossibleMoves, test_get_possible_moves_2) {
    EightPuzzle eightPuzzle;
    std::vector<std::vector<int>> state = { {2, 3, 4}, {5, 8, 1}, {6, 0, 7} };
    auto result = eightPuzzle.get_possible_moves(state);
    std::vector<std::string> expected = { "up", "left", "right" };
    for (const auto& direction : result) {
        EXPECT_NE(std::find(expected.begin(), expected.end(), direction), expected.end());
    }
}

TEST_F(EightPuzzleTestGetPossibleMoves, test_get_possible_moves_3) {
    EightPuzzle eightPuzzle;
    std::vector<std::vector<int>> state = { {2, 0, 4}, {5, 3, 1}, {6, 8, 7} };
    auto result = eightPuzzle.get_possible_moves(state);
    std::vector<std::string> expected = { "down", "left", "right" };
    for (const auto& direction : result) {
        EXPECT_NE(std::find(expected.begin(), expected.end(), direction), expected.end());
    }
}

TEST_F(EightPuzzleTestGetPossibleMoves, test_get_possible_moves_4) {
    EightPuzzle eightPuzzle;
    std::vector<std::vector<int>> state = { {2, 3, 4}, {5, 1, 0}, {6, 8, 7} };
    auto result = eightPuzzle.get_possible_moves(state);
    std::vector<std::string> expected = { "up", "down", "left" };
    for (const auto& direction : result) {
        EXPECT_NE(std::find(expected.begin(), expected.end(), direction), expected.end());
    }
}

TEST_F(EightPuzzleTestGetPossibleMoves, test_get_possible_moves_5) {
    EightPuzzle eightPuzzle;
    std::vector<std::vector<int>> state = { {2, 3, 4}, {0, 5, 1}, {6, 8, 7} };
    auto result = eightPuzzle.get_possible_moves(state);
    std::vector<std::string> expected = { "up", "down", "right" };
    for (const auto& direction : result) {
        EXPECT_NE(std::find(expected.begin(), expected.end(), direction), expected.end());
    }
}

class EightPuzzleTestSolve : public ::testing::Test {};

TEST_F(EightPuzzleTestSolve, test_solve_1) {
    EightPuzzle eightPuzzle({ {1, 2, 3}, {4, 5, 6}, {7, 0, 8} });
    auto result = eightPuzzle.solve();
    std::vector<std::string> expected = { "right" };
    EXPECT_EQ(result, expected);
}

TEST_F(EightPuzzleTestSolve, test_solve_2) {
    EightPuzzle eightPuzzle({ {1, 2, 3}, {4, 0, 6}, {7, 5, 8} });
    auto result = eightPuzzle.solve();
    std::vector<std::string> expected = { "down", "right" };
    EXPECT_EQ(result, expected);
}

TEST_F(EightPuzzleTestSolve, test_solve_3) {
    EightPuzzle eightPuzzle({ {1, 2, 3}, {0, 4, 5}, {6, 7, 8} });
    auto result = eightPuzzle.solve();
    std::vector<std::string> expected = { "right", "right", "down", "left", "left", "up", "right", "down", "right", "up", "left", "left", "down", "right", "right" };
    EXPECT_EQ(result, expected);
}

TEST_F(EightPuzzleTestSolve, test_solve_4) {
    EightPuzzle eightPuzzle({ {1, 2, 3}, {4, 5, 6}, {7, 8, 0} });
    auto result = eightPuzzle.solve();
    std::vector<std::string> expected = {};
    EXPECT_EQ(result, expected);
}

TEST_F(EightPuzzleTestSolve, test_solve_5) {
    EightPuzzle eightPuzzle({ {1, 2, 3}, {4, 5, 6}, {0, 7, 8} });
    auto result = eightPuzzle.solve();
    std::vector<std::string> expected = { "right", "right" };
    EXPECT_EQ(result, expected);
}

TEST_F(EightPuzzleTestSolve, test_solve_6) {
    EightPuzzle eightPuzzle({ {0, 0, 0}, {0, 0, 0}, {0, 0, 0} });
    auto result = eightPuzzle.solve();
    EXPECT_EQ(result, std::vector<std::string>()); 
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}