import java.util.ArrayList;
import java.util.List;

public class Interpolation {

    public static double[][] interpolate_2d(double[] x, double[] y, double[][] z, double[] x_interp, double[] y_interp) {
        double[][] z_interp = new double[x_interp.length][y_interp.length];

        for (int i = 0; i < x_interp.length; i++) {
            for (int j = 0; j < y_interp.length; j++) {
                for (int k = 0; k < x.length - 1; k++) {
                    if (x[k] <= x_interp[i] && x_interp[i] <= x[k + 1]) {
                        for (int l = 0; l < y.length - 1; l++) {
                            if (y[l] <= y_interp[j] && y_interp[j] <= y[l + 1]) {
                                double z00 = z[k][l];
                                double z01 = z[k][l + 1];
                                double z10 = z[k + 1][l];
                                double z11 = z[k + 1][l + 1];
                                double zi = (z00 * (x[k + 1] - x_interp[i]) * (y[l + 1] - y_interp[j]) +
                                        z10 * (x_interp[i] - x[k]) * (y[l + 1] - y_interp[j]) +
                                        z01 * (x[k + 1] - x_interp[i]) * (y_interp[j] - y[l]) +
                                        z11 * (x_interp[i] - x[k]) * (y_interp[j] - y[l])) / ((x[k + 1] - x[k]) * (y[l + 1] - y[l]));
                                z_interp[i][j] = zi;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }

        return z_interp;
    }

    public static List<Double> interpolate_1d(List<Double> x, List<Double> y, List<Double> x_interp) {
        List<Double> y_interp = new ArrayList<>();
        for (double xi : x_interp) {
            for (int i = 0; i < x.size() - 1; i++) {
                if (x.get(i) <= xi && xi <= x.get(i + 1)) {
                    double yi = y.get(i) + (y.get(i + 1) - y.get(i)) * (xi - x.get(i)) / (x.get(i + 1) - x.get(i));
                    y_interp.add(yi);
                    break;
                }
            }
        }
        return y_interp;
    }
}