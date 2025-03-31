#include <gtest/gtest.h>
#include "pch.h" 

class EncryptionUtilsTestCaesarCipher : public ::testing::Test {
protected:
    EncryptionUtils* encryption_utils;

    void SetUp() override {
        encryption_utils = new EncryptionUtils("key");
    }

    void TearDown() override {
        delete encryption_utils;
    }
};

TEST_F(EncryptionUtilsTestCaesarCipher, test_caesar_cipher) {
    EXPECT_EQ(encryption_utils->caesar_cipher("abc", 1), "bcd");
}

TEST_F(EncryptionUtilsTestCaesarCipher, test_caesar_cipher_2) {
    EXPECT_EQ(encryption_utils->caesar_cipher("WORLD", -2), "UMPJB");
}

TEST_F(EncryptionUtilsTestCaesarCipher, test_caesar_cipher_3) {
    EXPECT_EQ(encryption_utils->caesar_cipher("", 4), "");
}

TEST_F(EncryptionUtilsTestCaesarCipher, test_caesar_cipher_4) {
    EXPECT_EQ(encryption_utils->caesar_cipher("abcxyz", 26), "abcxyz");
}

TEST_F(EncryptionUtilsTestCaesarCipher, test_caesar_cipher_5) {
    EXPECT_EQ(encryption_utils->caesar_cipher("abcxyz", 27), "bcdyza");
}

TEST_F(EncryptionUtilsTestCaesarCipher, test_caesar_cipher_6) {
    EXPECT_EQ(encryption_utils->caesar_cipher("123", 27), "123");
}

class EncryptionUtilsTestVigenereCipher : public ::testing::Test {
protected:
    EncryptionUtils* encryption_utils;

    void SetUp() override {
        encryption_utils = new EncryptionUtils("key");
    }

    void TearDown() override {
        delete encryption_utils;
    }
};

TEST_F(EncryptionUtilsTestVigenereCipher, test_vigenere_cipher) {
    EXPECT_EQ(encryption_utils->vigenere_cipher("abc"), "kfa");
}

TEST_F(EncryptionUtilsTestVigenereCipher, test_vigenere_cipher_2) {
    EXPECT_EQ(encryption_utils->vigenere_cipher("hello"), "rijvs");
}

TEST_F(EncryptionUtilsTestVigenereCipher, test_vigenere_cipher_3) {
    EncryptionUtils encryption_utils("longkey");
    EXPECT_EQ(encryption_utils.vigenere_cipher("AbCdEfG"), "LpPjOjE");
}

TEST_F(EncryptionUtilsTestVigenereCipher, test_vigenere_cipher_4) {
    EXPECT_EQ(encryption_utils->vigenere_cipher("Hello, World! 123"), "Rijvs, Uyvjn! 123");
}

TEST_F(EncryptionUtilsTestVigenereCipher, test_vigenere_cipher_5) {
    EXPECT_EQ(encryption_utils->vigenere_cipher(""), "");
}

class EncryptionUtilsTestRailFenceCipher : public ::testing::Test {
protected:
    EncryptionUtils* encryption_utils;

    void SetUp() override {
        encryption_utils = new EncryptionUtils("key");
    }

    void TearDown() override {
        delete encryption_utils;
    }
};

TEST_F(EncryptionUtilsTestRailFenceCipher, test_rail_fence_cipher) {
    EXPECT_EQ(encryption_utils->rail_fence_cipher("abc", 2), "acb");
}

TEST_F(EncryptionUtilsTestRailFenceCipher, test_rail_fence_cipher_2) {
    EXPECT_EQ(encryption_utils->rail_fence_cipher("hello", 2), "hloel");
}

TEST_F(EncryptionUtilsTestRailFenceCipher, test_rail_fence_cipher_3) {
    EncryptionUtils encryption_utils("longkey");
    EXPECT_EQ(encryption_utils.rail_fence_cipher("AbCdEfG", 2), "ACEGbdf");
}

TEST_F(EncryptionUtilsTestRailFenceCipher, test_rail_fence_cipher_4) {
    EXPECT_EQ(encryption_utils->rail_fence_cipher("Hello, World! 123", 2), "Hlo ol!13el,Wrd 2");
}

TEST_F(EncryptionUtilsTestRailFenceCipher, test_rail_fence_cipher_5) {
    EXPECT_EQ(encryption_utils->rail_fence_cipher("", 2), "");
}

TEST_F(EncryptionUtilsTestRailFenceCipher, test_rail_fence_cipher_6) {
    EXPECT_EQ(encryption_utils->rail_fence_cipher("abcdefg", 3), "aebdfcg");
}

class EncryptionUtilsTestMain : public ::testing::Test {
protected:
    EncryptionUtils* encryption_utils;

    void SetUp() override {
        encryption_utils = new EncryptionUtils("key");
    }

    void TearDown() override {
        delete encryption_utils;
    }
};

TEST_F(EncryptionUtilsTestMain, test_main) {
    EXPECT_EQ(encryption_utils->caesar_cipher("abc", 1), "bcd");
    EXPECT_EQ(encryption_utils->vigenere_cipher("abc"), "kfa");
    EXPECT_EQ(encryption_utils->rail_fence_cipher("abc", 2), "acb");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}