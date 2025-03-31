package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class DecryptionUtilsTest {

    @Test
    void testCaesarDecipher() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("hello", d.caesarDecipher("ifmmp", 1));
    }

    @Test
    void testCaesarDecipher2() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("abcxyz", d.caesarDecipher("bcdyza", 27));
    }

    @Test
    void testCaesarDecipher3() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("bcd", d.caesarDecipher("bcd", 0));
    }

    @Test
    void testCaesarDecipher4() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("bcd", d.caesarDecipher("bcd", 26));
    }

    @Test
    void testCaesarDecipher5() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("bcd", d.caesarDecipher("bcd", -26));
    }

    @Test
    void testCaesarDecipher6() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("HELLO", d.caesarDecipher("IFMMP", 1));
    }

    @Test
    void testCaesarDecipher7() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("123", d.caesarDecipher("123", 1));
    }

    @Test
    void testVigenereDecipher() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("ybocl", d.vigenereDecipher("ifmmp"));
    }

    @Test
    void testVigenereDecipher2() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("hello", d.vigenereDecipher("rijvs"));
    }

    @Test
    void testVigenereDecipher3() {
        DecryptionUtils d = new DecryptionUtils("longkey");
        assertEquals("AbCdEfG", d.vigenereDecipher("LpPjOjE"));
    }

    @Test
    void testVigenereDecipher4() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("ryf", d.vigenereDecipher("bcd"));
    }

    @Test
    void testVigenereDecipher5() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("ryfqw", d.vigenereDecipher("bcdaa"));
    }

    @Test
    void testVigenereDecipher6() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("123", d.vigenereDecipher("123"));
    }

    @Test
    void testRailFenceDecipher() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("Hello, World!", d.railFenceDecipher("Hoo!el,Wrdl l", 3));
    }

    @Test
    void testRailFenceDecipher2() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("H!W reoldll,o", d.railFenceDecipher("Hoo!el,Wrdl l", 4));
    }

    @Test
    void testRailFenceDecipher3() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("Holr d,!oeWll", d.railFenceDecipher("Hoo!el,Wrdl l", 5));
    }

    @Test
    void testRailFenceDecipher4() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("Holrll d,!oeW", d.railFenceDecipher("Hoo!el,Wrdl l", 6));
    }

    @Test
    void testRailFenceDecipher5() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("Hoe,rll dWl!o", d.railFenceDecipher("Hoo!el,Wrdl l", 7));
    }

    @Test
    void testMain() {
        DecryptionUtils d = new DecryptionUtils("key");
        assertEquals("hello", d.caesarDecipher("ifmmp", 1));
        assertEquals("ybocl", d.vigenereDecipher("ifmmp"));
        assertEquals("Hello, World!", d.railFenceDecipher("Hoo!el,Wrdl l", 3));
    }
}
