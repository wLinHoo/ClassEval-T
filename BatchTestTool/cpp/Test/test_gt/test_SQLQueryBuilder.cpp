#include <gtest/gtest.h>
#include <string>
#include <map>
#include <vector>
#include "pch.h"

class SQLQueryBuilderTestSelect : public ::testing::Test {};

TEST_F(SQLQueryBuilderTestSelect, test_select_1) {
    ASSERT_EQ(SQLQueryBuilder::select("users", { "id", "name" }, { {"age", "30"} }), "SELECT id, name FROM users WHERE age='30'");
}

TEST_F(SQLQueryBuilderTestSelect, test_select_2) {
    ASSERT_EQ(SQLQueryBuilder::select("students", { "id", "name" }, { {"age", "18"} }), "SELECT id, name FROM students WHERE age='18'");
}

TEST_F(SQLQueryBuilderTestSelect, test_select_3) {
    ASSERT_EQ(SQLQueryBuilder::select("items", { "id", "name" }, { {"price", "1.0"} }), "SELECT id, name FROM items WHERE price='1.0'");
}

TEST_F(SQLQueryBuilderTestSelect, test_select_4) {
    ASSERT_EQ(SQLQueryBuilder::select("users", { "id" }, { {"age", "30"} }), "SELECT id FROM users WHERE age='30'");
}

TEST_F(SQLQueryBuilderTestSelect, test_select_5) {
    ASSERT_EQ(SQLQueryBuilder::select("users", { "name" }, { {"age", "30"} }), "SELECT name FROM users WHERE age='30'");
}

TEST_F(SQLQueryBuilderTestSelect, test_select_6) {
    ASSERT_EQ(SQLQueryBuilder::select("users", { "name" }), "SELECT name FROM users");
}

TEST_F(SQLQueryBuilderTestSelect, test_select_7) {
    ASSERT_EQ(SQLQueryBuilder::select("users", { "*" }), "SELECT * FROM users");
}

class SQLQueryBuilderTestInsert : public ::testing::Test {};

TEST_F(SQLQueryBuilderTestInsert, test_insert_1) {
    ASSERT_EQ(SQLQueryBuilder::insert("users", { {"name", "Tom"}, {"age", "30"} }), "INSERT INTO users (name, age) VALUES ('Tom', '30')");
}

TEST_F(SQLQueryBuilderTestInsert, test_insert_2) {
    ASSERT_EQ(SQLQueryBuilder::insert("students", { {"name", "Tom"}, {"age", "18"} }), "INSERT INTO students (name, age) VALUES ('Tom', '18')");
}

TEST_F(SQLQueryBuilderTestInsert, test_insert_3) {
    ASSERT_EQ(SQLQueryBuilder::insert("items", { {"name", "apple"}, {"price", "1.0"} }), "INSERT INTO items (name, price) VALUES ('apple', '1.0')");
}

TEST_F(SQLQueryBuilderTestInsert, test_insert_4) {
    ASSERT_EQ(SQLQueryBuilder::insert("users", { {"name", "Tom"} }), "INSERT INTO users (name) VALUES ('Tom')");
}

TEST_F(SQLQueryBuilderTestInsert, test_insert_5) {
    ASSERT_EQ(SQLQueryBuilder::insert("users", { {"name", "Tom"}, {"age", "30"}, {"region", "USA"} }), "INSERT INTO users (name, age, region) VALUES ('Tom', '30', 'USA')");
}

class SQLQueryBuilderTestDelete : public ::testing::Test {};

TEST_F(SQLQueryBuilderTestDelete, test_delete_1) {
    ASSERT_EQ(SQLQueryBuilder::delete_("users", { {"name", "Tom"} }), "DELETE FROM users WHERE name='Tom'");
}

TEST_F(SQLQueryBuilderTestDelete, test_delete_2) {
    ASSERT_EQ(SQLQueryBuilder::delete_("students", { {"name", "Tom"} }), "DELETE FROM students WHERE name='Tom'");
}

TEST_F(SQLQueryBuilderTestDelete, test_delete_3) {
    ASSERT_EQ(SQLQueryBuilder::delete_("items", { {"name", "apple"} }), "DELETE FROM items WHERE name='apple'");
}

TEST_F(SQLQueryBuilderTestDelete, test_delete_4) {
    ASSERT_EQ(SQLQueryBuilder::delete_("items", { {"name", "aaa"} }), "DELETE FROM items WHERE name='aaa'");
}

TEST_F(SQLQueryBuilderTestDelete, test_delete_5) {
    ASSERT_EQ(SQLQueryBuilder::delete_("items", { {"name", "bbb"} }), "DELETE FROM items WHERE name='bbb'");
}

TEST_F(SQLQueryBuilderTestDelete, test_delete_6) {
    ASSERT_EQ(SQLQueryBuilder::delete_("items"), "DELETE FROM items");
}

class SQLQueryBuilderTestUpdate : public ::testing::Test {};

TEST_F(SQLQueryBuilderTestUpdate, test_update_1) {
    ASSERT_EQ(SQLQueryBuilder::update("users", { {"age", "35"} }, { {"name", "Tom"} }), "UPDATE users SET age='35' WHERE name='Tom'");
}

TEST_F(SQLQueryBuilderTestUpdate, test_update_2) {
    ASSERT_EQ(SQLQueryBuilder::update("students", { {"age", "18"} }, { {"name", "Tom"} }), "UPDATE students SET age='18' WHERE name='Tom'");
}

TEST_F(SQLQueryBuilderTestUpdate, test_update_3) {
    ASSERT_EQ(SQLQueryBuilder::update("items", { {"price", "1.0"} }, { {"name", "apple"} }), "UPDATE items SET price='1.0' WHERE name='apple'");
}

TEST_F(SQLQueryBuilderTestUpdate, test_update_4) {
    ASSERT_EQ(SQLQueryBuilder::update("items", { {"price", "1.0"} }, { {"name", "aaa"} }), "UPDATE items SET price='1.0' WHERE name='aaa'");
}

TEST_F(SQLQueryBuilderTestUpdate, test_update_5) {
    ASSERT_EQ(SQLQueryBuilder::update("items", { {"price", "1.0"} }, { {"name", "bbb"} }), "UPDATE items SET price='1.0' WHERE name='bbb'");
}

TEST_F(SQLQueryBuilderTestUpdate, test_update_6) {
    ASSERT_EQ(SQLQueryBuilder::update("items", { {"price", "1.0"} }), "UPDATE items SET price='1.0'");
}

class SQLQueryBuilderTestMain : public ::testing::Test {};

TEST_F(SQLQueryBuilderTestMain, test_main) {
    ASSERT_EQ(SQLQueryBuilder::select("users", { "id", "name" }, { {"age", "30"} }), "SELECT id, name FROM users WHERE age='30'");
    ASSERT_EQ(SQLQueryBuilder::insert("users", { {"name", "Tom"}, {"age", "30"} }), "INSERT INTO users (name, age) VALUES ('Tom', '30')");
    ASSERT_EQ(SQLQueryBuilder::delete_("users", { {"name", "Tom"} }), "DELETE FROM users WHERE name='Tom'");
    ASSERT_EQ(SQLQueryBuilder::update("users", { {"age", "35"} }, { {"name", "Tom"} }), "UPDATE users SET age='35' WHERE name='Tom'");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}