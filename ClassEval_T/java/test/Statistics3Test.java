package org.example;

import org.junit.Test;
import static org.junit.Assert.*;

public class Statistics3Test {

    private final Statistics3 statistics3 = new Statistics3();

    @Test
    public void testMedian() {
        assertEquals(2.5, statistics3.median(new int[]{1, 2, 3, 4}), 0.001);
    }

    @Test
    public void testMedian2() {
        assertEquals(3, statistics3.median(new int[]{1, 2, 3, 4, 5}), 0.001);
    }

    @Test
    public void testMedian3() {
        assertEquals(3.5, statistics3.median(new int[]{1, 2, 3, 4, 5, 6}), 0.001);
    }

    @Test
    public void testMedian4() {
        assertEquals(4, statistics3.median(new int[]{1, 2, 3, 4, 5, 6, 7}), 0.001);
    }

    @Test
    public void testMedian5() {
        assertEquals(4.5, statistics3.median(new int[]{1, 2, 3, 4, 5, 6, 7, 8}), 0.001);
    }

    @Test
    public void testMode() {
        assertArrayEquals(new int[]{3}, statistics3.mode(new int[]{1, 2, 3, 3}));
    }

    @Test
    public void testMode2() {
        assertArrayEquals(new int[]{3, 4}, statistics3.mode(new int[]{1, 2, 3, 3, 4, 4}));
    }

    @Test
    public void testMode3() {
        assertArrayEquals(new int[]{3, 4}, statistics3.mode(new int[]{1, 2, 3, 3, 4, 4, 5}));
    }

    @Test
    public void testMode4() {
        assertArrayEquals(new int[]{3, 4, 5}, statistics3.mode(new int[]{1, 2, 3, 3, 4, 4, 5, 5}));
    }

    @Test
    public void testMode5() {
        assertArrayEquals(new int[]{3, 4, 5}, statistics3.mode(new int[]{1, 2, 3, 3, 4, 4, 5, 5, 6}));
    }

    @Test
    public void testCorrelation() {
        assertEquals(1.0, statistics3.correlation(new int[]{1, 2, 3}, new int[]{4, 5, 6}), 0.001);
    }

    @Test
    public void testCorrelation2() {
        assertEquals(1.0, statistics3.correlation(new int[]{1, 2, 3, 4}, new int[]{5, 6, 7, 8}), 0.001);
    }

    @Test
    public void testCorrelation3() {
        assertEquals(1.0, statistics3.correlation(new int[]{1, 2, 3}, new int[]{1, 2, 3}), 0.001);
    }

    @Test
    public void testCorrelation4() {
        assertNull(statistics3.correlation(new int[]{1, 1, 1}, new int[]{2, 2, 2}));
    }

    @Test
    public void testCorrelation5() {
        assertNull(statistics3.correlation(new int[]{1, 1, 1}, new int[]{1, 1, 1}));
    }

    @Test
    public void testMean() {
        assertEquals(2.0, statistics3.mean(new int[]{1, 2, 3}), 0.001);
    }

    @Test
    public void testMean2() {
        assertNull(statistics3.mean(new int[]{}));
    }

    @Test
    public void testMean3() {
        assertEquals(1.0, statistics3.mean(new int[]{1, 1, 1}), 0.001);
    }

    @Test
    public void testMean4() {
        assertEquals(1.0, statistics3.mean(new int[]{1, 1, 1, 1}), 0.001);
    }

    @Test
    public void testMean5() {
        assertEquals(1.0, statistics3.mean(new int[]{1, 1, 1, 1, 1}), 0.001);
    }

    @Test
    public void testCorrelationMatrix() {
        double[][] expected = {{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
        assertArrayEquals(expected, statistics3.correlationMatrix(new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}));
    }

    @Test
    public void testCorrelationMatrix2() {
        double[][] expected = {{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
        assertArrayEquals(expected, statistics3.correlationMatrix(new int[][]{{1, 2, 3}, {4, 5, 6}}));
    }

    @Test
    public void testCorrelationMatrix3() {
        double[][] expected = {{Double.NaN, Double.NaN, Double.NaN}, {Double.NaN, Double.NaN, Double.NaN}, {Double.NaN, Double.NaN, Double.NaN}};
        assertArrayEquals(expected, statistics3.correlationMatrix(new int[][]{{1, 2, 3}}));
    }

    @Test
    public void testCorrelationMatrix4() {
        double[][] expected = {{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
        assertArrayEquals(expected, statistics3.correlationMatrix(new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}}));
    }

    @Test
    public void testCorrelationMatrix5() {
        double[][] expected = {{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
        assertArrayEquals(expected, statistics3.correlationMatrix(new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}}));
    }

    @Test
    public void testStandardDeviation() {
        assertEquals(1.0, statistics3.standardDeviation(new int[]{1, 2, 3}), 0.001);
    }

    @Test
    public void testStandardDeviation2() {
        assertEquals(0.0, statistics3.standardDeviation(new int[]{1, 1, 1}), 0.001);
    }

    @Test
    public void testStandardDeviation3() {
        assertEquals(0.0, statistics3.standardDeviation(new int[]{1, 1}), 0.001);
    }

    @Test
    public void testStandardDeviation4() {
        assertEquals(0.0, statistics3.standardDeviation(new int[]{1, 1, 1, 1}), 0.001);
    }

    @Test
    public void testStandardDeviation5() {
        assertEquals(1.3038404810405297, statistics3.standardDeviation(new int[]{1, 1, 2, 1, 4}), 0.001);
    }

    @Test
    public void testZScore() {
        double[] expected = {-1.161895003862225, -0.3872983346207417, 0.3872983346207417, 1.161895003862225};
        assertArrayEquals(expected, statistics3.zScore(new int[]{1, 2, 3, 4}), 0.001);
    }

    @Test
    public void testZScore2() {
        assertNull(statistics3.zScore(new int[]{1, 1, 1, 1}));
    }

    @Test
    public void testZScore3() {
        assertNull(statistics3.zScore(new int[]{1}));
    }

    @Test
    public void testZScore4() {
        double[] expected = {-0.7833494518006403, -0.7833494518006403, 0.26111648393354675, 1.3055824196677337};
        assertArrayEquals(expected, statistics3.zScore(new int[]{1, 1, 2, 3}), 0.001);
    }

    @Test
    public void testZScore5() {
        assertNull(statistics3.zScore(new int[]{1, 1, 1, 1, 1}));
    }

    @Test
    public void testMain() {
        assertEquals(2.5, statistics3.median(new int[]{1, 2, 3, 4}), 0.001);
        assertArrayEquals(new int[]{3}, statistics3.mode(new int[]{1, 2, 3, 3}));
        assertEquals(1.0, statistics3.correlation(new int[]{1, 2, 3}, new int[]{4, 5, 6}), 0.001);
        assertEquals(2.0, statistics3.mean(new int[]{1, 2, 3}), 0.001);
        double[][] expectedMatrix = {{1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}, {1.0, 1.0, 1.0}};
        assertArrayEquals(expectedMatrix, statistics3.correlationMatrix(new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}));
        assertEquals(1.0, statistics3.standardDeviation(new int[]{1, 2, 3}), 0.001);
        double[] expectedZScores = {-1.161895003862225, -0.3872983346207417, 0.3872983346207417, 1.161895003862225};
        assertArrayEquals(expectedZScores, statistics3.zScore(new int[]{1, 2, 3, 4}), 0.001);
    }
}
