package org.example;

public class NumberConverter {

    public static String decimalToBinary(int decimalNum) {
        return Integer.toBinaryString(decimalNum);
    }

    public static int binaryToDecimal(String binaryNum) {
        return Integer.parseInt(binaryNum, 2);
    }

    public static String decimalToOctal(int decimalNum) {
        return Integer.toOctalString(decimalNum);
    }

    public static int octalToDecimal(String octalNum) {
        return Integer.parseInt(octalNum, 8);
    }

    public static String decimalToHex(int decimalNum) {
        return Integer.toHexString(decimalNum);
    }

    public static int hexToDecimal(String hexNum) {
        return Integer.parseInt(hexNum, 16);
    }
}