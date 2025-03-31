import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

public class DatabaseProcessor {
    private String databaseName;

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

    public void deleteFromDatabase(String tableName, String name) {
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:" + databaseName);
             PreparedStatement pstmt = conn.prepareStatement("DELETE FROM " + tableName + " WHERE name = ?")) {

            pstmt.setString(1, name);
            pstmt.executeUpdate();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void insertIntoDatabase(String tableName, List<Map<String, Object>> data) {
        String url = "jdbc:sqlite:" + databaseName;

        try (Connection conn = DriverManager.getConnection(url);
             PreparedStatement pstmt = conn.prepareStatement(
                 "INSERT INTO " + tableName + " (name, age) VALUES (?, ?)")) {

            for (Map<String, Object> item : data) {
                pstmt.setString(1, (String) item.get("name"));
                pstmt.setInt(2, (Integer) item.get("age"));
                pstmt.executeUpdate();
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public List<Object[]> searchDatabase(String tableName, String name) {
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:" + databaseName);
             PreparedStatement pstmt = conn.prepareStatement("SELECT * FROM " + tableName + " WHERE name = ?")) {

            pstmt.setString(1, name);
            ResultSet rs = pstmt.executeQuery();

            List<Object[]> results = new ArrayList<>();
            while (rs.next()) {
                int columnCount = rs.getMetaData().getColumnCount();
                Object[] row = new Object[columnCount];

                for (int i = 1; i <= columnCount; i++) {
                    row[i-1] = rs.getObject(i);
                }
                results.add(row);
            }

            return results.isEmpty() ? null : results;

        } catch (SQLException e) {
            e.printStackTrace();
            return null;
        }
    }
}