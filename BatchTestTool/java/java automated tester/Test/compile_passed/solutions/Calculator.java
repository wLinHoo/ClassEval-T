import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
import java.util.function.BiFunction;

public class Calculator {

    private Map<String, BiFunction<Double, Double, Double>> operators;

    public Calculator() {
        operators = new HashMap<>();
        operators.put("+", (x, y) -> x + y);
        operators.put("-", (x, y) -> x - y);
        operators.put("*", (x, y) -> x * y);
        operators.put("/", (x, y) -> x / y);
        operators.put("^", (x, y) -> Math.pow(x, y));
    }

    public double calculate(String expression) {
        Stack<Double> operandStack = new Stack<>();
        Stack<String> operatorStack = new Stack<>();
        String numBuffer = "";

        for (char c : expression.toCharArray()) {
            if (Character.isDigit(c) || c == '.') {
                numBuffer += c;
            } else {
                if (!numBuffer.isEmpty()) {
                    operandStack.push(Double.parseDouble(numBuffer));
                    numBuffer = "";
                }

                if (operators.containsKey(String.valueOf(c))) {
                    while (!operatorStack.isEmpty() && !operatorStack.peek().equals("(") && precedence(operatorStack.peek()) >= precedence(String.valueOf(c))) {
                        operandStack = applyOperator(operandStack, operatorStack);
                    }
                    operatorStack.push(String.valueOf(c));
                } else if (c == '(') {
                    operatorStack.push("(");
                } else if (c == ')') {
                    while (!operatorStack.isEmpty() && !operatorStack.peek().equals("(")) {
                        operandStack = applyOperator(operandStack, operatorStack);
                    }
                    operatorStack.pop(); // Remove the opening parenthesis
                }
            }
        }

        if (!numBuffer.isEmpty()) {
            operandStack.push(Double.parseDouble(numBuffer));
        }

        while (!operatorStack.isEmpty()) {
            operandStack = applyOperator(operandStack, operatorStack);
        }

        return operandStack.isEmpty() ? 0 : operandStack.pop();
    }

    private Stack<Double> applyOperator(Stack<Double> operandStack, Stack<String> operatorStack) {
        String operator = operatorStack.pop();
        double operand2 = operandStack.pop();
        double operand1 = operandStack.pop();
        double result = operators.get(operator).apply(operand1, operand2);
        operandStack.push(result);
        return operandStack;
    }

    private int precedence(String operator) {
        switch (operator) {
            case "^":
                return 4;
            case "*", "/":
                return 3;
            case "+", "-":
                return 2;
            case "(":
                return 1;
            default:
                return 0;
        }
    }
}