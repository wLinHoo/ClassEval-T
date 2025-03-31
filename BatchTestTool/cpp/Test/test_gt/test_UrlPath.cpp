#include <gtest/gtest.h>
#include "pch.h"  

class UrlPathTestAdd : public ::testing::Test {
protected:
    UrlPath url_path;
};

TEST_F(UrlPathTestAdd, test_add_1) {
    url_path.add("foo");
    url_path.add("bar");
    std::vector<std::string> now{ "foo", "bar" };
    EXPECT_EQ(url_path.get_segments(), now);
}

TEST_F(UrlPathTestAdd, test_add_2) {
    url_path.add("aaa");
    url_path.add("bbb");
    std::vector<std::string> now{ "aaa", "bbb" };
    EXPECT_EQ(url_path.get_segments(), now);
}

TEST_F(UrlPathTestAdd, test_add_3) {
    url_path.add("123");
    EXPECT_EQ(url_path.get_segments(), std::vector<std::string>{"123"});
}

TEST_F(UrlPathTestAdd, test_add_4) {
    url_path.add("ddd");
    EXPECT_EQ(url_path.get_segments(), std::vector<std::string>{"ddd"});
}

TEST_F(UrlPathTestAdd, test_add_5) {
    url_path.add("eee");
    EXPECT_EQ(url_path.get_segments(), std::vector<std::string>{"eee"});
}

class UrlPathTestParse : public ::testing::Test {
protected:
    UrlPath url_path;
};

TEST_F(UrlPathTestParse, test_parse_1) {
    url_path.parse("/foo/bar/", "utf-8");
    std::vector<std::string> now{ "foo", "bar" };
    EXPECT_EQ(url_path.get_segments(), now);
    EXPECT_EQ(url_path.with_end_tag(), true);
}

TEST_F(UrlPathTestParse, test_parse_2) {
    url_path.parse("aaa/bbb", "utf-8");
    std::vector<std::string> now{ "aaa", "bbb" };
    EXPECT_EQ(url_path.get_segments(), now);
    EXPECT_EQ(url_path.with_end_tag(), false);
}

TEST_F(UrlPathTestParse, test_parse_3) {
    url_path.parse("/123/456/", "utf-8");
    std::vector<std::string> now{ "123", "456" };
    EXPECT_EQ(url_path.get_segments(), now);
    EXPECT_EQ(url_path.with_end_tag(), true);
}

TEST_F(UrlPathTestParse, test_parse_4) {
    url_path.parse("/123/456/789", "utf-8");
    std::vector<std::string> now{ "123", "456", "789"};
    EXPECT_EQ(url_path.get_segments(), now);
    EXPECT_EQ(url_path.with_end_tag(), false);
}

TEST_F(UrlPathTestParse, test_parse_5) {
    url_path.parse("/foo/bar", "utf-8");
    std::vector<std::string> now{ "foo", "bar" };
    EXPECT_EQ(url_path.get_segments(), now);
    EXPECT_EQ(url_path.with_end_tag(), false);
}

TEST_F(UrlPathTestParse, test_parse_6) {
    url_path.parse("", "utf-8");
    EXPECT_EQ(url_path.get_segments(), std::vector<std::string>{});
    EXPECT_EQ(url_path.with_end_tag(), false);
}

TEST_F(UrlPathTestParse, test_parse_7) {
    url_path.parse("//", "utf-8");
    EXPECT_EQ(url_path.get_segments(), std::vector<std::string>{});
    EXPECT_EQ(url_path.with_end_tag(), true);
}

class UrlPathTestFixPath : public ::testing::Test {};

TEST_F(UrlPathTestFixPath, test_fix_path_1) {
    std::string fixed_path = UrlPath::fix_path("/foo/bar/");
    EXPECT_EQ(fixed_path, "foo/bar");
}

TEST_F(UrlPathTestFixPath, test_fix_path_2) {
    std::string fixed_path = UrlPath::fix_path("/aaa/bbb/");
    EXPECT_EQ(fixed_path, "aaa/bbb");
}

TEST_F(UrlPathTestFixPath, test_fix_path_3) {
    std::string fixed_path = UrlPath::fix_path("/a/b/");
    EXPECT_EQ(fixed_path, "a/b");
}

TEST_F(UrlPathTestFixPath, test_fix_path_4) {
    std::string fixed_path = UrlPath::fix_path("/111/222/");
    EXPECT_EQ(fixed_path, "111/222");
}

TEST_F(UrlPathTestFixPath, test_fix_path_5) {
    std::string fixed_path = UrlPath::fix_path("/a/");
    EXPECT_EQ(fixed_path, "a");
}

TEST_F(UrlPathTestFixPath, test_fix_path_6) {
    std::string fixed_path = UrlPath::fix_path("");
    EXPECT_EQ(fixed_path, "");
}

class UrlPathTest : public ::testing::Test {
protected:
    UrlPath url_path;
};

TEST_F(UrlPathTest, test_urlpath) {
    url_path.add("foo");
    url_path.add("bar");
    std::vector<std::string> now{ "foo", "bar" };
    EXPECT_EQ(url_path.get_segments(), now);

    UrlPath url_path2;
    url_path2.parse("/foo/bar/", "utf-8");
    std::vector<std::string> kkk{ "foo", "bar" };
    EXPECT_EQ(url_path2.get_segments(), kkk);
    EXPECT_EQ(url_path2.with_end_tag(), true);

    std::string fixed_path = UrlPath::fix_path("/foo/bar/");
    EXPECT_EQ(fixed_path, "foo/bar");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}