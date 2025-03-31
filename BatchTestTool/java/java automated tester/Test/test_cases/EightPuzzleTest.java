package test_cases;
import to_be_tested.EightPuzzle;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.util.Arrays;
import java.util.List;

public class EightPuzzleTest {

    @Test
    public void testFindBlank1() {
        int[][] state = {{2, 3, 4}, {5, 8, 1}, {6, 0, 7}};
        EightPuzzle eightPuzzle = new EightPuzzle(state);
        assertArrayEquals(new int[]{2, 1}, eightPuzzle.findBlank(state));
    }

    @Test
    public void testFindBlank2() {
        int[][] state = {{2, 3, 4}, {5, 0, 1}, {6, 8, 7}};
        EightPuzzle eightPuzzle = new EightPuzzle(state);
        assertArrayEquals(new int[]{1, 1}, eightPuzzle.findBlank(state));
    }

    @Test
    public void testMove1() {
        int[][] state = {{2, 3, 4}, {5, 0, 1}, {6, 8, 7}};
        EightPuzzle eightPuzzle = new EightPuzzle(state);
        int[][] result = eightPuzzle.move(state, "up");
        int[][] expected = {{2, 0, 4}, {5, 3, 1}, {6, 8, 7}};
        assertTrue(Arrays.deepEquals(result, expected));
    }

    @Test
    public void testMove2() {
        int[][] state = {{2, 3, 4}, {5, 0, 1}, {6, 8, 7}};
        EightPuzzle eightPuzzle = new EightPuzzle(state);
        int[][] result = eightPuzzle.move(state, "down");
        int[][] expected = {{2, 3, 4}, {5, 8, 1}, {6, 0, 7}};
        assertTrue(Arrays.deepEquals(result, expected));
    }

    @Test
    public void testMove3() {
        int[][] state = {{2, 3, 4}, {5, 0, 1}, {6, 8, 7}};
        EightPuzzle eightPuzzle = new EightPuzzle(state);
        int[][] result = eightPuzzle.move(state, "left");
        int[][] expected = {{2, 3, 4}, {0, 5, 1}, {6, 8, 7}};
        assertTrue(Arrays.deepEquals(result, expected));
    }

    @Test
    public void testMove4() {
        int[][] state = {{2, 3, 4}, {5, 0, 1}, {6, 8, 7}};
        EightPuzzle eightPuzzle = new EightPuzzle(state);
        int[][] result = eightPuzzle.move(state, "right");
        int[][] expected = {{2, 3, 4}, {5, 1, 0}, {6, 8, 7}};
        assertTrue(Arrays.deepEquals(result, expected));
    }

    @Test
    public void testGetPossibleMoves1() {
        int[][] state = {{2, 3, 4}, {5, 0, 1}, {6, 8, 7}};
        EightPuzzle eightPuzzle = new EightPuzzle(state);
        List<String> result = eightPuzzle.getPossibleMoves(state);
        List<String> expected = List.of("up", "down", "left", "right");
        assertEquals(expected.size(), result.size());
        for (String direction : result) {
            assertTrue(expected.contains(direction));
        }
    }

    @Test
    public void testGetPossibleMoves2() {
        int[][] state = {{2, 3, 4}, {5, 8, 1}, {6, 0, 7}};
        EightPuzzle eightPuzzle = new EightPuzzle(state);
        List<String> result = eightPuzzle.getPossibleMoves(state);
        List<String> expected = List.of("up", "left", "right");
        assertEquals(expected.size(), result.size());
        for (String direction : result) {
            assertTrue(expected.contains(direction));
        }
    }

    @Test
    public void testSolve1() {
        int[][] initialState = {{1, 2, 3}, {4, 5, 6}, {7, 0, 8}};
        EightPuzzle eightPuzzle = new EightPuzzle(initialState);
        List<String> result = eightPuzzle.solve();
        List<String> expected = List.of("right");
        assertEquals(expected, result);
    }

    @Test
    public void testSolve2() {
        int[][] initialState = {{1, 2, 3}, {4, 0, 6}, {7, 5, 8}};
        EightPuzzle eightPuzzle = new EightPuzzle(initialState);
        List<String> result = eightPuzzle.solve();
        List<String> expected = List.of("down", "right");
        assertEquals(expected, result);
    }

    @Test
    public void testSolve3() {
        int[][] initialState = {{1, 2, 3}, {0, 4, 5}, {6, 7, 8}};
        EightPuzzle eightPuzzle = new EightPuzzle(initialState);
        List<String> result = eightPuzzle.solve();
        List<String> expected = List.of("right", "right", "down", "left", "left", "up", "right", "down", "right", "up", "left", "left", "down", "right", "right");
        assertEquals(expected, result);
    }

    @Test
    public void testSolve4() {
        int[][] initialState = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
        EightPuzzle eightPuzzle = new EightPuzzle(initialState);
        List<String> result = eightPuzzle.solve();
        List<String> expected = List.of();
        assertEquals(expected, result);
    }

    @Test
    public void testSolve5() {
        int[][] initialState = {{1, 2, 3}, {4, 5, 6}, {0, 7, 8}};
        EightPuzzle eightPuzzle = new EightPuzzle(initialState);
        List<String> result = eightPuzzle.solve();
        List<String> expected = List.of("right", "right");
        assertEquals(expected, result);
    }
}