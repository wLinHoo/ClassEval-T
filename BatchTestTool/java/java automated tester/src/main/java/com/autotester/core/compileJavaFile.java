package com.autotester.core;

import com.autotester.util.JsonUtils;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.concurrent.TimeUnit;

public class compileJavaFile {

    // 设置超时时间（如30秒）
    private static final long TIMEOUT = 30;
    private static int compileSuccessCount = 0;  // 用于记录编译成功的文件数量

    public static boolean compile(String filePath) {
        Process process = null;
        try {
            // 启动 javac 进程
            ProcessBuilder pb = new ProcessBuilder("javac", filePath);
            process = pb.start();

            // 设置超时：如果超过指定时间则认为编译失败
            boolean finished = process.waitFor(TIMEOUT, TimeUnit.SECONDS);

            if (!finished) {
                // 如果超时，杀掉进程并返回失败
                process.destroy();
                System.out.println("Compilation timed out for: " + filePath);
                return false;
            }

            // 读取标准输出和错误输出
            StringBuilder output = new StringBuilder();
            try (BufferedReader outputReader = new BufferedReader(new InputStreamReader(process.getInputStream()))) {
                String line;
                while ((line = outputReader.readLine()) != null) {
                    output.append(line).append("\n");
                }
            }

            StringBuilder errorOutput = new StringBuilder();
            try (BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()))) {
                String line;
                while ((line = errorReader.readLine()) != null) {
                    errorOutput.append(line).append("\n");
                }
            }

            // 如果有错误输出，则保存错误信息
            if (errorOutput.length() > 0) {
                JsonUtils.saveCompileErrors(filePath, errorOutput.toString());
                System.out.println("Compilation failed for: " + filePath);
                return false;
            }

            // 如果没有错误输出，编译成功
            compileSuccessCount++;  // 编译成功，增加计数
            System.out.println("Compilation successful for: " + filePath);
            return true;

        } catch (IOException | InterruptedException e) {
            // 捕获并输出异常信息
            System.err.println("Error during compilation of file: " + filePath);
            e.printStackTrace();
            return false;
        } finally {
            // 确保在所有情况下都正确销毁进程
            if (process != null) {
                process.destroy();
            }
        }
    }

    // 获取编译成功的总数
    public static void printCompileSuccessCount() {
        System.out.println("Total number of successful compilations: " + compileSuccessCount);
    }
}
