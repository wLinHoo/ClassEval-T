package test_cases;
import to_be_tested.BookManagement;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

public class BookManagementTest {
    private BookManagement bookManagement;

    @BeforeEach
    public void setUp() {
        bookManagement = new BookManagement();
    }

    @Test
    public void testAddBook1() {
        bookManagement.addBook("book1", 1);
        assertEquals(Map.of("book1", 1), bookManagement.viewInventory());
    }

    @Test
    public void testAddBook2() {
        assertEquals(Map.of(), bookManagement.viewInventory());
    }

    @Test
    public void testAddBook3() {
        bookManagement.addBook("book1", 1);
        bookManagement.addBook("book1", 2);
        assertEquals(Map.of("book1", 3), bookManagement.viewInventory());
    }

    @Test
    public void testAddBook4() {
        bookManagement.addBook("book1", 2);
        assertEquals(Map.of("book1", 2), bookManagement.viewInventory());
    }

    @Test
    public void testAddBook5() {
        bookManagement.addBook("book1", 2);
        bookManagement.addBook("book1", 1);
        assertEquals(Map.of("book1", 3), bookManagement.viewInventory());
    }

    @Test
    public void testRemoveBook1() throws Exception {
        bookManagement.addBook("book1", 2);
        bookManagement.addBook("book2", 1);
        bookManagement.removeBook("book1", 2);
        assertEquals(Map.of("book2", 1), bookManagement.viewInventory());
    }

    @Test
    public void testRemoveBook2() throws Exception {
        bookManagement.addBook("book1", 2);
        bookManagement.addBook("book2", 1);
        bookManagement.removeBook("book1", 1);
        assertEquals(Map.of("book1", 1, "book2", 1), bookManagement.viewInventory());
    }

    @Test
    public void testRemoveBook3() {
        bookManagement.addBook("book1", 2);
        bookManagement.addBook("book2", 1);
        assertThrows(Exception.class, () -> bookManagement.removeBook("book3", 1));
    }

    @Test
    public void testRemoveBook4() {
        bookManagement.addBook("book1", 2);
        bookManagement.addBook("book2", 1);
        assertThrows(Exception.class, () -> bookManagement.removeBook("book2", 2));
    }

    @Test
    public void testRemoveBook5() {
        bookManagement.addBook("book1", 2);
        bookManagement.addBook("book2", 1);
        assertThrows(Exception.class, () -> bookManagement.removeBook("book2", 5));
    }

    @Test
    public void testViewInventory1() {
        bookManagement.addBook("book1", 2);
        bookManagement.addBook("book2", 1);
        assertEquals(Map.of("book1", 2, "book2", 1), bookManagement.viewInventory());
    }

    @Test
    public void testViewInventory2() {
        assertEquals(Map.of(), bookManagement.viewInventory());
    }

    @Test
    public void testViewInventory3() {
        bookManagement.addBook("book1", 2);
        bookManagement.addBook("book2", 1);
        assertEquals(Map.of("book1", 2, "book2", 1), bookManagement.viewInventory());
    }

    @Test
    public void testViewInventory4() throws Exception {
        bookManagement.addBook("book1", 2);
        bookManagement.addBook("book2", 1);
        bookManagement.removeBook("book1", 2);
        assertEquals(Map.of("book2", 1), bookManagement.viewInventory());
    }

    @Test
    public void testViewInventory5() throws Exception {
        bookManagement.addBook("book1", 2);
        bookManagement.addBook("book2", 1);
        bookManagement.removeBook("book1", 2);
        bookManagement.removeBook("book2", 1);
        assertEquals(Map.of(), bookManagement.viewInventory());
    }

    @Test
    public void testViewBookQuantity1() {
        bookManagement.addBook("book1", 2);
        assertEquals(2, bookManagement.viewBookQuantity("book1"));
    }

    @Test
    public void testViewBookQuantity2() {
        assertEquals(0, bookManagement.viewBookQuantity("book1"));
    }

    @Test
    public void testViewBookQuantity3() {
        bookManagement.addBook("book1", 2);
        assertEquals(2, bookManagement.viewBookQuantity("book1"));
    }

    @Test
    public void testViewBookQuantity4() throws Exception {
        bookManagement.addBook("book1", 2);
        bookManagement.removeBook("book1", 2);
        assertEquals(0, bookManagement.viewBookQuantity("book1"));
    }

    @Test
    public void testViewBookQuantity5() throws Exception {
        bookManagement.addBook("book1", 3);
        bookManagement.removeBook("book1", 2);
        assertEquals(1, bookManagement.viewBookQuantity("book1"));
    }
}