package test_cases;
import to_be_tested.DataStatistics4;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import org.apache.commons.math3.stat.descriptive.moment.Kurtosis;
import org.apache.commons.math3.stat.descriptive.moment.Skewness;
import org.apache.commons.math3.stat.correlation.PearsonsCorrelation;
import org.apache.commons.math3.distribution.NormalDistribution;

public class DataStatistics4Test {

    @Test
    void testCorrelationCoefficient() {
        assertEquals(0.9999999999999998, DataStatistics4.correlationCoefficient(
                Arrays.asList(1.0, 2.0, 3.0), Arrays.asList(4.0, 5.0, 6.0)), 1e-15);
    }

    @Test
    void testCorrelationCoefficient2() {
        assertEquals(0, DataStatistics4.correlationCoefficient(
                Arrays.asList(1.0, 1.0, 1.0), Arrays.asList(2.0, 2.0, 2.0)), 1e-15);
    }

    @Test
    void testCorrelationCoefficient3() {
        assertEquals(0.9999999999999998, DataStatistics4.correlationCoefficient(
                Arrays.asList(1.0, 2.0, 3.0), Arrays.asList(1.0, 2.0, 3.0)), 1e-15);
    }

    @Test
    void testCorrelationCoefficient4() {
        assertEquals(0.9819805060619659, DataStatistics4.correlationCoefficient(
                Arrays.asList(1.0, 2.0, 3.0), Arrays.asList(1.0, 2.0, 4.0)), 1e-15);
    }

    @Test
    void testCorrelationCoefficient5() {
        assertEquals(0.5, DataStatistics4.correlationCoefficient(
                Arrays.asList(1.0, 2.0, 3.0), Arrays.asList(1.0, 5.0, 3.0)), 1e-15);
    }

    @Test
    void testSkewness() {
        assertEquals(2.3760224064818463, DataStatistics4.skewness(Arrays.asList(1.0, 2.0, 5.0)), 1e-15);
    }

    @Test
    void testSkewness2() {
        assertEquals(0, DataStatistics4.skewness(Arrays.asList(1.0, 1.0, 1.0)), 1e-15);
    }

    @Test
    void testSkewness3() {
        assertEquals(0, DataStatistics4.skewness(Arrays.asList(1.0, 2.0, 3.0)), 1e-15);
    }

    @Test
    void testSkewness4() {
        assertEquals(1.7181079837227264, DataStatistics4.skewness(Arrays.asList(1.0, 2.0, 4.0)), 1e-15);
    }

    @Test
    void testSkewness5() {
        assertEquals(0.0, DataStatistics4.skewness(Arrays.asList(1.0, 5.0, 3.0)), 1e-15);
    }

    @Test
    void testKurtosis() {
        assertEquals(-1.5, DataStatistics4.kurtosis(Arrays.asList(1.0, 2.0, 5.0)), 1e-15);
    }

    @Test
    void testKurtosis2() {
        assertTrue(Double.isNaN(DataStatistics4.kurtosis(Arrays.asList(1.0, 1.0, 1.0))));
    }

    @Test
    void testKurtosis3() {
        assertEquals(-1.5, DataStatistics4.kurtosis(Arrays.asList(1.0, 2.0, 3.0)), 1e-15);
    }

    @Test
    void testKurtosis4() {
        assertEquals(-1.5, DataStatistics4.kurtosis(Arrays.asList(1.0, 2.0, 4.0)), 1e-15);
    }

    @Test
    void testKurtosis5() {
        assertEquals(-1.5, DataStatistics4.kurtosis(Arrays.asList(1.0, 5.0, 3.0)), 1e-15);
    }

    @Test
    void testPDF() {
        assertEquals(
                Arrays.asList(0.3989422804014327, 0.24197072451914337, 0.05399096651318806),
                DataStatistics4.pdf(Arrays.asList(1.0, 2.0, 3.0), 1.0, 1.0)
        );
    }

    @Test
    void testPDF2() {
        assertEquals(
                Arrays.asList(0.3989422804014327, 0.3989422804014327, 0.3989422804014327),
                DataStatistics4.pdf(Arrays.asList(1.0, 1.0, 1.0), 1.0, 1.0)
        );
    }

    @Test
    void testPDF3() {
        assertEquals(
                Arrays.asList(0.24197072451914337, 0.3989422804014327, 0.24197072451914337),
                DataStatistics4.pdf(Arrays.asList(1.0, 2.0, 3.0), 2.0, 1.0)
        );
    }

    @Test
    void testPDF4() {
        assertEquals(
                Arrays.asList(0.19947114020071635, 0.17603266338214976, 0.12098536225957168),
                DataStatistics4.pdf(Arrays.asList(1.0, 2.0, 3.0), 1.0, 2.0)
        );
    }

    @Test
    void testPDF5() {
        assertEquals(
                Arrays.asList(0.17603266338214976, 0.19947114020071635, 0.17603266338214976),
                DataStatistics4.pdf(Arrays.asList(1.0, 2.0, 3.0), 2.0, 2.0)
        );
    }

    @Test
    void testMain() {
        assertEquals(0.9999999999999998, DataStatistics4.correlationCoefficient(
                Arrays.asList(1.0, 2.0, 3.0), Arrays.asList(4.0, 5.0, 6.0)), 1e-15);
        assertEquals(2.3760224064818463, DataStatistics4.skewness(Arrays.asList(1.0, 2.0, 5.0)), 1e-15);
        assertEquals(-1.5, DataStatistics4.kurtosis(Arrays.asList(1.0, 2.0, 5.0)), 1e-15);
        assertEquals(
                Arrays.asList(0.3989422804014327, 0.24197072451914337, 0.05399096651318806),
                DataStatistics4.pdf(Arrays.asList(1.0, 2.0, 3.0), 1.0, 1.0)
        );
    }
}
