package to_be_tested;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.List;

public class DataStatistics {

    public double median(double[] data) {
        Arrays.sort(data);
        int n = data.length;
        if (n % 2 == 0) {
            int middle = n / 2;
            return (data[middle - 1] + data[middle]) / 2.0;
        } else {
            int middle = n / 2;
            return data[middle];
        }
    }

    public String[] mode(int[] data) {
        Map<Integer, Integer> counter = new HashMap<>();
        int modeCount = 0;
        int[] modeValues = new int[0];
        for (int value : data) {
            if (counter.containsKey(value)) {
                counter.put(value, counter.get(value) + 1);
            } else {
                counter.put(value, 1);
            }
            if (counter.get(value) > modeCount) {
                modeCount = counter.get(value);
                modeValues = new int[] { value };
            } else if (counter.get(value) == modeCount) {
                boolean found = false;
                for (int modeValue : modeValues) {
                    if (modeValue == value) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    int[] newArray = new int[modeValues.length + 1];
                    System.arraycopy(modeValues, 0, newArray, 0, modeValues.length);
                    newArray[modeValues.length] = value;
                    modeValues = newArray;
                }
            }
        }
        String[] modes = new String[modeValues.length];
        for (int i = 0; i < modeValues.length; i++) {
            modes[i] = String.valueOf(modeValues[i]);
        }
        return modes;
    }

    public double mean(List<Integer> data) {
        double sum = 0;
        for (int num : data) {
            sum += num;
        }
        return Double.parseDouble(String.format("%.2f", sum / data.size()));
    }
}
