import java.util.ArrayList;
import java.util.List;

public class BoyerMooreSearch {
    private String text;
    private String pattern;
    private int textLen;
    private int patLen;

    public BoyerMooreSearch(String text, String pattern) {
        this.text = text;
        this.pattern = pattern;
        this.textLen = text.length();
        this.patLen = pattern.length();
    }

    private int matchInPattern(char ch) {
        for (int i = patLen - 1; i >= 0; i--) {
            if (ch == pattern.charAt(i)) {
                return i;
            }
        }
        return -1;
    }

    private int mismatchInText(int currentPos) {
        for (int i = patLen - 1; i >= 0; i--) {
            if (pattern.charAt(i) != text.charAt(currentPos + i)) {
                return currentPos + i;
            }
        }
        return -1;
    }

    public List<Integer> badCharacterHeuristic() {
        List<Integer> positions = new ArrayList<>();
        int i = 0;

        while (i <= textLen - patLen) {
            int mismatchIndex = mismatchInText(i);
            if (mismatchIndex == -1) {
                positions.add(i);
                i++;
            } else {
                int matchIndex = matchInPattern(text.charAt(mismatchIndex));
                i += Math.max(1, mismatchIndex - matchIndex);
            }
        }

        return positions;
    }

    public static void main(String[] args) {
        BoyerMooreSearch bmSearch = new BoyerMooreSearch("ABAAABCD", "ABC");
        List<Integer> result = bmSearch.badCharacterHeuristic();
        System.out.println(result);  // Output: [4]
    }
}