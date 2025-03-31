package org.example;

import org.junit.jupiter.api.*;
import java.io.*;
import java.nio.file.*;
import java.util.*;

class CSVProcessorTestReadCSV {

    private String file;

    @Test
    void testReadCSV1() throws IOException {
        file = "read_test.csv";

        // 创建文件并写入内容
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
            writer.write("a,b,c,d\nhElLo,YoU,ME,LoW");
        }

        // 预期值
        List<String> expectedTitle = Arrays.asList("a", "b", "c", "d");
        List<List<String>> expectedData = Collections.singletonList(Arrays.asList("hElLo", "YoU", "ME", "LoW"));

        CSVProcessor csvProcessor = new CSVProcessor();
        List<String> title = new ArrayList<>();
        List<List<String>> data = new ArrayList<>();
        csvProcessor.readCSV(file, title, data);

        Assertions.assertEquals(expectedTitle, title);
        Assertions.assertEquals(expectedData, data);
    }

    @Test
    void testReadCSV2() throws IOException {
        file = "read_test.csv";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
            writer.write("1234\nhElLo,YoU,ME,LoW");
        }

        List<String> expectedTitle = Collections.singletonList("1234");
        List<List<String>> expectedData = Collections.singletonList(Arrays.asList("hElLo", "YoU", "ME", "LoW"));

        CSVProcessor csvProcessor = new CSVProcessor();
        List<String> title = new ArrayList<>();
        List<List<String>> data = new ArrayList<>();
        csvProcessor.readCSV(file, title, data);

        Assertions.assertEquals(expectedTitle, title);
        Assertions.assertEquals(expectedData, data);
    }

    @Test
    void testReadCSV3() throws IOException {
        file = "read_test.csv";

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
            writer.write("title\nhElLo,YoU,ME,LoW");
        }

        List<String> expectedTitle = Collections.singletonList("title");
        List<List<String>> expectedData = Collections.singletonList(Arrays.asList("hElLo", "YoU", "ME", "LoW"));

        CSVProcessor csvProcessor = new CSVProcessor();
        List<String> title = new ArrayList<>();
        List<List<String>> data = new ArrayList<>();
        csvProcessor.readCSV(file, title, data);

        Assertions.assertEquals(expectedTitle, title);
        Assertions.assertEquals(expectedData, data);
    }

    @Test
    void testReadCSV4() throws IOException {
        file = "read_test.csv";

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
            writer.write("title4\nhElLo,YoU,ME,LoW");
        }

        List<String> expectedTitle = Collections.singletonList("title4");
        List<List<String>> expectedData = Collections.singletonList(Arrays.asList("hElLo", "YoU", "ME", "LoW"));

        CSVProcessor csvProcessor = new CSVProcessor();
        List<String> title = new ArrayList<>();
        List<List<String>> data = new ArrayList<>();
        csvProcessor.readCSV(file, title, data);

        Assertions.assertEquals(expectedTitle, title);
        Assertions.assertEquals(expectedData, data);
    }

    @Test
    void testReadCSV5() throws IOException {
        file = "read_test.csv";

        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
            writer.write("title5\nhElLo,YoU,ME,LoW");
        }

        List<String> expectedTitle = Collections.singletonList("title5");
        List<List<String>> expectedData = Collections.singletonList(Arrays.asList("hElLo", "YoU", "ME", "LoW"));

        CSVProcessor csvProcessor = new CSVProcessor();
        List<String> title = new ArrayList<>();
        List<List<String>> data = new ArrayList<>();
        csvProcessor.readCSV(file, title, data);

        Assertions.assertEquals(expectedTitle, title);
        Assertions.assertEquals(expectedData, data);
    }
}

class CSVProcessorTestWriteCSV {

    private String file;

    @Test
    void testWriteCSV1() throws IOException {
        file = "read_test.csv";

        CSVProcessor csvProcessor = new CSVProcessor();
        List<List<String>> data = Arrays.asList(
                Arrays.asList("a", "b", "c", "d"),
                Arrays.asList("1", "2", "3", "4")
        );

        // 断言写入操作的返回值
        Assertions.assertEquals(1, csvProcessor.writeCSV(data, file));

        // 读取以验证是否正确写入
        List<String> readTitle = new ArrayList<>();
        List<List<String>> readData = new ArrayList<>();
        csvProcessor.readCSV(file, readTitle, readData);

        Assertions.assertEquals(data.get(0), readTitle);
        Assertions.assertEquals(data.get(1), readData.get(0));
        Files.delete(Paths.get(file));
    }

    @Test
    void testWriteCSV2() throws IOException {
        file = "read_test.csv";

        CSVProcessor csvProcessor = new CSVProcessor();
        List<List<String>> data = Arrays.asList(
                Arrays.asList("aa", "bb", "cc", "dd"),
                Arrays.asList("1", "2", "3", "4")
        );

        Assertions.assertEquals(1, csvProcessor.writeCSV(data, file));

        List<String> readTitle = new ArrayList<>();
        List<List<String>> readData = new ArrayList<>();
        csvProcessor.readCSV(file, readTitle, readData);

        Assertions.assertEquals(data.get(0), readTitle);
        Assertions.assertEquals(data.get(1), readData.get(0));
        Files.delete(Paths.get(file));
    }

    @Test
    void testWriteCSV3() throws IOException {
        file = "read_test.csv";

        CSVProcessor csvProcessor = new CSVProcessor();
        List<List<String>> data = Arrays.asList(
                Arrays.asList("a", "b", "c", "d"),
                Arrays.asList("11", "22", "33", "44")
        );

        Assertions.assertEquals(1, csvProcessor.writeCSV(data, file));

        List<String> readTitle = new ArrayList<>();
        List<List<String>> readData = new ArrayList<>();
        csvProcessor.readCSV(file, readTitle, readData);

        Assertions.assertEquals(data.get(0), readTitle);
        Assertions.assertEquals(data.get(1), readData.get(0));
        Files.delete(Paths.get(file));
    }

    @Test
    void testWriteCSV4() throws IOException {
        file = "read_test.csv";

        CSVProcessor csvProcessor = new CSVProcessor();
        List<List<String>> data = Arrays.asList(
                Arrays.asList("e", "f", "g", "h"),
                Arrays.asList("1", "2", "3", "4")
        );

        Assertions.assertEquals(1, csvProcessor.writeCSV(data, file));

        List<String> readTitle = new ArrayList<>();
        List<List<String>> readData = new ArrayList<>();
        csvProcessor.readCSV(file, readTitle, readData);

        Assertions.assertEquals(data.get(0), readTitle);
        Assertions.assertEquals(data.get(1), readData.get(0));
        Files.delete(Paths.get(file));
    }

    @Test
    void testWriteCSV5() throws IOException {
        file = "read_test.csv";

        CSVProcessor csvProcessor = new CSVProcessor();
        List<List<String>> data = Arrays.asList(
                Arrays.asList("a", "b", "c", "d"),
                Arrays.asList("5", "6", "7", "8")
        );

        Assertions.assertEquals(1, csvProcessor.writeCSV(data, file));

        List<String> readTitle = new ArrayList<>();
        List<List<String>> readData = new ArrayList<>();
        csvProcessor.readCSV(file, readTitle, readData);

        Assertions.assertEquals(data.get(0), readTitle);
        Assertions.assertEquals(data.get(1), readData.get(0));
        Files.delete(Paths.get(file));
    }

    @Test
    void testWriteCSV6() {
        file = "";
        CSVProcessor csvProcessor = new CSVProcessor();
        Assertions.assertEquals(0, csvProcessor.writeCSV(Collections.emptyList(), file));
    }
}

class CSVProcessorTestProcessCSVData {

    private String file;
    private String fileProcess;

    @BeforeEach
    void setUp() throws IOException {
        file = "read_test.csv";
        fileProcess = "read_test_process.csv";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
            writer.write("a,b,c,d\nhElLo,YoU,ME,LoW,aBc");
        }
    }

    @Test
    void testProcessCSVData1() throws IOException {
        List<String> title = Arrays.asList("a", "b", "c", "d");
        List<String> data = Collections.singletonList("HELLO");

        CSVProcessor csvProcessor = new CSVProcessor();
        Assertions.assertEquals(1, csvProcessor.processCSVData(0, file));

        List<String> readTitle = new ArrayList<>();
        List<List<String>> readData = new ArrayList<>();
        csvProcessor.readCSV(fileProcess, readTitle, readData);

        Assertions.assertEquals(title, readTitle);
        Assertions.assertEquals(data, readData.get(0));
    }

    @Test
    void testProcessCSVData2() throws IOException {
        List<String> title = Arrays.asList("a", "b", "c", "d");
        List<String> data = Collections.singletonList("YOU");

        CSVProcessor csvProcessor = new CSVProcessor();
        Assertions.assertEquals(1, csvProcessor.processCSVData(1, file));

        List<String> readTitle = new ArrayList<>();
        List<List<String>> readData = new ArrayList<>();
        csvProcessor.readCSV(fileProcess, readTitle, readData);

        Assertions.assertEquals(title, readTitle);
        Assertions.assertEquals(data, readData.get(0));
    }

    @Test
    void testProcessCSVData3() throws IOException {
        List<String> title = Arrays.asList("a", "b", "c", "d");
        List<String> data = Collections.singletonList("ME");

        CSVProcessor csvProcessor = new CSVProcessor();
        Assertions.assertEquals(1, csvProcessor.processCSVData(2, file));

        List<String> readTitle = new ArrayList<>();
        List<List<String>> readData = new ArrayList<>();
        csvProcessor.readCSV(fileProcess, readTitle, readData);

        Assertions.assertEquals(title, readTitle);
        Assertions.assertEquals(data, readData.get(0));
    }

    @Test
    void testProcessCSVData4() throws IOException {
        List<String> title = Arrays.asList("a", "b", "c", "d");
        List<String> data = Collections.singletonList("LOW");

        CSVProcessor csvProcessor = new CSVProcessor();
        Assertions.assertEquals(1, csvProcessor.processCSVData(3, file));

        List<String> readTitle = new ArrayList<>();
        List<List<String>> readData = new ArrayList<>();
        csvProcessor.readCSV(fileProcess, readTitle, readData);

        Assertions.assertEquals(title, readTitle);
        Assertions.assertEquals(data, readData.get(0));
    }

    @Test
    void testProcessCSVData5() throws IOException {
        List<String> title = Arrays.asList("a", "b", "c", "d");
        List<String> data = Collections.singletonList("ABC");

        CSVProcessor csvProcessor = new CSVProcessor();
        Assertions.assertEquals(1, csvProcessor.processCSVData(4, file));

        List<String> readTitle = new ArrayList<>();
        List<List<String>> readData = new ArrayList<>();
        csvProcessor.readCSV(fileProcess, readTitle, readData);

        Assertions.assertEquals(title, readTitle);
        Assertions.assertEquals(data, readData.get(0));
    }
}

class CSVProcessorTestMain {

    private String file;
    private String fileProcess;

    @BeforeEach
    void setUp() throws IOException {
        file = "test.csv";
        fileProcess = "test_process.csv";
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(file))) {
            writer.write("a,b,c,d\nhElLo,YoU,ME,LoW");
        }
    }

    @Test
    void testMain() throws IOException {
        CSVProcessor csvProcessor = new CSVProcessor();
        List<List<String>> data = Arrays.asList(
                Arrays.asList("a", "b", "c", "d"),
                Arrays.asList("hElLo", "YoU", "ME", "LoW")
        );

        // 断言写入操作的返回值
        Assertions.assertEquals(1, csvProcessor.writeCSV(data, file));
        List<String> expectedTitle = Arrays.asList("a", "b", "c", "d");
        List<List<String>> expectedData = Collections.singletonList(Arrays.asList("hElLo", "YoU", "ME", "LoW"));
        List<String> title = new ArrayList<>();
        List<List<String>> readData = new ArrayList<>();
        csvProcessor.readCSV(file, title, readData);

        Assertions.assertEquals(expectedTitle, title);
        Assertions.assertEquals(expectedData, readData);

        title = Arrays.asList("a", "b", "c", "d");
        List<String> processedData = Collections.singletonList("HELLO");
        Assertions.assertEquals(1, csvProcessor.processCSVData(0, file));

        List<String> readTitle = new ArrayList<>();
        List<List<String>> readProcessedData = new ArrayList<>();
        csvProcessor.readCSV(fileProcess, readTitle, readProcessedData);

        Assertions.assertEquals(title, readTitle);
        Assertions.assertEquals(processedData, readProcessedData.get(0));
    }
}
