package test_cases;
import to_be_tested.AssessmentSystem;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class AssessmentSystemTest {

    @Test
    public void testAddStudent() {
        AssessmentSystem system = new AssessmentSystem();
        system.addStudent("Alice", 3, "Mathematics");
        assertEquals(new AssessmentSystem.Student("Alice", 3, "Mathematics"), system.students.get("Alice"));
    }

    @Test
    public void testAddStudent2() {
        AssessmentSystem system = new AssessmentSystem();
        system.addStudent("Alice", 3, "Mathematics");
        system.addStudent("Bob", 2, "Science");
        assertEquals(Map.of(
                "Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"),
                "Bob", new AssessmentSystem.Student("Bob", 2, "Science")
        ), system.students);
    }

    @Test
    public void testAddStudent3() {
        AssessmentSystem system = new AssessmentSystem();
        system.addStudent("Alice", 3, "Mathematics");
        system.addStudent("Bob", 2, "Science");
        system.addStudent("Charlie", 4, "Chemistry");
        assertEquals(Map.of(
                "Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"),
                "Bob", new AssessmentSystem.Student("Bob", 2, "Science"),
                "Charlie", new AssessmentSystem.Student("Charlie", 4, "Chemistry")
        ), system.students);
    }

    @Test
    public void testAddStudent4() {
        AssessmentSystem system = new AssessmentSystem();
        system.addStudent("Alice", 3, "Mathematics");
        system.addStudent("Bob", 2, "Science");
        system.addStudent("Charlie", 4, "Chemistry");
        system.addStudent("David", 1, "Physics");
        assertEquals(Map.of(
                "Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"),
                "Bob", new AssessmentSystem.Student("Bob", 2, "Science"),
                "Charlie", new AssessmentSystem.Student("Charlie", 4, "Chemistry"),
                "David", new AssessmentSystem.Student("David", 1, "Physics")
        ), system.students);
    }

    @Test
    public void testAddStudent5() {
        AssessmentSystem system = new AssessmentSystem();
        system.addStudent("Alice", 3, "Mathematics");
        system.addStudent("Bob", 2, "Science");
        system.addStudent("Charlie", 4, "Chemistry");
        system.addStudent("David", 1, "Physics");
        system.addStudent("Eve", 3, "Mathematics");
        assertEquals(Map.of(
                "Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"),
                "Bob", new AssessmentSystem.Student("Bob", 2, "Science"),
                "Charlie", new AssessmentSystem.Student("Charlie", 4, "Chemistry"),
                "David", new AssessmentSystem.Student("David", 1, "Physics"),
                "Eve", new AssessmentSystem.Student("Eve", 3, "Mathematics")
        ), system.students);
    }

    @Test
    public void testAddCourseScore() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.addCourseScore("Alice", "Math", 90);
        assertEquals(Map.of("Math", 90), system.students.get("Alice").courses);
    }

    @Test
    public void testAddCourseScore2() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.addCourseScore("Alice", "Math", 90);
        assertEquals(Map.of("Math", 90), system.students.get("Alice").courses);
    }

    @Test
    public void testAddCourseScore3() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.addCourseScore("Alice", "Math", 90);
        system.addCourseScore("Alice", "Science", 80);
        system.addCourseScore("Alice", "Math", 95);
        assertEquals(Map.of("Math", 95, "Science", 80), system.students.get("Alice").courses);
    }

    @Test
    public void testAddCourseScore4() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.addCourseScore("Alice", "Math", 90);
        system.addCourseScore("Alice", "Science", 80);
        system.addCourseScore("Alice", "Math", 95);
        system.addCourseScore("Alice", "Science", 85);
        assertEquals(Map.of("Math", 95, "Science", 85), system.students.get("Alice").courses);
    }

    @Test
    public void testAddCourseScore5() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.addCourseScore("Bob", "Math", 90);
        assertEquals(Map.of(), system.students.get("Alice").courses);
    }

    @Test
    public void testGetGPA1() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        system.students.get("Alice").courses.put("Science", 80);
        assertEquals(85.0, system.getGPA("Alice"));
    }

    @Test
    public void testGetGPA2() {
        AssessmentSystem system = new AssessmentSystem();
        assertNull(system.getGPA("Alice"));
    }

    @Test
    public void testGetGPA3() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        assertNull(system.getGPA("Alice"));
    }

    @Test
    public void testGetGPA4() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        assertNull(system.getGPA("Bob"));
    }

    @Test
    public void testGetGPA5() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        assertEquals(90.0, system.getGPA("Alice"));
    }

    @Test
    public void testGetAllStudentsWithFailCourse() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.put("Bob", new AssessmentSystem.Student("Bob", 4, "Physics"));
        system.students.put("Charlie", new AssessmentSystem.Student("Charlie", 2, "Chemistry"));
        system.students.put("David", new AssessmentSystem.Student("David", 1, "Physics"));
        system.students.put("Eve", new AssessmentSystem.Student("Eve", 3, "Mathematics"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        system.students.get("Alice").courses.put("Science", 80);
        system.students.get("Bob").courses.put("Physics", 50);
        system.students.get("Charlie").courses.put("Chemistry", 70);
        system.students.get("David").courses.put("Physics", 60);
        system.students.get("Eve").courses.put("Mathematics", 90);
        List<String> expected = List.of("Bob");
        List<String> actual = system.getAllStudentsWithFailCourse();
        assertIterableEquals(expected.stream().sorted().collect(Collectors.toList()), actual.stream().sorted().collect(Collectors.toList()));
    }

    @Test
    public void testGetAllStudentsWithFailCourse2() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.put("Bob", new AssessmentSystem.Student("Bob", 4, "Physics"));
        system.students.put("Charlie", new AssessmentSystem.Student("Charlie", 2, "Chemistry"));
        system.students.put("David", new AssessmentSystem.Student("David", 1, "Physics"));
        system.students.put("Eve", new AssessmentSystem.Student("Eve", 3, "Mathematics"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        system.students.get("Alice").courses.put("Science", 80);
        system.students.get("Bob").courses.put("Physics", 70);
        system.students.get("Charlie").courses.put("Chemistry", 70);
        system.students.get("David").courses.put("Physics", 70);
        system.students.get("Eve").courses.put("Mathematics", 90);
        List<String> expected = List.of();
        List<String> actual = system.getAllStudentsWithFailCourse();
        assertIterableEquals(expected.stream().sorted().collect(Collectors.toList()), actual.stream().sorted().collect(Collectors.toList()));
    }

    @Test
    public void testGetAllStudentsWithFailCourse3() {
        AssessmentSystem system = new AssessmentSystem();
        List<String> expected = List.of();
        List<String> actual = system.getAllStudentsWithFailCourse();
        assertIterableEquals(expected.stream().sorted().collect(Collectors.toList()), actual.stream().sorted().collect(Collectors.toList()));
    }

    @Test
    public void testGetAllStudentsWithFailCourse4() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        List<String> expected = List.of();
        List<String> actual = system.getAllStudentsWithFailCourse();
        assertIterableEquals(expected.stream().sorted().collect(Collectors.toList()), actual.stream().sorted().collect(Collectors.toList()));
    }

    @Test
    public void testGetAllStudentsWithFailCourse5() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.put("Bob", new AssessmentSystem.Student("Bob", 4, "Physics"));
        system.students.put("Charlie", new AssessmentSystem.Student("Charlie", 2, "Chemistry"));
        system.students.put("David", new AssessmentSystem.Student("David", 1, "Physics"));
        system.students.put("Eve", new AssessmentSystem.Student("Eve", 3, "Mathematics"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        system.students.get("Alice").courses.put("Science", 50);
        system.students.get("Bob").courses.put("Physics", 50);
        system.students.get("Charlie").courses.put("Chemistry", 70);
        system.students.get("David").courses.put("Physics", 70);
        system.students.get("Eve").courses.put("Mathematics", 90);
        List<String> expected = List.of("Alice", "Bob");
        List<String> actual = system.getAllStudentsWithFailCourse();
        assertIterableEquals(expected.stream().sorted().collect(Collectors.toList()), actual.stream().sorted().collect(Collectors.toList()));
    }

    @Test
    public void testGetCourseAverage1() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.put("Bob", new AssessmentSystem.Student("Bob", 4, "Physics"));
        system.students.put("Charlie", new AssessmentSystem.Student("Charlie", 2, "Chemistry"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        system.students.get("Alice").courses.put("Science", 80);
        system.students.get("Bob").courses.put("Physics", 90);
        system.students.get("Charlie").courses.put("Chemistry", 70);
        system.students.get("Charlie").courses.put("Physics", 80);
        assertEquals(85.0, system.getCourseAverage("Physics"));
    }

    @Test
    public void testGetCourseAverage2() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.put("Bob", new AssessmentSystem.Student("Bob", 4, "Physics"));
        system.students.put("Charlie", new AssessmentSystem.Student("Charlie", 2, "Chemistry"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        system.students.get("Alice").courses.put("Science", 80);
        system.students.get("Bob").courses.put("Physics", 85);
        system.students.get("Charlie").courses.put("Chemistry", 70);
        system.students.get("Charlie").courses.put("Physics", null);
        assertEquals(85.0, system.getCourseAverage("Physics"));
    }

    @Test
    public void testGetCourseAverage3() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.put("Bob", new AssessmentSystem.Student("Bob", 4, "Physics"));
        system.students.put("Charlie", new AssessmentSystem.Student("Charlie", 2, "Chemistry"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        system.students.get("Alice").courses.put("Science", 80);
        system.students.get("Bob").courses.put("Physics", 85);
        system.students.get("Charlie").courses.put("Chemistry", 70);
        system.students.get("Charlie").courses.put("Physics", 80);
        assertNull(system.getCourseAverage("Computer"));
    }

    @Test
    public void testGetCourseAverage4() {
        AssessmentSystem system = new AssessmentSystem();
        assertNull(system.getCourseAverage("Computer"));
    }

    @Test
    public void testGetCourseAverage5() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.put("Bob", new AssessmentSystem.Student("Bob", 4, "Physics"));
        system.students.put("Charlie", new AssessmentSystem.Student("Charlie", 2, "Chemistry"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        system.students.get("Alice").courses.put("Science", 80);
        system.students.get("Bob").courses.put("Physics", 85);
        system.students.get("Charlie").courses.put("Chemistry", 70);
        system.students.get("Charlie").courses.put("Physics", 80);
        assertEquals(90.0, system.getCourseAverage("Mathematics"));
    }

    @Test
    public void testGetTopStudent() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.put("Bob", new AssessmentSystem.Student("Bob", 4, "Physics"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        system.students.get("Bob").courses.put("Physics", 85);
        assertEquals("Alice", system.getTopStudent());
    }

    @Test
    public void testGetTopStudent2() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.put("Bob", new AssessmentSystem.Student("Bob", 4, "Physics"));
        system.students.put("Charlie", new AssessmentSystem.Student("Charlie", 2, "Chemistry"));
        system.students.get("Bob").courses.put("Physics", 85);
        system.students.get("Charlie").courses.put("Chemistry", 70);
        system.students.get("Charlie").courses.put("Physics", 80);
        assertEquals("Bob", system.getTopStudent());
    }

    @Test
    public void testGetTopStudent3() {
        AssessmentSystem system = new AssessmentSystem();
        assertNull(system.getTopStudent());
    }

    @Test
    public void testGetTopStudent4() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.put("Bob", new AssessmentSystem.Student("Bob", 4, "Physics"));
        system.students.put("Charlie", new AssessmentSystem.Student("Charlie", 2, "Chemistry"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        system.students.get("Alice").courses.put("Science", 60);
        system.students.get("Bob").courses.put("Physics", 85);
        system.students.get("Charlie").courses.put("Chemistry", 70);
        system.students.get("Charlie").courses.put("Physics", 80);
        assertEquals("Bob", system.getTopStudent());
    }

    @Test
    public void testGetTopStudent5() {
        AssessmentSystem system = new AssessmentSystem();
        system.students.put("Alice", new AssessmentSystem.Student("Alice", 3, "Mathematics"));
        system.students.put("Bob", new AssessmentSystem.Student("Bob", 4, "Physics"));
        system.students.put("Charlie", new AssessmentSystem.Student("Charlie", 2, "Chemistry"));
        system.students.put("David", new AssessmentSystem.Student("David", 2, "Chemistry"));
        system.students.get("Alice").courses.put("Mathematics", 90);
        system.students.get("Alice").courses.put("Science", 60);
        system.students.get("Bob").courses.put("Physics", 85);
        system.students.get("Charlie").courses.put("Chemistry", 70);
        system.students.get("Charlie").courses.put("Physics", 80);
        system.students.get("David").courses.put("Chemistry", 70);
        system.students.get("David").courses.put("Physics", 80);
        assertEquals("Bob", system.getTopStudent());
    }

    @Test
    public void testMain() {
        AssessmentSystem system = new AssessmentSystem();
        system.addStudent("student 1", 3, "SE");
        system.addStudent("student 2", 2, "SE");
        assertEquals(Map.of(
                "student 1", new AssessmentSystem.Student("student 1", 3, "SE"),
                "student 2", new AssessmentSystem.Student("student 2", 2, "SE")
        ), system.students);
        system.addCourseScore("student 1", "course 1", 86);
        system.addCourseScore("student 2", "course 1", 59);
        system.addCourseScore("student 1", "course 2", 78);
        system.addCourseScore("student 2", "course 2", 90);

        assertEquals(86, system.students.get("student 1").courses.get("course 1"));
        assertEquals(78, system.students.get("student 1").courses.get("course 2"));
        assertEquals(59, system.students.get("student 2").courses.get("course 1"));
        assertEquals(90, system.students.get("student 2").courses.get("course 2"));

        List<String> expected = List.of("student 2");
        List<String> actual = system.getAllStudentsWithFailCourse();
        assertIterableEquals(expected.stream().sorted().collect(Collectors.toList()), actual.stream().sorted().collect(Collectors.toList()));
        assertEquals(72.5, system.getCourseAverage("course 1"));
        assertEquals(84.0, system.getCourseAverage("course 2"));

        assertEquals(82.0, system.getGPA("student 1"));
        assertEquals(74.5, system.getGPA("student 2"));

        assertEquals("student 1", system.getTopStudent());
    }
}