import java.math.BigDecimal;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ExpressionCalculator {
    private Deque<String> postfixStack = new ArrayDeque<>();
    private final int[] operatPriority = {0, 3, 2, 1, -1, 1, 0, 2};

    public double calculate(String expression) {
        prepare(transform(expression));

        Deque<String> resultStack = new ArrayDeque<>();

        while (!postfixStack.isEmpty()) {
            String currentOp = postfixStack.removeLast();
            if (!isOperator(currentOp)) {
                currentOp = currentOp.replace("~", "-");
                resultStack.push(currentOp);
            } else {
                String secondValue = resultStack.pop();
                String firstValue = resultStack.pop();

                firstValue = firstValue.replace("~", "-");
                secondValue = secondValue.replace("~", "-");

                BigDecimal tempResult = _calculate(firstValue, secondValue, currentOp);
                resultStack.push(tempResult.toString());
            }
        }

        return Double.parseDouble(eval(resultStack));
    }

    private void prepare(String expression) {
        Deque<Character> opStack = new ArrayDeque<>();
        opStack.push(',');

        char[] arr = expression.toCharArray();
        int currentIndex = 0;
        int count = 0;

        for (int i = 0; i < arr.length; i++) {
            char currentOp = arr[i];
            if (isOperator(currentOp)) {
                if (count > 0) {
                    postfixStack.push(new String(arr, currentIndex, count));
                }
                char peekOp = opStack.peek();
                if (currentOp == ')') {
                    while (opStack.peek() != '(') {
                        postfixStack.push(String.valueOf(opStack.pop()));
                    }
                    opStack.pop();
                } else {
                    while (currentOp != '(' && peekOp != ',' && compare(currentOp, peekOp)) {
                        postfixStack.push(String.valueOf(opStack.pop()));
                        peekOp = opStack.peek();
                    }
                    opStack.push(currentOp);
                }

                count = 0;
                currentIndex = i + 1;
            } else {
                count++;
            }
        }

        if (count > 1 || (count == 1 && !isOperator(arr[currentIndex]))) {
            postfixStack.push(new String(arr, currentIndex, count));
        }

        while (opStack.peek() != ',') {
            postfixStack.push(String.valueOf(opStack.pop()));
        }
    }

    private boolean isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '%';
    }

    private boolean isOperator(String c) {
        return c.equals("+") || c.equals("-") || c.equals("*") || c.equals("/") || c.equals("(") || c.equals(")") || c.equals("%");
    }

    private boolean compare(char cur, char peek) {
        if (cur == '%') {
            cur = '/';
        }
        if (peek == '%') {
            peek = '/';
        }
        return operatPriority[peek - 40] >= operatPriority[cur - 40];
    }

    private BigDecimal _calculate(String firstValue, String secondValue, String currentOp) {
        BigDecimal first = new BigDecimal(firstValue);
        BigDecimal second = new BigDecimal(secondValue);

        switch (currentOp) {
            case "+":
                return first.add(second);
            case "-":
                return first.subtract(second);
            case "*":
                return first.multiply(second);
            case "/":
                return first.divide(second);
            case "%":
                return first.remainder(second);
            default:
                throw new IllegalArgumentException("Unexpected operator: " + currentOp);
        }
    }

    private String transform(String expression) {
        expression = expression.replaceAll("\\s+", "");
        expression = expression.replaceAll("=$", "");
        char[] arr = expression.toCharArray();

        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == '-') {
                if (i == 0) {
                    arr[i] = '~';
                } else {
                    char prevC = arr[i - 1];
                    if (prevC == '+' || prevC == '-' || prevC == '*' || prevC == '/' || prevC == '(' || prevC == 'E' || prevC == 'e') {
                        arr[i] = '~';
                    }
                }
            }
        }

        if (arr[0] == '~' && (arr.length > 1 && arr[1] == '(')) {
            arr[0] = '-';
            return "0" + new String(arr);
        } else {
            return new String(arr);
        }
    }

    private String eval(Deque<String> resultStack) {
        StringBuilder sb = new StringBuilder();
        while (!resultStack.isEmpty()) {
            sb.append(resultStack.pop());
            if (!resultStack.isEmpty()) {
                sb.append("*");
            }
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        ExpressionCalculator calculator = new ExpressionCalculator();
        System.out.println(calculator.calculate("3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3"));
    }
}