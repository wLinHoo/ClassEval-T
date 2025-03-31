package org.example;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class BlackjackGame {
    private List<String> deck;
    private List<String> playerHand;
    private List<String> dealerHand;

    public BlackjackGame() {
        this.deck = createDeck();
        this.playerHand = new ArrayList<>();
        this.dealerHand = new ArrayList<>();
    }

    List<String> createDeck() {
        List<String> deck = new ArrayList<>();
        String[] suits = {"S", "C", "D", "H"};
        String[] ranks = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        for (String suit : suits) {
            for (String rank : ranks) {
                deck.add(rank + suit);
            }
        }
        Collections.shuffle(deck, new Random());
        return deck;
    }

    int calculateHandValue(List<String> hand) {
        int value = 0;
        int numAces = 0;
        for (String card : hand) {
            String rank = card.substring(0, card.length() - 1);
            if (rank.matches("\\d+")) {
                value += Integer.parseInt(rank);
            }
            else if (rank.equals("J") || rank.equals("Q") || rank.equals("K")) {
                value += 10;
            }
            else if (rank.equals("A")) {
                value += 11;
                numAces += 1;
            }
        }
        while (value > 21 && numAces > 0) {
            value -= 10;
            numAces -= 1;
        }
        return value;
    }

    public String checkWinner(List<String> playerHand, List<String> dealerHand) {
        int playerValue = calculateHandValue(playerHand);
        int dealerValue = calculateHandValue(dealerHand);
        if (playerValue > 21 && dealerValue > 21) {
            return playerValue <= dealerValue ? "Player wins" : "Dealer wins";
        }
        else if (playerValue > 21) {
            return "Dealer wins";
        }
        else if (dealerValue > 21) {
            return "Player wins";
        }
        else {
            return playerValue > dealerValue ? "Player wins" : "Dealer wins";
        }
    }

    public static void main(String[] args) {
        BlackjackGame game = new BlackjackGame();
        System.out.println(game.deck);
        System.out.println(game.calculateHandValue(List.of("QD", "9D", "JC", "QH", "AS")));
        System.out.println(game.checkWinner(List.of("QD", "9D", "JC", "QH", "AS"), List.of("QD", "9D", "JC", "QH", "2S")));
    }
}