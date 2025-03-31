import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;

public class BinaryDataProcessor {
    private String binaryString;

    public BinaryDataProcessor(String binaryString) {
        this.binaryString = binaryString;
        cleanNonBinaryChars();
    }

    private void cleanNonBinaryChars() {
        StringBuilder cleanedString = new StringBuilder();
        for (char c : binaryString.toCharArray()) {
            if (c == '0' || c == '1') {
                cleanedString.append(c);
            }
        }
        binaryString = cleanedString.toString();
    }

    public String convertToAscii() {
        StringBuilder asciiString = new StringBuilder();
        for (int i = 0; i < binaryString.length(); i += 8) {
            String byteString = binaryString.substring(i, Math.min(i + 8, binaryString.length()));
            int decimal = Integer.parseInt(byteString, 2);
            asciiString.append((char) decimal);
        }
        return asciiString.toString();
    }

    public String convertToUtf8() {
        int length = binaryString.length();
        byte[] byteArray = new byte[(length + 7) / 8]; // Round up to the nearest byte

        for (int i = 0; i < length; i += 8) {
            String byteString = binaryString.substring(i, Math.min(i + 8, length));
            int decimal = Integer.parseInt(byteString, 2);
            byteArray[i / 8] = (byte) decimal;
        }

        return new String(byteArray, StandardCharsets.UTF_8);
    }

    public Map<String, Double> calculateBinaryInfo() {
        int zeroesCount = 0;
        int onesCount = 0;
        for (char c : binaryString.toCharArray()) {
            if (c == '0') {
                zeroesCount++;
            } else if (c == '1') {
                onesCount++;
            }
        }

        int totalLength = binaryString.length();

        double zeroesPercentage = (double) zeroesCount / totalLength;
        double onesPercentage = (double) onesCount / totalLength;

        Map<String, Double> binaryInfo = new HashMap<>();
        binaryInfo.put("Zeroes", zeroesPercentage);
        binaryInfo.put("Ones", onesPercentage);
        binaryInfo.put("Bit length", (double) totalLength);

        return binaryInfo;
    }

    public String getBinaryString() {
        return binaryString;
    }

    public static void main(String[] args) {
        String binaryInput = "010010000110010101101100011011000110111100111111"; // Example binary string
        BinaryDataProcessor processor = new BinaryDataProcessor(binaryInput);
        System.out.println("Cleaned Binary String: " + processor.getBinaryString());
        System.out.println("Converted ASCII String: " + processor.convertToAscii());

        BinaryDataProcessor processor2 = new BinaryDataProcessor("0100100001100101011011000110110001101111");
        String result = processor2.convertToUtf8();
        System.out.println(result);

        BinaryDataProcessor processor3 = new BinaryDataProcessor("101100abc010");
        Map<String, Double> info = processor3.calculateBinaryInfo();
        System.out.println("Zeroes: " + info.get("Zeroes"));
        System.out.println("Ones: " + info.get("Ones"));
        System.out.println("Bit length: " + info.get("Bit length"));
    }
}