package to_be_tested;

public class MetricsCalculator {

    public int truePositives;

    public int falsePositives;

    public int falseNegatives;

    public int trueNegatives;

    public MetricsCalculator() {
        this.truePositives = 0;
        this.falsePositives = 0;
        this.falseNegatives = 0;
        this.trueNegatives = 0;
    }

    public void update(int[] predictedLabels, int[] trueLabels) {
        for (int i = 0; i < predictedLabels.length; i++) {
            if (predictedLabels[i] == 1 && trueLabels[i] == 1) {
                truePositives++;
            } else if (predictedLabels[i] == 1 && trueLabels[i] == 0) {
                falsePositives++;
            } else if (predictedLabels[i] == 0 && trueLabels[i] == 1) {
                falseNegatives++;
            } else if (predictedLabels[i] == 0 && trueLabels[i] == 0) {
                trueNegatives++;
            }
        }
    }

    public double precision(int[] predictedLabels, int[] trueLabels) {
        update(predictedLabels, trueLabels);
        if (truePositives + falsePositives == 0) {
            return 0.0;
        }
        return (double) truePositives / (truePositives + falsePositives);
    }

    public double recall(int[] predictedLabels, int[] trueLabels) {
        update(predictedLabels, trueLabels);
        if (truePositives + falseNegatives == 0) {
            return 0.0;
        }
        return (double) truePositives / (truePositives + falseNegatives);
    }

    public double f1Score(int[] predictedLabels, int[] trueLabels) {
        update(predictedLabels, trueLabels);
        double precision = precision(predictedLabels, trueLabels);
        double recall = recall(predictedLabels, trueLabels);
        if (precision + recall == 0.0) {
            return 0.0;
        }
        return (2 * precision * recall) / (precision + recall);
    }

    public double accuracy(int[] predictedLabels, int[] trueLabels) {
        update(predictedLabels, trueLabels);
        int total = truePositives + trueNegatives + falsePositives + falseNegatives;
        if (total == 0) {
            return 0.0;
        }
        return (double) (truePositives + trueNegatives) / total;
    }
}
