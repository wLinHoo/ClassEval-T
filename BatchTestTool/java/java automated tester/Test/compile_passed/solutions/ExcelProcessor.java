import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ExcelProcessor {
    public ExcelProcessor() {
    }

    public List<List<Object>> readExcel(String fileName) {
        List<List<Object>> data = new ArrayList<>();
        try {
            // Initialize OpenXLSX library
            // You need to add the OpenXLSX library to your project or download it manually
            // This code is for illustration purposes only
            // OpenXLSX.XLDocument doc = new OpenXLSX.XLDocument();
            // doc.open(fileName);

            // Rest of the code is omitted as it's not possible to replicate the exact functionality without OpenXLSX library
        } catch (Exception e) {
            return new ArrayList<>();
        }
        return data;
    }

    public int writeExcel(List<List<Object>> data, String fileName) {
        try {
            // Initialize OpenXLSX library
            // You need to add the OpenXLSX library to your project or download it manually
            // This code is for illustration purposes only
            // OpenXLSX.XLDocument doc = new OpenXLSX.XLDocument();
            // doc.create(fileName);

            // Rest of the code is omitted as it's not possible to replicate the exact functionality without OpenXLSX library
        } catch (Exception e) {
            return 0;
        }
        return 1;
    }

    public Pair<Integer, String> processExcelData(int N, String saveFileName) {
        List<List<Object>> data = readExcel(saveFileName);
        if (data.isEmpty() || N >= data.get(0).size()) {
            return new Pair<>(0, "");
        }

        List<List<Object>> newData = new ArrayList<>();
        for (List<Object> row : data) {
            List<Object> newRow = new ArrayList<>(row);
            if (N < row.size()) {
                if (row.get(N) instanceof String) {
                    String value = (String) row.get(N);
                    if (!Character.isDigit(value.charAt(0))) {
                        value = value.toLowerCase();
                        newRow.set(N, value);
                    } else {
                        newRow.set(N, value.substring(0, 1));
                    }
                } else {
                    newRow.set(N, ((Integer) row.get(N)));
                }
            }
            newData.add(newRow);
        }

        String newFileName = saveFileName.substring(0, saveFileName.lastIndexOf('.')) + "_process.xlsx";
        int success = writeExcel(newData, newFileName);
        return new Pair<>(success, newFileName);
    }
}

class Pair<K, V> {
    public K key;
    public V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }
}