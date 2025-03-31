#include <string>
#include <unordered_map>

class Hotel {
public:
    Hotel(const std::string& name, const std::unordered_map<std::string, int>& rooms);

    std::string book_room(const std::string& room_type, int room_number, const std::string& name);
    bool check_in(const std::string& room_type, int room_number, const std::string& name);
    void check_out(const std::string& room_type, int room_number);
    int get_available_rooms(const std::string& room_type) const;
    std::string name;
    std::unordered_map<std::string, int> available_rooms;
    std::unordered_map<std::string, std::unordered_map<std::string, int>> booked_rooms;
};

Hotel::Hotel(const std::string& name, const std::unordered_map<std::string, int>& rooms)
    : name(name), available_rooms(rooms) {}

std::string Hotel::book_room(const std::string& room_type, int room_number, const std::string& name) {
    if (available_rooms.find(room_type) == available_rooms.end()) {
        return "False.";
    }

    if (room_number <= available_rooms[room_type]) {
        if (booked_rooms.find(room_type) == booked_rooms.end()) {
            booked_rooms[room_type] = {};
        }
        booked_rooms[room_type][name] = room_number;
        available_rooms[room_type] -= room_number;
        return "Success!";
    }
    else if (available_rooms[room_type] != 0) {
        return std::to_string(available_rooms[room_type]);
    }
    else {
        return "False.";
    }
}

bool Hotel::check_in(const std::string& room_type, int room_number, const std::string& name) {
    if (booked_rooms.find(room_type) == booked_rooms.end()) {
        return false;
    }

    if (booked_rooms[room_type].find(name) != booked_rooms[room_type].end()) {
        if (room_number > booked_rooms[room_type][name]) {
            return false;
        }
        else if (room_number == booked_rooms[room_type][name]) {
            booked_rooms[room_type].erase(name);
        }
        else {
            booked_rooms[room_type][name] -= room_number;
        }
        return true;
    }
    return false;
}

void Hotel::check_out(const std::string& room_type, int room_number) {
    if (available_rooms.find(room_type) != available_rooms.end()) {
        available_rooms[room_type] += room_number;
    }
    else {
        available_rooms[room_type] = room_number;
    }
}

int Hotel::get_available_rooms(const std::string& room_type) const {
    auto it = available_rooms.find(room_type);
    if (it != available_rooms.end()) {
        return it->second;
    }
    return 0;
}
