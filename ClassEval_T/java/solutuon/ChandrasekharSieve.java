package org.example;

import java.util.ArrayList;
import java.util.List;

public class ChandrasekharSieve {
    private int n;
    private List<Integer> primes;

    public ChandrasekharSieve(int n) {
        this.n = n;
        this.primes = generatePrimes();
    }

    private List<Integer> generatePrimes() {
        if (n < 2) {
            return new ArrayList<>();
        }

        boolean[] sieve = new boolean[n + 1];
        for (int i = 0; i <= n; i++) {
            sieve[i] = true;
        }
        sieve[0] = sieve[1] = false;

        int p = 2;
        while (p * p <= n) {
            if (sieve[p]) {
                for (int i = p * p; i <= n; i += p) {
                    sieve[i] = false;
                }
            }
            p += 1;
        }

        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (sieve[i]) {
                primes.add(i);
            }
        }

        return primes;
    }

    public List<Integer> getPrimes() {
        return primes;
    }

    public static void main(String[] args) {
        ChandrasekharSieve cs = new ChandrasekharSieve(20);
        System.out.println(cs.getPrimes());
    }
}