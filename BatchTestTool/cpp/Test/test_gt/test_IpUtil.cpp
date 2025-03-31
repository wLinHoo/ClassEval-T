#include <gtest/gtest.h>
#include "pch.h"  

class IpUtilTestIsValidIpv4 : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(IpUtilTestIsValidIpv4, TestIsValidIpv4_1) {
    bool result = IpUtil::is_valid_ipv4("192.168.0.123");
    ASSERT_EQ(result, true);
}

TEST_F(IpUtilTestIsValidIpv4, TestIsValidIpv4_2) {
    bool result = IpUtil::is_valid_ipv4("10.10.10.10");
    ASSERT_EQ(result, true);
}

TEST_F(IpUtilTestIsValidIpv4, TestIsValidIpv4_3) {
    bool result = IpUtil::is_valid_ipv4("0.0.0.0");
    ASSERT_EQ(result, true);
}

TEST_F(IpUtilTestIsValidIpv4, TestIsValidIpv4_4) {
    bool result = IpUtil::is_valid_ipv4("abc.168.0.123");
    ASSERT_EQ(result, false);
}

TEST_F(IpUtilTestIsValidIpv4, TestIsValidIpv4_5) {
    bool result = IpUtil::is_valid_ipv4("256.0.0.0");
    ASSERT_EQ(result, false);
}

class IpUtilTestIsValidIpv6 : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(IpUtilTestIsValidIpv6, TestIsValidIpv6_1) {
    bool result = IpUtil::is_valid_ipv6("2001:0db8:85a3:0000:0000:8a2e:0370:7334");
    ASSERT_EQ(result, true);
}

TEST_F(IpUtilTestIsValidIpv6, TestIsValidIpv6_2) {
    bool result = IpUtil::is_valid_ipv6("2001:0db8:85a3:::8a2e:0370:7334");
    ASSERT_EQ(result, false);
}

TEST_F(IpUtilTestIsValidIpv6, TestIsValidIpv6_3) {
    bool result = IpUtil::is_valid_ipv6("2001:0db8:85a3:2001:llll:8a2e:0370:7334");
    ASSERT_EQ(result, false);
}

TEST_F(IpUtilTestIsValidIpv6, TestIsValidIpv6_4) {
    bool result = IpUtil::is_valid_ipv6("2001:0db8:85a3:llll:llll:8a2e:0370:7334");
    ASSERT_EQ(result, false);
}

TEST_F(IpUtilTestIsValidIpv6, TestIsValidIpv6_5) {
    bool result = IpUtil::is_valid_ipv6("2001:0db8:85a3::llll:8a2e:0370:7334");
    ASSERT_EQ(result, false);
}

class IpUtilTestGetHostname : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(IpUtilTestGetHostname, TestGetHostname_1) {
    std::string result = IpUtil::get_hostname("110.242.68.3");
    ASSERT_EQ(result, "");
}

TEST_F(IpUtilTestGetHostname, TestGetHostname_2) {
    std::string result = IpUtil::get_hostname("10.0.0.1");
    ASSERT_EQ(result, "");
}

TEST_F(IpUtilTestGetHostname, TestGetHostname_3) {
    std::string result = IpUtil::get_hostname("0.0.0.0");
    ASSERT_EQ(result, "LAPTOP-2CS86KUM");
}

TEST_F(IpUtilTestGetHostname, TestGetHostname_4) {
    std::string result = IpUtil::get_hostname("0.0.0.1");
    ASSERT_EQ(result, "");
}

TEST_F(IpUtilTestGetHostname, TestGetHostname_5) {
    std::string result = IpUtil::get_hostname("0.0.0.2");
    ASSERT_EQ(result, "");
}

class IpUtilTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(IpUtilTest, TestIpUtil) {
    bool result = IpUtil::is_valid_ipv4("192.168.0.123");
    ASSERT_EQ(result, true);

    result = IpUtil::is_valid_ipv6("2001:0db8:85a3:0000:0000:8a2e:0370:7334");
    ASSERT_EQ(result, true);

    std::string hostname = IpUtil::get_hostname("110.242.68.3");
    ASSERT_EQ(hostname, "");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


