package org.example;

import java.util.Arrays;

public class KappaCalculator {

    public static double kappa(int[][] testData, int k) {
        int[][] dataMat = testData;
        double P0 = 0.0;
        for (int i = 0; i < k; i++) {
            P0 += dataMat[i][i] * 1.0;
        }
        int[] xsum = new int[k];
        int[] ysum = new int[k];
        int sum = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                xsum[i] += dataMat[i][j];
                ysum[j] += dataMat[i][j];
                sum += dataMat[i][j];
            }
        }
        double Pe = 0.0;
        for (int i = 0; i < k; i++) {
            Pe += ysum[i] * xsum[i];
        }
        Pe = Pe / (sum * sum);
        P0 = P0 / sum;
        return (P0 - Pe) / (1 - Pe);
    }

    public static double fleissKappa(int[][] testData, int N, int k, int n) {
        int[][] dataMat = testData;
        double[] P = new double[N];
        double sum = 0.0;
        for (int i = 0; i < N; i++) {
            double temp = 0.0;
            for (int j = 0; j < k; j++) {
                sum += dataMat[i][j];
                temp += dataMat[i][j] * dataMat[i][j];
            }
            temp -= n;
            temp /= (n - 1) * n;
            P[i] = temp;
        }
        double P0 = Arrays.stream(P).sum() / N;
        double[] pj = new double[k];
        for (int j = 0; j < k; j++) {
            for (int i = 0; i < N; i++) {
                pj[j] += dataMat[i][j];
            }
            pj[j] /= sum;
        }
        double Pe = Arrays.stream(pj).map(p -> p * p).sum();
        return (P0 - Pe) / (1 - Pe);
    }

    public static void main(String[] args) {
        System.out.println(kappa(new int[][]{{2, 1, 1}, {1, 2, 1}, {1, 1, 2}}, 3)); // 0.25
        System.out.println(fleissKappa(new int[][]{{0, 0, 0, 0, 14},
                {0, 2, 6, 4, 2},
                {0, 0, 3, 5, 6},
                {0, 3, 9, 2, 0},
                {2, 2, 8, 1, 1},
                {7, 7, 0, 0, 0},
                {3, 2, 6, 3, 0},
                {2, 5, 3, 2, 2},
                {6, 5, 2, 1, 0},
                {0, 2, 2, 3, 7}}, 10, 5, 14));
    }
}