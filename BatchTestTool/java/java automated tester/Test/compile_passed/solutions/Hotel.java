import java.util.HashMap;
import java.util.Map;

public class Hotel {
    private String name;
    private Map<String, Integer> availableRooms;
    private Map<String, Map<String, Integer>> bookedRooms;

    public Hotel(String name, Map<String, Integer> rooms) {
        this.name = name;
        this.availableRooms = rooms;
        this.bookedRooms = new HashMap<>();
    }

    public boolean checkIn(String roomType, int roomNumber, String name) {
        if (!bookedRooms.containsKey(roomType)) {
            return false;
        }
        if (bookedRooms.get(roomType).containsKey(name)) {
            if (roomNumber > bookedRooms.get(roomType).get(name)) {
                return false;
            } else if (roomNumber == bookedRooms.get(roomType).get(name)) {
                bookedRooms.get(roomType).remove(name);
            } else {
                bookedRooms.get(roomType).put(name, bookedRooms.get(roomType).get(name) - roomNumber);
            }
        }
        return true;
    }

    public void checkOut(String roomType, int roomNumber) {
        if (availableRooms.containsKey(roomType)) {
            availableRooms.put(roomType, availableRooms.get(roomType) + roomNumber);
        } else {
            availableRooms.put(roomType, roomNumber);
        }
    }

    public int getAvailableRooms(String roomType) {
        return availableRooms.get(roomType);
    }

    public String bookRoom(String roomType, int roomNumber, String name) {
        if (!availableRooms.containsKey(roomType)) {
            return "Room type not available";
        }

        if (roomNumber <= availableRooms.get(roomType)) {
            if (!bookedRooms.containsKey(roomType)) {
                bookedRooms.put(roomType, new HashMap<>());
            }
            bookedRooms.get(roomType).put(name, roomNumber);
            availableRooms.put(roomType, availableRooms.get(roomType) - roomNumber);
            return "Success!";
        } else if (availableRooms.get(roomType) != 0) {
            return "Only " + availableRooms.get(roomType) + " rooms left";
        } else {
            return "No rooms available";
        }
    }
}