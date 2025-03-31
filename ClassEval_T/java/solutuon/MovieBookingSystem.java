package org.example;

import java.time.LocalTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class MovieBookingSystem {

    private List<Map<String, Object>> movies;

    public MovieBookingSystem() {
        this.movies = new ArrayList<>();
    }

    public void addMovie(String name, double price, String startTime, String endTime, int n) {
        Map<String, Object> movie = new HashMap<>();
        movie.put("name", name);
        movie.put("price", price);
        movie.put("start_time", LocalTime.parse(startTime));
        movie.put("end_time", LocalTime.parse(endTime));
        movie.put("seats", new int[n][n]);
        movies.add(movie);
    }

    public String bookTicket(String name, int[][] seatsToBook) {
        for (Map<String, Object> movie : movies) {
            if (movie.get("name").equals(name)) {
                int[][] seats = (int[][]) movie.get("seats");
                for (int[] seat : seatsToBook) {
                    int row = seat[0];
                    int col = seat[1];
                    if (seats[row][col] == 0) {
                        seats[row][col] = 1;
                    } else {
                        return "Booking failed.";
                    }
                }
                return "Booking success.";
            }
        }
        return "Movie not found.";
    }

    public List<String> availableMovies(String startTime, String endTime) {
        LocalTime start = LocalTime.parse(startTime);
        LocalTime end = LocalTime.parse(endTime);

        return movies.stream()
                .filter(movie -> {
                    LocalTime movieStart = (LocalTime) movie.get("start_time");
                    LocalTime movieEnd = (LocalTime) movie.get("end_time");
                    return !movieStart.isBefore(start) && !movieEnd.isAfter(end);
                })
                .map(movie -> (String) movie.get("name"))
                .collect(Collectors.toList());
    }

    public List<Map<String, Object>> getMovies() {
        return movies;
    }
}
