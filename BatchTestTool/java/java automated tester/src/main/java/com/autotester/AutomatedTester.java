package com.autotester;

import com.autotester.core.compileJavaFile;
import com.autotester.core.ResultParser;
import com.autotester.core.TestRunner;
import com.autotester.util.FileUtils;
import java.io.File;
import java.io.IOException;

public class AutomatedTester {
    private static final String SOURCE_DIR = "Test/to_be_tested";
    private static final String TEST_DIR = "Test/test_cases";
    private static final String PASSED_DIR = "Test/compile_passed/solutions";
    private static final long TIMEOUT_MILLIS = 5000; // 设置超时为5000毫秒（5秒）

    public static void main(String[] args) {
        FileUtils.createDirectoryIfNotExists(PASSED_DIR);
        FileUtils.createDirectoryIfNotExists("results");
        File[] sourceFiles = new File(SOURCE_DIR).listFiles(
                (dir, name) -> name.endsWith(".java")
        );
        if (sourceFiles == null) return;

        int totalFiles = sourceFiles.length;
        int successCount = 0;
        int failureCount = 0;
        int timeoutCount = 0; // 超时代码计数器

        for (File sourceFile : sourceFiles) {
            String sourcePath = sourceFile.getAbsolutePath();
            long startTime = System.currentTimeMillis(); // 记录开始时间

            boolean compileSuccess = compileJavaFile.compile(sourcePath);

            long compileTime = System.currentTimeMillis() - startTime; // 计算编译时间

            if (compileTime > TIMEOUT_MILLIS) {
                timeoutCount++; // 记录超时代码
                System.out.println("编译超时: " + sourcePath + " 超过 " + TIMEOUT_MILLIS + " 毫秒");
                failureCount++; // 超时也算失败
            } else if (compileSuccess) {
                successCount++;
                try {
                    FileUtils.copyFileToDirectory(sourcePath, PASSED_DIR);
                } catch (IOException e) {
                    System.err.println("文件复制失败: " + sourcePath);
                    e.printStackTrace();
                }
            } else {
                failureCount++;
                // 删除编译失败的文件
                try {
                    if (FileUtils.deleteFile(sourcePath)) {
                        System.out.println("已删除编译失败文件: " + sourcePath);
                    } else {
                        System.out.println("文件删除失败: " + sourcePath);
                    }
                } catch (IOException e) {
                    System.err.println("删除文件时发生错误: " + sourcePath);
                    e.printStackTrace();
                }
            }
        }

        // 输出统计结果
        System.out.println("\n编译结果统计:");
        System.out.println("总文件数: " + totalFiles);
        System.out.println("编译成功: " + successCount);
        System.out.println("编译失败: " + failureCount);
        System.out.println("超时代码: " + timeoutCount);
        System.out.println("失败文件已自动删除");
    }
}