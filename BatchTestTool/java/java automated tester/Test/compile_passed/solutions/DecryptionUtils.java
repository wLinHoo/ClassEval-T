public class DecryptionUtils {
    private String key;

    public DecryptionUtils(String key) {
        this.key = key;
    }

    public String vigenereDecipher(String ciphertext) {
        StringBuilder decryptedText = new StringBuilder();
        int keyIndex = 0;
        for (char c : ciphertext.toCharArray()) {
            if (Character.isLetter(c)) {
                int shift = key.charAt(keyIndex % key.length()) - 'a';
                char decryptedChar;
                if (Character.isUpperCase(c)) {
                    decryptedChar = (char) ('A' + (c - 'A' - shift) % 26);
                } else {
                    decryptedChar = (char) ('a' + (c - 'a' - shift) % 26);
                }
                decryptedText.append(decryptedChar);
                keyIndex++;
            } else {
                decryptedText.append(c);
            }
        }
        return decryptedText.toString();
    }

    public String railFenceDecipher(String encryptedText, int rails) {
        char[][] fence = new char[rails][encryptedText.length()];
        for (int i = 0; i < rails; i++) {
            for (int j = 0; j < encryptedText.length(); j++) {
                fence[i][j] = '\n';
            }
        }
        int direction = -1;
        int row = 0, col = 0;

        for (int i = 0; i < encryptedText.length(); i++) {
            if (row == 0 || row == rails - 1) {
                direction = -direction;
            }

            fence[row][col] = ' ';
            col++;
            row += direction;
        }

        int index = 0;
        for (int i = 0; i < rails; i++) {
            for (int j = 0; j < encryptedText.length(); j++) {
                if (fence[i][j] == '\n') {
                    fence[i][j] = encryptedText.charAt(index);
                    index++;
                }
            }
        }

        String plainText = "";
        direction = -1;
        row = 0;
        col = 0;
        for (int i = 0; i < encryptedText.length(); i++) {
            if (row == 0 || row == rails - 1) {
                direction = -direction;
            }

            plainText += fence[row][col];
            col++;
            row += direction;
        }

        return plainText;
    }

    public String caesarDecipher(String ciphertext, int shift) {
        String plaintext = "";
        for (char c : ciphertext.toCharArray()) {
            if (Character.isLetter(c)) {
                int asciiOffset = Character.isUpperCase(c) ? 65 : 97;
                char shiftedChar = (char) ((c - asciiOffset - shift) % 26 + asciiOffset);
                plaintext += shiftedChar;
            } else {
                plaintext += c;
            }
        }
        return plaintext;
    }
}