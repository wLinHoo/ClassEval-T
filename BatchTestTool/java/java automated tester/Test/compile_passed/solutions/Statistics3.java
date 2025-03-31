import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class Statistics3 {

    // Static method to calculate the correlation between two lists of numbers
    public static Double correlation(List<Double> x, List<Double> y) {
        int n = x.size();
        double meanX = x.stream().mapToDouble(Double::doubleValue).sum() / n;
        double meanY = y.stream().mapToDouble(Double::doubleValue).sum() / n;

        double numerator = 0.0;
        double sumX = 0.0;
        double sumY = 0.0;

        for (int i = 0; i < n; i++) {
            double diffX = x.get(i) - meanX;
            double diffY = y.get(i) - meanY;
            numerator += diffX * diffY;
            sumX += diffX * diffX;
            sumY += diffY * diffY;
        }

        double denominator = Math.sqrt(sumX * sumY);

        if (denominator == 0) {
            return null;
        }

        return numerator / denominator;
    }

    // Static method to calculate the correlation matrix for a 2D list of numbers
    public static List<List<Double>> correlationMatrix(List<List<Double>> data) {
        int columns = data.get(0).size();
        List<List<Double>> matrix = new ArrayList<>();

        for (int i = 0; i < columns; i++) {
            List<Double> row = new ArrayList<>();
            for (int j = 0; j < columns; j++) {
                List<Double> column1 = new ArrayList<>();
                List<Double> column2 = new ArrayList<>();

                for (List<Double> rowData : data) {
                    column1.add(rowData.get(i));
                    column2.add(rowData.get(j));
                }

                Double correlation = correlation(column1, column2);
                row.add(correlation);
            }
            matrix.add(row);
        }

        return matrix;
    }

    public static double median(int[] data) {
        Arrays.sort(data);
        int n = data.length;
        if (n % 2 == 1) {
            return data[n / 2];
        } else {
            return (data[n / 2 - 1] + data[n / 2]) / 2.0;
        }
    }

    public static List<Integer> mode(int[] data) {
        Map<Integer, Integer> counts = new HashMap<>();

        // Count the occurrences of each value
        for (int value : data) {
            counts.put(value, counts.getOrDefault(value, 0) + 1);
        }

        // Find the maximum count
        int maxCount = 0;
        for (int count : counts.values()) {
            if (count > maxCount) {
                maxCount = count;
            }
        }

        // Find the mode values
        List<Integer> modeValues = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            if (entry.getValue() == maxCount) {
                modeValues.add(entry.getKey());
            }
        }

        return modeValues;
    }

    public static Double mean(List<Double> data) {
        if (data.isEmpty()) {
            return null;
        }
        double sum = 0.0;
        for (Double num : data) {
            sum += num;
        }
        return sum / data.size();
    }

    public static Double standardDeviation(List<Double> data) {
        int n = data.size();
        if (n < 2) {
            return null;
        }
        Double meanValue = mean(data);
        double variance = 0.0;
        for (Double x : data) {
            variance += Math.pow(x - meanValue, 2);
        }
        variance /= (n - 1);
        return Math.sqrt(variance);
    }

    public static List<Double> zScore(List<Double> data) {
        Double mean = mean(data);
        Double stdDeviation = standardDeviation(data);
        if (stdDeviation == null || stdDeviation == 0) {
            return null;
        }
        List<Double> zScores = new java.util.ArrayList<>();
        for (Double x : data) {
            zScores.add((x - mean) / stdDeviation);
        }
        return zScores;
    }

    public static void main(String[] args) {
        // You can test the methods here if needed
    }
}