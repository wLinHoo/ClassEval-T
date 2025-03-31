package test_cases;
import to_be_tested.NumericEntityUnescaper;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class NumericEntityUnescaperTest {

    @Test
    public void testReplace1() {
        NumericEntityUnescaper unescaper = new NumericEntityUnescaper();
        String res = unescaper.replace("&#65;&#66;&#67;");
        assertEquals("ABC", res);
    }

    @Test
    public void testReplace2() {
        NumericEntityUnescaper unescaper = new NumericEntityUnescaper();
        String res = unescaper.replace("&#65;&#65;&#65;");
        assertEquals("AAA", res);
    }

    @Test
    public void testReplace3() {
        NumericEntityUnescaper unescaper = new NumericEntityUnescaper();
        String res = unescaper.replace("&#66;&#66;&#66;");
        assertEquals("BBB", res);
    }

    @Test
    public void testReplace4() {
        NumericEntityUnescaper unescaper = new NumericEntityUnescaper();
        String res = unescaper.replace("&#67;&#67;&#67;");
        assertEquals("CCC", res);
    }

    @Test
    public void testReplace5() {
        NumericEntityUnescaper unescaper = new NumericEntityUnescaper();
        String res = unescaper.replace("");
        assertEquals("", res);
    }

    @Test
    public void testReplace6() {
        NumericEntityUnescaper unescaper = new NumericEntityUnescaper();
        String res = unescaper.replace("&#");
        assertEquals("", res);
    }

    @Test
    public void testReplace7() {
        NumericEntityUnescaper unescaper = new NumericEntityUnescaper();
        String res = unescaper.replace("&#X65;&#66;&#67;");
        assertEquals("eBC", res);
    }

    @Test
    public void testReplace8() {
        NumericEntityUnescaper unescaper = new NumericEntityUnescaper();
        String res = unescaper.replace("&#???;&#66;&#67;");
        assertEquals("&#???;BC", res);
    }

    @Test
    public void testReplace9() {
        NumericEntityUnescaper unescaper = new NumericEntityUnescaper();
        String res = unescaper.replace("&#67;&#67;&#67;;");
        assertEquals("CCC", res);
    }

    @Test
    public void testReplace10() {
        NumericEntityUnescaper unescaper = new NumericEntityUnescaper();
        String res = unescaper.replace("&#X");
        assertEquals("", res);
    }

    @Test
    public void testReplace11() {
        NumericEntityUnescaper unescaper = new NumericEntityUnescaper();
        String res = unescaper.replace("&#c1d;&#66;&#67;");
        assertEquals("", res);
    }

    @Test
    public void testIsHexChar1() {
        boolean res = NumericEntityUnescaper.isHexChar('0');
        assertTrue(res);
    }

    @Test
    public void testIsHexChar2() {
        boolean res = NumericEntityUnescaper.isHexChar('F');
        assertTrue(res);
    }

    @Test
    public void testIsHexChar3() {
        boolean res = NumericEntityUnescaper.isHexChar('G');
        assertFalse(res);
    }

    @Test
    public void testIsHexChar4() {
        boolean res = NumericEntityUnescaper.isHexChar('X');
        assertFalse(res);
    }

    @Test
    public void testIsHexChar5() {
        boolean res = NumericEntityUnescaper.isHexChar('Z');
        assertFalse(res);
    }

    @Test
    public void testNumericEntityUnescaper() {
        NumericEntityUnescaper unescaper = new NumericEntityUnescaper();
        String res = unescaper.replace("&#65;&#66;&#67;");
        assertEquals("ABC", res);

        boolean hexRes = NumericEntityUnescaper.isHexChar('0');
        assertTrue(hexRes);
    }
}