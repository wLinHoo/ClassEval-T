package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.List;
import java.util.Arrays;

public class ChandrasekharSieveTest {

    @Test
    public void testGeneratePrimes1() {
        ChandrasekharSieve cs = new ChandrasekharSieve(20);
        List<Integer> expected = Arrays.asList(2, 3, 5, 7, 11, 13, 17, 19);
        assertEquals(expected, cs.getPrimes());
    }

    @Test
    public void testGeneratePrimes2() {
        ChandrasekharSieve cs = new ChandrasekharSieve(18);
        List<Integer> expected = Arrays.asList(2, 3, 5, 7, 11, 13, 17);
        assertEquals(expected, cs.getPrimes());
    }

    @Test
    public void testGeneratePrimes3() {
        ChandrasekharSieve cs = new ChandrasekharSieve(15);
        List<Integer> expected = Arrays.asList(2, 3, 5, 7, 11, 13);
        assertEquals(expected, cs.getPrimes());
    }

    @Test
    public void testGeneratePrimes4() {
        ChandrasekharSieve cs = new ChandrasekharSieve(10);
        List<Integer> expected = Arrays.asList(2, 3, 5, 7);
        assertEquals(expected, cs.getPrimes());
    }

    @Test
    public void testGeneratePrimes5() {
        ChandrasekharSieve cs = new ChandrasekharSieve(1);
        List<Integer> expected = List.of();
        assertEquals(expected, cs.getPrimes());
    }

    @Test
    public void testGetPrimes1() {
        ChandrasekharSieve cs = new ChandrasekharSieve(20);
        List<Integer> expected = Arrays.asList(2, 3, 5, 7, 11, 13, 17, 19);
        assertEquals(expected, cs.getPrimes());
    }

    @Test
    public void testGetPrimes2() {
        ChandrasekharSieve cs = new ChandrasekharSieve(18);
        List<Integer> expected = Arrays.asList(2, 3, 5, 7, 11, 13, 17);
        assertEquals(expected, cs.getPrimes());
    }

    @Test
    public void testGetPrimes3() {
        ChandrasekharSieve cs = new ChandrasekharSieve(15);
        List<Integer> expected = Arrays.asList(2, 3, 5, 7, 11, 13);
        assertEquals(expected, cs.getPrimes());
    }

    @Test
    public void testGetPrimes4() {
        ChandrasekharSieve cs = new ChandrasekharSieve(10);
        List<Integer> expected = Arrays.asList(2, 3, 5, 7);
        assertEquals(expected, cs.getPrimes());
    }

    @Test
    public void testGetPrimes5() {
        ChandrasekharSieve cs = new ChandrasekharSieve(1);
        List<Integer> expected = List.of();
        assertEquals(expected, cs.getPrimes());
    }

    @Test
    public void testChandrasekharSieve() {
        ChandrasekharSieve cs = new ChandrasekharSieve(20);
        List<Integer> expected = Arrays.asList(2, 3, 5, 7, 11, 13, 17, 19);
        assertEquals(expected, cs.getPrimes());
    }
}