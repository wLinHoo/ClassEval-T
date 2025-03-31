package org.example;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.w3c.dom.Document;
import org.w3c.dom.NodeList;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import static org.junit.jupiter.api.Assertions.*;

public class XMLProcessorTest {

    private static final String TEST_XML_FILE = "test.xml";
    private static final String OUTPUT_XML_FILE = "output.xml";
    private static final String PROCESSED_XML_FILE = "processed.xml";

    private XMLProcessor processor;

    @BeforeEach
    public void setUp() {
        processor = new XMLProcessor(TEST_XML_FILE);
    }

    @AfterEach
    public void tearDown() {
        new File(TEST_XML_FILE).delete();
        new File(OUTPUT_XML_FILE).delete();
        new File(PROCESSED_XML_FILE).delete();
    }

    private void writeTestXml(String content) throws IOException {
        try (FileWriter writer = new FileWriter(TEST_XML_FILE)) {
            writer.write(content);
        }
    }

    @Test
    public void testReadXml1() throws Exception {
        writeTestXml("<root>\n    <item>apple</item>\n    <item>banana</item>\n    <item>orange</item>\n</root>");
        processor.readXml();
        Document doc = processor.getDocument();
        assertNotNull(doc);
        NodeList lst = doc.getElementsByTagName("item");
        assertEquals("apple", lst.item(0).getTextContent());
        assertEquals("banana", lst.item(1).getTextContent());
        assertEquals("orange", lst.item(2).getTextContent());
    }

    @Test
    public void testReadXml2() throws Exception {
        writeTestXml("<root>\n    <item>aaa</item>\n    <item>bbb</item>\n    <item>ccc</item>\n</root>");
        processor.readXml();
        Document doc = processor.getDocument();
        assertNotNull(doc);
        NodeList lst = doc.getElementsByTagName("item");
        assertEquals("aaa", lst.item(0).getTextContent());
        assertEquals("bbb", lst.item(1).getTextContent());
        assertEquals("ccc", lst.item(2).getTextContent());
    }

    @Test
    public void testReadXml3() throws Exception {
        writeTestXml("<root>\n    <item>apple</item>\n</root>");
        processor.readXml();
        Document doc = processor.getDocument();
        assertNotNull(doc);
        NodeList lst = doc.getElementsByTagName("item");
        assertEquals("apple", lst.item(0).getTextContent());
    }

    @Test
    public void testReadXml4() throws Exception {
        writeTestXml("<root>\n    <item>apple</item>\n    <item>banana</item>\n</root>");
        processor.readXml();
        Document doc = processor.getDocument();
        assertNotNull(doc);
        NodeList lst = doc.getElementsByTagName("item");
        assertEquals("apple", lst.item(0).getTextContent());
        assertEquals("banana", lst.item(1).getTextContent());
    }

    @Test
    public void testReadXml5() throws Exception {
        writeTestXml("<root>\n    <item>apple</item>\n    <item>orange</item>\n</root>");
        processor.readXml();
        Document doc = processor.getDocument();
        assertNotNull(doc);
        NodeList lst = doc.getElementsByTagName("item");
        assertEquals("apple", lst.item(0).getTextContent());
        assertEquals("orange", lst.item(1).getTextContent());
    }

    @Test
    public void testReadXml6() throws Exception {
        processor = new XMLProcessor("");
        Document doc = processor.readXml();
        assertNull(doc);
    }

    @Test
    public void testWriteXml1() throws Exception {
        writeTestXml("<root>\n    <item>apple</item>\n    <item>banana</item>\n    <item>orange</item>\n</root>");
        processor.readXml();
        boolean result = processor.writeXml(OUTPUT_XML_FILE);
        assertTrue(result);

        XMLProcessor processor1 = new XMLProcessor(OUTPUT_XML_FILE);
        processor1.readXml();
        Document doc1 = processor1.getDocument();

        assertNotNull(doc1);
        NodeList lst = doc1.getElementsByTagName("item");
        assertEquals("apple", lst.item(0).getTextContent());
        assertEquals("banana", lst.item(1).getTextContent());
        assertEquals("orange", lst.item(2).getTextContent());
    }

    @Test
    public void testWriteXml2() throws Exception {
        writeTestXml("<root>\n    <item>apple</item>\n    <item>banana</item>\n</root>");
        processor.readXml();
        boolean result = processor.writeXml(OUTPUT_XML_FILE);
        assertTrue(result);

        XMLProcessor processor1 = new XMLProcessor(OUTPUT_XML_FILE);
        processor1.readXml();
        Document doc1 = processor1.getDocument();

        assertNotNull(doc1);
        NodeList lst = doc1.getElementsByTagName("item");
        assertEquals("apple", lst.item(0).getTextContent());
        assertEquals("banana", lst.item(1).getTextContent());
    }

    @Test
    public void testWriteXml3() throws Exception {
        writeTestXml("<root>\n    <item>apple</item>\n</root>");
        processor.readXml();
        boolean result = processor.writeXml(OUTPUT_XML_FILE);
        assertTrue(result);

        XMLProcessor processor1 = new XMLProcessor(OUTPUT_XML_FILE);
        processor1.readXml();
        Document doc1 = processor1.getDocument();

        assertNotNull(doc1);
        NodeList lst = doc1.getElementsByTagName("item");
        assertEquals("apple", lst.item(0).getTextContent());
    }

    @Test
    public void testWriteXml4() throws Exception {
        writeTestXml("<root>\n    <item>aaa</item>\n    <item>bbb</item>\n    <item>ccc</item>\n</root>");
        processor.readXml();
        boolean result = processor.writeXml(OUTPUT_XML_FILE);
        assertTrue(result);

        XMLProcessor processor1 = new XMLProcessor(OUTPUT_XML_FILE);
        processor1.readXml();
        Document doc1 = processor1.getDocument();

        assertNotNull(doc1);
        NodeList lst = doc1.getElementsByTagName("item");
        assertEquals("aaa", lst.item(0).getTextContent());
        assertEquals("bbb", lst.item(1).getTextContent());
        assertEquals("ccc", lst.item(2).getTextContent());
    }

    @Test
    public void testWriteXml5() throws Exception {
        writeTestXml("<root>\n    <item>apple</item>\n    <item>orange</item>\n</root>");
        processor.readXml();
        boolean result = processor.writeXml(OUTPUT_XML_FILE);
        assertTrue(result);

        XMLProcessor processor1 = new XMLProcessor(OUTPUT_XML_FILE);
        processor1.readXml();
        Document doc1 = processor1.getDocument();

        assertNotNull(doc1);
        NodeList lst = doc1.getElementsByTagName("item");
        assertEquals("apple", lst.item(0).getTextContent());
        assertEquals("orange", lst.item(1).getTextContent());
    }

    @Test
    public void testWriteXml6() throws Exception {
        processor = new XMLProcessor("");
        boolean result = processor.writeXml(PROCESSED_XML_FILE);
        assertFalse(result);

        // Also test when document is not loaded
        processor = new XMLProcessor(TEST_XML_FILE);
        processor.setDocument(null);
        result = processor.writeXml(PROCESSED_XML_FILE);
        assertFalse(result);
    }
}
