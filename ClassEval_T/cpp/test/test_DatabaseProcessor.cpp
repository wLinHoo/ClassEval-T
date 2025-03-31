#include <gtest/gtest.h>
#include "pch.h" 

class DatabaseProcessorTestCreateTable : public ::testing::Test {
protected:
    void SetUp() override {
        database_name = "test.db";
        processor = std::make_unique<DatabaseProcessor>(database_name);
    }

    void TearDown() override {
        sqlite3* db;
        sqlite3_open(database_name.c_str(), &db);
        sqlite3_exec(db, "DROP TABLE IF EXISTS test_table", nullptr, nullptr, nullptr);
        sqlite3_close(db);
    }

    std::string database_name;
    std::unique_ptr<DatabaseProcessor> processor;
};

TEST_F(DatabaseProcessorTestCreateTable, test_create_table_1) {
    std::string table_name = "test_table";
    processor->create_table(table_name, "name", "age");

    sqlite3* db;
    sqlite3_stmt* stmt;
    sqlite3_open(database_name.c_str(), &db);
    std::string query = "SELECT name FROM sqlite_master WHERE type='table' AND name=?";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, table_name.c_str(), -1, SQLITE_STATIC);

    const char* result = nullptr;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        result = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    }


    ASSERT_NE(result, nullptr);
    ASSERT_STREQ(result, table_name.c_str());

    sqlite3_finalize(stmt);
    sqlite3_close(db);

}

TEST_F(DatabaseProcessorTestCreateTable, test_create_table_2) {
    std::string table_name = "test_table2";
    processor->create_table(table_name, "name", "age");

    sqlite3* db;
    sqlite3_stmt* stmt;
    sqlite3_open(database_name.c_str(), &db);
    std::string query = "SELECT name FROM sqlite_master WHERE type='table' AND name=?";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, table_name.c_str(), -1, SQLITE_STATIC);

    const char* result = nullptr;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        result = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    }

    ASSERT_NE(result, nullptr);
    ASSERT_STREQ(result, table_name.c_str());

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

TEST_F(DatabaseProcessorTestCreateTable, test_create_table_3) {
    std::string table_name = "test_table3";
    processor->create_table(table_name, "name", "age");

    sqlite3* db;
    sqlite3_stmt* stmt;
    sqlite3_open(database_name.c_str(), &db);
    std::string query = "SELECT name FROM sqlite_master WHERE type='table' AND name=?";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, table_name.c_str(), -1, SQLITE_STATIC);

    const char* result = nullptr;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        result = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    }

    ASSERT_NE(result, nullptr);
    ASSERT_STREQ(result, table_name.c_str());

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

TEST_F(DatabaseProcessorTestCreateTable, test_create_table_4) {
    std::string table_name = "test_table4";
    processor->create_table(table_name, "name", "age");

    sqlite3* db;
    sqlite3_stmt* stmt;
    sqlite3_open(database_name.c_str(), &db);
    std::string query = "SELECT name FROM sqlite_master WHERE type='table' AND name=?";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, table_name.c_str(), -1, SQLITE_STATIC);

    const char* result = nullptr;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        result = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    }

    ASSERT_NE(result, nullptr);
    ASSERT_STREQ(result, table_name.c_str());

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

TEST_F(DatabaseProcessorTestCreateTable, test_create_table_5) {
    std::string table_name = "test_table5";
    processor->create_table(table_name, "name", "age");

    sqlite3* db;
    sqlite3_stmt* stmt;
    sqlite3_open(database_name.c_str(), &db);
    std::string query = "SELECT name FROM sqlite_master WHERE type='table' AND name=?";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, table_name.c_str(), -1, SQLITE_STATIC);

    const char* result = nullptr;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        result = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    }

    ASSERT_NE(result, nullptr);
    ASSERT_STREQ(result, table_name.c_str());

    sqlite3_finalize(stmt);
    sqlite3_close(db);
}


class DatabaseProcessorTestInsertIntoDatabase : public ::testing::Test {
protected:
    void SetUp() override {
        database_name = "test.db";
        processor = std::make_unique<DatabaseProcessor>(database_name);
    }

    void TearDown() override {
        sqlite3* db;
        sqlite3_open(database_name.c_str(), &db);
        sqlite3_exec(db, "DROP TABLE IF EXISTS test_table", nullptr, nullptr, nullptr);
        sqlite3_close(db);
    }

    std::string database_name;
    std::unique_ptr<DatabaseProcessor> processor;
};

TEST_F(DatabaseProcessorTestInsertIntoDatabase, test_insert_into_database_1) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "25"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    sqlite3* db;
    sqlite3_stmt* stmt;
    sqlite3_open(database_name.c_str(), &db);
    std::string query = "SELECT * FROM " + table_name;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    std::vector<std::vector<std::string>> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        result.push_back(row);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_EQ(result.size(), data.size());
    ASSERT_EQ(result[0][2], "25"); 
}

TEST_F(DatabaseProcessorTestInsertIntoDatabase, test_insert_into_database_2) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "15"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    sqlite3* db;
    sqlite3_stmt* stmt;
    sqlite3_open(database_name.c_str(), &db);
    std::string query = "SELECT * FROM " + table_name;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    std::vector<std::vector<std::string>> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        result.push_back(row);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_EQ(result.size(), data.size());
    ASSERT_EQ(result[0][2], "15"); 
}

TEST_F(DatabaseProcessorTestInsertIntoDatabase, test_insert_into_database_3) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "16"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    sqlite3* db;
    sqlite3_stmt* stmt;
    sqlite3_open(database_name.c_str(), &db);
    std::string query = "SELECT * FROM " + table_name;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    std::vector<std::vector<std::string>> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        result.push_back(row);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_EQ(result.size(), data.size());
    ASSERT_EQ(result[0][2], "16"); 
}

TEST_F(DatabaseProcessorTestInsertIntoDatabase, test_insert_into_database_4) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "17"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    sqlite3* db;
    sqlite3_stmt* stmt;
    sqlite3_open(database_name.c_str(), &db);
    std::string query = "SELECT * FROM " + table_name;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    std::vector<std::vector<std::string>> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        result.push_back(row);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_EQ(result.size(), data.size());
    ASSERT_EQ(result[0][2], "17"); 
}

TEST_F(DatabaseProcessorTestInsertIntoDatabase, test_insert_into_database_5) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "18"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    sqlite3* db;
    sqlite3_stmt* stmt;
    sqlite3_open(database_name.c_str(), &db);
    std::string query = "SELECT * FROM " + table_name;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    std::vector<std::vector<std::string>> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        result.push_back(row);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_EQ(result.size(), data.size());
    ASSERT_EQ(result[0][2], "18"); 
}

class DatabaseProcessorTestSearchDatabase : public ::testing::Test {
protected:
    void SetUp() override {
        database_name = "test.db";
        processor = std::make_unique<DatabaseProcessor>(database_name);
    }

    void TearDown() override {
        sqlite3* db;
        sqlite3_open(database_name.c_str(), &db);
        sqlite3_exec(db, "DROP TABLE IF EXISTS test_table", nullptr, nullptr, nullptr);
        sqlite3_close(db);
    }

    std::string database_name;
    std::unique_ptr<DatabaseProcessor> processor;
};

TEST_F(DatabaseProcessorTestSearchDatabase, test_search_database_1) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "25"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    auto result = processor->search_database(table_name, "John");
    ASSERT_FALSE(result.empty());
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result[0][1], "John");

}

TEST_F(DatabaseProcessorTestSearchDatabase, test_search_database_2) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "25"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    auto result = processor->search_database(table_name, "Alice");
    ASSERT_FALSE(result.empty());
    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ((result)[0][1], "Alice");
}

TEST_F(DatabaseProcessorTestSearchDatabase, test_search_database_3) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "25"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    auto result = processor->search_database(table_name, "Bob");
    ASSERT_TRUE(result.empty());
}

TEST_F(DatabaseProcessorTestSearchDatabase, test_search_database_4) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "25"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    auto result = processor->search_database(table_name, "aaa");
    ASSERT_TRUE(result.empty());
}

TEST_F(DatabaseProcessorTestSearchDatabase, test_search_database_5) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "25"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    auto result = processor->search_database(table_name, "bbb");
    ASSERT_TRUE(result.empty());
}

class DatabaseProcessorTestDeleteFromDatabase : public ::testing::Test {
protected:
    void SetUp() override {
        database_name = "test.db";
        processor = std::make_unique<DatabaseProcessor>(database_name);
    }

    void TearDown() override {
        sqlite3* db;
        sqlite3_open(database_name.c_str(), &db);
        sqlite3_exec(db, "DROP TABLE IF EXISTS test_table", nullptr, nullptr, nullptr);
        sqlite3_close(db);
    }

    std::string database_name;
    std::unique_ptr<DatabaseProcessor> processor;
};

TEST_F(DatabaseProcessorTestDeleteFromDatabase, test_delete_from_database_1) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "25"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    processor->delete_from_database(table_name, "John");

    sqlite3* db;
    sqlite3_open(database_name.c_str(), &db);
    sqlite3_stmt* stmt;
    std::string query = "SELECT * FROM " + table_name;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    std::vector<std::vector<std::string>> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        result.push_back(row);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result[0][1], "Alice");
}

TEST_F(DatabaseProcessorTestDeleteFromDatabase, test_delete_from_database_2) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "25"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    processor->delete_from_database(table_name, "Alice");

    sqlite3* db;
    sqlite3_open(database_name.c_str(), &db);
    sqlite3_stmt* stmt;
    std::string query = "SELECT * FROM " + table_name;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    std::vector<std::vector<std::string>> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        result.push_back(row);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result[0][1], "John");
}

TEST_F(DatabaseProcessorTestDeleteFromDatabase, test_delete_from_database_3) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "25"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    processor->delete_from_database(table_name, "John");
    processor->delete_from_database(table_name, "Alice");

    sqlite3* db;
    sqlite3_open(database_name.c_str(), &db);
    sqlite3_stmt* stmt;
    std::string query = "SELECT * FROM " + table_name;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    std::vector<std::vector<std::string>> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        result.push_back(row);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_EQ(result.size(), 0);
}

TEST_F(DatabaseProcessorTestDeleteFromDatabase, test_delete_from_database_4) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "25"}},
        {{"name", "aaa"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    processor->delete_from_database(table_name, "John");

    sqlite3* db;
    sqlite3_open(database_name.c_str(), &db);
    sqlite3_stmt* stmt;
    std::string query = "SELECT * FROM " + table_name;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    std::vector<std::vector<std::string>> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        result.push_back(row);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result[0][1], "aaa");
}

TEST_F(DatabaseProcessorTestDeleteFromDatabase, test_delete_from_database_5) {
    std::string table_name = "test_table";
    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "bbb"}, {"age", "25"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->create_table(table_name, "name", "age");
    processor->insert_into_database(table_name, data);

    processor->delete_from_database(table_name, "bbb");

    sqlite3* db;
    sqlite3_open(database_name.c_str(), &db);
    sqlite3_stmt* stmt;
    std::string query = "SELECT * FROM " + table_name;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    std::vector<std::vector<std::string>> result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        result.push_back(row);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_EQ(result.size(), 1);
    ASSERT_EQ(result[0][1], "Alice");
}

class DatabaseProcessorTest : public ::testing::Test {
protected:
    void SetUp() override {
        database_name = "test.db";
        processor = std::make_unique<DatabaseProcessor>(database_name);
    }

    void TearDown() override {
        sqlite3* db;
        sqlite3_open(database_name.c_str(), &db);
        sqlite3_exec(db, "DROP TABLE IF EXISTS test_table", nullptr, nullptr, nullptr);
        sqlite3_close(db);
    }

    std::string database_name;
    std::unique_ptr<DatabaseProcessor> processor;
};

TEST_F(DatabaseProcessorTest, test_DatabaseProcessor) {
    std::string table_name = "test_table";
    processor->create_table(table_name, "name", "age");

    sqlite3* db;
    sqlite3_open(database_name.c_str(), &db);
    sqlite3_stmt* stmt;
    std::string query = "SELECT name FROM sqlite_master WHERE type='table' AND name=?";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, table_name.c_str(), -1, SQLITE_STATIC);

    std::vector<std::string> result;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        result.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_FALSE(result.empty());
    ASSERT_EQ(result[0], table_name);

    std::vector<std::unordered_map<std::string, std::string>> data = {
        {{"name", "John"}, {"age", "25"}},
        {{"name", "Alice"}, {"age", "30"}}
    };
    processor->insert_into_database(table_name, data);

    sqlite3_open(database_name.c_str(), &db);
    sqlite3_prepare_v2(db, ("SELECT * FROM " + table_name).c_str(), -1, &stmt, nullptr);

    std::vector<std::vector<std::string>> query_result;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        query_result.push_back(row);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_EQ(query_result.size(), data.size());
    ASSERT_EQ(query_result[0][2], "25");
    auto search_result = processor->search_database(table_name, "John");
    ASSERT_FALSE(search_result.empty());
    ASSERT_EQ(search_result.size(), 1);
    ASSERT_EQ(search_result[0][1], "John");

    processor->delete_from_database(table_name, "John");

    sqlite3_open(database_name.c_str(), &db);
    sqlite3_prepare_v2(db, ("SELECT * FROM " + table_name).c_str(), -1, &stmt, nullptr);

    query_result.clear();
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::vector<std::string> row;
        for (int i = 0; i < sqlite3_column_count(stmt); ++i) {
            row.push_back(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
        }
        query_result.push_back(row);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

    ASSERT_EQ(query_result.size(), 1);
    ASSERT_EQ(query_result[0][1], "Alice");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}