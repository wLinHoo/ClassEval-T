#include <gtest/gtest.h>
#include "pch.h"
#include <unordered_map>
#include <string>

using CookiesMap = std::unordered_map<std::string, std::string>;

class CookiesUtilTestGetCookies : public ::testing::Test {
protected:
    CookiesUtil cookies_util;
    std::unordered_map<std::string, CookiesMap> response;

    CookiesUtilTestGetCookies() : cookies_util("cookies.json") {}

    void SetUp() override {
        response = { {"cookies", {{"key1", "value1"}, {"key2", "value2"}}} };
    }
};

TEST_F(CookiesUtilTestGetCookies, TestGetCookies) {
    cookies_util.get_cookies(response);
    EXPECT_EQ(cookies_util.cookies, (CookiesMap{ {"key1", "value1"}, {"key2", "value2"} }));
}

TEST_F(CookiesUtilTestGetCookies, TestGetCookies2) {
    response["cookies2"] = { {"key3", "value3"}, {"key4", "value4"} };
    cookies_util.get_cookies(response);
    EXPECT_EQ(cookies_util.cookies, (CookiesMap{ {"key1", "value1"}, {"key2", "value2"} }));
}

TEST_F(CookiesUtilTestGetCookies, TestGetCookies3) {
    response["cookies2"] = { {"key3", "value3"}, {"key4", "value4"} };
    response["cookies3"] = { {"key5", "value5"}, {"key6", "value6"} };
    cookies_util.get_cookies(response);
    EXPECT_EQ(cookies_util.cookies, (CookiesMap{ {"key1", "value1"}, {"key2", "value2"} }));
}

TEST_F(CookiesUtilTestGetCookies, TestGetCookies4) {
    response["cookies2"] = { {"key3", "value3"}, {"key4", "value4"} };
    response["cookies3"] = { {"key5", "value5"}, {"key6", "value6"} };
    response["cookies4"] = { {"key7", "value7"}, {"key8", "value8"} };
    cookies_util.get_cookies(response);
    EXPECT_EQ(cookies_util.cookies, (CookiesMap{ {"key1", "value1"}, {"key2", "value2"} }));
}

TEST_F(CookiesUtilTestGetCookies, TestGetCookies5) {
    response["cookies2"] = { {"key3", "value3"}, {"key4", "value4"} };
    response["cookies3"] = { {"key5", "value5"}, {"key6", "value6"} };
    response["cookies4"] = { {"key7", "value7"}, {"key8", "value8"} };
    response["cookies5"] = { {"key9", "value9"}, {"key10", "value10"} };
    cookies_util.get_cookies(response);
    EXPECT_EQ(cookies_util.cookies, (CookiesMap{ {"key1", "value1"}, {"key2", "value2"} }));
}

class CookiesUtilTestLoadCookies : public ::testing::Test {
protected:
    CookiesUtil cookies_util;

    CookiesUtilTestLoadCookies() : cookies_util("cookies.json") {}

    void SetUp() override {
        cookies_util.cookies = { {"key1", "value1"}, {"key2", "value2"} };
    }
};

TEST_F(CookiesUtilTestLoadCookies, TestLoadCookies) {
    EXPECT_EQ(cookies_util.load_cookies(), (CookiesMap{ {"key1", "value1"}, {"key2", "value2"} }));
}

TEST_F(CookiesUtilTestLoadCookies, TestLoadCookies2) {
    cookies_util.cookies = { {"key1", "value1"}, {"key2", "value2"} };
    EXPECT_EQ(cookies_util.load_cookies(), (CookiesMap{ {"key1", "value1"}, {"key2", "value2"} }));
}

TEST_F(CookiesUtilTestLoadCookies, TestLoadCookies3) {
    cookies_util.cookies = { {"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"} };
    EXPECT_EQ(cookies_util.load_cookies(), (CookiesMap{ {"key1", "value1"}, {"key2", "value2"} }));
}

TEST_F(CookiesUtilTestLoadCookies, TestLoadCookies4) {
    cookies_util.cookies = { {"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}, {"key6", "value6"} };
    EXPECT_EQ(cookies_util.load_cookies(), (CookiesMap{ {"key1", "value1"}, {"key2", "value2"} }));
}

TEST_F(CookiesUtilTestLoadCookies, TestLoadCookies5) {
    cookies_util.cookies = { {"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}, {"key6", "value6"},{"key7", "value7"}, {"key8", "value8"} };
    EXPECT_EQ(cookies_util.load_cookies(), (CookiesMap{ {"key1", "value1"}, {"key2", "value2"} }));
}

TEST_F(CookiesUtilTestLoadCookies, TestLoadCookies6) {
    CookiesUtil empty_cookies_util("");
    nlohmann::json expected;
    EXPECT_EQ(empty_cookies_util.load_cookies(), expected);
}

class CookiesUtilTestSaveCookies : public ::testing::Test {
protected:
    CookiesUtil cookies_util;

    CookiesUtilTestSaveCookies() : cookies_util("cookies.json") {}

    void SetUp() override {
        cookies_util.cookies = { {"key1", "value1"}, {"key2", "value2"} };
    }
};

TEST_F(CookiesUtilTestSaveCookies, TestSaveCookies) {
    EXPECT_TRUE(cookies_util._save_cookies());
}

TEST_F(CookiesUtilTestSaveCookies, TestSaveCookies2) {
    cookies_util.cookies = { {"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"} };
    EXPECT_TRUE(cookies_util._save_cookies());
}

TEST_F(CookiesUtilTestSaveCookies, TestSaveCookies3) {
    cookies_util.cookies = { {"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}, {"key6", "value6"} };
    EXPECT_TRUE(cookies_util._save_cookies());
}

TEST_F(CookiesUtilTestSaveCookies, TestSaveCookies4) {
    cookies_util.cookies = { {"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}, {"key6", "value6"}, {"key7", "value7"}, {"key8", "value8"} };
    EXPECT_TRUE(cookies_util._save_cookies());
}

TEST_F(CookiesUtilTestSaveCookies, TestSaveCookies5) {
    cookies_util.cookies = { {"key1", "value1"}, {"key2", "value2"}, {"key3", "value3"}, {"key4", "value4"}, {"key5", "value5"}, {"key6", "value6"}, {"key7", "value7"}, {"key8", "value8"}, {"key9", "value9"}, {"key10", "value10"} };
    EXPECT_TRUE(cookies_util._save_cookies());
}

TEST_F(CookiesUtilTestSaveCookies, TestSaveCookies6) {
    CookiesUtil empty_cookies_util("");
    EXPECT_FALSE(empty_cookies_util._save_cookies());
}

class CookiesUtilTestSetCookies : public ::testing::Test {
protected:
    CookiesUtil cookies_util;

    CookiesUtilTestSetCookies() : cookies_util("cookies.json") {}

    void SetUp() override {
        cookies_util.cookies = { {"key1", "value1"}, {"key2", "value2"} };
    }
};

TEST_F(CookiesUtilTestSetCookies, TestSetCookies) {
    nlohmann::json request;
    cookies_util.set_cookies(request);
    EXPECT_EQ(request["cookies"], "key1=value1; key2=value2");
}

class CookiesUtilTestMain : public ::testing::Test {
protected:
    CookiesUtil cookies_util;
    nlohmann::json cookies_data;

    CookiesUtilTestMain() : cookies_util("cookies.json") {}

    void SetUp() override {
        cookies_data = {
        {"cookies", {
            {"key1", "value1"},
            {"key2", "value2"}
        }}
        };

    }
};

TEST_F(CookiesUtilTestMain, TestMain) {
    
    cookies_util.get_cookies(cookies_data);

    CookiesMap expected_cookies = { {"key1", "value1"}, {"key2", "value2"} };
    EXPECT_EQ(cookies_util.cookies, expected_cookies);

    EXPECT_EQ(cookies_util.load_cookies(), expected_cookies);
    EXPECT_TRUE(cookies_util._save_cookies());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

