package test_cases;
import to_be_tested.ExpressionCalculator;

import org.junit.jupiter.api.*;
import java.util.*;
import static org.junit.jupiter.api.Assertions.*;

public class ExpressionCalculatorTest {

    private ExpressionCalculator expressionCalculator;

    @BeforeEach
    public void setUp() {
        expressionCalculator = new ExpressionCalculator();
    }

    @Test
    public void testCalculate1() {
        double result = expressionCalculator.calculate("2 + 3 * 4");
        assertEquals(14.0, result, 0.0001);
    }

    @Test
    public void testCalculate2() {
        double result = expressionCalculator.calculate("2 + 3 + 4");
        assertEquals(9.0, result, 0.0001);
    }

    @Test
    public void testCalculate3() {
        double result = expressionCalculator.calculate("2 * 3 * 4");
        assertEquals(24.0, result, 0.0001);
    }

    @Test
    public void testCalculate4() {
        double result = expressionCalculator.calculate("2 + 4 / 4");
        assertEquals(3.0, result, 0.0001);
    }

    @Test
    public void testCalculate5() {
        double result = expressionCalculator.calculate("(2 + 3) * 4");
        assertEquals(20.0, result, 0.0001);
    }

    @Test
    public void testPrepare1() {
        expressionCalculator.prepare("2+3*4");
        assertIterableEquals(new ArrayDeque<>(Arrays.asList("2", "3", "4", "*", "+")), expressionCalculator.postfixStack);
    }

    @Test
    public void testPrepare2() {
        expressionCalculator.prepare("2+3/4");
        assertIterableEquals(new ArrayDeque<>(Arrays.asList("2", "3", "4", "/", "+")), expressionCalculator.postfixStack);
    }

    @Test
    public void testPrepare3() {
        expressionCalculator.prepare("2-3*4");
        assertIterableEquals(new ArrayDeque<>(Arrays.asList("2", "3", "4", "*", "-")), expressionCalculator.postfixStack);
    }

    @Test
    public void testPrepare4() {
        expressionCalculator.prepare("1+3*4");
        assertIterableEquals(new ArrayDeque<>(Arrays.asList("1", "3", "4", "*", "+")), expressionCalculator.postfixStack);
    }

    @Test
    public void testPrepare5() {
        expressionCalculator.prepare("(2+3)*4");
        assertIterableEquals(new ArrayDeque<>(Arrays.asList("2", "3", "+", "4", "*")), expressionCalculator.postfixStack);
    }

    @Test
    public void testPrepare6() {
        expressionCalculator.prepare("");
        assertIterableEquals(new ArrayDeque<>(), expressionCalculator.postfixStack);
    }

    @Test
    public void testIsOperator1() {
        assertTrue(expressionCalculator.isOperator('+'));
    }

    @Test
    public void testIsOperator2() {
        assertTrue(expressionCalculator.isOperator('-'));
    }

    @Test
    public void testIsOperator3() {
        assertTrue(expressionCalculator.isOperator('*'));
    }

    @Test
    public void testIsOperator4() {
        assertTrue(expressionCalculator.isOperator('/'));
    }

    @Test
    public void testIsOperator5() {
        assertFalse(expressionCalculator.isOperator('5'));
    }

    @Test
    public void testCompare1() {
        assertTrue(expressionCalculator.compare('+', '-'));
    }

    @Test
    public void testCompare2() {
        assertTrue(expressionCalculator.compare('*', '/'));
    }

    @Test
    public void testCompare3() {
        assertTrue(expressionCalculator.compare('+', '*'));
    }

    @Test
    public void testCompare4() {
        assertFalse(expressionCalculator.compare('*', '+'));
    }

    @Test
    public void testCompare5() {
        assertFalse(expressionCalculator.compare('/', '+'));
    }

    @Test
    public void testCompare6() {
        assertFalse(expressionCalculator.compare('%', '+'));
    }

    @Test
    public void testCompare7() {
        assertTrue(expressionCalculator.compare('+', '%'));
    }

    @Test
    public void testCalculateMethod1() {
        double result = expressionCalculator._calculate(2.0, 3.0, '+');
        assertEquals(5.0, result, 0.0001);
    }

    @Test
    public void testCalculateMethod2() {
        double result = expressionCalculator._calculate(3.0, 2.0, '-');
        assertEquals(1.0, result, 0.0001);
    }

    @Test
    public void testCalculateMethod3() {
        double result = expressionCalculator._calculate(2.0, 3.0, '*');
        assertEquals(6.0, result, 0.0001);
    }

    @Test
    public void testCalculateMethod4() {
        double result = expressionCalculator._calculate(3.0, 3.0, '/');
        assertEquals(1.0, result, 0.0001);
    }

    @Test
    public void testCalculateMethod5() {
        double result = expressionCalculator._calculate(6.0, 2.0, '/');
        assertEquals(3.0, result, 0.0001);
    }

    @Test
    public void testCalculateMethod6() {
        double result = expressionCalculator._calculate(6.0, 2.0, '%');
        assertEquals(0.0, result, 0.0001);
    }

    @Test
    public void testCalculateMethod7() {
        assertThrows(IllegalArgumentException.class, () -> {
            expressionCalculator._calculate(6.0, 2.0, '?');
        });
    }

    @Test
    public void testTransform1() {
        String result = expressionCalculator.transform("2 + 3 * 4");
        assertEquals("2+3*4", result);
    }

    @Test
    public void testTransform2() {
        String result = expressionCalculator.transform("2 + 3 / 4");
        assertEquals("2+3/4", result);
    }

    @Test
    public void testTransform3() {
        String result = expressionCalculator.transform("2 - 3 * 4");
        assertEquals("2~3*4", result);
    }

    @Test
    public void testTransform4() {
        String result = expressionCalculator.transform("1 + 3 * 4");
        assertEquals("1+3*4", result);
    }

    @Test
    public void testTransform5() {
        String result = expressionCalculator.transform("-2 + (-3) * 4");
        assertEquals("~2+(~3)*4", result);
    }

    @Test
    public void testTransform6() {
        String result = expressionCalculator.transform("~(1 + 1)");
        assertEquals("0-(1+1)", result);
    }

    @Test
    public void testExpressionCalculator() {
        double result = expressionCalculator.calculate("2 + 3 * 4");
        assertEquals(14.0, result, 0.0001);

        expressionCalculator.prepare("2+3*4");
        assertIterableEquals(new ArrayDeque<>(Arrays.asList("2", "3", "4", "*", "+")), expressionCalculator.postfixStack);

        assertTrue(expressionCalculator.isOperator('+'));

        assertTrue(expressionCalculator.compare('+', '-'));

        double calculateResult = expressionCalculator._calculate(2.0, 3.0, '+');
        assertEquals(5.0, calculateResult, 0.0001);

        String transformResult = expressionCalculator.transform("2 + 3 * 4");
        assertEquals("2+3*4", transformResult);
    }
}