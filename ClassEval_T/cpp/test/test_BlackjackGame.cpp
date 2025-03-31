#include <gtest/gtest.h>
#include "pch.h"

class BlackjackGameTestCreateDeck : public ::testing::Test {
protected:
    BlackjackGame blackjackGame;
    std::vector<std::string> deck;

    void SetUp() override {
        deck = blackjackGame.create_deck();
    }
};

TEST_F(BlackjackGameTestCreateDeck, TestCreateDeck1) {
    EXPECT_EQ(deck.size(), 52);
}

TEST_F(BlackjackGameTestCreateDeck, TestCreateDeck2) {
    std::vector<std::string> suits = { "S", "C", "D", "H" };
    std::vector<std::string> ranks = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            EXPECT_NE(std::find(deck.begin(), deck.end(), rank + suit), deck.end());
        }
    }
}

TEST_F(BlackjackGameTestCreateDeck, TestCreateDeck3) {
    std::vector<std::string> suits = { "S", "C", "D", "H" };
    std::vector<std::string> ranks = { "A", "2", "3", "4", "5", "6", "7", "8", "9" };
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            EXPECT_NE(std::find(deck.begin(), deck.end(), rank + suit), deck.end());
        }
    }
}

TEST_F(BlackjackGameTestCreateDeck, TestCreateDeck4) {
    std::vector<std::string> suits = { "S", "C", "D", "H" };
    std::vector<std::string> ranks = { "10", "J", "Q", "K" };
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            EXPECT_NE(std::find(deck.begin(), deck.end(), rank + suit), deck.end());
        }
    }
}

TEST_F(BlackjackGameTestCreateDeck, TestCreateDeck5) {
    std::vector<std::string> suits = { "S", "C", "D", "H" };
    std::vector<std::string> ranks = { "A", "2", "3", "4", "5", "6", "7", "8", "9" };
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            EXPECT_NE(std::find(deck.begin(), deck.end(), rank + suit), deck.end());
        }
    }
}

class BlackjackGameTestCalculateHandValue : public ::testing::Test {
protected:
    BlackjackGame blackjackGame;
};

TEST_F(BlackjackGameTestCalculateHandValue, TestCalculateHandValue1) {
    std::vector<std::string> hand = { "2S", "3S", "4S", "5S" };
    EXPECT_EQ(blackjackGame.calculate_hand_value(hand), 14);
}

TEST_F(BlackjackGameTestCalculateHandValue, TestCalculateHandValue2) {
    std::vector<std::string> hand = { "2S", "3S", "JS", "QS" };
    EXPECT_EQ(blackjackGame.calculate_hand_value(hand), 25);
}

TEST_F(BlackjackGameTestCalculateHandValue, TestCalculateHandValue3) {
    std::vector<std::string> hand = { "2S", "3S", "4S", "AS" };
    EXPECT_EQ(blackjackGame.calculate_hand_value(hand), 20);
}

TEST_F(BlackjackGameTestCalculateHandValue, TestCalculateHandValue4) {
    std::vector<std::string> hand = { "JS", "QS", "4S", "AS" };
    EXPECT_EQ(blackjackGame.calculate_hand_value(hand), 25);
}

TEST_F(BlackjackGameTestCalculateHandValue, TestCalculateHandValue5) {
    std::vector<std::string> hand = { "JS", "QS", "AS", "AS", "AS" };
    EXPECT_EQ(blackjackGame.calculate_hand_value(hand), 23);
}

TEST_F(BlackjackGameTestCalculateHandValue, TestCalculateHandValue6) {
    std::vector<std::string> hand = { "JS", "QS", "BS", "CS" };
    EXPECT_EQ(blackjackGame.calculate_hand_value(hand), 20);
}


class BlackjackGameTestCheckWinner : public ::testing::Test {
protected:
    BlackjackGame blackjackGame;
};

TEST_F(BlackjackGameTestCheckWinner, TestCheckWinner1) {
    std::vector<std::string> player_hand = { "2S", "JS", "QS" };
    std::vector<std::string> dealer_hand = { "7S", "9S" };
    EXPECT_EQ(blackjackGame.check_winner(player_hand, dealer_hand), "Dealer wins");
}

TEST_F(BlackjackGameTestCheckWinner, TestCheckWinner2) {
    std::vector<std::string> player_hand = { "2S", "4S", "5S" };
    std::vector<std::string> dealer_hand = { "2S", "JS", "QS" };
    EXPECT_EQ(blackjackGame.check_winner(player_hand, dealer_hand), "Player wins");
}

TEST_F(BlackjackGameTestCheckWinner, TestCheckWinner3) {
    std::vector<std::string> player_hand = { "3S", "JS", "QS" };
    std::vector<std::string> dealer_hand = { "2S", "JS", "QS" };
    EXPECT_EQ(blackjackGame.check_winner(player_hand, dealer_hand), "Dealer wins");
}

TEST_F(BlackjackGameTestCheckWinner, TestCheckWinner4) {
    std::vector<std::string> player_hand = { "2S", "JS", "QS" };
    std::vector<std::string> dealer_hand = { "3S", "JS", "QS" };
    EXPECT_EQ(blackjackGame.check_winner(player_hand, dealer_hand), "Player wins");
}

TEST_F(BlackjackGameTestCheckWinner, TestCheckWinner5) {
    std::vector<std::string> player_hand = { "2S", "3S", "5S" };
    std::vector<std::string> dealer_hand = { "AS", "JS" };
    EXPECT_EQ(blackjackGame.check_winner(player_hand, dealer_hand), "Dealer wins");
}

TEST_F(BlackjackGameTestCheckWinner, TestCheckWinner6) {
    std::vector<std::string> player_hand = { "AS", "JS" };
    std::vector<std::string> dealer_hand = { "2S", "3S", "5S" };
    EXPECT_EQ(blackjackGame.check_winner(player_hand, dealer_hand), "Player wins");
}

class BlackjackGameTestMain : public ::testing::Test {
protected:
    BlackjackGame blackjackGame;
};

TEST_F(BlackjackGameTestMain, TestMain1) {
    std::vector<std::string> deck = blackjackGame.create_deck();
    std::vector<std::string> suits = { "S", "C", "D", "H" };
    std::vector<std::string> ranks = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            EXPECT_NE(std::find(deck.begin(), deck.end(), rank + suit), deck.end());
        }
    }
    std::vector<std::string> player_hand = { "2S", "JS", "QS" };
    std::vector<std::string> dealer_hand = { "7S", "9S" };
    EXPECT_EQ(blackjackGame.check_winner(player_hand, dealer_hand), "Dealer wins");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}