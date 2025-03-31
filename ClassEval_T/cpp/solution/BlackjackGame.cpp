
#include <algorithm>
#include <random>
#include <ctime>

#include <vector>
#include <string>

class BlackjackGame {
public:
    BlackjackGame();
    std::vector<std::string> create_deck();
    int calculate_hand_value(const std::vector<std::string>& hand);
    std::string check_winner(const std::vector<std::string>& player_hand, const std::vector<std::string>& dealer_hand);

private:
    std::vector<std::string> deck;
    std::vector<std::string> player_hand;
    std::vector<std::string> dealer_hand;
};

BlackjackGame::BlackjackGame() {
    this->deck = create_deck();
    this->player_hand = {};
    this->dealer_hand = {};
}

std::vector<std::string> BlackjackGame::create_deck() {
    std::vector<std::string> deck;
    std::vector<std::string> suits = { "S", "C", "D", "H" };
    std::vector<std::string> ranks = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            deck.push_back(rank + suit);
        }
    }
    std::srand(std::time(0));
    std::mt19937 gen(std::random_device{}());
    std::shuffle(deck.begin(), deck.end(), gen);
    return deck;
}

int BlackjackGame::calculate_hand_value(const std::vector<std::string>& hand) {
    int value = 0;
    int num_aces = 0;
    for (const auto& card : hand) {
        std::string rank = card.substr(0, card.size() - 1);
        if (rank >= "2" && rank <= "9") {
            value += std::stoi(rank);
        }
        else if (rank == "A") {
            value += 11;
            num_aces += 1;
        }
        else {
            if (rank == "J" || rank == "Q" || rank == "K") value += 10;
        }
    }
    while (value > 21 && num_aces > 0) {
        value -= 10;
        num_aces -= 1;
    }
    return value;
}

std::string BlackjackGame::check_winner(const std::vector<std::string>& player_hand, const std::vector<std::string>& dealer_hand) {
    int player_value = calculate_hand_value(player_hand);
    int dealer_value = calculate_hand_value(dealer_hand);
    if (player_value > 21 && dealer_value > 21) {
        return player_value <= dealer_value ? "Player wins" : "Dealer wins";
    }
    else if (player_value > 21) {
        return "Dealer wins";
    }
    else if (dealer_value > 21) {
        return "Player wins";
    }
    else {
        return player_value <= dealer_value ? "Dealer wins" : "Player wins";
    }
}