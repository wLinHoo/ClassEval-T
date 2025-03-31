package org.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class BookManagementDB {

    Connection connection;

    public BookManagementDB(String dbName) throws SQLException {
        connection = DriverManager.getConnection("jdbc:sqlite:" + dbName);
        createTable();
    }

    void createTable() throws SQLException {
        String createTableSQL = "CREATE TABLE IF NOT EXISTS books ("
                + "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                + "title TEXT, "
                + "author TEXT, "
                + "available INTEGER"
                + ")";
        try (Statement stmt = connection.createStatement()) {
            stmt.execute(createTableSQL);
        }
    }

    public void addBook(String title, String author) throws SQLException {
        String insertSQL = "INSERT INTO books (title, author, available) VALUES (?, ?, 1)";
        try (PreparedStatement pstmt = connection.prepareStatement(insertSQL)) {
            pstmt.setString(1, title);
            pstmt.setString(2, author);
            pstmt.executeUpdate();
        }
    }

    public void removeBook(int bookId) throws SQLException {
        String deleteSQL = "DELETE FROM books WHERE id = ?";
        try (PreparedStatement pstmt = connection.prepareStatement(deleteSQL)) {
            pstmt.setInt(1, bookId);
            pstmt.executeUpdate();
        }
    }

    public void borrowBook(int bookId) throws SQLException {
        String updateSQL = "UPDATE books SET available = 0 WHERE id = ?";
        try (PreparedStatement pstmt = connection.prepareStatement(updateSQL)) {
            pstmt.setInt(1, bookId);
            pstmt.executeUpdate();
        }
    }

    public void returnBook(int bookId) throws SQLException {
        String updateSQL = "UPDATE books SET available = 1 WHERE id = ?";
        try (PreparedStatement pstmt = connection.prepareStatement(updateSQL)) {
            pstmt.setInt(1, bookId);
            pstmt.executeUpdate();
        }
    }

    public List<Book> searchBooks() throws SQLException {
        String selectSQL = "SELECT * FROM books";
        List<Book> books = new ArrayList<>();
        try (Statement stmt = connection.createStatement();
             ResultSet rs = stmt.executeQuery(selectSQL)) {
            while (rs.next()) {
                int id = rs.getInt("id");
                String title = rs.getString("title");
                String author = rs.getString("author");
                int available = rs.getInt("available");
                books.add(new Book(id, title, author, available));
            }
        }
        return books;
    }

    public static class Book {
        private int id;
        private String title;
        private String author;
        private int available;

        public Book(int id, String title, String author, int available) {
            this.id = id;
            this.title = title;
            this.author = author;
            this.available = available;
        }

        public int getId() { return id; }
        public String getTitle() { return title; }
        public String getAuthor() { return author; }
        public int getAvailable() { return available; }

        @Override
        public String toString() {
            return "Book{" +
                    "id=" + id +
                    ", title='" + title + '\'' +
                    ", author='" + author + '\'' +
                    ", available=" + available +
                    '}';
        }
    }
}
