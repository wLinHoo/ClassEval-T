package org.example;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.io.File;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.List;

import static org.junit.Assert.*;

public class BookManagementDBTest {

    private String dbName;
    private BookManagementDB db;
    private Connection connection;
    private Statement statement;

    @Before
    public void setUp() throws Exception {
        dbName = "test.db";
        db = new BookManagementDB(dbName);
        connection = DriverManager.getConnection("jdbc:sqlite:" + dbName);
        statement = connection.createStatement();
    }

    @After
    public void tearDown() throws Exception {
        if (db.connection != null && !db.connection.isClosed()) {
            db.connection.close();
        }
        if (statement != null && !statement.isClosed()) {
            statement.close();
        }
        if (connection != null && !connection.isClosed()) {
            connection.close();
        }
        File file = new File(dbName);
        if (file.exists()) {
            file.delete();
        }
    }


    @Test
    public void testCreateTable1() throws Exception {
        ResultSet result = statement.executeQuery("SELECT name FROM sqlite_master WHERE type='table' AND name='books'");
        assertTrue(result.next());
        result.close();
    }

    @Test
    public void testCreateTable2() throws Exception {
        db.createTable();
        ResultSet result = statement.executeQuery("PRAGMA table_info(books)");
        String[] expectedColumnNames = {"id", "title", "author", "available"};
        int index = 0;
        while (result.next()) {
            assertEquals(expectedColumnNames[index], result.getString("name"));
            index++;
        }
        assertEquals(expectedColumnNames.length, index);
        result.close();
    }

    @Test
    public void testAddBook() throws Exception {
        String title = "Introduction to Python";
        String author = "John Smith";
        db.addBook(title, author);

        ResultSet result = statement.executeQuery("SELECT title, author, available FROM books WHERE id=1");
        assertTrue(result.next());
        assertEquals(title, result.getString("title"));
        assertEquals(author, result.getString("author"));
        assertEquals(1, result.getInt("available"));
        result.close();
    }

    @Test
    public void testRemoveBook() throws Exception {
        db.addBook("Book to Remove", "John Doe");
        db.removeBook(1);

        ResultSet result = statement.executeQuery("SELECT * FROM books WHERE id=1");
        assertFalse(result.next());
        result.close();
    }

    @Test
    public void testBorrowBook() throws Exception {
        db.addBook("Book to Borrow", "Jane Smith");
        db.borrowBook(1);

        ResultSet result = statement.executeQuery("SELECT available FROM books WHERE id=1");
        assertTrue(result.next());
        assertEquals(0, result.getInt("available"));
        result.close();
    }

    @Test
    public void testReturnBook() throws Exception {
        db.addBook("Book to Return", "James Smith");
        db.borrowBook(1);
        db.returnBook(1);

        ResultSet result = statement.executeQuery("SELECT available FROM books WHERE id=1");
        assertTrue(result.next());
        assertEquals(1, result.getInt("available"));
        result.close();
    }

    @Test
    public void testSearchBooks() throws Exception {
        db.addBook("Book 1", "Author 1");
        db.addBook("Book 2", "Author 2");
        db.addBook("Book 3", "Author 3");

        List<BookManagementDB.Book> books = db.searchBooks();

        assertEquals(3, books.size());

        assertEquals("Book 1", books.get(0).getTitle());
        assertEquals("Author 2", books.get(1).getAuthor());
        assertEquals(1, books.get(2).getAvailable());
    }
}
