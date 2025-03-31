import java.util.HashMap;
import java.util.Map;
import java.util.Random;

public class TwentyFourPointGame {
    private int[] nums;
    private Random random;

    public TwentyFourPointGame() {
        this.nums = new int[4];
        this.random = new Random();
    }

    public int[] getMyCards() {
        nums = new int[4];
        generateCards();
        return nums;
    }

    public boolean answer(String expression) {
        if (expression.equals("pass")) {
            return true;
        }
        Map<Character, Integer> statistic = new HashMap<>();
        for (char c : expression.toCharArray()) {
            if (Character.isDigit(c) && contains(nums, Character.getNumericValue(c))) {
                statistic.put(c, statistic.getOrDefault(c, 0) + 1);
            }
        }

        Map<Character, Integer> numsUsed = new HashMap<>(statistic);

        for (int num : nums) {
            char c = (char) (num + '0');
            if (numsUsed.containsKey(c) && numsUsed.get(c) > 0) {
                numsUsed.put(c, numsUsed.get(c) - 1);
            } else {
                return false;
            }
        }

        return numsUsed.values().stream().allMatch(count -> count == 0) && evaluateExpression(expression);
    }

    private void generateCards() {
        for (int i = 0; i < 4; i++) {
            nums[i] = random.nextInt(9) + 1;
        }
        assert nums.length == 4;
    }

    private boolean evaluateExpression(String expression) {
        try {
            return eval(expression) == 24;
        } catch (Exception e) {
            return false;
        }
    }

    private boolean contains(int[] array, int target) {
        for (int num : array) {
            if (num == target) {
                return true;
            }
        }
        return false;
    }

    private double eval(final String str) {
        return new Object() {
            int pos = -1, ch;

            void nextChar() {
                ch = (++pos < str.length()) ? str.charAt(pos) : -1;
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
                double v = parseExpression();
                if (pos < str.length()) throw new RuntimeException("Unexpected: " + (char) ch);
                return v;
            }

            double parseExpression() {
                double v = parseTerm();
                while (true) {
                    if (eat('+')) {
                        v += parseTerm(); // addition
                    } else if (eat('-')) {
                        v -= parseTerm(); // subtraction
                    } else {
                        break;
                    }
                }
                return v;
            }

            double parseTerm() {
                double v = parseFactor();
                while (true) {
                    if (eat('*')) {
                        v *= parseFactor(); // multiplication
                    } else if (eat('/')) {
                        v /= parseFactor(); // division
                    } else {
                        break;
                    }
                }
                return v;
            }

            double parseFactor() {
                if (eat('+')) return parseFactor(); // unary plus
                if (eat('-')) return -parseFactor(); // unary minus

                double v;
                int startPos = this.pos;
                if (eat('(')) { // parentheses
                    v = parseExpression();
                    eat(')');
                } else if ((ch >= '0' && ch <= '9') || ch == '.') { // numbers
                    while ((ch >= '0' && ch <= '9') || ch == '.') nextChar();
                    v = Double.parseDouble(str.substring(startPos, this.pos));
                } else if (ch >= 'a' && ch <= 'z') { // functions
                    while (ch >= 'a' && ch <= 'z') nextChar();
                    String func = str.substring(startPos, this.pos);
                    v = parseFactor();
                    if (func.equals("sqrt")) v = Math.sqrt(v);
                    else if (func.equals("sin")) v = Math.sin(Math.toRadians(v));
                    else if (func.equals("cos")) v = Math.cos(Math.toRadians(v));
                    else if (func.equals("tan")) v = Math.tan(Math.toRadians(v));
                    else throw new RuntimeException("Unknown function: " + func);
                } else {
                    throw new RuntimeException("Unexpected: " + (char) ch);
                }

                return v;
            }
        }.parse();
    }
}