package org.example;

import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class ExcelProcessorTest {

    private String testFileName;

    @Before
    public void setUp() {
        testFileName = "test_data.xlsx";
    }

    @After
    public void tearDown() {
        new File(testFileName).delete();
    }

    @Test
    public void testReadExcel1() throws IOException {
        List<List<Object>> data = new ArrayList<>();
        data.add(List.of("Name", "Age", "Country"));
        data.add(List.of("John", 25, "USA"));
        data.add(List.of("Alice", 30, "Canada"));
        data.add(List.of("Bob", 35, "Australia"));

        writeExcel(data, testFileName);

        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> readData = processor.readExcel(testFileName);
        List<List<Object>> expectedData = new ArrayList<>();
        expectedData.add(List.of("Name", "Age", "Country"));
        expectedData.add(List.of("John", 25, "USA"));
        expectedData.add(List.of("Alice", 30, "Canada"));
        expectedData.add(List.of("Bob", 35, "Australia"));

        assertEquals(expectedData, readData);
    }

    @Test
    public void testReadExcel2() throws IOException {
        List<List<Object>> data = new ArrayList<>();
        data.add(List.of("Name", "Age"));
        data.add(List.of("John", 25));
        data.add(List.of("Alice", 30));
        data.add(List.of("Bob", 35));

        writeExcel(data, testFileName);

        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> readData = processor.readExcel(testFileName);
        List<List<Object>> expectedData = new ArrayList<>();
        expectedData.add(List.of("Name", "Age"));
        expectedData.add(List.of("John", 25));
        expectedData.add(List.of("Alice", 30));
        expectedData.add(List.of("Bob", 35));

        assertEquals(expectedData, readData);
    }

    @Test
    public void testReadExcel3() throws IOException {
        List<List<Object>> data = new ArrayList<>();
        data.add(List.of("Name"));
        data.add(List.of("John"));
        data.add(List.of("Alice"));
        data.add(List.of("Bob"));

        writeExcel(data, testFileName);

        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> readData = processor.readExcel(testFileName);
        List<List<Object>> expectedData = new ArrayList<>();
        expectedData.add(List.of("Name"));
        expectedData.add(List.of("John"));
        expectedData.add(List.of("Alice"));
        expectedData.add(List.of("Bob"));

        assertEquals(expectedData, readData);
    }

    @Test
    public void testReadExcel4() throws IOException {
        List<List<Object>> data = new ArrayList<>();
        data.add(List.of("Name", "Country"));
        data.add(List.of("John", "USA"));
        data.add(List.of("Alice", "Canada"));
        data.add(List.of("Bob", "Australia"));

        writeExcel(data, testFileName);

        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> readData = processor.readExcel(testFileName);
        List<List<Object>> expectedData = new ArrayList<>();
        expectedData.add(List.of("Name", "Country"));
        expectedData.add(List.of("John", "USA"));
        expectedData.add(List.of("Alice", "Canada"));
        expectedData.add(List.of("Bob", "Australia"));

        assertEquals(expectedData, readData);
    }

    @Test
    public void testReadExcel5() throws IOException {
        List<List<Object>> data = new ArrayList<>();
        data.add(List.of("Name", "Country"));
        data.add(List.of("John", "USA"));

        writeExcel(data, testFileName);

        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> readData = processor.readExcel(testFileName);
        List<List<Object>> expectedData = new ArrayList<>();
        expectedData.add(List.of("Name", "Country"));
        expectedData.add(List.of("John", "USA"));

        assertEquals(expectedData, readData);
    }

    @Test
    public void testReadExcel6() throws IOException {
        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> readData = processor.readExcel("");
        assertNull(readData);
    }

    @Test
    public void testWriteExcel1() throws IOException {
        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> newData = new ArrayList<>();
        newData.add(List.of("Name", "Age", "Country"));
        newData.add(List.of("John", 25, "USA"));
        newData.add(List.of("Alice", 30, "Canada"));
        newData.add(List.of("Bob", 35, "Australia"));
        newData.add(List.of("Julia", 28, "Germany"));

        String saveFileName = "test_output.xlsx";
        boolean success = processor.writeExcel(newData, saveFileName);
        assertTrue(success);
        assertTrue(new File(saveFileName).exists());

        List<List<Object>> savedData = processor.readExcel(saveFileName);
        assertEquals(newData, savedData);

        new File(saveFileName).delete();
    }

    @Test
    public void testWriteExcel2() throws IOException {
        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> newData = new ArrayList<>();
        newData.add(List.of("Name", "Age"));
        newData.add(List.of("John", 25));
        newData.add(List.of("Alice", 30));
        newData.add(List.of("Bob", 35));
        newData.add(List.of("Julia", 28));

        String saveFileName = "test_output.xlsx";
        boolean success = processor.writeExcel(newData, saveFileName);
        assertTrue(success);
        assertTrue(new File(saveFileName).exists());

        List<List<Object>> savedData = processor.readExcel(saveFileName);
        assertEquals(newData, savedData);

        new File(saveFileName).delete();
    }

    @Test
    public void testWriteExcel3() throws IOException {
        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> newData = new ArrayList<>();
        newData.add(List.of("Name", "Age", "Country"));
        newData.add(List.of("John", 25, "USA"));
        newData.add(List.of("Alice", 30, "Canada"));
        newData.add(List.of("Bob", 35, "Australia"));

        String saveFileName = "test_output.xlsx";
        boolean success = processor.writeExcel(newData, saveFileName);
        assertTrue(success);
        assertTrue(new File(saveFileName).exists());

        List<List<Object>> savedData = processor.readExcel(saveFileName);
        assertEquals(newData, savedData);

        new File(saveFileName).delete();
    }

    @Test
    public void testWriteExcel4() throws IOException {
        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> newData = new ArrayList<>();
        newData.add(List.of("Name", "Age", "Country"));
        newData.add(List.of("John", 25, "USA"));
        newData.add(List.of("Alice", 30, "Canada"));

        String saveFileName = "test_output.xlsx";
        boolean success = processor.writeExcel(newData, saveFileName);
        assertTrue(success);
        assertTrue(new File(saveFileName).exists());

        List<List<Object>> savedData = processor.readExcel(saveFileName);
        assertEquals(newData, savedData);

        new File(saveFileName).delete();
    }

    @Test
    public void testWriteExcel5() throws IOException {
        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> newData = new ArrayList<>();
        newData.add(List.of("Name", "Age", "Country"));
        newData.add(List.of("John", 25, "USA"));

        String saveFileName = "test_output.xlsx";
        boolean success = processor.writeExcel(newData, saveFileName);
        assertTrue(success);
        assertTrue(new File(saveFileName).exists());

        List<List<Object>> savedData = processor.readExcel(saveFileName);
        assertEquals(newData, savedData);

        new File(saveFileName).delete();
    }

    @Test
    public void testWriteExcel6() throws IOException {
        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> newData = new ArrayList<>();
        newData.add(List.of("Name", "Age", "Country"));
        newData.add(List.of("John", 25, "USA"));

        boolean success = processor.writeExcel(newData, "");
        assertFalse(success);
    }

    @Test
    public void testProcessExcelData1() throws IOException {
        List<List<Object>> data = new ArrayList<>();
        data.add(List.of("Name", "Age", "Country"));
        data.add(List.of("John", 25, "USA"));
        data.add(List.of("Alice", 30, "Canada"));
        data.add(List.of("Bob", 35, "Australia"));

        writeExcel(data, testFileName);

        ExcelProcessor processor = new ExcelProcessor();
        int N = 1;
        String outputFile = processor.processExcelData(N, testFileName);
        assertNotNull(outputFile);
        assertTrue(new File(outputFile).exists());

        List<List<Object>> processedData = processor.readExcel(outputFile);
        List<List<Object>> expectedProcessedData = new ArrayList<>();
        expectedProcessedData.add(List.of("Name", "Age", "Country", "AGE"));
        expectedProcessedData.add(List.of("John", 25, "USA", 25));
        expectedProcessedData.add(List.of("Alice", 30, "Canada", 30));
        expectedProcessedData.add(List.of("Bob", 35, "Australia", 35));

        assertEquals(expectedProcessedData, processedData);

        new File(outputFile).delete();
    }

    @Test
    public void testProcessExcelData2() throws IOException {
        List<List<Object>> data = new ArrayList<>();
        data.add(List.of("Name", "Age", "Country"));
        data.add(List.of("John", 25, "USA"));
        data.add(List.of("Alice", 30, "Canada"));
        data.add(List.of("Bob", 35, "Australia"));

        writeExcel(data, testFileName);

        ExcelProcessor processor = new ExcelProcessor();
        int N = 0;
        String outputFile = processor.processExcelData(N, testFileName);
        assertNotNull(outputFile);
        assertTrue(new File(outputFile).exists());

        List<List<Object>> processedData = processor.readExcel(outputFile);
        List<List<Object>> expectedProcessedData = new ArrayList<>();
        expectedProcessedData.add(List.of("Name", "Age", "Country", "NAME"));
        expectedProcessedData.add(List.of("John", 25, "USA", "JOHN"));
        expectedProcessedData.add(List.of("Alice", 30, "Canada", "ALICE"));
        expectedProcessedData.add(List.of("Bob", 35, "Australia", "BOB"));

        assertEquals(expectedProcessedData, processedData);

        new File(outputFile).delete();
    }

    @Test
    public void testProcessExcelData3() throws IOException {
        List<List<Object>> data = new ArrayList<>();
        data.add(List.of("Name", "Age", "Country"));
        data.add(List.of("John", 25, "USA"));
        data.add(List.of("Alice", 30, "Canada"));
        data.add(List.of("Bob", 35, "Australia"));

        writeExcel(data, testFileName);

        ExcelProcessor processor = new ExcelProcessor();
        int N = 2;
        String outputFile = processor.processExcelData(N, testFileName);
        assertNotNull(outputFile);
        assertTrue(new File(outputFile).exists());

        List<List<Object>> processedData = processor.readExcel(outputFile);
        List<List<Object>> expectedProcessedData = new ArrayList<>();
        expectedProcessedData.add(List.of("Name", "Age", "Country", "COUNTRY"));
        expectedProcessedData.add(List.of("John", 25, "USA", "USA"));
        expectedProcessedData.add(List.of("Alice", 30, "Canada", "CANADA"));
        expectedProcessedData.add(List.of("Bob", 35, "Australia", "AUSTRALIA"));

        assertEquals(expectedProcessedData, processedData);

        new File(outputFile).delete();
    }

    @Test
    public void testProcessExcelData4() throws IOException {
        List<List<Object>> data = new ArrayList<>();
        data.add(List.of("Name", "Age", "COUNTRY"));
        data.add(List.of("John", 25, "USA"));
        data.add(List.of("Alice", 30, "CANADA"));
        data.add(List.of("Bob", 35, "AUSTRALIA"));

        writeExcel(data, testFileName);

        ExcelProcessor processor = new ExcelProcessor();
        int N = 2;
        String outputFile = processor.processExcelData(N, testFileName);
        assertNotNull(outputFile);
        assertTrue(new File(outputFile).exists());

        List<List<Object>> processedData = processor.readExcel(outputFile);
        List<List<Object>> expectedProcessedData = new ArrayList<>();
        expectedProcessedData.add(List.of("Name", "Age", "COUNTRY", "COUNTRY"));
        expectedProcessedData.add(List.of("John", 25, "USA", "USA"));
        expectedProcessedData.add(List.of("Alice", 30, "CANADA", "CANADA"));
        expectedProcessedData.add(List.of("Bob", 35, "AUSTRALIA", "AUSTRALIA"));

        assertEquals(expectedProcessedData, processedData);

        new File(outputFile).delete();
    }

    @Test
    public void testProcessExcelData5() throws IOException {
        List<List<Object>> data = new ArrayList<>();
        data.add(List.of("Name", "AGE", "COUNTRY"));
        data.add(List.of("John", 25, "USA"));
        data.add(List.of("Alice", 30, "CANADA"));
        data.add(List.of("Bob", 35, "AUSTRALIA"));

        writeExcel(data, testFileName);

        ExcelProcessor processor = new ExcelProcessor();
        int N = 1;
        String outputFile = processor.processExcelData(N, testFileName);
        assertNotNull(outputFile);
        assertTrue(new File(outputFile).exists());

        List<List<Object>> processedData = processor.readExcel(outputFile);
        List<List<Object>> expectedProcessedData = new ArrayList<>();
        expectedProcessedData.add(List.of("Name", "AGE", "COUNTRY", "AGE"));
        expectedProcessedData.add(List.of("John", 25, "USA", 25));
        expectedProcessedData.add(List.of("Alice", 30, "CANADA", 30));
        expectedProcessedData.add(List.of("Bob", 35, "AUSTRALIA", 35));

        assertEquals(expectedProcessedData, processedData);

        new File(outputFile).delete();
    }

    @Test
    public void testProcessExcelData6() throws IOException {
        List<List<Object>> data = new ArrayList<>();
        data.add(List.of("Name", "AGE", "COUNTRY"));
        data.add(List.of("John", 25, "USA"));
        data.add(List.of("Alice", 30, "CANADA"));
        data.add(List.of("Bob", 35, "AUSTRALIA"));

        writeExcel(data, testFileName);

        ExcelProcessor processor = new ExcelProcessor();
        String outputFile = processor.processExcelData(100, testFileName);
        assertNull(outputFile);
    }

    @Test
    public void testExcelProcessor() throws IOException {
        List<List<Object>> data = new ArrayList<>();
        data.add(List.of("Name", "Age", "Country"));
        data.add(List.of("John", 25, "USA"));
        data.add(List.of("Alice", 30, "Canada"));
        data.add(List.of("Bob", 35, "Australia"));

        writeExcel(data, testFileName);

        ExcelProcessor processor = new ExcelProcessor();
        List<List<Object>> readData = processor.readExcel(testFileName);
        List<List<Object>> expectedData = new ArrayList<>();
        expectedData.add(List.of("Name", "Age", "Country"));
        expectedData.add(List.of("John", 25, "USA"));
        expectedData.add(List.of("Alice", 30, "Canada"));
        expectedData.add(List.of("Bob", 35, "Australia"));

        assertEquals(expectedData, readData);

        List<List<Object>> newData = new ArrayList<>();
        newData.add(List.of("Name", "Age", "Country"));
        newData.add(List.of("John", 25, "USA"));
        newData.add(List.of("Alice", 30, "Canada"));
        newData.add(List.of("Bob", 35, "Australia"));
        newData.add(List.of("Julia", 28, "Germany"));

        String saveFileName = "test_output.xlsx";
        boolean success = processor.writeExcel(newData, saveFileName);
        assertTrue(success);
        assertTrue(new File(saveFileName).exists());

        List<List<Object>> savedData = processor.readExcel(saveFileName);
        assertEquals(newData, savedData);

        new File(saveFileName).delete();

        writeExcel(data, testFileName);

        int N = 1;
        String outputFile = processor.processExcelData(N, testFileName);
        assertNotNull(outputFile);
        assertTrue(new File(outputFile).exists());

        List<List<Object>> processedData = processor.readExcel(outputFile);
        List<List<Object>> expectedProcessedData = new ArrayList<>();
        expectedProcessedData.add(List.of("Name", "Age", "Country", "AGE"));
        expectedProcessedData.add(List.of("John", 25, "USA", 25));
        expectedProcessedData.add(List.of("Alice", 30, "Canada", 30));
        expectedProcessedData.add(List.of("Bob", 35, "Australia", 35));

        assertEquals(expectedProcessedData, processedData);

        new File(outputFile).delete();
    }


    private void writeExcel(List<List<Object>> data, String fileName) throws IOException {
        Workbook workbook = new XSSFWorkbook();
        Sheet sheet = workbook.createSheet("Sheet1");

        for (int i = 0; i < data.size(); i++) {
            Row row = sheet.createRow(i);
            List<Object> rowData = data.get(i);
            for (int j = 0; j < rowData.size(); j++) {
                Cell cell = row.createCell(j);
                Object value = rowData.get(j);
                if (value instanceof String) {
                    cell.setCellValue((String) value);
                } else if (value instanceof Integer) {
                    cell.setCellValue((Integer) value);
                }
            }
        }

        try (FileOutputStream fileOut = new FileOutputStream(fileName)) {
            workbook.write(fileOut);
        }
    }
}