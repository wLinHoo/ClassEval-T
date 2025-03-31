#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "pch.h" 

class CurrencyConverterTestConvert : public ::testing::Test {
protected:
    CurrencyConverter cc;
};

TEST_F(CurrencyConverterTestConvert, test_convert_1) {
    double res = cc.convert(64, "CNY", "USD");
    ASSERT_EQ(res, 10.0);
}

TEST_F(CurrencyConverterTestConvert, test_convert_2) {
    double res = cc.convert(64, "USD", "USD");
    ASSERT_EQ(res, 64);
}

TEST_F(CurrencyConverterTestConvert, test_convert_3) {
    double res = cc.convert(64, "CNY", "GBP");
    ASSERT_NEAR(res, 7.1999999999999, 1e-9);
}

TEST_F(CurrencyConverterTestConvert, test_convert_4) {
    double res = cc.convert(64, "USD", "GBP");
    ASSERT_NEAR(res, 46.08, 1e-9);
}

TEST_F(CurrencyConverterTestConvert, test_convert_5) {
    double res = cc.convert(64, "USD", "CAD");
    ASSERT_NEAR(res, 78.72, 1e-9);
}

TEST_F(CurrencyConverterTestConvert, test_convert_6) {
    bool res = cc.convert(64, "???", "USD");
    ASSERT_FALSE(res);
}

class CurrencyConverterTestGetSupportedCurrencies : public ::testing::Test {
protected:
    CurrencyConverter cc;
};

TEST_F(CurrencyConverterTestGetSupportedCurrencies, test_get_supported_currencies_1) {
    std::vector<std::string> res = cc.get_supported_currencies();
    std::vector<std::string> expected = { "USD", "EUR", "GBP", "JPY", "CAD", "AUD", "CNY" };
    ASSERT_EQ(res, expected);
}

TEST_F(CurrencyConverterTestGetSupportedCurrencies, test_get_supported_currencies_2) {
    std::vector<std::string> res = cc.get_supported_currencies();
    std::vector<std::string> expected = { "USD", "EUR", "GBP", "JPY", "CAD", "AUD", "CNY" };
    ASSERT_EQ(res, expected);
}

TEST_F(CurrencyConverterTestGetSupportedCurrencies, test_get_supported_currencies_3) {
    std::vector<std::string> res = cc.get_supported_currencies();
    std::vector<std::string> expected = { "USD", "EUR", "GBP", "JPY", "CAD", "AUD", "CNY" };
    ASSERT_EQ(res, expected);
}

TEST_F(CurrencyConverterTestGetSupportedCurrencies, test_get_supported_currencies_4) {
    std::vector<std::string> res = cc.get_supported_currencies();
    std::vector<std::string> expected = { "USD", "EUR", "GBP", "JPY", "CAD", "AUD", "CNY" };
    ASSERT_EQ(res, expected);
}

TEST_F(CurrencyConverterTestGetSupportedCurrencies, test_get_supported_currencies_5) {
    std::vector<std::string> res = cc.get_supported_currencies();
    std::vector<std::string> expected = { "USD", "EUR", "GBP", "JPY", "CAD", "AUD", "CNY" };
    ASSERT_EQ(res, expected);
}

class CurrencyConverterTestAddCurrencyRate : public ::testing::Test {
protected:
    CurrencyConverter cc;
};

TEST_F(CurrencyConverterTestAddCurrencyRate, test_add_currency_rate_1) {
    cc.add_currency_rate("KRW", 1308.84);
    ASSERT_EQ(cc.rates["KRW"], 1308.84);
}

TEST_F(CurrencyConverterTestAddCurrencyRate, test_add_currency_rate_2) {
    cc.add_currency_rate("aaa", 1.0);
    ASSERT_EQ(cc.rates["aaa"], 1.0);
}

TEST_F(CurrencyConverterTestAddCurrencyRate, test_add_currency_rate_3) {
    cc.add_currency_rate("bbb", 2.0);
    ASSERT_EQ(cc.rates["bbb"], 2.0);
}

TEST_F(CurrencyConverterTestAddCurrencyRate, test_add_currency_rate_4) {
    cc.add_currency_rate("ccc", 3.0);
    ASSERT_EQ(cc.rates["ccc"], 3.0);
}

TEST_F(CurrencyConverterTestAddCurrencyRate, test_add_currency_rate_5) {
    cc.add_currency_rate("ddd", 4.0);
    ASSERT_EQ(cc.rates["ddd"], 4.0);
}

TEST_F(CurrencyConverterTestAddCurrencyRate, test_add_currency_rate_6) {
    bool res = cc.add_currency_rate("USD", 1.0);
    ASSERT_FALSE(res);
}

class CurrencyConverterTestUpdateCurrencyRate : public ::testing::Test {
protected:
    CurrencyConverter cc;
};

TEST_F(CurrencyConverterTestUpdateCurrencyRate, test_update_currency_rate_1) {
    cc.update_currency_rate("CNY", 7.18);
    ASSERT_EQ(cc.rates["CNY"], 7.18);
}

TEST_F(CurrencyConverterTestUpdateCurrencyRate, test_update_currency_rate_2) {
    cc.update_currency_rate("CNY", 1.0);
    ASSERT_EQ(cc.rates["CNY"], 1.0);
}

TEST_F(CurrencyConverterTestUpdateCurrencyRate, test_update_currency_rate_3) {
    cc.update_currency_rate("CNY", 2.0);
    ASSERT_EQ(cc.rates["CNY"], 2.0);
}

TEST_F(CurrencyConverterTestUpdateCurrencyRate, test_update_currency_rate_4) {
    cc.update_currency_rate("CNY", 3.0);
    ASSERT_EQ(cc.rates["CNY"], 3.0);
}

TEST_F(CurrencyConverterTestUpdateCurrencyRate, test_update_currency_rate_5) {
    cc.update_currency_rate("CNY", 4.0);
    ASSERT_EQ(cc.rates["CNY"], 4.0);
}

TEST_F(CurrencyConverterTestUpdateCurrencyRate, test_update_currency_rate_6) {
    bool res = cc.update_currency_rate("???", 7.18);
    ASSERT_FALSE(res);
}

class CurrencyConverterTest : public ::testing::Test {
protected:
    CurrencyConverter cc;
};

TEST_F(CurrencyConverterTest, test_currencyconverter) {
    double res = cc.convert(64, "CNY", "USD");
    ASSERT_EQ(res, 10.0);

    std::vector<std::string> supported_currencies = cc.get_supported_currencies();
    std::vector<std::string> expected_currencies = { "USD", "EUR", "GBP", "JPY", "CAD", "AUD", "CNY" };
    ASSERT_EQ(supported_currencies, expected_currencies);

    cc.add_currency_rate("KRW", 1308.84);
    ASSERT_EQ(cc.rates["KRW"], 1308.84);

    cc.update_currency_rate("CNY", 7.18);
    ASSERT_EQ(cc.rates["CNY"], 7.18);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}