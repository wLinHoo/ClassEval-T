package test_cases;
import to_be_tested.ComplexCalculator;

import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class ComplexCalculatorTest {

    @Test
    public void testAdd() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.add(new ComplexCalculator.ComplexNumber(1, 2), new ComplexCalculator.ComplexNumber(3, 4));
        assertEquals(new ComplexCalculator.ComplexNumber(4, 6), result);
    }

    @Test
    public void testAdd2() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.add(new ComplexCalculator.ComplexNumber(-1, -2), new ComplexCalculator.ComplexNumber(-3, -4));
        assertEquals(new ComplexCalculator.ComplexNumber(-4, -6), result);
    }

    @Test
    public void testAdd3() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.add(new ComplexCalculator.ComplexNumber(1, -2), new ComplexCalculator.ComplexNumber(3, -4));
        assertEquals(new ComplexCalculator.ComplexNumber(4, -6), result);
    }

    @Test
    public void testAdd4() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.add(new ComplexCalculator.ComplexNumber(-1, 2), new ComplexCalculator.ComplexNumber(-3, 4));
        assertEquals(new ComplexCalculator.ComplexNumber(-4, 6), result);
    }

    @Test
    public void testAdd5() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.add(new ComplexCalculator.ComplexNumber(1, 2), new ComplexCalculator.ComplexNumber(-1, -2));
        assertEquals(new ComplexCalculator.ComplexNumber(0, 0), result);
    }

    @Test
    public void testSubtract() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.subtract(new ComplexCalculator.ComplexNumber(1, 2), new ComplexCalculator.ComplexNumber(3, 4));
        assertEquals(new ComplexCalculator.ComplexNumber(-2, -2), result);
    }

    @Test
    public void testSubtract2() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.subtract(new ComplexCalculator.ComplexNumber(-1, -2), new ComplexCalculator.ComplexNumber(-3, -4));
        assertEquals(new ComplexCalculator.ComplexNumber(2, 2), result);
    }

    @Test
    public void testSubtract3() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.subtract(new ComplexCalculator.ComplexNumber(1, -2), new ComplexCalculator.ComplexNumber(3, -4));
        assertEquals(new ComplexCalculator.ComplexNumber(-2, 2), result);
    }

    @Test
    public void testSubtract4() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.subtract(new ComplexCalculator.ComplexNumber(-1, 2), new ComplexCalculator.ComplexNumber(-3, 4));
        assertEquals(new ComplexCalculator.ComplexNumber(2, -2), result);
    }

    @Test
    public void testSubtract5() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.subtract(new ComplexCalculator.ComplexNumber(1, 2), new ComplexCalculator.ComplexNumber(1, 2));
        assertEquals(new ComplexCalculator.ComplexNumber(0, 0), result);
    }

    @Test
    public void testMultiply() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.multiply(new ComplexCalculator.ComplexNumber(1, 2), new ComplexCalculator.ComplexNumber(3, 4));
        assertEquals(new ComplexCalculator.ComplexNumber(-5, 10), result);
    }

    @Test
    public void testMultiply2() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.multiply(new ComplexCalculator.ComplexNumber(-1, -2), new ComplexCalculator.ComplexNumber(-3, -4));
        assertEquals(new ComplexCalculator.ComplexNumber(-5, 10), result);
    }

    @Test
    public void testMultiply3() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.multiply(new ComplexCalculator.ComplexNumber(1, -2), new ComplexCalculator.ComplexNumber(3, -4));
        assertEquals(new ComplexCalculator.ComplexNumber(-5, -10), result);
    }

    @Test
    public void testMultiply4() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.multiply(new ComplexCalculator.ComplexNumber(-1, 2), new ComplexCalculator.ComplexNumber(-3, 4));
        assertEquals(new ComplexCalculator.ComplexNumber(-5, -10), result);
    }

    @Test
    public void testMultiply5() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.multiply(new ComplexCalculator.ComplexNumber(1, 2), new ComplexCalculator.ComplexNumber(-1, -2));
        assertEquals(new ComplexCalculator.ComplexNumber(3, -4), result);
    }

    @Test
    public void testDivide() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.divide(new ComplexCalculator.ComplexNumber(1, 2), new ComplexCalculator.ComplexNumber(3, 4));
        assertEquals(new ComplexCalculator.ComplexNumber(0.44, 0.08), result);
    }

    @Test
    public void testDivide2() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.divide(new ComplexCalculator.ComplexNumber(-1, -2), new ComplexCalculator.ComplexNumber(-3, -4));
        assertEquals(new ComplexCalculator.ComplexNumber(0.44, 0.08), result);
    }

    @Test
    public void testDivide3() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.divide(new ComplexCalculator.ComplexNumber(1, -2), new ComplexCalculator.ComplexNumber(3, -4));
        assertEquals(new ComplexCalculator.ComplexNumber(0.44, -0.08), result);
    }

    @Test
    public void testDivide4() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.divide(new ComplexCalculator.ComplexNumber(-1, 2), new ComplexCalculator.ComplexNumber(-3, 4));
        assertEquals(new ComplexCalculator.ComplexNumber(0.44, -0.08), result);
    }

    @Test
    public void testDivide5() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber result = complexCalculator.divide(new ComplexCalculator.ComplexNumber(1, 2), new ComplexCalculator.ComplexNumber(-1, -2));
        assertEquals(new ComplexCalculator.ComplexNumber(-1, 0), result);
    }

    @Test
    public void testMain() {
        ComplexCalculator complexCalculator = new ComplexCalculator();
        ComplexCalculator.ComplexNumber addResult = complexCalculator.add(new ComplexCalculator.ComplexNumber(1, 2), new ComplexCalculator.ComplexNumber(3, 4));
        ComplexCalculator.ComplexNumber subtractResult = complexCalculator.subtract(new ComplexCalculator.ComplexNumber(1, 2), new ComplexCalculator.ComplexNumber(3, 4));
        ComplexCalculator.ComplexNumber multiplyResult = complexCalculator.multiply(new ComplexCalculator.ComplexNumber(1, 2), new ComplexCalculator.ComplexNumber(3, 4));
        ComplexCalculator.ComplexNumber divideResult = complexCalculator.divide(new ComplexCalculator.ComplexNumber(1, 2), new ComplexCalculator.ComplexNumber(3, 4));

        assertEquals(new ComplexCalculator.ComplexNumber(4, 6), addResult);
        assertEquals(new ComplexCalculator.ComplexNumber(-2, -2), subtractResult);
        assertEquals(new ComplexCalculator.ComplexNumber(-5, 10), multiplyResult);
        assertEquals(new ComplexCalculator.ComplexNumber(0.44, 0.08), divideResult);
    }
}