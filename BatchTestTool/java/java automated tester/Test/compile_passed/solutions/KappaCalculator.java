import java.util.Arrays;

public class KappaCalculator {

    public static double fleissKappa(double[][] testData, int N, int k, int n) {
        double sum = 0.0;
        double P0 = 0.0;
        for (int i = 0; i < N; i++) {
            double temp = 0.0;
            for (int j = 0; j < k; j++) {
                sum += testData[i][j];
                temp += Math.pow(testData[i][j], 2);
            }
            temp -= n;
            temp /= (n - 1) * n;
            P0 += temp;
        }
        P0 = P0 / N;
        double[] ysum = new double[k];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < k; j++) {
                ysum[j] += testData[i][j];
            }
        }
        for (int i = 0; i < k; i++) {
            ysum[i] = Math.pow(ysum[i] / sum, 2);
        }
        double Pe = 0.0;
        for (int i = 0; i < k; i++) {
            Pe += ysum[i];
        }
        Pe /= k;
        double ans = (P0 - Pe) / (1 - Pe);
        return ans;
    }

    public static double kappa(double[][] testData, int k) {
        double P0 = 0.0;
        for (int i = 0; i < k; i++) {
            P0 += testData[i][i];
        }
        double[] xsum = new double[testData.length];
        double[] ysum = new double[testData[0].length];
        double sum = 0;
        for (int i = 0; i < testData.length; i++) {
            for (int j = 0; j < testData[0].length; j++) {
                sum += testData[i][j];
                xsum[i] += testData[i][j];
                ysum[j] += testData[i][j];
            }
        }
        double Pe = 0;
        for (int i = 0; i < xsum.length; i++) {
            for (int j = 0; j < ysum.length; j++) {
                Pe += (xsum[i] * ysum[j]) / (sum * sum);
            }
        }
        P0 = P0 / sum;
        double cohens_coefficient = (P0 - Pe) / (1 - Pe);
        return cohens_coefficient;
    }

    public static void main(String[] args) {
        double[][] testData = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int k = 3;
        double kappa = kappa(testData, k);
        System.out.println("Cohen's kappa coefficient: " + kappa);
    }
}