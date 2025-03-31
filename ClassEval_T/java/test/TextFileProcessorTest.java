package org.example;

import org.junit.jupiter.api.*;
import java.io.*;
import java.nio.file.*;
import java.util.*;
import static org.junit.jupiter.api.Assertions.*;

public class TextFileProcessorTest {

    private static final String[] files = {"test_1.txt", "test_2.txt", "test_3.txt", "test_4.txt", "test_5.txt"};
    private static final String[] contents = {
            "{\n    \"name\": \"test\",\n    \"age\": 12\n}",
            "12345",
            "\"hello\"",
            "\"aaa\"",
            "\"bbb\""
    };

    @BeforeEach
    public void setUp() throws IOException {
        for (int i = 0; i < files.length; i++) {
            Files.write(Paths.get(files[i]), contents[i].getBytes());
        }
    }

    @AfterEach
    public void tearDown() {
        for (String file : files) {
            try {
                Files.deleteIfExists(Paths.get(file));
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    @Test
    public void test_read_file_as_json_1() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[0]);
        Object data = textFileProcessor.read_file_as_json();
        Map<String, Object> expected = new HashMap<>();
        expected.put("name", "test");
        expected.put("age", 12);
        assertEquals(expected, data);
        assertTrue(data instanceof Map);
    }

    @Test
    public void test_read_file_as_json_2() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[1]);
        Object data = textFileProcessor.read_file_as_json();
        assertEquals(12345, data);
        assertEquals(Integer.class, data.getClass());
    }

    @Test
    public void test_read_file_as_json_3() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[2]);
        Object data = textFileProcessor.read_file_as_json();
        assertEquals("hello", data);
        assertEquals(String.class, data.getClass());
    }

    @Test
    public void test_read_file_as_json_4() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[3]);
        Object data = textFileProcessor.read_file_as_json();
        assertEquals("aaa", data);
        assertEquals(String.class, data.getClass());
    }

    @Test
    public void test_read_file_as_json_5() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[4]);
        Object data = textFileProcessor.read_file_as_json();
        assertEquals("bbb", data);
        assertEquals(String.class, data.getClass());
    }

    @Test
    public void test_read_file_1() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[0]);
        String data = textFileProcessor.read_file();
        assertEquals(contents[0], data);
    }

    @Test
    public void test_read_file_2() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[1]);
        String data = textFileProcessor.read_file();
        assertEquals(contents[1], data);
    }

    @Test
    public void test_read_file_3() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[2]);
        String data = textFileProcessor.read_file();
        assertEquals(contents[2], data);
    }

    @Test
    public void test_read_file_4() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[3]);
        String data = textFileProcessor.read_file();
        assertEquals(contents[3], data);
    }

    @Test
    public void test_read_file_5() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[4]);
        String data = textFileProcessor.read_file();
        assertEquals(contents[4], data);
    }

    @Test
    public void test_write_file_1() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[0]);
        textFileProcessor.write_file(contents[0]);
        String data = new String(Files.readAllBytes(Paths.get(files[0])));
        assertEquals(contents[0], data);
    }

    @Test
    public void test_write_file_2() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[1]);
        textFileProcessor.write_file(contents[1]);
        String data = new String(Files.readAllBytes(Paths.get(files[1])));
        assertEquals(contents[1], data);
    }

    @Test
    public void test_write_file_3() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[2]);
        textFileProcessor.write_file(contents[2]);
        String data = new String(Files.readAllBytes(Paths.get(files[2])));
        assertEquals(contents[2], data);
    }

    @Test
    public void test_write_file_4() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[3]);
        textFileProcessor.write_file(contents[3]);
        String data = new String(Files.readAllBytes(Paths.get(files[3])));
        assertEquals(contents[3], data);
    }

    @Test
    public void test_write_file_5() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[4]);
        textFileProcessor.write_file(contents[4]);
        String data = new String(Files.readAllBytes(Paths.get(files[4])));
        assertEquals(contents[4], data);
    }

    @Test
    public void test_process_file_1() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[0]);
        String result = textFileProcessor.process_file();
        assertEquals("nametestage", result);
    }

    @Test
    public void test_process_file_2() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[1]);
        String result = textFileProcessor.process_file();
        assertEquals("", result);
    }

    @Test
    public void test_process_file_3() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[2]);
        String result = textFileProcessor.process_file();
        assertEquals("hello", result);
    }

    @Test
    public void test_process_file_4() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[3]);
        String result = textFileProcessor.process_file();
        assertEquals("aaa", result);
    }

    @Test
    public void test_process_file_5() throws IOException {
        TextFileProcessor textFileProcessor = new TextFileProcessor(files[4]);
        String result = textFileProcessor.process_file();
        assertEquals("bbb", result);
    }
}