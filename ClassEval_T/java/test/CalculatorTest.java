package org.example;

import org.junit.jupiter.api.Test;

import java.util.Stack;

import static org.junit.jupiter.api.Assertions.*;

public class CalculatorTest {

    @org.junit.Test
    @Test
    public void testCalculate1() {
        Calculator calculator = new Calculator();
        Double res = calculator.calculate("1+2");
        assertEquals(3.0, res);
    }

    @Test
    public void testCalculate2() {
        Calculator calculator = new Calculator();
        Double res = calculator.calculate("1+2*3");
        assertEquals(7.0, res);
    }

    @Test
    public void testCalculate3() {
        Calculator calculator = new Calculator();
        Double res = calculator.calculate("1+2*3+4");
        assertEquals(11.0, res);
    }

    @Test
    public void testCalculate4() {
        Calculator calculator = new Calculator();
        Double res = calculator.calculate("1+2^3*2+4*5");
        assertEquals(37.0, res);
    }

    @Test
    public void testCalculate5() {
        Calculator calculator = new Calculator();
        Double res = calculator.calculate("1+2+3");
        assertEquals(6.0, res);
    }

    @Test
    public void testCalculate6() {
        Calculator calculator = new Calculator();
        Double res = calculator.calculate("(1+2)+3");
        assertEquals(6.0, res);
    }

    @Test
    public void testCalculate7() {
        Calculator calculator = new Calculator();
        Double res = calculator.calculate("");
        assertNull(res);
    }

    @Test
    public void testCalculate8() {
        Calculator calculator = new Calculator();
        Double res = calculator.calculate("1+2?");
        assertEquals(3.0, res);
    }

    @Test
    public void testPrecedence1() {
        Calculator calculator = new Calculator();
        int res1 = calculator.precedence('+');
        int res2 = calculator.precedence('-');
        assertEquals(res1, res2);
    }

    @Test
    public void testPrecedence2() {
        Calculator calculator = new Calculator();
        int res1 = calculator.precedence('*');
        int res2 = calculator.precedence('/');
        assertEquals(res1, res2);
    }

    @Test
    public void testPrecedence3() {
        Calculator calculator = new Calculator();
        int res1 = calculator.precedence('+');
        int res2 = calculator.precedence('/');
        assertNotEquals(res1, res2);
    }

    @Test
    public void testPrecedence4() {
        Calculator calculator = new Calculator();
        int res1 = calculator.precedence('+');
        int res2 = calculator.precedence('/');
        assertNotEquals(res1, res2);
    }

    @Test
    public void testPrecedence5() {
        Calculator calculator = new Calculator();
        int res1 = calculator.precedence('*');
        int res2 = calculator.precedence('-');
        assertNotEquals(res1, res2);
    }

    @Test
    public void testApplyOperator1() {
        Calculator calculator = new Calculator();
        Stack<Double> operandStack = new Stack<>();
        operandStack.push(1.0);
        operandStack.push(2.0);
        operandStack.push(3.0);
        Stack<Character> operatorStack = new Stack<>();
        operatorStack.push('+');
        operatorStack.push('-');
        calculator.applyOperator(operandStack, operatorStack);
        assertEquals(operandStack, new Stack<Double>() {{ push(1.0); push(-1.0); }});
        assertEquals(operatorStack, new Stack<Character>() {{ push('+'); }});
    }

    @Test
    public void testApplyOperator2() {
        Calculator calculator = new Calculator();
        Stack<Double> operandStack = new Stack<>();
        operandStack.push(1.0);
        operandStack.push(2.0);
        operandStack.push(3.0);
        Stack<Character> operatorStack = new Stack<>();
        operatorStack.push('+');
        operatorStack.push('*');
        calculator.applyOperator(operandStack, operatorStack);
        assertEquals(operandStack, new Stack<Double>() {{ push(1.0); push(6.0); }});
        assertEquals(operatorStack, new Stack<Character>() {{ push('+'); }});
    }

    @Test
    public void testApplyOperator3() {
        Calculator calculator = new Calculator();
        Stack<Double> operandStack = new Stack<>();
        operandStack.push(6.0);
        operandStack.push(3.0);
        operandStack.push(3.0);
        Stack<Character> operatorStack = new Stack<>();
        operatorStack.push('+');
        operatorStack.push('/');
        calculator.applyOperator(operandStack, operatorStack);
        assertEquals(operandStack, new Stack<Double>() {{ push(6.0); push(1.0); }});
        assertEquals(operatorStack, new Stack<Character>() {{ push('+'); }});
    }

    @Test
    public void testApplyOperator4() {
        Calculator calculator = new Calculator();
        Stack<Double> operandStack = new Stack<>();
        operandStack.push(1.0);
        operandStack.push(2.0);
        operandStack.push(3.0);
        Stack<Character> operatorStack = new Stack<>();
        operatorStack.push('+');
        operatorStack.push('^');
        calculator.applyOperator(operandStack, operatorStack);
        assertEquals(operandStack, new Stack<Double>() {{ push(1.0); push(8.0); }});
        assertEquals(operatorStack, new Stack<Character>() {{ push('+'); }});
    }

    @Test
    public void testApplyOperator5() {
        Calculator calculator = new Calculator();
        Stack<Double> operandStack = new Stack<>();
        operandStack.push(1.0);
        operandStack.push(2.0);
        operandStack.push(3.0);
        Stack<Character> operatorStack = new Stack<>();
        operatorStack.push('+');
        operatorStack.push('+');
        calculator.applyOperator(operandStack, operatorStack);
        assertEquals(operandStack, new Stack<Double>() {{ push(1.0); push(5.0); }});
        assertEquals(operatorStack, new Stack<Character>() {{ push('+'); }});
    }

    @Test
    public void testCalculator() {
        Calculator calculator = new Calculator();
        Double res = calculator.calculate("1+2");
        assertEquals(3.0, res);
        int res1 = calculator.precedence('+');
        int res2 = calculator.precedence('-');
        int res3 = calculator.precedence('*');
        int res4 = calculator.precedence('/');
        int res5 = calculator.precedence('^');
        assertEquals(res1, res2);
        assertEquals(res3, res4);
        assertTrue(res3 > res1);
        assertTrue(res5 > res3);
        Stack<Double> operandStack = new Stack<>();
        operandStack.push(1.0);
        operandStack.push(2.0);
        operandStack.push(3.0);
        Stack<Character> operatorStack = new Stack<>();
        operatorStack.push('+');
        operatorStack.push('-');
        calculator.applyOperator(operandStack, operatorStack);
        assertEquals(operandStack, new Stack<Double>() {{ push(1.0); push(-1.0); }});
        assertEquals(operatorStack, new Stack<Character>() {{ push('+'); }});
    }
}