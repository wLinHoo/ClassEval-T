#include "pch.h"
#include <gtest/gtest.h>

class ChatTestAddUser : public ::testing::Test {
protected:
    Chat chat;
};

TEST_F(ChatTestAddUser, TestAddUser) {
    EXPECT_TRUE(chat.add_user("John"));
    EXPECT_EQ(chat.get_users().size(), 1);
    EXPECT_EQ(chat.get_users()["John"].size(), 0);
}

TEST_F(ChatTestAddUser, TestAddUser2) {
    chat.add_user("John");
    EXPECT_FALSE(chat.add_user("John"));
    EXPECT_EQ(chat.get_users().size(), 1);
    EXPECT_EQ(chat.get_users()["John"].size(), 0);
}

TEST_F(ChatTestAddUser, TestAddUser3) {
    chat.add_user("John");
    EXPECT_TRUE(chat.add_user("Mary"));
    EXPECT_EQ(chat.get_users().size(), 2);
    EXPECT_EQ(chat.get_users()["Mary"].size(), 0);
}

TEST_F(ChatTestAddUser, TestAddUser4) {
    chat.add_user("John");
    EXPECT_TRUE(chat.add_user("Mary"));
    EXPECT_EQ(chat.get_users().size(), 2);
    EXPECT_EQ(chat.get_users()["Mary"].size(), 0);
}

TEST_F(ChatTestAddUser, TestAddUser5) {
    EXPECT_TRUE(chat.add_user("John"));
    EXPECT_TRUE(chat.add_user("Mary"));
    EXPECT_EQ(chat.get_users().size(), 2);
    EXPECT_EQ(chat.get_users()["John"].size(), 0);
    EXPECT_EQ(chat.get_users()["Mary"].size(), 0);
}

class ChatTestRemoveUser : public ::testing::Test {
protected:
    Chat chat;
};

TEST_F(ChatTestRemoveUser, TestRemoveUser) {
    chat.add_user("John");
    EXPECT_TRUE(chat.remove_user("John"));
    EXPECT_EQ(chat.get_users().size(), 0);
}

TEST_F(ChatTestRemoveUser, TestRemoveUser2) {
    EXPECT_FALSE(chat.remove_user("John"));
    EXPECT_EQ(chat.get_users().size(), 0);
}

TEST_F(ChatTestRemoveUser, TestRemoveUser3) {
    chat.add_user("John");
    chat.add_user("Mary");
    EXPECT_TRUE(chat.remove_user("John"));
    auto users = chat.get_users();
    EXPECT_EQ(users.size(), 1);
    EXPECT_EQ(users.find("John"),users.end());
}

TEST_F(ChatTestRemoveUser, TestRemoveUser4) {
    chat.add_user("John");
    chat.add_user("Mary");
    EXPECT_TRUE(chat.remove_user("Mary"));
    EXPECT_TRUE(chat.remove_user("John"));
    EXPECT_EQ(chat.get_users().size(), 0);
}

TEST_F(ChatTestRemoveUser, TestRemoveUser5) {
    chat.add_user("John");
    chat.add_user("Mary");
    EXPECT_FALSE(chat.remove_user("Amy"));
    EXPECT_EQ(chat.get_users().size(), 2);
    EXPECT_EQ(chat.get_users()["John"].size(), 0);
    EXPECT_EQ(chat.get_users()["Mary"].size(), 0);
}

class ChatTestSendMessage : public ::testing::Test {
protected:
    Chat chat;
};

TEST_F(ChatTestSendMessage, TestSendMessage) {
    chat.add_user("John");
    chat.add_user("Mary");
    std::string timestamp = chat.get_current_time(); 
    EXPECT_TRUE(chat.send_message("John", "Mary", "Hello"));
    auto messages = chat.get_messages("John");
    EXPECT_EQ(messages.size(), 1);
    EXPECT_EQ(messages[0].sender, "John");
    EXPECT_EQ(messages[0].receiver, "Mary");
    EXPECT_EQ(messages[0].message, "Hello");
    EXPECT_EQ(messages[0].timestamp, timestamp);
}

TEST_F(ChatTestSendMessage, TestSendMessage2) {
    chat.add_user("John");
    chat.add_user("Mary");
    EXPECT_FALSE(chat.send_message("John", "Tom", "Hello"));
    EXPECT_EQ(chat.get_messages("John").size(), 0);
}

TEST_F(ChatTestSendMessage, TestSendMessage3) {
    chat.add_user("John");
    chat.add_user("Mary");
    EXPECT_FALSE(chat.send_message("Amy", "Mary", "Hello"));
    EXPECT_EQ(chat.get_messages("John").size(), 0);
}

TEST_F(ChatTestSendMessage, TestSendMessage4) {
    chat.add_user("John");
    chat.add_user("Mary");
    EXPECT_FALSE(chat.send_message("Amy", "Tom", "Hello"));
    EXPECT_EQ(chat.get_messages("John").size(), 0);
}

TEST_F(ChatTestSendMessage, TestSendMessage5) {
    chat.add_user("John");
    chat.add_user("Mary");
    EXPECT_FALSE(chat.send_message("Amy", "Amy", "Hello"));
    EXPECT_EQ(chat.get_messages("John").size(), 0);
    EXPECT_EQ(chat.get_messages("Mary").size(), 0);
}

class ChatTestGetMessages : public ::testing::Test {
protected:
    Chat chat;
};

TEST_F(ChatTestGetMessages, TestGetMessages) {
    std::string timestamp = chat.get_current_time(); 
    chat.add_user("John");
    chat.add_user("Mary");
    chat.send_message("John", "Mary", "Hello");
    auto messages = chat.get_messages("John");
    EXPECT_EQ(messages.size(), 1);
    EXPECT_EQ(messages[0].sender, "John");
    EXPECT_EQ(messages[0].receiver, "Mary");
    EXPECT_EQ(messages[0].message, "Hello");
    EXPECT_EQ(messages[0].timestamp, timestamp);
}

TEST_F(ChatTestGetMessages, TestGetMessages2) {
    chat.add_user("John");
    chat.add_user("Mary");
    EXPECT_EQ(chat.get_messages("John").size(), 0);
}

TEST_F(ChatTestGetMessages, TestGetMessages3) {
    chat.add_user("John");
    chat.add_user("Mary");
    EXPECT_EQ(chat.get_messages("Amy").size(), 0);
}

TEST_F(ChatTestGetMessages, TestGetMessages4) {
    std::string timestamp = chat.get_current_time(); 
    chat.add_user("John");
    chat.send_message("John", "Mary", "Hello");
    EXPECT_EQ(chat.get_messages("Mary").size(), 0);
}

TEST_F(ChatTestGetMessages, TestGetMessages5) {
    std::string timestamp = chat.get_current_time(); 
    chat.add_user("John");
    chat.send_message("John", "Mary", "Hello");
    EXPECT_EQ(chat.get_messages("Amy").size(), 0);
}

class ChatTestMain : public ::testing::Test {
protected:
    Chat chat;
};

TEST_F(ChatTestMain, TestMain) {
    std::string timestamp = chat.get_current_time(); 
    EXPECT_TRUE(chat.add_user("John"));
    EXPECT_TRUE(chat.add_user("Mary"));
    EXPECT_TRUE(chat.add_user("Amy"));
    EXPECT_EQ(chat.get_users().size(), 3);
    EXPECT_TRUE(chat.remove_user("Amy"));
    EXPECT_EQ(chat.get_users().size(), 2);
    EXPECT_TRUE(chat.send_message("John", "Mary", "Hello"));
    EXPECT_FALSE(chat.send_message("John", "Tom", "Hello"));
    auto john_messages = chat.get_messages("John");
    auto mary_messages = chat.get_messages("Mary");
    EXPECT_EQ(john_messages.size(), 1);
    EXPECT_EQ(mary_messages.size(), 1);
    EXPECT_EQ(john_messages[0].sender, "John");
    EXPECT_EQ(john_messages[0].receiver, "Mary");
    EXPECT_EQ(john_messages[0].message, "Hello");
    EXPECT_EQ(john_messages[0].timestamp, timestamp);
    EXPECT_EQ(mary_messages[0].sender, "John");
    EXPECT_EQ(mary_messages[0].receiver, "Mary");
    EXPECT_EQ(mary_messages[0].message, "Hello");
    EXPECT_EQ(mary_messages[0].timestamp, timestamp);
}

TEST_F(ChatTestMain, TestMain2) {
    std::string timestamp = chat.get_current_time(); 
    EXPECT_FALSE(chat.remove_user("Amy"));
    EXPECT_TRUE(chat.add_user("John"));
    EXPECT_TRUE(chat.add_user("Mary"));
    EXPECT_TRUE(chat.add_user("Amy"));
    EXPECT_EQ(chat.get_users().size(), 3);
    EXPECT_TRUE(chat.send_message("John", "Mary", "Hello"));
    EXPECT_FALSE(chat.send_message("John", "Tom", "Hello"));
    EXPECT_TRUE(chat.remove_user("Amy"));
    EXPECT_EQ(chat.get_users().size(), 2);
    auto john_messages = chat.get_messages("John");
    auto mary_messages = chat.get_messages("Mary");
    EXPECT_EQ(john_messages.size(), 1);
    EXPECT_EQ(mary_messages.size(), 1);
    EXPECT_EQ(john_messages[0].sender, "John");
    EXPECT_EQ(john_messages[0].receiver, "Mary");
    EXPECT_EQ(john_messages[0].message, "Hello");
    EXPECT_EQ(john_messages[0].timestamp, timestamp);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}