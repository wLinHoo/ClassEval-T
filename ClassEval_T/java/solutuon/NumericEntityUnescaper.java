package org.example;

public class NumericEntityUnescaper {

    public String replace(String string) {
        StringBuilder out = new StringBuilder();
        int pos = 0;
        int length = string.length();

        while (pos < length - 2) {
            if (string.charAt(pos) == '&' && string.charAt(pos + 1) == '#') {
                int start = pos + 2;
                boolean isHex = false;
                char firstChar = string.charAt(start);

                if (firstChar == 'x' || firstChar == 'X') {
                    start++;
                    isHex = true;
                }

                if (start == length) {
                    return out.toString();
                }

                int end = start;
                while (end < length && isHexChar(string.charAt(end))) {
                    end++;
                }

                if (end < length && string.charAt(end) == ';') {
                    try {
                        int entityValue = Integer.parseInt(string.substring(start, end), isHex ? 16 : 10);
                        out.append((char) entityValue);
                        pos = end + 1;
                        continue;
                    } catch (NumberFormatException e) {
                        return out.toString();
                    }
                }
            }
            out.append(string.charAt(pos));
            pos++;
        }

        return out.toString();
    }

    public static boolean isHexChar(char c) {
        return Character.isDigit(c) || ('a' <= Character.toLowerCase(c) && Character.toLowerCase(c) <= 'f');
    }
}