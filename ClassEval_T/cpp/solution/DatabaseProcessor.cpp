
#include <stdexcept>

#include <string>
#include <vector>
#include <unordered_map>
#include <winsqlite/winsqlite3.h>

class DatabaseProcessor {
public:
    explicit DatabaseProcessor(const std::string& database_name);

    void create_table(const std::string& table_name, const std::string& key1, const std::string& key2);
    void insert_into_database(const std::string& table_name, const std::vector<std::unordered_map<std::string, std::string>>& data);
    std::vector<std::vector<std::string>> search_database(const std::string& table_name, const std::string& name);
    void delete_from_database(const std::string& table_name, const std::string& name);

private:
    std::string database_name;
    sqlite3* open_database();
};

DatabaseProcessor::DatabaseProcessor(const std::string& database_name)
    : database_name(database_name) {}

sqlite3* DatabaseProcessor::open_database() {
    sqlite3* db;
    if (sqlite3_open(database_name.c_str(), &db) != SQLITE_OK) {
        throw std::runtime_error("Failed to open database");
    }
    return db;
}

void DatabaseProcessor::create_table(const std::string& table_name, const std::string& key1, const std::string& key2) {
    sqlite3* db = open_database();
    std::string create_table_query = "CREATE TABLE IF NOT EXISTS " + table_name + " (id INTEGER PRIMARY KEY, " + key1 + " TEXT, " + key2 + " INTEGER)";
    char* err_msg = nullptr;
    if (sqlite3_exec(db, create_table_query.c_str(), nullptr, nullptr, &err_msg) != SQLITE_OK) {
        std::string error_msg = "Failed to create table: " + std::string(err_msg);
        sqlite3_free(err_msg);
        sqlite3_close(db);
        throw std::runtime_error(error_msg);
    }
    sqlite3_close(db);
}

void DatabaseProcessor::insert_into_database(const std::string& table_name, const std::vector<std::unordered_map<std::string, std::string>>& data) {
    sqlite3* db = open_database();
    sqlite3_stmt* stmt;
    std::string insert_query = "INSERT INTO " + table_name + " (name, age) VALUES (?, ?)";
    if (sqlite3_prepare_v2(db, insert_query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::string error_msg = "Failed to prepare statement: " + std::string(sqlite3_errmsg(db));
        sqlite3_close(db);
        throw std::runtime_error(error_msg);
    }

    for (const auto& item : data) {
        sqlite3_bind_text(stmt, 1, item.at("name").c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, std::stoi(item.at("age")));

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            std::string error_msg = "Failed to execute statement: " + std::string(sqlite3_errmsg(db));
            sqlite3_finalize(stmt);
            sqlite3_close(db);
            throw std::runtime_error(error_msg);
        }
        sqlite3_reset(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

std::vector<std::vector<std::string>> DatabaseProcessor::search_database(const std::string& table_name, const std::string& name) {
    sqlite3* db;
    sqlite3_stmt* stmt;
    std::vector<std::vector<std::string>> result;

    int rc = sqlite3_open(database_name.c_str(), &db);
    if (rc != SQLITE_OK) {
        sqlite3_close(db);
        return result;
    }

    std::string query = "SELECT * FROM " + table_name + " WHERE name = ?";
    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        sqlite3_close(db);
        return result;
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        int column_count = sqlite3_column_count(stmt);
        for (int i = 0; i < column_count; ++i) {
            const unsigned char* text = sqlite3_column_text(stmt, i);
            row.push_back(text ? std::string(reinterpret_cast<const char*>(text)) : std::string());
        }
        result.push_back(row);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return result;
}


void DatabaseProcessor::delete_from_database(const std::string& table_name, const std::string& name) {
    sqlite3* db = open_database();
    sqlite3_stmt* stmt;
    std::string delete_query = "DELETE FROM " + table_name + " WHERE name = ?";
    if (sqlite3_prepare_v2(db, delete_query.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::string error_msg = "Failed to prepare statement: " + std::string(sqlite3_errmsg(db));
        sqlite3_close(db);
        throw std::runtime_error(error_msg);
    }

    sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::string error_msg = "Failed to execute statement: " + std::string(sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        throw std::runtime_error(error_msg);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}
