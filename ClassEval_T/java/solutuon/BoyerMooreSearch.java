package org.example;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class BoyerMooreSearch {
    private final String text;
    private final String pattern;
    private final int textLen;
    private final int patLen;

    public BoyerMooreSearch(String text, String pattern) {
        this.text = text;
        this.pattern = pattern;
        this.textLen = text.length();
        this.patLen = pattern.length();
    }

    int matchInPattern(char ch) {
        return pattern.lastIndexOf(ch);
    }

    int mismatchInText(int currentPos) {
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

        Map<Character, Integer> badCharHeuristic = new HashMap<>();
        for (int j = 0; j < patLen; j++) {
            badCharHeuristic.put(pattern.charAt(j), j);
        }

        if(patLen==0)
        {
            for(int j=0;j<=textLen;++j)
            {
                positions.add(j);
            }
            return positions;
        }

        while (i <= textLen - patLen) {
            int mismatchIndex = mismatchInText(i);
            if (mismatchIndex == -1) {
                positions.add(i);
                i += patLen;
            } else {
                char mismatchChar = text.charAt(mismatchIndex);
                int matchIndex = badCharHeuristic.getOrDefault(mismatchChar, -1);
                if (matchIndex >= 0) {
                    i += Math.max(1, mismatchIndex - i - matchIndex);
                }
                else {
                    i += mismatchIndex - i + 1;
                }
            }
        }
        return positions;
    }
}
