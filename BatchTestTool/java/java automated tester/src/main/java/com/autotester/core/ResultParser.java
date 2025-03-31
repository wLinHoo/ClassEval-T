package com.autotester.core;

import com.autotester.util.JsonUtils;

public class ResultParser {

    public static void parseAndSaveResults(String testOutput, String testClassName) {
        int totalTests = 0;
        int passed = 0;
        int failed = 0;

        // 解析JUnit输出（示例）
        String[] lines = testOutput.split("\n");
        for (String line : lines) {
            if (line.contains("Tests run:")) {
                String[] parts = line.split(",");
                for (String part : parts) {
                    if (part.contains("Tests run:")) {
                        totalTests = Integer.parseInt(part.split(":")[1].trim());
                    } else if (part.contains("Failures:")) {
                        failed = Integer.parseInt(part.split(":")[1].trim());
                    }
                }
                passed = totalTests - failed;
                break;
            }
        }

        JsonUtils.saveTestReport(testClassName, totalTests, passed, failed);
    }
}
