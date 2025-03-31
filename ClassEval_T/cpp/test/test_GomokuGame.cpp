#include <gtest/gtest.h>
#include "pch.h"  

class GomokuGameTestMakeMove : public ::testing::Test {
protected:
    int board_size;
    GomokuGame* gomokuGame;

    void SetUp() override {
        board_size = 10;
        gomokuGame = new GomokuGame(board_size);
    }

    void TearDown() override {
        delete gomokuGame;
    }
};

TEST_F(GomokuGameTestMakeMove, test_make_move_1) {
    std::vector<std::vector<char>> board(board_size, std::vector<char>(board_size, ' '));
    EXPECT_TRUE(gomokuGame->make_move(0, 0));
    board[0][0] = 'X';
    EXPECT_EQ(board, gomokuGame->getBoard());
}

TEST_F(GomokuGameTestMakeMove, test_make_move_2) {
    std::vector<std::vector<char>> board(board_size, std::vector<char>(board_size, ' '));
    EXPECT_TRUE(gomokuGame->make_move(0, 0));
    EXPECT_FALSE(gomokuGame->make_move(0, 0));
    board[0][0] = 'X';
    EXPECT_EQ(board, gomokuGame->getBoard());
}

TEST_F(GomokuGameTestMakeMove, test_make_move_3) {
    std::vector<std::vector<char>> board(board_size, std::vector<char>(board_size, ' '));
    EXPECT_TRUE(gomokuGame->make_move(0, 0));
    EXPECT_TRUE(gomokuGame->make_move(0, 1));
    board[0][0] = 'X';
    board[0][1] = 'O';
    EXPECT_EQ(board, gomokuGame->getBoard());
}

TEST_F(GomokuGameTestMakeMove, test_make_move_4) {
    std::vector<std::vector<char>> board(board_size, std::vector<char>(board_size, ' '));
    EXPECT_TRUE(gomokuGame->make_move(0, 0));
    EXPECT_TRUE(gomokuGame->make_move(0, 1));
    EXPECT_FALSE(gomokuGame->make_move(0, 0));
    board[0][0] = 'X';
    board[0][1] = 'O';
    EXPECT_EQ(board, gomokuGame->getBoard());
}

TEST_F(GomokuGameTestMakeMove, test_make_move_5) {
    std::vector<std::vector<char>> board(board_size, std::vector<char>(board_size, ' '));
    EXPECT_TRUE(gomokuGame->make_move(0, 0));
    EXPECT_TRUE(gomokuGame->make_move(0, 1));
    EXPECT_FALSE(gomokuGame->make_move(0, 1));
    board[0][0] = 'X';
    board[0][1] = 'O';
    EXPECT_EQ(board, gomokuGame->getBoard());
}

class GomokuGameTestCheckWinner : public ::testing::Test {};

TEST_F(GomokuGameTestCheckWinner, test_check_winner_1) {
    GomokuGame gomokuGame(10);
    EXPECT_EQ(std::nullopt, gomokuGame.check_winner());
}

TEST_F(GomokuGameTestCheckWinner, test_check_winner_2) {
    GomokuGame gomokuGame(10);
    std::vector<std::pair<int, int>> moves = { {5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1} };
    for (const auto& move : moves) {
        gomokuGame.make_move(move.first, move.second);
    }
    EXPECT_EQ('X', gomokuGame.check_winner());
}

TEST_F(GomokuGameTestCheckWinner, test_check_winner_3) {
    GomokuGame gomokuGame(10);
    std::vector<std::pair<int, int>> moves = { {5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 0}, {0, 4} };
    for (const auto& move : moves) {
        gomokuGame.make_move(move.first, move.second);
    }
    EXPECT_EQ('O', gomokuGame.check_winner());
}

TEST_F(GomokuGameTestCheckWinner, test_check_winner_4) {
    GomokuGame gomokuGame(10);
    std::vector<std::pair<int, int>> moves = { {5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1}, {0, 4} };
    for (const auto& move : moves) {
        gomokuGame.make_move(move.first, move.second);
    }
    EXPECT_EQ('O', gomokuGame.check_winner());
}

TEST_F(GomokuGameTestCheckWinner, test_check_winner_5) {
    GomokuGame gomokuGame(10);
    std::vector<std::pair<int, int>> moves = { {5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1}, {0, 4}, {5, 0} };
    for (const auto& move : moves) {
        gomokuGame.make_move(move.first, move.second);
    }
    EXPECT_EQ('O', gomokuGame.check_winner());
}

class GomokuGameTestCheckFiveInARow : public ::testing::Test {
protected:
    GomokuGame* gomokuGame;

    void SetUp() override {
        gomokuGame = new GomokuGame(10);
        std::vector<std::pair<int, int>> moves = { {5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1} };
        for (const auto& move : moves) {
            gomokuGame->make_move(move.first, move.second);
        }
    }

    void TearDown() override {
        delete gomokuGame;
    }
};

TEST_F(GomokuGameTestCheckFiveInARow, test_check_five_in_a_row_1) {
    EXPECT_TRUE(gomokuGame->_check_five_in_a_row(5, 5, std::make_pair(0, -1)));
}

TEST_F(GomokuGameTestCheckFiveInARow, test_check_five_in_a_row_2) {
    EXPECT_TRUE(gomokuGame->_check_five_in_a_row(5, 1, std::make_pair(0, 1)));
}

TEST_F(GomokuGameTestCheckFiveInARow, test_check_five_in_a_row_3) {
    EXPECT_FALSE(gomokuGame->_check_five_in_a_row(0, 0, std::make_pair(0, 1)));
}

TEST_F(GomokuGameTestCheckFiveInARow, test_check_five_in_a_row_4) {
    EXPECT_FALSE(gomokuGame->_check_five_in_a_row(0, 0, std::make_pair(1, 0)));
}

TEST_F(GomokuGameTestCheckFiveInARow, test_check_five_in_a_row_5) {
    EXPECT_FALSE(gomokuGame->_check_five_in_a_row(5, 5, std::make_pair(1, 0)));
}

class GomokuGameTestMain : public ::testing::Test {};

TEST_F(GomokuGameTestMain, test_main) {
    GomokuGame gomokuGame(10);
    std::vector<std::pair<int, int>> moves = { {5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1} };
    EXPECT_EQ(std::nullopt, gomokuGame.check_winner());
    for (const auto& move : moves) {
        EXPECT_TRUE(gomokuGame.make_move(move.first, move.second));
    }
    EXPECT_FALSE(gomokuGame.make_move(0, 0));
    EXPECT_TRUE(gomokuGame._check_five_in_a_row(5, 5, std::make_pair(0, -1)));
    EXPECT_EQ('X', gomokuGame.check_winner());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}