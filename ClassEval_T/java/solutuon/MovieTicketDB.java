package org.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class MovieTicketDB {
    private Connection connection;

    public MovieTicketDB(String dbName) {
        try {
            connection = DriverManager.getConnection("jdbc:sqlite:" + dbName);
            createTable();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private void createTable() {
        String sql = "CREATE TABLE IF NOT EXISTS tickets (" +
                "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
                "movie_name TEXT, " +
                "theater_name TEXT, " +
                "seat_number TEXT, " +
                "customer_name TEXT)";
        try (Statement stmt = connection.createStatement()) {
            stmt.execute(sql);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void insertTicket(String movieName, String theaterName, String seatNumber, String customerName) {
        String sql = "INSERT INTO tickets (movie_name, theater_name, seat_number, customer_name) VALUES (?, ?, ?, ?)";
        try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
            pstmt.setString(1, movieName);
            pstmt.setString(2, theaterName);
            pstmt.setString(3, seatNumber);
            pstmt.setString(4, customerName);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public List<Ticket> searchTicketsByCustomer(String customerName) {
        String sql = "SELECT * FROM tickets WHERE customer_name = ?";
        List<Ticket> tickets = new ArrayList<>();
        try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
            pstmt.setString(1, customerName);
            ResultSet rs = pstmt.executeQuery();
            while (rs.next()) {
                Ticket ticket = new Ticket(
                        rs.getInt("id"),
                        rs.getString("movie_name"),
                        rs.getString("theater_name"),
                        rs.getString("seat_number"),
                        rs.getString("customer_name")
                );
                tickets.add(ticket);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return tickets;
    }

    public void deleteTicket(int ticketId) {
        String sql = "DELETE FROM tickets WHERE id = ?";
        try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
            pstmt.setInt(1, ticketId);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void close() {
        try {
            if (connection != null && !connection.isClosed()) {
                connection.close();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public static class Ticket {
        private int id;
        private String movieName;
        private String theaterName;
        private String seatNumber;
        private String customerName;

        public Ticket(int id, String movieName, String theaterName, String seatNumber, String customerName) {
            this.id = id;
            this.movieName = movieName;
            this.theaterName = theaterName;
            this.seatNumber = seatNumber;
            this.customerName = customerName;
        }

        public int getId() {
            return id;
        }

        public String getMovieName() {
            return movieName;
        }

        public String getTheaterName() {
            return theaterName;
        }

        public String getSeatNumber() {
            return seatNumber;
        }

        public String getCustomerName() {
            return customerName;
        }
    }
}
