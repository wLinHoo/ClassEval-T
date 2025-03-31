package test_cases;
import to_be_tested.Interpolation;

import org.junit.jupiter.api.Test;
import java.util.Arrays;
import java.util.List;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class InterpolationTest {

    @Test
    public void testInterpolate1d() {
        List<Double> x = Arrays.asList(1.0, 2.0, 3.0);
        List<Double> y = Arrays.asList(1.0, 2.0, 3.0);
        List<Double> xInterp = Arrays.asList(1.5, 2.5);
        List<Double> expected = Arrays.asList(1.5, 2.5);
        List<Double> result = Interpolation.interpolate1d(x, y, xInterp);
        assertEquals(expected, result);
    }

    @Test
    public void testInterpolate1d_2() {
        List<Double> x = Arrays.asList(1.0, 6.0, 4.0);
        List<Double> y = Arrays.asList(1.0, 2.0, 5.0);
        List<Double> xInterp = Arrays.asList(1.5, 2.5);
        List<Double> expected = Arrays.asList(1.1, 1.3);
        List<Double> result = Interpolation.interpolate1d(x, y, xInterp);
        assertEquals(expected, result);
    }

    @Test
    public void testInterpolate1d_3() {
        List<Double> x = Arrays.asList(1.0, 6.0, 4.0);
        List<Double> y = Arrays.asList(1.0, 7.0, 5.0);
        List<Double> xInterp = Arrays.asList(1.5, 2.5);
        List<Double> expected = Arrays.asList(1.6, 2.8);
        List<Double> result = Interpolation.interpolate1d(x, y, xInterp);
        assertEquals(expected, result);
    }

    @Test
    public void testInterpolate1d_4() {
        List<Double> x = Arrays.asList(1.0, 6.0, 4.0);
        List<Double> y = Arrays.asList(1.0, 2.0, 5.0);
        List<Double> xInterp = Arrays.asList(2.0, 3.0);
        List<Double> expected = Arrays.asList(1.2, 1.4);
        List<Double> result = Interpolation.interpolate1d(x, y, xInterp);
        assertEquals(expected, result);
    }

    @Test
    public void testInterpolate1d_5() {
        List<Double> x = Arrays.asList(1.0, 6.0, 4.0);
        List<Double> y = Arrays.asList(1.0, 7.0, 5.0);
        List<Double> xInterp = Arrays.asList(2.0, 3.0);
        List<Double> expected = Arrays.asList(2.2, 3.4);
        List<Double> result = Interpolation.interpolate1d(x, y, xInterp);
        assertEquals(expected, result);
    }

    @Test
    public void testInterpolate1d_6() {
        List<Double> x = Arrays.asList(1.0, 6.0, 4.0);
        List<Double> y = Arrays.asList(1.0, 7.0, 5.0);
        List<Double> xInterp = Arrays.asList();
        List<Double> expected = Arrays.asList();
        List<Double> result = Interpolation.interpolate1d(x, y, xInterp);
        assertEquals(expected, result);
    }

    @Test
    public void testInterpolate1d_7() {
        List<Double> x = Arrays.asList();
        List<Double> y = Arrays.asList();
        List<Double> xInterp = Arrays.asList();
        List<Double> expected = Arrays.asList();
        List<Double> result = Interpolation.interpolate1d(x, y, xInterp);
        assertEquals(expected, result);
    }

    @Test
    public void testInterpolate2d() {
        List<Double> x = Arrays.asList(1.0, 2.0, 3.0);
        List<Double> y = Arrays.asList(1.0, 2.0, 3.0);
        List<List<Double>> z = Arrays.asList(
                Arrays.asList(1.0, 2.0, 3.0),
                Arrays.asList(4.0, 5.0, 6.0),
                Arrays.asList(7.0, 8.0, 9.0)
        );
        List<Double> xInterp = Arrays.asList(1.5, 2.5);
        List<Double> yInterp = Arrays.asList(1.5, 2.5);
        List<Double> expected = Arrays.asList(3.0, 7.0);
        List<Double> result = Interpolation.interpolate2d(x, y, z, xInterp, yInterp);
        assertEquals(expected, result);
    }

    @Test
    public void testInterpolate2d_2() {
        List<Double> x = Arrays.asList(1.0, 2.0, 3.0);
        List<Double> y = Arrays.asList(1.0, 2.0, 3.0);
        List<List<Double>> z = Arrays.asList(
                Arrays.asList(1.0, 2.0, 3.0),
                Arrays.asList(4.0, 5.0, 6.0),
                Arrays.asList(7.0, 8.0, 9.0)
        );
        List<Double> xInterp = Arrays.asList(1.5, 2.5);
        List<Double> yInterp = Arrays.asList(3.0, 4.0);
        List<Double> expected = Arrays.asList(4.5);
        List<Double> result = Interpolation.interpolate2d(x, y, z, xInterp, yInterp);
        assertEquals(expected, result);
    }

    @Test
    public void testInterpolate2d_3() {
        List<Double> x = Arrays.asList(1.0, 2.0, 3.0);
        List<Double> y = Arrays.asList(1.0, 2.0, 3.0);
        List<List<Double>> z = Arrays.asList(
                Arrays.asList(1.0, 2.0, 3.0),
                Arrays.asList(4.0, 5.0, 6.0),
                Arrays.asList(7.0, 8.0, 9.0)
        );
        List<Double> xInterp = Arrays.asList(3.0, 4.0);
        List<Double> yInterp = Arrays.asList(1.5, 2.5);
        List<Double> expected = Arrays.asList(7.5);
        List<Double> result = Interpolation.interpolate2d(x, y, z, xInterp, yInterp);
        assertEquals(expected, result);
    }

    @Test
    public void testInterpolate2d_4() {
        List<Double> x = Arrays.asList(1.0, 2.0, 3.0);
        List<Double> y = Arrays.asList(1.0, 2.0, 3.0);
        List<List<Double>> z = Arrays.asList(
                Arrays.asList(1.0, 2.0, 3.0),
                Arrays.asList(4.0, 5.0, 6.0),
                Arrays.asList(7.0, 8.0, 9.0)
        );
        List<Double> xInterp = Arrays.asList(3.0, 4.0);
        List<Double> yInterp = Arrays.asList(3.0, 4.0);
        List<Double> expected = Arrays.asList(9.0);
        List<Double> result = Interpolation.interpolate2d(x, y, z, xInterp, yInterp);
        assertEquals(expected, result);
    }

    @Test
    public void testInterpolate2d_5() {
        List<Double> x = Arrays.asList(1.0, 2.0, 3.0);
        List<Double> y = Arrays.asList(1.0, 2.0, 3.0);
        List<List<Double>> z = Arrays.asList(
                Arrays.asList(1.0, 2.0, 3.0),
                Arrays.asList(4.0, 5.0, 6.0),
                Arrays.asList(7.0, 8.0, 9.0)
        );
        List<Double> xInterp = Arrays.asList(1.5, 2.5);
        List<Double> yInterp = Arrays.asList(1.5, 2.5);
        List<Double> expected = Arrays.asList(3.0, 7.0);
        List<Double> result = Interpolation.interpolate2d(x, y, z, xInterp, yInterp);
        assertEquals(expected, result);
    }
}