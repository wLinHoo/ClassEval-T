#include <gtest/gtest.h>
#include "pch.h"
#include <chrono>
#include <iomanip>
#include <sstream>
#include <ctime>


std::string get_current_time() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    std::ostringstream oss;
    oss << 1900 + ltm->tm_year << "-"
        << 1 + ltm->tm_mon << "-"
        << ltm->tm_mday << " "
        << ltm->tm_hour << ":"
        << ltm->tm_min << ":"
        << ltm->tm_sec;
    return oss.str();
}

class EmailClientTestSendTo : public ::testing::Test {
protected:
    void SetUp() override {
        
    }

    void TearDown() override {
        
    }
};

TEST_F(EmailClientTestSendTo, test_send_to) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    std::string timestamp = get_current_time();
    EXPECT_TRUE(sender.send_to(receiver, "Hello", 10));

    EXPECT_EQ(receiver.inbox[0]["sender"], "sender@example.com");
    EXPECT_EQ(receiver.inbox[0]["receiver"], "receiver@example.com");
    EXPECT_EQ(receiver.inbox[0]["content"], "Hello");
    EXPECT_EQ(receiver.inbox[0]["size"], "10");
    EXPECT_EQ(receiver.inbox[0]["time"], timestamp);
    EXPECT_EQ(receiver.inbox[0]["state"], "unread");
}

TEST_F(EmailClientTestSendTo, test_send_to_2) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 0);
    EXPECT_FALSE(sender.send_to(receiver, "Hello", 10));
}

TEST_F(EmailClientTestSendTo, test_send_to_3) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    receiver.inbox = { { {"sender", "sender@example.com"},
                        {"receiver", "receiver@example.com"},
                        {"content", "Hello"},
                        {"size", "50"},
                        {"time", "2021-01-01 00:00:00"},
                        {"state", "unread"} } };
    std::string timestamp = get_current_time();
    EXPECT_FALSE(sender.send_to(receiver, "Hello", 10));

    EXPECT_EQ(receiver.inbox.size(), 1);
    EXPECT_EQ(receiver.inbox[0]["sender"], "sender@example.com");
    EXPECT_EQ(receiver.inbox[0]["receiver"], "receiver@example.com");
    EXPECT_EQ(receiver.inbox[0]["content"], "Hello");
    EXPECT_EQ(receiver.inbox[0]["size"], "50");
    EXPECT_EQ(receiver.inbox[0]["time"], "2021-01-01 00:00:00");
    EXPECT_EQ(receiver.inbox[0]["state"], "unread");
}

TEST_F(EmailClientTestSendTo, test_send_to_4) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 30);
    std::string timestamp = get_current_time();
    EXPECT_TRUE(sender.send_to(receiver, "Hello", 20));

    EXPECT_EQ(receiver.inbox.size(), 1);
    EXPECT_EQ(receiver.inbox[0]["sender"], "sender@example.com");
    EXPECT_EQ(receiver.inbox[0]["receiver"], "receiver@example.com");
    EXPECT_EQ(receiver.inbox[0]["content"], "Hello");
    EXPECT_EQ(receiver.inbox[0]["size"], "20");
    EXPECT_EQ(receiver.inbox[0]["time"], timestamp);
    EXPECT_EQ(receiver.inbox[0]["state"], "unread");
}

TEST_F(EmailClientTestSendTo, test_send_to_5) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 30);
    std::string timestamp = get_current_time();
    EXPECT_TRUE(sender.send_to(receiver, "bye", 20));

    EXPECT_EQ(receiver.inbox.size(), 1);
    EXPECT_EQ(receiver.inbox[0]["sender"], "sender@example.com");
    EXPECT_EQ(receiver.inbox[0]["receiver"], "receiver@example.com");
    EXPECT_EQ(receiver.inbox[0]["content"], "bye");
    EXPECT_EQ(receiver.inbox[0]["size"], "20");
    EXPECT_EQ(receiver.inbox[0]["time"], timestamp);
    EXPECT_EQ(receiver.inbox[0]["state"], "unread");
}

class EmailClientTestFetch : public ::testing::Test {
protected:
    void SetUp() override {
        
    }

    void TearDown() override {
        
    }
};

TEST_F(EmailClientTestFetch, test_fetch) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    std::string timestamp = get_current_time();
    receiver.inbox = { { {"sender", "sender@example.com"},
                         {"receiver", "receiver@example.com"},
                         {"content", "Hello"},
                         {"size", "10"},
                         {"time", timestamp},
                         {"state", "unread"} } };

    auto email = receiver.fetch();
    EXPECT_EQ(email["sender"], "sender@example.com");
    EXPECT_EQ(email["receiver"], "receiver@example.com");
    EXPECT_EQ(email["content"], "Hello");
    EXPECT_EQ(email["size"], "10");
    EXPECT_EQ(email["time"], timestamp);
    EXPECT_EQ(email["state"], "read");
}

TEST_F(EmailClientTestFetch, test_fetch_2) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    auto email = receiver.fetch();
    EXPECT_TRUE(email.empty());
}

TEST_F(EmailClientTestFetch, test_fetch_3) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    std::string timestamp = get_current_time();
    receiver.inbox = { { {"sender", "sender@example.com"},
                         {"receiver", "receiver@example.com"},
                         {"content", "Hello"},
                         {"size", "10"},
                         {"time", timestamp},
                         {"state", "read"} } };

    auto email = receiver.fetch();
    EXPECT_TRUE(email.empty());
}

TEST_F(EmailClientTestFetch, test_fetch_4) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    std::string timestamp = get_current_time();
    receiver.inbox = { { {"sender", "sender@example.com"},
                         {"receiver", "receiver@example.com"},
                         {"content", "Hello"},
                         {"size", "10"},
                         {"time", "2021-01-01 00:00:00"},
                         {"state", "unread"} },
                       { {"sender", "sender@example.com"},
                         {"receiver", "receiver@example.com"},
                         {"content", "Hello"},
                         {"size", "10"},
                         {"time", timestamp},
                         {"state", "unread"} } };

    auto email = receiver.fetch();
    EXPECT_EQ(email["sender"], "sender@example.com");
    EXPECT_EQ(email["receiver"], "receiver@example.com");
    EXPECT_EQ(email["content"], "Hello");
    EXPECT_EQ(email["size"], "10");
    EXPECT_EQ(email["time"], "2021-01-01 00:00:00");
    EXPECT_EQ(email["state"], "read");
}

TEST_F(EmailClientTestFetch, test_fetch_5) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    std::string timestamp = get_current_time();
    receiver.inbox = { { {"sender", "sender@example.com"},
                         {"receiver", "receiver@example.com"},
                         {"content", "Hello"},
                         {"size", "10"},
                         {"time", "2021-01-01 00:00:00"},
                         {"state", "read"} },
                       { {"sender", "sender@example.com"},
                         {"receiver", "receiver@example.com"},
                         {"content", "Hello"},
                         {"size", "10"},
                         {"time", timestamp},
                         {"state", "unread"} } };

    auto email = receiver.fetch();
    EXPECT_EQ(email["sender"], "sender@example.com");
    EXPECT_EQ(email["receiver"], "receiver@example.com");
    EXPECT_EQ(email["content"], "Hello");
    EXPECT_EQ(email["size"], "10");
    EXPECT_EQ(email["time"], timestamp);
    EXPECT_EQ(email["state"], "read");
}

class EmailClientTestIsFullWithOneMoreEmail : public ::testing::Test {
protected:
    void SetUp() override {
        
    }

    void TearDown() override {
        
    }
};

TEST_F(EmailClientTestIsFullWithOneMoreEmail, test_is_full_with_one_more_email) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    EXPECT_FALSE(receiver.is_full_with_one_more_email(10));
}

TEST_F(EmailClientTestIsFullWithOneMoreEmail, test_is_full_with_one_more_email_2) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 0);
    EXPECT_TRUE(receiver.is_full_with_one_more_email(10));
}

TEST_F(EmailClientTestIsFullWithOneMoreEmail, test_is_full_with_one_more_email_3) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 10);
    EXPECT_FALSE(receiver.is_full_with_one_more_email(10));
}

TEST_F(EmailClientTestIsFullWithOneMoreEmail, test_is_full_with_one_more_email_4) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 10);
    EXPECT_TRUE(receiver.is_full_with_one_more_email(20));
}

TEST_F(EmailClientTestIsFullWithOneMoreEmail, test_is_full_with_one_more_email_5) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 20);
    EXPECT_FALSE(receiver.is_full_with_one_more_email(20));
}

class EmailClientTestGetOccupiedSize : public ::testing::Test {
protected:
    void SetUp() override {
        
    }

    void TearDown() override {
        
    }
};

TEST_F(EmailClientTestGetOccupiedSize, test_get_occupied_size) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    sender.inbox.push_back({
        {"sender", "sender@example.com"},
        {"receiver", "receiver@example.com"},
        {"content", "Hello"},
        {"size", "10"},
        {"time", get_current_time()},
        {"state", "unread"}
        });
    EXPECT_EQ(sender.get_occupied_size(), 10);
}

TEST_F(EmailClientTestGetOccupiedSize, test_get_occupied_size_2) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    sender.inbox.clear();
    EXPECT_EQ(sender.get_occupied_size(), 0);
}

TEST_F(EmailClientTestGetOccupiedSize, test_get_occupied_size_3) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    sender.inbox.push_back({
        {"sender", "sender@example.com"},
        {"receiver", "receiver@example.com"},
        {"content", "Hello"},
        {"size", "20"},
        {"time", get_current_time()},
        {"state", "unread"}
        });
    EXPECT_EQ(sender.get_occupied_size(), 20);
}

TEST_F(EmailClientTestGetOccupiedSize, test_get_occupied_size_4) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    sender.inbox.push_back({
        {"sender", "sender@example.com"},
        {"receiver", "receiver@example.com"},
        {"content", "Hello"},
        {"size", "20"},
        {"time", get_current_time()},
        {"state", "unread"}
        });
    sender.inbox.push_back({
        {"sender", "sender@example.com"},
        {"receiver", "receiver@example.com"},
        {"content", "Hello"},
        {"size", "30"},
        {"time", get_current_time()},
        {"state", "unread"}
        });
    EXPECT_EQ(sender.get_occupied_size(), 50);
}

TEST_F(EmailClientTestGetOccupiedSize, test_get_occupied_size_5) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    sender.inbox.push_back({
        {"sender", "sender@example.com"},
        {"receiver", "receiver@example.com"},
        {"content", "Hello"},
        {"size", "20"},
        {"time", get_current_time()},
        {"state", "unread"}
        });
    sender.inbox.push_back({
        {"sender", "sender@example.com"},
        {"receiver", "receiver@example.com"},
        {"content", "Hello"},
        {"size", "60"},
        {"time", get_current_time()},
        {"state", "unread"}
        });
    EXPECT_EQ(sender.get_occupied_size(), 80);
}

class EmailClientTestClearInbox : public ::testing::Test {
protected:
    void SetUp() override {
        
    }

    void TearDown() override {
        
    }
};

TEST_F(EmailClientTestClearInbox, test_clear_inbox) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    receiver.inbox = {
        {{"size", "10"}},
        {{"size", "20"}},
        {{"size", "15"}}
    };
    receiver.clear_inbox(30);
    EXPECT_EQ(receiver.inbox.size(), 1);
    EXPECT_EQ(receiver.inbox[0]["size"], "15");
}

TEST_F(EmailClientTestClearInbox, test_clear_inbox_2) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("", 50);
    receiver.inbox = {
        {{"size", "10"}},
        {{"size", "20"}},
        {{"size", "15"}}
    };
    receiver.clear_inbox(30);
    EXPECT_EQ(receiver.inbox.size(), 3);
    EXPECT_EQ(receiver.inbox[0]["size"], "10");
    EXPECT_EQ(receiver.inbox[1]["size"], "20");
    EXPECT_EQ(receiver.inbox[2]["size"], "15");
}

TEST_F(EmailClientTestClearInbox, test_clear_inbox_3) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    receiver.inbox = {
        {{"size", "10"}},
        {{"size", "20"}},
        {{"size", "15"}}
    };
    receiver.clear_inbox(50);
    EXPECT_EQ(receiver.inbox.size(), 0);
}

TEST_F(EmailClientTestClearInbox, test_clear_inbox_4) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    receiver.inbox = {
        {{"size", "10"}},
        {{"size", "20"}},
        {{"size", "15"}}
    };
    receiver.clear_inbox(45);
    EXPECT_EQ(receiver.inbox.size(), 0);
}

TEST_F(EmailClientTestClearInbox, test_clear_inbox_5) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    receiver.inbox = {
        {{"size", "10"}},
        {{"size", "20"}},
        {{"size", "15"}}
    };
    receiver.clear_inbox(10);
    EXPECT_EQ(receiver.inbox.size(), 2);
    EXPECT_EQ(receiver.inbox[0]["size"], "20");
    EXPECT_EQ(receiver.inbox[1]["size"], "15");
}
class EmailClientTestMain : public ::testing::Test {
protected:
    void SetUp() override {
        
    }

    void TearDown() override {
        
    }
};

TEST_F(EmailClientTestMain, test_main) {
    EmailClient sender("sender@example.com", 100);
    EmailClient receiver("receiver@example.com", 50);
    std::string timestamp = get_current_time();

    
    EXPECT_TRUE(sender.send_to(receiver, "Hello", 10));
    EXPECT_EQ(receiver.inbox.size(), 1);
    EXPECT_EQ(receiver.inbox[0]["sender"], "sender@example.com");
    EXPECT_EQ(receiver.inbox[0]["receiver"], "receiver@example.com");
    EXPECT_EQ(receiver.inbox[0]["content"], "Hello");
    EXPECT_EQ(receiver.inbox[0]["size"], "10");
    EXPECT_EQ(receiver.inbox[0]["time"], timestamp);
    EXPECT_EQ(receiver.inbox[0]["state"], "unread");

    
    auto now = receiver.fetch();
    EXPECT_EQ(now["sender"], "sender@example.com");
    EXPECT_EQ(now["receiver"], "receiver@example.com");
    EXPECT_EQ(now["content"], "Hello");
    EXPECT_EQ(now["size"], "10");
    EXPECT_EQ(now["time"], timestamp);
    EXPECT_EQ(now["state"], "read");

    
    EXPECT_FALSE(receiver.is_full_with_one_more_email(10));

    
    EXPECT_EQ(receiver.get_occupied_size(), 10);

    
    receiver.inbox = {
        {{"size", "10"}},
        {{"size", "20"}},
        {{"size", "15"}}
    };
    receiver.clear_inbox(30);
    EXPECT_EQ(receiver.inbox.size(), 1);
    EXPECT_EQ(receiver.inbox[0]["size"], "15");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}