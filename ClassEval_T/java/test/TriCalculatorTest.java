package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class TriCalculatorTest {

    @Test
    public void testCos1() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.5, tricalculator.cos(60), 1e-10);
    }

    @Test
    public void testCos2() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.8660254038, tricalculator.cos(30), 1e-10);
    }

    @Test
    public void testCos3() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(1.0, tricalculator.cos(0), 1e-10);
    }

    @Test
    public void testCos4() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.0, tricalculator.cos(90), 1e-10);
    }

    @Test
    public void testCos5() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.7071067812, tricalculator.cos(45), 1e-10);
    }

    @Test
    public void testFactorial1() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(120, tricalculator.factorial(5).intValue());
    }

    @Test
    public void testFactorial2() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(24, tricalculator.factorial(4).intValue());
    }

    @Test
    public void testFactorial3() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(6, tricalculator.factorial(3).intValue());
    }

    @Test
    public void testFactorial4() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(2, tricalculator.factorial(2).intValue());
    }

    @Test
    public void testFactorial5() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(1, tricalculator.factorial(1).intValue());
    }

    @Test
    public void testTaylor1() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.5, tricalculator.taylor(60, 50), 1e-10);
    }

    @Test
    public void testTaylor2() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.8660254037844386, tricalculator.taylor(30, 50), 1e-10);
    }

    @Test
    public void testTaylor3() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.0, tricalculator.taylor(90, 50), 1e-10);
    }

    @Test
    public void testTaylor4() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(1.0, tricalculator.taylor(0, 50), 1e-10);
    }

    @Test
    public void testTaylor5() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.7071067811865475, tricalculator.taylor(45, 50), 1e-10);
    }

    @Test
    public void testSin1() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.5, tricalculator.sin(30), 1e-10);
    }

    @Test
    public void testSin2() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.8660254038, tricalculator.sin(60), 1e-10);
    }

    @Test
    public void testSin3() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.0, tricalculator.sin(0), 1e-10);
    }

    @Test
    public void testSin4() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(1.0, tricalculator.sin(90), 1e-10);
    }

    @Test
    public void testSin5() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.7071067812, tricalculator.sin(45), 1e-10);
    }

    @Test
    public void testTan1() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(1.0, tricalculator.tan(45), 1e-10);
    }

    @Test
    public void testTan2() {
        TriCalculator tricalculator = new TriCalculator();
        assertTrue(Double.isNaN(tricalculator.tan(90)));
    }

    @Test
    public void testTan3() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.5773502692, tricalculator.tan(30), 1e-10);
    }

    @Test
    public void testTan4() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(1.7320508076, tricalculator.tan(60), 1e-10);
    }

    @Test
    public void testTan5() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.0, tricalculator.tan(0), 1e-10);
    }

    @Test
    public void testTriCalculator() {
        TriCalculator tricalculator = new TriCalculator();
        assertEquals(0.5, tricalculator.cos(60), 1e-10);
        assertEquals(0.5, tricalculator.taylor(60, 50), 1e-10);
        assertEquals(0.5, tricalculator.sin(30), 1e-10);
        assertEquals(1.0, tricalculator.tan(45), 1e-10);
        assertTrue(Double.isNaN(tricalculator.tan(90)));
    }
}
