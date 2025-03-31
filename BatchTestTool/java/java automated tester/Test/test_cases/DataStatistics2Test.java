package test_cases;
import to_be_tested.DataStatistics2;

import org.junit.jupiter.api.Test;
import static org.junit.Assert.assertEquals;
import java.util.Arrays;
import java.util.List;

public class DataStatistics2Test {

    @Test
    public void testGetSum1() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 3, 4));
        double res = ds2.getSum();
        assertEquals(10, res, 0.001);
    }

    @Test
    public void testGetSum2() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 203, 4));
        double res = ds2.getSum();
        assertEquals(210, res, 0.001);
    }

    @Test
    public void testGetSum3() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 33, 4));
        double res = ds2.getSum();
        assertEquals(40, res, 0.001);
    }

    @Test
    public void testGetSum4() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 333, 4));
        double res = ds2.getSum();
        assertEquals(340, res, 0.001);
    }

    @Test
    public void testGetSum5() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 6, 4));
        double res = ds2.getSum();
        assertEquals(13, res, 0.001);
    }

    @Test
    public void testGetMin1() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 3, 4));
        double res = ds2.getMin();
        assertEquals(1, res, 0.001);
    }

    @Test
    public void testGetMin2() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 203, 4));
        double res = ds2.getMin();
        assertEquals(1, res, 0.001);
    }

    @Test
    public void testGetMin3() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(0, -1, -3, 2));
        double res = ds2.getMin();
        assertEquals(-3, res, 0.001);
    }

    @Test
    public void testGetMin4() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(-111, -1, -3, 2));
        double res = ds2.getMin();
        assertEquals(-111, res, 0.001);
    }

    @Test
    public void testGetMin5() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(0, -1111, -3, 2));
        double res = ds2.getMin();
        assertEquals(-1111, res, 0.001);
    }

    @Test
    public void testGetMax1() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 3, 4));
        double res = ds2.getMax();
        assertEquals(4, res, 0.001);
    }

    @Test
    public void testGetMax2() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 203, 4));
        double res = ds2.getMax();
        assertEquals(203, res, 0.001);
    }

    @Test
    public void testGetMax3() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(-1, -4, 3, 2));
        double res = ds2.getMax();
        assertEquals(3, res, 0.001);
    }

    @Test
    public void testGetMax4() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(-1, 4, 3, 2));
        double res = ds2.getMax();
        assertEquals(4, res, 0.001);
    }

    @Test
    public void testGetMax5() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(-1, 444, 3, 2));
        double res = ds2.getMax();
        assertEquals(444, res, 0.001);
    }

    @Test
    public void testGetVariance1() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 3, 4));
        double res = ds2.getVariance();
        assertEquals(1.25, res, 0.01);
    }

    @Test
    public void testGetVariance2() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 203, 4));
        double res = ds2.getVariance();
        assertEquals(7551.25, res, 0.01);
    }

    @Test
    public void testGetVariance3() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 4, 3, 2));
        double res = ds2.getVariance();
        assertEquals(1.25, res, 0.01);
    }

    @Test
    public void testGetVariance4() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(11, 14, 13, 12));
        double res = ds2.getVariance();
        assertEquals(1.25, res, 0.01);
    }

    @Test
    public void testGetVariance5() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(111, 114, 113, 112));
        double res = ds2.getVariance();
        assertEquals(1.25, res, 0.01);
    }

    @Test
    public void testGetStdDeviation1() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 3, 4));
        double res = ds2.getStdDeviation();
        assertEquals(1.12, res, 0.01);
    }

    @Test
    public void testGetStdDeviation2() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 203, 4));
        double res = ds2.getStdDeviation();
        assertEquals(86.9, res, 0.1);
    }

    @Test
    public void testGetStdDeviation3() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 4, 3, 2));
        double res = ds2.getStdDeviation();
        assertEquals(1.12, res, 0.01);
    }

    @Test
    public void testGetStdDeviation4() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(11, 14, 13, 12));
        double res = ds2.getStdDeviation();
        assertEquals(1.12, res, 0.01);
    }

    @Test
    public void testGetStdDeviation5() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(111, 114, 113, 112));
        double res = ds2.getStdDeviation();
        assertEquals(1.12, res, 0.01);
    }

    @Test
    public void testGetCorrelation1() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 3, 4));
        double res = ds2.getCorrelation();
        assertEquals(1.0, res, 0.001);
    }

    @Test
    public void testGetCorrelation2() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 2, 203, 4));
        double res = ds2.getCorrelation();
        assertEquals(1.0, res, 0.001);
    }

    @Test
    public void testGetCorrelation3() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(1, 4, 3, 2));
        double res = ds2.getCorrelation();
        assertEquals(1.0, res, 0.001);
    }

    @Test
    public void testGetCorrelation4() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(11, 14, 13, 12));
        double res = ds2.getCorrelation();
        assertEquals(1.0, res, 0.001);
    }

    @Test
    public void testGetCorrelation5() {
        DataStatistics2 ds2 = new DataStatistics2(Arrays.asList(111, 114, 113, 112));
        double res = ds2.getCorrelation();
        assertEquals(1.0, res, 0.001);
    }
}
