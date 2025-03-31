import java.sql.*;

public class MovieTicketDB {
    private Connection connection;
    private Statement statement;

    public MovieTicketDB(String dbName) throws SQLException {
        connection = DriverManager.getConnection("jdbc:sqlite:" + dbName);
        statement = connection.createStatement();
        createTable();
    }

    private void createTable() throws SQLException {
        statement.execute("CREATE TABLE IF NOT EXISTS tickets (id INTEGER PRIMARY KEY, customer_name TEXT)");
    }

    public ResultSet searchTicketsByCustomer(String customerName) throws SQLException {
        PreparedStatement preparedStatement = connection.prepareStatement("SELECT * FROM tickets WHERE customer_name = ?");
        preparedStatement.setString(1, customerName);
        return preparedStatement.executeQuery();
    }

    public void deleteTicket(int ticketId) throws SQLException {
        PreparedStatement preparedStatement = connection.prepareStatement("DELETE FROM tickets WHERE id = ?");
        preparedStatement.setInt(1, ticketId);
        preparedStatement.execute();
        connection.commit();
    }

    public void insertTicket(String movieName, String theaterName, String seatNumber, String customerName) throws SQLException {
        PreparedStatement preparedStatement = connection.prepareStatement("INSERT INTO tickets (movie_name, theater_name, seat_number, customer_name) VALUES (?, ?, ?, ?)");
        preparedStatement.setString(1, movieName);
        preparedStatement.setString(2, theaterName);
        preparedStatement.setString(3, seatNumber);
        preparedStatement.setString(4, customerName);
        preparedStatement.executeUpdate();
    }
}