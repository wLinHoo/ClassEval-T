package test_cases;
import to_be_tested.Hotel;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.util.HashMap;
import java.util.Map;
import static org.junit.jupiter.api.Assertions.*;

public class HotelTest {
    private Hotel hotel;

    @BeforeEach
    public void setUp() {
        Map<String, Integer> rooms = new HashMap<>();
        rooms.put("single", 3);
        rooms.put("double", 2);
        hotel = new Hotel("Test Hotel", rooms);
    }

    @Test
    public void testBookRoom1() {
        assertEquals("Success!", hotel.bookRoom("single", 2, "guest 1"));
        assertEquals(Map.of("single", Map.of("guest 1", 2)), hotel.bookedRooms);
        assertEquals(Map.of("single", 1, "double", 2), hotel.availableRooms);
    }

    @Test
    public void testBookRoom2() {
        assertEquals("False", hotel.bookRoom("triple", 2, "guest 1"));
        assertEquals(Map.of(), hotel.bookedRooms);
        assertEquals(Map.of("single", 3, "double", 2), hotel.availableRooms);
    }

    @Test
    public void testBookRoom3() {
        hotel.bookRoom("single", 2, "guest 1");
        assertEquals("False", hotel.bookRoom("single", 2, "guest 2"));
        assertEquals(Map.of("single", Map.of("guest 1", 2)), hotel.bookedRooms);
        assertEquals(Map.of("single", 1, "double", 2), hotel.availableRooms);
    }

    @Test
    public void testBookRoom4() {
        hotel.bookRoom("single", 2, "guest 1");
        assertEquals("Success!", hotel.bookRoom("single", 1, "guest 2"));
        assertEquals(Map.of("single", Map.of("guest 1", 2, "guest 2", 1)), hotel.bookedRooms);
        assertEquals(Map.of("single", 0, "double", 2), hotel.availableRooms);
    }

    @Test
    public void testBookRoom5() {
        hotel.bookRoom("single", 2, "guest 1");
        assertEquals("False", hotel.bookRoom("single", 3, "guest 2"));
        assertEquals(Map.of("single", Map.of("guest 1", 2)), hotel.bookedRooms);
        assertEquals(Map.of("single", 1, "double", 2), hotel.availableRooms);
    }

    @Test
    public void testBookRoom6() {
        hotel.bookRoom("single", 3, "guest 1");
        assertEquals("False", hotel.bookRoom("single", 100, "guest 1"));
    }

    @Test
    public void testCheckIn1() {
        hotel.bookRoom("single", 2, "guest 1");
        assertTrue(hotel.checkIn("single", 1, "guest 1"));
        assertEquals(Map.of("single", Map.of("guest 1", 1)), hotel.bookedRooms);
    }

    @Test
    public void testCheckIn2() {
        hotel.bookRoom("single", 2, "guest 1");
        assertFalse(hotel.checkIn("single", 3, "guest 1"));
        assertEquals(Map.of("single", Map.of("guest 1", 2)), hotel.bookedRooms);
    }

    @Test
    public void testCheckIn3() {
        hotel.bookRoom("single", 2, "guest 1");
        assertFalse(hotel.checkIn("double", 1, "guest 1"));
        assertEquals(Map.of("single", Map.of("guest 1", 2)), hotel.bookedRooms);
    }

    @Test
    public void testCheckIn4() {
        hotel.bookRoom("double", 1, "guest 2");
        assertTrue(hotel.checkIn("double", 1, "guest 2"));
        assertEquals(Map.of("double", Map.of()), hotel.bookedRooms);
    }

    @Test
    public void testCheckIn5() {
        hotel.bookRoom("double", 1, "guest 2");
        assertFalse(hotel.checkIn("double", 2, "guest 2"));
        assertEquals(Map.of("double", Map.of("guest 2", 1)), hotel.bookedRooms);
    }

    @Test
    public void testCheckIn6() {
        assertFalse(hotel.checkIn("abc", 1, "guest 1"));
    }

    @Test
    public void testCheckOut1() {
        hotel.checkOut("single", 1);
        assertEquals(Map.of("single", 4, "double", 2), hotel.availableRooms);
    }

    @Test
    public void testCheckOut2() {
        hotel.checkOut("single", 3);
        assertEquals(Map.of("single", 6, "double", 2), hotel.availableRooms);
    }

    @Test
    public void testCheckOut3() {
        hotel.checkOut("triple", 2);
        assertEquals(Map.of("single", 3, "double", 2, "triple", 2), hotel.availableRooms);
    }

    @Test
    public void testCheckOut4() {
        hotel.checkOut("double", 1);
        assertEquals(Map.of("single", 3, "double", 3), hotel.availableRooms);
    }

    @Test
    public void testCheckOut5() {
        hotel.checkOut("double", 2);
        assertEquals(Map.of("single", 3, "double", 4), hotel.availableRooms);
    }

    @Test
    public void testGetAvailableRooms() {
        assertEquals(3, hotel.getAvailableRooms("single"));
    }

    @Test
    public void testGetAvailableRooms2() {
        hotel.bookRoom("single", 2, "guest 1");
        assertEquals(1, hotel.getAvailableRooms("single"));
    }

    @Test
    public void testGetAvailableRooms3() {
        hotel.bookRoom("single", 3, "guest 1");
        assertEquals(0, hotel.getAvailableRooms("single"));
    }

    @Test
    public void testGetAvailableRooms4() {
        hotel.bookRoom("single", 3, "guest 1");
        assertEquals(2, hotel.getAvailableRooms("double"));
    }

    @Test
    public void testGetAvailableRooms5() {
        hotel.bookRoom("single", 3, "guest 1");
        assertEquals(0, hotel.getAvailableRooms("triple"));
    }

    @Test
    public void testMain() {
        assertEquals("Success!", hotel.bookRoom("single", 2, "guest 1"));
        assertEquals(Map.of("single", Map.of("guest 1", 2)), hotel.bookedRooms);
        assertEquals(Map.of("single", 1, "double", 2), hotel.availableRooms);

        assertTrue(hotel.checkIn("single", 2, "guest 1"));
        assertEquals(Map.of("single", Map.of()), hotel.bookedRooms);
        assertEquals(Map.of("single", 1, "double", 2), hotel.availableRooms);

        hotel.checkOut("single", 2);
        assertEquals(Map.of("single", 3, "double", 2), hotel.availableRooms);

        assertEquals(3, hotel.getAvailableRooms("single"));
    }
}