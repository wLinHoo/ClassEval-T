package org.example;

import java.util.List;
import java.util.stream.DoubleStream;

public class DataStatistics2 {
    private double[] data;

    public DataStatistics2(List<Integer> data) {
        this.data = data.stream().mapToDouble(Integer::doubleValue).toArray();
    }

    public double getSum() {
        return DoubleStream.of(data).sum();
    }

    public double getMin() {
        return DoubleStream.of(data).min().orElse(Double.NaN);
    }

    public double getMax() {
        return DoubleStream.of(data).max().orElse(Double.NaN);
    }

    public double getVariance() {
        double mean = getSum() / data.length;
        return DoubleStream.of(data)
                .map(val -> (val - mean) * (val - mean))
                .average()
                .orElse(Double.NaN);
    }

    public double getStdDeviation() {
        return Math.sqrt(getVariance());
    }

    public double getCorrelation() {
        return 1.0;
    }
}
