package to_be_tested;

import java.sql.*;

public class StudentDatabaseProcessor {

    public String databaseName;

    public StudentDatabaseProcessor(String databaseName) {
        this.databaseName = databaseName;
    }

    public void insertStudent(StudentData studentData) throws SQLException {
        Connection conn = DriverManager.getConnection("jdbc:sqlite:" + databaseName);
        Statement stmt = conn.createStatement();
        String insertQuery = "INSERT INTO students (name, age, gender, grade) VALUES (?, ?, ?, ?)";
        PreparedStatement pstmt = conn.prepareStatement(insertQuery);
        pstmt.setString(1, studentData.getName());
        pstmt.setInt(2, studentData.getAge());
        pstmt.setString(3, studentData.getGender());
        pstmt.setInt(4, studentData.getGrade());
        pstmt.executeUpdate();
        conn.close();
    }

    public ResultSet searchStudentByName(String name) throws SQLException {
        Connection conn = DriverManager.getConnection("jdbc:sqlite:" + databaseName);
        Statement stmt = conn.createStatement();
        ResultSet result = stmt.executeQuery("SELECT * FROM students WHERE name = '" + name + "'");
        conn.close();
        return result;
    }

    public void deleteStudentByName(String name) {
        try (Connection conn = DriverManager.getConnection("jdbc:sqlite:" + databaseName);
            Statement stmt = conn.createStatement()) {
            String deleteQuery = "DELETE FROM students WHERE name = ?";
            PreparedStatement pstmt = conn.prepareStatement(deleteQuery);
            pstmt.setString(1, name);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }

    public void createStudentTable() throws SQLException {
        Connection conn = DriverManager.getConnection("jdbc:sqlite:" + databaseName);
        Statement stmt = conn.createStatement();
        String createTableQuery = "CREATE TABLE IF NOT EXISTS students (id INTEGER PRIMARY KEY, name TEXT, age INTEGER);";
        stmt.execute(createTableQuery);
        conn.commit();
        conn.close();
    }
}

public class StudentData {

    public String name;

    public int age;

    public String gender;

    public int grade;

    public StudentData(String name, int age, String gender, int grade) {
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.grade = grade;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public String getGender() {
        return gender;
    }

    public int getGrade() {
        return grade;
    }
}
