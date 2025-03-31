package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class TicTacToeTest {

    @Test
    public void testMakeMove1() {
        TicTacToe ttt = new TicTacToe();
        assertEquals('X', ttt.getCurrentPlayer());
        assertTrue(ttt.makeMove(0, 0));
        assertEquals('O', ttt.getCurrentPlayer());
    }

    @Test
    public void testMakeMove2() {
        TicTacToe ttt = new TicTacToe();
        assertEquals('X', ttt.getCurrentPlayer());
        assertTrue(ttt.makeMove(0, 0));
        assertTrue(ttt.makeMove(0, 1));
        assertFalse(ttt.makeMove(0, 0));
        assertEquals('X', ttt.getCurrentPlayer());
    }

    @Test
    public void testMakeMove3() {
        TicTacToe ttt = new TicTacToe();
        assertEquals('X', ttt.getCurrentPlayer());
        assertTrue(ttt.makeMove(0, 0));
        assertTrue(ttt.makeMove(0, 1));
        assertTrue(ttt.makeMove(1, 1));
        assertEquals('O', ttt.getCurrentPlayer());
    }

    @Test
    public void testMakeMove4() {
        TicTacToe ttt = new TicTacToe();
        assertEquals('X', ttt.getCurrentPlayer());
        assertTrue(ttt.makeMove(0, 0));
        assertTrue(ttt.makeMove(0, 1));
        assertTrue(ttt.makeMove(1, 1));
        assertTrue(ttt.makeMove(1, 2));
        assertEquals('X', ttt.getCurrentPlayer());
    }

    @Test
    public void testMakeMove5() {
        TicTacToe ttt = new TicTacToe();
        assertEquals('X', ttt.getCurrentPlayer());
        assertTrue(ttt.makeMove(0, 0));
        assertTrue(ttt.makeMove(0, 1));
        assertTrue(ttt.makeMove(1, 1));
        assertTrue(ttt.makeMove(1, 2));
        assertTrue(ttt.makeMove(2, 2));
        assertEquals('O', ttt.getCurrentPlayer());
    }

    @Test
    public void testCheckWinner1() {
        TicTacToe ttt = new TicTacToe();
        int[][] moves = {{1, 0}, {2, 0}, {1, 1}, {2, 1}, {1, 2}};
        for (int[] move : moves) {
            ttt.makeMove(move[0], move[1]);
        }
        assertEquals('X', ttt.checkWinner());
    }

    @Test
    public void testCheckWinner2() {
        TicTacToe ttt = new TicTacToe();
        int[][] moves = {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 0}};
        for (int[] move : moves) {
            ttt.makeMove(move[0], move[1]);
        }
        assertEquals('X', ttt.checkWinner());
    }

    @Test
    public void testCheckWinner3() {
        TicTacToe ttt = new TicTacToe();
        int[][] moves = {{0, 0}, {0, 1}, {1, 1}, {0, 2}, {2, 2}};
        for (int[] move : moves) {
            ttt.makeMove(move[0], move[1]);
        }
        assertEquals('X', ttt.checkWinner());
    }

    @Test
    public void testCheckWinner4() {
        TicTacToe ttt = new TicTacToe();
        int[][] moves = {{0, 2}, {0, 1}, {1, 1}, {1, 0}, {2, 0}};
        for (int[] move : moves) {
            ttt.makeMove(move[0], move[1]);
        }
        assertEquals('X', ttt.checkWinner());
    }

    @Test
    public void testCheckWinner5() {
        TicTacToe ttt = new TicTacToe();
        int[][] moves = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 0}};
        for (int[] move : moves) {
            ttt.makeMove(move[0], move[1]);
        }
        assertNull(ttt.checkWinner());
    }

    @Test
    public void testIsBoardFull1() {
        TicTacToe ttt = new TicTacToe();
        assertFalse(ttt.isBoardFull());
    }

    @Test
    public void testIsBoardFull2() {
        TicTacToe ttt = new TicTacToe();
        int[][] moves = {{1, 1}, {0, 2}, {2, 2}, {0, 0}, {0, 1}, {2, 1}, {1, 0}, {1, 2}, {2, 0}};
        for (int[] move : moves) {
            ttt.makeMove(move[0], move[1]);
        }
        assertTrue(ttt.isBoardFull());
    }

    @Test
    public void testIsBoardFull3() {
        TicTacToe ttt = new TicTacToe();
        int[][] moves = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 0}};
        for (int[] move : moves) {
            ttt.makeMove(move[0], move[1]);
        }
        assertFalse(ttt.isBoardFull());
    }

    @Test
    public void testIsBoardFull4() {
        TicTacToe ttt = new TicTacToe();
        int[][] moves = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 0}, {0, 2}, {1, 2}, {2, 1}, {2, 2}};
        for (int[] move : moves) {
            ttt.makeMove(move[0], move[1]);
        }
        assertTrue(ttt.isBoardFull());
    }

    @Test
    public void testIsBoardFull5() {
        TicTacToe ttt = new TicTacToe();
        int[][] moves = {{0, 0}, {0, 1}, {1, 1}, {1, 0}, {2, 0}, {0, 2}, {1, 2}, {2, 1}};
        for (int[] move : moves) {
            ttt.makeMove(move[0], move[1]);
        }
        assertFalse(ttt.isBoardFull());
    }

    @Test
    public void testMain() {
        TicTacToe ttt = new TicTacToe();
        int[][] moves = {{1, 1}, {0, 2}, {2, 2}, {0, 0}, {0, 1}, {2, 1}, {1, 0}, {1, 2}, {2, 0}};
        for (int[] move : moves) {
            assertTrue(ttt.makeMove(move[0], move[1]));
            assertNull(ttt.checkWinner());
            if (move[0] != 2 || move[1] != 0) {
                assertFalse(ttt.isBoardFull());
            }
        }
        assertTrue(ttt.isBoardFull());
    }
}