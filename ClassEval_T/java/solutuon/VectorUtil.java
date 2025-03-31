package org.example;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class VectorUtil {

    public static double similarity(double[] vector1, double[] vector2) {
        double dotProduct = 0.0;
        double norm1 = 0.0;
        double norm2 = 0.0;
        for (int i = 0; i < vector1.length; i++) {
            dotProduct += vector1[i] * vector2[i];
            norm1 += Math.pow(vector1[i], 2);
            norm2 += Math.pow(vector2[i], 2);
        }
        double denominator = Math.sqrt(norm1) * Math.sqrt(norm2);
        return denominator == 0 ? 0.0 : dotProduct / denominator;
    }

    public static List<Double> cosineSimilarities(double[] vector1, List<double[]> vectorsAll) {
        List<Double> similarities = new ArrayList<>();
        double norm1 = Math.sqrt(dotProduct(vector1, vector1));
        if (norm1 == 0) {
            for (int i = 0; i < vectorsAll.size(); i++) {
                similarities.add(0.0);
            }
            return similarities;
        }
        for (double[] vector2 : vectorsAll) {
            double norm2 = Math.sqrt(dotProduct(vector2, vector2));
            if (norm2 == 0) {
                similarities.add(0.0);
            } else {
                double similarity = dotProduct(vector1, vector2) / (norm1 * norm2);
                similarities.add(similarity);
            }
        }
        return similarities;
    }

    public static double nSimilarity(List<double[]> vectorList1, List<double[]> vectorList2) {
        if (vectorList1.isEmpty() || vectorList2.isEmpty()) {
            throw new IllegalArgumentException("At least one of the passed lists is empty.");
        }
        double[] avgVector1 = averageVector(vectorList1);
        double[] avgVector2 = averageVector(vectorList2);
        return similarity(avgVector1, avgVector2);
    }

    public static Map<String, Double> computeIdfWeightDict(int totalNum, Map<String, Double> numberDict) {
        Map<String, Double> result = new HashMap<>();
        for (Map.Entry<String, Double> entry : numberDict.entrySet()) {
            double count = entry.getValue();
            double weight = Math.log((totalNum + 1) / (count + 1));
            result.put(entry.getKey(), weight);
        }
        return result;
    }

    private static double dotProduct(double[] vector1, double[] vector2) {
        double result = 0.0;
        for (int i = 0; i < vector1.length; i++) {
            result += vector1[i] * vector2[i];
        }
        return result;
    }

    private static double[] averageVector(List<double[]> vectors) {
        double[] avgVector = new double[vectors.get(0).length];
        for (double[] vector : vectors) {
            for (int i = 0; i < vector.length; i++) {
                avgVector[i] += vector[i];
            }
        }
        for (int i = 0; i < avgVector.length; i++) {
            avgVector[i] /= vectors.size();
        }
        return avgVector;
    }
}
