import java.sql.*;

public class UserLoginDB {
    private Connection connection;
    private PreparedStatement preparedStatement;
    private PreparedStatement searchUserStatement;
    private PreparedStatement validateUserStatement;

    public UserLoginDB(String dbName) throws SQLException, ClassNotFoundException {
        Class.forName("org.sqlite.JDBC");
        connection = DriverManager.getConnection("jdbc:sqlite:" + dbName);
        preparedStatement = connection.prepareStatement("DELETE FROM users WHERE username = ?");
        searchUserStatement = connection.prepareStatement("SELECT * FROM users WHERE username = ?");
        validateUserStatement = connection.prepareStatement("SELECT * FROM users WHERE username = ? AND password = ?");
        String query = "INSERT INTO users (username, password) VALUES (?, ?)";
        preparedStatement = connection.prepareStatement(query);
    }

    public void insertUser(String username, String password) throws SQLException {
        preparedStatement.setString(1, username);
        preparedStatement.setString(2, password);
        preparedStatement.executeUpdate();
        connection.commit();
    }

    public void deleteUserByUsername(String username) throws SQLException {
        preparedStatement.setString(1, username);
        preparedStatement.executeUpdate();
        connection.commit();
    }

    public Object[] searchUserByUsername(String username) throws SQLException {
        searchUserStatement.setString(1, username);
        ResultSet resultSet = searchUserStatement.executeQuery();
        if (resultSet.next()) {
            int columnCount = resultSet.getMetaData().getColumnCount();
            Object[] user = new Object[columnCount];
            for (int i = 0; i < columnCount; i++) {
                user[i] = resultSet.getObject(i + 1);
            }
            return user;
        }
        return null;
    }

    public boolean validateUserLogin(String username, String password) throws SQLException {
        Object[] user = searchUserByUsername(username);
        if (user != null && user[1].equals(password)) {
            return true;
        }
        return false;
    }
}