#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <fstream>
#include "pch.h" 

class MovieTicketDBTest : public ::testing::Test {
protected:
    void SetUp() override {
        db_name = "test_database.db";
        db = std::make_unique<MovieTicketDB>(db_name);
    }

    void TearDown() override {
        db->close_connection();
        std::remove(db_name.c_str());
    }

    std::string db_name;
    std::unique_ptr<MovieTicketDB> db;
};

TEST_F(MovieTicketDBTest, TestMovieTicketDB) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "John Doe");

    std::vector<std::vector<std::string>> tickets = db->search_tickets_by_customer("John Doe");
    ASSERT_EQ(tickets.size(), 1);

    std::vector<std::string> ticket = tickets[0];
    ASSERT_EQ(ticket[1], "Avengers: Endgame");
    ASSERT_EQ(ticket[2], "Cinema 1");
    ASSERT_EQ(ticket[3], "A1");
    ASSERT_EQ(ticket[4], "John Doe");

    std::string ticket_id = tickets[0][0];
    db->delete_ticket(ticket_id);

    tickets = db->search_tickets_by_customer("John Doe");
    ASSERT_EQ(tickets.size(), 0);
}

class MovieTicketDBTestInsertTicket : public ::testing::Test {
protected:
    void SetUp() override {
        db_name = "test_database.db";
        db = std::make_unique<MovieTicketDB>(db_name);
    }

    void TearDown() override {
        db->close_connection();
        std::remove(db_name.c_str());
    }

    std::string db_name;
    std::unique_ptr<MovieTicketDB> db;
};

TEST_F(MovieTicketDBTestInsertTicket, TestInsertTicket1) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "John Doe");
    auto tickets = db->search_tickets_by_customer("John Doe");
    ASSERT_EQ(tickets.size(), 1);
    auto& ticket = tickets[0];
    ASSERT_EQ(ticket[1], "Avengers: Endgame");
    ASSERT_EQ(ticket[2], "Cinema 1");
    ASSERT_EQ(ticket[3], "A1");
    ASSERT_EQ(ticket[4], "John Doe");
}

TEST_F(MovieTicketDBTestInsertTicket, TestInsertTicket2) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "aaa");
    auto tickets = db->search_tickets_by_customer("aaa");
    ASSERT_EQ(tickets.size(), 1);
    auto& ticket = tickets[0];
    ASSERT_EQ(ticket[1], "Avengers: Endgame");
    ASSERT_EQ(ticket[2], "Cinema 1");
    ASSERT_EQ(ticket[3], "A1");
    ASSERT_EQ(ticket[4], "aaa");
}

TEST_F(MovieTicketDBTestInsertTicket, TestInsertTicket3) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "bbb");
    auto tickets = db->search_tickets_by_customer("bbb");
    ASSERT_EQ(tickets.size(), 1);
    auto& ticket = tickets[0];
    ASSERT_EQ(ticket[1], "Avengers: Endgame");
    ASSERT_EQ(ticket[2], "Cinema 1");
    ASSERT_EQ(ticket[3], "A1");
    ASSERT_EQ(ticket[4], "bbb");
}

TEST_F(MovieTicketDBTestInsertTicket, TestInsertTicket4) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "ccc");
    auto tickets = db->search_tickets_by_customer("ccc");
    ASSERT_EQ(tickets.size(), 1);
    auto& ticket = tickets[0];
    ASSERT_EQ(ticket[1], "Avengers: Endgame");
    ASSERT_EQ(ticket[2], "Cinema 1");
    ASSERT_EQ(ticket[3], "A1");
    ASSERT_EQ(ticket[4], "ccc");
}

TEST_F(MovieTicketDBTestInsertTicket, TestInsertTicket5) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "ddd");
    auto tickets = db->search_tickets_by_customer("ddd");
    ASSERT_EQ(tickets.size(), 1);
    auto& ticket = tickets[0];
    ASSERT_EQ(ticket[1], "Avengers: Endgame");
    ASSERT_EQ(ticket[2], "Cinema 1");
    ASSERT_EQ(ticket[3], "A1");
    ASSERT_EQ(ticket[4], "ddd");
}

class MovieTicketDBTestSearchTicketsByCustomer : public ::testing::Test {
protected:
    void SetUp() override {
        db_name = "test_database.db";
        db = std::make_unique<MovieTicketDB>(db_name);
    }

    void TearDown() override {
        db->close_connection();
        std::remove(db_name.c_str());
    }

    std::string db_name;
    std::unique_ptr<MovieTicketDB> db;
};

TEST_F(MovieTicketDBTestSearchTicketsByCustomer, TestSearchTicketsByCustomer1) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "John Doe");
    auto tickets = db->search_tickets_by_customer("John Doe");
    ASSERT_EQ(tickets.size(), 1);
    auto& ticket = tickets[0];
    ASSERT_EQ(ticket[1], "Avengers: Endgame");
    ASSERT_EQ(ticket[2], "Cinema 1");
    ASSERT_EQ(ticket[3], "A1");
    ASSERT_EQ(ticket[4], "John Doe");
}

TEST_F(MovieTicketDBTestSearchTicketsByCustomer, TestSearchTicketsByCustomer2) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "aaa");
    auto tickets = db->search_tickets_by_customer("aaa");
    ASSERT_EQ(tickets.size(), 1);
    auto& ticket = tickets[0];
    ASSERT_EQ(ticket[1], "Avengers: Endgame");
    ASSERT_EQ(ticket[2], "Cinema 1");
    ASSERT_EQ(ticket[3], "A1");
    ASSERT_EQ(ticket[4], "aaa");
}

TEST_F(MovieTicketDBTestSearchTicketsByCustomer, TestSearchTicketsByCustomer3) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "bbb");
    auto tickets = db->search_tickets_by_customer("bbb");
    ASSERT_EQ(tickets.size(), 1);
    auto& ticket = tickets[0];
    ASSERT_EQ(ticket[1], "Avengers: Endgame");
    ASSERT_EQ(ticket[2], "Cinema 1");
    ASSERT_EQ(ticket[3], "A1");
    ASSERT_EQ(ticket[4], "bbb");
}

TEST_F(MovieTicketDBTestSearchTicketsByCustomer, TestSearchTicketsByCustomer4) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "ccc");
    auto tickets = db->search_tickets_by_customer("ccc");
    ASSERT_EQ(tickets.size(), 1);
    auto& ticket = tickets[0];
    ASSERT_EQ(ticket[1], "Avengers: Endgame");
    ASSERT_EQ(ticket[2], "Cinema 1");
    ASSERT_EQ(ticket[3], "A1");
    ASSERT_EQ(ticket[4], "ccc");
}

TEST_F(MovieTicketDBTestSearchTicketsByCustomer, TestSearchTicketsByCustomer5) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "ddd");
    auto tickets = db->search_tickets_by_customer("ddd");
    ASSERT_EQ(tickets.size(), 1);
    auto& ticket = tickets[0];
    ASSERT_EQ(ticket[1], "Avengers: Endgame");
    ASSERT_EQ(ticket[2], "Cinema 1");
    ASSERT_EQ(ticket[3], "A1");
    ASSERT_EQ(ticket[4], "ddd");
}

class MovieTicketDBTestDeleteTicket : public ::testing::Test {
protected:
    void SetUp() override {
        db_name = "test_database.db";
        db = std::make_unique<MovieTicketDB>(db_name);
    }

    void TearDown() override {
        db->close_connection();
        std::remove(db_name.c_str());
    }

    std::string db_name;
    std::unique_ptr<MovieTicketDB> db;
};

TEST_F(MovieTicketDBTestDeleteTicket, TestDeleteTicket1) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "John Doe");
    auto tickets = db->search_tickets_by_customer("John Doe");
    ASSERT_EQ(tickets.size(), 1);
    std::string ticket_id = tickets[0][0];
    db->delete_ticket(ticket_id);
    tickets = db->search_tickets_by_customer("John Doe");
    ASSERT_EQ(tickets.size(), 0);
}

TEST_F(MovieTicketDBTestDeleteTicket, TestDeleteTicket2) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "aaa");
    auto tickets = db->search_tickets_by_customer("aaa");
    ASSERT_EQ(tickets.size(), 1);
    std::string ticket_id = tickets[0][0];
    db->delete_ticket(ticket_id);
    tickets = db->search_tickets_by_customer("aaa");
    ASSERT_EQ(tickets.size(), 0);
}

TEST_F(MovieTicketDBTestDeleteTicket, TestDeleteTicket3) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "bbb");
    auto tickets = db->search_tickets_by_customer("bbb");
    ASSERT_EQ(tickets.size(), 1);
    std::string ticket_id = tickets[0][0];
    db->delete_ticket(ticket_id);
    tickets = db->search_tickets_by_customer("bbb");
    ASSERT_EQ(tickets.size(), 0);
}

TEST_F(MovieTicketDBTestDeleteTicket, TestDeleteTicket4) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "ccc");
    auto tickets = db->search_tickets_by_customer("ccc");
    ASSERT_EQ(tickets.size(), 1);
    std::string ticket_id = tickets[0][0];
    db->delete_ticket(ticket_id);
    tickets = db->search_tickets_by_customer("ccc");
    ASSERT_EQ(tickets.size(), 0);
}

TEST_F(MovieTicketDBTestDeleteTicket, TestDeleteTicket5) {
    db->insert_ticket("Avengers: Endgame", "Cinema 1", "A1", "ddd");
    auto tickets = db->search_tickets_by_customer("ddd");
    ASSERT_EQ(tickets.size(), 1);
    std::string ticket_id = tickets[0][0];
    db->delete_ticket(ticket_id);
    tickets = db->search_tickets_by_customer("ddd");
    ASSERT_EQ(tickets.size(), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}