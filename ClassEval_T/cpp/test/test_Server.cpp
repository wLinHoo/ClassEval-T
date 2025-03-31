#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <string>
#include "pch.h"

class ServerTestAddWhiteList : public ::testing::Test {
};

TEST_F(ServerTestAddWhiteList, test_add_white_list_1) {
    Server server;
    server.add_white_list(88);
    ASSERT_EQ(server.white_list, std::vector<int>({ 88 }));
}

TEST_F(ServerTestAddWhiteList, test_add_white_list_2) {
    Server server;
    server.add_white_list(88);
    ASSERT_EQ(server.add_white_list(88), std::vector<int>{});
}

TEST_F(ServerTestAddWhiteList, test_add_white_list_3) {
    Server server;
    server.add_white_list(88);
    server.add_white_list(11);
    ASSERT_EQ(server.add_white_list(11), std::vector<int>{});
}

TEST_F(ServerTestAddWhiteList, test_add_white_list_4) {
    Server server;
    server.add_white_list(11);
    ASSERT_EQ(server.white_list, std::vector<int>({ 11 }));
}

TEST_F(ServerTestAddWhiteList, test_add_white_list_5) {
    Server server;
    server.add_white_list(88);
    server.add_white_list(11);
    server.add_white_list(22);
    ASSERT_EQ(server.add_white_list(22), std::vector<int>{});
}

class ServerTestDelWhiteList : public ::testing::Test {
};

TEST_F(ServerTestDelWhiteList, test_del_white_list_1) {
    Server server;
    server.add_white_list(88);
    server.del_white_list(88);
    ASSERT_EQ(server.white_list, std::vector<int>({}));
}

TEST_F(ServerTestDelWhiteList, test_del_white_list_2) {
    Server server;
    ASSERT_EQ(server.del_white_list(88), std::vector<int>{});
}

TEST_F(ServerTestDelWhiteList, test_del_white_list_3) {
    Server server;
    ASSERT_EQ(server.del_white_list(11), std::vector<int>{});
}

TEST_F(ServerTestDelWhiteList, test_del_white_list_4) {
    Server server;
    ASSERT_EQ(server.del_white_list(22), std::vector<int>{});
}

TEST_F(ServerTestDelWhiteList, test_del_white_list_5) {
    Server server;
    server.add_white_list(11);
    ASSERT_EQ(server.del_white_list(22), std::vector<int>{});
}

class ServerTestRecv : public ::testing::Test {
};

TEST_F(ServerTestRecv, test_recv_1) {
    Server server;
    server.add_white_list(88);
    server.recv({ {"addr", "88"}, {"content", "abc"} });
    std::map<std::string, std::string> now({ {"addr", "88"}, {"content", "abc"} });
    ASSERT_EQ(server.receive_struct, now);
}

TEST_F(ServerTestRecv, test_recv_2) {
    Server server;
    server.add_white_list(88);
    bool flag = server.recv({ {"addr", "66"}, {"content", "abc"} });
    std::map<std::string, std::string> now;
    ASSERT_EQ(server.receive_struct, now);
    ASSERT_FALSE(flag);
}

TEST_F(ServerTestRecv, test_recv_3) {
    Server server;
    int flag = server.recv({ {"addr", "88"} });
    std::map<std::string, std::string> now;
    ASSERT_EQ(server.receive_struct, now);
    ASSERT_EQ(flag, -1);
}

TEST_F(ServerTestRecv, test_recv_4) {
    Server server;
    int flag = server.recv({ {"addr", "88"} });
    std::map<std::string, std::string> now;
    ASSERT_EQ(server.receive_struct, now);
    ASSERT_EQ(flag, -1);
}

TEST_F(ServerTestRecv, test_recv_5) {
    Server server;
    int flag = server.recv({ {"content", "abc"} });
    std::map<std::string, std::string> now;
    ASSERT_EQ(server.receive_struct, now);
    ASSERT_EQ(flag, -1);
}

class ServerTestSend : public ::testing::Test {
};

TEST_F(ServerTestSend, test_send_1) {
    Server server;
    server.send({ {"addr", "88"}, {"content", "abc"} });
    std::map<std::string, std::string> now({ {"addr", "88"}, {"content", "abc"} });
    ASSERT_EQ(server.send_struct, now);
}

TEST_F(ServerTestSend, test_send_2) {
    Server server;
    std::string flag = server.send({ {"addr", "88"} });
    ASSERT_EQ(flag, "info structure is not correct");
}

TEST_F(ServerTestSend, test_send_3) {
    Server server;
    std::string flag = server.send({ {"content", "abc"} });
    ASSERT_EQ(flag, "info structure is not correct");
}

TEST_F(ServerTestSend, test_send_4) {
    Server server;
    std::string flag = server.send({});
    ASSERT_EQ(flag, "info structure is not correct");
}

TEST_F(ServerTestSend, test_send_5) {
    Server server;
    server.send({ {"addr", "66"}, {"content", "abc"} });
    std::map<std::string, std::string> now({ {"addr", "66"}, {"content", "abc"} });
    ASSERT_EQ(server.send_struct, now);
}

class ServerTestShow : public ::testing::Test {
};

TEST_F(ServerTestShow, test_show_1) {
    Server server;
    server.add_white_list(66);
    server.send({ {"addr", "88"}, {"content", "abc"} });
    server.recv({ {"addr", "66"}, {"content", "ABC"} });
    std::map<std::string, std::string> now({ {"addr", "88"}, {"content", "abc"} });
    ASSERT_EQ(server.show("send"), now);
}

TEST_F(ServerTestShow, test_show_2) {
    Server server;
    server.add_white_list(66);
    server.send({ {"addr", "88"}, {"content", "abc"} });
    server.recv({ {"addr", "66"}, {"content", "ABC"} });
    std::map<std::string, std::string> now({ {"addr", "66"}, {"content", "ABC"} });
    ASSERT_EQ(server.show("receive"), now);
}

TEST_F(ServerTestShow, test_show_3) {
    Server server;
    server.add_white_list(66);
    server.send({ {"addr", "88"}, {"content", "abc"} });
    server.recv({ {"addr", "66"}, {"content", "ABC"} });
    std::map<std::string, std::string> now;
    ASSERT_EQ(server.show("abcdefg"), now);
}

TEST_F(ServerTestShow, test_show_4) {
    Server server;
    server.add_white_list(66);
    server.send({ {"addr", "11"}, {"content", "abc"} });
    server.recv({ {"addr", "66"}, {"content", "ABC"} });
    std::map<std::string, std::string> now({ {"addr", "11"}, {"content", "abc"} });
    ASSERT_EQ(server.show("send"), now);
}

TEST_F(ServerTestShow, test_show_5) {
    Server server;
    server.add_white_list(66);
    server.send({ {"addr", "22"}, {"content", "abc"} });
    server.recv({ {"addr", "66"}, {"content", "ABC"} });
    std::map<std::string, std::string> now({ {"addr", "22"}, {"content", "abc"} });
    ASSERT_EQ(server.show("send"),now);
}

class ServerTest : public ::testing::Test {
};

TEST_F(ServerTest, test_server) {
    Server server;
    server.add_white_list(88);
    ASSERT_EQ(server.white_list, std::vector<int>({ 88 }));
    server.del_white_list(88);
    ASSERT_EQ(server.white_list, std::vector<int>());
    server.add_white_list(88);
    server.recv({ {"addr", "88"}, {"content", "abc"} });
    std::map<std::string, std::string> now({ {"addr", "88"}, {"content", "abc"} });
    ASSERT_EQ(server.receive_struct, now);
    server.send({ {"addr", "66"}, {"content", "ABC"} });
    std::map<std::string, std::string> kkk({ {"addr", "66"}, {"content", "ABC"} });
    ASSERT_EQ(server.send_struct, kkk);
    server.recv({ {"addr", "88"}, {"content", "abc"} });
    ASSERT_EQ(server.show("receive"), now);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}