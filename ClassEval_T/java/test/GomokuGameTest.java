package org.example;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static org.junit.jupiter.api.Assertions.*;

public class GomokuGameTest {
    private GomokuGame gomokuGame;

    @BeforeEach
    public void setUp() {
        gomokuGame = new GomokuGame(10);
    }

    @Test
    public void testMakeMove1() {
        assertTrue(gomokuGame.makeMove(0, 0));
        char[][] expectedBoard = new char[10][10];
        for (char[] row : expectedBoard) {
            Arrays.fill(row, ' ');
        }
        expectedBoard[0][0] = 'X';
        assertArrayEquals(expectedBoard, gomokuGame.board);
    }

    @Test
    public void testMakeMove2() {
        assertTrue(gomokuGame.makeMove(0, 0));
        assertFalse(gomokuGame.makeMove(0, 0));
        char[][] expectedBoard = new char[10][10];
        for (char[] row : expectedBoard) {
            Arrays.fill(row, ' ');
        }
        expectedBoard[0][0] = 'X';
        assertArrayEquals(expectedBoard, gomokuGame.board);
    }

    @Test
    public void testMakeMove3() {
        assertTrue(gomokuGame.makeMove(0, 0));
        assertTrue(gomokuGame.makeMove(0, 1));
        char[][] expectedBoard = new char[10][10];
        for (char[] row : expectedBoard) {
            Arrays.fill(row, ' ');
        }
        expectedBoard[0][0] = 'X';
        expectedBoard[0][1] = 'O';
        assertArrayEquals(expectedBoard, gomokuGame.board);
    }

    @Test
    public void testMakeMove4() {
        assertTrue(gomokuGame.makeMove(0, 0));
        assertTrue(gomokuGame.makeMove(0, 1));
        assertFalse(gomokuGame.makeMove(0, 0));
        char[][] expectedBoard = new char[10][10];
        for (char[] row : expectedBoard) {
            Arrays.fill(row, ' ');
        }
        expectedBoard[0][0] = 'X';
        expectedBoard[0][1] = 'O';
        assertArrayEquals(expectedBoard, gomokuGame.board);
    }

    @Test
    public void testMakeMove5() {
        assertTrue(gomokuGame.makeMove(0, 0));
        assertTrue(gomokuGame.makeMove(0, 1));
        assertFalse(gomokuGame.makeMove(0, 1));
        char[][] expectedBoard = new char[10][10];
        for (char[] row : expectedBoard) {
            Arrays.fill(row, ' ');
        }
        expectedBoard[0][0] = 'X';
        expectedBoard[0][1] = 'O';
        assertArrayEquals(expectedBoard, gomokuGame.board);
    }

    @Test
    public void testCheckWinner1() {
        assertNull(gomokuGame.checkWinner());
    }

    @Test
    public void testCheckWinner2() {
        int[][] moves = {{5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1}};
        for (int[] move : moves) {
            gomokuGame.makeMove(move[0], move[1]);
        }
        assertEquals('X', gomokuGame.checkWinner());
    }

    @Test
    public void testCheckWinner3() {
        int[][] moves = {{5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 0}, {0, 4}};
        for (int[] move : moves) {
            gomokuGame.makeMove(move[0], move[1]);
        }
        assertEquals('O', gomokuGame.checkWinner());
    }

    @Test
    public void testCheckWinner4() {
        int[][] moves = {{5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1}, {0, 4}};
        for (int[] move : moves) {
            gomokuGame.makeMove(move[0], move[1]);
        }
        assertEquals('O', gomokuGame.checkWinner());
    }

    @Test
    public void testCheckWinner5() {
        int[][] moves = {{5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1}, {0, 4}, {5, 0}};
        for (int[] move : moves) {
            gomokuGame.makeMove(move[0], move[1]);
        }
        assertEquals('O', gomokuGame.checkWinner());
    }

    @Test
    public void testCheckFiveInARow1() {
        int[][] moves = {{5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1}};
        for (int[] move : moves) {
            gomokuGame.makeMove(move[0], move[1]);
        }
        assertTrue(gomokuGame.checkFiveInARow(5, 5, new int[]{0, -1}));
    }

    @Test
    public void testCheckFiveInARow2() {
        int[][] moves = {{5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1}};
        for (int[] move : moves) {
            gomokuGame.makeMove(move[0], move[1]);
        }
        assertTrue(gomokuGame.checkFiveInARow(5, 1, new int[]{0, 1}));
    }

    @Test
    public void testCheckFiveInARow3() {
        int[][] moves = {{5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1}};
        for (int[] move : moves) {
            gomokuGame.makeMove(move[0], move[1]);
        }
        assertFalse(gomokuGame.checkFiveInARow(0, 0, new int[]{0, 1}));
    }

    @Test
    public void testCheckFiveInARow4() {
        int[][] moves = {{5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1}};
        for (int[] move : moves) {
            gomokuGame.makeMove(move[0], move[1]);
        }
        assertFalse(gomokuGame.checkFiveInARow(0, 0, new int[]{1, 0}));
    }

    @Test
    public void testCheckFiveInARow5() {
        int[][] moves = {{5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1}};
        for (int[] move : moves) {
            gomokuGame.makeMove(move[0], move[1]);
        }
        assertFalse(gomokuGame.checkFiveInARow(5, 5, new int[]{1, 0}));
    }

    @Test
    public void testMain() {
        GomokuGame gomokuGame = new GomokuGame(10);
        int[][] moves = {{5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1}};
        assertNull(gomokuGame.checkWinner());
        for (int[] move : moves) {
            assertTrue(gomokuGame.makeMove(move[0], move[1]));
        }
        assertFalse(gomokuGame.makeMove(0, 0));
        assertTrue(gomokuGame.checkFiveInARow(5, 5, new int[]{0, -1}));
        assertEquals('X', gomokuGame.checkWinner());
    }
}