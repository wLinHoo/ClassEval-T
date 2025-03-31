package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class TwentyFourPointGame {
    private List<Integer> nums;

    public TwentyFourPointGame() {
        this.nums = getMyCards();
    }

    private List<Integer> getMyCards() {
        List<Integer> cards = new ArrayList<>();
        Random random = new Random();
        for (int i = 0; i < 4; i++) {
            cards.add(random.nextInt(9) + 1);
        }
        return cards;
    }

    public boolean answer(String expression) {
        if (expression.equals("pass")) {
            this.nums = getMyCards();
            return false;
        }

        int[] counts = new int[10];
        for (char c : expression.toCharArray()) {
            if (Character.isDigit(c)) {
                counts[Character.getNumericValue(c)]++;
            }
        }

        for (int num : nums) {
            if (counts[num] > 0) {
                counts[num]--;
            } else {
                return false;
            }
        }

        for (int count : counts) {
            if (count != 0) {
                return false;
            }
        }

        return evaluateExpression(expression);
    }

    public boolean evaluateExpression(String expression) {
        try {
            return new Object() {
                int pos = -1, ch;

                void nextChar() {
                    ch = (++pos < expression.length()) ? expression.charAt(pos) : -1;
                }

                boolean eat(int charToEat) {
                    while (ch == ' ') nextChar();
                    if (ch == charToEat) {
                        nextChar();
                        return true;
                    }
                    return false;
                }

                double parse() {
                    nextChar();
                    double x = parseExpression();
                    if (pos < expression.length()) throw new RuntimeException("Unexpected: " + (char) ch);
                    return x;
                }

                double parseExpression() {
                    double x = parseTerm();
                    for (; ; ) {
                        if (eat('+')) x += parseTerm();
                        else if (eat('-')) x -= parseTerm();
                        else return x;
                    }
                }

                double parseTerm() {
                    double x = parseFactor();
                    for (; ; ) {
                        if (eat('*')) x *= parseFactor();
                        else if (eat('/')) x /= parseFactor();
                        else return x;
                    }
                }

                double parseFactor() {
                    if (eat('+')) return parseFactor();
                    if (eat('-')) return -parseFactor();

                    double x;
                    int startPos = this.pos;
                    if (eat('(')) {
                        x = parseExpression();
                        eat(')');
                    } else if ((ch >= '0' && ch <= '9') || ch == '.') {
                        while ((ch >= '0' && ch <= '9') || ch == '.') nextChar();
                        x = Double.parseDouble(expression.substring(startPos, this.pos));
                    } else {
                        throw new RuntimeException("Unexpected: " + (char) ch);
                    }

                    return x;
                }
            }.parse() == 24;
        } catch (Exception e) {
            return false;
        }
    }

    public List<Integer> getNums() {
        return nums;
    }
}