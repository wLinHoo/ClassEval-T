package org.example;

import java.util.*;

public class ExpressionCalculator {
    Deque<String> postfixStack;

    public ExpressionCalculator() {
        postfixStack = new ArrayDeque<>();
    }

    public double calculate(String expression) {
        String transformedExpression = transform(expression);
        prepare(transformedExpression);
        return evaluatePostfix();
    }

    public void prepare(String expression) {
        postfixStack.clear();
        Deque<Character> operatorStack = new ArrayDeque<>();
        int length = expression.length();
        for (int i = 0; i < length; i++) {
            char ch = expression.charAt(i);
            if (Character.isDigit(ch) || ch == '.') {
                StringBuilder num = new StringBuilder();
                while (i < length && (Character.isDigit(expression.charAt(i)) || expression.charAt(i) == '.')) {
                    num.append(expression.charAt(i++));
                }
                i--;
                postfixStack.add(num.toString());
            } else if (ch == '(') {
                operatorStack.push(ch);
            } else if (ch == ')') {
                while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                    postfixStack.add(String.valueOf(operatorStack.pop()));
                }
                operatorStack.pop();
            } else if (isOperator(ch)) {
                while (!operatorStack.isEmpty() && isOperator(operatorStack.peek()) && !compare(operatorStack.peek(), ch)) {
                    postfixStack.add(String.valueOf(operatorStack.pop()));
                }
                operatorStack.push(ch);
            }
        }
        while (!operatorStack.isEmpty()) {
            postfixStack.add(String.valueOf(operatorStack.pop()));
        }
    }

    public boolean isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
    }

    public boolean compare(char op1, char op2) {
        char cur_op = op1 == '%' ? '/' : op1;
        char peek_op = op2 == '%' ? '/' : op2;
        int[] operat_priority = {0, 3, 2, 1, -1, 1, 0, 2};
        return operat_priority[peek_op - 40] >= operat_priority[cur_op - 40];
    }

    private double evaluatePostfix() {
        Deque<Double> stack = new ArrayDeque<>();
        for (String token : postfixStack) {
            if (isOperator(token.charAt(0))) {
                double b = stack.pop();
                double a = stack.pop();
                stack.push(_calculate(a, b, token.charAt(0)));
            } else {
                stack.push(Double.parseDouble(token));
            }
        }
        return stack.pop();
    }

    double _calculate(double a, double b, char operator) {
        switch (operator) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            case '%':
                return a % b;
            default:
                throw new IllegalArgumentException("Unsupported operator: " + operator);
        }
    }

    public String transform(String expression) {
        expression = expression.replaceAll(" ", "");
        expression = expression.replaceAll("-", "~");
        char[] chars = expression.toCharArray();
        if (chars[0] == '~' && expression.length() > 1 && chars[1] == '(') {
            chars[0] = '-';
            expression=String.valueOf(chars);
            return "0" + expression;
        }
        else {
            return expression;
        }
    }
}