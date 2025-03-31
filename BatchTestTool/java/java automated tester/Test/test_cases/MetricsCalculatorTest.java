package test_cases;
import to_be_tested.MetricsCalculator;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class MetricsCalculatorTest {

    @Test
    public void testUpdate1() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 0, 0, 1};
        mc.update(predictedLabels, trueLabels);
        assertArrayEquals(new int[]{1, 1, 1, 1}, new int[]{mc.truePositives, mc.falsePositives, mc.falseNegatives, mc.trueNegatives});
    }

    @Test
    public void testUpdate2() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 1, 0};
        int[] trueLabels = {1, 0, 0, 1};
        mc.update(predictedLabels, trueLabels);
        assertArrayEquals(new int[]{1, 2, 1, 0}, new int[]{mc.truePositives, mc.falsePositives, mc.falseNegatives, mc.trueNegatives});
    }

    @Test
    public void testUpdate3() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 1};
        int[] trueLabels = {1, 0, 0, 1};
        mc.update(predictedLabels, trueLabels);
        assertArrayEquals(new int[]{2, 1, 0, 1}, new int[]{mc.truePositives, mc.falsePositives, mc.falseNegatives, mc.trueNegatives});
    }

    @Test
    public void testUpdate4() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 1, 0, 1};
        mc.update(predictedLabels, trueLabels);
        assertArrayEquals(new int[]{2, 0, 1, 1}, new int[]{mc.truePositives, mc.falsePositives, mc.falseNegatives, mc.trueNegatives});
    }

    @Test
    public void testUpdate5() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 0, 1, 1};
        mc.update(predictedLabels, trueLabels);
        assertArrayEquals(new int[]{1, 1, 2, 0}, new int[]{mc.truePositives, mc.falsePositives, mc.falseNegatives, mc.trueNegatives});
    }

    @Test
    public void testPrecision1() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 0, 0, 1};
        assertEquals(0.5, mc.precision(predictedLabels, trueLabels));
    }

    @Test
    public void testPrecision2() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 1, 0};
        int[] trueLabels = {1, 0, 0, 1};
        assertEquals(0.3333333333333333, mc.precision(predictedLabels, trueLabels), 0.0000000001);
    }

    @Test
    public void testPrecision3() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 1};
        int[] trueLabels = {1, 0, 0, 1};
        assertEquals(0.6666666666666666, mc.precision(predictedLabels, trueLabels), 0.0000000001);
    }

    @Test
    public void testPrecision4() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 1, 0, 1};
        assertEquals(1.0, mc.precision(predictedLabels, trueLabels));
    }

    @Test
    public void testPrecision5() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 0, 1, 1};
        assertEquals(0.5, mc.precision(predictedLabels, trueLabels));
    }

    @Test
    public void testPrecision6() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {0, 0, 0, 0};
        int[] trueLabels = {1, 0, 1, 1};
        assertEquals(0.0, mc.precision(predictedLabels, trueLabels));
    }

    @Test
    public void testRecall1() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 0, 0, 1};
        assertEquals(0.5, mc.recall(predictedLabels, trueLabels));
    }

    @Test
    public void testRecall2() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 1, 0};
        int[] trueLabels = {1, 0, 0, 1};
        assertEquals(0.5, mc.recall(predictedLabels, trueLabels));
    }

    @Test
    public void testRecall3() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 1};
        int[] trueLabels = {1, 0, 0, 1};
        assertEquals(1.0, mc.recall(predictedLabels, trueLabels));
    }

    @Test
    public void testRecall4() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 1, 0, 1};
        assertEquals(0.6666666666666666, mc.recall(predictedLabels, trueLabels), 0.0000000001);
    }

    @Test
    public void testRecall5() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 0, 1, 1};
        assertEquals(0.3333333333333333, mc.recall(predictedLabels, trueLabels), 0.0000000001);
    }

    @Test
    public void testRecall6() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {0, 0, 0, 0};
        assertEquals(0.0, mc.recall(predictedLabels, trueLabels));
    }

    @Test
    public void testF1Score1() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 0, 0, 1};
        assertEquals(0.5, mc.f1Score(predictedLabels, trueLabels));
    }

    @Test
    public void testF1Score2() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 1, 0};
        int[] trueLabels = {1, 0, 0, 1};
        assertEquals(0.4, mc.f1Score(predictedLabels, trueLabels));
    }

    @Test
    public void testF1Score3() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 1};
        int[] trueLabels = {1, 0, 0, 1};
        assertEquals(0.8, mc.f1Score(predictedLabels, trueLabels));
    }

    @Test
    public void testF1Score4() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 1, 0, 1};
        assertEquals(0.8, mc.f1Score(predictedLabels, trueLabels));
    }

    @Test
    public void testF1Score5() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 0, 1, 1};
        assertEquals(0.4, mc.f1Score(predictedLabels, trueLabels));
    }

    @Test
    public void testF1Score6() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {0, 0, 0, 0};
        int[] trueLabels = {0, 0, 0, 0};
        assertEquals(0.0, mc.f1Score(predictedLabels, trueLabels));
    }

    @Test
    public void testAccuracy1() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 0, 0, 1};
        assertEquals(0.5, mc.accuracy(predictedLabels, trueLabels));
    }

    @Test
    public void testAccuracy2() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 2, 0};
        int[] trueLabels = {1, 0, 0, 1};
        assertEquals(0.3333333333333333, mc.accuracy(predictedLabels, trueLabels), 0.0000000001);
    }

    @Test
    public void testAccuracy3() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 1};
        int[] trueLabels = {1, 0, 0, 1};
        assertEquals(0.75, mc.accuracy(predictedLabels, trueLabels));
    }

    @Test
    public void testAccuracy4() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 1, 0, 1};
        assertEquals(0.75, mc.accuracy(predictedLabels, trueLabels));
    }

    @Test
    public void testAccuracy5() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {1, 1, 0, 0};
        int[] trueLabels = {1, 0, 1, 1};
        assertEquals(0.25, mc.accuracy(predictedLabels, trueLabels));
    }

    @Test
    public void testAccuracy6() {
        MetricsCalculator mc = new MetricsCalculator();
        int[] predictedLabels = {};
        int[] trueLabels = {};
        assertEquals(0.0, mc.accuracy(predictedLabels, trueLabels));
    }
}