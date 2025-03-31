package org.example;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

class CookiesUtilTest {

    private CookiesUtil cookiesUtil;
    private File tempFile;

    @BeforeEach
    void setUp() throws IOException {
        tempFile = File.createTempFile("cookies", ".json");
        cookiesUtil = new CookiesUtil(tempFile.getAbsolutePath());
    }

    @Test
    void testGetCookies() {
        Map<String, Map<String, String>> response = new HashMap<>();
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");
        response.put("cookies", cookiesMap);

        cookiesUtil.getCookies(response);
        assertEquals(cookiesMap, cookiesUtil.loadCookies());
    }

    @Test
    void testGetCookies_2() {
        Map<String, Map<String, String>> response = new HashMap<>();
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");
        response.put("cookies", cookiesMap);
        response.put("cookies2", Map.of("key3", "value3", "key4", "value4"));

        cookiesUtil.getCookies(response);
        assertEquals(cookiesMap, cookiesUtil.loadCookies());
    }

    @Test
    void testGetCookies_3() {
        Map<String, Map<String, String>> response = new HashMap<>();
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");
        response.put("cookies", cookiesMap);
        response.put("cookies2", Map.of("key3", "value3", "key4", "value4"));
        response.put("cookies3", Map.of("key5", "value5", "key6", "value6"));

        cookiesUtil.getCookies(response);
        assertEquals(cookiesMap, cookiesUtil.loadCookies());
    }

    @Test
    void testGetCookies_4() {
        Map<String, Map<String, String>> response = new HashMap<>();
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");
        response.put("cookies", cookiesMap);
        response.put("cookies2", Map.of("key3", "value3", "key4", "value4"));
        response.put("cookies3", Map.of("key5", "value5", "key6", "value6"));
        response.put("cookies4", Map.of("key7", "value7", "key8", "value8"));

        cookiesUtil.getCookies(response);
        assertEquals(cookiesMap, cookiesUtil.loadCookies());
    }

    @Test
    void testGetCookies_5() {
        Map<String, Map<String, String>> response = new HashMap<>();
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");
        response.put("cookies", cookiesMap);
        response.put("cookies2", Map.of("key3", "value3", "key4", "value4"));
        response.put("cookies3", Map.of("key5", "value5", "key6", "value6"));
        response.put("cookies4", Map.of("key7", "value7", "key8", "value8"));
        response.put("cookies5", Map.of("key9", "value9", "key10", "value10"));

        cookiesUtil.getCookies(response);
        assertEquals(cookiesMap, cookiesUtil.loadCookies());
    }

    @Test
    void testLoadCookies() throws IOException {
        Map<String, String> expectedCookies = new HashMap<>();
        expectedCookies.put("key1", "value1");
        expectedCookies.put("key2", "value2");

        cookiesUtil.getCookies(Map.of("cookies", expectedCookies));
        assertEquals(expectedCookies, cookiesUtil.loadCookies());
    }

    @Test
    void testLoadCookies_2() {
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");

        cookiesUtil.getCookies(Map.of("cookies", cookiesMap));
        assertEquals(cookiesMap, cookiesUtil.loadCookies());
    }

    @Test
    void testLoadCookies_3() {
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");

        cookiesUtil.getCookies(Map.of("cookies", cookiesMap, "cookies2", Map.of("key3", "value3", "key4", "value4")));
        assertEquals(cookiesMap, cookiesUtil.loadCookies());
    }

    @Test
    void testLoadCookies_4() {
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");

        cookiesUtil.getCookies(Map.of("cookies", cookiesMap,
                "cookies2", Map.of("key3", "value3", "key4", "value4"),
                "cookies3", Map.of("key5", "value5", "key6", "value6")));
        assertEquals(cookiesMap, cookiesUtil.loadCookies());
    }

    @Test
    void testLoadCookies_5() {
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");

        cookiesUtil.getCookies(Map.of("cookies", cookiesMap,
                "cookies2", Map.of("key3", "value3", "key4", "value4"),
                "cookies3", Map.of("key5", "value5", "key6", "value6"),
                "cookies4", Map.of("key7", "value7", "key8", "value8")));
        assertEquals(cookiesMap, cookiesUtil.loadCookies());
    }

    @Test
    void testLoadCookies_6() {
        CookiesUtil emptyCookiesUtil = new CookiesUtil("");
        assertEquals(new HashMap<>(), emptyCookiesUtil.loadCookies());
    }

    @Test
    void testSaveCookies() {
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");

        cookiesUtil.getCookies(Map.of("cookies", cookiesMap));
        assertTrue(cookiesUtil._saveCookies());
    }

    @Test
    void testSaveCookies_2() {
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");

        cookiesUtil.getCookies(Map.of("cookies", cookiesMap,
                "cookies2", Map.of("key3", "value3", "key4", "value4")));
        assertTrue(cookiesUtil._saveCookies());
    }

    @Test
    void testSaveCookies_3() {
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");

        cookiesUtil.getCookies(Map.of("cookies", cookiesMap,
                "cookies2", Map.of("key3", "value3", "key4", "value4"),
                "cookies3", Map.of("key5", "value5", "key6", "value6")));
        assertTrue(cookiesUtil._saveCookies());
    }

    @Test
    void testSaveCookies_4() {
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");

        cookiesUtil.getCookies(Map.of("cookies", cookiesMap,
                "cookies2", Map.of("key3", "value3", "key4", "value4"),
                "cookies3", Map.of("key5", "value5", "key6", "value6"),
                "cookies4", Map.of("key7", "value7", "key8", "value8")));
        assertTrue(cookiesUtil._saveCookies());
    }

    @Test
    void testSaveCookies_5() {
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");

        cookiesUtil.getCookies(Map.of("cookies", cookiesMap,
                "cookies2", Map.of("key3", "value3", "key4", "value4"),
                "cookies3", Map.of("key5", "value5", "key6", "value6"),
                "cookies4", Map.of("key7", "value7", "key8", "value8"),
                "cookies5", Map.of("key9", "value9", "key10", "value10")));
        assertTrue(cookiesUtil._saveCookies());
    }

    @Test
    void testSaveCookies_6() {
        CookiesUtil emptyCookiesUtil = new CookiesUtil("");
        assertFalse(emptyCookiesUtil._saveCookies());
    }

    @Test
    void testSetCookies() {
        Map<String, String> cookiesMap = new HashMap<>();
        cookiesMap.put("key1", "value1");
        cookiesMap.put("key2", "value2");

        cookiesUtil.getCookies(Map.of("cookies", cookiesMap));
        Map<String, String> request = new HashMap<>();
        cookiesUtil.setCookies(request);
        assertEquals("key1=value1; key2=value2", request.get("cookies"));
    }

    @Test
    void testMain() {
        Map<String, String> cookiesData = new HashMap<>();
        cookiesData.put("key1", "value1");
        cookiesData.put("key2", "value2");

        cookiesUtil.getCookies(Map.of("cookies", cookiesData));
        assertEquals(cookiesData, cookiesUtil.loadCookies());
        assertTrue(cookiesUtil._saveCookies());
    }
}
