package com.autotester.util;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class FileUtils {
    public static void copyFileToDirectory(String sourcePath, String destDir) throws IOException {
        File sourceFile = new File(sourcePath);
        File destDirectory = new File(destDir);
        org.apache.commons.io.FileUtils.copyFileToDirectory(sourceFile, destDirectory);
    }

    public static void createDirectoryIfNotExists(String dirPath) {
        File dir = new File(dirPath);
        if (!dir.exists()) {
            dir.mkdirs();
        }
    }
    public static boolean deleteFile(String filePath) throws IOException {
        Path path = Paths.get(filePath);
        return Files.deleteIfExists(path);
    }
}
