package test_cases;
import to_be_tested.Manacher;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.Test;

public class ManacherTest {

    @Test
    public void testPalindromicLength() {
        Manacher manacher = new Manacher("ababa");
        assertEquals(2, manacher.palindromicLength("a|b|a|b|a", 2));
    }

    @Test
    public void testPalindromicLength2() {
        Manacher manacher = new Manacher("ababaxse");
        assertEquals(2, manacher.palindromicLength("a|b|a|b|a|x|s|e", 2));
    }

    @Test
    public void testPalindromicLength3() {
        Manacher manacher = new Manacher("ababax");
        assertEquals(2, manacher.palindromicLength("a|b|a|b|a|x", 2));
    }

    @Test
    public void testPalindromicLength4() {
        Manacher manacher = new Manacher("ababax");
        assertEquals(0, manacher.palindromicLength("a|b|a|b|a|x", 9));
    }

    @Test
    public void testPalindromicLength5() {
        Manacher manacher = new Manacher("ababax");
        assertEquals(4, manacher.palindromicLength("a|b|a|b|a|x", 4));
    }

    @Test
    public void testPalindromicString() {
        Manacher manacher = new Manacher("ababaxse");
        assertEquals("ababa", manacher.palindromicString());
    }

    @Test
    public void testPalindromicString2() {
        Manacher manacher = new Manacher("ababax");
        assertEquals("ababa", manacher.palindromicString());
    }

    @Test
    public void testPalindromicString3() {
        Manacher manacher = new Manacher("ababax");
        assertEquals("ababa", manacher.palindromicString());
    }

    @Test
    public void testPalindromicString4() {
        Manacher manacher = new Manacher("ababaxssss");
        assertEquals("ababa", manacher.palindromicString());
    }

    @Test
    public void testPalindromicString5() {
        Manacher manacher = new Manacher("abab");
        assertEquals("aba", manacher.palindromicString());
    }

    @Test
    public void testMain() {
        Manacher manacher = new Manacher("ababa");
        assertEquals(2, manacher.palindromicLength("a|b|a|b|a", 2));
        assertEquals("ababa", manacher.palindromicString());
    }
}
