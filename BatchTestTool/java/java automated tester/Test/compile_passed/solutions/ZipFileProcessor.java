import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import java.util.Enumeration;
import java.util.List;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;
import java.util.zip.ZipInputStream;
import java.util.zip.ZipOutputStream;

public class ZipFileProcessor {
    private String fileName;

    public ZipFileProcessor(String fileName) {
        this.fileName = fileName;
    }

    public boolean extractAll(String outputPath) {
        try (ZipFile zipFile = new ZipFile(fileName)) {
            Enumeration<? extends ZipEntry> entries = zipFile.entries();
            while (entries.hasMoreElements()) {
                ZipEntry entry = entries.nextElement();
                File outFile = new File(outputPath, entry.getName());

                if (entry.isDirectory()) {
                    outFile.mkdirs();
                } else {
                    outFile.getParentFile().mkdirs();
                    Files.copy(zipFile.getInputStream(entry), outFile.toPath(), StandardCopyOption.REPLACE_EXISTING);
                }
            }
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    public boolean extractFile(String fileName, String outputPath) {
        byte[] buffer = new byte[1024];

        try (ZipInputStream zipInputStream = new ZipInputStream(new FileInputStream(this.fileName))) {
            ZipEntry zipEntry;
            while ((zipEntry = zipInputStream.getNextEntry()) != null) {
                if (zipEntry.getName().equals(fileName)) {
                    File outputFile = new File(outputPath, zipEntry.getName());
                    try (FileOutputStream fileOutputStream = new FileOutputStream(outputFile)) {
                        int len;
                        while ((len = zipInputStream.read(buffer)) > 0) {
                            fileOutputStream.write(buffer, 0, len);
                        }
                    }
                    return true;
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
        return false;
    }

    public boolean createZipFile(List<String> files, String outputFileName) {
        try (ZipOutputStream zipOut = new ZipOutputStream(new FileOutputStream(outputFileName))) {
            for (String filePath : files) {
                File fileToZip = new File(filePath);
                try (FileInputStream fis = new FileInputStream(fileToZip)) {
                    ZipEntry zipEntry = new ZipEntry(fileToZip.getName());
                    zipOut.putNextEntry(zipEntry);

                    byte[] bytes = new byte[1024];
                    int length;
                    while ((length = fis.read(bytes)) >= 0) {
                        zipOut.write(bytes, 0, length);
                    }
                }
            }
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    public ZipFile readZipFile() {
        try {
            ZipFile zipFile = new ZipFile(this.fileName);
            return zipFile;
        } catch (IOException e) {
            return null;
        }
    }

    public static void main(String[] args) {
        ZipFileProcessor processor = new ZipFileProcessor("example.zip");
        boolean result = processor.extractAll("outputDirectory");

        if (result) {
            System.out.println("Extraction successful.");
        } else {
            System.out.println("Extraction failed.");
        }

        boolean result2 = processor.extractFile("file.txt", "outputDir");
        System.out.println("Extraction success: " + result2);

        ZipFile zipFile = processor.readZipFile();
        if (zipFile != null) {
            System.out.println("Zip file opened successfully.");
        } else {
            System.out.println("Failed to open zip file.");
        }
    }
}