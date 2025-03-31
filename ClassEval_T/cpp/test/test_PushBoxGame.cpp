#include <gtest/gtest.h>
#include "pch.h"

class PushBoxGameTestInitGame : public ::testing::Test {
protected:
    void SetUp() override {
        game_map = {
            "#####",
            "#O  #",
            "# X #",
            "#  G#",
            "#####"
        };
        game = PushBoxGame(game_map);
    }

    std::vector<std::string> game_map;
    PushBoxGame game;
};

TEST_F(PushBoxGameTestInitGame, test_init_game_1) {
    ASSERT_EQ(game.gat_map(), game_map);
}

TEST_F(PushBoxGameTestInitGame, test_init_game_2) {
    ASSERT_FALSE(game.is_game_over());
}

TEST_F(PushBoxGameTestInitGame, test_init_game_3) {
    ASSERT_EQ(game.get_player_col(), 1);
}

TEST_F(PushBoxGameTestInitGame, test_init_game_4) {
    ASSERT_EQ(game.get_player_row(), 1);
}

TEST_F(PushBoxGameTestInitGame, test_init_game_5) {
    std::vector<std::pair<int, int>> now{ {3, 3} };
    ASSERT_EQ(game.get_targets(), now);
}

TEST_F(PushBoxGameTestInitGame, test_init_game_6) {
    std::vector<std::pair<int, int>> now{ {2, 2} };
    ASSERT_EQ(game.get_boxes(), now);
}

TEST_F(PushBoxGameTestInitGame, test_init_game_7) {
    ASSERT_EQ(game.get_target_count(), 1);
}

class PushBoxGameTestCheckWin : public ::testing::Test {
protected:
    void SetUp() override {
        game_map = {
            "#####",
            "#O  #",
            "# X #",
            "#  G#",
            "#####"
        };
        game = PushBoxGame(game_map);
    }

    std::vector<std::string> game_map;
    PushBoxGame game;
};

TEST_F(PushBoxGameTestCheckWin, test_check_win_1) {
    ASSERT_FALSE(game.check_win());
}

TEST_F(PushBoxGameTestCheckWin, test_check_win_2) {
    std::vector<char> moves = { 'd', 's', 'a', 's', 'd' };
    for (char move : moves) {
        game.move(move);
    }
    ASSERT_TRUE(game.check_win());
}

class PushBoxGameTestMove : public ::testing::Test {
protected:
    void SetUp() override {
        game_map = {
            "#####",
            "#O  #",
            "# X #",
            "#  G#",
            "#####"
        };
        game = PushBoxGame(game_map);
    }

    std::vector<std::string> game_map;
    PushBoxGame game;
};

TEST_F(PushBoxGameTestMove, test_move_1) {
    std::vector<char> moves = { 'd', 's', 'a', 's' };
    for (char move : moves) {
        ASSERT_FALSE(game.move(move));
    }
    ASSERT_TRUE(game.move('d'));
}

TEST_F(PushBoxGameTestMove, test_move_2) {
    game.move('a');
    ASSERT_EQ(game.get_player_col(), 1);
    ASSERT_EQ(game.get_player_row(), 1);
    ASSERT_FALSE(game.is_game_over());
}

TEST_F(PushBoxGameTestMove, test_move_3) {
    game.move('d');
    ASSERT_EQ(game.get_player_col(), 2);
    ASSERT_EQ(game.get_player_row(), 1);
    ASSERT_FALSE(game.is_game_over());
}

TEST_F(PushBoxGameTestMove, test_move_4) {
    game.move('s');
    ASSERT_EQ(game.get_player_col(), 1);
    ASSERT_EQ(game.get_player_row(), 2);
    ASSERT_FALSE(game.is_game_over());
}

TEST_F(PushBoxGameTestMove, test_move_5) {
    game.move('w');
    ASSERT_EQ(game.get_player_col(), 1);
    ASSERT_EQ(game.get_player_row(), 1);
    ASSERT_FALSE(game.is_game_over());
}

TEST_F(PushBoxGameTestMove, test_move_6) {
    game.move('?');
    ASSERT_FALSE(game.is_game_over());
}

TEST_F(PushBoxGameTestMove, test_move_7) {
    game_map = {
        "#####",
        "# X #",
        "# O #",
        "#  G#",
        "#####"
    };
    game = PushBoxGame(game_map);
    game.move('w');
    ASSERT_EQ(game.get_player_col(), 2);
    ASSERT_EQ(game.get_player_row(), 2);
    ASSERT_FALSE(game.is_game_over());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}