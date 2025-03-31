package test_cases;
import to_be_tested.MovieBookingSystem;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.time.LocalTime;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertArrayEquals;

public class MovieBookingSystemTestAddMovie {
    private MovieBookingSystem system;

    @BeforeEach
    void setUp() {
        system = new MovieBookingSystem();
    }

    @AfterEach
    void tearDown() {
        system = null;
    }

    @Test
    void testAddMovie1() {
        system.addMovie("Batman", 49.9, "17:05", "19:25", 3);
        assertEquals(1, system.getMovies().size());
        Map<String, Object> movie = system.getMovies().get(0);
        assertEquals("Batman", movie.get("name"));
        assertEquals(49.9, movie.get("price"));
        assertEquals(LocalTime.parse("17:05"), movie.get("start_time"));
        assertEquals(LocalTime.parse("19:25"), movie.get("end_time"));
        int[][] seats = (int[][]) movie.get("seats");
        assertArrayEquals(new int[][]{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, seats);
    }

    @Test
    void testAddMovie2() {
        system.addMovie("Batman", 49.9, "17:05", "19:25", 3);
        system.addMovie("Superman", 49.9, "17:05", "19:25", 3);
        assertEquals(2, system.getMovies().size());
        assertEquals("Batman", system.getMovies().get(0).get("name"));
        assertEquals("Superman", system.getMovies().get(1).get("name"));
    }

    @Test
    void testAddMovie3() {
        system.addMovie("Batman", 39.9, "17:05", "19:25", 3);
        assertEquals(1, system.getMovies().size());
        Map<String, Object> movie = system.getMovies().get(0);
        assertEquals("Batman", movie.get("name"));
        assertEquals(39.9, movie.get("price"));
        assertEquals(LocalTime.parse("17:05"), movie.get("start_time"));
        assertEquals(LocalTime.parse("19:25"), movie.get("end_time"));
        int[][] seats = (int[][]) movie.get("seats");
        assertArrayEquals(new int[][]{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, seats);
    }

    @Test
    void testAddMovie4() {
        system.addMovie("Batman", 29.9, "17:05", "19:25", 3);
        assertEquals(1, system.getMovies().size());
        Map<String, Object> movie = system.getMovies().get(0);
        assertEquals("Batman", movie.get("name"));
        assertEquals(29.9, movie.get("price"));
        assertEquals(LocalTime.parse("17:05"), movie.get("start_time"));
        assertEquals(LocalTime.parse("19:25"), movie.get("end_time"));
        int[][] seats = (int[][]) movie.get("seats");
        assertArrayEquals(new int[][]{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, seats);
    }

    @Test
    void testAddMovie5() {
        system.addMovie("Batman", 19.9, "17:05", "19:25", 3);
        assertEquals(1, system.getMovies().size());
        Map<String, Object> movie = system.getMovies().get(0);
        assertEquals("Batman", movie.get("name"));
        assertEquals(19.9, movie.get("price"));
        assertEquals(LocalTime.parse("17:05"), movie.get("start_time"));
        assertEquals(LocalTime.parse("19:25"), movie.get("end_time"));
        int[][] seats = (int[][]) movie.get("seats");
        assertArrayEquals(new int[][]{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, seats);
    }
}

class MovieBookingSystemTestBookTicket {
    private MovieBookingSystem system;

    @BeforeEach
    void setUp() {
        system = new MovieBookingSystem();
        system.addMovie("Batman", 49.9, "17:05", "19:25", 3);
    }

    @Test
    void testBookTicket1() {
        int[][] seatsToBook = {{0, 0}, {1, 1}, {2, 2}};
        String result = system.bookTicket("Batman", seatsToBook);
        assertEquals("Booking success.", result);
        int[][] seats = (int[][]) system.getMovies().get(0).get("seats");
        assertEquals(1, seats[0][0]);
        assertEquals(1, seats[1][1]);
        assertEquals(1, seats[2][2]);
    }

    @Test
    void testBookTicket2() {
        system.bookTicket("Batman", new int[][]{{0, 0}});
        String result = system.bookTicket("Batman", new int[][]{{0, 0}});
        assertEquals("Booking failed.", result);
        int[][] seats = (int[][]) system.getMovies().get(0).get("seats");
        assertEquals(1, seats[0][0]);
    }

    @Test
    void testBookTicket3() {
        String result = system.bookTicket("batman", new int[][]{{0, 0}});
        assertEquals("Movie not found.", result);
        int[][] seats = (int[][]) system.getMovies().get(0).get("seats");
        assertEquals(0, seats[0][0]);
    }

    @Test
    void testBookTicket4() {
        String result = system.bookTicket("Batman", new int[][]{{0, 0}, {1, 1}});
        assertEquals("Booking success.", result);
        int[][] seats = (int[][]) system.getMovies().get(0).get("seats");
        assertEquals(1, seats[0][0]);
        assertEquals(1, seats[1][1]);
    }

    @Test
    void testBookTicket5() {
        String result = system.bookTicket("Batman", new int[][]{{0, 0}});
        assertEquals("Booking success.", result);
        int[][] seats = (int[][]) system.getMovies().get(0).get("seats");
        assertEquals(1, seats[0][0]);
    }
}

class MovieBookingSystemTestAvailableMovies {
    private MovieBookingSystem system;

    @BeforeEach
    void setUp() {
        system = new MovieBookingSystem();
        system.addMovie("Batman", 49.9, "17:05", "19:25", 3);
        system.addMovie("Spiderman", 59.9, "20:00", "22:30", 4);
    }

    @Test
    void testAvailableMovies1() {
        List<String> result = system.availableMovies("16:00", "23:00");
        assertEquals(List.of("Batman", "Spiderman"), result);
    }

    @Test
    void testAvailableMovies2() {
        List<String> result = system.availableMovies("23:00", "23:59");
        assertEquals(List.of(), result);
    }

    @Test
    void testAvailableMovies3() {
        List<String> result = system.availableMovies("17:00", "20:00");
        assertEquals(List.of("Batman"), result);
    }

    @Test
    void testAvailableMovies4() {
        List<String> result = system.availableMovies("10:00", "23:00");
        assertEquals(List.of("Batman", "Spiderman"), result);
    }

    @Test
    void testAvailableMovies5() {
        List<String> result = system.availableMovies("20:00", "23:00");
        assertEquals(List.of("Spiderman"), result);
    }
}

class MovieBookingSystemTestMain {
    @Test
    void testMain() {
        MovieBookingSystem system = new MovieBookingSystem();
        system.addMovie("Batman", 49.9, "17:05", "19:25", 3);
        assertEquals(1, system.getMovies().size());
        Map<String, Object> movie = system.getMovies().get(0);
        assertEquals("Batman", movie.get("name"));
        assertEquals(49.9, movie.get("price"));
        assertEquals(LocalTime.parse("17:05"), movie.get("start_time"));
        assertEquals(LocalTime.parse("19:25"), movie.get("end_time"));
        int[][] seats = (int[][]) movie.get("seats");
        assertArrayEquals(new int[][]{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, seats);

        int[][] seatsToBook = {{0, 0}, {1, 1}, {2, 2}};
        String result = system.bookTicket("Batman", seatsToBook);
        assertEquals("Booking success.", result);
        assertEquals(1, seats[0][0]);
        assertEquals(1, seats[1][1]);
        assertEquals(1, seats[2][2]);

        List<String> availableMovies = system.availableMovies("16:00", "23:00");
        assertEquals(List.of("Batman"), availableMovies);
    }
}
