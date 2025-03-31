#include <gtest/gtest.h>
#include "pch.h"  

class TicTacToeTestMakeMove : public ::testing::Test {};

TEST_F(TicTacToeTestMakeMove, test_make_move_1) {
    TicTacToe ttt;
    EXPECT_EQ(ttt.get_current_player(), 'X');
    EXPECT_TRUE(ttt.make_move(0, 0));
    EXPECT_EQ(ttt.get_current_player(), 'O');
}


TEST_F(TicTacToeTestMakeMove, test_make_move_2) {
    TicTacToe ttt;
    EXPECT_EQ(ttt.get_current_player(), 'X');
    EXPECT_TRUE(ttt.make_move(0, 0));
    EXPECT_TRUE(ttt.make_move(0, 1));
    EXPECT_FALSE(ttt.make_move(0, 0));
    EXPECT_EQ(ttt.get_current_player(), 'X');
}

TEST_F(TicTacToeTestMakeMove, test_make_move_3) {
    TicTacToe ttt;
    EXPECT_EQ(ttt.get_current_player(), 'X');
    EXPECT_TRUE(ttt.make_move(0, 0));
    EXPECT_TRUE(ttt.make_move(0, 1));
    EXPECT_TRUE(ttt.make_move(1, 1));
    EXPECT_EQ(ttt.get_current_player(), 'O');
}

TEST_F(TicTacToeTestMakeMove, test_make_move_4) {
    TicTacToe ttt;
    EXPECT_EQ(ttt.get_current_player(), 'X');
    EXPECT_TRUE(ttt.make_move(0, 0));
    EXPECT_TRUE(ttt.make_move(0, 1));
    EXPECT_TRUE(ttt.make_move(1, 1));
    EXPECT_TRUE(ttt.make_move(1, 2));
    EXPECT_EQ(ttt.get_current_player(), 'X');
}

TEST_F(TicTacToeTestMakeMove, test_make_move_5) {
    TicTacToe ttt;
    EXPECT_EQ(ttt.get_current_player(), 'X');
    EXPECT_TRUE(ttt.make_move(0, 0));
    EXPECT_TRUE(ttt.make_move(0, 1));
    EXPECT_TRUE(ttt.make_move(1, 1));
    EXPECT_TRUE(ttt.make_move(1, 2));
    EXPECT_TRUE(ttt.make_move(2, 2));
    EXPECT_EQ(ttt.get_current_player(), 'O');
}

class TicTacToeTestCheckWinner : public ::testing::Test {};


TEST_F(TicTacToeTestCheckWinner, test_check_winner_1) {
    TicTacToe ttt;
    std::vector<std::pair<int, int>> moves = { {1, 0}, {2, 0}, {1, 1}, {2, 1}, {1, 2} };
    for (const auto& move : moves) {
        ttt.make_move(move.first, move.second);
    }
    EXPECT_EQ(ttt.check_winner(), 'X');
}


TEST_F(TicTacToeTestCheckWinner, test_check_winner_2) {
    TicTacToe ttt;
    std::vector<std::pair<int, int>> moves = { {0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 0} };
    for (const auto& move : moves) {
        ttt.make_move(move.first, move.second);
    }
    EXPECT_EQ(ttt.check_winner(), 'X');
}


TEST_F(TicTacToeTestCheckWinner, test_check_winner_3) {
    TicTacToe ttt;
    std::vector<std::pair<int, int>> moves = { {0, 0}, {0, 1}, {1, 1}, {0, 2}, {2, 2} };
    for (const auto& move : moves) {
        ttt.make_move(move.first, move.second);
    }
    EXPECT_EQ(ttt.check_winner(), 'X');
}


TEST_F(TicTacToeTestCheckWinner, test_check_winner_4) {
    TicTacToe ttt;
    std::vector<std::pair<int, int>> moves = { {0, 2}, {0, 1}, {1, 1}, {1, 0}, {2, 0} };
    for (const auto& move : moves) {
        ttt.make_move(move.first, move.second);
    }
    EXPECT_EQ(ttt.check_winner(), 'X');
}

TEST_F(TicTacToeTestCheckWinner, test_check_winner_5) {
    TicTacToe ttt;
    std::vector<std::pair<int, int>> moves = { {0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 0} };
    for (const auto& move : moves) {
        ttt.make_move(move.first, move.second);
    }
    EXPECT_EQ(ttt.check_winner(), '\0');
}

class TicTacToeTestIsBoardFull : public ::testing::Test {};


TEST_F(TicTacToeTestIsBoardFull, test_is_board_full_1) {
    TicTacToe ttt;
    EXPECT_FALSE(ttt.is_board_full());
}


TEST_F(TicTacToeTestIsBoardFull, test_is_board_full_2) {
    TicTacToe ttt;
    std::vector<std::pair<int, int>> moves = { {1, 1}, {0, 2}, {2, 2}, {0, 0}, {0, 1}, {2, 1}, {1, 0}, {1, 2}, {2, 0} };
    for (const auto& move : moves) {
        ttt.make_move(move.first, move.second);
    }
    EXPECT_TRUE(ttt.is_board_full());
}

TEST_F(TicTacToeTestIsBoardFull, test_is_board_full_3) {
    TicTacToe ttt;
    std::vector<std::pair<int, int>> moves = { {0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 0} };
    for (const auto& move : moves) {
        ttt.make_move(move.first, move.second);
    }
    EXPECT_FALSE(ttt.is_board_full());
}

TEST_F(TicTacToeTestIsBoardFull, test_is_board_full_4) {
    TicTacToe ttt;
    std::vector<std::pair<int, int>> moves = { {0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 0}, {0, 2}, {1, 2}, {2, 1}, {2, 2} };
    for (const auto& move : moves) {
        ttt.make_move(move.first, move.second);
    }
    EXPECT_TRUE(ttt.is_board_full());
}

TEST_F(TicTacToeTestIsBoardFull, test_is_board_full_5) {
    TicTacToe ttt;
    std::vector<std::pair<int, int>> moves = { {0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 0}, {0, 2}, {1, 2}, {2, 1} };
    for (const auto& move : moves) {
        ttt.make_move(move.first, move.second);
    }
    EXPECT_FALSE(ttt.is_board_full());
}

class TicTacToeTestMain : public ::testing::Test {};

TEST_F(TicTacToeTestMain, test_main) {
    
    TicTacToe ttt;
    std::vector<std::pair<int, int>> moves = { {1, 1}, {0, 2}, {2, 2}, {0, 0}, {0, 1}, {2, 1}, {1, 0}, {1, 2}, {2, 0} };
    for (const auto& move : moves) {
        EXPECT_TRUE(ttt.make_move(move.first, move.second));
        
        EXPECT_FALSE(ttt.check_winner());
        if (move != std::make_pair(2, 0)) {
            EXPECT_FALSE(ttt.is_board_full());
        }
    }
    EXPECT_TRUE(ttt.is_board_full());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}