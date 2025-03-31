public class Manacher {

    private String inputString;

    public Manacher(String inputString) {
        this.inputString = inputString;
    }

    public String palindromicString() {
        int maxLength = 0;
        int start = 0;

        String newInputString = "";
        for (int i = 0; i < inputString.length() - 1; i++) {
            newInputString += inputString.charAt(i) + "|";
        }
        newInputString += inputString.charAt(inputString.length() - 1);

        for (int i = 0; i < newInputString.length(); i++) {
            int length = palindromicLength(i, 1, newInputString);
            if (maxLength < length) {
                maxLength = length;
                start = i;
            }
        }

        String outputString = "";
        for (int i = start - maxLength; i <= start + maxLength; i++) {
            if (newInputString.charAt(i) != '|') {
                outputString += newInputString.charAt(i);
            }
        }

        return outputString;
    }

    private int palindromicLength(int center, int diff, String string) {
        if (center - diff == -1 || center + diff == string.length() || string.charAt(center - diff) != string.charAt(center + diff)) {
            return 0;
        }
        return 1 + palindromicLength(center, diff + 1, string);
    }
}