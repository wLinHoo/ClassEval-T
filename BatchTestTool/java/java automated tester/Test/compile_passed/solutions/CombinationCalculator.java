import java.util.List;
import java.util.ArrayList;
import java.math.BigInteger;

public class CombinationCalculator {
    private List<String> datas;

    public CombinationCalculator(List<String> datas) {
        this.datas = datas;
    }

    public static int count(int n, int m) {
        if (m == 0 || n == m) {
            return 1;
        }
        int factorialN = factorial(n);
        int factorialNM = factorial(n - m);
        int factorialM = factorial(m);
        return factorialN / (factorialNM * factorialM);
    }

    private static int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }

    public static int countAll(int n) {
        if (n < 0 || n > 63) {
            return -1; // or throw an exception
        }
        BigInteger result = BigInteger.ZERO;
        for (int i = 0; i < n; i++) {
            result = result.shiftLeft(1);
        }
        return result.intValue();
    }

    public List<List<String>> select(int m) {
        List<List<String>> result = new ArrayList<>();
        _select(0, new ArrayList<>(m), 0, result);
        return result;
    }

    public List<List<String>> selectAll() {
        List<List<String>> result = new ArrayList<>();
        for (int i = 1; i <= datas.size(); i++) {
            result.addAll(select(i));
        }
        return result;
    }

    private void _select(int dataIndex, List<String> resultList, int resultIndex, List<List<String>> result) {
        int resultLen = resultList.size();
        int resultCount = resultIndex + 1;
        if (resultCount > resultLen) {
            result.add(new ArrayList<>(resultList));
            return;
        }

        for (int i = dataIndex; i <= datas.size() - resultLen + resultCount; i++) {
            resultList.set(resultIndex, datas.get(i));
            _select(i + 1, resultList, resultIndex + 1, result);
        }
    }
}