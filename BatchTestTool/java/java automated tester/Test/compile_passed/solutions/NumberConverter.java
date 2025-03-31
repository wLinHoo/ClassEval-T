public class NumberConverter {

    public static int binaryToDecimal(String binaryNum) {
        return Integer.parseInt(binaryNum, 2);
    }

    public static String decimalToOctal(int decimalNum) {
        return Integer.toOctalString(decimalNum);
    }

    public static int octalToDecimal(String octalNum) {
        int decimalNum = Integer.parseInt(octalNum, 8);
        return decimalNum;
    }

    public static String decimalToHex(int decimalNum) {
        String hexNum = Integer.toHexString(decimalNum);
        return hexNum;
    }

    public static int hexToDecimal(String hexNum) {
        int decimalNum = Integer.parseInt(hexNum, 16);
        return decimalNum;
    }

    public static String decimalToBinary(int decimalNum) {
        String binaryNum = Integer.toBinaryString(decimalNum);
        return binaryNum;
    }

    public static void main(String[] args) {
        int decimalNum = 10;
        System.out.println("Octal representation of " + decimalNum + " is " + decimalToOctal(decimalNum));

        String octalNum = "12"; // example octal number
        int decimalNum2 = octalToDecimal(octalNum);
        System.out.println("Decimal number: " + decimalNum2);

        String binaryNum = decimalToBinary(decimalNum);
        System.out.println("Binary representation of " + decimalNum + " is " + binaryNum);
    }
}