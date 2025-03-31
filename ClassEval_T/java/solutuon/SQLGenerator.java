package org.example;

import java.util.Map;
import java.util.TreeMap;
import java.util.stream.Collectors;

public class SQLGenerator {
    private final String table_name;

    public SQLGenerator(String table_name) {
        this.table_name = table_name;
    }

    public String select(String[] fields, String condition) {
        String fieldsStr = fields == null ? "*" : String.join(", ", fields);
        String sql = "SELECT " + fieldsStr + " FROM " + table_name;
        if (condition != null) {
            sql += " WHERE " + condition;
        }
        return sql + ";";
    }

    public String insert(Map<String, String> data) {
        Map<String, String> sortedData = new TreeMap<>(data);
        String fields = String.join(", ", sortedData.keySet());
        String values = sortedData.values().stream().map(value -> "'" + value + "'").collect(Collectors.joining(", "));
        return "INSERT INTO " + table_name + " (" + fields + ") VALUES (" + values + ");";
    }

    public String update(Map<String, String> data, String condition) {
        Map<String, String> sortedData = new TreeMap<>(data);
        String setClause = sortedData.entrySet().stream()
                .map(entry -> entry.getKey() + " = '" + entry.getValue() + "'")
                .collect(Collectors.joining(", "));
        return "UPDATE " + table_name + " SET " + setClause + " WHERE " + condition + ";";
    }

    public String delete(String condition) {
        return "DELETE FROM " + table_name + " WHERE " + condition + ";";
    }

    public String selectFemaleUnderAge(int age) {
        return "SELECT * FROM " + table_name + " WHERE age < " + age + " AND gender = 'female';";
    }

    public String selectByAgeRange(int minAge, int maxAge) {
        return "SELECT * FROM " + table_name + " WHERE age BETWEEN " + minAge + " AND " + maxAge + ";";
    }
}