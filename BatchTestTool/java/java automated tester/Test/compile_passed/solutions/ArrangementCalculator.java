import java.util.List;
import java.util.ArrayList;

public class ArrangementCalculator {
    private List<String> datas;

    public ArrangementCalculator(List<String> datas) {
        this.datas = datas;
    }

    public static int count(int n, int m) {
        if (m == -1 || n == m) {
            return factorial(n);
        } else {
            return factorial(n) / factorial(n - m);
        }
    }

    public static int count(int n) {
        return count(n, -1);
    }

    public static int countAll(int n) {
        int total = 0;
        for (int i = 1; i <= n; i++) {
            total += ArrangementCalculator.count(n, i);
        }
        return total;
    }

    public static int factorial(int n) {
        int result = 1;
        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    public List<List<String>> select(int m) {
        List<List<String>> result = new ArrayList<>();
        if (m == -1) {
            m = datas.size();
        }

        List<String> current = new ArrayList<>();
        List<String> remaining = new ArrayList<>(datas);

        permutationsRecursive(current, remaining, m, result);

        return result;
    }

    public List<List<String>> select() {
        return select(-1);
    }

    public List<List<String>> selectAll() {
        List<List<String>> result = new ArrayList<>();
        for (int i = 1; i <= datas.size(); i++) {
            List<List<String>> partialResult = select(i);
            result.addAll(partialResult);
        }
        return result;
    }

    private void permutationsRecursive(List<String> current, List<String> remaining, int m, List<List<String>> result) {
        if (current.size() == m) {
            result.add(new ArrayList<>(current));
        } else {
            for (int i = 0; i < remaining.size(); i++) {
                List<String> newCurrent = new ArrayList<>(current);
                newCurrent.add(remaining.get(i));
                List<String> newRemaining = new ArrayList<>(remaining);
                newRemaining.remove(i);
                permutationsRecursive(newCurrent, newRemaining, m, result);
            }
        }
    }
}