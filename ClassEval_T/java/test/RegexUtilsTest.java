package org.example;

import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class RegexUtilsTestMatch {

    @Test
    void testMatch1() {
        RegexUtils ru = new RegexUtils();
        boolean res = ru.match("\\b\\d{3}-\\d{3}-\\d{4}\\b", "123-456-7890");
        assertTrue(res);
    }

    @Test
    void testMatch2() {
        RegexUtils ru = new RegexUtils();
        boolean res = ru.match("\\b\\d{3}-\\d{3}-\\d{4}\\b", "1234567890");
        assertFalse(res);
    }

    @Test
    void testMatch3() {
        RegexUtils ru = new RegexUtils();
        boolean res = ru.match("\\b\\d{3}-\\d{3}-\\d{4}\\b", "111-111-1111");
        assertTrue(res);
    }

    @Test
    void testMatch4() {
        RegexUtils ru = new RegexUtils();
        boolean res = ru.match("\\b\\d{3}-\\d{3}-\\d{4}\\b", "123-456-789");
        assertFalse(res);
    }

    @Test
    void testMatch5() {
        RegexUtils ru = new RegexUtils();
        boolean res = ru.match("\\b\\d{3}-\\d{3}-\\d{4}\\b", "123-456-789a");
        assertFalse(res);
    }
}

class RegexUtilsTestFindall {

    @Test
    void testFindall1() {
        RegexUtils ru = new RegexUtils();
        List<String> res = ru.findall("\\b\\d{3}-\\d{3}-\\d{4}\\b", "123-456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
        assertEquals(Arrays.asList("123-456-7890", "876-286-9876", "987-762-9767"), res);
    }

    @Test
    void testFindall2() {
        RegexUtils ru = new RegexUtils();
        List<String> res = ru.findall("\\b\\d{3}-\\d{3}-\\d{4}\\b", "abiguygusu kjgufwycs 987-762-9767");
        assertEquals(Arrays.asList("987-762-9767"), res);
    }

    @Test
    void testFindall3() {
        RegexUtils ru = new RegexUtils();
        List<String> res = ru.findall("\\b\\d{3}-\\d{3}-\\d{4}\\b", "abiguygusu kjgufwycs ");
        assertEquals(Collections.emptyList(), res);
    }

    @Test
    void testFindall4() {
        RegexUtils ru = new RegexUtils();
        List<String> res = ru.findall("\\b\\d{3}-\\d{3}-\\d{4}\\b", "abiguygusu 111-111-1111 kjgufwycs 987-762-9767");
        assertEquals(Arrays.asList("111-111-1111", "987-762-9767"), res);
    }

    @Test
    void testFindall5() {
        RegexUtils ru = new RegexUtils();
        List<String> res = ru.findall("\\b\\d{3}-\\d{3}-\\d{4}\\b", "abiguygusu 111-111-111a kjgufwycs 987-762-9767");
        assertEquals(Arrays.asList("987-762-9767"), res);
    }
}

class RegexUtilsTestSplit {

    @Test
    void testSplit1() {
        RegexUtils ru = new RegexUtils();
        String[] res = ru.split("\\b\\d{3}-\\d{3}-\\d{4}\\b", "123-456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767").toArray(new String[0]);
        assertArrayEquals(new String[]{"", " abiguygusu ", " kjgufwycs ", ""}, res);
    }

    @Test
    void testSplit2() {
        RegexUtils ru = new RegexUtils();
        String[] res = ru.split("\\b\\d{3}-\\d{3}-\\d{4}\\b", "1234567890 abiguygusu 8762869876 kjgufwycs 9877629767").toArray(new String[0]);
        assertArrayEquals(new String[]{"1234567890 abiguygusu 8762869876 kjgufwycs 9877629767"}, res);
    }

    @Test
    void testSplit3() {
        RegexUtils ru = new RegexUtils();
        String[] res = ru.split("\\b\\d{3}-\\d{3}-\\d{4}\\b", "111-111-1111 abiguygusu 876-286-9876 kjgufwycs 987-762-9767").toArray(new String[0]);
        assertArrayEquals(new String[]{"", " abiguygusu ", " kjgufwycs ", ""}, res);
    }

    @Test
    void testSplit4() {
        RegexUtils ru = new RegexUtils();
        String[] res = ru.split("\\b\\d{3}-\\d{3}-\\d{4}\\b", "123456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767").toArray(new String[0]);
        assertArrayEquals(new String[]{"123456-7890 abiguygusu ", " kjgufwycs ", ""}, res);
    }

    @Test
    void testSplit5() {
        RegexUtils ru = new RegexUtils();
        String[] res = ru.split("\\b\\d{3}-\\d{3}-\\d{4}\\b", "123-456-789a abiguygusu 876-286-9876 kjgufwycs 987-762-9767").toArray(new String[0]);
        assertArrayEquals(new String[]{"123-456-789a abiguygusu ", " kjgufwycs ", ""}, res);
    }
}

class RegexUtilsTestSub {

    @Test
    void testSub1() {
        RegexUtils ru = new RegexUtils();
        String res = ru.sub("\\b\\d{3}-\\d{3}-\\d{4}\\b", "phone num", "123-456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
        assertEquals("phone num abiguygusu phone num kjgufwycs phone num", res);
    }

    @Test
    void testSub2() {
        RegexUtils ru = new RegexUtils();
        String res = ru.sub("\\b\\d{3}-\\d{3}-\\d{4}\\b", "phone num", "1234567890 abiguygusu 8762869876 kjgufwycs 9877629767");
        assertEquals("1234567890 abiguygusu 8762869876 kjgufwycs 9877629767", res);
    }

    @Test
    void testSub3() {
        RegexUtils ru = new RegexUtils();
        String res = ru.sub("\\b\\d{3}-\\d{3}-\\d{4}\\b", "phone num", "123456-7890 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
        assertEquals("123456-7890 abiguygusu phone num kjgufwycs phone num", res);
    }

    @Test
    void testSub4() {
        RegexUtils ru = new RegexUtils();
        String res = ru.sub("\\b\\d{3}-\\d{3}-\\d{4}\\b", "phone num", "123-456-789a abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
        assertEquals("123-456-789a abiguygusu phone num kjgufwycs phone num", res);
    }

    @Test
    void testSub5() {
        RegexUtils ru = new RegexUtils();
        String res = ru.sub("\\b\\d{3}-\\d{3}-\\d{4}\\b", "phone num", "123-456-780 abiguygusu 876-286-9876 kjgufwycs 987-762-9767");
        assertEquals("123-456-780 abiguygusu phone num kjgufwycs phone num", res);
    }
}

class RegexUtilsTestGenerateEmailPattern {

    @Test
    void testGenerateEmailPattern1() {
        RegexUtils ru = new RegexUtils();
        String pat = ru.generateEmailPattern();
        boolean res = ru.match(pat, "iustd87t2euh@163.com");
        assertTrue(res);
    }

    @Test
    void testGenerateEmailPattern2() {
        RegexUtils ru = new RegexUtils();
        String pat = ru.generateEmailPattern();
        boolean res = ru.match(pat, "iustd87t2euhifg.com");
        assertFalse(res);
    }

    @Test
    void testGenerateEmailPattern3() {
        RegexUtils ru = new RegexUtils();
        String pat = ru.generateEmailPattern();
        boolean res = ru.match(pat, "iustd87t2euh@.com");
        assertFalse(res);
    }

    @Test
    void testGenerateEmailPattern4() {
        RegexUtils ru = new RegexUtils();
        String pat = ru.generateEmailPattern();
        boolean res = ru.match(pat, "iustd87t2euh@163.c");
        assertFalse(res);
    }

    @Test
    void testGenerateEmailPattern5() {
        RegexUtils ru = new RegexUtils();
        String pat = ru.generateEmailPattern();
        boolean res = ru.match(pat, "iustd87t2euh@163.com");
        assertTrue(res);
    }
}

class RegexUtilsTestGeneratePhonePattern {

    @Test
    void testGeneratePhonePattern1() {
        RegexUtils ru = new RegexUtils();
        String pat = ru.generatePhoneNumberPattern(); // 使用电话号码模式
        boolean res = ru.match(pat, "123-456-7890");
        assertTrue(res); // 预期值为 true，因为电话号码应该匹配电话号码模式
    }

    @Test
    void testGeneratePhonePattern2() {
        RegexUtils ru = new RegexUtils();
        String pat = ru.generatePhoneNumberPattern();
        boolean res = ru.match(pat, "1234567890");
        assertFalse(res);
    }

    @Test
    void testGeneratePhonePattern3() {
        RegexUtils ru = new RegexUtils();
        String pat = ru.generatePhoneNumberPattern();
        boolean res = ru.match(pat, "123-456-7890");
        assertTrue(res);
    }

    @Test
    void testGeneratePhonePattern4() {
        RegexUtils ru = new RegexUtils();
        String pat = ru.generatePhoneNumberPattern();
        boolean res = ru.match(pat, "123-456-78");
        assertFalse(res);
    }

    @Test
    void testGeneratePhonePattern5() {
        RegexUtils ru = new RegexUtils();
        String pat = ru.generatePhoneNumberPattern();
        boolean res = ru.match(pat, "123-456-789x");
        assertFalse(res);
    }
}
