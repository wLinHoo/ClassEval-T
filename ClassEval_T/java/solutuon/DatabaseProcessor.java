package org.example;

import java.sql.*;
import java.util.*;

public class DatabaseProcessor {
    private String databaseName;

    static {
        try {
            Class.forName("org.sqlite.JDBC");
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    public DatabaseProcessor(String databaseName) {
        this.databaseName = databaseName;
    }

    public void createTable(String tableName, String key1, String key2) {
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:" + databaseName);
             Statement stmt = conn.createStatement()) {
            String createTableQuery = String.format(
                    "CREATE TABLE IF NOT EXISTS %s (id INTEGER PRIMARY KEY, %s TEXT, %s INTEGER)",
                    tableName, key1, key2);
            stmt.execute(createTableQuery);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void insertIntoDatabase(String tableName, List<Map<String, Object>> data) {
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:" + databaseName);
             Statement stmt = conn.createStatement()) {
            for (Map<String, Object> item : data) {
                String insertQuery = String.format(
                        "INSERT INTO %s (name, age) VALUES ('%s', %d)",
                        tableName, item.get("name"), (int) item.get("age"));
                stmt.execute(insertQuery);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public List<Map<String, Object>> searchDatabase(String tableName, String name) {
        List<Map<String, Object>> result = new ArrayList<>();
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:" + databaseName);
             Statement stmt = conn.createStatement()) {
            String selectQuery = String.format("SELECT * FROM %s WHERE name = '%s'", tableName, name);
            ResultSet rs = stmt.executeQuery(selectQuery);
            while (rs.next()) {
                Map<String, Object> row = new HashMap<>();
                row.put("id", rs.getInt("id"));
                row.put("name", rs.getString("name"));
                row.put("age", rs.getInt("age"));
                result.add(row);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return result.isEmpty() ? null : result;
    }

    public void deleteFromDatabase(String tableName, String name) {
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:" + databaseName);
             Statement stmt = conn.createStatement()) {
            String deleteQuery = String.format("DELETE FROM %s WHERE name = '%s'", tableName, name);
            stmt.execute(deleteQuery);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
