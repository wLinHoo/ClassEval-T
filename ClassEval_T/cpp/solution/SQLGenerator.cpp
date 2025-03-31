
#include <sstream>
#include <algorithm>

#include <string>
#include <vector>
#include <map>

class SQLGenerator {
public:
    SQLGenerator(const std::string& table_name);

    std::string select(const std::vector<std::string>& fields = {}, const std::string& condition = "") const;
    std::string insert(const std::map<std::string, std::string>& data) const;
    std::string update(const std::map<std::string, std::string>& data, const std::string& condition) const;
    std::string delete_query(const std::string& condition) const;
    std::string select_female_under_age(int age) const;
    std::string select_by_age_range(int min_age, int max_age) const;

private:
    std::string table_name;
};


SQLGenerator::SQLGenerator(const std::string& table_name) : table_name(table_name) {}


std::string SQLGenerator::select(const std::vector<std::string>& fields, const std::string& condition) const {
    std::string fields_str = "*";
    if (!fields.empty()) {
        fields_str = fields[0];
        for (size_t i = 1; i < fields.size(); ++i) {
            fields_str += ", " + fields[i];
        }
    }

    std::string sql = "SELECT " + fields_str + " FROM " + table_name;
    if (!condition.empty()) {
        sql += " WHERE " + condition;
    }
    return sql + ";";
}


std::string SQLGenerator::insert(const std::map<std::string, std::string>& data) const {
    std::ostringstream fields_stream, values_stream;

    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it != data.begin()) {
            fields_stream << ", ";
            values_stream << ", ";
        }
        fields_stream << it->first;
        values_stream << "'" << it->second << "'";
    }

    std::string sql = "INSERT INTO " + table_name + " (" + fields_stream.str() + ") VALUES (" + values_stream.str() + ")";
    return sql + ";";
}


std::string SQLGenerator::update(const std::map<std::string, std::string>& data, const std::string& condition) const {
    std::ostringstream set_clause_stream;

    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it != data.begin()) {
            set_clause_stream << ", ";
        }
        set_clause_stream << it->first << " = '" << it->second << "'";
    }

    std::string sql = "UPDATE " + table_name + " SET " + set_clause_stream.str();
    if (!condition.empty()) {
        sql += " WHERE " + condition;
    }
    return sql + ";";
}


std::string SQLGenerator::delete_query(const std::string& condition) const {
    std::string sql = "DELETE FROM " + table_name;
    if (!condition.empty()) {
        sql += " WHERE " + condition;
    }
    return sql + ";";
}


std::string SQLGenerator::select_female_under_age(int age) const {
    std::string condition = "age < " + std::to_string(age) + " AND gender = 'female'";
    return select({}, condition);
}


std::string SQLGenerator::select_by_age_range(int min_age, int max_age) const {
    std::string condition = "age BETWEEN " + std::to_string(min_age) + " AND " + std::to_string(max_age);
    return select({}, condition);
}
