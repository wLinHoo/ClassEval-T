
#include <iostream>
#include <stdexcept>

#include <winsqlite/winsqlite3.h>
#include <string>
#include <vector>

class MovieTicketDB {
public:
    MovieTicketDB(const std::string& dbName);
    ~MovieTicketDB();

    void create_table();
    void insert_ticket(const std::string& movieName, const std::string& theaterName,
        const std::string& seatNumber, const std::string& customerName);
    std::vector<std::vector<std::string>> search_tickets_by_customer(const std::string& customerName);
    void delete_ticket(const std::string& ticketId);
    void close_connection();

private:
    sqlite3* db;
    std::string dbName;
};

MovieTicketDB::MovieTicketDB(const std::string& dbName) : dbName(dbName) {
    if (sqlite3_open(dbName.c_str(), &db) != SQLITE_OK) {
        throw std::runtime_error("Unable to open database");
    }
    create_table();
}

MovieTicketDB::~MovieTicketDB() {
    close_connection();
}

void MovieTicketDB::create_table() {
    const char* create_tableSQL = R"(
        CREATE TABLE IF NOT EXISTS tickets (
            id INTEGER PRIMARY KEY,
            movie_name TEXT,
            theater_name TEXT,
            seat_number TEXT,
            customer_name TEXT
        )
    )";
    char* errMsg = nullptr;
    if (sqlite3_exec(db, create_tableSQL, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        throw std::runtime_error("Failed to create table: " + std::string(errMsg));
    }
}

void MovieTicketDB::insert_ticket(const std::string& movieName, const std::string& theaterName,
    const std::string& seatNumber, const std::string& customerName) {
    const char* insertSQL = R"(
        INSERT INTO tickets (movie_name, theater_name, seat_number, customer_name)
        VALUES (?, ?, ?, ?)
    )";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Failed to prepare statement");
    }
    sqlite3_bind_text(stmt, 1, movieName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, theaterName.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, seatNumber.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, customerName.c_str(), -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error("Failed to insert ticket");
    }
    sqlite3_finalize(stmt);
}

std::vector<std::vector<std::string>> MovieTicketDB::search_tickets_by_customer(const std::string& customerName) {
    const char* searchSQL = R"(
        SELECT * FROM tickets WHERE customer_name = ?
    )";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, searchSQL, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Failed to prepare statement");
    }
    sqlite3_bind_text(stmt, 1, customerName.c_str(), -1, SQLITE_STATIC);

    std::vector<std::vector<std::string>> results;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.emplace_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        results.emplace_back(std::move(row));
    }
    sqlite3_finalize(stmt);
    return results;
}

void MovieTicketDB::delete_ticket(const std::string& ticketId) {
    const char* deleteSQL = R"(
        DELETE FROM tickets WHERE id = ?
    )";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, deleteSQL, -1, &stmt, nullptr) != SQLITE_OK) {
        throw std::runtime_error("Failed to prepare statement");
    }
    sqlite3_bind_text(stmt, 1, ticketId.c_str(), -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        throw std::runtime_error("Failed to delete ticket");
    }
    sqlite3_finalize(stmt);
}

void MovieTicketDB::close_connection() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}
