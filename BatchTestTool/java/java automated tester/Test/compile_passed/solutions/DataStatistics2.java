import java.util.List;
import java.util.Collections;

public class DataStatistics2 {
    private List<Double> data;

    public DataStatistics2(List<Double> data) {
        this.data = data;
    }

    public double getSum() {
        return data.stream()
                   .mapToDouble(Double::doubleValue)
                   .sum();
    }

    public double getMin() {
        return Collections.min(data);
    }

    public double getMax() {
        return Collections.max(data);
    }

    public double getVariance() {
        double mean = getSum() / data.size();
        double variance = 0.0;
        for (Double value : data) {
            variance += Math.pow(value - mean, 2);
        }
        variance /= data.size();
        return Math.round(variance * 100.0) / 100.0;
    }

    public double getStdDeviation() {
        double variance = getVariance();
        double std_dev = Math.sqrt(variance);
        return Math.round(std_dev * 100.0) / 100.0;
    }

    public double getCorrelation() {
        if (data.size() < 2) return 1.0;

        double mean = getSum() / data.size();
        double sumProd = 0.0;
        double sumSq = 0.0;

        for (Double value : data) {
            sumProd += (value - mean) * (value - mean);
            sumSq += (value - mean) * (value - mean);
        }

        return sumProd / sumSq;
    }
}