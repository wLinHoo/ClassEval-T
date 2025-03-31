package org.example;

import org.junit.jupiter.api.Test;
import java.util.Arrays;
import java.util.List;
import static org.junit.jupiter.api.Assertions.*;

public class AvgPartitionTest {

    @org.junit.Test
    @Test
    public void testSetNum() {
        AvgPartition a = new AvgPartition(Arrays.asList(1, 2, 3, 4), 2);
        int[] result = a.setNum();
        assertArrayEquals(new int[]{2, 0}, result);
    }

    @Test
    public void testSetNum_2() {
        AvgPartition a = new AvgPartition(Arrays.asList(1, 2, 3, 4, 5), 2);
        int[] result = a.setNum();
        assertArrayEquals(new int[]{2, 1}, result);
    }

    @Test
    public void testSetNum_3() {
        AvgPartition a = new AvgPartition(Arrays.asList(1, 2, 3, 4, 5), 3);
        int[] result = a.setNum();
        assertArrayEquals(new int[]{1, 2}, result);
    }

    @Test
    public void testSetNum_4() {
        AvgPartition a = new AvgPartition(Arrays.asList(1, 2, 3, 4, 5), 4);
        int[] result = a.setNum();
        assertArrayEquals(new int[]{1, 1}, result);
    }

    @Test
    public void testSetNum_5() {
        AvgPartition a = new AvgPartition(Arrays.asList(1, 2, 3, 4, 5), 5);
        int[] result = a.setNum();
        assertArrayEquals(new int[]{1, 0}, result);
    }

    @Test
    public void testGet() {
        AvgPartition a = new AvgPartition(Arrays.asList(1, 2, 3, 4), 2);
        List<Integer> result = a.get(0);
        assertEquals(Arrays.asList(1, 2), result);
    }

    @Test
    public void testGet_2() {
        AvgPartition a = new AvgPartition(Arrays.asList(1, 2, 3, 4), 2);
        List<Integer> result = a.get(1);
        assertEquals(Arrays.asList(3, 4), result);
    }

    @Test
    public void testGet_3() {
        AvgPartition a = new AvgPartition(Arrays.asList(1, 2, 3, 4, 5), 2);
        List<Integer> result = a.get(0);
        assertEquals(Arrays.asList(1, 2, 3), result);
    }

    @Test
    public void testGet_4() {
        AvgPartition a = new AvgPartition(Arrays.asList(1, 2, 3, 4, 5), 2);
        List<Integer> result = a.get(1);
        assertEquals(Arrays.asList(4, 5), result);
    }

    @Test
    public void testGet_5() {
        AvgPartition a = new AvgPartition(Arrays.asList(1, 2, 3, 4, 5), 3);
        List<Integer> result = a.get(0);
        assertEquals(Arrays.asList(1, 2), result);
    }

    @Test
    public void testMain() {
        AvgPartition a = new AvgPartition(Arrays.asList(1, 2, 3, 4), 2);
        int[] result = a.setNum();
        assertArrayEquals(new int[]{2, 0}, result);
        List<Integer> block = a.get(0);
        assertEquals(Arrays.asList(1, 2), block);
    }
}