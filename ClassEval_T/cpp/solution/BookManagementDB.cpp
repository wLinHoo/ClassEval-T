
#include <stdexcept>

#include <winsqlite/winsqlite3.h>
#include <string>
#include <vector>
#include <tuple>

class BookManagementDB {
public:
    explicit BookManagementDB(const std::string& db_name);
    ~BookManagementDB();

    void create_table();
    void add_book(const std::string& title, const std::string& author);
    void remove_book(int id);
    void borrow_book(int id);
    void return_book(int id);
    std::vector<std::tuple<int, std::string, std::string, int>> search_books();
    sqlite3* get_connection();

private:
    sqlite3* connection;
};

BookManagementDB::BookManagementDB(const std::string& db_name) {
    if (sqlite3_open(db_name.c_str(), &connection) != SQLITE_OK) {
        throw std::runtime_error("Failed to open database");
    }
}

BookManagementDB::~BookManagementDB() {
    sqlite3_close(connection);
}

void BookManagementDB::create_table() {
    const char* create_table_sql = R"(
        CREATE TABLE IF NOT EXISTS books (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            title TEXT NOT NULL,
            author TEXT NOT NULL,
            available INTEGER NOT NULL
        )
    )";
    char* error_msg = nullptr;
    if (sqlite3_exec(connection, create_table_sql, nullptr, nullptr, &error_msg) != SQLITE_OK) {
        throw std::runtime_error(error_msg);
    }
}

void BookManagementDB::add_book(const std::string& title, const std::string& author) {
    const char* insert_sql = "INSERT INTO books (title, author, available) VALUES (?, ?, 1)";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(connection, insert_sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error(sqlite3_errmsg(connection));
    }
    sqlite3_bind_text(stmt, 1, title.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, author.c_str(), -1, SQLITE_TRANSIENT);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error(sqlite3_errmsg(connection));
    }
    sqlite3_finalize(stmt);
}

void BookManagementDB::remove_book(int id) {
    const char* delete_sql = "DELETE FROM books WHERE id = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(connection, delete_sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error(sqlite3_errmsg(connection));
    }
    sqlite3_bind_int(stmt, 1, id);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error(sqlite3_errmsg(connection));
    }
    sqlite3_finalize(stmt);
}

void BookManagementDB::borrow_book(int id) {
    const char* update_sql = "UPDATE books SET available = 0 WHERE id = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(connection, update_sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error(sqlite3_errmsg(connection));
    }
    sqlite3_bind_int(stmt, 1, id);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error(sqlite3_errmsg(connection));
    }
    sqlite3_finalize(stmt);
}

void BookManagementDB::return_book(int id) {
    const char* update_sql = "UPDATE books SET available = 1 WHERE id = ?";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(connection, update_sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error(sqlite3_errmsg(connection));
    }
    sqlite3_bind_int(stmt, 1, id);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error(sqlite3_errmsg(connection));
    }
    sqlite3_finalize(stmt);
}

std::vector<std::tuple<int, std::string, std::string, int>> BookManagementDB::search_books() {
    const char* select_sql = "SELECT * FROM books";
    sqlite3_stmt* stmt;
    std::vector<std::tuple<int, std::string, std::string, int>> books;

    if (sqlite3_prepare_v2(connection, select_sql, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error(sqlite3_errmsg(connection));
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        std::string title(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        std::string author(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        int available = sqlite3_column_int(stmt, 3);
        books.emplace_back(id, title, author, available);
    }
    sqlite3_finalize(stmt);
    return books;
}

sqlite3* BookManagementDB::get_connection()
{
    return this->connection;
}
