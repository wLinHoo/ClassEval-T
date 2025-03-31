package org.example;

import java.util.HashMap;
import java.util.Map;

public class Words2Numbers {

    private Map<String, int[]> numwords;
    private String[] units;
    private String[] tens;
    private String[] scales;
    private Map<String, Integer> ordinalWords;
    private String[][] ordinalEndings;

    public Words2Numbers() {
        numwords = new HashMap<>();
        units = new String[]{
                "zero", "one", "two", "three", "four", "five", "six", "seven", "eight",
                "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
                "sixteen", "seventeen", "eighteen", "nineteen"
        };
        tens = new String[]{
                "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
        };
        scales = new String[]{
                "hundred", "thousand", "million", "billion", "trillion"
        };

        numwords.put("and", new int[]{1, 0});
        for (int idx = 0; idx < units.length; idx++) {
            numwords.put(units[idx], new int[]{1, idx});
        }
        for (int idx = 0; idx < tens.length; idx++) {
            numwords.put(tens[idx], new int[]{1, idx * 10});
        }
        for (int idx = 0; idx < scales.length; idx++) {
            numwords.put(scales[idx], new int[]{(int) Math.pow(10, (idx * 3 == 0 ? 2 : idx * 3)), 0});
        }

        ordinalWords = new HashMap<>();
        ordinalWords.put("first", 1);
        ordinalWords.put("second", 2);
        ordinalWords.put("third", 3);
        ordinalWords.put("fifth", 5);
        ordinalWords.put("eighth", 8);
        ordinalWords.put("ninth", 9);
        ordinalWords.put("twelfth", 12);

        ordinalEndings = new String[][]{
                {"ieth", "y"}, {"th", ""}
        };
    }

    public String text2int(String textnum) {
        textnum = textnum.replace("-", " ");

        int current = 0, result = 0;
        StringBuilder curstring = new StringBuilder();
        boolean onnumber = false;

        for (String word : textnum.split(" ")) {
            if (ordinalWords.containsKey(word)) {
                int scale = 1, increment = ordinalWords.get(word);
                current = current * scale + increment;
                onnumber = true;
            } else {
                for (String[] ending : ordinalEndings) {
                    if (word.endsWith(ending[0])) {
                        word = word.substring(0, word.length() - ending[0].length()) + ending[1];
                    }
                }

                if (!numwords.containsKey(word)) {
                    if (onnumber) {
                        curstring.append(result + current).append(" ");
                    }
                    curstring.append(word).append(" ");
                    result = current = 0;
                    onnumber = false;
                } else {
                    int scale = numwords.get(word)[0];
                    int increment = numwords.get(word)[1];
                    current = current * scale + increment;
                    if (scale > 100) {
                        result += current;
                        current = 0;
                    }
                    onnumber = true;
                }
            }
        }

        if (onnumber) {
            curstring.append(result + current);
        }

        return curstring.toString();
    }

    public boolean isValidInput(String textnum) {
        textnum = textnum.replace("-", " ");

        for (String word : textnum.split(" ")) {
            if (ordinalWords.containsKey(word)) {
                continue;
            } else {
                for (String[] ending : ordinalEndings) {
                    if (word.endsWith(ending[0])) {
                        word = word.substring(0, word.length() - ending[0].length()) + ending[1];
                    }
                }

                if (!numwords.containsKey(word)) {
                    return false;
                }
            }
        }

        return true;
    }
}
