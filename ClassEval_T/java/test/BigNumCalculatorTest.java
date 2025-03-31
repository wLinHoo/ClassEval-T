package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class BigNumCalculatorTest {

    @Test
    public void testAdd() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("111111111011111111100", bigNum.add("12345678901234567890", "98765432109876543210"));
    }

    @Test
    public void testAdd2() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("222222221122222222132", bigNum.add("123456789012345678922", "98765432109876543210"));
    }

    @Test
    public void testAdd3() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("222222221122222222144", bigNum.add("123456789012345678934", "98765432109876543210"));
    }

    @Test
    public void testAdd4() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("222222221122222222156", bigNum.add("123456789012345678946", "98765432109876543210"));
    }

    @Test
    public void testAdd5() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("222222221122222222168", bigNum.add("123456789012345678958", "98765432109876543210"));
    }

    @Test
    public void testSubtract() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("-86419753208641975320", bigNum.subtract("12345678901234567890", "98765432109876543210"));
    }

    @Test
    public void testSubtract2() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("24691356902469135712", bigNum.subtract("123456789012345678922", "98765432109876543210"));
    }

    @Test
    public void testSubtract3() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("123358023580235802391", bigNum.subtract("123456789012345678934", "98765432109876543"));
    }

    @Test
    public void testSubtract4() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("-98753086430975308643", bigNum.subtract("12345678901234567", "98765432109876543210"));
    }

    @Test
    public void testSubtract5() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("735802468", bigNum.subtract("923456789", "187654321"));
    }

    @Test
    public void testMultiply() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("1219326311370217952237463801111263526900", bigNum.multiply("12345678901234567890", "98765432109876543210"));
    }

    @Test
    public void testMultiply2() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("12193263113702179524547477517529919219620", bigNum.multiply("123456789012345678922", "98765432109876543210"));
    }

    @Test
    public void testMultiply3() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("12193263113702179499806737010255845162", bigNum.multiply("123456789012345678934", "98765432109876543"));
    }

    @Test
    public void testMultiply4() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("1219326311370217864336229223321140070", bigNum.multiply("12345678901234567", "98765432109876543210"));
    }

    @Test
    public void testMultiply5() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("173290656712635269", bigNum.multiply("923456789", "187654321"));
    }

    @Test
    public void testMultiply6() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("1", bigNum.multiply("000000001", "000000001"));
    }

    @Test
    public void testMain() {
        BigNumCalculator bigNum = new BigNumCalculator();
        assertEquals("111111111011111111100", bigNum.add("12345678901234567890", "98765432109876543210"));
        assertEquals("-86419753208641975320", bigNum.subtract("12345678901234567890", "98765432109876543210"));
        assertEquals("1219326311370217952237463801111263526900", bigNum.multiply("12345678901234567890", "98765432109876543210"));
    }
}