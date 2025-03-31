#include <gtest/gtest.h>
#include <cstdio> 
#include "pch.h"

class UserLoginDBTest : public ::testing::Test {
protected:
    std::string db_path;
    UserLoginDB* db;

    void SetUp() override {
        db_path = "test_db.db";
        std::remove(db_path.c_str()); 
        db = new UserLoginDB(db_path); 
        db->create_table(); 
    }

    void TearDown() override {
        db->close_connection(); 
        delete db; 
        std::remove(db_path.c_str()); 
    }
};

TEST_F(UserLoginDBTest, UserLoginDB) {
    
    db->insert_user("user1", "pass1");

    
    auto user = db->search_user_by_username("user1");
    ASSERT_NE(user, nullptr); 
    if (user) {
        EXPECT_EQ(std::get<0>(*user), "user1"); 
        EXPECT_EQ(std::get<1>(*user), "pass1"); 
    }

    
    db->delete_user_by_username("user1");
    user = db->search_user_by_username("user1");
    EXPECT_EQ(user, nullptr); 

    
    db->insert_user("user1", "pass1");
    bool valid = db->validate_user_login("user1", "pass1");
    EXPECT_TRUE(valid); 
}

class UserLoginDBTestInsertUser : public ::testing::Test {
protected:
    std::string db_path;
    UserLoginDB* db;

    void SetUp() override {
        db_path = "test_db.db"; 
        std::remove(db_path.c_str()); 
        db = new UserLoginDB(db_path); 
        db->create_table(); 
    }

    void TearDown() override {
        db->close_connection(); 
        delete db; 
        std::remove(db_path.c_str()); 
    }
};

TEST_F(UserLoginDBTestInsertUser, test_insert_user_1) {
    db->insert_user("user1", "pass1");
    auto user = db->search_user_by_username("user1");
    ASSERT_NE(user, nullptr); 
    if (user) {
        EXPECT_EQ(std::get<0>(*user), "user1"); 
        EXPECT_EQ(std::get<1>(*user), "pass1"); 
    }
}

TEST_F(UserLoginDBTestInsertUser, test_insert_user_2) {
    db->insert_user("user2", "pass2");
    auto user = db->search_user_by_username("user2");
    ASSERT_NE(user, nullptr); 
    if (user) {
        EXPECT_EQ(std::get<0>(*user), "user2"); 
        EXPECT_EQ(std::get<1>(*user), "pass2"); 
    }
}

TEST_F(UserLoginDBTestInsertUser, test_insert_user_3) {
    db->insert_user("user3", "pass3");
    auto user = db->search_user_by_username("user3");
    ASSERT_NE(user, nullptr); 
    if (user) {
        EXPECT_EQ(std::get<0>(*user), "user3"); 
        EXPECT_EQ(std::get<1>(*user), "pass3"); 
    }
}

TEST_F(UserLoginDBTestInsertUser, test_insert_user_4) {
    db->insert_user("user4", "pass4");
    auto user = db->search_user_by_username("user4");
    ASSERT_NE(user, nullptr); 
    if (user) {
        EXPECT_EQ(std::get<0>(*user), "user4"); 
        EXPECT_EQ(std::get<1>(*user), "pass4"); 
    }
}

TEST_F(UserLoginDBTestInsertUser, test_insert_user_5) {
    db->insert_user("user5", "pass5");
    auto user = db->search_user_by_username("user5");
    ASSERT_NE(user, nullptr); 
    if (user) {
        EXPECT_EQ(std::get<0>(*user), "user5"); 
        EXPECT_EQ(std::get<1>(*user), "pass5"); 
    }
}

class UserLoginDBTestSearchUserByUsername : public ::testing::Test {
protected:
    std::string db_path;
    UserLoginDB* db;

    void SetUp() override {
        db_path = "test_db.db"; 
        std::remove(db_path.c_str()); 
        db = new UserLoginDB(db_path); 
        db->create_table(); 
    }

    void TearDown() override {
        db->close_connection(); 
        delete db; 
        std::remove(db_path.c_str()); 
    }
};

TEST_F(UserLoginDBTestSearchUserByUsername, test_search_user_by_username_1) {
    db->insert_user("user1", "pass1");
    auto user = db->search_user_by_username("user1");
    ASSERT_NE(user, nullptr); 
    if (user) {
        EXPECT_EQ(std::get<0>(*user), "user1"); 
        EXPECT_EQ(std::get<1>(*user), "pass1"); 
    }
}

TEST_F(UserLoginDBTestSearchUserByUsername, test_search_user_by_username_2) {
    db->insert_user("user2", "pass2");
    auto user = db->search_user_by_username("user2");
    ASSERT_NE(user, nullptr); 
    if (user) {
        EXPECT_EQ(std::get<0>(*user), "user2"); 
        EXPECT_EQ(std::get<1>(*user), "pass2"); 
    }
}

TEST_F(UserLoginDBTestSearchUserByUsername, test_search_user_by_username_3) {
    db->insert_user("user3", "pass3");
    auto user = db->search_user_by_username("user3");
    ASSERT_NE(user, nullptr); 
    if (user) {
        EXPECT_EQ(std::get<0>(*user), "user3"); 
        EXPECT_EQ(std::get<1>(*user), "pass3"); 
    }
}

TEST_F(UserLoginDBTestSearchUserByUsername, test_search_user_by_username_4) {
    db->insert_user("user4", "pass4");
    auto user = db->search_user_by_username("user4");
    ASSERT_NE(user, nullptr); 
    if (user) {
        EXPECT_EQ(std::get<0>(*user), "user4"); 
        EXPECT_EQ(std::get<1>(*user), "pass4"); 
    }
}

TEST_F(UserLoginDBTestSearchUserByUsername, test_search_user_by_username_5) {
    db->insert_user("user5", "pass5");
    auto user = db->search_user_by_username("user5");
    ASSERT_NE(user, nullptr); 
    if (user) {
        EXPECT_EQ(std::get<0>(*user), "user5"); 
        EXPECT_EQ(std::get<1>(*user), "pass5"); 
    }
}

class UserLoginDBTestDeleteUserByUsername : public ::testing::Test {
protected:
    std::string db_path;
    UserLoginDB* db;

    void SetUp() override {
        db_path = "test_db.db"; 
        std::remove(db_path.c_str()); 
        db = new UserLoginDB(db_path); 
        db->create_table(); 
    }

    void TearDown() override {
        db->close_connection(); 
        delete db; 
        std::remove(db_path.c_str()); 
    }
};

TEST_F(UserLoginDBTestDeleteUserByUsername, test_delete_user_by_username_1) {
    db->insert_user("user1", "pass1");
    db->delete_user_by_username("user1");
    auto user = db->search_user_by_username("user1");
    EXPECT_EQ(user, nullptr); 
}

TEST_F(UserLoginDBTestDeleteUserByUsername, test_delete_user_by_username_2) {
    db->insert_user("user2", "pass2");
    db->delete_user_by_username("user2");
    auto user = db->search_user_by_username("user2");
    EXPECT_EQ(user, nullptr); 
}

TEST_F(UserLoginDBTestDeleteUserByUsername, test_delete_user_by_username_3) {
    db->insert_user("user3", "pass3");
    db->delete_user_by_username("user3");
    auto user = db->search_user_by_username("user3");
    EXPECT_EQ(user, nullptr); 
}

TEST_F(UserLoginDBTestDeleteUserByUsername, test_delete_user_by_username_4) {
    db->insert_user("user4", "pass4");
    db->delete_user_by_username("user4");
    auto user = db->search_user_by_username("user4");
    EXPECT_EQ(user, nullptr); 
}

TEST_F(UserLoginDBTestDeleteUserByUsername, test_delete_user_by_username_5) {
    db->insert_user("user5", "pass5");
    db->delete_user_by_username("user5");
    auto user = db->search_user_by_username("user5");
    EXPECT_EQ(user, nullptr); 
}

class UserLoginDBTestValidateUserLogin : public ::testing::Test {
protected:
    std::string db_path;
    UserLoginDB* db;

    void SetUp() override {
        db_path = "test_db.db"; 
        std::remove(db_path.c_str()); 
        db = new UserLoginDB(db_path); 
        db->create_table(); 
    }

    void TearDown() override {
        db->close_connection(); 
        delete db; 
        std::remove(db_path.c_str()); 
    }
};

TEST_F(UserLoginDBTestValidateUserLogin, test_validate_user_login_1) {
    db->insert_user("user1", "pass1");
    bool valid = db->validate_user_login("user1", "pass1");
    EXPECT_TRUE(valid); 
}

TEST_F(UserLoginDBTestValidateUserLogin, test_validate_user_login_2) {
    db->insert_user("user1", "pass1");
    bool invalid = db->validate_user_login("user1", "wrongpass");
    EXPECT_FALSE(invalid); 
}

TEST_F(UserLoginDBTestValidateUserLogin, test_validate_user_login_3) {
    bool invalid = db->validate_user_login("nonexistentuser", "somepass");
    EXPECT_FALSE(invalid); 
}

TEST_F(UserLoginDBTestValidateUserLogin, test_validate_user_login_4) {
    db->insert_user("user2", "pass2");
    bool valid = db->validate_user_login("user2", "pass2");
    EXPECT_TRUE(valid); 
}

TEST_F(UserLoginDBTestValidateUserLogin, test_validate_user_login_5) {
    db->insert_user("user3", "pass3");
    bool valid = db->validate_user_login("user3", "pass3");
    EXPECT_TRUE(valid); 
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
