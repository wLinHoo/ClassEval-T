#include <gtest/gtest.h>
#include "pch.h"

class SQLGeneratorTestSelect : public ::testing::Test {
protected:
    SQLGenerator sql;

    SQLGeneratorTestSelect() : sql("table1") {}
};

TEST_F(SQLGeneratorTestSelect, test_select_1) {
    std::string result = sql.select({ "field1" }, "field2 = value1");
    EXPECT_EQ(result, "SELECT field1 FROM table1 WHERE field2 = value1;");
}

TEST_F(SQLGeneratorTestSelect, test_select_2) {
    std::string result = sql.select({ "field1", "field2" }, "field3 = value1");
    EXPECT_EQ(result, "SELECT field1, field2 FROM table1 WHERE field3 = value1;");
}

TEST_F(SQLGeneratorTestSelect, test_select_3) {
    std::string result = sql.select({ "field1, field2" }, "field3 = value1");
    EXPECT_EQ(result, "SELECT field1, field2 FROM table1 WHERE field3 = value1;");
}

TEST_F(SQLGeneratorTestSelect, test_select_4) {
    std::string result = sql.select({ "field1, field2" }, "field3 = value1, field4 = value2");
    EXPECT_EQ(result, "SELECT field1, field2 FROM table1 WHERE field3 = value1, field4 = value2;");
}

TEST_F(SQLGeneratorTestSelect, test_select_5) {
    std::string result = sql.select({ "field1" }, "field2 = value1, field3 = value2");
    EXPECT_EQ(result, "SELECT field1 FROM table1 WHERE field2 = value1, field3 = value2;");
}

TEST_F(SQLGeneratorTestSelect, test_select_6) {
    std::string result = sql.select({ "field1" });
    EXPECT_EQ(result, "SELECT field1 FROM table1;");
}

class SQLGeneratorTestInsert : public ::testing::Test {
protected:
    SQLGenerator sql;

    SQLGeneratorTestInsert() : sql("table1") {}
};

TEST_F(SQLGeneratorTestInsert, test_insert) {
    std::string result = sql.insert({ {"field1", "value1"}, {"field2", "value2"} });
    EXPECT_EQ(result, "INSERT INTO table1 (field1, field2) VALUES ('value1', 'value2');");
}

TEST_F(SQLGeneratorTestInsert, test_insert_2) {
    std::string result = sql.insert({ {"field1", "value1"}, {"field2", "value2"}, {"field3", "value3"} });
    EXPECT_EQ(result, "INSERT INTO table1 (field1, field2, field3) VALUES ('value1', 'value2', 'value3');");
}

TEST_F(SQLGeneratorTestInsert, test_insert_3) {
    std::string result = sql.insert({ {"field1", "value1"}, {"field2", "value2"}, {"field3", "value3"}, {"field4", "value4"} });
    EXPECT_EQ(result, "INSERT INTO table1 (field1, field2, field3, field4) VALUES ('value1', 'value2', 'value3', 'value4');");
}

TEST_F(SQLGeneratorTestInsert, test_insert_4) {
    std::string result = sql.insert({ {"field1", "value1"}, {"field2", "value2"}, {"field3", "value3"}, {"field4", "value4"}, {"field5", "value5"} });
    EXPECT_EQ(result, "INSERT INTO table1 (field1, field2, field3, field4, field5) VALUES ('value1', 'value2', 'value3', 'value4', 'value5');");
}

TEST_F(SQLGeneratorTestInsert, test_insert_5) {
    std::string result = sql.insert({ {"field1", "value1"}, {"field2", "value2"}, {"field3", "value3"}, {"field4", "value4"}, {"field5", "value5"}, {"field6", "value6"} });
    EXPECT_EQ(result, "INSERT INTO table1 (field1, field2, field3, field4, field5, field6) VALUES ('value1', 'value2', 'value3', 'value4', 'value5', 'value6');");
}

class SQLGeneratorTestUpdate : public ::testing::Test {
protected:
    SQLGenerator sql;

    SQLGeneratorTestUpdate() : sql("table1") {}
};

TEST_F(SQLGeneratorTestUpdate, test_update) {
    std::string result = sql.update({ {"field1", "new_value1"}, {"field2", "new_value2"} }, "field3 = value1");
    EXPECT_EQ(result, "UPDATE table1 SET field1 = 'new_value1', field2 = 'new_value2' WHERE field3 = value1;");
}

TEST_F(SQLGeneratorTestUpdate, test_update_2) {
    std::string result = sql.update({ {"field1", "new_value1"}, {"field2", "new_value2"}, {"field3", "new_value3"} }, "field4 = value1");
    EXPECT_EQ(result, "UPDATE table1 SET field1 = 'new_value1', field2 = 'new_value2', field3 = 'new_value3' WHERE field4 = value1;");
}

TEST_F(SQLGeneratorTestUpdate, test_update_3) {
    std::string result = sql.update({ {"field1", "new_value1"}, {"field2", "new_value2"}, {"field3", "new_value3"}, {"field4", "new_value4"} }, "field5 = value1");
    EXPECT_EQ(result, "UPDATE table1 SET field1 = 'new_value1', field2 = 'new_value2', field3 = 'new_value3', field4 = 'new_value4' WHERE field5 = value1;");
}

TEST_F(SQLGeneratorTestUpdate, test_update_4) {
    std::string result = sql.update({ {"field1", "new_value1"}, {"field2", "new_value2"}, {"field3", "new_value3"}, {"field4", "new_value4"}, {"field5", "new_value5"} }, "field6 = value1");
    EXPECT_EQ(result, "UPDATE table1 SET field1 = 'new_value1', field2 = 'new_value2', field3 = 'new_value3', field4 = 'new_value4', field5 = 'new_value5' WHERE field6 = value1;");
}

TEST_F(SQLGeneratorTestUpdate, test_update_5) {
    std::string result = sql.update({ {"field1", "new_value1"}, {"field2", "new_value2"}, {"field3", "new_value3"}, {"field4", "new_value4"}, {"field5", "new_value5"}, {"field6", "new_value6"} }, "field7 = value1");
    EXPECT_EQ(result, "UPDATE table1 SET field1 = 'new_value1', field2 = 'new_value2', field3 = 'new_value3', field4 = 'new_value4', field5 = 'new_value5', field6 = 'new_value6' WHERE field7 = value1;");
}

class SQLGeneratorTestDelete : public ::testing::Test {
protected:
    SQLGenerator sql;

    SQLGeneratorTestDelete() : sql("table1") {}
};

TEST_F(SQLGeneratorTestDelete, test_delete) {
    std::string result = sql.delete_query("field1 = value1");
    EXPECT_EQ(result, "DELETE FROM table1 WHERE field1 = value1;");
}

TEST_F(SQLGeneratorTestDelete, test_delete_2) {
    std::string result = sql.delete_query("field1 = value1 AND field2 = value2");
    EXPECT_EQ(result, "DELETE FROM table1 WHERE field1 = value1 AND field2 = value2;");
}

TEST_F(SQLGeneratorTestDelete, test_delete_3) {
    std::string result = sql.delete_query("field1 = value1 AND field2 = value2 AND field3 = value3");
    EXPECT_EQ(result, "DELETE FROM table1 WHERE field1 = value1 AND field2 = value2 AND field3 = value3;");
}

TEST_F(SQLGeneratorTestDelete, test_delete_4) {
    std::string result = sql.delete_query("field1 = value1 AND field2 = value2 AND field3 = value3 AND field4 = value4");
    EXPECT_EQ(result, "DELETE FROM table1 WHERE field1 = value1 AND field2 = value2 AND field3 = value3 AND field4 = value4;");
}

TEST_F(SQLGeneratorTestDelete, test_delete_5) {
    std::string result = sql.delete_query("field1 = value1 AND field2 = value2 AND field3 = value3 AND field4 = value4 AND field5 = value5");
    EXPECT_EQ(result, "DELETE FROM table1 WHERE field1 = value1 AND field2 = value2 AND field3 = value3 AND field4 = value4 AND field5 = value5;");
}

class SQLGeneratorTestSelectFemaleUnderAge : public ::testing::Test {
protected:
    SQLGenerator sql;

    SQLGeneratorTestSelectFemaleUnderAge() : sql("table1") {}
};

TEST_F(SQLGeneratorTestSelectFemaleUnderAge, test_select_female_under_age) {
    std::string result = sql.select_female_under_age(30);
    EXPECT_EQ(result, "SELECT * FROM table1 WHERE age < 30 AND gender = 'female';");
}

TEST_F(SQLGeneratorTestSelectFemaleUnderAge, test_select_female_under_age_2) {
    std::string result = sql.select_female_under_age(40);
    EXPECT_EQ(result, "SELECT * FROM table1 WHERE age < 40 AND gender = 'female';");
}

TEST_F(SQLGeneratorTestSelectFemaleUnderAge, test_select_female_under_age_3) {
    std::string result = sql.select_female_under_age(20);
    EXPECT_EQ(result, "SELECT * FROM table1 WHERE age < 20 AND gender = 'female';");
}

TEST_F(SQLGeneratorTestSelectFemaleUnderAge, test_select_female_under_age_4) {
    std::string result = sql.select_female_under_age(10);
    EXPECT_EQ(result, "SELECT * FROM table1 WHERE age < 10 AND gender = 'female';");
}

TEST_F(SQLGeneratorTestSelectFemaleUnderAge, test_select_female_under_age_5) {
    std::string result = sql.select_female_under_age(50);
    EXPECT_EQ(result, "SELECT * FROM table1 WHERE age < 50 AND gender = 'female';");
}

class SQLGeneratorTestSelect_by_age_range : public ::testing::Test {
protected:
    SQLGenerator sql;

    SQLGeneratorTestSelect_by_age_range() : sql("table1") {}
};

TEST_F(SQLGeneratorTestSelect_by_age_range, test_select_by_age_range) {
    std::string result = sql.select_by_age_range(20, 30);
    EXPECT_EQ(result, "SELECT * FROM table1 WHERE age BETWEEN 20 AND 30;");
}

TEST_F(SQLGeneratorTestSelect_by_age_range, test_select_by_age_range_2) {
    std::string result = sql.select_by_age_range(10, 20);
    EXPECT_EQ(result, "SELECT * FROM table1 WHERE age BETWEEN 10 AND 20;");
}

TEST_F(SQLGeneratorTestSelect_by_age_range, test_select_by_age_range_3) {
    std::string result = sql.select_by_age_range(30, 40);
    EXPECT_EQ(result, "SELECT * FROM table1 WHERE age BETWEEN 30 AND 40;");
}

TEST_F(SQLGeneratorTestSelect_by_age_range, test_select_by_age_range_4) {
    std::string result = sql.select_by_age_range(40, 50);
    EXPECT_EQ(result, "SELECT * FROM table1 WHERE age BETWEEN 40 AND 50;");
}

TEST_F(SQLGeneratorTestSelect_by_age_range, test_select_by_age_range_5) {
    std::string result = sql.select_by_age_range(50, 60);
    EXPECT_EQ(result, "SELECT * FROM table1 WHERE age BETWEEN 50 AND 60;");
}

class SQLGeneratorTestMain : public ::testing::Test {
protected:
    SQLGenerator sql;

    SQLGeneratorTestMain() : sql("table1") {}
};

TEST_F(SQLGeneratorTestMain, test_main) {
    EXPECT_EQ(sql.select({ "field1", "field2" }, "field3 = value1"), "SELECT field1, field2 FROM table1 WHERE field3 = value1;");
    EXPECT_EQ(sql.insert({ {"field1", "value1"}, {"field2", "value2"} }), "INSERT INTO table1 (field1, field2) VALUES ('value1', 'value2');");
    EXPECT_EQ(sql.update({ {"field1", "new_value1"}, {"field2", "new_value2"} }, "field3 = value1"), "UPDATE table1 SET field1 = 'new_value1', field2 = 'new_value2' WHERE field3 = value1;");
    EXPECT_EQ(sql.delete_query("field1 = value1"), "DELETE FROM table1 WHERE field1 = value1;");
    EXPECT_EQ(sql.select_female_under_age(30), "SELECT * FROM table1 WHERE age < 30 AND gender = 'female';");
    EXPECT_EQ(sql.select_by_age_range(20, 30), "SELECT * FROM table1 WHERE age BETWEEN 20 AND 30;");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}