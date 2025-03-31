package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class BinaryDataProcessorTest {

    @org.junit.Test
    @Test
    public void testCleanNonBinaryChars() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("01101000daf3e4r01100101011011000110110001101111");
        assertEquals("0110100001100101011011000110110001101111", bdp.getBinaryString());
    }

    @Test
    public void testCleanNonBinaryChars2() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("01101000daf3e4r01100101011011addf0110001d1111");
        assertEquals("011010000110010101101101100011111", bdp.getBinaryString());
    }

    @Test
    public void testCleanNonBinaryChars3() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0sd1000daf3e4r01100101011011addf0110001d1111");
        assertEquals("010000110010101101101100011111", bdp.getBinaryString());
    }

    @Test
    public void testCleanNonBinaryChars4() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("sdsdf");
        assertEquals("", bdp.getBinaryString());
    }

    @Test
    public void testCleanNonBinaryChars5() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0");
        assertEquals("0", bdp.getBinaryString());
    }

    @Test
    public void testCalculateBinaryInfo() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0110100001100101011011000110110001101111");
        BinaryInfo info = bdp.calculateBinaryInfo();
        assertEquals(0.475, info.getZeroes(), 0.001);
        assertEquals(0.525, info.getOnes(), 0.001);
        assertEquals(40, info.getBitLength());
    }

    @Test
    public void testCalculateBinaryInfo2() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0110100001100101011010011111");
        BinaryInfo info = bdp.calculateBinaryInfo();
        assertEquals(0.4642857142857143, info.getZeroes(), 0.001);
        assertEquals(0.5357142857142857, info.getOnes(), 0.001);
        assertEquals(28, info.getBitLength());
    }

    @Test
    public void testCalculateBinaryInfo3() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("01101001111100101011010011111");
        BinaryInfo info = bdp.calculateBinaryInfo();
        assertEquals(0.3793103448275862, info.getZeroes(), 0.001);
        assertEquals(0.6206896551724138, info.getOnes(), 0.001);
        assertEquals(29, info.getBitLength());
    }

    @Test
    public void testCalculateBinaryInfo4() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("011010011111001");
        BinaryInfo info = bdp.calculateBinaryInfo();
        assertEquals(0.4, info.getZeroes(), 0.001);
        assertEquals(0.6, info.getOnes(), 0.001);
        assertEquals(15, info.getBitLength());
    }

    @Test
    public void testCalculateBinaryInfo5() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0110100111110010");
        BinaryInfo info = bdp.calculateBinaryInfo();
        assertEquals(0.4375, info.getZeroes(), 0.001);
        assertEquals(0.5625, info.getOnes(), 0.001);
        assertEquals(16, info.getBitLength());
    }

    @Test
    public void testConvertToAscii() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0110100001100101011011000110110001101111");
        assertEquals("hello", bdp.convertToAscii());
    }

    @Test
    public void testConvertToAscii2() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0110100000100101011011000110110001101111");
        assertEquals("h%llo", bdp.convertToAscii());
    }

    @Test
    public void testConvertToAscii3() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("01101000011011010110001001101111");
        assertEquals("hmbo", bdp.convertToAscii());
    }

    @Test
    public void testConvertToAscii4() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("01101000011001010110001001101111");
        assertEquals("hebo", bdp.convertToAscii());
    }

    @Test
    public void testConvertToAscii5() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0110100001100101011011000110110001101111");
        assertEquals("hello", bdp.convertToAscii());
    }

    @Test
    public void testConvertToUtf8() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0110100001100101011011000110110001101111");
        assertEquals("hello", bdp.convertToUtf8());
    }

    @Test
    public void testConvertToUtf82() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0110100001100101011011000110110001101001");
        assertEquals("helli", bdp.convertToUtf8());
    }

    @Test
    public void testConvertToUtf83() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0110000001100101011011000110110001101111");
        assertEquals("`ello", bdp.convertToUtf8());
    }

    @Test
    public void testConvertToUtf84() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0110101101100101011011000110110001101111");
        assertEquals("kello", bdp.convertToUtf8());
    }

    @Test
    public void testConvertToUtf85() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("0110101101100100011011000110110001101111");
        assertEquals("kdllo", bdp.convertToUtf8());
    }

    @Test
    public void testMain() {
        BinaryDataProcessor bdp = new BinaryDataProcessor("01101000daf3e4r01100101011011000110110001101111");
        assertEquals("0110100001100101011011000110110001101111", bdp.getBinaryString());
        BinaryInfo info = bdp.calculateBinaryInfo();
        assertEquals(0.475, info.getZeroes(), 0.001);
        assertEquals(0.525, info.getOnes(), 0.001);
        assertEquals(40, info.getBitLength());
        assertEquals("hello", bdp.convertToAscii());
        assertEquals("hello", bdp.convertToUtf8());
    }
}