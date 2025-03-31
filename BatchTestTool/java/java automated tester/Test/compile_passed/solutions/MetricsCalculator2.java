import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class MetricsCalculator2 {

    public static class Pair<T1, T2> {
        public T1 first;
        public T2 second;

        public Pair(T1 first, T2 second) {
            this.first = first;
            this.second = second;
        }
    }

    public MetricsCalculator2() {
        // empty constructor
    }

    public static Pair<Double, List<Double>> map(Object data) throws Exception {
        if (!(data instanceof List) && !(data instanceof Pair)) {
            throw new Exception("the input must be a tuple([0,...,1,...],int) or a iteration of list of tuple");
        }

        if (data instanceof Pair) {
            @SuppressWarnings("unchecked")
            Pair<List<Integer>, Integer> tuple = (Pair<List<Integer>, Integer>) data;
            List<Integer> subList = tuple.first;
            int totalNum = tuple.second;

            if (subList.isEmpty()) {
                List<Double> result = new ArrayList<>();
                result.add(0.0);
                return new Pair<>(0.0, result);
            }

            if (totalNum == 0) {
                List<Double> result = new ArrayList<>();
                result.add(0.0);
                return new Pair<>(0.0, result);
            } else {
                double[] rankingArray = new double[subList.size()];
                for (int i = 0; i < rankingArray.length; i++) {
                    rankingArray[i] = 1.0 / (i + 1);
                }

                List<Integer> rightRankingList = new ArrayList<>();
                int count = 1;
                for (int t : subList) {
                    if (t == 0) {
                        rightRankingList.add(0);
                    } else {
                        rightRankingList.add(count);
                        count++;
                    }
                }

                double ap = 0;
                for (int i = 0; i < rightRankingList.size(); i++) {
                    ap += rightRankingList.get(i) * rankingArray[i];
                }
                ap /= totalNum;

                List<Double> result = new ArrayList<>();
                result.add(ap);
                return new Pair<>(ap, result);
            }
        }

        if (data instanceof List) {
            @SuppressWarnings("unchecked")
            List<Pair<List<Integer>, Integer>> dataList = (List<Pair<List<Integer>, Integer>>) data;
            List<Double> separateResult = new ArrayList<>();

            for (Pair<List<Integer>, Integer> tuple : dataList) {
                List<Integer> subList = tuple.first;
                int totalNum = tuple.second;

                double ap;
                if (totalNum == 0) {
                    ap = 0.0;
                } else {
                    double[] rankingArray = new double[subList.size()];
                    for (int i = 0; i < rankingArray.length; i++) {
                        rankingArray[i] = 1.0 / (i + 1);
                    }

                    List<Integer> rightRankingList = new ArrayList<>();
                    int count = 1;
                    for (int t : subList) {
                        if (t == 0) {
                            rightRankingList.add(0);
                        } else {
                            rightRankingList.add(count);
                            count++;
                        }
                    }

                    ap = 0;
                    for (int i = 0; i < rightRankingList.size(); i++) {
                        ap += rightRankingList.get(i) * rankingArray[i];
                    }
                    ap /= totalNum;
                }

                separateResult.add(ap);
            }

            double mean = separateResult.stream()
                    .mapToDouble(Double::doubleValue)
                    .average()
                    .orElse(0.0);

            return new Pair<>(mean, separateResult);
        }

        // This should never happen due to the initial check
        throw new Exception("Invalid input type");
    }

    public static Pair<Double, double[]> mrr(Object data) {
        if (!(data instanceof List<?>) && !(data instanceof Pair<?, ?>)) {
            throw new IllegalArgumentException("the input must be a Pair([0,...,1,...],int) or a List of Pairs");
        }

        if (data instanceof Pair<?, ?>) {
            @SuppressWarnings("unchecked")
            Pair<List<Double>, Integer> pair = (Pair<List<Double>, Integer>) data;
            List<Double> subList = pair.first;
            int totalNum = pair.second;

            if (subList.isEmpty()) {
                return new Pair<>(0.0, new double[]{0.0});
            }

            if (totalNum == 0) {
                return new Pair<>(0.0, new double[]{0.0});
            } else {
                double[] rankingArray = new double[subList.size()];
                for (int i = 0; i < rankingArray.length; i++) {
                    rankingArray[i] = 1.0 / (i + 1);
                }

                double mr = 0.0;
                for (int i = 0; i < subList.size(); i++) {
                    double value = subList.get(i) * rankingArray[i];
                    if (value > 0) {
                        mr = value;
                        break;
                    }
                }
                return new Pair<>(mr, new double[]{mr});
            }
        }

        @SuppressWarnings("unchecked")
        List<Pair<List<Double>, Integer>> dataList = (List<Pair<List<Double>, Integer>>) data;
        if (dataList.isEmpty()) {
            return new Pair<>(0.0, new double[]{0.0});
        }

        List<Double> separateResult = new ArrayList<>();
        for (Pair<List<Double>, Integer> pair : dataList) {
            List<Double> subList = pair.first;
            int totalNum = pair.second;

            double mr = 0.0;
            if (totalNum != 0) {
                double[] rankingArray = new double[subList.size()];
                for (int i = 0; i < rankingArray.length; i++) {
                    rankingArray[i] = 1.0 / (i + 1);
                }

                for (int i = 0; i < subList.size(); i++) {
                    double value = subList.get(i) * rankingArray[i];
                    if (value > 0) {
                        mr = value;
                        break;
                    }
                }
            }
            separateResult.add(mr);
        }

        // Calculate mean
        double mean = separateResult.stream()
                .mapToDouble(Double::doubleValue)
                .average()
                .orElse(0.0);

        // Convert List<Double> to double[]
        double[] resultArray = separateResult.stream()
                .mapToDouble(Double::doubleValue)
                .toArray();

        return new Pair<>(mean, resultArray);
    }
}