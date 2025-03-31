package org.example;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.util.List;
import static org.junit.jupiter.api.Assertions.*;

public class BlackjackGameTest {

    private BlackjackGame blackjackGame;

    @BeforeEach
    public void setUp() {
        blackjackGame = new BlackjackGame();
    }

    @Test
    public void testCreateDeck1() {
        assertEquals(52, blackjackGame.createDeck().size());
    }

    @Test
    public void testCreateDeck2() {
        List<String> deck = blackjackGame.createDeck();
        String[] suits = {"S", "C", "D", "H"};
        String[] ranks = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        for (String suit : suits) {
            for (String rank : ranks) {
                assertTrue(deck.contains(rank + suit));
            }
        }
    }

    @Test
    public void testCreateDeck3() {
        List<String> deck = blackjackGame.createDeck();
        String[] suits = {"S", "C", "D", "H"};
        String[] ranks = {"A", "2", "3", "4", "5", "6", "7", "8", "9"};
        for (String suit : suits) {
            for (String rank : ranks) {
                assertTrue(deck.contains(rank + suit));
            }
        }
    }

    @Test
    public void testCreateDeck4() {
        List<String> deck = blackjackGame.createDeck();
        String[] suits = {"S", "C", "D", "H"};
        String[] ranks = {"10", "J", "Q", "K"};
        for (String suit : suits) {
            for (String rank : ranks) {
                assertTrue(deck.contains(rank + suit));
            }
        }
    }

    @Test
    public void testCreateDeck5() {
        List<String> deck = blackjackGame.createDeck();
        String[] suits = {"S", "C", "D", "H"};
        String[] ranks = {"A", "2", "3", "4", "5", "6", "7", "8", "9"};
        for (String suit : suits) {
            for (String rank : ranks) {
                assertTrue(deck.contains(rank + suit));
            }
        }
    }

    @Test
    public void testCalculateHandValue1() {
        List<String> hand = List.of("2S", "3S", "4S", "5S");
        assertEquals(14, blackjackGame.calculateHandValue(hand));
    }

    @Test
    public void testCalculateHandValue2() {
        List<String> hand = List.of("2S", "3S", "JS", "QS");
        assertEquals(25, blackjackGame.calculateHandValue(hand));
    }

    @Test
    public void testCalculateHandValue3() {
        List<String> hand = List.of("2S", "3S", "4S", "AS");
        assertEquals(20, blackjackGame.calculateHandValue(hand));
    }

    @Test
    public void testCalculateHandValue4() {
        List<String> hand = List.of("JS", "QS", "4S", "AS");
        assertEquals(25, blackjackGame.calculateHandValue(hand));
    }

    @Test
    public void testCalculateHandValue5() {
        List<String> hand = List.of("JS", "QS", "AS", "AS", "AS");
        assertEquals(23, blackjackGame.calculateHandValue(hand));
    }

    @Test
    public void testCheckWinner1() {
        List<String> playerHand = List.of("2S", "JS", "QS");
        List<String> dealerHand = List.of("7S", "9S");
        assertEquals("Dealer wins", blackjackGame.checkWinner(playerHand, dealerHand));
    }

    @Test
    public void testCheckWinner2() {
        List<String> playerHand = List.of("2S", "4S", "5S");
        List<String> dealerHand = List.of("2S", "JS", "QS");
        assertEquals("Player wins", blackjackGame.checkWinner(playerHand, dealerHand));
    }

    @Test
    public void testCheckWinner3() {
        List<String> playerHand = List.of("3S", "JS", "QS");
        List<String> dealerHand = List.of("2S", "JS", "QS");
        assertEquals("Dealer wins", blackjackGame.checkWinner(playerHand, dealerHand));
    }

    @Test
    public void testCheckWinner4() {
        List<String> playerHand = List.of("2S", "JS", "QS");
        List<String> dealerHand = List.of("3S", "JS", "QS");
        assertEquals("Player wins", blackjackGame.checkWinner(playerHand, dealerHand));
    }

    @Test
    public void testCheckWinner5() {
        List<String> playerHand = List.of("2S", "3S", "5S");
        List<String> dealerHand = List.of("AS", "JS");
        assertEquals("Dealer wins", blackjackGame.checkWinner(playerHand, dealerHand));
    }

    @Test
    public void testCheckWinner6() {
        List<String> playerHand = List.of("AS", "JS");
        List<String> dealerHand = List.of("2S", "3S", "5S");
        assertEquals("Player wins", blackjackGame.checkWinner(playerHand, dealerHand));
    }

    @Test
    public void testMain1() {
        List<String> deck = blackjackGame.createDeck();
        String[] suits = {"S", "C", "D", "H"};
        String[] ranks = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        for (String suit : suits) {
            for (String rank : ranks) {
                assertTrue(deck.contains(rank + suit));
            }
        }
        List<String> playerHand = List.of("2S", "JS", "QS");
        List<String> dealerHand = List.of("7S", "9S");
        assertEquals("Dealer wins", blackjackGame.checkWinner(playerHand, dealerHand));
    }
}