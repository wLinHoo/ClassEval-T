package org.example;

public class DecryptionUtils {
    private String key;

    public DecryptionUtils(String key) {
        this.key = key;
    }

    public String caesarDecipher(String ciphertext, int shift) {
        StringBuilder plaintext = new StringBuilder();
        shift = shift % 26;
        for (char ch : ciphertext.toCharArray()) {
            if (Character.isLetter(ch)) {
                int asciiOffset = Character.isUpperCase(ch) ? 'A' : 'a';
                char shiftedChar = (char) ((ch - asciiOffset - shift + 26) % 26 + asciiOffset);
                plaintext.append(shiftedChar);
            }
            else {
                plaintext.append(ch);
            }
        }
        return plaintext.toString();
    }

    public String vigenereDecipher(String ciphertext) {
        StringBuilder decryptedText = new StringBuilder();
        int keyIndex = 0;
        for (char ch : ciphertext.toCharArray()) {
            if (Character.isLetter(ch)) {
                int shift = Character.toLowerCase(key.charAt(keyIndex % key.length())) - 'a';
                char base = Character.isUpperCase(ch) ? 'A' : 'a';
                char decryptedChar = (char) ((ch - base - shift + 26) % 26 + base);
                decryptedText.append(decryptedChar);
                keyIndex++;
            }
            else {
                decryptedText.append(ch);
            }
        }
        return decryptedText.toString();
    }

    public String railFenceDecipher(String encryptedText, int rails) {
        char[][] fence = new char[rails][encryptedText.length()];
        for (int i = 0; i < rails; i++) {
            for (int j = 0; j < encryptedText.length(); j++) {
                fence[i][j] = '\0';
            }
        }

        int direction = -1;
        int row = 0, col = 0;

        for (int i = 0; i < encryptedText.length(); i++) {
            if (row == 0 || row == rails - 1) {
                direction = -direction;
            }
            fence[row][col++] = '*';
            row += direction;
        }

        int index = 0;
        for (int i = 0; i < rails; i++) {
            for (int j = 0; j < encryptedText.length(); j++) {
                if (fence[i][j] == '*') {
                    fence[i][j] = encryptedText.charAt(index++);
                }
            }
        }

        StringBuilder plainText = new StringBuilder();
        direction = -1;
        row = 0;
        col = 0;

        for (int i = 0; i < encryptedText.length(); i++) {
            if (row == 0 || row == rails - 1) {
                direction = -direction;
            }
            plainText.append(fence[row][col++]);
            row += direction;
        }

        return plainText.toString();
    }
}
