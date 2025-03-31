package test_cases;
import to_be_tested.KappaCalculator;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class KappaCalculatorTest {

    @Test
    public void testKappa1() {
        assertEquals(0.25, KappaCalculator.kappa(new int[][]{{2, 1, 1}, {1, 2, 1}, {1, 1, 2}}, 3));
    }

    @Test
    public void testKappa2() {
        assertEquals(0.19469026548672572, KappaCalculator.kappa(new int[][]{{2, 2, 1}, {1, 2, 1}, {1, 1, 2}}, 3), 1e-15);
    }

    @Test
    public void testKappa3() {
        assertEquals(0.19469026548672572, KappaCalculator.kappa(new int[][]{{2, 1, 2}, {1, 2, 1}, {1, 1, 2}}, 3), 1e-15);
    }

    @Test
    public void testKappa4() {
        assertEquals(0.19469026548672572, KappaCalculator.kappa(new int[][]{{2, 1, 1}, {2, 2, 1}, {1, 1, 2}}, 3), 1e-15);
    }

    @Test
    public void testKappa5() {
        assertEquals(0.19469026548672572, KappaCalculator.kappa(new int[][]{{2, 1, 1}, {1, 2, 2}, {1, 1, 2}}, 3), 1e-15);
    }

    @Test
    public void testFleissKappa1() {
        assertEquals(0.20993070442195522, KappaCalculator.fleissKappa(new int[][]{{0, 0, 0, 0, 14},
                {0, 2, 6, 4, 2},
                {0, 0, 3, 5, 6},
                {0, 3, 9, 2, 0},
                {2, 2, 8, 1, 1},
                {7, 7, 0, 0, 0},
                {3, 2, 6, 3, 0},
                {2, 5, 3, 2, 2},
                {6, 5, 2, 1, 0},
                {0, 2, 2, 3, 7}}, 10, 5, 14), 1e-15);
    }

    @Test
    public void testFleissKappa2() {
        assertEquals(0.2115748928799344, KappaCalculator.fleissKappa(new int[][]{{1, 0, 0, 0, 14},
                {0, 2, 6, 4, 2},
                {0, 0, 3, 5, 6},
                {0, 3, 9, 2, 0},
                {2, 2, 8, 1, 1},
                {7, 7, 0, 0, 0},
                {3, 2, 6, 3, 0},
                {2, 5, 3, 2, 2},
                {6, 5, 2, 1, 0},
                {0, 2, 2, 3, 7}}, 10, 5, 14), 1e-15);
    }

    @Test
    public void testFleissKappa3() {
        assertEquals(0.21076904123090398, KappaCalculator.fleissKappa(new int[][]{{0, 1, 0, 0, 14},
                {0, 2, 6, 4, 2},
                {0, 0, 3, 5, 6},
                {0, 3, 9, 2, 0},
                {2, 2, 8, 1, 1},
                {7, 7, 0, 0, 0},
                {3, 2, 6, 3, 0},
                {2, 5, 3, 2, 2},
                {6, 5, 2, 1, 0},
                {0, 2, 2, 3, 7}}, 10, 5, 14), 1e-15);
    }

    @Test
    public void testFleissKappa4() {
        assertEquals(0.2096583016522883, KappaCalculator.fleissKappa(new int[][]{{0, 0, 1, 0, 14},
                {0, 2, 6, 4, 2},
                {0, 0, 3, 5, 6},
                {0, 3, 9, 2, 0},
                {2, 2, 8, 1, 1},
                {7, 7, 0, 0, 0},
                {3, 2, 6, 3, 0},
                {2, 5, 3, 2, 2},
                {6, 5, 2, 1, 0},
                {0, 2, 2, 3, 7}}, 10, 5, 14), 1e-15);
    }

    @Test
    public void testFleissKappa5() {
        assertEquals(0.21147425143148907, KappaCalculator.fleissKappa(new int[][]{{0, 0, 0, 1, 14},
                {0, 2, 6, 4, 2},
                {0, 0, 3, 5, 6},
                {0, 3, 9, 2, 0},
                {2, 2, 8, 1, 1},
                {7, 7, 0, 0, 0},
                {3, 2, 6, 3, 0},
                {2, 5, 3, 2, 2},
                {6, 5, 2, 1, 0},
                {0, 2, 2, 3, 7}}, 10, 5, 14), 1e-15);
    }
}