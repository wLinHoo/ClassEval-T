package org.example;

import java.util.HashMap;
import java.util.Map;

public class Hotel {
    private String name;
    Map<String, Integer> availableRooms;
    Map<String, Map<String, Integer>> bookedRooms;

    public Hotel(String name, Map<String, Integer> rooms) {
        this.name = name;
        this.availableRooms = new HashMap<>(rooms);
        this.bookedRooms = new HashMap<>();
    }

    public String bookRoom(String roomType, int roomNumber, String name) {
        if (!availableRooms.containsKey(roomType)) {
            return "False";
        }

        int available = availableRooms.get(roomType);
        if (roomNumber <= available) {
            bookedRooms.putIfAbsent(roomType, new HashMap<>());
            bookedRooms.get(roomType).put(name, roomNumber);
            availableRooms.put(roomType, available - roomNumber);
            return "Success!";
        } else {
            return "False";
        }
    }

    public boolean checkIn(String roomType, int roomNumber, String name) {
        if (!bookedRooms.containsKey(roomType) || !bookedRooms.get(roomType).containsKey(name)) {
            return false;
        }

        int booked = bookedRooms.get(roomType).get(name);
        if (roomNumber > booked) {
            return false;
        } else if (roomNumber == booked) {
            bookedRooms.get(roomType).remove(name);
        } else {
            bookedRooms.get(roomType).put(name, booked - roomNumber);
        }
        return true;
    }

    public void checkOut(String roomType, int roomNumber) {
        availableRooms.put(roomType, availableRooms.getOrDefault(roomType, 0) + roomNumber);
    }

    public int getAvailableRooms(String roomType) {
        return availableRooms.getOrDefault(roomType, 0);
    }

    public static void main(String[] args) {
        Map<String, Integer> rooms = new HashMap<>();
        rooms.put("single", 3);
        rooms.put("double", 2);
        Hotel hotel = new Hotel("Test Hotel", rooms);

        System.out.println(hotel.bookRoom("single", 2, "guest 1"));
        System.out.println(hotel.bookRoom("triple", 2, "guest 1"));
        System.out.println(hotel.bookRoom("single", 2, "guest 2"));
        System.out.println(hotel.bookRoom("single", 1, "guest 2"));
        System.out.println(hotel.bookRoom("single", 3, "guest 1"));
        System.out.println(hotel.bookRoom("single", 100, "guest 1"));

        hotel.checkIn("single", 1, "guest 1");
        System.out.println(hotel.bookedRooms);
        System.out.println(hotel.checkIn("single", 3, "guest 1"));
        System.out.println(hotel.checkIn("double", 1, "guest 1"));
        hotel.checkIn("double", 1, "guest 2");
        System.out.println(hotel.bookedRooms);

        hotel.checkOut("single", 1);
        System.out.println(hotel.availableRooms);
        hotel.checkOut("triple", 2);
        System.out.println(hotel.availableRooms);

        System.out.println(hotel.getAvailableRooms("single"));
    }
}