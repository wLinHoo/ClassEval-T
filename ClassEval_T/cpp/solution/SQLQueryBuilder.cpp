#include <string>
#include <vector>
#include <sstream>

class SQLQueryBuilder {
public:
    static std::string select(const std::string& table, const std::vector<std::string>& columns = { "*" }, const std::vector<std::pair<std::string, std::string>>& where = {});
    static std::string insert(const std::string& table, const std::vector<std::pair<std::string, std::string>>& data);
    static std::string delete_(const std::string& table, const std::vector<std::pair<std::string, std::string>>& where = {});
    static std::string update(const std::string& table, const std::vector<std::pair<std::string, std::string>>& data, const std::vector<std::pair<std::string, std::string>>& where = {});
};


std::string SQLQueryBuilder::select(const std::string& table, const std::vector<std::string>& columns, const std::vector<std::pair<std::string, std::string>>& where) {
    std::ostringstream query;
    if (columns.size() == 1 && columns[0] == "*") {
        query << "SELECT *";
    }
    else {
        query << "SELECT ";
        for (size_t i = 0; i < columns.size(); ++i) {
            query << columns[i];
            if (i < columns.size() - 1) {
                query << ", ";
            }
        }
    }
    query << " FROM " << table;
    if (!where.empty()) {
        query << " WHERE ";
        bool first = true;
        for (const auto& [key, value] : where) {
            if (!first) {
                query << " AND ";
            }
            query << key << "='" << value << "'";
            first = false;
        }
    }
    return query.str();
}

std::string SQLQueryBuilder::insert(const std::string& table, const std::vector<std::pair<std::string, std::string>>& data) {
    std::ostringstream query;
    query << "INSERT INTO " << table << " (";
    for (size_t i = 0; i < data.size(); ++i) {
        query << data[i].first;
        if (i < data.size() - 1) {
            query << ", ";
        }
    }
    query << ") VALUES (";
    for (size_t i = 0; i < data.size(); ++i) {
        query << "'" << data[i].second << "'";
        if (i < data.size() - 1) {
            query << ", ";
        }
    }
    query << ")";
    return query.str();
}

std::string SQLQueryBuilder::delete_(const std::string& table, const std::vector<std::pair<std::string, std::string>>& where) {
    std::ostringstream query;
    query << "DELETE FROM " << table;
    if (!where.empty()) {
        query << " WHERE ";
        for (size_t i = 0; i < where.size(); ++i) {
            query << where[i].first << "='" << where[i].second << "'";
            if (i < where.size() - 1) {
                query << " AND ";
            }
        }
    }
    return query.str();
}

std::string SQLQueryBuilder::update(const std::string& table, const std::vector<std::pair<std::string, std::string>>& data, const std::vector<std::pair<std::string, std::string>>& where) {
    std::ostringstream query;
    query << "UPDATE " << table << " SET ";
    for (size_t i = 0; i < data.size(); ++i) {
        query << data[i].first << "='" << data[i].second << "'";
        if (i < data.size() - 1) {
            query << ", ";
        }
    }
    if (!where.empty()) {
        query << " WHERE ";
        for (size_t i = 0; i < where.size(); ++i) {
            query << where[i].first << "='" << where[i].second << "'";
            if (i < where.size() - 1) {
                query << " AND ";
            }
        }
    }
    return query.str();
}
