package to_be_tested;

import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.text.ParseException;
import java.text.SimpleDateFormat;

public class MovieBookingSystem {

    public List<Map<String, Object>> movies;

    public MovieBookingSystem() {
        this.movies = new ArrayList<>();
    }

    public String bookTicket(String name, List<int[]> seatsToBook) {
        for (Map<String, Object> movie : movies) {
            if (name.equals(movie.get("name"))) {
                for (int[] seat : seatsToBook) {
                    if ((int[]) movie.get("seats").get(seat[0]).get(seat[1]) == 0) {
                        ((Map<Integer, Object>) movie.get("seats")).put(seat[0], ((Map<Integer, Object>) movie.get("seats")).get(seat[0]).replace(seat[1], 1));
                    } else {
                        return "Booking failed.";
                    }
                }
                return "Booking success.";
            }
        }
        return "Movie not found.";
    }

    public static void main(String[] args) {
        MovieBookingSystem movieBookingSystem = new MovieBookingSystem();
        // Add movies
        Map<String, Object> movie1 = new HashMap<>();
        movie1.put("name", "Movie1");
        Map<Integer, Object> seats1 = new HashMap<>();
        seats1.put(0, new HashMap<>());
        seats1.put(1, new HashMap<>());
        movie1.put("seats", seats1);
        movieBookingSystem.movies.add(movie1);
        Map<String, Object> movie2 = new HashMap<>();
        movie2.put("name", "Movie2");
        Map<Integer, Object> seats2 = new HashMap<>();
        seats2.put(0, new HashMap<>());
        seats2.put(1, new HashMap<>());
        movie2.put("seats", seats2);
        movieBookingSystem.movies.add(movie2);
        // Book tickets
        System.out.println(movieBookingSystem.bookTicket("Movie1", new int[][] { { 0, 0 } }));
        System.out.println(movieBookingSystem.bookTicket("Movie1", new int[][] { { 0, 0 }, { 1, 1 } }));
        System.out.println(movieBookingSystem.bookTicket("Movie2", new int[][] { { 0, 0 } }));
    }

    public ArrayList<Movie> movies = new ArrayList<>();

    public MovieBookingSystem() {
        // No-op
    }

    public String[] availableMovies(String start, String end) throws ParseException {
        SimpleDateFormat dateFormat = new SimpleDateFormat("HH:mm");
        Date startDateTime = dateFormat.parse(start);
        Date endDateTime = dateFormat.parse(end);
        ArrayList<String> availableMovies = new ArrayList<>();
        for (Movie movie : movies) {
            if (startDateTime.before(movie.getEndDateTime()) && endDateTime.after(movie.getStartDateTime())) {
                availableMovies.add(movie.getName());
            }
        }
        return availableMovies.toArray(new String[0]);
    }

    public void addMovie(String name, double price, String startTime, String endTime, int n) {
        Movie movie = new Movie(name, price);
        try {
            SimpleDateFormat simpleDateFormat = new SimpleDateFormat("HH:mm");
            Date startDate = simpleDateFormat.parse(startTime);
            Date endDate = simpleDateFormat.parse(endTime);
            movie.setStartTime(startDate);
            movie.setEndTime(endDate);
            movie.setSeats(new int[n][n]);
        } catch (ParseException e) {
            System.out.println("Invalid time format. Please use HH:mm.");
        }
        movies.add(movie);
    }

    public class Movie {

        public String name;

        public double price;

        public Date startTime;

        public Date endTime;

        public int[][] seats;

        public Movie(String name, double price) {
            this.name = name;
            this.price = price;
        }

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

        public Date getStartTime() {
            return startTime;
        }

        public void setStartTime(Date startTime) {
            this.startTime = startTime;
        }

        public Date getEndTime() {
            return endTime;
        }

        public void setEndTime(Date endTime) {
            this.endTime = endTime;
        }

        public int[][] getSeats() {
            return seats;
        }

        public void setSeats(int[][] seats) {
            this.seats = seats;
        }
    }
}

public class Movie {

    public String name;

    public Date startDateTime;

    public Date endDateTime;

    public Movie(String name, Date startDateTime, Date endDateTime) {
        this.name = name;
        this.startDateTime = startDateTime;
        this.endDateTime = endDateTime;
    }

    public String getName() {
        return name;
    }

    public Date getStartDateTime() {
        return startDateTime;
    }

    public Date getEndDateTime() {
        return endDateTime;
    }
}
