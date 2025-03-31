package org.example;

import java.util.ArrayList;
import java.util.List;

public class Interpolation {

    public static List<Double> interpolate1d(List<Double> x, List<Double> y, List<Double> xInterp) {
        List<Double> yInterp = new ArrayList<>();
        for (Double xi : xInterp) {
            for (int i = 0; i < x.size() - 1; i++) {
                if (x.get(i) <= xi && xi <= x.get(i + 1)) {
                    double yi = y.get(i) + (y.get(i + 1) - y.get(i)) * (xi - x.get(i)) / (x.get(i + 1) - x.get(i));
                    yInterp.add(yi);
                    break;
                }
            }
        }
        return yInterp;
    }

    public static List<Double> interpolate2d(List<Double> x, List<Double> y, List<List<Double>> z, List<Double> xInterp, List<Double> yInterp) {
        List<Double> zInterp = new ArrayList<>();
        for (int k = 0; k < xInterp.size(); k++) {
            Double xi = xInterp.get(k);
            Double yi = yInterp.get(k);
            for (int i = 0; i < x.size() - 1; i++) {
                if (x.get(i) <= xi && xi <= x.get(i + 1)) {
                    for (int j = 0; j < y.size() - 1; j++) {
                        if (y.get(j) <= yi && yi <= y.get(j + 1)) {
                            double z00 = z.get(i).get(j);
                            double z01 = z.get(i).get(j + 1);
                            double z10 = z.get(i + 1).get(j);
                            double z11 = z.get(i + 1).get(j + 1);
                            double zi = (z00 * (x.get(i + 1) - xi) * (y.get(j + 1) - yi) +
                                    z10 * (xi - x.get(i)) * (y.get(j + 1) - yi) +
                                    z01 * (x.get(i + 1) - xi) * (yi - y.get(j)) +
                                    z11 * (xi - x.get(i)) * (yi - y.get(j))) /
                                    ((x.get(i + 1) - x.get(i)) * (y.get(j + 1) - y.get(j)));
                            zInterp.add(zi);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return zInterp;
    }
}