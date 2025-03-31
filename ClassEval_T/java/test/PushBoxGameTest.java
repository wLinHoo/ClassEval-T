package org.example;

import org.junit.Before;
import org.junit.Test;
import static org.junit.Assert.*;

public class PushBoxGameTest {

    private PushBoxGame game;
    private char[][] gameMap;

    @Before
    public void setUp() {
        gameMap = new char[][]{
                "#####".toCharArray(),
                "#O  #".toCharArray(),
                "# X #".toCharArray(),
                "#  G#".toCharArray(),
                "#####".toCharArray()
        };
        game = new PushBoxGame(gameMap);
    }

    @Test
    public void testInitGame1() {
        char[][] expectedMap = new char[][]{
                "#####".toCharArray(),
                "#O  #".toCharArray(),
                "# X #".toCharArray(),
                "#  G#".toCharArray(),
                "#####".toCharArray()
        };
        assertArrayEquals(expectedMap, game.getMap());
    }

    @Test
    public void testInitGame2() {
        assertFalse(game.isGameOver());
    }

    @Test
    public void testInitGame3() {
        assertEquals(1, game.getPlayerCol());
    }

    @Test
    public void testInitGame4() {
        assertEquals(1, game.getPlayerRow());
    }

    @Test
    public void testInitGame5() {
        int[][] expectedTargets = {{3, 3}};
        assertArrayEquals(expectedTargets, game.getTargets().toArray(new int[0][]));
    }

    @Test
    public void testInitGame6() {
        int[][] expectedBoxes = {{2, 2}};
        assertArrayEquals(expectedBoxes, game.getBoxes().toArray(new int[0][]));
    }

    @Test
    public void testInitGame7() {
        assertEquals(1, game.getTargetCount());
    }

    @Test
    public void testCheckWin1() {
        assertFalse(game.checkWin());
    }

    @Test
    public void testCheckWin2() {
        char[] moves = {'d', 's', 'a', 's', 'd'};
        for (char move : moves) {
            game.move(move);
        }
        assertTrue(game.checkWin());
    }

    @Test
    public void testMove1() {
        char[] moves = {'d', 's', 'a', 's'};
        for (char move : moves) {
            assertFalse(game.move(move));
        }
        assertTrue(game.move('d'));
    }

    @Test
    public void testMove2() {
        game.move('a');
        assertEquals(1, game.getPlayerCol());
        assertEquals(1, game.getPlayerRow());
        assertFalse(game.isGameOver());
    }

    @Test
    public void testMove3() {
        game.move('d');
        assertEquals(2, game.getPlayerCol());
        assertEquals(1, game.getPlayerRow());
        assertFalse(game.isGameOver());
    }

    @Test
    public void testMove4() {
        game.move('s');
        assertEquals(1, game.getPlayerCol());
        assertEquals(2, game.getPlayerRow());
        assertFalse(game.isGameOver());
    }

    @Test
    public void testMove5() {
        game.move('w');
        assertEquals(1, game.getPlayerCol());
        assertEquals(1, game.getPlayerRow());
        assertFalse(game.isGameOver());
    }

    @Test
    public void testMove6() {
        game.move('?');
        assertFalse(game.isGameOver());
    }

    @Test
    public void testMove7() {
        gameMap = new char[][]{
                "#####".toCharArray(),
                "# X #".toCharArray(),
                "# O #".toCharArray(),
                "#  G#".toCharArray(),
                "#####".toCharArray()
        };
        game = new PushBoxGame(gameMap);
        game.move('w');
        assertEquals(2, game.getPlayerCol());
        assertEquals(2, game.getPlayerRow());
        assertFalse(game.isGameOver());
    }
}
