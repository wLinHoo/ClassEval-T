#include <gtest/gtest.h>
#include "pch.h"

class URLHandlerTest : public ::testing::Test {};

TEST_F(URLHandlerTest, test_urlhandler) {
    URLHandler urlhandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#page");

    std::string temp = urlhandler.get_scheme();
    EXPECT_EQ(temp, "https");

    temp = urlhandler.get_host();
    EXPECT_EQ(temp, "www.baidu.com");

    temp = urlhandler.get_path();
    EXPECT_EQ(temp, "/s?wd=aaa&rsv_spt=1#page");

    std::map<std::string, std::string> queryParams = urlhandler.get_query_params();
    std::map<std::string, std::string> expectedParams = { {"wd", "aaa"}, {"rsv_spt", "1"} };
    EXPECT_EQ(queryParams, expectedParams);

    temp = urlhandler.get_fragment();
    EXPECT_EQ(temp, "page");
}

class URLHandlerTestGetScheme : public ::testing::Test {};

TEST_F(URLHandlerTestGetScheme, test_get_scheme_1) {
    URLHandler urlhandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#page");
    std::string temp = urlhandler.get_scheme();
    EXPECT_EQ(temp, "https");
}

TEST_F(URLHandlerTestGetScheme, test_get_scheme_2) {
    URLHandler urlhandler(
        "https://www.bing.com/search?pglt=41&q=humaneval&cvid=4dc2da2bb4bc429eb498c85245ae5253&aqs=edge.0.0l7j69i61j69i60.10008j0j1&FORM=ANNTA1&PC=U531&mkt=zh-CN");
    std::string temp = urlhandler.get_scheme();
    EXPECT_EQ(temp, "https");
}

TEST_F(URLHandlerTestGetScheme, test_get_scheme_3) {
    URLHandler urlhandler("https://github.com/openai/human-eval");
    std::string temp = urlhandler.get_scheme();
    EXPECT_EQ(temp, "https");
}

TEST_F(URLHandlerTestGetScheme, test_get_scheme_4) {
    URLHandler urlhandler("aaa://github.com/openai/human-eval");
    std::string temp = urlhandler.get_scheme();
    EXPECT_EQ(temp, "aaa");
}

TEST_F(URLHandlerTestGetScheme, test_get_scheme_5) {
    URLHandler urlhandler("bbb://github.com/openai/human-eval");
    std::string temp = urlhandler.get_scheme();
    EXPECT_EQ(temp, "bbb");
}

TEST_F(URLHandlerTestGetScheme, test_get_scheme_6) {
    URLHandler urlhandler("abcdefg");
    std::string temp = urlhandler.get_scheme();
    EXPECT_EQ(temp, "");
}

class URLHandlerTestGetHost : public ::testing::Test {};

TEST_F(URLHandlerTestGetHost, test_get_host_1) {
    URLHandler urlhandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#page");
    std::string temp = urlhandler.get_host();
    EXPECT_EQ(temp, "www.baidu.com");
}

TEST_F(URLHandlerTestGetHost, test_get_host_2) {
    URLHandler urlhandler(
        "https://www.bing.com/search?pglt=41&q=humaneval&cvid=4dc2da2bb4bc429eb498c85245ae5253&aqs=edge.0.0l7j69i61j69i60.10008j0j1&FORM=ANNTA1&PC=U531&mkt=zh-CN");
    std::string temp = urlhandler.get_host();
    EXPECT_EQ(temp, "www.bing.com");
}

TEST_F(URLHandlerTestGetHost, test_get_host_3) {
    URLHandler urlhandler("https://github.com/openai/human-eval");
    std::string temp = urlhandler.get_host();
    EXPECT_EQ(temp, "github.com");
}

TEST_F(URLHandlerTestGetHost, test_get_host_4) {
    URLHandler urlhandler("https://aaa.com/openai/human-eval");
    std::string temp = urlhandler.get_host();
    EXPECT_EQ(temp, "aaa.com");
}

TEST_F(URLHandlerTestGetHost, test_get_host_5) {
    URLHandler urlhandler("https://bbb.com/openai/human-eval");
    std::string temp = urlhandler.get_host();
    EXPECT_EQ(temp, "bbb.com");
}

TEST_F(URLHandlerTestGetHost, test_get_host_6) {
    URLHandler urlhandler("abcdefg");
    std::string temp = urlhandler.get_host();
    EXPECT_EQ(temp, "");
}

TEST_F(URLHandlerTestGetHost, test_get_host_7) {
    URLHandler urlhandler("https://bbb.com");
    std::string temp = urlhandler.get_host();
    EXPECT_EQ(temp, "bbb.com");
}

TEST_F(URLHandlerTestGetHost, test_get_host_8) {
    URLHandler urlhandler("https://bbb.com/");
    std::string temp = urlhandler.get_host();
    EXPECT_EQ(temp, "bbb.com");
}

class URLHandlerTestGetPath : public ::testing::Test {};

TEST_F(URLHandlerTestGetPath, test_get_path_1) {
    URLHandler urlhandler(
        "https://www.baidu.com/s?wd=aaa&rsv_spt=1#page");
    std::string temp = urlhandler.get_path();
    EXPECT_EQ(temp, "/s?wd=aaa&rsv_spt=1#page");
}

TEST_F(URLHandlerTestGetPath, test_get_path_2) {
    URLHandler urlhandler(
        "https://www.bing.com/search?pglt=41&q=humaneval&cvid=4dc2da2bb4bc429eb498c85245ae5253&aqs=edge.0.0l7j69i61j69i60.10008j0j1&FORM=ANNTA1&PC=U531&mkt=zh-CN");
    std::string temp = urlhandler.get_path();
    EXPECT_EQ(temp, "/search?pglt=41&q=humaneval&cvid=4dc2da2bb4bc429eb498c85245ae5253&aqs=edge.0.0l7j69i61j69i60.10008j0j1&FORM=ANNTA1&PC=U531&mkt=zh-CN");
}

TEST_F(URLHandlerTestGetPath, test_get_path_3) {
    URLHandler urlhandler("https://github.com/openai/human-eval");
    std::string temp = urlhandler.get_path();
    EXPECT_EQ(temp, "/openai/human-eval");
}

TEST_F(URLHandlerTestGetPath, test_get_path_4) {
    URLHandler urlhandler("https://github.com/aaa/human-eval");
    std::string temp = urlhandler.get_path();
    EXPECT_EQ(temp, "/aaa/human-eval");
}

TEST_F(URLHandlerTestGetPath, test_get_path_5) {
    URLHandler urlhandler("https://github.com/bbb/human-eval");
    std::string temp = urlhandler.get_path();
    EXPECT_EQ(temp, "/bbb/human-eval");
}

TEST_F(URLHandlerTestGetPath, test_get_path_6) {
    URLHandler urlhandler("abcdefg");
    std::string temp = urlhandler.get_path();
    EXPECT_EQ(temp, "");
}

class URLHandlerTestGetQueryParams : public ::testing::Test {};

TEST_F(URLHandlerTestGetQueryParams, test_get_query_params_1) {
    URLHandler urlhandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#page");
    std::map<std::string, std::string> temp = urlhandler.get_query_params();
    std::map<std::string, std::string> expectedParams = { {"wd", "aaa"}, {"rsv_spt", "1"} };
    EXPECT_EQ(temp, expectedParams);
}

TEST_F(URLHandlerTestGetQueryParams, test_get_query_params_2) {
    URLHandler urlhandler(
        "https://www.bing.com/search?pglt=41&q=humaneval&cvid=4dc2da2bb4bc429eb498c85245ae5253&aqs=edge.0.0l7j69i61j69i60.10008j0j1&FORM=ANNTA1&PC=U531#");
    std::map<std::string, std::string> temp = urlhandler.get_query_params();
    std::map<std::string, std::string> expectedParams = {
        {"pglt", "41"}, {"q", "humaneval"}, {"cvid", "4dc2da2bb4bc429eb498c85245ae5253"},
        {"aqs", "edge.0.0l7j69i61j69i60.10008j0j1"}, {"FORM", "ANNTA1"}, {"PC", "U531"}
    };
    EXPECT_EQ(temp, expectedParams);
}

TEST_F(URLHandlerTestGetQueryParams, test_get_query_params_3) {
    URLHandler urlhandler("https://github.com/openai/human-eval");
    std::map<std::string, std::string> temp = urlhandler.get_query_params();
    EXPECT_TRUE(temp.empty()); 
}

TEST_F(URLHandlerTestGetQueryParams, test_get_query_params_4) {
    URLHandler urlhandler("https://www.baidu.com/s?wd=bbb&rsv_spt=1#page");
    std::map<std::string, std::string> temp = urlhandler.get_query_params();
    std::map<std::string, std::string> expectedParams = { {"wd", "bbb"}, {"rsv_spt", "1"} };
    EXPECT_EQ(temp, expectedParams);
}

TEST_F(URLHandlerTestGetQueryParams, test_get_query_params_5) {
    URLHandler urlhandler("https://www.baidu.com/s?wd=ccc&rsv_spt=1#page");
    std::map<std::string, std::string> temp = urlhandler.get_query_params();
    std::map<std::string, std::string> expectedParams = { {"wd", "ccc"}, {"rsv_spt", "1"} };
    EXPECT_EQ(temp, expectedParams);
}

TEST_F(URLHandlerTestGetQueryParams, test_get_query_params_6) {
    URLHandler urlhandler("https://www.baidu.com/s?&#page");
    std::map<std::string, std::string> temp = urlhandler.get_query_params();
    EXPECT_TRUE(temp.empty()); 
}

class URLHandlerTestGetFragment : public ::testing::Test {};

TEST_F(URLHandlerTestGetFragment, test_get_fragment_1) {
    URLHandler urlhandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#page");
    std::string temp = urlhandler.get_fragment();
    EXPECT_EQ(temp, "page");
}

TEST_F(URLHandlerTestGetFragment, test_get_fragment_2) {
    URLHandler urlhandler(
        "https://www.bing.com/search?pglt=41&q=humaneval&cvid=4dc2da2bb4bc429eb498c85245ae5253&aqs=edge.0.0l7j69i61j69i60.10008j0j1&FORM=ANNTA1&PC=U531&mkt=zh-CN");
    std::string temp = urlhandler.get_fragment();
    EXPECT_EQ(temp, ""); 
}

TEST_F(URLHandlerTestGetFragment, test_get_fragment_3) {
    URLHandler urlhandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#aaa");
    std::string temp = urlhandler.get_fragment();
    EXPECT_EQ(temp, "aaa");
}

TEST_F(URLHandlerTestGetFragment, test_get_fragment_4) {
    URLHandler urlhandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#bbb");
    std::string temp = urlhandler.get_fragment();
    EXPECT_EQ(temp, "bbb");
}

TEST_F(URLHandlerTestGetFragment, test_get_fragment_5) {
    URLHandler urlhandler("https://www.baidu.com/s?wd=aaa&rsv_spt=1#ccc");
    std::string temp = urlhandler.get_fragment();
    EXPECT_EQ(temp, "ccc");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}