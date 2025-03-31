package org.example;

import com.google.gson.Gson;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;

public class JSONProcessor {

    public Map<String, Object> readJson(String filePath) {
        if (!Files.exists(Paths.get(filePath))) {
            return null;
        }
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            return new Gson().fromJson(reader, Map.class);
        } catch (Exception e) {
            return null;
        }
    }

    public boolean writeJson(Map<String, Object> data, String filePath) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
            new Gson().toJson(data, writer);
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public boolean processJson(String filePath, String removeKey) {
        Map<String, Object> data = readJson(filePath);
        if (data == null) {
            return false;
        }
        if (data.containsKey(removeKey)) {
            data.remove(removeKey);
            return writeJson(data, filePath);
        } else {
            return false;
        }
    }
}