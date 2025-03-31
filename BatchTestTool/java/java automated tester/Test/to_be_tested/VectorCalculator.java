package to_be_tested;

import org.apache.commons.math3.linear.ArrayRealVector;
import org.apache.commons.math3.linear.RealVector;
import org.apache.commons.math3.linear.VectorUtils;
import org.apache.commons.math3.fraction.Fraction;
import org.apache.commons.math3.util.Cleaner;
import org.apache.commons.math3.util.Precision;
import org.apache.commons.math3.util.ReentrantLock;
import org.apache.commons.math3.util.WrappedPrintStream;
import org.apache.commons.math3.util.concurrent.Accumulator;
import org.apache.commons.math3.util.concurrent.AtomicDouble;
import org.apache.commons.math3.util.concurrent.AtomicReal;
import org.apache.commons.math3.util.concurrent.AtomicRealAccumulator;
import org.deeplearning4j.models.embeddings.loader.IOUtil;
import org.deeplearning4j.models.embeddings.loader.cache.SimpleWordCache;
import org.deeplearning4j.models.embeddings.loader.wordvectors.WordVectorSerializer;
import org.deeplearning4j.models.embeddings.reader.WordVectorSerializer;
import org.deeplearning4j.models.embeddings.loader.cache.NoOpCache;
import org.deeplearning4j.models.embeddings.reader.cache.SimpleWordCache;
import org.deeplearning4j.models.embeddings.reader.cache.NoOpCache;
import org.deeplearning4j.nn.util.Vectors;
import org.deeplearning4j.util.matrices.Vector;
import org.deeplearning4j.util.matrices.Matrix;
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.List;

public class VectorUtil {

    public static double[] cosineSimilarities(RealVector vector1, RealVector[] vectorsAll) {
        double norm = vector1.getNorm();
        double[] allNorms = new double[vectorsAll.length];
        for (int i = 0; i < vectorsAll.length; i++) {
            allNorms[i] = vectorsAll[i].getNorm();
        }
        double[] dotProducts = new double[vectorsAll.length];
        for (int i = 0; i < vectorsAll.length; i++) {
            dotProducts[i] = vectorsAll[i].dotProduct(vector1);
        }
        double[] similarities = new double[vectorsAll.length];
        for (int i = 0; i < vectorsAll.length; i++) {
            similarities[i] = dotProducts[i] / (norm * allNorms[i]);
        }
        return similarities;
    }

    public static Map<String, Double> computeIdfWeightDict(int totalNum, Map<String, Integer> numberDict) {
        Map<Integer, String> index2KeyMap = new HashMap<>();
        int index = 0;
        List<Integer> countList = new ArrayList<>();
        for (Map.Entry<String, Integer> entry : numberDict.entrySet()) {
            index2KeyMap.put(index, entry.getKey());
            countList.add(entry.getValue());
            index++;
        }
        double[] array = new double[countList.size()];
        for (int i = 0; i < countList.size(); i++) {
            array[i] = (Math.log((totalNum + 1) / (countList.get(i) + 1)));
        }
        Map<String, Double> result = new HashMap<>();
        for (int i = 0; i < array.length; i++) {
            String key = index2KeyMap.get(i);
            result.put(key, array[i]);
        }
        return result;
    }

    public static double similarity(Vector vector1, Vector vector2) {
        Vector unitVector1 = Vectors.unitVector(vector1);
        Vector unitVector2 = Vectors.unitVector(vector2);
        return Matrix.dot(unitVector1, unitVector2);
    }
}
