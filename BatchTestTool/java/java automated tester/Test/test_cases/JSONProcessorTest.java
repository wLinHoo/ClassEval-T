package test_cases;
import to_be_tested.JSONProcessor;

import com.google.gson.Gson;
import org.junit.jupiter.api.*;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

public class JSONProcessorTest {

    private JSONProcessor processor;
    private String filePath;
    private String readOnlyFilePath;
    private Map<String, Object> testData;

    @BeforeEach
    public void setUp() throws IOException {
        processor = new JSONProcessor();
        filePath = "test.json";
        readOnlyFilePath = "test_only_read.json";
        testData = new HashMap<>();
        testData.put("key1", "value1");
        testData.put("key2", "value2");
        testData.put("key3", "value3");

        Files.write(Paths.get(readOnlyFilePath), "{\"key1\": \"value1\"}".getBytes());
        Files.setAttribute(Paths.get(readOnlyFilePath), "dos:readonly", true);
    }

    @AfterEach
    public void tearDown() throws IOException {
        Files.deleteIfExists(Paths.get(filePath));
        Files.setAttribute(Paths.get(readOnlyFilePath), "dos:readonly", false);
        Files.deleteIfExists(Paths.get(readOnlyFilePath));
    }

    @Test
    public void testReadJson1() throws IOException {
        Files.write(Paths.get(filePath), new Gson().toJson(testData).getBytes());
        Map<String, Object> result = processor.readJson(filePath);
        assertEquals(testData, result);
    }

    @Test
    public void testReadJson2() {
        Map<String, Object> result = processor.readJson(filePath);
        assertNull(result);
    }

    @Test
    public void testReadJson3() throws IOException {
        Files.write(Paths.get(filePath), "Invalid JSON".getBytes());
        Map<String, Object> result = processor.readJson(filePath);
        assertNull(result);
    }

    @Test
    public void testReadJson4() {
        Map<String, Object> result = processor.readJson("wrong");
        assertNull(result);
    }

    @Test
    public void testReadJson5() {
        Map<String, Object> result = processor.readJson("abcd");
        assertNull(result);
    }

    @Test
    public void testWriteJson1() throws IOException {
        boolean result = processor.writeJson(testData, filePath);
        assertTrue(result);
        assertEquals(testData, new Gson().fromJson(new String(Files.readAllBytes(Paths.get(filePath))), Map.class));
    }

    @Test
    public void testWriteJson2() {
        boolean result = processor.writeJson(testData, readOnlyFilePath);
        assertFalse(result);
    }

    @Test
    public void testWriteJson3() {
        boolean result = processor.writeJson(new HashMap<>(), readOnlyFilePath);
        assertFalse(result);
    }

    @Test
    public void testWriteJson4() {
        boolean result = processor.writeJson(testData, "");
        assertFalse(result);
    }

    @Test
    public void testWriteJson5() {
        boolean result = processor.writeJson(new HashMap<>(), "");
        assertFalse(result);
    }

    @Test
    public void testProcessJson1() throws IOException {
        Files.write(Paths.get(filePath), new Gson().toJson(testData).getBytes());
        String removeKey = "key2";
        assertTrue(processor.processJson(filePath, removeKey));
        testData.remove(removeKey);
        assertEquals(testData, new Gson().fromJson(new String(Files.readAllBytes(Paths.get(filePath))), Map.class));
    }

    @Test
    public void testProcessJson2() throws IOException {
        Files.write(Paths.get(filePath), new Gson().toJson(testData).getBytes());
        String removeKey = "nonexistent_key";
        assertFalse(processor.processJson(filePath, removeKey));
        assertEquals(testData, new Gson().fromJson(new String(Files.readAllBytes(Paths.get(filePath))), Map.class));
    }

    @Test
    public void testProcessJson3() throws IOException {
        Files.createFile(Paths.get(filePath));
        String removeKey = "key1";
        assertFalse(processor.processJson(filePath, removeKey));
    }

    @Test
    public void testProcessJson4() throws IOException {
        Files.write(Paths.get(filePath), new Gson().toJson(testData).getBytes());
        String removeKey = "aaa";
        assertFalse(processor.processJson(filePath, removeKey));
        assertEquals(testData, new Gson().fromJson(new String(Files.readAllBytes(Paths.get(filePath))), Map.class));
    }

    @Test
    public void testProcessJson5() throws IOException {
        Files.write(Paths.get(filePath), new Gson().toJson(testData).getBytes());
        String removeKey = "bbb";
        assertFalse(processor.processJson(filePath, removeKey));
        assertEquals(testData, new Gson().fromJson(new String(Files.readAllBytes(Paths.get(filePath))), Map.class));
    }

    @Test
    public void testMain() {
        assertTrue(processor.writeJson(testData, filePath));
        assertEquals(testData, processor.readJson(filePath));
        String removeKey = "key2";
        assertTrue(processor.processJson(filePath, removeKey));
        testData.remove(removeKey);
        assertEquals(testData, processor.readJson(filePath));
    }
}