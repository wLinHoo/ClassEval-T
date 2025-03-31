
#include <sstream>
#include <iomanip>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>
#include <ctime>

class MovieBookingSystem {
public:
    MovieBookingSystem();

    void add_movie(const std::string& name, double price, const std::string& start_time, const std::string& end_time, int n);
    std::string book_ticket(const std::string& name, const std::vector<std::pair<int, int>>& seats);
    std::vector<std::string> available_movies(const std::string& start_time, const std::string& end_time) const;

    struct Movie {
        std::string name;
        double price;
        std::tm start_time;
        std::tm end_time;
        std::vector<std::vector<int>> seats;
    };

    std::vector<Movie> movies;

    std::tm parse_time(const std::string& time_str) const;
    bool is_time_in_range(const std::tm& start, const std::tm& end, const std::tm& check) const;
};


std::tm MovieBookingSystem::parse_time(const std::string& time_str) const {
    std::tm tm = {};
    std::istringstream ss(time_str);
    ss >> std::get_time(&tm, "%H:%M");
    if (ss.fail()) {
        throw std::runtime_error("Failed to parse time");
    }
    return tm;
}


bool MovieBookingSystem::is_time_in_range(const std::tm& start, const std::tm& end, const std::tm& check) const {
    auto time_to_seconds = [](const std::tm& tm) -> int {
        return tm.tm_hour * 3600 + tm.tm_min * 60;
        };
    return time_to_seconds(start) <= time_to_seconds(check) && time_to_seconds(check) <= time_to_seconds(end);
}

MovieBookingSystem::MovieBookingSystem() {}

void MovieBookingSystem::add_movie(const std::string& name, double price, const std::string& start_time, const std::string& end_time, int n) {
    Movie movie;
    movie.name = name;
    movie.price = price;
    movie.start_time = parse_time(start_time);
    movie.end_time = parse_time(end_time);
    movie.seats.resize(n, std::vector<int>(n, 0));
    movies.push_back(movie);
}

std::string MovieBookingSystem::book_ticket(const std::string& name, const std::vector<std::pair<int, int>>& seats_to_book) {
    for (auto& movie : movies) {
        if (movie.name == name) {
            for (const auto& seat : seats_to_book) {
                int row = seat.first;
                int col = seat.second;
                if (row >= 0 && row < movie.seats.size() && col >= 0 && col < movie.seats[row].size()) {
                    if (movie.seats[row][col] == 0) {
                        movie.seats[row][col] = 1;
                    }
                    else {
                        return "Booking failed.";
                    }
                }
                else {
                    return "Booking failed."; 
                }
            }
            return "Booking success.";
        }
    }
    return "Movie not found.";
}

std::vector<std::string> MovieBookingSystem::available_movies(const std::string& start_time, const std::string& end_time) const {
    std::tm start = parse_time(start_time);
    std::tm end = parse_time(end_time);

    std::vector<std::string> available_movies;
    for (const auto& movie : movies) {
        if (is_time_in_range(start, end, movie.start_time) && is_time_in_range(start, end, movie.end_time)) {
            available_movies.push_back(movie.name);
        }
    }
    return available_movies;
}
