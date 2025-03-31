package org.example;

import org.junit.jupiter.api.*;

import java.sql.*;
import java.util.*;
import static org.junit.jupiter.api.Assertions.*;

public class DatabaseProcessorTest {
    private static final String DATABASE_NAME = "test.db";
    private DatabaseProcessor processor;

    @BeforeEach
    void setUp() {
        processor = new DatabaseProcessor(DATABASE_NAME);
    }

    @AfterEach
    void tearDown() throws SQLException {
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:" + DATABASE_NAME);
             Statement stmt = conn.createStatement()) {
            stmt.execute("DROP TABLE IF EXISTS test_table");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Test
    void testCreateTable() {
        String tableName = "test_table";
        processor.createTable(tableName, "name", "age");

        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:" + DATABASE_NAME);
             Statement stmt = conn.createStatement()) {
            ResultSet rs = stmt.executeQuery("SELECT name FROM sqlite_master WHERE type='table' AND name='" + tableName + "'");
            assertTrue(rs.next());
            assertEquals(tableName, rs.getString("name"));
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Test
    void testInsertIntoDatabase() {
        String tableName = "test_table";
        List<Map<String, Object>> data = new ArrayList<>();
        data.add(Map.of("name", "John", "age", 25));
        data.add(Map.of("name", "Alice", "age", 30));

        processor.createTable(tableName, "name", "age");
        processor.insertIntoDatabase(tableName, data);

        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:" + DATABASE_NAME);
             Statement stmt = conn.createStatement()) {
            ResultSet rs = stmt.executeQuery("SELECT * FROM " + tableName);
            int count = 0;
            while (rs.next()) {
                count++;
            }
            assertEquals(data.size(), count);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Test
    void testSearchDatabase() {
        String tableName = "test_table";
        List<Map<String, Object>> data = new ArrayList<>();
        data.add(Map.of("name", "John", "age", 25));
        data.add(Map.of("name", "Alice", "age", 30));

        processor.createTable(tableName, "name", "age");
        processor.insertIntoDatabase(tableName, data);

        List<Map<String, Object>> result = processor.searchDatabase(tableName, "John");
        assertNotNull(result);
        assertEquals(1, result.size());
        assertEquals("John", result.get(0).get("name"));
    }

    @Test
    void testDeleteFromDatabase() {
        String tableName = "test_table";
        List<Map<String, Object>> data = new ArrayList<>();
        data.add(Map.of("name", "John", "age", 25));
        data.add(Map.of("name", "Alice", "age", 30));

        processor.createTable(tableName, "name", "age");
        processor.insertIntoDatabase(tableName, data);

        processor.deleteFromDatabase(tableName, "John");

        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:" + DATABASE_NAME);
             Statement stmt = conn.createStatement()) {
            ResultSet rs = stmt.executeQuery("SELECT * FROM " + tableName);
            int count = 0;
            while (rs.next()) {
                count++;
            }
            assertEquals(1, count);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
