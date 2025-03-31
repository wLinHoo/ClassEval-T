package org.example;

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class DataStatistics4 {

    public static double correlationCoefficient(List<Double> data1, List<Double> data2) {
        int n = data1.size();
        double mean1 = data1.stream().mapToDouble(Double::doubleValue).average().orElse(0);
        double mean2 = data2.stream().mapToDouble(Double::doubleValue).average().orElse(0);

        double numerator = IntStream.range(0, n)
                .mapToDouble(i -> (data1.get(i) - mean1) * (data2.get(i) - mean2))
                .sum();

        double denominator = Math.sqrt(data1.stream()
                .mapToDouble(x -> (x - mean1) * (x - mean1))
                .sum()) * Math.sqrt(data2.stream()
                .mapToDouble(x -> (x - mean2) * (x - mean2))
                .sum());

        return denominator != 0 ? numerator / denominator : 0;
    }

    public static double skewness(List<Double> data) {
        int n = data.size();
        double mean = data.stream().mapToDouble(Double::doubleValue).average().orElse(0);
        double variance = data.stream()
                .mapToDouble(x -> (x - mean) * (x - mean))
                .average().orElse(0);
        double stdDeviation = Math.sqrt(variance);

        if (stdDeviation == 0) {
            return 0;
        }

        double skewness = data.stream()
                .mapToDouble(x -> (x - mean) * (x - mean) * (x - mean))
                .sum() * n / ((n - 1) * (n - 2) * Math.pow(stdDeviation, 3));

        return skewness;
    }

    public static double kurtosis(List<Double> data) {
        int n = data.size();
        double mean = data.stream().mapToDouble(Double::doubleValue).average().orElse(0);
        double stdDev = Math.sqrt(data.stream()
                .mapToDouble(x -> (x - mean) * (x - mean))
                .average().orElse(0));

        if (stdDev == 0) {
            return Double.NaN;
        }

        List<Double> centeredData = data.stream()
                .map(x -> x - mean)
                .collect(Collectors.toList());

        double fourthMoment = centeredData.stream()
                .mapToDouble(x -> Math.pow(x, 4))
                .average().orElse(0);

        double kurtosisValue = (fourthMoment / Math.pow(stdDev, 4)) - 3;

        return kurtosisValue;
    }

    public static List<Double> pdf(List<Double> data, double mu, double sigma) {
        return data.stream()
                .map(x -> (1 / (sigma * Math.sqrt(2 * Math.PI))) * Math.exp(-0.5 * Math.pow((x - mu) / sigma, 2)))
                .collect(Collectors.toList());
    }
}
