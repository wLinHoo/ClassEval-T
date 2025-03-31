package test_cases;
import to_be_tested.MovieTicketDB;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class MovieTicketDBTest {

    private String dbName = "test_database.db";
    private MovieTicketDB db;

    @BeforeEach
    public void setUp() {
        db = new MovieTicketDB(dbName);
    }

    @AfterEach
    public void tearDown() {
        db.close();
        try {
            Files.deleteIfExists(Paths.get(dbName));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Test
    public void testInsertTicket1() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "John Doe");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("John Doe");
        assertEquals(1, tickets.size());
        MovieTicketDB.Ticket ticket = tickets.get(0);
        assertEquals("Avengers: Endgame", ticket.getMovieName());
        assertEquals("Cinema 1", ticket.getTheaterName());
        assertEquals("A1", ticket.getSeatNumber());
        assertEquals("John Doe", ticket.getCustomerName());
    }

    @Test
    public void testInsertTicket2() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "aaa");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("aaa");
        assertEquals(1, tickets.size());
        MovieTicketDB.Ticket ticket = tickets.get(0);
        assertEquals("Avengers: Endgame", ticket.getMovieName());
        assertEquals("Cinema 1", ticket.getTheaterName());
        assertEquals("A1", ticket.getSeatNumber());
        assertEquals("aaa", ticket.getCustomerName());
    }

    @Test
    public void testInsertTicket3() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "bbb");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("bbb");
        assertEquals(1, tickets.size());
        MovieTicketDB.Ticket ticket = tickets.get(0);
        assertEquals("Avengers: Endgame", ticket.getMovieName());
        assertEquals("Cinema 1", ticket.getTheaterName());
        assertEquals("A1", ticket.getSeatNumber());
        assertEquals("bbb", ticket.getCustomerName());
    }

    @Test
    public void testInsertTicket4() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "ccc");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("ccc");
        assertEquals(1, tickets.size());
        MovieTicketDB.Ticket ticket = tickets.get(0);
        assertEquals("Avengers: Endgame", ticket.getMovieName());
        assertEquals("Cinema 1", ticket.getTheaterName());
        assertEquals("A1", ticket.getSeatNumber());
        assertEquals("ccc", ticket.getCustomerName());
    }

    @Test
    public void testInsertTicket5() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "ddd");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("ddd");
        assertEquals(1, tickets.size());
        MovieTicketDB.Ticket ticket = tickets.get(0);
        assertEquals("Avengers: Endgame", ticket.getMovieName());
        assertEquals("Cinema 1", ticket.getTheaterName());
        assertEquals("A1", ticket.getSeatNumber());
        assertEquals("ddd", ticket.getCustomerName());
    }

    @Test
    public void testSearchTicketsByCustomer1() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "John Doe");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("John Doe");
        assertEquals(1, tickets.size());
        MovieTicketDB.Ticket ticket = tickets.get(0);
        assertEquals("Avengers: Endgame", ticket.getMovieName());
        assertEquals("Cinema 1", ticket.getTheaterName());
        assertEquals("A1", ticket.getSeatNumber());
        assertEquals("John Doe", ticket.getCustomerName());
    }

    @Test
    public void testSearchTicketsByCustomer2() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "aaa");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("aaa");
        assertEquals(1, tickets.size());
        MovieTicketDB.Ticket ticket = tickets.get(0);
        assertEquals("Avengers: Endgame", ticket.getMovieName());
        assertEquals("Cinema 1", ticket.getTheaterName());
        assertEquals("A1", ticket.getSeatNumber());
        assertEquals("aaa", ticket.getCustomerName());
    }

    @Test
    public void testSearchTicketsByCustomer3() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "bbb");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("bbb");
        assertEquals(1, tickets.size());
        MovieTicketDB.Ticket ticket = tickets.get(0);
        assertEquals("Avengers: Endgame", ticket.getMovieName());
        assertEquals("Cinema 1", ticket.getTheaterName());
        assertEquals("A1", ticket.getSeatNumber());
        assertEquals("bbb", ticket.getCustomerName());
    }

    @Test
    public void testSearchTicketsByCustomer4() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "ccc");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("ccc");
        assertEquals(1, tickets.size());
        MovieTicketDB.Ticket ticket = tickets.get(0);
        assertEquals("Avengers: Endgame", ticket.getMovieName());
        assertEquals("Cinema 1", ticket.getTheaterName());
        assertEquals("A1", ticket.getSeatNumber());
        assertEquals("ccc", ticket.getCustomerName());
    }

    @Test
    public void testSearchTicketsByCustomer5() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "ddd");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("ddd");
        assertEquals(1, tickets.size());
        MovieTicketDB.Ticket ticket = tickets.get(0);
        assertEquals("Avengers: Endgame", ticket.getMovieName());
        assertEquals("Cinema 1", ticket.getTheaterName());
        assertEquals("A1", ticket.getSeatNumber());
        assertEquals("ddd", ticket.getCustomerName());
    }

    @Test
    public void testDeleteTicket1() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "John Doe");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("John Doe");
        assertEquals(1, tickets.size());
        int ticketId = tickets.get(0).getId();
        db.deleteTicket(ticketId);
        tickets = db.searchTicketsByCustomer("John Doe");
        assertEquals(0, tickets.size());
    }

    @Test
    public void testDeleteTicket2() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "aaa");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("aaa");
        assertEquals(1, tickets.size());
        int ticketId = tickets.get(0).getId();
        db.deleteTicket(ticketId);
        tickets = db.searchTicketsByCustomer("aaa");
        assertEquals(0, tickets.size());
    }

    @Test
    public void testDeleteTicket3() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "bbb");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("bbb");
        assertEquals(1, tickets.size());
        int ticketId = tickets.get(0).getId();
        db.deleteTicket(ticketId);
        tickets = db.searchTicketsByCustomer("bbb");
        assertEquals(0, tickets.size());
    }

    @Test
    public void testDeleteTicket4() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "ccc");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("ccc");
        assertEquals(1, tickets.size());
        int ticketId = tickets.get(0).getId();
        db.deleteTicket(ticketId);
        tickets = db.searchTicketsByCustomer("ccc");
        assertEquals(0, tickets.size());
    }

    @Test
    public void testDeleteTicket5() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "ddd");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("ddd");
        assertEquals(1, tickets.size());
        int ticketId = tickets.get(0).getId();
        db.deleteTicket(ticketId);
        tickets = db.searchTicketsByCustomer("ddd");
        assertEquals(0, tickets.size());
    }

    @Test
    public void testMovieTicketDB() {
        db.insertTicket("Avengers: Endgame", "Cinema 1", "A1", "John Doe");
        List<MovieTicketDB.Ticket> tickets = db.searchTicketsByCustomer("John Doe");
        assertEquals(1, tickets.size());
        MovieTicketDB.Ticket ticket = tickets.get(0);
        assertEquals("Avengers: Endgame", ticket.getMovieName());
        assertEquals("Cinema 1", ticket.getTheaterName());
        assertEquals("A1", ticket.getSeatNumber());
        assertEquals("John Doe", ticket.getCustomerName());
        int ticketId = tickets.get(0).getId();
        db.deleteTicket(ticketId);
        tickets = db.searchTicketsByCustomer("John Doe");
        assertEquals(0, tickets.size());
    }
}
