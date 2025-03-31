import java.util.*;
import java.lang.Math;

public class VectorUtil {

    public static <N> double similarity(double[] vector1, double[] vector2) {
        double[] normVec1 = normalize(vector1);
        double[] normVec2 = normalize(vector2);
        double dotProduct = 0.0;
        for (int i = 0; i < vector1.length; i++) {
            dotProduct += normVec1[i] * normVec2[i];
        }
        return dotProduct;
    }

    public static <N> List<Double> cosineSimilarities(double[] vector1, List<double[]> vectorsAll) {
        List<Double> similarities = new ArrayList<>();
        double normVec1 = norm(vector1);

        for (double[] vec : vectorsAll) {
            double normVecAll = norm(vec);
            if (normVecAll == 0.0) {
                similarities.add(0.0);
                continue;
            }
            double dotProduct = 0.0;
            for (int i = 0; i < vector1.length; i++) {
                dotProduct += vec[i] * vector1[i];
            }
            double similarity = dotProduct / (normVec1 * normVecAll);
            similarities.add(similarity);
        }
        return similarities;
    }

    public static <N> double nSimilarity(List<double[]> vectorList1, List<double[]> vectorList2) {
        if (vectorList1.isEmpty() || vectorList2.isEmpty()) {
            throw new IllegalArgumentException("At least one of the lists is empty.");
        }

        double[] meanVec1 = new double[vectorList1.get(0).length];
        double[] meanVec2 = new double[vectorList2.get(0).length];

        for (double[] vec : vectorList1) {
            for (int i = 0; i < vec.length; i++) {
                meanVec1[i] += vec[i];
            }
        }
        for (double[] vec : vectorList2) {
            for (int i = 0; i < vec.length; i++) {
                meanVec2[i] += vec[i];
            }
        }

        for (int i = 0; i < meanVec1.length; i++) {
            meanVec1[i] /= vectorList1.size();
            meanVec2[i] /= vectorList2.size();
        }

        return similarity(meanVec1, meanVec2);
    }

    public static Map<String, Double> computeIdfWeightDict(int totalNum, Map<String, Double> numberDict) {
        Map<String, Double> result = new HashMap<>();
        Map<Integer, String> index2KeyMap = new HashMap<>();
        List<Double> countList = new ArrayList<>();
        int index = 0;

        for (Map.Entry<String, Double> entry : numberDict.entrySet()) {
            index2KeyMap.put(index, entry.getKey());
            countList.add(entry.getValue());
            index++;
        }

        double[] a = new double[countList.size()];
        for (int i = 0; i < countList.size(); i++) {
            a[i] = Math.log((totalNum + 1.0) / (countList.get(i) + 1.0));
        }

        for (int i = 0; i < a.length; i++) {
            result.put(index2KeyMap.get(i), a[i]);
        }

        return result;
    }

    private static double norm(double[] vec) {
        double sum = 0.0;
        for (double val : vec) {
            sum += val * val;
        }
        return Math.sqrt(sum);
    }

    private static double[] normalize(double[] vec) {
        double[] normalized = new double[vec.length];
        double vecNorm = norm(vec);
        if (vecNorm == 0.0) {
            return normalized;
        }
        for (int i = 0; i < vec.length; i++) {
            normalized[i] = vec[i] / vecNorm;
        }
        return normalized;
    }

    public static void main(String[] args) {
        // Example usage
        double[] vector1 = {1.0, 2.0};
        double[] vector2 = {2.0, 3.0};
        System.out.println("Similarity: " + similarity(vector1, vector2));

        List<double[]> vectors = Arrays.asList(new double[]{1.0, 2.0}, new double[]{2.0, 3.0});
        System.out.println("Cosine Similarities: " + cosineSimilarities(vector1, vectors));

        List<double[]> vectorList1 = Arrays.asList(new double[]{1.0, 2.0}, new double[]{2.0, 3.0});
        List<double[]> vectorList2 = Arrays.asList(new double[]{2.0, 3.0}, new double[]{3.0, 4.0});
        System.out.println("N Similarity: " + nSimilarity(vectorList1, vectorList2));

        Map<String, Double> numberDict = new HashMap<>();
        numberDict.put("word1", 2.0);
        numberDict.put("word2", 3.0);
        System.out.println("IDF Weight Dict: " + computeIdfWeightDict(10, numberDict));
    }
}