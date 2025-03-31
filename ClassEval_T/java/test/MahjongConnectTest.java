package org.example;

import org.junit.jupiter.api.Test;
import java.util.ArrayList;
import java.util.List;
import static org.junit.jupiter.api.Assertions.*;

public class MahjongConnectTest {

    @Test
    public void testCreateBoard1() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        assertEquals(boardSize, mc.BOARD_SIZE);
        assertEquals(icons, mc.ICONS);
        for (String[] row : mc.board) {
            for (String icon : row) {
                assertTrue(icons.contains(icon));
            }
        }
    }

    @Test
    public void testCreateBoard2() {
        int[] boardSize = {2, 2};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        assertEquals(boardSize, mc.BOARD_SIZE);
        assertEquals(icons, mc.ICONS);
        for (String[] row : mc.board) {
            for (String icon : row) {
                assertTrue(icons.contains(icon));
            }
        }
    }

    @Test
    public void testCreateBoard3() {
        int[] boardSize = {3, 3};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        assertEquals(boardSize, mc.BOARD_SIZE);
        assertEquals(icons, mc.ICONS);
        for (String[] row : mc.board) {
            for (String icon : row) {
                assertTrue(icons.contains(icon));
            }
        }
    }

    @Test
    public void testCreateBoard4() {
        int[] boardSize = {1, 1};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        assertEquals(boardSize, mc.BOARD_SIZE);
        assertEquals(icons, mc.ICONS);
        for (String[] row : mc.board) {
            for (String icon : row) {
                assertTrue(icons.contains(icon));
            }
        }
    }

    @Test
    public void testCreateBoard5() {
        int[] boardSize = {5, 5};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        assertEquals(boardSize, mc.BOARD_SIZE);
        assertEquals(icons, mc.ICONS);
        for (String[] row : mc.board) {
            for (String icon : row) {
                assertTrue(icons.contains(icon));
            }
        }
    }

    @Test
    public void testIsValidMove1() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        assertTrue(mc.isValidMove(new int[]{0, 0}, new int[]{1, 0}));
    }

    @Test
    public void testIsValidMove2() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        assertFalse(mc.isValidMove(new int[]{0, 0}, new int[]{0, 1}));
    }

    @Test
    public void testIsValidMove3() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        assertFalse(mc.isValidMove(new int[]{-1, 0}, new int[]{0, 1}));
    }

    @Test
    public void testIsValidMove4() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        assertFalse(mc.isValidMove(new int[]{0, 0}, new int[]{0, 0}));
    }

    @Test
    public void testIsValidMove5() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        assertFalse(mc.isValidMove(new int[]{300, 0}, new int[]{0, 0}));
    }

    @Test
    public void testIsValidMove6() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "a", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        assertFalse(mc.isValidMove(new int[]{0, 2}, new int[]{0, 0}));
    }

    @Test
    public void testHasPath1() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        assertTrue(mc.hasPath(new int[]{0, 0}, new int[]{1, 0}));
    }

    @Test
    public void testHasPath2() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        assertTrue(mc.hasPath(new int[]{0, 0}, new int[]{0, 0}));
    }

    @Test
    public void testHasPath3() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        assertTrue(mc.hasPath(new int[]{0, 0}, new int[]{3, 0}));
    }

    @Test
    public void testHasPath4() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        assertFalse(mc.hasPath(new int[]{0, 0}, new int[]{1, 1}));
    }

    @Test
    public void testHasPath5() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        assertFalse(mc.hasPath(new int[]{300, 0}, new int[]{1, 1}));
    }

    @Test
    public void testHasPath6() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "a", "a", "a"},
                {"a", "a", "a", "a"},
                {"a", "a", "a", "a"},
                {"a", "a", "a", "a"}
        };
        assertTrue(mc.hasPath(new int[]{0, 0}, new int[]{3, 3}));
    }

    @Test
    public void testRemoveIcons1() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        mc.removeIcons(new int[]{0, 0}, new int[]{1, 0});
        assertArrayEquals(new String[][]{
                {" ", "b", "c", "a"},
                {" ", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        }, mc.board);
    }

    @Test
    public void testRemoveIcons2() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        mc.removeIcons(new int[]{2, 0}, new int[]{1, 0});
        assertArrayEquals(new String[][]{
                {"a", "b", "c", "a"},
                {" ", "b", "c", "a"},
                {" ", "b", "c", "a"},
                {"a", "b", "c", "a"}
        }, mc.board);
    }

    @Test
    public void testRemoveIcons3() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        mc.removeIcons(new int[]{1, 1}, new int[]{0, 1});
        assertArrayEquals(new String[][]{
                {"a", " ", "c", "a"},
                {"a", " ", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        }, mc.board);
    }

    @Test
    public void testRemoveIcons4() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        mc.removeIcons(new int[]{3, 0}, new int[]{2, 0});
        assertArrayEquals(new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {" ", "b", "c", "a"},
                {" ", "b", "c", "a"}
        }, mc.board);
    }

    @Test
    public void testRemoveIcons5() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        mc.removeIcons(new int[]{3, 3}, new int[]{2, 3});
        assertArrayEquals(new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", " "},
                {"a", "b", "c", " "}
        }, mc.board);
    }

    @Test
    public void testIsGameOver1() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {" ", " ", " ", " "},
                {" ", " ", " ", " "},
                {" ", " ", " ", " "},
                {" ", " ", " ", " "}
        };
        assertTrue(mc.isGameOver());
    }

    @Test
    public void testIsGameOver2() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", " ", " ", " "},
                {"a", " ", " ", " "},
                {" ", " ", " ", " "},
                {" ", " ", " ", " "}
        };
        assertFalse(mc.isGameOver());
    }

    @Test
    public void testIsGameOver3() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {" ", " ", " ", " "},
                {"a", " ", " ", " "},
                {" ", " ", " ", " "},
                {" ", " ", " ", " "}
        };
        assertFalse(mc.isGameOver());
    }

    @Test
    public void testIsGameOver4() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"1", " ", " ", " "},
                {" ", " ", " ", " "},
                {" ", " ", " ", " "},
                {" ", " ", " ", " "}
        };
        assertFalse(mc.isGameOver());
    }

    @Test
    public void testIsGameOver5() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        mc.board = new String[][]{
                {"a", " ", " ", " "},
                {" ", " ", " ", " "},
                {" ", " ", " ", " "},
                {" ", " ", " ", " "}
        };
        assertFalse(mc.isGameOver());
    }


    @Test
    public void testMahjongConnect() {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");
        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        assertEquals(boardSize, mc.BOARD_SIZE);
        assertEquals(icons, mc.ICONS);
        for (String[] row : mc.board) {
            for (String icon : row) {
                assertTrue(icons.contains(icon));
            }
        }

        mc.board = new String[][]{
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        };
        assertTrue(mc.isValidMove(new int[]{0, 0}, new int[]{1, 0}));

        assertTrue(mc.hasPath(new int[]{0, 0}, new int[]{1, 0}));

        mc.removeIcons(new int[]{0, 0}, new int[]{1, 0});
        assertArrayEquals(new String[][]{
                {" ", "b", "c", "a"},
                {" ", "b", "c", "a"},
                {"a", "b", "c", "a"},
                {"a", "b", "c", "a"}
        }, mc.board);

        mc.board = new String[][]{
                {" ", " ", " ", " "},
                {" ", " ", " ", " "},
                {" ", " ", " ", " "},
                {" ", " ", " ", " "}
        };
        assertTrue(mc.isGameOver());
    }
}