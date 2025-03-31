#include <gtest/gtest.h>
#include "pch.h"  

class TwentyFourPointGameTestGetMyCards : public ::testing::Test {
protected:
    TwentyFourPointGame game;
};

TEST_F(TwentyFourPointGameTestGetMyCards, TestGetMyCards1) {
    auto cards = game.get_my_cards();
    EXPECT_EQ(cards.size(), 4);
    for (const auto& card : cards) {
        EXPECT_TRUE(card >= 1 && card <= 9);
    }
}

TEST_F(TwentyFourPointGameTestGetMyCards, TestGetMyCards2) {
    auto cards = game.get_my_cards();
    EXPECT_EQ(cards.size(), 4);
    for (const auto& card : cards) {
        EXPECT_TRUE(card >= 1 && card <= 9);
    }
}

TEST_F(TwentyFourPointGameTestGetMyCards, TestGetMyCards3) {
    auto cards = game.get_my_cards();
    EXPECT_EQ(cards.size(), 4);
    for (const auto& card : cards) {
        EXPECT_TRUE(card >= 1 && card <= 9);
    }
}

TEST_F(TwentyFourPointGameTestGetMyCards, TestGetMyCards4) {
    auto cards = game.get_my_cards();
    EXPECT_EQ(cards.size(), 4);
    for (const auto& card : cards) {
        EXPECT_TRUE(card >= 1 && card <= 9);
    }
}

TEST_F(TwentyFourPointGameTestGetMyCards, TestGetMyCards5) {
    auto cards = game.get_my_cards();
    EXPECT_EQ(cards.size(), 4);
    for (const auto& card : cards) {
        EXPECT_TRUE(card >= 1 && card <= 9);
    }
}

class TwentyFourPointGameTestAnswer : public ::testing::Test {
protected:
    TwentyFourPointGame game;
};

TEST_F(TwentyFourPointGameTestAnswer, TestAnswer1) {
    auto cards = game.answer("pass");
    EXPECT_EQ(cards.size(), 4);
}

TEST_F(TwentyFourPointGameTestAnswer, TestAnswer2) {
    auto result = game.answer("4*3+6+6");
    EXPECT_FALSE(result.empty());
}

TEST_F(TwentyFourPointGameTestAnswer, TestAnswer3) {
    auto result = game.answer("1+1+1+1");
    EXPECT_TRUE(result.empty());
}

TEST_F(TwentyFourPointGameTestAnswer, TestAnswer4) {
    auto result = game.answer("1+");
    EXPECT_TRUE(result.empty());
}

TEST_F(TwentyFourPointGameTestAnswer, TestAnswer5) {
    auto result = game.answer("abc");
    EXPECT_TRUE(result.empty());
}

TEST_F(TwentyFourPointGameTestAnswer, TestAnswer6) {
    game.set_nums({ 1, 1, 1, 1 });
    auto result = game.answer("1+1+1+2");
    EXPECT_TRUE(result.empty());
}

TEST_F(TwentyFourPointGameTestAnswer, TestAnswer7) {
    game.set_nums({ 1, 1, 1, 1 });
   auto result = game.answer("1+1+1+1+1");
    EXPECT_TRUE(result.empty());
}

class TwentyFourPointGameTestEvaluateExpression : public ::testing::Test {
protected:
    TwentyFourPointGame game;
};

TEST_F(TwentyFourPointGameTestEvaluateExpression, TestEvaluateExpression1) {
    bool result = game.evaluate_expression("4+3+6+6");
    EXPECT_FALSE(result);
}

TEST_F(TwentyFourPointGameTestEvaluateExpression, TestEvaluateExpression2) {
    bool result = game.evaluate_expression("4*3+6+6");
    EXPECT_TRUE(result);
}

TEST_F(TwentyFourPointGameTestEvaluateExpression, TestEvaluateExpression3) {
    bool result = game.evaluate_expression("1+1+1+1");
    EXPECT_FALSE(result);
}

TEST_F(TwentyFourPointGameTestEvaluateExpression, TestEvaluateExpression4) {
    bool result = game.evaluate_expression("1+");
    EXPECT_FALSE(result);
}

TEST_F(TwentyFourPointGameTestEvaluateExpression, TestEvaluateExpression5) {
    bool result = game.evaluate_expression("abc");
    EXPECT_FALSE(result);
}

class TwentyFourPointGameTest : public ::testing::Test {
protected:
    TwentyFourPointGame game;
};

TEST_F(TwentyFourPointGameTest, TestTwentyFourPointGame) {
    auto cards = game.get_my_cards();
    EXPECT_EQ(cards.size(), 4);
    for (const auto& card : cards) {
        EXPECT_TRUE(card >= 1 && card <= 9);
    }
    game.set_nums({ 4, 3, 6, 6 });
    auto result = game.answer("4*3+6+6");
    EXPECT_FALSE(result.empty());
    auto result2 = game.evaluate_expression("4*3+6+6");
    EXPECT_TRUE(result2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}