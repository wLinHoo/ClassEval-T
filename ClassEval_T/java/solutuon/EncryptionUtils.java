package org.example;

public class EncryptionUtils {
    private String key;

    public EncryptionUtils(String key) {
        this.key = key;
    }

    public String caesarCipher(String plaintext, int shift) {
        StringBuilder ciphertext = new StringBuilder();
        for (char c : plaintext.toCharArray()) {
            if (Character.isLetter(c)) {
                int asciiOffset = Character.isUpperCase(c) ? 'A' : 'a';
                char shiftedChar = (char) ((c - asciiOffset + shift) % 26 + asciiOffset);
                ciphertext.append(shiftedChar);
            }
            else {
                ciphertext.append(c);
            }
        }
        return ciphertext.toString();
    }

    public String vigenereCipher(String plainText) {
        StringBuilder encryptedText = new StringBuilder();
        int keyIndex = 0;
        for (char c : plainText.toCharArray()) {
            if (Character.isLetter(c)) {
                int shift = Character.toLowerCase(key.charAt(keyIndex % key.length())) - 'a';
                char encryptedChar = (char) ((Character.toLowerCase(c) - 'a' + shift) % 26 + 'a');
                encryptedText.append(Character.isUpperCase(c) ? Character.toUpperCase(encryptedChar) : encryptedChar);
                keyIndex++;
            }
            else {
                encryptedText.append(c);
            }
        }
        return encryptedText.toString();
    }

    public String railFenceCipher(String plainText, int rails) {
        char[][] fence = new char[rails][plainText.length()];
        for (char[] row : fence) {
            java.util.Arrays.fill(row, '\n');
        }

        int direction = -1;
        int row = 0, col = 0;

        for (char c : plainText.toCharArray()) {
            if (row == 0 || row == rails - 1) {
                direction = -direction;
            }

            fence[row][col] = c;
            col++;
            row += direction;
        }

        StringBuilder encryptedText = new StringBuilder();
        for (int i = 0; i < rails; i++) {
            for (int j = 0; j < plainText.length(); j++) {
                if (fence[i][j] != '\n') {
                    encryptedText.append(fence[i][j]);
                }
            }
        }
        return encryptedText.toString();
    }
}
