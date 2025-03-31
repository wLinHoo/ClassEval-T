#include "pch.h"
#include <gtest/gtest.h>
#include <algorithm>

class MahjongConnectTestCreateBoard : public ::testing::Test {
protected:
    MahjongConnect* mc;

    void SetUp() override {
    }

    void TearDown() override {
        delete mc;
    }
};

TEST_F(MahjongConnectTestCreateBoard, TestCreateBoard1) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    EXPECT_EQ(mc->BOARD_SIZE, std::make_pair(4, 4));
    EXPECT_EQ(mc->ICONS, std::vector<char>({ 'a', 'b', 'c' }));
    for (const auto& row : mc->board) {
        for (char icon : row) {
            EXPECT_NE(std::find(mc->ICONS.begin(), mc->ICONS.end(), icon), mc->ICONS.end());
        }
    }
}

TEST_F(MahjongConnectTestCreateBoard, TestCreateBoard2) {
    mc = new MahjongConnect({ 2, 2 }, { 'a', 'b', 'c' });
    EXPECT_EQ(mc->BOARD_SIZE, std::make_pair(2, 2));
    EXPECT_EQ(mc->ICONS, std::vector<char>({ 'a', 'b', 'c' }));
    for (const auto& row : mc->board) {
        for (char icon : row) {
            EXPECT_NE(std::find(mc->ICONS.begin(), mc->ICONS.end(), icon), mc->ICONS.end());
        }
    }
}

TEST_F(MahjongConnectTestCreateBoard, TestCreateBoard3) {
    mc = new MahjongConnect({ 3, 3 }, { 'a', 'b', 'c' });
    EXPECT_EQ(mc->BOARD_SIZE, std::make_pair(3, 3));
    EXPECT_EQ(mc->ICONS, std::vector<char>({ 'a', 'b', 'c' }));
    for (const auto& row : mc->board) {
        for (char icon : row) {
            EXPECT_NE(std::find(mc->ICONS.begin(), mc->ICONS.end(), icon), mc->ICONS.end());
        }
    }
}

TEST_F(MahjongConnectTestCreateBoard, TestCreateBoard4) {
    mc = new MahjongConnect({ 1, 1 }, { 'a', 'b', 'c' });
    EXPECT_EQ(mc->BOARD_SIZE, std::make_pair(1, 1));
    EXPECT_EQ(mc->ICONS, std::vector<char>({ 'a', 'b', 'c' }));
    for (const auto& row : mc->board) {
        for (char icon : row) {
            EXPECT_NE(std::find(mc->ICONS.begin(), mc->ICONS.end(), icon), mc->ICONS.end());
        }
    }
}

TEST_F(MahjongConnectTestCreateBoard, TestCreateBoard5) {
    mc = new MahjongConnect({ 5, 5 }, { 'a', 'b', 'c' });
    EXPECT_EQ(mc->BOARD_SIZE, std::make_pair(5, 5));
    EXPECT_EQ(mc->ICONS, std::vector<char>({ 'a', 'b', 'c' }));
    for (const auto& row : mc->board) {
        for (char icon : row) {
            EXPECT_NE(std::find(mc->ICONS.begin(), mc->ICONS.end(), icon), mc->ICONS.end());
        }
    }
}

class MahjongConnectTestIsValidMove : public ::testing::Test {
protected:
    MahjongConnect* mc;

    void SetUp() override {
    }

    void TearDown() override {
        delete mc;
    }
};

TEST_F(MahjongConnectTestIsValidMove, TestIsValidMove1) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    bool res = mc->is_valid_move({ 0, 0 }, { 1, 0 });
    EXPECT_TRUE(res);
}

TEST_F(MahjongConnectTestIsValidMove, TestIsValidMove2) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    bool res = mc->is_valid_move({ 0, 0 }, { 0, 1 });
    EXPECT_FALSE(res);
}

TEST_F(MahjongConnectTestIsValidMove, TestIsValidMove3) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    bool res = mc->is_valid_move({ -1, 0 }, { 0, 1 });
    EXPECT_FALSE(res);
}

TEST_F(MahjongConnectTestIsValidMove, TestIsValidMove4) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    bool res = mc->is_valid_move({ 0, 0 }, { 0, 0 });
    EXPECT_FALSE(res);
}

TEST_F(MahjongConnectTestIsValidMove, TestIsValidMove5) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    bool res = mc->is_valid_move({ 300, 0 }, { 0, 0 });
    EXPECT_FALSE(res);
}

TEST_F(MahjongConnectTestIsValidMove, TestIsValidMove6) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'a', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    bool res = mc->is_valid_move({ 0, 2 }, { 0, 0 });
    EXPECT_FALSE(res);
}

class MahjongConnectTestHasPath : public ::testing::Test {
protected:
    MahjongConnect* mc;

    void SetUp() override {
    }

    void TearDown() override {
        delete mc;
    }
};

TEST_F(MahjongConnectTestHasPath, TestHasPath1) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    bool res = mc->has_path({ 0, 0 }, { 1, 0 });
    EXPECT_TRUE(res);
}

TEST_F(MahjongConnectTestHasPath, TestHasPath2) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    bool res = mc->has_path({ 0, 0 }, { 0, 0 });
    EXPECT_TRUE(res);
}

TEST_F(MahjongConnectTestHasPath, TestHasPath3) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    bool res = mc->has_path({ 0, 0 }, { 3, 0 });
    EXPECT_TRUE(res);
}

TEST_F(MahjongConnectTestHasPath, TestHasPath4) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    bool res = mc->has_path({ 0, 0 }, { 1, 1 });
    EXPECT_FALSE(res);
}

TEST_F(MahjongConnectTestHasPath, TestHasPath5) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    bool res = mc->has_path({ 300, 0 }, { 1, 1 });
    EXPECT_FALSE(res);
}

TEST_F(MahjongConnectTestHasPath, TestHasPath6) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a'}
    };
    bool res = mc->has_path({ 0, 0 }, { 3, 3 });
    EXPECT_TRUE(res);
}

class MahjongConnectTestRemoveIcons : public ::testing::Test {
protected:
    MahjongConnect* mc;

    void SetUp() override {
    }

    void TearDown() override {
        delete mc;
    }
};

TEST_F(MahjongConnectTestRemoveIcons, TestRemoveIcons1) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    mc->remove_icons({ 0, 0 }, { 1, 0 });
    std::vector<std::vector<char>> expected_board = {
        {' ', 'b', 'c', 'a'},
        {' ', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    EXPECT_EQ(mc->board, expected_board);
}

TEST_F(MahjongConnectTestRemoveIcons, TestRemoveIcons2) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    mc->remove_icons({ 2, 0 }, { 1, 0 });
    std::vector<std::vector<char>> expected_board = {
        {'a', 'b', 'c', 'a'},
        {' ', 'b', 'c', 'a'},
        {' ', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    EXPECT_EQ(mc->board, expected_board);
}

TEST_F(MahjongConnectTestRemoveIcons, TestRemoveIcons3) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    mc->remove_icons({ 1, 1 }, { 0, 1 });
    std::vector<std::vector<char>> expected_board = {
        {'a', ' ', 'c', 'a'},
        {'a', ' ', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    EXPECT_EQ(mc->board, expected_board);
}

TEST_F(MahjongConnectTestRemoveIcons, TestRemoveIcons4) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    mc->remove_icons({ 3, 0 }, { 2, 0 });
    std::vector<std::vector<char>> expected_board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {' ', 'b', 'c', 'a'},
        {' ', 'b', 'c', 'a'}
    };
    EXPECT_EQ(mc->board, expected_board);
}

TEST_F(MahjongConnectTestRemoveIcons, TestRemoveIcons5) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    mc->remove_icons({ 3, 3 }, { 2, 3 });
    std::vector<std::vector<char>> expected_board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', ' '},
        {'a', 'b', 'c', ' '}
    };
    EXPECT_EQ(mc->board, expected_board);
}

class MahjongConnectTestIsGameOver : public ::testing::Test {
protected:
    MahjongConnect* mc;

    void SetUp() override {
    }

    void TearDown() override {
        delete mc;
    }
};

TEST_F(MahjongConnectTestIsGameOver, TestIsGameOver1) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    };
    bool res = mc->is_game_over();
    EXPECT_EQ(res, true);
}

TEST_F(MahjongConnectTestIsGameOver, TestIsGameOver2) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', ' ', ' ', ' '},
        {'a', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    };
    bool res = mc->is_game_over();
    EXPECT_EQ(res, false);
}

TEST_F(MahjongConnectTestIsGameOver, TestIsGameOver3) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {' ', ' ', ' ', ' '},
        {'a', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    };
    bool res = mc->is_game_over();
    EXPECT_EQ(res, false);
}

TEST_F(MahjongConnectTestIsGameOver, TestIsGameOver4) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'1', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    };
    bool res = mc->is_game_over();
    EXPECT_EQ(res, false);
}

TEST_F(MahjongConnectTestIsGameOver, TestIsGameOver5) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    mc->board = {
        {'a', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    };
    bool res = mc->is_game_over();
    EXPECT_EQ(res, false);
}

class MahjongConnectTest : public ::testing::Test {
protected:
    MahjongConnect* mc;

    void SetUp() override {
    }

    void TearDown() override {
        delete mc;
    }
};

TEST_F(MahjongConnectTest, TestMahjongConnect) {
    mc = new MahjongConnect({ 4, 4 }, { 'a', 'b', 'c' });
    EXPECT_EQ(mc->BOARD_SIZE, std::make_pair(4, 4));
    EXPECT_EQ(mc->ICONS, std::vector<char>({ 'a', 'b', 'c' }));

    for (const auto& row : mc->board) {
        for (const auto& icon : row) {
            EXPECT_TRUE(std::find(mc->ICONS.begin(), mc->ICONS.end(), icon) != mc->ICONS.end());
        }
    }

    mc->board = {
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
    };
    bool res = mc->is_valid_move({ 0, 0 }, { 1, 0 });
    EXPECT_EQ(res, true);

    res = mc->has_path({ 0, 0 }, { 1, 0 });
    EXPECT_EQ(res, true);

    mc->remove_icons({ 0, 0 }, { 1, 0 });
    EXPECT_EQ(mc->board, std::vector<std::vector<char>>({
        {' ', 'b', 'c', 'a'},
        {' ', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'},
        {'a', 'b', 'c', 'a'}
        }));

    mc->board = {
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' '}
    };
    res = mc->is_game_over();
    EXPECT_EQ(res, true);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}