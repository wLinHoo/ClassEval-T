package to_be_tested;

public class Interpolation {

    public static double[][] interpolate_2d(double[][] x, double[][] y, double[][] z, double[] x_interp, double[] y_interp) {
        double[][] z_interp = new double[x_interp.length][y_interp.length];
        for (int i = 0; i < x_interp.length; i++) {
            for (int j = 0; j < y_interp.length; j++) {
                double xi = x_interp[i];
                double yi = y_interp[j];
                double z00, z01, z10, z11;
                for (int k = 0; k < x.length - 1; k++) {
                    if (x[k] <= xi && xi <= x[k + 1]) {
                        for (int l = 0; l < y.length - 1; l++) {
                            if (y[l] <= yi && yi <= y[l + 1]) {
                                z00 = z[k][l];
                                z01 = z[k][l + 1];
                                z10 = z[k + 1][l];
                                z11 = z[k + 1][l + 1];
                                z_interp[i][j] = (z00 * (x[k + 1] - xi) * (y[l + 1] - yi) + z10 * (xi - x[k]) * (y[l + 1] - yi) + z01 * (x[k + 1] - xi) * (yi - y[l]) + z11 * (xi - x[k]) * (yi - y[l])) / ((x[k + 1] - x[k]) * (y[l + 1] - y[l]));
                            }
                        }
                        break;
                    }
                }
            }
        }
        return z_interp;
    }

    @staticmethod
    public double[] interpolate_1d(double[] x, double[] y, double[] x_interp) {
        double[] y_interp = new double[x_interp.length];
        for (int i = 0; i < x_interp.length; i++) {
            double xi = x_interp[i];
            for (int j = 0; j < x.length - 1; j++) {
                if (x[j] <= xi && xi <= x[j + 1]) {
                    double yi = y[j] + (y[j + 1] - y[j]) * (xi - x[j]) / (x[j + 1] - x[j]);
                    y_interp[i] = yi;
                    break;
                }
            }
        }
        return y_interp;
    }
}
