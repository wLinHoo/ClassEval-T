package org.example;

import java.util.Stack;

public class BalancedBrackets {
    private Stack<Character> stack;
    private String leftBrackets;
    private String rightBrackets;
    private String expr;

    public BalancedBrackets(String expr) {
        this.stack = new Stack<>();
        this.leftBrackets = "({[";
        this.rightBrackets = ")}]";
        this.expr = expr;
    }

    public void clearExpr() {
        StringBuilder cleanedExpr = new StringBuilder();
        for (char c : expr.toCharArray()) {
            if (leftBrackets.indexOf(c) != -1 || rightBrackets.indexOf(c) != -1) {
                cleanedExpr.append(c);
            }
        }
        this.expr = cleanedExpr.toString();
    }

    public boolean checkBalancedBrackets() {
        clearExpr();
        for (char Brkt : expr.toCharArray()) {
            if (leftBrackets.indexOf(Brkt) != -1) {
                stack.push(Brkt);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                char currentBrkt = stack.pop();
                if (currentBrkt == '(' && Brkt != ')') {
                    return false;
                }
                if (currentBrkt == '{' && Brkt != '}') {
                    return false;
                }
                if (currentBrkt == '[' && Brkt != ']') {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    public String getExpr() {
        return expr;
    }

    public static void main(String[] args) {
        BalancedBrackets b = new BalancedBrackets("a(b)c");
        System.out.println(b.checkBalancedBrackets());
    }
}