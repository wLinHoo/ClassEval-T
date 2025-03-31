#include "pch.h"
#include <gtest/gtest.h>

class ChandrasekharSieveTestGeneratePrimes : public ::testing::Test {};

TEST_F(ChandrasekharSieveTestGeneratePrimes, test_generate_primes_1) {
    ChandrasekharSieve cs(20);
    std::vector<int> res = cs.get_primes();
    EXPECT_EQ(res, (std::vector<int>{2, 3, 5, 7, 11, 13, 17, 19}));
}

TEST_F(ChandrasekharSieveTestGeneratePrimes, test_generate_primes_2) {
    ChandrasekharSieve cs(18);
    std::vector<int> res = cs.get_primes();
    EXPECT_EQ(res, (std::vector<int>{2, 3, 5, 7, 11, 13, 17}));
}

TEST_F(ChandrasekharSieveTestGeneratePrimes, test_generate_primes_3) {
    ChandrasekharSieve cs(15);
    std::vector<int> res = cs.get_primes();
    EXPECT_EQ(res, (std::vector<int>{2, 3, 5, 7, 11, 13}));
}

TEST_F(ChandrasekharSieveTestGeneratePrimes, test_generate_primes_4) {
    ChandrasekharSieve cs(10);
    std::vector<int> res = cs.get_primes();
    EXPECT_EQ(res, (std::vector<int>{2, 3, 5, 7}));
}

TEST_F(ChandrasekharSieveTestGeneratePrimes, test_generate_primes_5) {
    ChandrasekharSieve cs(1);
    std::vector<int> res = cs.get_primes();
    EXPECT_EQ(res, std::vector<int>{});
}

class ChandrasekharSieveTestGetPrimes : public ::testing::Test {};

TEST_F(ChandrasekharSieveTestGetPrimes, test_get_primes_1) {
    ChandrasekharSieve cs(20);
    std::vector<int> res = cs.get_primes();
    EXPECT_EQ(res, (std::vector<int>{2, 3, 5, 7, 11, 13, 17, 19}));
}

TEST_F(ChandrasekharSieveTestGetPrimes, test_get_primes_2) {
    ChandrasekharSieve cs(18);
    std::vector<int> res = cs.get_primes();
    EXPECT_EQ(res, (std::vector<int>{2, 3, 5, 7, 11, 13, 17}));
}

TEST_F(ChandrasekharSieveTestGetPrimes, test_get_primes_3) {
    ChandrasekharSieve cs(15);
    std::vector<int> res = cs.get_primes();
    EXPECT_EQ(res, (std::vector<int>{2, 3, 5, 7, 11, 13}));
}

TEST_F(ChandrasekharSieveTestGetPrimes, test_get_primes_4) {
    ChandrasekharSieve cs(10);
    std::vector<int> res = cs.get_primes();
    EXPECT_EQ(res, (std::vector<int>{2, 3, 5, 7}));
}

TEST_F(ChandrasekharSieveTestGetPrimes, test_get_primes_5) {
    ChandrasekharSieve cs(1);
    std::vector<int> res = cs.get_primes();
    EXPECT_EQ(res, std::vector<int>{});
}

class ChandrasekharSieveTest : public ::testing::Test {};

TEST_F(ChandrasekharSieveTest, test_chandrasekharsieve) {
    ChandrasekharSieve cs(20);
    std::vector<int> res = cs.get_primes();
    EXPECT_EQ(res, (std::vector<int>{2, 3, 5, 7, 11, 13, 17, 19}));
    res = cs.get_primes();
    EXPECT_EQ(res, (std::vector<int>{2, 3, 5, 7, 11, 13, 17, 19}));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}