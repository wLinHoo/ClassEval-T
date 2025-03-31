package org.example;

import java.util.HashMap;
import java.util.Map;
import java.util.Stack;

public class Calculator {
    private Map<Character, Operation> operators;

    public Calculator() {
        operators = new HashMap<>();
        operators.put('+', (x, y) -> x + y);
        operators.put('-', (x, y) -> x - y);
        operators.put('*', (x, y) -> x * y);
        operators.put('/', (x, y) -> x / y);
        operators.put('^', (x, y) -> Math.pow(x, y));
    }

    public Double calculate(String expression) {
        Stack<Double> operandStack = new Stack<>();
        Stack<Character> operatorStack = new Stack<>();
        StringBuilder numBuffer = new StringBuilder();

        for (int i = 0; i < expression.length(); i++) {
            char ch = expression.charAt(i);
            if (Character.isDigit(ch) || ch == '.') {
                numBuffer.append(ch);
            } else {
                if (numBuffer.length() > 0) {
                    operandStack.push(Double.parseDouble(numBuffer.toString()));
                    numBuffer.setLength(0);
                }

                if (operators.containsKey(ch)) {
                    while (!operatorStack.isEmpty() &&
                            operatorStack.peek() != '(' &&
                            precedence(operatorStack.peek()) >= precedence(ch)) {
                        applyOperator(operandStack, operatorStack);
                    }
                    operatorStack.push(ch);
                } else if (ch == '(') {
                    operatorStack.push(ch);
                } else if (ch == ')') {
                    while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                        applyOperator(operandStack, operatorStack);
                    }
                    operatorStack.pop();
                }
            }
        }

        if (numBuffer.length() > 0) {
            operandStack.push(Double.parseDouble(numBuffer.toString()));
        }

        while (!operatorStack.isEmpty()) {
            applyOperator(operandStack, operatorStack);
        }

        return operandStack.isEmpty() ? null : operandStack.peek();
    }

    int precedence(char operator) {
        switch (operator) {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
            case '^':
                return 3;
            default:
                return 0;
        }
    }

    void applyOperator(Stack<Double> operandStack, Stack<Character> operatorStack) {
        char operator = operatorStack.pop();
        double operand2 = operandStack.pop();
        double operand1 = operandStack.pop();
        double result = operators.get(operator).apply(operand1, operand2);
        operandStack.push(result);
    }

    @FunctionalInterface
    private interface Operation {
        double apply(double x, double y);
    }

    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        System.out.println(calculator.calculate("1+2-3"));
    }
}