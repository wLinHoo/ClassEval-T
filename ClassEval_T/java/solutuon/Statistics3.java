package org.example;

import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.DoubleStream;

public class Statistics3 {

    public double median(int[] data) {
        int[] sortedData = Arrays.copyOf(data, data.length);
        Arrays.sort(sortedData);
        int n = sortedData.length;
        if (n % 2 == 1) {
            return sortedData[n / 2];
        } else {
            return (sortedData[n / 2 - 1] + sortedData[n / 2]) / 2.0;
        }
    }

    public int[] mode(int[] data) {
        Map<Integer, Long> counts = Arrays.stream(data)
                .boxed()
                .collect(Collectors.groupingBy(e -> e, Collectors.counting()));
        long maxCount = Collections.max(counts.values());
        return counts.entrySet().stream()
                .filter(entry -> entry.getValue() == maxCount)
                .mapToInt(Map.Entry::getKey)
                .toArray();
    }

    public Double correlation(int[] x, int[] y) {
        if (x.length != y.length || x.length == 0) {
            return null;
        }

        double meanX = Arrays.stream(x).average().orElse(Double.NaN);
        double meanY = Arrays.stream(y).average().orElse(Double.NaN);

        double numerator = 0.0;
        double denomX = 0.0;
        double denomY = 0.0;

        for (int i = 0; i < x.length; i++) {
            double diffX = x[i] - meanX;
            double diffY = y[i] - meanY;
            numerator += diffX * diffY;
            denomX += diffX * diffX;
            denomY += diffY * diffY;
        }

        if (denomX == 0 || denomY == 0) {
            return null;
        }

        return numerator / Math.sqrt(denomX * denomY);
    }

    public Double mean(int[] data) {
        if (data.length == 0) {
            return null;
        }
        return Arrays.stream(data).average().orElse(Double.NaN);
    }

    public double[][] correlationMatrix(int[][] data) {
        int numCols = data[0].length;
        double[][] matrix = new double[numCols][numCols];

        for (int i = 0; i < numCols; i++) {
            for (int j = 0; j < numCols; j++) {
                int finalI = i;
                int[] column1 = Arrays.stream(data).mapToInt(row -> row[finalI]).toArray();
                int finalJ = j;
                int[] column2 = Arrays.stream(data).mapToInt(row -> row[finalJ]).toArray();
                matrix[i][j] = correlation(column1, column2) != null ? correlation(column1, column2) : Double.NaN;
            }
        }

        return matrix;
    }

    public Double standardDeviation(int[] data) {
        if (data.length < 2) {
            return null;
        }
        double mean = mean(data);
        double variance = Arrays.stream(data)
                .mapToDouble(x -> Math.pow(x - mean, 2))
                .sum() / (data.length - 1);
        return Math.sqrt(variance);
    }

    public double[] zScore(int[] data) {
        Double mean = mean(data);
        Double stdDeviation = standardDeviation(data);
        if (mean == null || stdDeviation == null || stdDeviation == 0) {
            return null;
        }
        return Arrays.stream(data)
                .mapToDouble(x -> (x - mean) / stdDeviation)
                .toArray();
    }
}
