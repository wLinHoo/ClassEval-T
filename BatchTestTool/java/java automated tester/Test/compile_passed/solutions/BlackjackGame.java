import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class BlackjackGame {
    private List<String> deck;
    private List<String> playerHand;
    private List<String> dealerHand;

    public BlackjackGame() {
        this.deck = createDeck();
        this.playerHand = new ArrayList<>();
        this.dealerHand = new ArrayList<>();
    }

    private List<String> createDeck() {
        List<String> deck = new ArrayList<>();
        String[] suits = {"S", "C", "D", "H"};
        String[] ranks = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        for (String suit : suits) {
            for (String rank : ranks) {
                deck.add(rank + suit);
            }
        }
        Collections.shuffle(deck);
        return deck;
    }

    private int calculateHandValue(List<String> hand) {
        int value = 0;
        int numAces = 0;
        for (String card : hand) {
            String rank = card.substring(0, card.length() - 1);
            if (rank.matches("\\d+")) {
                value += Integer.parseInt(rank);
            } else if (rank.equals("J") || rank.equals("Q") || rank.equals("K")) {
                value += 10;
            } else if (rank.equals("A")) {
                value += 11;
                numAces++;
            }
        }
        while (value > 21 && numAces > 0) {
            value -= 10;
            numAces--;
        }
        return value;
    }

    private String checkWinner(List<String> playerHand, List<String> dealerHand) {
        int playerValue = calculateHandValue(playerHand);
        int dealerValue = calculateHandValue(dealerHand);
        if (playerValue > 21 && dealerValue > 21) {
            if (playerValue <= dealerValue) {
                return "Player wins";
            } else {
                return "Dealer wins";
            }
        } else if (playerValue > 21) {
            return "Dealer wins";
        } else if (dealerValue > 21) {
            return "Player wins";
        } else {
            if (playerValue <= dealerValue) {
                return "Dealer wins";
            } else {
                return "Player wins";
            }
        }
    }

    public void playGame() {
        playerHand.add(deck.remove(0));
        dealerHand.add(deck.remove(0));
        playerHand.add(deck.remove(0));
        dealerHand.add(deck.remove(0));

        System.out.println("Player's hand: " + playerHand);
        System.out.println("Dealer's hand: " + dealerHand);

        while (true) {
            System.out.println("What would you like to do? (hit/stand)");
            String choice = System.console().readLine();
            if (choice.equals("hit")) {
                playerHand.add(deck.remove(0));
                System.out.println("Player's hand: " + playerHand);
                if (calculateHandValue(playerHand) > 21) {
                    System.out.println("Bust! Player loses");
                    return;
                }
            } else if (choice.equals("stand")) {
                break;
            } else {
                System.out.println("Invalid choice");
            }
        }

        while (calculateHandValue(dealerHand) < 17) {
            dealerHand.add(deck.remove(0));
        }

        System.out.println("Player's hand: " + playerHand);
        System.out.println("Dealer's hand: " + dealerHand);

        String winner = checkWinner(playerHand, dealerHand);
        System.out.println(winner);
    }

    public static void main(String[] args) {
        BlackjackGame game = new BlackjackGame();
        game.playGame();
    }
}