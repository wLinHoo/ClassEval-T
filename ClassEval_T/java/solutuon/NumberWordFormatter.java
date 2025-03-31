package org.example;

public class NumberWordFormatter {
    private final String[] NUMBER = {"", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    private final String[] NUMBER_TEEN = {"TEN", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"};
    private final String[] NUMBER_TEN = {"TEN", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"};
    private final String[] NUMBER_MORE = {"", "THOUSAND", "MILLION", "BILLION"};
    private final String[] NUMBER_SUFFIX = {"k", "w", "", "m", "", "", "b", "", "", "t", "", "", "p", "", "", "e"};

    public String format(Object x) {
        if (x == null) {
            return "";
        }
        return formatString(x.toString());
    }

    public String formatString(String x) {
        String[] parts = x.split("\\.");
        String lstr = parts[0];
        String rstr = parts.length > 1 ? parts[1] : "";
        String lstrrev = new StringBuilder(lstr).reverse().toString();
        String[] a = new String[5];

        if (lstrrev.length() % 3 == 1) {
            lstrrev += "00";
        } else if (lstrrev.length() % 3 == 2) {
            lstrrev += "0";
        }

        StringBuilder lm = new StringBuilder();
        for (int i = 0; i < lstrrev.length() / 3; i++) {
            a[i] = new StringBuilder(lstrrev.substring(3 * i, 3 * i + 3)).reverse().toString();
            if (!a[i].equals("000")) {
                lm.insert(0, transThree(a[i]) + " " + parseMore(i) + " ");
            } else {
                lm.insert(0, transThree(a[i]));
            }
        }

        String xs = !rstr.isEmpty() ? "AND CENTS " + transTwo(rstr) + " " : "";
        if (lm.toString().trim().isEmpty()) {
            return "ZERO ONLY";
        } else {
            return lm.toString().trim() + " " + xs + "ONLY";
        }
    }

    public String transTwo(String s) {
        s = String.format("%2s", s).replace(' ', '0');
        if (s.charAt(0) == '0') {
            return NUMBER[Integer.parseInt(s.substring(1))];
        } else if (s.charAt(0) == '1') {
            return NUMBER_TEEN[Integer.parseInt(s) - 10];
        } else if (s.charAt(1) == '0') {
            return NUMBER_TEN[Integer.parseInt(s.substring(0, 1)) - 1];
        } else {
            return NUMBER_TEN[Integer.parseInt(s.substring(0, 1)) - 1] + " " + NUMBER[Integer.parseInt(s.substring(1))];
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