package org.example;

public class Manacher {
    private String inputString;

    public Manacher(String inputString) {
        this.inputString = inputString;
    }

    private String preprocess(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            sb.append('|');
            sb.append(s.charAt(i));
        }
        sb.append('|');
        return sb.toString();
    }

    protected int palindromicLength(String s, int center) {
        int diff = 1;
        while (center - diff >= 0 && center + diff < s.length() && s.charAt(center - diff) == s.charAt(center + diff)) {
            diff++;
        }
        return diff - 1;
    }

    public String palindromicString() {
        String processedString = preprocess(inputString);
        int maxLength = 0;
        int centerIndex = 0;

        for (int i = 0; i < processedString.length(); i++) {
            int length = palindromicLength(processedString, i);
            if (length > maxLength) {
                maxLength = length;
                centerIndex = i;
            }
        }

        String result = processedString.substring(centerIndex - maxLength, centerIndex + maxLength + 1);
        return result.replace("|", "");
    }

    public static void main(String[] args) {
        Manacher manacher = new Manacher("ababaxse");
        System.out.println(manacher.palindromicString());
    }
}
