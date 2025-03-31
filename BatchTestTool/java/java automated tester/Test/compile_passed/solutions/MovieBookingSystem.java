// 导入的库
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

// MovieBookingSystem 类框架
public class MovieBookingSystem {
    // 成员变量
    private List<Movie> movies;  // 假设有一个Movie类

    // MovieBookingSystem 的构造函数
    public MovieBookingSystem() {
        this.movies = new ArrayList<>();
    }

    public void addMovie(String name, double price, String startTime, String endTime, int n) {
        // Create a Movie class object instead of a dictionary
        Movie movie = new Movie();
        movie.setName(name);
        movie.setPrice(price);

        // Parse time strings to LocalTime objects
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm");
        movie.setStartTime(LocalTime.parse(startTime, formatter));
        movie.setEndTime(LocalTime.parse(endTime, formatter));

        // Create a 2D array for seats
        int[][] seats = new int[n][n];
        // Initialize all seats to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                seats[i][j] = 0;
            }
        }
        movie.setSeats(seats);

        // Add movie to the list
        movies.add(movie);
    }

    public List<String> availableMovies(String startTime, String endTime) {
        // Create DateTimeFormatter for parsing time strings
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm");

        // Parse input strings to LocalTime
        LocalTime start = LocalTime.parse(startTime, formatter);
        LocalTime end = LocalTime.parse(endTime, formatter);

        // Create list to store available movie names
        List<String> availableMovies = new ArrayList<>();

        // Assuming movies is a List<Movie> or similar structure in the class
        for (Movie movie : movies) {
            if (start.compareTo(movie.getStartTime()) <= 0 &&
                movie.getEndTime().compareTo(end) <= 0) {
                availableMovies.add(movie.getName());
            }
        }

        return availableMovies;
    }

    public String bookTicket(String name, int[][] seatsToBook) {
        for (Movie movie : movies) {  // Assuming movies is a List<Movie>
            if (movie.getName().equals(name)) {
                for (int[] seat : seatsToBook) {
                    if (movie.getSeats()[seat[0]][seat[1]] == 0) {
                        movie.getSeats()[seat[0]][seat[1]] = 1;
                    } else {
                        return "Booking failed.";
                    }
                }
                return "Booking success.";
            }
        }
        return "Movie not found.";
    }
}

// You'll need to create a Movie class
class Movie {
    private String name;
    private double price;
    private LocalTime startTime;
    private LocalTime endTime;
    private int[][] seats;

    // Getters and setters
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public LocalTime getStartTime() {
        return startTime;
    }

    public void setStartTime(LocalTime startTime) {
        this.startTime = startTime;
    }

    public LocalTime getEndTime() {
        return endTime;
    }

    public void setEndTime(LocalTime endTime) {
        this.endTime = endTime;
    }

    public int[][] getSeats() {
        return seats;
    }

    public void setSeats(int[][] seats) {
        this.seats = seats;
    }
}