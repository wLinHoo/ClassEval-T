package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class NumberConverterTest {

    @Test
    public void testDecimalToBinary() {
        assertEquals("1010010110110111", NumberConverter.decimalToBinary(42423));
    }

    @Test
    public void testDecimalToBinary2() {
        assertEquals("101001100010111", NumberConverter.decimalToBinary(21271));
    }

    @Test
    public void testDecimalToBinary3() {
        assertEquals("1010010111010111", NumberConverter.decimalToBinary(42455));
    }

    @Test
    public void testDecimalToBinary4() {
        assertEquals("10100101110101011", NumberConverter.decimalToBinary(84907));
    }

    @Test
    public void testDecimalToBinary5() {
        assertEquals("101001011101010111", NumberConverter.decimalToBinary(169815));
    }

    @Test
    public void testBinaryToDecimal() {
        assertEquals(42423, NumberConverter.binaryToDecimal("1010010110110111"));
    }

    @Test
    public void testBinaryToDecimal2() {
        assertEquals(10615, NumberConverter.binaryToDecimal("10100101110111"));
    }

    @Test
    public void testBinaryToDecimal3() {
        assertEquals(42455, NumberConverter.binaryToDecimal("1010010111010111"));
    }

    @Test
    public void testBinaryToDecimal4() {
        assertEquals(169819, NumberConverter.binaryToDecimal("101001011101011011"));
    }

    @Test
    public void testBinaryToDecimal5() {
        assertEquals(339639, NumberConverter.binaryToDecimal("1010010111010110111"));
    }

    @Test
    public void testDecimalToOctal() {
        assertEquals("122667", NumberConverter.decimalToOctal(42423));
    }

    @Test
    public void testDecimalToOctal2() {
        assertEquals("51427", NumberConverter.decimalToOctal(21271));
    }

    @Test
    public void testDecimalToOctal3() {
        assertEquals("245653", NumberConverter.decimalToOctal(84907));
    }

    @Test
    public void testDecimalToOctal4() {
        assertEquals("513527", NumberConverter.decimalToOctal(169815));
    }

    @Test
    public void testDecimalToOctal5() {
        assertEquals("1227256", NumberConverter.decimalToOctal(339630));
    }

    @Test
    public void testOctalToDecimal() {
        assertEquals(42423, NumberConverter.octalToDecimal("122667"));
    }

    @Test
    public void testOctalToDecimal2() {
        assertEquals(21271, NumberConverter.octalToDecimal("51427"));
    }

    @Test
    public void testOctalToDecimal3() {
        assertEquals(84907, NumberConverter.octalToDecimal("245653"));
    }

    @Test
    public void testOctalToDecimal4() {
        assertEquals(169815, NumberConverter.octalToDecimal("513527"));
    }

    @Test
    public void testOctalToDecimal5() {
        assertEquals(339630, NumberConverter.octalToDecimal("1227256"));
    }

    @Test
    public void testDecimalToHex() {
        assertEquals("a5b7", NumberConverter.decimalToHex(42423));
    }

    @Test
    public void testDecimalToHex2() {
        assertEquals("5317", NumberConverter.decimalToHex(21271));
    }

    @Test
    public void testDecimalToHex3() {
        assertEquals("14bab", NumberConverter.decimalToHex(84907));
    }

    @Test
    public void testDecimalToHex4() {
        assertEquals("29757", NumberConverter.decimalToHex(169815));
    }

    @Test
    public void testDecimalToHex5() {
        assertEquals("52eb7", NumberConverter.decimalToHex(339639));
    }

    @Test
    public void testHexToDecimal() {
        assertEquals(42423, NumberConverter.hexToDecimal("a5b7"));
    }

    @Test
    public void testHexToDecimal2() {
        assertEquals(21207, NumberConverter.hexToDecimal("52d7"));
    }

    @Test
    public void testHexToDecimal3() {
        assertEquals(84627, NumberConverter.hexToDecimal("14a93"));
    }

    @Test
    public void testHexToDecimal4() {
        assertEquals(170615, NumberConverter.hexToDecimal("29a77"));
    }

    @Test
    public void testHexToDecimal5() {
        assertEquals(342647, NumberConverter.hexToDecimal("53a77"));
    }

    @Test
    public void testMain() {
        assertEquals("1010010110110111", NumberConverter.decimalToBinary(42423));
        assertEquals(42423, NumberConverter.binaryToDecimal("1010010110110111"));
        assertEquals("122667", NumberConverter.decimalToOctal(42423));
        assertEquals("122667", NumberConverter.decimalToOctal(42423));
        assertEquals("a5b7", NumberConverter.decimalToHex(42423));
        assertEquals(42423, NumberConverter.hexToDecimal("a5b7"));
    }
}