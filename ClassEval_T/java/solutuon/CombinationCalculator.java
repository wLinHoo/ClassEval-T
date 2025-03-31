package org.example;

import java.util.ArrayList;
import java.util.List;

public class CombinationCalculator {
    private List<String> datas;

    public CombinationCalculator(List<String> datas) {
        this.datas = datas;
    }

    public static int count(int n, int m) {
        if (m == 0 || n == m) {
            return 1;
        }
        return factorial(n) / (factorial(n - m) * factorial(m));
    }

    private static int factorial(int x) {
        int result = 1;
        for (int i = 1; i <= x; i++) {
            result *= i;
        }
        return result;
    }

    public static double countAll(int n) {
        if (n < 0 || n > 63) {
            return Double.NaN;
        }
        return n != 63 ? (1 << n) - 1 : Double.POSITIVE_INFINITY;
    }

    public List<List<String>> select(int m) {
        List<List<String>> result = new ArrayList<>();
        _select(0, new ArrayList<>(m), 0, result, m);
        return result;
    }

    public List<List<String>> selectAll() {
        List<List<String>> result = new ArrayList<>();
        for (int i = 1; i <= datas.size(); i++) {
            result.addAll(select(i));
        }
        return result;
    }

    protected void _select(int dataIndex, List<String> resultList, int resultIndex, List<List<String>> result, int m) {
        if (resultIndex == m) {
            result.add(new ArrayList<>(resultList));
            return;
        }

        for (int i = dataIndex; i <= datas.size() - (m - resultIndex); i++) {
            resultList.add(resultIndex, datas.get(i));
            _select(i + 1, resultList, resultIndex + 1, result, m);
            resultList.remove(resultIndex);
        }
    }
}
