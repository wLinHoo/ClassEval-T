#include <gtest/gtest.h>
#include "pch.h"  

class IPAddressTestIsValid : public ::testing::Test {
protected:
    
};

TEST_F(IPAddressTestIsValid, test_is_valid_1) {
    IPAddress ipaddress("10.10.10.10");
    EXPECT_EQ(ipaddress.is_valid(), true);
}

TEST_F(IPAddressTestIsValid, test_is_valid_2) {
    IPAddress ipaddress("-1.10.10.10");
    EXPECT_EQ(ipaddress.is_valid(), false);
}

TEST_F(IPAddressTestIsValid, test_is_valid_3) {
    IPAddress ipaddress("10.10.10");
    EXPECT_EQ(ipaddress.is_valid(), false);
}

TEST_F(IPAddressTestIsValid, test_is_valid_4) {
    IPAddress ipaddress("a.10.10.10");
    EXPECT_EQ(ipaddress.is_valid(), false);
}

TEST_F(IPAddressTestIsValid, test_is_valid_5) {
    IPAddress ipaddress("300.10.10.10");
    EXPECT_EQ(ipaddress.is_valid(), false);
}

class IPAddressTestGetOctets : public ::testing::Test {
protected:
    
};

TEST_F(IPAddressTestGetOctets, test_get_octets_1) {
    IPAddress ipaddress("10.10.10.10");
    std::vector<std::string> now{ "10", "10", "10", "10" };
    EXPECT_EQ(ipaddress.get_octets(), now);
}

TEST_F(IPAddressTestGetOctets, test_get_octets_2) {
    IPAddress ipaddress("a.10.10.10");
    EXPECT_EQ(ipaddress.get_octets(), std::vector<std::string>{});
}

TEST_F(IPAddressTestGetOctets, test_get_octets_3) {
    IPAddress ipaddress("-1.10.10.10");
    EXPECT_EQ(ipaddress.get_octets(), std::vector<std::string>{});
}

TEST_F(IPAddressTestGetOctets, test_get_octets_4) {
    IPAddress ipaddress("300.10.10.10");
    EXPECT_EQ(ipaddress.get_octets(), std::vector<std::string>{});
}

TEST_F(IPAddressTestGetOctets, test_get_octets_5) {
    IPAddress ipaddress(".10.10.10");
    EXPECT_EQ(ipaddress.get_octets(), std::vector<std::string>{});
}

class IPAddressTestGetBinary : public ::testing::Test {
protected:
    
};

TEST_F(IPAddressTestGetBinary, test_get_binary_1) {
    IPAddress ipaddress("10.10.10.10");
    EXPECT_EQ(ipaddress.get_binary(), "00001010.00001010.00001010.00001010");
}

TEST_F(IPAddressTestGetBinary, test_get_binary_2) {
    IPAddress ipaddress("a.10.10.10");
    EXPECT_EQ(ipaddress.get_binary(), "");
}

TEST_F(IPAddressTestGetBinary, test_get_binary_3) {
    IPAddress ipaddress("-1.10.10.10");
    EXPECT_EQ(ipaddress.get_binary(), "");
}

TEST_F(IPAddressTestGetBinary, test_get_binary_4) {
    IPAddress ipaddress("300.10.10.10");
    EXPECT_EQ(ipaddress.get_binary(), "");
}

TEST_F(IPAddressTestGetBinary, test_get_binary_5) {
    IPAddress ipaddress(".10.10.10");
    EXPECT_EQ(ipaddress.get_binary(), "");
}

class IPAddressTest : public ::testing::Test {
protected:
    
};

TEST_F(IPAddressTest, test_IPAddress) {
    IPAddress ipaddress("10.10.10.10");
    EXPECT_EQ(ipaddress.is_valid(), true);
    std::vector<std::string> now{ "10", "10", "10", "10" };
    EXPECT_EQ(ipaddress.get_octets(), now);
    EXPECT_EQ(ipaddress.get_binary(), "00001010.00001010.00001010.00001010");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
