package com.autotester.core;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.concurrent.TimeUnit;

public class TestRunner {
    public static String runTest(String testClassName) {
        Process process = null;
        StringBuilder testOutput = new StringBuilder();
        try {
            String classpath = "target/classes:lib/*";  // 添加所有依赖 JAR 文件
            ProcessBuilder pb = new ProcessBuilder(
                    "java",
                    "-cp", classpath,  // 使用通配符包含所有 JAR 文件
                    "org.junit.platform.console.ConsoleLauncher",
                    "--select-class", testClassName
            );
            try {
                process = pb.start();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            process.waitFor(30, TimeUnit.SECONDS);  // 设置超时

            // 读取标准输出
            try (BufferedReader outputReader = new BufferedReader(new InputStreamReader(process.getInputStream()))) {
                String line;
                while ((line = outputReader.readLine()) != null) {
                    testOutput.append(line).append("\n");
                }
            }

            // 读取错误输出
            try (BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()))) {
                String line;
                while ((line = errorReader.readLine()) != null) {
                    testOutput.append("ERROR: ").append(line).append("\n");
                }
            }

        } catch (IOException | InterruptedException e) {
            testOutput.append("Test execution failed: ").append(e.getMessage()).append("\n");
            e.printStackTrace();
        } finally {
            if (process != null) {
                process.destroy();  // 确保进程被销毁
            }
        }

        return testOutput.toString();
    }
}
