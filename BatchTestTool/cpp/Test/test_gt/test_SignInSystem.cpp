#include <gtest/gtest.h>
#include "pch.h"  

class SignInSystemTest : public ::testing::Test {
protected:
    void SetUp() override {
        signin_system = new SignInSystem();
    }

    void TearDown() override {
        delete signin_system;
    }

    SignInSystem* signin_system;
};

TEST_F(SignInSystemTest, TestMain) {
    bool result;

    result = signin_system->add_user("user1");
    result = signin_system->add_user("user2");
    EXPECT_TRUE(result);

    result = signin_system->sign_in("user1");
    EXPECT_TRUE(result);

    result = signin_system->check_sign_in("user1");
    EXPECT_TRUE(result);

    result = signin_system->all_signed_in();
    EXPECT_FALSE(result);

    std::vector<std::string> result_vector = signin_system->all_not_signed_in();
    std::vector<std::string> expected_vector = { "user2" };
    EXPECT_EQ(result_vector, expected_vector);
}

class SignInSystemTestAddUser : public ::testing::Test {};

TEST(SignInSystemTestAddUser, TestAddUser1) {
    SignInSystem signin_system;
    bool result = signin_system.add_user("user1");
    EXPECT_TRUE(result);
}

TEST(SignInSystemTestAddUser, TestAddUser2) {
    SignInSystem signin_system;
    signin_system.add_user("user1");
    bool result = signin_system.add_user("user1");
    EXPECT_FALSE(result);
}

TEST(SignInSystemTestAddUser, TestAddUser3) {
    SignInSystem signin_system;
    bool result = signin_system.add_user("aaa");
    EXPECT_TRUE(result);
}

TEST(SignInSystemTestAddUser, TestAddUser4) {
    SignInSystem signin_system;
    bool result = signin_system.add_user("bbb");
    EXPECT_TRUE(result);
}

TEST(SignInSystemTestAddUser, TestAddUser5) {
    SignInSystem signin_system;
    bool result = signin_system.add_user("ccc");
    EXPECT_TRUE(result);
}

class SignInSystemTestSignIn : public ::testing::Test {};

TEST(SignInSystemTestSignIn, TestSignIn1) {
    SignInSystem signin_system;
    signin_system.add_user("user1");
    bool result = signin_system.sign_in("user1");
    EXPECT_TRUE(result);
}

TEST(SignInSystemTestSignIn, TestSignIn2) {
    SignInSystem signin_system;
    bool result = signin_system.sign_in("user1");
    EXPECT_FALSE(result);
}

TEST(SignInSystemTestSignIn, TestSignIn3) {
    SignInSystem signin_system;
    signin_system.add_user("aaa");
    bool result = signin_system.sign_in("aaa");
    EXPECT_TRUE(result);
}

TEST(SignInSystemTestSignIn, TestSignIn4) {
    SignInSystem signin_system;
    signin_system.add_user("bbb");
    bool result = signin_system.sign_in("bbb");
    EXPECT_TRUE(result);
}

TEST(SignInSystemTestSignIn, TestSignIn5) {
    SignInSystem signin_system;
    bool result = signin_system.sign_in("ccc");
    EXPECT_FALSE(result);
}

class SignInSystemTestCheckSignIn : public ::testing::Test {};

TEST(SignInSystemTestCheckSignIn, TestCheckSignIn1) {
    SignInSystem signin_system;
    signin_system.add_user("user1");
    signin_system.sign_in("user1");
    bool result = signin_system.check_sign_in("user1");
    EXPECT_TRUE(result);
}

TEST(SignInSystemTestCheckSignIn, TestCheckSignIn2) {
    SignInSystem signin_system;
    signin_system.add_user("user1");
    bool result = signin_system.check_sign_in("user1");
    EXPECT_FALSE(result);
}

TEST(SignInSystemTestCheckSignIn, TestCheckSignIn3) {
    SignInSystem signin_system;
    bool result = signin_system.check_sign_in("user1");
    EXPECT_FALSE(result);
}

TEST(SignInSystemTestCheckSignIn, TestCheckSignIn4) {
    SignInSystem signin_system;
    signin_system.add_user("aaa");
    signin_system.sign_in("aaa");
    bool result = signin_system.check_sign_in("aaa");
    EXPECT_TRUE(result);
}

TEST(SignInSystemTestCheckSignIn, TestCheckSignIn5) {
    SignInSystem signin_system;
    signin_system.add_user("bbb");
    signin_system.sign_in("bbb");
    bool result = signin_system.check_sign_in("bbb");
    EXPECT_TRUE(result);
}


class SignInSystemTestAllSignedIn : public ::testing::Test {};

TEST(SignInSystemTestAllSignedIn, TestAllSignedIn1) {
    SignInSystem signin_system;
    signin_system.add_user("user1");
    signin_system.sign_in("user1");
    bool result = signin_system.all_signed_in();
    EXPECT_TRUE(result);
}

TEST(SignInSystemTestAllSignedIn, TestAllSignedIn2) {
    SignInSystem signin_system;
    signin_system.add_user("user1");
    bool result = signin_system.all_signed_in();
    EXPECT_FALSE(result);
}

TEST(SignInSystemTestAllSignedIn, TestAllSignedIn3) {
    SignInSystem signin_system;
    signin_system.add_user("aaa");
    signin_system.sign_in("aaa");
    bool result = signin_system.all_signed_in();
    EXPECT_TRUE(result);
}

TEST(SignInSystemTestAllSignedIn, TestAllSignedIn4) {
    SignInSystem signin_system;
    signin_system.add_user("bbb");
    signin_system.sign_in("bbb");
    bool result = signin_system.all_signed_in();
    EXPECT_TRUE(result);
}

TEST(SignInSystemTestAllSignedIn, TestAllSignedIn5) {
    SignInSystem signin_system;
    signin_system.add_user("aaa");
    signin_system.add_user("bbb");
    signin_system.sign_in("aaa");
    bool result = signin_system.all_signed_in();
    EXPECT_FALSE(result);
}

class SignInSystemTestAllNotSignedIn : public ::testing::Test {};

TEST(SignInSystemTestAllNotSignedIn, TestAllNotSignedIn1) {
    SignInSystem signin_system;
    signin_system.add_user("user1");
    signin_system.sign_in("user1");
    std::vector<std::string> result = signin_system.all_not_signed_in();
    std::vector<std::string> expected_vector = {};
    EXPECT_EQ(result, expected_vector);
}

TEST(SignInSystemTestAllNotSignedIn, TestAllNotSignedIn2) {
    SignInSystem signin_system;
    signin_system.add_user("user1");
    signin_system.add_user("user2");
    std::vector<std::string> result = signin_system.all_not_signed_in();
    std::vector<std::string> expected_vector = { "user1", "user2" };
    EXPECT_EQ(result, expected_vector);
}

TEST(SignInSystemTestAllNotSignedIn, TestAllNotSignedIn3) {
    SignInSystem signin_system;
    signin_system.add_user("aaa");
    signin_system.sign_in("aaa");
    std::vector<std::string> result = signin_system.all_not_signed_in();
    std::vector<std::string> expected_vector = {};
    EXPECT_EQ(result, expected_vector);
}

TEST(SignInSystemTestAllNotSignedIn, TestAllNotSignedIn4) {
    SignInSystem signin_system;
    signin_system.add_user("user1");
    signin_system.add_user("aaa");
    signin_system.sign_in("user1");
    std::vector<std::string> result = signin_system.all_not_signed_in();
    std::vector<std::string> expected_vector = { "aaa" };
    EXPECT_EQ(result, expected_vector);
}

TEST(SignInSystemTestAllNotSignedIn, TestAllNotSignedIn5) {
    SignInSystem signin_system;
    std::vector<std::string> result = signin_system.all_not_signed_in();
    std::vector<std::string> expected_vector = {};
    EXPECT_EQ(result, expected_vector);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}