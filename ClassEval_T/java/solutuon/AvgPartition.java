package org.example;

import java.util.ArrayList;
import java.util.List;

public class AvgPartition {
    private List<Integer> lst;
    private int limit;

    public AvgPartition(List<Integer> lst, int limit) {
        this.lst = lst;
        this.limit = limit;
    }

    public int[] setNum() {
        int size = lst.size() / limit;
        int remainder = lst.size() % limit;
        return new int[]{size, remainder};
    }

    public List<Integer> get(int index) {
        int[] nums = setNum();
        int size = nums[0];
        int remainder = nums[1];
        int start = index * size + Math.min(index, remainder);
        int end = start + size;
        if (index + 1 <= remainder) {
            end += 1;
        }
        return lst.subList(start, end);
    }

    public static void main(String[] args) {
        List<Integer> lst = new ArrayList<>();
        lst.add(1);
        lst.add(2);
        lst.add(3);
        lst.add(4);
        AvgPartition a = new AvgPartition(lst, 2);
        System.out.println(a.get(0));
        System.out.println(a.get(1));
    }
}