import java.sql.*;

public class BookManagementDB {
    private Connection connection;
    private Statement statement;

    public BookManagementDB(String dbName) throws SQLException {
        connection = DriverManager.getConnection("jdbc:sqlite:" + dbName);
        statement = connection.createStatement();
        createTable();
    }

    private void createTable() throws SQLException {
        statement.executeUpdate("CREATE TABLE IF NOT EXISTS books (id INTEGER PRIMARY KEY, title TEXT, author TEXT)");
    }

    public void addBook(String title, String author) throws SQLException {
        PreparedStatement preparedStatement = connection.prepareStatement("INSERT INTO books (title, author) VALUES (?, ?)");
        preparedStatement.setString(1, title);
        preparedStatement.setString(2, author);
        preparedStatement.executeUpdate();
    }

    public void removeBook(int bookId) throws SQLException {
        PreparedStatement preparedStatement = connection.prepareStatement("DELETE FROM books WHERE id = ?");
        preparedStatement.setInt(1, bookId);
        preparedStatement.execute();
        connection.commit();
    }

    public void borrowBook(int bookId) throws SQLException {
        PreparedStatement preparedStatement = connection.prepareStatement("UPDATE books SET ... WHERE id = ?");
        preparedStatement.setInt(1, bookId);
        preparedStatement.execute();
        connection.commit();
    }

    public void returnBook(int bookId) throws SQLException {
        PreparedStatement preparedStatement = connection.prepareStatement("...");
        preparedStatement.setInt(1, bookId);
        preparedStatement.executeUpdate();
    }

    public ResultSet searchBooks() throws SQLException {
        return statement.executeQuery("SELECT * FROM books");
    }
}