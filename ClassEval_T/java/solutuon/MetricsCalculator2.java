package org.example;

import java.util.List;
import java.util.ArrayList;

public class MetricsCalculator2 {

    public static double mrr(Object data) {
        if (!(data instanceof List) && !(data instanceof Tuple)) {
            throw new IllegalArgumentException("the input must be a tuple([0,...,1,...],int) or a iteration of list of tuple");
        }

        if (data instanceof Tuple) {
            Tuple tuple = (Tuple) data;
            List<Integer> subList = tuple.getList();
            int totalNum = tuple.getTotalNum();

            if (totalNum == 0) {
                return 0.0;
            }

            double mr = 0.0;
            for (int i = 0; i < subList.size(); i++) {
                if (subList.get(i) == 1) {
                    mr = 1.0 / (i + 1);
                    break;
                }
            }
            return mr;
        }
        else {
            List<Tuple> tupleList = (List<Tuple>) data;
            List<Double> separateResult = new ArrayList<>();

            for (Tuple tuple : tupleList) {
                List<Integer> subList = tuple.getList();
                int totalNum = tuple.getTotalNum();

                if (totalNum == 0) {
                    separateResult.add(0.0);
                } else {
                    double mr = 0.0;
                    for (int i = 0; i < subList.size(); i++) {
                        if (subList.get(i) == 1) {
                            mr = 1.0 / (i + 1);
                            break;
                        }
                    }
                    separateResult.add(mr);
                }
            }
            return separateResult.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
        }
    }

    public static double map(Object data) {
        if (!(data instanceof List) && !(data instanceof Tuple)) {
            throw new IllegalArgumentException("the input must be a tuple([0,...,1,...],int) or a iteration of list of tuple");
        }

        if (data instanceof Tuple) {
            Tuple tuple = (Tuple) data;
            List<Integer> subList = tuple.getList();
            int totalNum = tuple.getTotalNum();

            if (totalNum == 0) {
                return 0.0;
            }

            double ap = 0.0;
            int count = 0;
            for (int i = 0; i < subList.size(); i++) {
                if (subList.get(i) == 1) {
                    count++;
                    ap += count / (i + 1.0);
                }
            }
            return ap / totalNum;
        } else {
            List<Tuple> tupleList = (List<Tuple>) data;
            List<Double> separateResult = new ArrayList<>();

            for (Tuple tuple : tupleList) {
                List<Integer> subList = tuple.getList();
                int totalNum = tuple.getTotalNum();

                if (totalNum == 0) {
                    separateResult.add(0.0);
                } else {
                    double ap = 0.0;
                    int count = 0;
                    for (int i = 0; i < subList.size(); i++) {
                        if (subList.get(i) == 1) {
                            count++;
                            ap += count / (i + 1.0);
                        }
                    }
                    separateResult.add(ap / totalNum);
                }
            }
            return separateResult.stream().mapToDouble(Double::doubleValue).average().orElse(0.0);
        }
    }

    public static class Tuple {
        private List<Integer> list;
        private int totalNum;

        public Tuple(List<Integer> list, int totalNum) {
            this.list = list;
            this.totalNum = totalNum;
        }

        public List<Integer> getList() {
            return list;
        }

        public int getTotalNum() {
            return totalNum;
        }
    }
}