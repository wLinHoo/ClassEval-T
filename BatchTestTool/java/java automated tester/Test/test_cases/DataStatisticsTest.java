package test_cases;
import to_be_tested.DataStatistics;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.Arrays;
import java.util.List;

public class DataStatisticsTest {

    private final DataStatistics ds = new DataStatistics();

    @Test
    public void testMean1() {
        double res = ds.mean(new int[]{1, 2, 3, 4, 5});
        assertEquals(3.00, res, 0.01);
    }

    @Test
    public void testMean2() {
        double res = ds.mean(new int[]{1, 2, 3, 4, 5, 6});
        assertEquals(3.50, res, 0.01);
    }

    @Test
    public void testMean3() {
        double res = ds.mean(new int[]{1, 2, 4, 5, 6, 7});
        assertEquals(4.17, res, 0.01);
    }

    @Test
    public void testMean4() {
        double res = ds.mean(new int[]{1, 2, 4, 5, 6, 7, 8});
        assertEquals(4.71, res, 0.01);
    }

    @Test
    public void testMean5() {
        double res = ds.mean(new int[]{1, 2, 4, 5, 6, 7, 8, 9});
        assertEquals(5.25, res, 0.01);
    }

    @Test
    public void testMedian1() {
        double res = ds.median(new int[]{2, 5, 1, 3, 4});
        assertEquals(3.00, res, 0.01);
    }

    @Test
    public void testMedian2() {
        double res = ds.median(new int[]{2, 5, 1, 3, 4, 6});
        assertEquals(3.50, res, 0.01);
    }

    @Test
    public void testMedian3() {
        double res = ds.median(new int[]{2, 5, 1, 4, 6, 7});
        assertEquals(4.50, res, 0.01);
    }

    @Test
    public void testMedian4() {
        double res = ds.median(new int[]{2, 5, 1, 4, 6, 7, 8});
        assertEquals(5.00, res, 0.01);
    }

    @Test
    public void testMedian5() {
        double res = ds.median(new int[]{2, 5, 1, 4, 6, 7, 8, 9});
        assertEquals(5.50, res, 0.01);
    }

    @Test
    public void testMode1() {
        List<Integer> res = ds.mode(new int[]{2, 2, 3, 3, 4});
        assertEquals(Arrays.asList(2, 3), res);
    }

    @Test
    public void testMode2() {
        List<Integer> res = ds.mode(new int[]{2, 2, 2, 3, 3, 4});
        assertEquals(Arrays.asList(2), res);
    }

    @Test
    public void testMode3() {
        List<Integer> res = ds.mode(new int[]{2, 2, 3, 3, 4, 4});
        assertEquals(Arrays.asList(2, 3, 4), res);
    }

    @Test
    public void testMode4() {
        List<Integer> res = ds.mode(new int[]{2, 2, 3, 3, 4, 4, 4});
        assertEquals(Arrays.asList(4), res);
    }

    @Test
    public void testMode5() {
        List<Integer> res = ds.mode(new int[]{2, 2, 3, 3, 4, 4, 4, 5});
        assertEquals(Arrays.asList(4), res);
    }

    @Test
    public void testDataStatistics() {
        double meanRes = ds.mean(new int[]{1, 2, 3, 4, 5});
        assertEquals(3.00, meanRes, 0.01);

        double medianRes = ds.median(new int[]{2, 5, 1, 3, 4});
        assertEquals(3.00, medianRes, 0.01);

        List<Integer> modeRes = ds.mode(new int[]{2, 2, 3, 3, 4});
        assertEquals(Arrays.asList(2, 3), modeRes);
    }
}
