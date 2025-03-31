package org.example;

import java.io.*;
import java.util.*;

public class CSVProcessor {

    public void readCSV(String fileName, List<String> title, List<List<String>> data) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line = reader.readLine();
            if (line != null) {
                title.addAll(Arrays.asList(line.split(",")));

                String lineData;
                while ((lineData = reader.readLine()) != null) {
                    data.add(Arrays.asList(lineData.split(",")));
                }
            }
        }
    }

    public int writeCSV(List<String> title, List<List<String>> data, String fileName) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            writer.write(String.join(",", title));
            writer.newLine();

            for (List<String> row : data) {
                writer.write(String.join(",", row));
                writer.newLine();
            }
            return 1;
        } catch (IOException e) {
            return 0;
        }
    }

    public int writeCSV(List<List<String>> data, String fileName) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName))) {
            for (List<String> row : data) {
                writer.write(String.join(",", row));
                writer.newLine();
            }
            return 1;
        } catch (IOException e) {
            return 0;
        }
    }

    public int processCSVData(int N, String saveFileName) throws IOException {
        List<String> title = new ArrayList<>();
        List<List<String>> data = new ArrayList<>();
        readCSV(saveFileName, title, data);

        List<String> columnData = new ArrayList<>();
        for (List<String> row : data) {
            if (N < row.size()) {
                columnData.add(row.get(N).toUpperCase());
            }
        }

        List<List<String>> newData = new ArrayList<>();
        newData.add(columnData);

        return writeCSV(title, newData, saveFileName.split("\\.")[0] + "_process.csv");
    }
}
