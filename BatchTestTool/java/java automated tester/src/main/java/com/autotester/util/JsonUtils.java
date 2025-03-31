package com.autotester.util;

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Paths;

public class JsonUtils {

    public static void saveCompileErrors(String filePath, String errors) {
        JsonObject json = new JsonObject();
        json.addProperty("file", Paths.get(filePath).getFileName().toString());
        json.addProperty("compile", "Fail");

        JsonArray errorList = new JsonArray();
        for (String errorLine : errors.split("\n")) {
            errorList.add(errorLine);
        }
        json.add("errors", errorList);

        saveToFile(json, "results/compile_errors.json");
    }

    public static void saveTestReport(String testClass, int total, int passed, int failed) {
        JsonObject json = new JsonObject();
        json.addProperty("testClass", testClass);
        json.addProperty("totalTests", total);
        json.addProperty("passed", passed);
        json.addProperty("failed", failed);

        saveToFile(json, "results/test_report.json");
    }

    private static void saveToFile(JsonObject json, String filePath) {
        try (FileWriter writer = new FileWriter(filePath, true)) {
            writer.write(json.toString() + "\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
