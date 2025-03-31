import java.util.Stack;
import java.util.ArrayList;
import java.util.List;

public class BalancedBrackets {
    private Stack<Character> stack;
    private List<Character> leftBrackets;
    private List<Character> rightBrackets;
    private String expr;

    public BalancedBrackets(String expr) {
        this.stack = new Stack<>();
        this.leftBrackets = new ArrayList<>(List.of('(', '{', '['));
        this.rightBrackets = new ArrayList<>(List.of(')', '}', ']'));
        this.expr = expr;
    }

    public void clearExpr() {
        StringBuilder sb = new StringBuilder();
        for (char c : expr.toCharArray()) {
            if (leftBrackets.contains(c) || rightBrackets.contains(c)) {
                sb.append(c);
            }
        }
        this.expr = sb.toString();
    }

    public boolean checkBalancedBrackets() {
        clearExpr();
        for (char Brkt : expr.toCharArray()) {
            if (leftBrackets.contains(Brkt)) {
                stack.push(Brkt);
            } else {
                char Current_Brkt = stack.pop();
                if (Current_Brkt == '(') {
                    if (Brkt != ')') {
                        return false;
                    }
                } else if (Current_Brkt == '{') {
                    if (Brkt != '}') {
                        return false;
                    }
                } else if (Current_Brkt == '[') {
                    if (Brkt != ']') {
                        return false;
                    }
                }
            }
        }
        return stack.isEmpty();
    }
}