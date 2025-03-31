package org.example;

import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class StudentDatabaseProcessor {
    private String databaseName;

    public StudentDatabaseProcessor(String databaseName) {
        this.databaseName = databaseName;
    }

    public void createStudentTable() {
        String createTableQuery = "CREATE TABLE IF NOT EXISTS students ("
                + "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                + "name TEXT, "
                + "age INTEGER, "
                + "gender TEXT, "
                + "grade INTEGER"
                + ")";
        try (Connection conn = getConnection();
             Statement stmt = conn.createStatement()) {
            stmt.execute(createTableQuery);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void insertStudent(StudentData studentData) {
        String insertQuery = "INSERT INTO students (name, age, gender, grade) VALUES (?, ?, ?, ?)";
        try (Connection conn = getConnection();
             PreparedStatement pstmt = conn.prepareStatement(insertQuery)) {
            pstmt.setString(1, studentData.getName());
            pstmt.setInt(2, studentData.getAge());
            pstmt.setString(3, studentData.getGender());
            pstmt.setInt(4, studentData.getGrade());
            pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public List<Map<String, Object>> searchStudentByName(String name) {
        String selectQuery = "SELECT * FROM students WHERE name = ?";
        List<Map<String, Object>> result = new ArrayList<>();
        try (Connection conn = getConnection();
             PreparedStatement pstmt = conn.prepareStatement(selectQuery)) {
            pstmt.setString(1, name); // 设置查询参数
            try (ResultSet rs = pstmt.executeQuery()) { // 使用 try-with-resources 自动关闭 ResultSet
                while (rs.next()) {
                    Map<String, Object> student = new HashMap<>();
                    student.put("id", rs.getInt("id"));
                    student.put("name", rs.getString("name"));
                    student.put("age", rs.getInt("age"));
                    student.put("gender", rs.getString("gender"));
                    student.put("grade", rs.getInt("grade"));
                    result.add(student);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return result;
    }

    public void deleteStudentByName(String name) {
        String deleteQuery = "DELETE FROM students WHERE name = ?";
        try (Connection conn = getConnection();
             PreparedStatement pstmt = conn.prepareStatement(deleteQuery)) {
            pstmt.setString(1, name);
            pstmt.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private Connection getConnection() throws SQLException {
        return DriverManager.getConnection("jdbc:sqlite:" + databaseName);
    }

    public static class StudentData {
        private String name;
        private int age;
        private String gender;
        private int grade;

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
}
