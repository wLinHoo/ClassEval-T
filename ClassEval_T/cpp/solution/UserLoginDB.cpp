
#include <stdexcept>
#include <tuple>

#include <winsqlite/winsqlite3.h>
#include <string>
#include <memory>

class UserLoginDB {
public:
    explicit UserLoginDB(const std::string& db_name);
    ~UserLoginDB();

    void insert_user(const std::string& username, const std::string& password);
    std::unique_ptr<std::tuple<std::string, std::string>> search_user_by_username(const std::string& username);
    void delete_user_by_username(const std::string& username);
    bool validate_user_login(const std::string& username, const std::string& password);

    void close_connection();
    void create_table();

private:
    sqlite3* connection;
    sqlite3_stmt* stmt;
    void prepare_statement(const std::string& query);
    void finalize_statement();
};

UserLoginDB::UserLoginDB(const std::string& db_name) : connection(nullptr), stmt(nullptr) {
    if (sqlite3_open(db_name.c_str(), &connection) != SQLITE_OK) {
        throw std::runtime_error("Cannot open database: " + std::string(sqlite3_errmsg(connection)));
    }
    create_table(); 
}

UserLoginDB::~UserLoginDB() {
    finalize_statement();
    if (connection) {
        sqlite3_close(connection);
    }
}

void UserLoginDB::prepare_statement(const std::string& query) {
    finalize_statement();
    if (sqlite3_prepare_v2(connection, query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Failed to prepare statement: " + std::string(sqlite3_errmsg(connection)));
    }
}

void UserLoginDB::finalize_statement() {
    if (stmt) {
        sqlite3_finalize(stmt);
        stmt = nullptr;
    }
}

void UserLoginDB::insert_user(const std::string& username, const std::string& password) {
    prepare_statement("INSERT INTO users (username, password) VALUES (?, ?)");
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error("Failed to insert user: " + std::string(sqlite3_errmsg(connection)));
    }
    finalize_statement();
}

std::unique_ptr<std::tuple<std::string, std::string>> UserLoginDB::search_user_by_username(const std::string& username) {
    prepare_statement("SELECT username, password FROM users WHERE username = ?");
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    std::unique_ptr<std::tuple<std::string, std::string>> user = nullptr;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        user = std::make_unique<std::tuple<std::string, std::string>>(
            std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))),
            std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)))
        );
    }
    finalize_statement();
    return user;
}

void UserLoginDB::delete_user_by_username(const std::string& username) {
    prepare_statement("DELETE FROM users WHERE username = ?");
    sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error("Failed to delete user: " + std::string(sqlite3_errmsg(connection)));
    }
    finalize_statement();
}

bool UserLoginDB::validate_user_login(const std::string& username, const std::string& password) {
    auto user = search_user_by_username(username);
    if (user && std::get<1>(*user) == password) {
        return true;
    }
    return false;
}

void UserLoginDB::create_table() {
    const char* create_table_query = R"(
        CREATE TABLE IF NOT EXISTS users (
            username TEXT,
            password TEXT
        )
    )";
    if (sqlite3_exec(connection, create_table_query, nullptr, nullptr, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Cannot create table: " + std::string(sqlite3_errmsg(connection)));
    }
}

void UserLoginDB::close_connection() {
    if (connection) {
        sqlite3_close(connection);
        connection = nullptr;
    }
}
