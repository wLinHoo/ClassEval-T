package test_cases;
import to_be_tested.MetricsCalculator2;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.Arrays;
import java.util.List;

public class MetricsCalculator2Test {

    @Test
    public void testMrr1() {
        MetricsCalculator2.Tuple tuple = new MetricsCalculator2.Tuple(Arrays.asList(1, 0, 1, 0), 4);
        double result = MetricsCalculator2.mrr(tuple);
        assertEquals(1.0, result, 0.000001);
    }

    @Test
    public void testMrr2() {
        MetricsCalculator2.Tuple tuple = new MetricsCalculator2.Tuple(Arrays.asList(0, 0, 0, 1), 4);
        double result = MetricsCalculator2.mrr(tuple);
        assertEquals(0.25, result, 0.000001);
    }

    @Test
    public void testMrr3() {
        List<MetricsCalculator2.Tuple> tupleList = Arrays.asList(
                new MetricsCalculator2.Tuple(Arrays.asList(1, 0, 1, 0), 4),
                new MetricsCalculator2.Tuple(Arrays.asList(0, 1, 0, 1), 4)
        );
        double result = MetricsCalculator2.mrr(tupleList);
        assertEquals(0.75, result, 0.000001);
    }

    @Test
    public void testMrr4() {
        List<MetricsCalculator2.Tuple> tupleList = Arrays.asList(
                new MetricsCalculator2.Tuple(Arrays.asList(1, 1, 1, 0), 4),
                new MetricsCalculator2.Tuple(Arrays.asList(0, 0, 0, 1), 4)
        );
        double result = MetricsCalculator2.mrr(tupleList);
        assertEquals(0.625, result, 0.000001);
    }

    @Test
    public void testMrr5() {
        List<MetricsCalculator2.Tuple> tupleList = Arrays.asList(
                new MetricsCalculator2.Tuple(Arrays.asList(1, 0, 1, 1), 4),
                new MetricsCalculator2.Tuple(Arrays.asList(0, 1, 0, 0), 4)
        );
        double result = MetricsCalculator2.mrr(tupleList);
        assertEquals(0.75, result, 0.000001);
    }

    @Test
    public void testMrr6() {
        assertThrows(IllegalArgumentException.class, () -> {
            MetricsCalculator2.mrr(1);
        });
    }

    @Test
    public void testMrr7() {
        List<MetricsCalculator2.Tuple> tupleList = Arrays.asList();
        double result = MetricsCalculator2.mrr(tupleList);
        assertEquals(0.0, result, 0.000001);
    }

    @Test
    public void testMrr8() {
        List<MetricsCalculator2.Tuple> tupleList = Arrays.asList(
                new MetricsCalculator2.Tuple(Arrays.asList(1, 0, 1, 1), 0),
                new MetricsCalculator2.Tuple(Arrays.asList(0, 1, 0, 0), 0)
        );
        double result = MetricsCalculator2.mrr(tupleList);
        assertEquals(0.0, result, 0.000001);
    }

    @Test
    public void testMap1() {
        MetricsCalculator2.Tuple tuple = new MetricsCalculator2.Tuple(Arrays.asList(1, 0, 1, 0), 4);
        double result = MetricsCalculator2.map(tuple);
        assertEquals(0.41666666666666663, result, 0.000001);
    }

    @Test
    public void testMap2() {
        MetricsCalculator2.Tuple tuple = new MetricsCalculator2.Tuple(Arrays.asList(0, 0, 0, 1), 4);
        double result = MetricsCalculator2.map(tuple);
        assertEquals(0.0625, result, 0.000001);
    }

    @Test
    public void testMap3() {
        List<MetricsCalculator2.Tuple> tupleList = Arrays.asList(
                new MetricsCalculator2.Tuple(Arrays.asList(1, 0, 1, 0), 4),
                new MetricsCalculator2.Tuple(Arrays.asList(0, 1, 0, 1), 4)
        );
        double result = MetricsCalculator2.map(tupleList);
        assertEquals(0.3333333333333333, result, 0.000001);
    }

    @Test
    public void testMap4() {
        List<MetricsCalculator2.Tuple> tupleList = Arrays.asList(
                new MetricsCalculator2.Tuple(Arrays.asList(1, 1, 1, 0), 4),
                new MetricsCalculator2.Tuple(Arrays.asList(0, 0, 0, 1), 4)
        );
        double result = MetricsCalculator2.map(tupleList);
        assertEquals(0.40625, result, 0.000001);
    }

    @Test
    public void testMap5() {
        List<MetricsCalculator2.Tuple> tupleList = Arrays.asList(
                new MetricsCalculator2.Tuple(Arrays.asList(1, 0, 1, 1), 4),
                new MetricsCalculator2.Tuple(Arrays.asList(0, 1, 0, 0), 4)
        );
        double result = MetricsCalculator2.map(tupleList);
        assertEquals(0.3645833333333333, result, 0.000001);
    }

    @Test
    public void testMap6() {
        assertThrows(IllegalArgumentException.class, () -> {
            MetricsCalculator2.map(1);
        });
    }

    @Test
    public void testMap7() {
        List<MetricsCalculator2.Tuple> tupleList = Arrays.asList();
        double result = MetricsCalculator2.map(tupleList);
        assertEquals(0.0, result, 0.000001);
    }

    @Test
    public void testMap8() {
        List<MetricsCalculator2.Tuple> tupleList = Arrays.asList(
                new MetricsCalculator2.Tuple(Arrays.asList(1, 0, 1, 1), 0),
                new MetricsCalculator2.Tuple(Arrays.asList(0, 1, 0, 0), 0)
        );
        double result = MetricsCalculator2.map(tupleList);
        assertEquals(0.0, result, 0.000001);
    }
}