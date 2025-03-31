package test_cases;
import to_be_tested.CombinationCalculator;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class CombinationCalculatorTestCount {

    @Test
    void testCount() {
        assertEquals(6, CombinationCalculator.count(4, 2));
    }

    @Test
    void testCount2() {
        assertEquals(10, CombinationCalculator.count(5, 3));
    }

    @Test
    void testCount3() {
        assertEquals(1, CombinationCalculator.count(6, 6));
    }

    @Test
    void testCount4() {
        assertEquals(1, CombinationCalculator.count(6, 0));
    }

    @Test
    void testCount5() {
        assertEquals(20, CombinationCalculator.count(6, 3));
    }
}

class CombinationCalculatorTestCountAll {

    @Test
    void testCountAll() {
        assertEquals(15, CombinationCalculator.countAll(4));
    }

    @Test
    void testCountAll2() {
        assertEquals(Double.NaN, CombinationCalculator.countAll(-1));
    }

    @Test
    void testCountAll3() {
        assertEquals(Double.NaN, CombinationCalculator.countAll(65));
    }

    @Test
    void testCountAll4() {
        assertEquals(0, CombinationCalculator.countAll(0));
    }

    @Test
    void testCountAll5() {
        assertEquals(Double.POSITIVE_INFINITY, CombinationCalculator.countAll(63));
    }
}

class CombinationCalculatorTestSelect {

    @Test
    void testSelect() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B", "C", "D"));
        assertEquals(6, calc.count(4, 2));
    }

    @Test
    void testSelect2() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B", "C", "D"));
        assertEquals(10, calc.count(5, 3));
    }

    @Test
    void testSelect3() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B", "C", "D"));
        assertEquals(1, calc.count(6, 6));
    }

    @Test
    void testSelect4() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B", "C", "D"));
        assertEquals(1, calc.count(6, 0));
    }

    @Test
    void testSelect5() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B", "C", "D"));
        assertEquals(20, calc.count(6, 3));
    }
}

class CombinationCalculatorTestSelectAll {

    @Test
    void testSelectAll() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A"));
        assertEquals(List.of(List.of("A")), calc.selectAll());
    }

    @Test
    void testSelectAll2() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B"));
        assertEquals(List.of(List.of("A"), List.of("B"), List.of("A", "B")), calc.selectAll());
    }

    @Test
    void testSelectAll3() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B", "C"));
        assertEquals(List.of(
                List.of("A"),
                List.of("B"),
                List.of("C"),
                List.of("A", "B"),
                List.of("A", "C"),
                List.of("B", "C"),
                List.of("A", "B", "C")
        ), calc.selectAll());
    }

    @Test
    void testSelectAll4() {
        CombinationCalculator calc = new CombinationCalculator(List.of());
        assertEquals(List.of(), calc.selectAll());
    }

    @Test
    void testSelectAll5() {
        CombinationCalculator calc = new CombinationCalculator(List.of("B"));
        assertEquals(List.of(List.of("B")), calc.selectAll());
    }
}

class CombinationCalculatorTestSelect2 {

    @Test
    void testSelect2() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B", "C", "D"));
        List<List<String>> result = new ArrayList<>();
        calc._select(0, new ArrayList<>(2), 0, result, 2);
        assertEquals(List.of(
                List.of("A", "B"),
                List.of("A", "C"),
                List.of("A", "D"),
                List.of("B", "C"),
                List.of("B", "D"),
                List.of("C", "D")
        ), result);
    }

    @Test
    void testSelect2_2() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B", "C", "D"));
        List<List<String>> result = new ArrayList<>();
        calc._select(0, new ArrayList<>(3), 0, result, 3);
        assertEquals(List.of(
                List.of("A", "B", "C"),
                List.of("A", "B", "D"),
                List.of("A", "C", "D"),
                List.of("B", "C", "D")
        ), result);
    }

    @Test
    void testSelect2_3() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B", "C", "D"));
        List<List<String>> result = new ArrayList<>();
        calc._select(0, new ArrayList<>(1), 0, result, 1);
        assertEquals(List.of(
                List.of("A"),
                List.of("B"),
                List.of("C"),
                List.of("D")
        ), result);
    }

    @Test
    void testSelect2_4() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B", "C", "D"));
        List<List<String>> result = new ArrayList<>();
        calc._select(0, new ArrayList<>(0), 0, result, 0);
        assertEquals(List.of(List.of()), result);
    }

    @Test
    void testSelect2_5() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B", "C", "D"));
        List<List<String>> result = new ArrayList<>();
        calc._select(0, new ArrayList<>(4), 0, result, 4);
        assertEquals(List.of(List.of("A", "B", "C", "D")), result);
    }
}

class CombinationCalculatorTestMain {

    @Test
    void testMain() {
        CombinationCalculator calc = new CombinationCalculator(List.of("A", "B", "C", "D"));
        assertEquals(6, calc.count(4, 2));
        assertEquals(15, calc.countAll(4));
        assertEquals(List.of(
                List.of("A", "B"),
                List.of("A", "C"),
                List.of("A", "D"),
                List.of("B", "C"),
                List.of("B", "D"),
                List.of("C", "D")
        ), calc.select(2));
        assertEquals(List.of(
                List.of("A"),
                List.of("B"),
                List.of("C"),
                List.of("D"),
                List.of("A", "B"),
                List.of("A", "C"),
                List.of("A", "D"),
                List.of("B", "C"),
                List.of("B", "D"),
                List.of("C", "D"),
                List.of("A", "B", "C"),
                List.of("A", "B", "D"),
                List.of("A", "C", "D"),
                List.of("B", "C", "D"),
                List.of("A", "B", "C", "D")
        ), calc.selectAll());
        List<List<String>> result = new ArrayList<>();
        calc._select(0, new ArrayList<>(2), 0, result, 2);
        assertEquals(List.of(
                List.of("A", "B"),
                List.of("A", "C"),
                List.of("A", "D"),
                List.of("B", "C"),
                List.of("B", "D"),
                List.of("C", "D")
        ), result);
    }
}
