#include <gtest/gtest.h>
#include "pch.h"
#include <cstdio>
#include <vector>


class BookManagementDBTestCreateTable : public ::testing::Test {
protected:
    void SetUp() override {
        db_name = "test.db";
        db = new BookManagementDB(db_name);
        db->create_table();  
        connection = db->get_connection(); 
    }

    void TearDown() override {
        delete db;
        std::remove(db_name.c_str());
    }

    std::string db_name;
    BookManagementDB* db;
    sqlite3* connection;
};


TEST_F(BookManagementDBTestCreateTable, TestCreateTable1) {
    sqlite3_stmt* stmt;
    const char* query = "SELECT name FROM sqlite_master WHERE type='table' AND name='books'";
    sqlite3_prepare_v2(connection, query, -1, &stmt, nullptr);

    int rc = sqlite3_step(stmt);
    EXPECT_EQ(rc, SQLITE_ROW) << "Table 'books' does not exist";

    sqlite3_finalize(stmt);
}


TEST_F(BookManagementDBTestCreateTable, TestCreateTable2) {
    sqlite3_stmt* stmt;
    const char* query = "PRAGMA table_info(books)";
    sqlite3_prepare_v2(connection, query, -1, &stmt, nullptr);

    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        std::vector<std::string> column_names;
        do {
            column_names.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        } while (sqlite3_step(stmt) == SQLITE_ROW);
        std::vector<std::string> expected_column_names = { "id", "title", "author", "available" };
        EXPECT_EQ(column_names, expected_column_names);
    }
    else {
        FAIL() << "Failed to retrieve table info";
    }

    sqlite3_finalize(stmt);
}

class BookManagementDBTestAddBook : public ::testing::Test {
protected:
    void SetUp() override {
        db_name = "test.db";
        db = new BookManagementDB(db_name);
        db->create_table();  
        connection = db->get_connection(); 
    }

    void TearDown() override {
        delete db;
        std::remove(db_name.c_str());
    }

    std::string db_name;
    BookManagementDB* db;
    sqlite3* connection;
};


TEST_F(BookManagementDBTestAddBook, TestAddBook) {
    std::string title = "Introduction to Python";
    std::string author = "John Smith";
    db->add_book(title, author);

    sqlite3_stmt* stmt;
    const char* query = "SELECT title, author, available FROM books WHERE id=1";
    sqlite3_prepare_v2(connection, query, -1, &stmt, nullptr);

    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        EXPECT_EQ(std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))), title);
        EXPECT_EQ(std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))), author);
        EXPECT_EQ(sqlite3_column_int(stmt, 2), 1);
    }
    else {
        FAIL() << "No row returned";
    }

    sqlite3_finalize(stmt);
}


class BookManagementDBTestRemoveBook : public ::testing::Test {
protected:
    void SetUp() override {
        db_name = "test.db";
        db = new BookManagementDB(db_name);
        db->create_table();  
        connection = db->get_connection(); 
    }

    void TearDown() override {
        delete db;
        std::remove(db_name.c_str());
    }

    std::string db_name;
    BookManagementDB* db;
    sqlite3* connection;
};


TEST_F(BookManagementDBTestRemoveBook, TestRemoveBook) {
    db->add_book("Book to Remove", "John Doe");
    db->remove_book(1);

    sqlite3_stmt* stmt;
    const char* query = "SELECT * FROM books WHERE id=1";
    sqlite3_prepare_v2(connection, query, -1, &stmt, nullptr);

    int rc = sqlite3_step(stmt);
    EXPECT_EQ(rc, SQLITE_DONE) << "Failed to remove book";

    sqlite3_finalize(stmt);
}


class BookManagementDBTestBorrowBook : public ::testing::Test {
protected:
    void SetUp() override {
        db_name = "test.db";
        db = new BookManagementDB(db_name);
        db->create_table();  
        connection = db->get_connection(); 
    }

    void TearDown() override {
        delete db;
        std::remove(db_name.c_str());
    }

    std::string db_name;
    BookManagementDB* db;
    sqlite3* connection;
};

TEST_F(BookManagementDBTestBorrowBook, TestBorrowBook) {
    db->add_book("Book to Borrow", "Jane Smith");
    db->borrow_book(1);

    sqlite3_stmt* stmt;
    const char* query = "SELECT available FROM books WHERE id=1";
    sqlite3_prepare_v2(connection, query, -1, &stmt, nullptr);

    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        EXPECT_EQ(sqlite3_column_int(stmt, 0), 0);
    }
    else {
        FAIL() << "No row returned";
    }

    sqlite3_finalize(stmt);
}



class BookManagementDBTestReturnBook : public ::testing::Test {
protected:
    void SetUp() override {
        db_name = "test.db";
        db = new BookManagementDB(db_name);
        db->create_table();  
        connection = db->get_connection(); 
    }

    void TearDown() override {
        delete db;
        std::remove(db_name.c_str());
    }

    std::string db_name;
    BookManagementDB* db;
    sqlite3* connection;
};

TEST_F(BookManagementDBTestReturnBook, TestReturnBook) {
    db->add_book("Book to Return", "James Smith");
    db->borrow_book(1);  
    db->return_book(1);

    sqlite3_stmt* stmt;
    const char* query = "SELECT available FROM books WHERE id=1";
    sqlite3_prepare_v2(connection, query, -1, &stmt, nullptr);

    int rc = sqlite3_step(stmt);
    if (rc == SQLITE_ROW) {
        EXPECT_EQ(sqlite3_column_int(stmt, 0), 1);
    }
    else {
        FAIL() << "No row returned";
    }

    sqlite3_finalize(stmt);
}


class BookManagementDBTestSearchBooks : public ::testing::Test {
protected:
    void SetUp() override {
        db_name = "test.db";
        db = new BookManagementDB(db_name);
        db->create_table();  
        connection = db->get_connection(); 
    }

    void TearDown() override {
        delete db;
        std::remove(db_name.c_str());
    }

    std::string db_name;
    BookManagementDB* db;
    sqlite3* connection;
};

TEST_F(BookManagementDBTestSearchBooks, TestSearchBooks) {
    db->add_book("Book 1", "Author 1");
    db->add_book("Book 2", "Author 2");
    db->add_book("Book 3", "Author 3");

    auto books = db->search_books();

    EXPECT_EQ(books.size(), 3);
    EXPECT_EQ(std::get<1>(books[0]), "Book 1");
    EXPECT_EQ(std::get<2>(books[1]), "Author 2");
    EXPECT_EQ(std::get<3>(books[2]), 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}