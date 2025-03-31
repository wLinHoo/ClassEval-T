package org.example;

public class BinaryDataProcessor {
    private String binaryString;

    public BinaryDataProcessor(String binaryString) {
        this.binaryString = binaryString;
        cleanNonBinaryChars();
    }

    public void cleanNonBinaryChars() {
        this.binaryString = this.binaryString.replaceAll("[^01]", "");
    }

    public BinaryInfo calculateBinaryInfo() {
        int zeroesCount = this.binaryString.length() - this.binaryString.replace("0", "").length();
        int onesCount = this.binaryString.length() - this.binaryString.replace("1", "").length();
        int totalLength = this.binaryString.length();

        double zeroesPercentage = (double) zeroesCount / totalLength;
        double onesPercentage = (double) onesCount / totalLength;

        return new BinaryInfo(zeroesPercentage, onesPercentage, totalLength);
    }

    public String convertToAscii() {
        StringBuilder asciiString = new StringBuilder();
        for (int i = 0; i < this.binaryString.length(); i += 8) {
            String byteString = this.binaryString.substring(i, i + 8);
            int decimal = Integer.parseInt(byteString, 2);
            asciiString.append((char) decimal);
        }
        return asciiString.toString();
    }

    public String convertToUtf8() {
        StringBuilder utf8String = new StringBuilder();
        for (int i = 0; i < this.binaryString.length(); i += 8) {
            String byteString = this.binaryString.substring(i, i + 8);
            int decimal = Integer.parseInt(byteString, 2);
            utf8String.append((char) decimal);
        }
        return utf8String.toString();
    }

    public String getBinaryString() {
        return this.binaryString;
    }

    public static void main(String[] args) {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0110100001100101011011000110110001101111");
        System.out.println(bdp.getBinaryString());
        System.out.println(bdp.calculateBinaryInfo());
        System.out.println(bdp.convertToAscii());
        System.out.println(bdp.convertToUtf8());
    }
}

class BinaryInfo {
    private double zeroes;
    private double ones;
    private int bitLength;

    public BinaryInfo(double zeroes, double ones, int bitLength) {
        this.zeroes = zeroes;
        this.ones = ones;
        this.bitLength = bitLength;
    }

    public double getZeroes() {
        return zeroes;
    }

    public double getOnes() {
        return ones;
    }

    public int getBitLength() {
        return bitLength;
    }

    @Override
    public String toString() {
        return String.format("{Zeroes: %.3f, Ones: %.3f, Bit length: %d}", zeroes, ones, bitLength);
    }
}