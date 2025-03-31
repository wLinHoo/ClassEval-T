package org.example;

import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;

public class TriCalculator {

    public TriCalculator() {
    }

    public double cos(double x) {
        return round(taylor(x, 50), 10);
    }

    public BigDecimal factorial(int a) {
        BigDecimal result = BigDecimal.ONE;
        while (a > 1) {
            result = result.multiply(BigDecimal.valueOf(a));
            a--;
        }
        return result;
    }

    public double taylor(double x, int n) {
        BigDecimal a = BigDecimal.ONE;
        x = x / 180 * Math.PI;
        int count = 1;
        for (int k = 1; k < n; k++) {
            BigDecimal term = BigDecimal.valueOf(Math.pow(x, 2 * k))
                    .divide(factorial(2 * k), MathContext.DECIMAL128);
            if (count % 2 != 0) {
                a = a.subtract(term);
            } else {
                a = a.add(term);
            }
            count++;
        }
        return a.doubleValue();
    }

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

    public Double tan(double x) {
        double cosValue = cos(x);
        if (cosValue != 0) {
            return round(sin(x) / cosValue, 10);
        } else {
            return Double.NaN;
        }
    }

    private double round(double value, int places) {
        BigDecimal bd = BigDecimal.valueOf(value);
        bd = bd.setScale(places, RoundingMode.HALF_UP);
        return bd.doubleValue();
    }
}
