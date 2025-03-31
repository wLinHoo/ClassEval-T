package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class EncryptionUtilsTest {

    private final EncryptionUtils encryptionUtils = new EncryptionUtils("key");

    @Test
    public void testCaesarCipher() {
        assertEquals("bcd", encryptionUtils.caesarCipher("abc", 1));
    }

    @Test
    public void testCaesarCipher2() {
        assertEquals("UMPJB", encryptionUtils.caesarCipher("WORLD", -2));
    }

    @Test
    public void testCaesarCipher3() {
        assertEquals("", encryptionUtils.caesarCipher("", 4));
    }

    @Test
    public void testCaesarCipher4() {
        assertEquals("abcxyz", encryptionUtils.caesarCipher("abcxyz", 26));
    }

    @Test
    public void testCaesarCipher5() {
        assertEquals("bcdyza", encryptionUtils.caesarCipher("abcxyz", 27));
    }

    @Test
    public void testCaesarCipher6() {
        assertEquals("123", encryptionUtils.caesarCipher("123", 27));
    }

    @Test
    public void testVigenereCipher() {
        assertEquals("kfa", encryptionUtils.vigenereCipher("abc"));
    }

    @Test
    public void testVigenereCipher2() {
        assertEquals("rijvs", encryptionUtils.vigenereCipher("hello"));
    }

    @Test
    public void testVigenereCipher3() {
        EncryptionUtils encryptionUtilsLongKey = new EncryptionUtils("longkey");
        assertEquals("LpPjOjE", encryptionUtilsLongKey.vigenereCipher("AbCdEfG"));
    }

    @Test
    public void testVigenereCipher4() {
        assertEquals("Rijvs, Uyvjn! 123", encryptionUtils.vigenereCipher("Hello, World! 123"));
    }

    @Test
    public void testVigenereCipher5() {
        assertEquals("", encryptionUtils.vigenereCipher(""));
    }

    @Test
    public void testRailFenceCipher() {
        assertEquals("acb", encryptionUtils.railFenceCipher("abc", 2));
    }

    @Test
    public void testRailFenceCipher2() {
        assertEquals("hloel", encryptionUtils.railFenceCipher("hello", 2));
    }

    @Test
    public void testRailFenceCipher3() {
        EncryptionUtils encryptionUtilsLongKey = new EncryptionUtils("longkey");
        assertEquals("ACEGbdf", encryptionUtilsLongKey.railFenceCipher("AbCdEfG", 2));
    }

    @Test
    public void testRailFenceCipher4() {
        assertEquals("Hlo ol!13el,Wrd 2", encryptionUtils.railFenceCipher("Hello, World! 123", 2));
    }

    @Test
    public void testRailFenceCipher5() {
        assertEquals("", encryptionUtils.railFenceCipher("", 2));
    }

    @Test
    public void testRailFenceCipher6() {
        assertEquals("aebdfcg", encryptionUtils.railFenceCipher("abcdefg", 3));
    }

    @Test
    public void testMain() {
        assertEquals("bcd", encryptionUtils.caesarCipher("abc", 1));
        assertEquals("kfa", encryptionUtils.vigenereCipher("abc"));
        assertEquals("acb", encryptionUtils.railFenceCipher("abc", 2));
    }
}
