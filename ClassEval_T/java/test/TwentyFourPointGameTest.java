package org.example;

import org.junit.jupiter.api.Test;
import java.util.List;
import static org.junit.jupiter.api.Assertions.*;

public class TwentyFourPointGameTest {

    @Test
    public void testGetMyCards1() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        List<Integer> cards = game.getNums();
        assertEquals(4, cards.size());
        for (int card : cards) {
            assertTrue(card >= 1 && card <= 9);
        }
    }

    @Test
    public void testGetMyCards2() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        List<Integer> cards = game.getNums();
        assertEquals(4, cards.size());
        for (int card : cards) {
            assertTrue(card >= 1 && card <= 9);
        }
    }

    @Test
    public void testGetMyCards3() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        List<Integer> cards = game.getNums();
        assertEquals(4, cards.size());
        for (int card : cards) {
            assertTrue(card >= 1 && card <= 9);
        }
    }

    @Test
    public void testGetMyCards4() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        List<Integer> cards = game.getNums();
        assertEquals(4, cards.size());
        for (int card : cards) {
            assertTrue(card >= 1 && card <= 9);
        }
    }

    @Test
    public void testGetMyCards5() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        List<Integer> cards = game.getNums();
        assertEquals(4, cards.size());
        for (int card : cards) {
            assertTrue(card >= 1 && card <= 9);
        }
    }

    @Test
    public void testAnswer1() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        List<Integer> cards = game.getNums();
        game.answer("pass");
        assertEquals(4, cards.size());
    }

    @Test
    public void testAnswer2() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        game.getNums().clear();
        game.getNums().add(4);
        game.getNums().add(3);
        game.getNums().add(6);
        game.getNums().add(6);
        boolean result = game.answer("4*3+6+6");
        assertTrue(result);
    }

    @Test
    public void testAnswer3() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        boolean result = game.answer("1+1+1+1");
        assertFalse(result);
    }

    @Test
    public void testAnswer4() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        boolean result = game.answer("1+");
        assertFalse(result);
    }

    @Test
    public void testAnswer5() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        boolean result = game.answer("abc");
        assertFalse(result);
    }

    @Test
    public void testAnswer6() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        game.getNums().clear();
        game.getNums().add(1);
        game.getNums().add(1);
        game.getNums().add(1);
        game.getNums().add(1);
        boolean result = game.answer("1+1+1+2");
        assertFalse(result);
    }

    @Test
    public void testAnswer7() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        game.getNums().clear();
        game.getNums().add(1);
        game.getNums().add(1);
        game.getNums().add(1);
        game.getNums().add(1);
        boolean result = game.answer("1+1+1+1+1");
        assertFalse(result);
    }

    @Test
    public void testEvaluateExpression1() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        boolean result = game.evaluateExpression("4+3+6+6");
        assertFalse(result);
    }

    @Test
    public void testEvaluateExpression2() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        boolean result = game.evaluateExpression("4*3+6+6");
        assertTrue(result);
    }

    @Test
    public void testEvaluateExpression3() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        boolean result = game.evaluateExpression("1+1+1+1");
        assertFalse(result);
    }

    @Test
    public void testEvaluateExpression4() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        boolean result = game.evaluateExpression("1+");
        assertFalse(result);
    }

    @Test
    public void testEvaluateExpression5() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        boolean result = game.evaluateExpression("abc");
        assertFalse(result);
    }

    @Test
    public void testTwentyFourPointGame() {
        TwentyFourPointGame game = new TwentyFourPointGame();
        List<Integer> cards = game.getNums();
        assertEquals(4, cards.size());
        for (int card : cards) {
            assertTrue(card >= 1 && card <= 9);
        }
        game.getNums().clear();
        game.getNums().add(4);
        game.getNums().add(3);
        game.getNums().add(6);
        game.getNums().add(6);
        boolean result = game.answer("4*3+6+6");
        assertTrue(result);
        result = game.evaluateExpression("4*3+6+6");
        assertTrue(result);
    }
}