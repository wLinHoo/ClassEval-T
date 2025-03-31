
#include <iostream>
#include <sstream>

#include <string>
#include <map>
#include <vector>
#include <winsqlite/winsqlite3.h>

class StudentDatabaseProcessor {
public:
    explicit StudentDatabaseProcessor(const std::string& database_name);
    void create_student_table();
    void insert_student(const std::map<std::string, std::string>& student_data);
    std::vector<std::map<std::string, std::string>> search_student_by_name(const std::string& name);
    void delete_student_by_name(const std::string& name);

private:
    std::string database_name;

    void execute_query(const std::string& query, const std::vector<std::string>& params);
    std::vector<std::vector<std::string>> query_result(const std::string& query, const std::vector<std::string>& params);
};

StudentDatabaseProcessor::StudentDatabaseProcessor(const std::string& database_name)
    : database_name(database_name) {}

void StudentDatabaseProcessor::create_student_table() {
    std::string create_table_query = R"(
        CREATE TABLE IF NOT EXISTS students (
            id INTEGER PRIMARY KEY,
            name TEXT,
            age INTEGER,
            gender TEXT,
            grade INTEGER
        )
    )";

    execute_query(create_table_query, {});
}

void StudentDatabaseProcessor::insert_student(const std::map<std::string, std::string>& student_data) {
    std::string insert_query = R"(
        INSERT INTO students (name, age, gender, grade)
        VALUES (?, ?, ?, ?)
    )";

    std::vector<std::string> params = {
        student_data.at("name"),
        student_data.at("age"),
        student_data.at("gender"),
        student_data.at("grade")
    };

    execute_query(insert_query, params);
}

std::vector<std::map<std::string, std::string>> StudentDatabaseProcessor::search_student_by_name(const std::string& name) {
    std::string select_query = R"(
        SELECT * FROM students WHERE name = ?
    )";

    std::vector<std::string> params = { name };
    std::vector<std::vector<std::string>> results = query_result(select_query, params);

    std::vector<std::map<std::string, std::string>> students;
    for (const auto& row : results) {
        std::map<std::string, std::string> student;
        student["id"] = row[0];
        student["name"] = row[1];
        student["age"] = row[2];
        student["gender"] = row[3];
        student["grade"] = row[4];
        students.push_back(student);
    }

    return students;
}

void StudentDatabaseProcessor::delete_student_by_name(const std::string& name) {
    std::string delete_query = R"(
        DELETE FROM students WHERE name = ?
    )";

    std::vector<std::string> params = { name };
    execute_query(delete_query, params);
}

void StudentDatabaseProcessor::execute_query(const std::string& query, const std::vector<std::string>& params) {
    sqlite3* conn;
    sqlite3_open(database_name.c_str(), &conn);

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(conn, query.c_str(), -1, &stmt, nullptr);

    for (size_t i = 0; i < params.size(); ++i) {
        sqlite3_bind_text(stmt, static_cast<int>(i + 1), params[i].c_str(), -1, SQLITE_STATIC);
    }

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(conn);
}

std::vector<std::vector<std::string>> StudentDatabaseProcessor::query_result(const std::string& query, const std::vector<std::string>& params) {
    sqlite3* conn;
    sqlite3_open(database_name.c_str(), &conn);

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(conn, query.c_str(), -1, &stmt, nullptr);

    for (size_t i = 0; i < params.size(); ++i) {
        sqlite3_bind_text(stmt, static_cast<int>(i + 1), params[i].c_str(), -1, SQLITE_STATIC);
    }

    std::vector<std::vector<std::string>> results;
    int result = sqlite3_step(stmt);
    while (result == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        results.push_back(row);
        result = sqlite3_step(stmt);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    return results;
}
