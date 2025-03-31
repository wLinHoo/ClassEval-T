#include <vector>

class ChandrasekharSieve {
public:
    ChandrasekharSieve(int n);
    std::vector<int> get_primes() const;

private:
    int n;
    std::vector<int> primes;

    std::vector<int> generate_primes();
};

ChandrasekharSieve::ChandrasekharSieve(int n) : n(n) {
    primes = generate_primes();
}

std::vector<int> ChandrasekharSieve::generate_primes() {
    if (n < 2) {
        return {};
    }

    std::vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;

    int p = 2;
    while (p * p <= n) {
        if (sieve[p]) {
            for (int i = p * p; i <= n; i += p) {
                sieve[i] = false;
            }
        }
        p++;
    }

    std::vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

std::vector<int> ChandrasekharSieve::get_primes() const {
    return primes;
}
