package org.example;

import java.util.ArrayList;
import java.util.List;

public class ArrangementCalculator {
    private List<Object> datas;

    public ArrangementCalculator(List<Object> datas) {
        this.datas = datas;
    }

    public static int count(int n, Integer m) {
        if (m == null || n == m) {
            return factorial(n);
        }
        else {
            return factorial(n) / factorial(n - m);
        }
    }

    public static int countAll(int n) {
        int total = 0;
        for (int i = 1; i <= n; i++) {
            total += count(n, i);
        }
        return total;
    }

    public List<List<Object>> select(Integer m) {
        if (m == null) {
            m = datas.size();
        }
        List<List<Object>> result = new ArrayList<>();
        selectPermutations(new ArrayList<>(), new ArrayList<>(datas), m, result);
        return result;
    }

    public List<List<Object>> selectAll() {
        List<List<Object>> result = new ArrayList<>();
        for (int i = 1; i <= datas.size(); i++) {
            result.addAll(select(i));
        }
        return result;
    }

    private void selectPermutations(List<Object> prefix, List<Object> remaining, int m, List<List<Object>> result) {
        if (prefix.size() == m) {
            result.add(new ArrayList<>(prefix));
            return;
        }
        for (int i = 0; i < remaining.size(); i++) {
            List<Object> newPrefix = new ArrayList<>(prefix);
            newPrefix.add(remaining.get(i));
            List<Object> newRemaining = new ArrayList<>(remaining);
            newRemaining.remove(i);
            selectPermutations(newPrefix, newRemaining, m, result);
        }
    }

    public static int factorial(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}
