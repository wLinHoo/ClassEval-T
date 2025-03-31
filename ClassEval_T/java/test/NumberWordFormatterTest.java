package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class NumberWordFormatterTest {

    @Test
    public void testFormat1() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ONE HUNDRED AND TWENTY THREE THOUSAND FOUR HUNDRED AND FIFTY SIX ONLY", formatter.format(123456));
    }

    @Test
    public void testFormat2() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ONE THOUSAND ONLY", formatter.format(1000));
    }

    @Test
    public void testFormat3() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ONE MILLION ONLY", formatter.format(1000000));
    }

    @Test
    public void testFormat4() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ONE AND CENTS TWENTY THREE ONLY", formatter.format(1.23));
    }

    @Test
    public void testFormat5() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ZERO ONLY", formatter.format(0));
    }

    @Test
    public void testFormat6() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("", formatter.format(null));
    }

    @Test
    public void testFormatString1() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ONE HUNDRED AND TWENTY THREE THOUSAND FOUR HUNDRED AND FIFTY SIX ONLY", formatter.formatString("123456"));
    }

    @Test
    public void testFormatString2() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ONE THOUSAND ONLY", formatter.formatString("1000"));
    }

    @Test
    public void testFormatString3() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ONE MILLION ONLY", formatter.formatString("1000000"));
    }

    @Test
    public void testFormatString4() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ONE AND CENTS TWENTY THREE ONLY", formatter.formatString("1.23"));
    }

    @Test
    public void testFormatString5() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ZERO ONLY", formatter.formatString("0"));
    }

    @Test
    public void testFormatString6() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("TEN ONLY", formatter.formatString("10"));
    }

    @Test
    public void testTransTwo1() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("TWENTY THREE", formatter.transTwo("23"));
    }

    @Test
    public void testTransTwo2() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("TEN", formatter.transTwo("10"));
    }

    @Test
    public void testTransTwo3() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("FIVE", formatter.transTwo("05"));
    }

    @Test
    public void testTransTwo4() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("", formatter.transTwo("00"));
    }

    @Test
    public void testTransTwo5() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ONE", formatter.transTwo("01"));
    }

    @Test
    public void testTransTwo6() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("EIGHTY", formatter.transTwo("80"));
    }

    @Test
    public void testTransThree1() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ONE HUNDRED AND TWENTY THREE", formatter.transThree("123"));
    }

    @Test
    public void testTransThree2() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("NINE HUNDRED", formatter.transThree("900"));
    }

    @Test
    public void testTransThree3() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("SEVEN", formatter.transThree("007"));
    }

    @Test
    public void testTransThree4() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ONE", formatter.transThree("001"));
    }

    @Test
    public void testTransThree5() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("SIX", formatter.transThree("006"));
    }

    @Test
    public void testParseMore1() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("", formatter.parseMore(0));
    }

    @Test
    public void testParseMore2() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("THOUSAND", formatter.parseMore(1));
    }

    @Test
    public void testParseMore3() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("MILLION", formatter.parseMore(2));
    }

    @Test
    public void testParseMore4() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("BILLION", formatter.parseMore(3));
    }

    @Test
    public void testNumberWordFormatter() {
        NumberWordFormatter formatter = new NumberWordFormatter();
        assertEquals("ONE HUNDRED AND TWENTY THREE THOUSAND FOUR HUNDRED AND FIFTY SIX ONLY", formatter.format(123456));

        formatter = new NumberWordFormatter();
        assertEquals("ONE HUNDRED AND TWENTY THREE THOUSAND FOUR HUNDRED AND FIFTY SIX ONLY", formatter.formatString("123456"));

        formatter = new NumberWordFormatter();
        assertEquals("TWENTY THREE", formatter.transTwo("23"));

        formatter = new NumberWordFormatter();
        assertEquals("ONE HUNDRED AND TWENTY THREE", formatter.transThree("123"));

        formatter = new NumberWordFormatter();
        assertEquals("THOUSAND", formatter.parseMore(1));
    }
}