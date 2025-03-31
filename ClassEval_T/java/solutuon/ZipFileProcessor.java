package org.example;

import java.io.*;
import java.nio.file.*;
import java.util.zip.*;
import java.util.logging.*;

public class ZipFileProcessor {

    private static final Logger logger = Logger.getLogger(ZipFileProcessor.class.getName());
    private final Path zipFilePath;

    public ZipFileProcessor(String zipFileName) {
        this.zipFilePath = Paths.get(zipFileName);
    }

    ZipFile readZipFile() {
        if (Files.notExists(zipFilePath)) {
            logger.log(Level.SEVERE, "Zip file does not exist: " + zipFilePath.toAbsolutePath());
            return null;
        }
        try {
            return new ZipFile(zipFilePath.toFile());
        } catch (IOException e) {
            logger.log(Level.SEVERE, "Failed to read the zip file: " + zipFilePath.toAbsolutePath(), e);
            return null;
        }
    }

    public boolean extractAll(String outputDir) {
        Path outputDirPath = Paths.get(outputDir);
        try (ZipFile zipFile = readZipFile()) {
            if (zipFile == null) return false;

            if (Files.notExists(outputDirPath)) {
                try {
                    Files.createDirectories(outputDirPath);
                    logger.info("Created output directory: " + outputDirPath.toAbsolutePath());
                } catch (IOException e) {
                    logger.log(Level.SEVERE, "Failed to create output directory: " + outputDirPath.toAbsolutePath(), e);
                    return false;
                }
            }

            zipFile.stream().forEach(entry -> {
                Path filePath = outputDirPath.resolve(entry.getName());
                try {
                    if (entry.isDirectory()) {
                        if (Files.notExists(filePath)) {
                            Files.createDirectories(filePath);
                            logger.info("Created directory: " + filePath.toAbsolutePath());
                        }
                    } else {
                        try (InputStream in = zipFile.getInputStream(entry);
                             OutputStream out = Files.newOutputStream(filePath, StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING)) {
                            byte[] buffer = new byte[1024];
                            int len;
                            while ((len = in.read(buffer)) > 0) {
                                out.write(buffer, 0, len);
                            }
                            logger.info("Extracted file: " + filePath.toAbsolutePath());
                        }
                    }
                } catch (IOException e) {
                    logger.log(Level.SEVERE, "Failed to process entry: " + entry.getName(), e);
                }
            });

            return true;
        } catch (IOException e) {
            logger.log(Level.SEVERE, "Failed to extract files from zip: " + zipFilePath.toAbsolutePath(), e);
            return false;
        }
    }

    public boolean extractFile(String fileName, String outputDir) {
        Path outputDirPath = Paths.get(outputDir);
        Path filePath = outputDirPath.resolve(fileName);
        try (ZipFile zipFile = readZipFile()) {
            if (zipFile == null) return false;

            ZipEntry entry = zipFile.getEntry(fileName);
            if (entry == null) {
                logger.warning("File not found in zip: " + fileName);
                return false;
            }

            if (Files.notExists(filePath.getParent())) {
                try {
                    Files.createDirectories(filePath.getParent());
                    logger.info("Created parent directory: " + filePath.getParent().toAbsolutePath());
                } catch (IOException e) {
                    logger.log(Level.SEVERE, "Failed to create parent directory: " + filePath.getParent().toAbsolutePath(), e);
                    return false;
                }
            }

            try (InputStream in = zipFile.getInputStream(entry);
                 OutputStream out = Files.newOutputStream(filePath, StandardOpenOption.CREATE, StandardOpenOption.TRUNCATE_EXISTING)) {
                byte[] buffer = new byte[1024];
                int len;
                while ((len = in.read(buffer)) > 0) {
                    out.write(buffer, 0, len);
                }
                logger.info("Extracted file: " + filePath.toAbsolutePath());
            }

            return true;
        } catch (IOException e) {
            logger.log(Level.SEVERE, "Failed to extract file: " + fileName, e);
            return false;
        }
    }
}
