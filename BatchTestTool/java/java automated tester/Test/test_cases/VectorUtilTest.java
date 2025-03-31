package test_cases;
import to_be_tested.VectorUtil;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.*;

public class VectorUtilTest {

    @Test
    void testSimilarity1() {
        double[] vector1 = {1, 1};
        double[] vector2 = {1, 0};
        double similarity = VectorUtil.similarity(vector1, vector2);
        assertEquals(0.7071067811865475, similarity, 1e-15);
    }

    @Test
    void testSimilarity2() {
        double[] vector1 = {1, 1};
        double[] vector2 = {0, 0};
        double similarity = VectorUtil.similarity(vector1, vector2);
        assertEquals(0.0, similarity, 1e-15);
    }

    @Test
    void testSimilarity3() {
        double[] vector1 = {1, 1};
        double[] vector2 = {1, 1};
        double similarity = VectorUtil.similarity(vector1, vector2);
        assertEquals(1.0, similarity, 1e-15);
    }

    @Test
    void testSimilarity4() {
        double[] vector1 = {1, 1, 0, 1, 0, 1, 0, 1};
        double[] vector2 = {1, 0, 0, 1, 0, 1, 0, 1};
        double similarity = VectorUtil.similarity(vector1, vector2);
        assertEquals(0.8944271909999159, similarity, 1e-15);
    }

    @Test
    void testSimilarity5() {
        double[] vector1 = {1, 1, 1, 1, 1, 1, 1, 1};
        double[] vector2 = {0, 0, 0, 0, 0, 0, 0, 0};
        double similarity = VectorUtil.similarity(vector1, vector2);
        assertEquals(0.0, similarity, 1e-15);
    }

    @Test
    void testCosineSimilarities1() {
        double[] vector1 = {1, 1};
        List<double[]> vectorsAll = List.of(new double[]{1, 0}, new double[]{1, 1});
        List<Double> similarities = VectorUtil.cosineSimilarities(vector1, vectorsAll);
        List<Double> expected = List.of(0.7071067811865475, 1.0);
        for (int i = 0; i < similarities.size(); i++) {
            assertEquals(expected.get(i), similarities.get(i), 1e-15);
        }
    }

    @Test
    void testCosineSimilarities2() {
        double[] vector1 = {1, 1, 0, 0, 1, 0, 1, 0};
        List<double[]> vectorsAll = List.of(new double[]{1, 0, 0, 0, 1, 0, 1, 0}, new double[]{1, 1, 0, 1, 1, 1, 1, 0});
        List<Double> similarities = VectorUtil.cosineSimilarities(vector1, vectorsAll);
        List<Double> expected = List.of(0.8660254037844387, 0.8164965809277261);
        for (int i = 0; i < similarities.size(); i++) {
            assertEquals(expected.get(i), similarities.get(i), 1e-15);
        }
    }

    @Test
    void testCosineSimilarities3() {
        double[] vector1 = {1, 1, 0, 0, 1, 0, 1, 0};
        List<double[]> vectorsAll = List.of(new double[]{1, 0, 0, 0, 1, 0, 1, 0}, new double[]{1, 1, 1, 1, 1, 1, 1, 0});
        List<Double> similarities = VectorUtil.cosineSimilarities(vector1, vectorsAll);
        List<Double> expected = List.of(0.8660254037844387, 0.7559289460184544);
        for (int i = 0; i < similarities.size(); i++) {
            assertEquals(expected.get(i), similarities.get(i), 1e-15);
        }
    }

    @Test
    void testCosineSimilarities4() {
        double[] vector1 = {1, 1, 0, 0, 1, 0, 1, 0};
        List<double[]> vectorsAll = List.of(new double[]{1, 0, 0, 0, 1, 0, 1, 0}, new double[]{1, 1, 1, 1, 1, 1, 1, 1});
        List<Double> similarities = VectorUtil.cosineSimilarities(vector1, vectorsAll);
        List<Double> expected = List.of(0.8660254037844387, 0.7071067811865475);
        for (int i = 0; i < similarities.size(); i++) {
            assertEquals(expected.get(i), similarities.get(i), 1e-15);
        }
    }

    @Test
    void testCosineSimilarities5() {
        double[] vector1 = {1, 1, 0, 0, 1, 0, 1, 0};
        List<double[]> vectorsAll = List.of(new double[]{1, 0, 0, 0, 1, 0, 1, 0}, new double[]{0, 1, 1, 1, 1, 1, 1, 1});
        List<Double> similarities = VectorUtil.cosineSimilarities(vector1, vectorsAll);
        List<Double> expected = List.of(0.8660254037844387, 0.5669467095138409);
        for (int i = 0; i < similarities.size(); i++) {
            assertEquals(expected.get(i), similarities.get(i), 1e-15);
        }
    }

    @Test
    void testNSimilarity1() {
        List<double[]> vectorList1 = List.of(new double[]{1, 0}, new double[]{0, 1});
        List<double[]> vectorList2 = List.of(new double[]{0, 0}, new double[]{1, 1});
        double similarity = VectorUtil.nSimilarity(vectorList1, vectorList2);
        assertEquals(1.0, similarity, 1e-15);
    }

    @Test
    void testNSimilarity2() {
        List<double[]> vectorList1 = List.of(new double[]{1, 1}, new double[]{0, 1});
        List<double[]> vectorList2 = List.of(new double[]{0, 0}, new double[]{1, 1});
        double similarity = VectorUtil.nSimilarity(vectorList1, vectorList2);
        assertEquals(0.9486832980505137, similarity, 1e-15);
    }

    @Test
    void testNSimilarity3() {
        List<double[]> vectorList1 = List.of(new double[]{1, 0}, new double[]{1, 1});
        List<double[]> vectorList2 = List.of(new double[]{0, 0}, new double[]{1, 1});
        double similarity = VectorUtil.nSimilarity(vectorList1, vectorList2);
        assertEquals(0.9486832980505137, similarity, 1e-15);
    }

    @Test
    void testNSimilarity4() {
        List<double[]> vectorList1 = List.of(new double[]{1, 0}, new double[]{0, 1});
        List<double[]> vectorList2 = List.of(new double[]{1, 0}, new double[]{1, 1});
        double similarity = VectorUtil.nSimilarity(vectorList1, vectorList2);
        assertEquals(0.9486832980505137, similarity, 1e-15);
    }

    @Test
    void testNSimilarity5() {
        List<double[]> vectorList1 = List.of(new double[]{1, 0}, new double[]{0, 1});
        List<double[]> vectorList2 = List.of(new double[]{0, 1}, new double[]{1, 1});
        double similarity = VectorUtil.nSimilarity(vectorList1, vectorList2);
        assertEquals(0.9486832980505137, similarity, 1e-15);
    }

    @Test
    void testNSimilarity6() {
        List<double[]> vectorList1 = Collections.emptyList();
        List<double[]> vectorList2 = Collections.emptyList();
        try {
            double similarity = VectorUtil.nSimilarity(vectorList1, vectorList2);
            fail("Expected an exception to be thrown");
        } catch (Exception e) {
            // Expected
        }
    }

    @Test
    void testComputeIdfWeightDict1() {
        Map<String, Double> numDict = Map.of("key1", 0.1, "key2", 0.5);
        Map<String, Double> res = VectorUtil.computeIdfWeightDict(2, numDict);
        assertEquals(1.0033021088637848, res.get("key1"), 1e-15);
        assertEquals(0.6931471805599453, res.get("key2"), 1e-15);
    }

    @Test
    void testComputeIdfWeightDict2() {
        Map<String, Double> numDict = Map.of("key1", 0.2, "key2", 0.5);
        Map<String, Double> res = VectorUtil.computeIdfWeightDict(2, numDict);
        assertEquals(0.9162907318741551, res.get("key1"), 1e-15);
        assertEquals(0.6931471805599453, res.get("key2"), 1e-15);
    }

    @Test
    void testComputeIdfWeightDict3() {
        Map<String, Double> numDict = Map.of("key1", 0.3, "key2", 0.5);
        Map<String, Double> res = VectorUtil.computeIdfWeightDict(2, numDict);
        assertEquals(0.8362480242006185, res.get("key1"), 1e-15);
        assertEquals(0.6931471805599453, res.get("key2"), 1e-15);
    }

    @Test
    void testComputeIdfWeightDict4() {
        Map<String, Double> numDict = Map.of("key1", 0.4, "key2", 0.5);
        Map<String, Double> res = VectorUtil.computeIdfWeightDict(2, numDict);
        assertEquals(0.7621400520468967, res.get("key1"), 1e-15);
        assertEquals(0.6931471805599453, res.get("key2"), 1e-15);
    }

    @Test
    void testComputeIdfWeightDict5() {
        Map<String, Double> numDict = Map.of("key1", 0.5, "key2", 0.5);
        Map<String, Double> res = VectorUtil.computeIdfWeightDict(2, numDict);
        assertEquals(0.6931471805599453, res.get("key1"), 1e-15);
        assertEquals(0.6931471805599453, res.get("key2"), 1e-15);
    }

    @Test
    void testVectorUtil() {
        double[] vector1 = {1, 1};
        double[] vector2 = {1, 0};
        double similarity = VectorUtil.similarity(vector1, vector2);
        assertEquals(0.7071067811865475, similarity, 1e-15);

        List<double[]> vectorsAll = List.of(new double[]{1, 0}, new double[]{1, 1});
        List<Double> similarities = VectorUtil.cosineSimilarities(vector1, vectorsAll);
        List<Double> expected = List.of(0.7071067811865475, 1.0);
        for (int i = 0; i < similarities.size(); i++) {
            assertEquals(expected.get(i), similarities.get(i), 1e-15);
        }

        List<double[]> vectorList1 = List.of(new double[]{1, 0}, new double[]{0, 1});
        List<double[]> vectorList2 = List.of(new double[]{0, 0}, new double[]{1, 1});
        double nSimilarity = VectorUtil.nSimilarity(vectorList1, vectorList2);
        assertEquals(1.0, nSimilarity, 1e-15);

        Map<String, Double> numDict = Map.of("key1", 0.1, "key2", 0.5);
        Map<String, Double> res = VectorUtil.computeIdfWeightDict(2, numDict);
        assertEquals(1.0033021088637848, res.get("key1"), 1e-15);
        assertEquals(0.6931471805599453, res.get("key2"), 1e-15);
    }
}
