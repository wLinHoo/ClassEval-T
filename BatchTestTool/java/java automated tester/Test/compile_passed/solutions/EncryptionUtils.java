public class EncryptionUtils {

    private String key;

    public EncryptionUtils(String key) {
        this.key = key;
    }

    public String vigenereCipher(String plainText) {
        String encryptedText = "";
        int keyIndex = 0;
        for (char c : plainText.toCharArray()) {
            if (Character.isLetter(c)) {
                int shift = getShift(keyIndex);
                char encryptedChar = getEncryptedChar(c, shift);
                encryptedText += encryptedChar;
                keyIndex = (keyIndex + 1) % key.length();
            } else {
                encryptedText += c;
            }
        }
        return encryptedText;
    }

    public String railFenceCipher(String plainText, int rails) {
        char[][] fence = new char[rails][plainText.length()];
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

    public String caesarCipher(String plaintext, int shift) {
        StringBuilder ciphertext = new StringBuilder();
        for (char c : plaintext.toCharArray()) {
            if (Character.isLetter(c)) {
                int asciiOffset = Character.isUpperCase(c) ? 65 : 97;
                char shiftedChar = (char) ((c - asciiOffset + shift) % 26 + asciiOffset);
                ciphertext.append(shiftedChar);
            } else {
                ciphertext.append(c);
            }
        }
        return ciphertext.toString();
    }

    private int getShift(int keyIndex) {
        return (int) (key.charAt(keyIndex % key.length()) - 'a');
    }

    private char getEncryptedChar(char c, int shift) {
        char baseChar = Character.isUpperCase(c) ? 'A' : 'a';
        return (char) (((c - baseChar + shift) % 26 + baseChar));
    }
}