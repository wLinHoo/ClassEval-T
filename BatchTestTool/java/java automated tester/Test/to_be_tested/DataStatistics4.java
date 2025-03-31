package to_be_tested;

import java.lang.Math;
import java.math.BigDecimal;
import java.math.RoundingMode;

public class DataStatistics4 {

    public static double skewness(double[] data) {
        int n = data.length;
        double mean = 0;
        for (double x : data) {
            mean += x;
        }
        mean /= n;
        double variance = 0;
        for (double x : data) {
            variance += Math.pow(x - mean, 2);
        }
        variance /= n;
        double stdDeviation = Math.sqrt(variance);
        double skewness = 0;
        for (double x : data) {
            skewness += Math.pow(x - mean, 3);
        }
        skewness /= (n * (n - 1) * (n - 2) * Math.pow(stdDeviation, 3));
        if (stdDeviation != 0) {
            skewness = skewness;
        } else {
            skewness = 0;
        }
        return skewness;
    }

    public static double kurtosis(double[] data) {
        int n = data.length;
        double mean = 0;
        for (double x : data) {
            mean += x;
        }
        mean /= n;
        double std_dev = 0;
        for (double x : data) {
            std_dev += Math.pow(x - mean, 2);
        }
        std_dev = Math.sqrt(std_dev / n);
        if (std_dev == 0) {
            return Double.NaN;
        }
        double[] centered_data = new double[n];
        for (int i = 0; i < n; i++) {
            centered_data[i] = data[i] - mean;
        }
        double fourth_moment = 0;
        for (double x : centered_data) {
            fourth_moment += Math.pow(x, 4);
        }
        fourth_moment /= n;
        double kurtosis_value = (fourth_moment / Math.pow(std_dev, 4)) - 3;
        return kurtosis_value;
    }

    public static double[] pdf(double[] data, double mu, double sigma) {
        double[] pdfValues = new double[data.length];
        for (int i = 0; i < data.length; i++) {
            pdfValues[i] = 1 / (sigma * Math.sqrt(2 * Math.PI)) * Math.exp(-0.5 * Math.pow((data[i] - mu) / sigma, 2));
        }
        return pdfValues;
    }

    public static double correlationCoefficient(double[] data1, double[] data2) {
        int n = data1.length;
        double mean1 = calculateMean(data1);
        double mean2 = calculateMean(data2);
        double numerator = 0;
        double denominator1 = 0;
        double denominator2 = 0;
        for (int i = 0; i < n; i++) {
            numerator += (data1[i] - mean1) * (data2[i] - mean2);
            denominator1 += Math.pow(data1[i] - mean1, 2);
            denominator2 += Math.pow(data2[i] - mean2, 2);
        }
        double denominator = Math.sqrt(denominator1) * Math.sqrt(denominator2);
        if (denominator != 0) {
            return numerator / denominator;
        } else {
            return 0;
        }
    }

    public static double calculateMean(double[] data) {
        int n = data.length;
        double sum = 0;
        for (double value : data) {
            sum += value;
        }
        return sum / n;
    }
}
