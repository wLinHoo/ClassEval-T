#include <gtest/gtest.h>
#include "pch.h"
#include <string>
#include <vector>
#include <map>

class StudentDatabaseProcessorTest : public ::testing::Test {
protected:
    void SetUp() override {
        processor = new StudentDatabaseProcessor("test_database.db");
        processor->create_student_table();
    }

    void TearDown() override {
        sqlite3* conn;
        sqlite3_open("test_database.db", &conn);
        sqlite3_exec(conn, "DROP TABLE IF EXISTS students", nullptr, nullptr, nullptr);
        sqlite3_close(conn);
        delete processor;
    }

    StudentDatabaseProcessor* processor;
};

TEST_F(StudentDatabaseProcessorTest, TestStudentDatabaseProcessor) {
    
    std::map<std::string, std::string> student_data = {
        {"name", "Alice"},
        {"age", "20"},
        {"gender", "female"},
        {"grade", "90"}
    };
    processor->insert_student(student_data);

    sqlite3* conn;
    sqlite3_stmt* stmt;
    sqlite3_open("test_database.db", &conn);
    sqlite3_prepare_v2(conn, "SELECT * FROM students WHERE name=?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "Alice", -1, SQLITE_STATIC);
    int result = sqlite3_step(stmt);
    std::vector<std::string> row;
    while (result == SQLITE_ROW) {
        row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        result = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    ASSERT_EQ(row.size(), 1);
    ASSERT_EQ(row[0], "Alice");

    
    student_data = {
        {"name", "Bob"},
        {"age", "19"},
        {"gender", "male"},
        {"grade", "85"}
    };
    processor->insert_student(student_data);

    auto result_set = processor->search_student_by_name("Bob");

    ASSERT_EQ(result_set.size(), 1);
    ASSERT_EQ(result_set[0]["name"], "Bob");

    
    student_data = {
        {"name", "Charlie"},
        {"age", "18"},
        {"gender", "male"},
        {"grade", "95"}
    };
    processor->insert_student(student_data);

    processor->delete_student_by_name("Charlie");

    sqlite3_open("test_database.db", &conn);
    sqlite3_prepare_v2(conn, "SELECT * FROM students WHERE name=?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "Charlie", -1, SQLITE_STATIC);
    result = sqlite3_step(stmt);
    row.clear();
    while (result == SQLITE_ROW) {
        row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        result = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    ASSERT_EQ(row.size(), 0);
}

class StudentDatabaseProcessorTestInsertStudent : public ::testing::Test {
protected:
    void SetUp() override {
        processor = new StudentDatabaseProcessor("test_database.db");
        processor->create_student_table();
    }

    void TearDown() override {
        sqlite3* conn;
        sqlite3_open("test_database.db", &conn);
        sqlite3_exec(conn, "DROP TABLE IF EXISTS students", nullptr, nullptr, nullptr);
        sqlite3_close(conn);
        delete processor;
    }

    StudentDatabaseProcessor* processor;
};

TEST_F(StudentDatabaseProcessorTestInsertStudent, test_insert_student_1) {
    std::map<std::string, std::string> student_data = {
        {"name", "Alice"},
        {"age", "20"},
        {"gender", "female"},
        {"grade", "90"}
    };
    processor->insert_student(student_data);

    sqlite3* conn;
    sqlite3_stmt* stmt;
    sqlite3_open("test_database.db", &conn);
    sqlite3_prepare_v2(conn, "SELECT * FROM students WHERE name=?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "Alice", -1, SQLITE_STATIC);
    int result = sqlite3_step(stmt);
    std::vector<std::string> row;
    while (result == SQLITE_ROW) {
        row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        result = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    ASSERT_EQ(row.size(), 1);
    ASSERT_EQ(row[0], "Alice");
}

TEST_F(StudentDatabaseProcessorTestInsertStudent, test_insert_student_2) {
    std::map<std::string, std::string> student_data = {
        {"name", "aaa"},
        {"age", "20"},
        {"gender", "female"},
        {"grade", "90"}
    };
    processor->insert_student(student_data);

    sqlite3* conn;
    sqlite3_stmt* stmt;
    sqlite3_open("test_database.db", &conn);
    sqlite3_prepare_v2(conn, "SELECT * FROM students WHERE name=?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "aaa", -1, SQLITE_STATIC);
    int result = sqlite3_step(stmt);
    std::vector<std::string> row;
    while (result == SQLITE_ROW) {
        row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        result = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    ASSERT_EQ(row.size(), 1);
    ASSERT_EQ(row[0], "aaa");
}

TEST_F(StudentDatabaseProcessorTestInsertStudent, test_insert_student_3) {
    std::map<std::string, std::string> student_data = {
        {"name", "bbb"},
        {"age", "20"},
        {"gender", "female"},
        {"grade", "90"}
    };
    processor->insert_student(student_data);

    sqlite3* conn;
    sqlite3_stmt* stmt;
    sqlite3_open("test_database.db", &conn);
    sqlite3_prepare_v2(conn, "SELECT * FROM students WHERE name=?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "bbb", -1, SQLITE_STATIC);
    int result = sqlite3_step(stmt);
    std::vector<std::string> row;
    while (result == SQLITE_ROW) {
        row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        result = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    ASSERT_EQ(row.size(), 1);
    ASSERT_EQ(row[0], "bbb");
}

TEST_F(StudentDatabaseProcessorTestInsertStudent, test_insert_student_4) {
    std::map<std::string, std::string> student_data = {
        {"name", "ccc"},
        {"age", "20"},
        {"gender", "female"},
        {"grade", "90"}
    };
    processor->insert_student(student_data);

    sqlite3* conn;
    sqlite3_stmt* stmt;
    sqlite3_open("test_database.db", &conn);
    sqlite3_prepare_v2(conn, "SELECT * FROM students WHERE name=?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "ccc", -1, SQLITE_STATIC);
    int result = sqlite3_step(stmt);
    std::vector<std::string> row;
    while (result == SQLITE_ROW) {
        row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        result = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    ASSERT_EQ(row.size(), 1);
    ASSERT_EQ(row[0], "ccc");
}

TEST_F(StudentDatabaseProcessorTestInsertStudent, test_insert_student_5) {
    std::map<std::string, std::string> student_data = {
        {"name", "ddd"},
        {"age", "20"},
        {"gender", "female"},
        {"grade", "90"}
    };
    processor->insert_student(student_data);

    sqlite3* conn;
    sqlite3_stmt* stmt;
    sqlite3_open("test_database.db", &conn);
    sqlite3_prepare_v2(conn, "SELECT * FROM students WHERE name=?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "ddd", -1, SQLITE_STATIC);
    int result = sqlite3_step(stmt);
    std::vector<std::string> row;
    while (result == SQLITE_ROW) {
        row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        result = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    ASSERT_EQ(row.size(), 1);
    ASSERT_EQ(row[0], "ddd");
}

class StudentDatabaseProcessorTestSearchStudentByName : public ::testing::Test {
protected:
    void SetUp() override {
        processor = new StudentDatabaseProcessor("test_database.db");
        processor->create_student_table();
    }

    void TearDown() override {
        sqlite3* conn;
        sqlite3_open("test_database.db", &conn);
        sqlite3_exec(conn, "DROP TABLE IF EXISTS students", nullptr, nullptr, nullptr);
        sqlite3_close(conn);
        delete processor;
    }

    StudentDatabaseProcessor* processor;
};

TEST_F(StudentDatabaseProcessorTestSearchStudentByName, test_search_student_by_name_1) {
    std::map<std::string, std::string> student_data = {
        {"name", "Bob"},
        {"age", "19"},
        {"gender", "male"},
        {"grade", "85"}
    };
    processor->insert_student(student_data);

    auto result = processor->search_student_by_name("Bob");

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result[0].at("name"), "Bob");
}

TEST_F(StudentDatabaseProcessorTestSearchStudentByName, test_search_student_by_name_2) {
    std::map<std::string, std::string> student_data = {
        {"name", "aaa"},
        {"age", "19"},
        {"gender", "male"},
        {"grade", "85"}
    };
    processor->insert_student(student_data);

    auto result = processor->search_student_by_name("aaa");

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result[0].at("name"), "aaa");
}

TEST_F(StudentDatabaseProcessorTestSearchStudentByName, test_search_student_by_name_3) {
    std::map<std::string, std::string> student_data = {
        {"name", "bbb"},
        {"age", "19"},
        {"gender", "male"},
        {"grade", "85"}
    };
    processor->insert_student(student_data);

    auto result = processor->search_student_by_name("bbb");

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result[0].at("name"), "bbb");
}

TEST_F(StudentDatabaseProcessorTestSearchStudentByName, test_search_student_by_name_4) {
    std::map<std::string, std::string> student_data = {
        {"name", "ccc"},
        {"age", "19"},
        {"gender", "male"},
        {"grade", "85"}
    };
    processor->insert_student(student_data);

    auto result = processor->search_student_by_name("ccc");

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result[0].at("name"), "ccc");
}

TEST_F(StudentDatabaseProcessorTestSearchStudentByName, test_search_student_by_name_5) {
    std::map<std::string, std::string> student_data = {
        {"name", "ddd"},
        {"age", "19"},
        {"gender", "male"},
        {"grade", "85"}
    };
    processor->insert_student(student_data);

    auto result = processor->search_student_by_name("ddd");

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result[0].at("name"), "ddd");
}

class StudentDatabaseProcessorTestDeleteStudentByName : public ::testing::Test {
protected:
    void SetUp() override {
        processor = new StudentDatabaseProcessor("test_database.db");
        processor->create_student_table();
    }

    void TearDown() override {
        sqlite3* conn;
        sqlite3_open("test_database.db", &conn);
        sqlite3_exec(conn, "DROP TABLE IF EXISTS students", nullptr, nullptr, nullptr);
        sqlite3_close(conn);
        delete processor;
    }

    StudentDatabaseProcessor* processor;
};

TEST_F(StudentDatabaseProcessorTestDeleteStudentByName, test_delete_student_by_name_1) {
    std::map<std::string, std::string> student_data = {
        {"name", "Charlie"},
        {"age", "18"},
        {"gender", "male"},
        {"grade", "95"}
    };
    processor->insert_student(student_data);

    processor->delete_student_by_name("Charlie");

    sqlite3* conn;
    sqlite3_stmt* stmt;
    sqlite3_open("test_database.db", &conn);
    sqlite3_prepare_v2(conn, "SELECT * FROM students WHERE name=?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "Charlie", -1, SQLITE_STATIC);
    int result = sqlite3_step(stmt);
    std::vector<std::vector<std::string>> rows;
    while (result == SQLITE_ROW) {
        std::vector<std::string> row;
        row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        rows.push_back(row);
        result = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    ASSERT_EQ(rows.size(), 0);
}

TEST_F(StudentDatabaseProcessorTestDeleteStudentByName, test_delete_student_by_name_2) {
    std::map<std::string, std::string> student_data = {
        {"name", "aaa"},
        {"age", "18"},
        {"gender", "male"},
        {"grade", "95"}
    };
    processor->insert_student(student_data);

    processor->delete_student_by_name("aaa");

    sqlite3* conn;
    sqlite3_stmt* stmt;
    sqlite3_open("test_database.db", &conn);
    sqlite3_prepare_v2(conn, "SELECT * FROM students WHERE name=?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "aaa", -1, SQLITE_STATIC);
    int result = sqlite3_step(stmt);
    std::vector<std::vector<std::string>> rows;
    while (result == SQLITE_ROW) {
        std::vector<std::string> row;
        row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        rows.push_back(row);
        result = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    ASSERT_EQ(rows.size(), 0);
}

TEST_F(StudentDatabaseProcessorTestDeleteStudentByName, test_delete_student_by_name_3) {
    std::map<std::string, std::string> student_data = {
        {"name", "bbb"},
        {"age", "18"},
        {"gender", "male"},
        {"grade", "95"}
    };
    processor->insert_student(student_data);

    processor->delete_student_by_name("bbb");

    sqlite3* conn;
    sqlite3_stmt* stmt;
    sqlite3_open("test_database.db", &conn);
    sqlite3_prepare_v2(conn, "SELECT * FROM students WHERE name=?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "bbb", -1, SQLITE_STATIC);
    int result = sqlite3_step(stmt);
    std::vector<std::vector<std::string>> rows;
    while (result == SQLITE_ROW) {
        std::vector<std::string> row;
        row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        rows.push_back(row);
        result = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    ASSERT_EQ(rows.size(), 0);
}

TEST_F(StudentDatabaseProcessorTestDeleteStudentByName, test_delete_student_by_name_4) {
    std::map<std::string, std::string> student_data = {
        {"name", "ccc"},
        {"age", "18"},
        {"gender", "male"},
        {"grade", "95"}
    };
    processor->insert_student(student_data);

    processor->delete_student_by_name("ccc");

    sqlite3* conn;
    sqlite3_stmt* stmt;
    sqlite3_open("test_database.db", &conn);
    sqlite3_prepare_v2(conn, "SELECT * FROM students WHERE name=?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "ccc", -1, SQLITE_STATIC);
    int result = sqlite3_step(stmt);
    std::vector<std::vector<std::string>> rows;
    while (result == SQLITE_ROW) {
        std::vector<std::string> row;
        row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        rows.push_back(row);
        result = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    ASSERT_EQ(rows.size(), 0);
}

TEST_F(StudentDatabaseProcessorTestDeleteStudentByName, test_delete_student_by_name_5) {
    std::map<std::string, std::string> student_data = {
        {"name", "ddd"},
        {"age", "18"},
        {"gender", "male"},
        {"grade", "95"}
    };
    processor->insert_student(student_data);

    processor->delete_student_by_name("ddd");

    sqlite3* conn;
    sqlite3_stmt* stmt;
    sqlite3_open("test_database.db", &conn);
    sqlite3_prepare_v2(conn, "SELECT * FROM students WHERE name=?", -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "ddd", -1, SQLITE_STATIC);
    int result = sqlite3_step(stmt);
    std::vector<std::vector<std::string>> rows;
    while (result == SQLITE_ROW) {
        std::vector<std::string> row;
        row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        rows.push_back(row);
        result = sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(conn);

    ASSERT_EQ(rows.size(), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}