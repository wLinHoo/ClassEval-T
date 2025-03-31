package test_cases;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;
import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;
import to_be_tested.ZipFileProcessor;

public class ZipFileProcessorTest {

    private static final String TEST_FOLDER = "test_folder";
    private static final String OUTPUT_DIRECTORY = "output_directory";
    private static final String EXAMPLE_CONTENT = "This is an example file.";

    @BeforeEach
    public void setUp() throws IOException {
        Files.createDirectories(Paths.get(TEST_FOLDER));
        Files.createDirectories(Paths.get(OUTPUT_DIRECTORY));
    }

    @AfterEach
    public void tearDown() throws IOException {
        deleteDirectoryRecursively(Paths.get(TEST_FOLDER));
        deleteDirectoryRecursively(Paths.get(OUTPUT_DIRECTORY));
    }

    private void deleteDirectoryRecursively(Path path) throws IOException {
        if (Files.isDirectory(path)) {
            Files.walk(path)
                    .sorted((p1, p2) -> p2.compareTo(p1)) // Delete files before directories
                    .map(Path::toFile)
                    .forEach(File::delete);
        } else {
            Files.delete(path);
        }
    }

    @Test
    public void testReadZipFile1() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example1.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        ZipFile zipFile = processor.readZipFile();

        assertEquals("example1.zip", zipFile.getName());
        zipFile.close();
    }

    @Test
    public void testReadZipFile2() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example2.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        ZipFile zipFile = processor.readZipFile();

        assertEquals("example2.zip", zipFile.getName());
        zipFile.close();
    }

    @Test
    public void testReadZipFile3() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example3.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        ZipFile zipFile = processor.readZipFile();

        assertEquals("example3.zip", zipFile.getName());
        zipFile.close();
    }

    @Test
    public void testReadZipFile4() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example4.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        ZipFile zipFile = processor.readZipFile();

        assertEquals("example4.zip", zipFile.getName());
        zipFile.close();
    }

    @Test
    public void testReadZipFile5() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example5.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        ZipFile zipFile = processor.readZipFile();

        assertEquals("example5.zip", zipFile.getName());
        zipFile.close();
    }

    @Test
    public void testReadZipFile6() {
        ZipFileProcessor processor = new ZipFileProcessor("");
        ZipFile zipFile = processor.readZipFile();
        assertTrue(zipFile == null);
    }

    @Test
    public void testExtractAll1() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example1.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        boolean success = processor.extractAll(OUTPUT_DIRECTORY);

        assertTrue(success);
        assertTrue(Files.exists(Paths.get(OUTPUT_DIRECTORY + "/example1.txt")));
    }

    @Test
    public void testExtractAll2() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example2.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        boolean success = processor.extractAll(OUTPUT_DIRECTORY);

        assertTrue(success);
        assertTrue(Files.exists(Paths.get(OUTPUT_DIRECTORY + "/example2.txt")));
    }

    @Test
    public void testExtractAll3() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example3.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        boolean success = processor.extractAll(OUTPUT_DIRECTORY);

        assertTrue(success);
        assertTrue(Files.exists(Paths.get(OUTPUT_DIRECTORY + "/example3.txt")));
    }

    @Test
    public void testExtractAll4() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example4.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        boolean success = processor.extractAll(OUTPUT_DIRECTORY);

        assertTrue(success);
        assertTrue(Files.exists(Paths.get(OUTPUT_DIRECTORY + "/example4.txt")));
    }

    @Test
    public void testExtractAll5() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example5.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        boolean success = processor.extractAll(OUTPUT_DIRECTORY);

        assertTrue(success);
        assertTrue(Files.exists(Paths.get(OUTPUT_DIRECTORY + "/example5.txt")));
    }

    @Test
    public void testExtractAll6() {
        ZipFileProcessor processor = new ZipFileProcessor("");
        boolean success = processor.extractAll("");
        assertFalse(success);
    }

    @Test
    public void testExtractFile1() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example1.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        boolean success = processor.extractFile("example1.txt", OUTPUT_DIRECTORY);

        assertTrue(success);
        assertTrue(Files.exists(Paths.get(OUTPUT_DIRECTORY + "/example1.txt")));
    }

    @Test
    public void testExtractFile2() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example2.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        boolean success = processor.extractFile("example2.txt", OUTPUT_DIRECTORY);

        assertTrue(success);
        assertTrue(Files.exists(Paths.get(OUTPUT_DIRECTORY + "/example2.txt")));
    }

    @Test
    public void testExtractFile3() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example3.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        boolean success = processor.extractFile("example3.txt", OUTPUT_DIRECTORY);

        assertTrue(success);
        assertTrue(Files.exists(Paths.get(OUTPUT_DIRECTORY + "/example3.txt")));
    }

    @Test
    public void testExtractFile4() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example4.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        boolean success = processor.extractFile("example4.txt", OUTPUT_DIRECTORY);

        assertTrue(success);
        assertTrue(Files.exists(Paths.get(OUTPUT_DIRECTORY + "/example4.txt")));
    }

    @Test
    public void testExtractFile5() throws IOException {
        String exampleFilePath = TEST_FOLDER + "/example5.txt";
        writeExampleFile(exampleFilePath);

        String zipFileName = "example.zip";
        createZipFile(zipFileName, exampleFilePath);

        ZipFileProcessor processor = new ZipFileProcessor(zipFileName);
        boolean success = processor.extractFile("example5.txt", OUTPUT_DIRECTORY);

        assertTrue(success);
        assertTrue(Files.exists(Paths.get(OUTPUT_DIRECTORY + "/example5.txt")));
    }

    @Test
    public void testExtractFile6() {
        ZipFileProcessor processor = new ZipFileProcessor("example.zip");
        boolean success = processor.extractFile("nonexistent.txt", OUTPUT_DIRECTORY);
        assertFalse(success);
    }

    private void writeExampleFile(String filePath) throws IOException {
        try (FileWriter writer = new FileWriter(filePath)) {
            writer.write(EXAMPLE_CONTENT);
        }
    }

    private void createZipFile(String zipFileName, String filePath) throws IOException {
        try (java.util.zip.ZipOutputStream zipOut = new java.util.zip.ZipOutputStream(new java.io.FileOutputStream(zipFileName))) {
            File fileToZip = new File(filePath);
            try (java.io.FileInputStream fis = new java.io.FileInputStream(fileToZip)) {
                ZipEntry zipEntry = new ZipEntry(fileToZip.getName());
                zipOut.putNextEntry(zipEntry);
                byte[] bytes = new byte[1024];
                int length;
                while ((length = fis.read(bytes)) >= 0) {
                    zipOut.write(bytes, 0, length);
                }
                zipOut.closeEntry();
            }
        }
    }
}
