import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class CSVProcessor {

    public void readCSV(String fileName, List<List<String>> data) throws IOException {
        List<String> lines = Files.readAllLines(Paths.get(fileName));
        String[] titles = lines.get(0).split(",");
        for (int i = 1; i < lines.size(); i++) {
            String[] row = lines.get(i).split(",");
            List<String> rowData = new ArrayList<>();
            for (int j = 0; j < row.length; j++) {
                rowData.add(row[j]);
            }
            data.add(rowData);
        }
    }

    public void writeCSV(List<List<String>> data, String fileName) throws IOException {
        String content = data.stream().map(row -> String.join(",", row)).collect(Collectors.joining("\n"));
        Files.write(Paths.get(fileName), content.getBytes());
    }

    public void processCSVData(int N, String saveFileName) throws IOException {
        List<List<String>> data = new ArrayList<>();
        readCSV(saveFileName, data);
        List<String> columnData = data.stream().map(row -> row.get(N)).collect(Collectors.toList());
        columnData = columnData.stream().map(String::toUpperCase).collect(Collectors.toList());
        List<List<String>> newData = new ArrayList<>();
        newData.add(data.get(0));
        newData.add(columnData);
        writeCSV(newData, saveFileName.substring(0, saveFileName.lastIndexOf(".")) + "_process.csv");
    }
}