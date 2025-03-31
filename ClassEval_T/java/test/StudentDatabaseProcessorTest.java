package org.example;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.List;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

public class StudentDatabaseProcessorTest {

    private StudentDatabaseProcessor processor;

    @BeforeEach
    public void setUp() throws SQLException {
        processor = new StudentDatabaseProcessor("test_database.db");
        processor.createStudentTable();
    }

    @AfterEach
    public void tearDown() throws SQLException {
        Connection conn = DriverManager.getConnection("jdbc:sqlite:test_database.db");
        Statement stmt = conn.createStatement();
        stmt.execute("DROP TABLE IF EXISTS students");
        conn.close();
    }

    @Test
    public void testInsertStudent1() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("Alice", 20, "female", 90);
        processor.insertStudent(studentData);

        List<Map<String, Object>> result = processor.searchStudentByName("Alice");
        assertTrue(result.size() > 0);
        assertEquals("Alice", result.get(0).get("name"));
    }

    @Test
    public void testInsertStudent2() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("aaa", 20, "female", 90);
        processor.insertStudent(studentData);

        List<Map<String, Object>> result = processor.searchStudentByName("aaa");
        assertTrue(result.size() > 0);
        assertEquals("aaa", result.get(0).get("name"));
    }

    @Test
    public void testInsertStudent3() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("bbb", 20, "female", 90);
        processor.insertStudent(studentData);

        List<Map<String, Object>> result = processor.searchStudentByName("bbb");
        assertTrue(result.size() > 0);
        assertEquals("bbb", result.get(0).get("name"));
    }

    @Test
    public void testInsertStudent4() throws SQLException {

        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("ccc", 20, "female", 90);
        processor.insertStudent(studentData);

        List<Map<String, Object>> result = processor.searchStudentByName("ccc");
        assertTrue(result.size() > 0);
        assertEquals("ccc", result.get(0).get("name"));
    }

    @Test
    public void testInsertStudent5() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("ddd", 20, "female", 90);
        processor.insertStudent(studentData);

        List<Map<String, Object>> result = processor.searchStudentByName("ddd");
        assertTrue(result.size() > 0);
        assertEquals("ddd", result.get(0).get("name"));
    }

    @Test
    public void testSearchStudentByName1() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("Bob", 19, "male", 85);
        processor.insertStudent(studentData);

        List<Map<String, Object>> result = processor.searchStudentByName("Bob");

        assertTrue(result.size() > 0); // Ensure we have at least one result
        assertEquals("Bob", result.get(0).get("name")); // Compare the name of the first result
    }

    @Test
    public void testSearchStudentByName2() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("aaa", 19, "male", 85);
        processor.insertStudent(studentData);

        List<Map<String, Object>> result = processor.searchStudentByName("aaa");

        assertTrue(result.size() > 0);
        assertEquals("aaa", result.get(0).get("name"));
    }

    @Test
    public void testSearchStudentByName3() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("bbb", 19, "male", 85);
        processor.insertStudent(studentData);

        List<Map<String, Object>> result = processor.searchStudentByName("bbb");

        assertTrue(result.size() > 0);
        assertEquals("bbb", result.get(0).get("name"));
    }

    @Test
    public void testSearchStudentByName4() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("ccc", 19, "male", 85);
        processor.insertStudent(studentData);

        List<Map<String, Object>> result = processor.searchStudentByName("ccc");

        assertTrue(result.size() > 0);
        assertEquals("ccc", result.get(0).get("name"));
    }

    @Test
    public void testSearchStudentByName5() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("ddd", 19, "male", 85);
        processor.insertStudent(studentData);
        List<Map<String, Object>> result = processor.searchStudentByName("ddd");

        assertTrue(result.size() > 0);
        assertEquals("ddd", result.get(0).get("name"));
    }

    @Test
    public void testDeleteStudentByName1() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("Charlie", 18, "male", 95);
        processor.insertStudent(studentData);

        processor.deleteStudentByName("Charlie");

        List<Map<String, Object>> result = processor.searchStudentByName("Charlie");
        assertTrue(result.isEmpty());
    }

    @Test
    public void testDeleteStudentByName2() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("aaa", 18, "male", 95);
        processor.insertStudent(studentData);

        processor.deleteStudentByName("aaa");

        List<Map<String, Object>> result = processor.searchStudentByName("aaa");
        assertTrue(result.isEmpty());
    }

    @Test
    public void testDeleteStudentByName3() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("bbb", 18, "male", 95);
        processor.insertStudent(studentData);

        processor.deleteStudentByName("bbb");

        List<Map<String, Object>> result = processor.searchStudentByName("bbb");
        assertTrue(result.isEmpty());
    }

    @Test
    public void testDeleteStudentByName4() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("ccc", 18, "male", 95);
        processor.insertStudent(studentData);

        processor.deleteStudentByName("ccc");

        List<Map<String, Object>> result = processor.searchStudentByName("ccc");
        assertTrue(result.isEmpty());
    }

    @Test
    public void testDeleteStudentByName5() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("ddd", 18, "male", 95);
        processor.insertStudent(studentData);

        processor.deleteStudentByName("ddd");

        List<Map<String, Object>> result = processor.searchStudentByName("ddd");
        assertTrue(result.isEmpty());
    }

    @Test
    public void testStudentDatabaseProcessor() throws SQLException {
        StudentDatabaseProcessor.StudentData studentData = new StudentDatabaseProcessor.StudentData("Alice", 20, "female", 90);
        processor.insertStudent(studentData);

        List<Map<String, Object>> result = processor.searchStudentByName("Alice");

        assertTrue(result.size() > 0);
        assertEquals("Alice", result.get(0).get("name"));
    }
}
