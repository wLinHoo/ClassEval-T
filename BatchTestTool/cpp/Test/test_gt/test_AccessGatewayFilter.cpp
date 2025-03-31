#include <gtest/gtest.h>
#include "pch.h"
#include <ctime>
#include <string>

class AccessGatewayFilterTestFilter : public ::testing::Test {
protected:
    AccessGatewayFilter agf;
};

TEST_F(AccessGatewayFilterTestFilter, TestFilter1) {
    Request request = { "/api/data", "GET", {} };
    EXPECT_TRUE(agf.filter(request));
}

TEST_F(AccessGatewayFilterTestFilter, TestFilter2) {
    Request request = { "/api/data", "POST", {} };
    EXPECT_TRUE(agf.filter(request));
}

TEST_F(AccessGatewayFilterTestFilter, TestFilter3) {
    Request request = { "/login/data", "GET", {} };
    EXPECT_TRUE(agf.filter(request));
}

TEST_F(AccessGatewayFilterTestFilter, TestFilter4) {
    Request request = { "/login/data", "POST", {} };
    EXPECT_TRUE(agf.filter(request));
}

TEST_F(AccessGatewayFilterTestFilter, TestFilter5) {
    std::time_t now = std::time(nullptr);
    User user = { "user1", 5, "address1" };
    Authorization auth = { user, "user1" + std::to_string(now) };
    Request request = { "/abc", "POST", auth };
    EXPECT_TRUE(agf.filter(request));
}

TEST_F(AccessGatewayFilterTestFilter, TestFilter6) {
    std::time_t now = std::time(nullptr); 
    User user = { "user1", 3, "address1" }; 
    Authorization auth = { user, "user1" + std::to_string(now - 365 * 24 * 60 * 60) }; 
    Request request = { "/abc", "POST", auth }; 
    EXPECT_FALSE(agf.filter(request)); 
}


TEST_F(AccessGatewayFilterTestFilter, TestFilter7) {
    std::time_t now = std::time(nullptr);
    User user = { "user1", 1, "address1" };
    Authorization auth = { user, "user1" + std::to_string(now) };
    Request request = { "/abc", "POST", auth };
    EXPECT_FALSE(agf.filter(request));
}

TEST_F(AccessGatewayFilterTestFilter, TestFilter8) {
    std::time_t now = std::time(nullptr);
    User user = { "user1", 3, "address1" };
    Authorization auth = { user, "user2" + std::to_string(now - 365 * 24 * 60 * 60) };
    Request request = { "/abc", "POST", auth };
    EXPECT_TRUE(agf.filter(request));
}

class AccessGatewayFilterTestIsStartWith : public ::testing::Test {
protected:
    AccessGatewayFilter agf;
};

TEST_F(AccessGatewayFilterTestIsStartWith, TestIsStartWith1) {
    std::string request_uri = "/api/data";
    EXPECT_TRUE(agf.is_start_with(request_uri));
}

TEST_F(AccessGatewayFilterTestIsStartWith, TestIsStartWith2) {
    std::string request_uri = "/admin/settings";
    EXPECT_FALSE(agf.is_start_with(request_uri));
}

TEST_F(AccessGatewayFilterTestIsStartWith, TestIsStartWith3) {
    std::string request_uri = "/login/data";
    EXPECT_TRUE(agf.is_start_with(request_uri));
}

TEST_F(AccessGatewayFilterTestIsStartWith, TestIsStartWith4) {
    std::string request_uri = "/abc/data";
    EXPECT_FALSE(agf.is_start_with(request_uri));
}

TEST_F(AccessGatewayFilterTestIsStartWith, TestIsStartWith5) {
    std::string request_uri = "/def/data";
    EXPECT_FALSE(agf.is_start_with(request_uri));
}

class AccessGatewayFilterTestGetJwtUser : public ::testing::Test {
protected:
    AccessGatewayFilter agf;
};

TEST_F(AccessGatewayFilterTestGetJwtUser, TestGetJwtUser1) {
    std::time_t now = std::time(nullptr);
    User user = { "user1", 0, "" };
    Authorization auth = { user, "user1" + std::to_string(now) };
    Request request = { "", "", auth };
    EXPECT_TRUE(!agf.get_jwt_user(request).jwt.empty());
}

TEST_F(AccessGatewayFilterTestGetJwtUser, TestGetJwtUser2) {
    std::time_t now = std::time(nullptr);
    User user = { "user2", 0, "" };
    Authorization auth = { user, "user2" + std::to_string(now) };
    Request request = { "", "", auth };
    EXPECT_TRUE(!agf.get_jwt_user(request).jwt.empty());
}

TEST_F(AccessGatewayFilterTestGetJwtUser, TestGetJwtUser3) {
    std::time_t now = std::time(nullptr);
    User user = { "user3", 0, "" };
    Authorization auth = { user, "user3" + std::to_string(now) };
    Request request = { "", "", auth };
    EXPECT_TRUE(!agf.get_jwt_user(request).jwt.empty());
}

TEST_F(AccessGatewayFilterTestGetJwtUser, TestGetJwtUser4) {
    std::time_t now = std::time(nullptr);
    User user = { "user4", 0, "" };
    Authorization auth = { user, "user4" + std::to_string(now) };
    Request request = { "", "", auth };
    EXPECT_TRUE(!agf.get_jwt_user(request).jwt.empty());
}

TEST_F(AccessGatewayFilterTestGetJwtUser, TestGetJwtUser5) {
    std::time_t now = std::time(nullptr);
    User user = { "user1", 0, "" };
    Authorization auth = { user, "user1" + std::to_string(now - 5 * 24 * 60 * 60) };
    Request request = { "", "", auth };
    EXPECT_TRUE(agf.get_jwt_user(request).jwt.empty());
}

class AccessGatewayFilterTestMain : public ::testing::Test {
protected:
    AccessGatewayFilter agf;
};
TEST_F(AccessGatewayFilterTestMain, TestMain) {
    Request request = { "/api/data", "GET", {} };
    EXPECT_TRUE(agf.filter(request));

    std::string request_uri = "/api/data";
    EXPECT_TRUE(agf.is_start_with(request_uri));

    std::time_t now = std::time(nullptr);
    User user = { "user1", 0, "" };
    Authorization auth = { user, "user1" + std::to_string(now) };
    Request request2 = { "", "", auth };
    EXPECT_TRUE(!agf.get_jwt_user(request2).jwt.empty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}