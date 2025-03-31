package org.example;

import org.junit.jupiter.api.Nested;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

class ArrangementCalculatorTest {

    @Test
    public void testArrangementCalculator() {
        int res = ArrangementCalculator.count(5, 3);
        assertEquals(60, res);

        res = ArrangementCalculator.countAll(4);
        assertEquals(64, res);

        ArrangementCalculator ac = new ArrangementCalculator(Arrays.asList(1, 2, 3, 4));
        List<List<Object>> resSelect = ac.select(2);
        List<List<Object>> expectedSelect = Arrays.asList(
                Arrays.asList(1, 2), Arrays.asList(1, 3), Arrays.asList(1, 4),
                Arrays.asList(2, 1), Arrays.asList(2, 3), Arrays.asList(2, 4),
                Arrays.asList(3, 1), Arrays.asList(3, 2), Arrays.asList(3, 4),
                Arrays.asList(4, 1), Arrays.asList(4, 2), Arrays.asList(4, 3)
        );
        assertEquals(expectedSelect, resSelect);

        ArrangementCalculator acAll = new ArrangementCalculator(Arrays.asList(1, 2, 3));
        List<List<Object>> resSelectAll = acAll.selectAll();
        List<List<Object>> expectedSelectAll = Arrays.asList(
                Arrays.asList(1), Arrays.asList(2), Arrays.asList(3),
                Arrays.asList(1, 2), Arrays.asList(1, 3),
                Arrays.asList(2, 1), Arrays.asList(2, 3),
                Arrays.asList(3, 1), Arrays.asList(3, 2),
                Arrays.asList(1, 2, 3), Arrays.asList(1, 3, 2),
                Arrays.asList(2, 1, 3), Arrays.asList(2, 3, 1),
                Arrays.asList(3, 1, 2), Arrays.asList(3, 2, 1)
        );
        assertEquals(expectedSelectAll, resSelectAll);

        res = ArrangementCalculator.factorial(4);
        assertEquals(24, res);
    }

    @Nested
    class ArrangementCalculatorTestCount {

        @Test
        public void testCount1() {
            int res = ArrangementCalculator.count(5, 3);
            assertEquals(60, res);
        }

        @Test
        public void testCount2() {
            int res = ArrangementCalculator.count(4, 3);
            assertEquals(24, res);
        }

        @Test
        public void testCount3() {
            int res = ArrangementCalculator.count(6, 3);
            assertEquals(120, res);
        }

        @Test
        public void testCount4() {
            int res = ArrangementCalculator.count(7, 3);
            assertEquals(210, res);
        }

        @Test
        public void testCount5() {
            int res = ArrangementCalculator.count(4, 4);
            assertEquals(24, res);
        }
    }

    @Nested
    class ArrangementCalculatorTestCountAll {

        @Test
        public void testCountAll1() {
            int res = ArrangementCalculator.countAll(4);
            assertEquals(64, res);
        }

        @Test
        public void testCountAll2() {
            int res = ArrangementCalculator.countAll(1);
            assertEquals(1, res);
        }

        @Test
        public void testCountAll3() {
            int res = ArrangementCalculator.countAll(2);
            assertEquals(4, res);
        }

        @Test
        public void testCountAll4() {
            int res = ArrangementCalculator.countAll(3);
            assertEquals(15, res);
        }

        @Test
        public void testCountAll5() {
            int res = ArrangementCalculator.countAll(5);
            assertEquals(325, res);
        }
    }

    @Nested
    class ArrangementCalculatorTestFactorial {

        @Test
        public void testFactorial1() {
            int res = ArrangementCalculator.factorial(4);
            assertEquals(24, res);
        }

        @Test
        public void testFactorial2() {
            int res = ArrangementCalculator.factorial(5);
            assertEquals(120, res);
        }

        @Test
        public void testFactorial3() {
            int res = ArrangementCalculator.factorial(3);
            assertEquals(6, res);
        }

        @Test
        public void testFactorial4() {
            int res = ArrangementCalculator.factorial(2);
            assertEquals(2, res);
        }

        @Test
        public void testFactorial5() {
            int res = ArrangementCalculator.factorial(1);
            assertEquals(1, res);
        }
    }

    @Nested
    class ArrangementCalculatorTestSelect {

        @Test
        public void testSelect1() {
            ArrangementCalculator ac = new ArrangementCalculator(Arrays.asList(1, 2, 3, 4));
            List<List<Object>> res = ac.select(2);
            List<List<Object>> expected = Arrays.asList(
                    Arrays.asList(1, 2), Arrays.asList(1, 3), Arrays.asList(1, 4),
                    Arrays.asList(2, 1), Arrays.asList(2, 3), Arrays.asList(2, 4),
                    Arrays.asList(3, 1), Arrays.asList(3, 2), Arrays.asList(3, 4),
                    Arrays.asList(4, 1), Arrays.asList(4, 2), Arrays.asList(4, 3)
            );
            assertEquals(expected, res);
        }

        @Test
        public void testSelect2() {
            ArrangementCalculator ac = new ArrangementCalculator(Arrays.asList(1, 2, 3));
            List<List<Object>> res = ac.select(2);
            List<List<Object>> expected = Arrays.asList(
                    Arrays.asList(1, 2), Arrays.asList(1, 3),
                    Arrays.asList(2, 1), Arrays.asList(2, 3),
                    Arrays.asList(3, 1), Arrays.asList(3, 2)
            );
            assertEquals(expected, res);
        }

        @Test
        public void testSelect3() {
            ArrangementCalculator ac = new ArrangementCalculator(Arrays.asList(2, 3, 4));
            List<List<Object>> res = ac.select(2);
            List<List<Object>> expected = Arrays.asList(
                    Arrays.asList(2, 3), Arrays.asList(2, 4),
                    Arrays.asList(3, 2), Arrays.asList(3, 4),
                    Arrays.asList(4, 2), Arrays.asList(4, 3)
            );
            assertEquals(expected, res);
        }

        @Test
        public void testSelect4() {
            ArrangementCalculator ac = new ArrangementCalculator(Arrays.asList(1, 2));
            List<List<Object>> res = ac.select(2);
            List<List<Object>> expected = Arrays.asList(
                    Arrays.asList(1, 2), Arrays.asList(2, 1)
            );
            assertEquals(expected, res);
        }

        @Test
        public void testSelect5() {
            ArrangementCalculator ac = new ArrangementCalculator(Arrays.asList(1, 2, 3, 4));
            List<List<Object>> res = ac.select(1);
            List<List<Object>> expected = Arrays.asList(
                    Arrays.asList(1), Arrays.asList(2),
                    Arrays.asList(3), Arrays.asList(4)
            );
            assertEquals(expected, res);
        }

        @Test
        public void testSelect6() {
            ArrangementCalculator ac = new ArrangementCalculator(Arrays.asList(1, 2));
            List<List<Object>> res = ac.select(null);
            List<List<Object>> expected = Arrays.asList(
                    Arrays.asList(1, 2), Arrays.asList(2, 1)
            );
            assertEquals(expected, res);
        }
    }

    @Nested
    class ArrangementCalculatorTestSelectAll {

        @Test
        public void testSelectAll1() {
            ArrangementCalculator ac = new ArrangementCalculator(Arrays.asList(1, 2, 3));
            List<List<Object>> res = ac.selectAll();
            List<List<Object>> expected = Arrays.asList(
                    Arrays.asList(1), Arrays.asList(2), Arrays.asList(3),
                    Arrays.asList(1, 2), Arrays.asList(1, 3),
                    Arrays.asList(2, 1), Arrays.asList(2, 3),
                    Arrays.asList(3, 1), Arrays.asList(3, 2),
                    Arrays.asList(1, 2, 3), Arrays.asList(1, 3, 2),
                    Arrays.asList(2, 1, 3), Arrays.asList(2, 3, 1),
                    Arrays.asList(3, 1, 2), Arrays.asList(3, 2, 1)
            );
            assertEquals(expected, res);
        }

        @Test
        public void testSelectAll2() {
            ArrangementCalculator ac = new ArrangementCalculator(Arrays.asList(1, 2, 4));
            List<List<Object>> res = ac.selectAll();
            List<List<Object>> expected = Arrays.asList(
                    Arrays.asList(1), Arrays.asList(2), Arrays.asList(4),
                    Arrays.asList(1, 2), Arrays.asList(1, 4),
                    Arrays.asList(2, 1), Arrays.asList(2, 4),
                    Arrays.asList(4, 1), Arrays.asList(4, 2),
                    Arrays.asList(1, 2, 4), Arrays.asList(1, 4, 2),
                    Arrays.asList(2, 1, 4), Arrays.asList(2, 4, 1),
                    Arrays.asList(4, 1, 2), Arrays.asList(4, 2, 1)
            );
            assertEquals(expected, res);
        }

        @Test
        public void testSelectAll3() {
            ArrangementCalculator ac = new ArrangementCalculator(Arrays.asList(1, 2));
            List<List<Object>> res = ac.selectAll();
            List<List<Object>> expected = Arrays.asList(
                    Arrays.asList(1), Arrays.asList(2),
                    Arrays.asList(1, 2), Arrays.asList(2, 1)
            );
            assertEquals(expected, res);
        }

        @Test
        public void testSelectAll4() {
            ArrangementCalculator ac = new ArrangementCalculator(Arrays.asList(1, 3));
            List<List<Object>> res = ac.selectAll();
            List<List<Object>> expected = Arrays.asList(
                    Arrays.asList(1), Arrays.asList(3),
                    Arrays.asList(1, 3), Arrays.asList(3, 1)
            );
            assertEquals(expected, res);
        }

        @Test
        public void testSelectAll5() {
            ArrangementCalculator ac = new ArrangementCalculator(Arrays.asList(1));
            List<List<Object>> res = ac.selectAll();
            List<List<Object>> expected = Arrays.asList(
                    Arrays.asList(1)
            );
            assertEquals(expected, res);
        }
    }
}
