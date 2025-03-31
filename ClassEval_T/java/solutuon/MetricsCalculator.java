package org.example;

public class MetricsCalculator {
    int truePositives;
    int falsePositives;
    int falseNegatives;
    int trueNegatives;

    public MetricsCalculator() {
        this.truePositives = 0;
        this.falsePositives = 0;
        this.falseNegatives = 0;
        this.trueNegatives = 0;
    }

    public void update(int[] predictedLabels, int[] trueLabels) {
        for (int i = 0; i < predictedLabels.length; i++) {
            if (predictedLabels[i] == 1 && trueLabels[i] == 1) {
                this.truePositives++;
            } else if (predictedLabels[i] == 1 && trueLabels[i] == 0) {
                this.falsePositives++;
            } else if (predictedLabels[i] == 0 && trueLabels[i] == 1) {
                this.falseNegatives++;
            } else if (predictedLabels[i] == 0 && trueLabels[i] == 0) {
                this.trueNegatives++;
            }
        }
    }

    public double precision(int[] predictedLabels, int[] trueLabels) {
        update(predictedLabels, trueLabels);
        if (this.truePositives + this.falsePositives == 0) {
            return 0.0;
        }
        return (double) this.truePositives / (this.truePositives + this.falsePositives);
    }

    public double recall(int[] predictedLabels, int[] trueLabels) {
        update(predictedLabels, trueLabels);
        if (this.truePositives + this.falseNegatives == 0) {
            return 0.0;
        }
        return (double) this.truePositives / (this.truePositives + this.falseNegatives);
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
        int total = this.truePositives + this.trueNegatives + this.falsePositives + this.falseNegatives;
        if (total == 0) {
            return 0.0;
        }
        return (double) (this.truePositives + this.trueNegatives) / total;
    }

    public static void main(String[] args) {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 0, 0, 1};
        System.out.println(mc.precision(predictedLabels, trueLabels));
        System.out.println(mc.recall(predictedLabels, trueLabels));
        System.out.println(mc.f1Score(predictedLabels, trueLabels));
        System.out.println(mc.accuracy(predictedLabels, trueLabels));
    }
}