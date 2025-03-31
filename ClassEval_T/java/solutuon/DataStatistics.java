package org.example;

import java.util.*;
import java.util.stream.Collectors;

public class DataStatistics {

    public double mean(int[] data) {
        double sum = Arrays.stream(data).sum();
        return Math.round((sum / data.length) * 100.0) / 100.0;
    }

    public double median(int[] data) {
        int[] sortedData = Arrays.copyOf(data, data.length);
        Arrays.sort(sortedData);
        int n = sortedData.length;

        if (n % 2 == 0) {
            int middle = n / 2;
            return Math.round(((sortedData[middle - 1] + sortedData[middle]) / 2.0) * 100.0) / 100.0;
        } else {
            int middle = n / 2;
            return sortedData[middle];
        }
    }

    public List<Integer> mode(int[] data) {
        Map<Integer, Long> frequencyMap = Arrays.stream(data)
                .boxed()
                .collect(Collectors.groupingBy(e -> e, Collectors.counting()));

        long maxCount = Collections.max(frequencyMap.values());

        return frequencyMap.entrySet()
                .stream()
                .filter(entry -> entry.getValue() == maxCount)
                .map(Map.Entry::getKey)
                .sorted()
                .collect(Collectors.toList());
    }
}
