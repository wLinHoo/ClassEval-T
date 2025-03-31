import java.util.ArrayList;
import java.util.List;

public class NumericEntityUnescaper {

    public NumericEntityUnescaper() {
    }

    public String replace(String string) {
        List<Character> out = new ArrayList<>();
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
                    return getString(out);
                }

                int end = start;
                while (end < length && isHexChar(string.charAt(end))) {
                    end++;
                }

                if (end < length && string.charAt(end) == ';') {
                    try {
                        int entityValue = Integer.parseInt(string.substring(start, end), isHex ? 16 : 10);
                        out.add((char) entityValue);
                        pos = end + 1;
                        continue;
                    } catch (NumberFormatException e) {
                        return getString(out);
                    }
                }

                out.add(string.charAt(pos));
                pos++;
            } else {
                out.add(string.charAt(pos));
                pos++;
            }
        }

        return getString(out);
    }

    private String getString(List<Character> list) {
        StringBuilder sb = new StringBuilder();
        for (Character c : list) {
            sb.append(c);
        }
        return sb.toString();
    }

    private boolean isHexChar(char c) {
        return Character.isDigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
    }
}