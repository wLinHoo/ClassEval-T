import java.lang.Math;

public class TriCalculator {

    public TriCalculator() {}

    public double sin(double x) {
        x = x / 180 * Math.PI;
        double g = 0;
        double t = x;
        int n = 1;

        while (Math.abs(t) >= 1e-15) {
            g += t;
            n += 1;
            t = -t * x * x / (2 * n - 1) / (2 * n - 2);
        }
        return round(g, 10);
    }

    public double cos(double x) {
        return round(taylor(x, 50), 10);
    }

    public double tan(double x) {
        if (cos(x) != 0) {
            double result = sin(x) / cos(x);
            return round(result, 10);
        } else {
            return 0; // Return 0 instead of false, as Java doesn't allow boolean return type for methods that return double
        }
    }

    public double taylor(double x, int n) {
        double a = 1;
        x = x / 180 * Math.PI;
        int count = 1;
        for (int k = 1; k < n; k++) {
            if (count % 2 != 0) {
                a -= Math.pow(x, 2 * k) / factorial(2 * k);
            } else {
                a += Math.pow(x, 2 * k) / factorial(2 * k);
            }
            count += 1;
        }
        return a;
    }

    public double factorial(double a) {
        double b = 1;
        while (a != 1) {
            b *= a;
            a -= 1;
        }
        return b;
    }

    private double round(double number, int decimalPlaces) {
        double multiplier = Math.pow(10, decimalPlaces);
        return Math.floor(number * multiplier + 0.5) / multiplier;
    }
}