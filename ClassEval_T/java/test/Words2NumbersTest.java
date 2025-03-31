package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class Words2NumbersTest {

    @Test
    public void testText2Int() {
        Words2Numbers w2n = new Words2Numbers();
        assertEquals("32", w2n.text2int("thirty-two"));
    }

    @Test
    public void testText2Int2() {
        Words2Numbers w2n = new Words2Numbers();
        assertEquals("123", w2n.text2int("one hundred and twenty-three"));
    }

    @Test
    public void testText2Int3() {
        Words2Numbers w2n = new Words2Numbers();
        assertEquals("2019", w2n.text2int("two thousand and nineteen"));
    }

    @Test
    public void testText2Int4() {
        Words2Numbers w2n = new Words2Numbers();
        assertEquals("101", w2n.text2int("one hundred and one"));
    }

    @Test
    public void testText2Int5() {
        Words2Numbers w2n = new Words2Numbers();
        assertEquals("1000011", w2n.text2int("one million and eleven"));
    }

    @Test
    public void testText2Int6() {
        Words2Numbers w2n = new Words2Numbers();
        assertEquals("1000169", w2n.text2int("one million one hundred sixty-ninth"));
    }

    @Test
    public void testIsValidInput() {
        Words2Numbers w2n = new Words2Numbers();
        assertTrue(w2n.isValidInput("twenty-five thousand three hundred and forty-two"));
    }

    @Test
    public void testIsValidInput2() {
        Words2Numbers w2n = new Words2Numbers();
        assertTrue(w2n.isValidInput("second hundred and third"));
    }

    @Test
    public void testIsValidInput3() {
        Words2Numbers w2n = new Words2Numbers();
        assertTrue(w2n.isValidInput("twenty-fifth thousand three hundred and forty-second"));
    }

    @Test
    public void testIsValidInput4() {
        Words2Numbers w2n = new Words2Numbers();
        assertFalse(w2n.isValidInput("eleventy thousand and five"));
    }

    @Test
    public void testIsValidInput5() {
        Words2Numbers w2n = new Words2Numbers();
        assertTrue(w2n.isValidInput("seventy two thousand and hundred eleven"));
    }

    @Test
    public void testIsValidInput6() {
        Words2Numbers w2n = new Words2Numbers();
        assertTrue(w2n.isValidInput("fifteenth hundred"));
    }

    @Test
    public void testMain() {
        Words2Numbers w2n = new Words2Numbers();
        assertTrue(w2n.isValidInput("seventy two thousand and hundred eleven"));
        assertEquals("72011", w2n.text2int("seventy two thousand and hundred eleven"));
    }
}