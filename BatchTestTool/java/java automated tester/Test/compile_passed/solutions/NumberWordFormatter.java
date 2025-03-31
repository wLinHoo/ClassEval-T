import java.util.Arrays;

public class NumberWordFormatter {
    private String[] NUMBER = {"", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    private String[] NUMBER_TEEN = {"TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"};
    private String[] NUMBER_TEN = {"TEN", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"};
    private String[] NUMBER_MORE = {"", "THOUSAND", "MILLION", "BILLION"};
    private String[] NUMBER_SUFFIX = {"k", "w", "", "m", "", "", "b", "", "", "t", "", "", "p", "", "", "e"};

    public String format(int x) {
        if (x != 0) {
            return formatString(String.valueOf(x));
        } else {
            return "";
        }
    }

    public String formatString(String x) {
        String[] parts = x.split("\\.");
        if (parts.length > 1) {
            String left = parts[0];
            String right = parts[1];
            return formatWithSuffix(left) + " AND CENTS " + transTwo(right) + " ONLY";
        } else {
            return formatWithSuffix(x);
        }
    }

    public String formatWithSuffix(String x) {
        StringBuilder lm = new StringBuilder();
        for (int i = 0; i < 3; i++) {
            int start = x.length() - 3 * (2 - i);
            if (start < 0) {
                break;
            }
            String part = x.substring(start, start + 3);
            if (!part.equals("000")) {
                lm.insert(0, " " + transThree(part) + " " + parseMore(i) + " ");
            } else {
                lm.insert(0, transThree(part));
            }
        }
        return lm.toString().trim();
    }

    public String transTwo(String s) {
        s = String.format("%02d", Integer.parseInt(s));
        if (s.charAt(0) == '0') {
            return NUMBER[Integer.parseInt(s.substring(1))];
        } else if (s.charAt(0) == '1') {
            return NUMBER_TEEN[Integer.parseInt(s) - 10];
        } else if (s.charAt(1) == '0') {
            return NUMBER_TEN[Integer.parseInt(s.substring(0, 1)) - 1];
        } else {
            return NUMBER_TEN[Integer.parseInt(s.substring(0, 1)) - 1] + " " + NUMBER[Integer.parseInt(s.substring(1, 2))];
        }
    }

    public String transThree(String s) {
        if (s.charAt(0) == '0') {
            return transTwo(s.substring(1));
        } else if (s.substring(1).equals("00")) {
            return NUMBER[Integer.parseInt(s.substring(0, 1))] + " HUNDRED";
        } else {
            return NUMBER[Integer.parseInt(s.substring(0, 1))] + " HUNDRED AND " + transTwo(s.substring(1));
        }
    }

    public String parseMore(int i) {
        return NUMBER_MORE[i];
    }
}