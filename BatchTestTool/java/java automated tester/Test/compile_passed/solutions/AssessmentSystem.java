import java.util.*;
import java.util.Optional;
import java.util.Map;

class Student {
    private Map<String, Integer> courses;
    private int grade;
    private String major;
    private List<Double> scores;

    public Student(int grade, String major) {
        this.grade = grade;
        this.major = major;
        this.courses = new HashMap<>();
        this.scores = new ArrayList<>();
    }

    public Map<String, Integer> getCourses() {
        return courses;
    }
}

public class AssessmentSystem {
    private Map<String, Student> students = new HashMap<>();

    public void addStudent(String name, int grade, String major) {
        students.put(name, new Student(grade, major));
    }

    public void addCourseScore(String name, String course, int score) {
        if (students.containsKey(name)) {
            students.get(name).getCourses().put(course, score);
        }
    }

    public Optional<Double> getGPA(String name) {
        if (students.containsKey(name)) {
            Map<String, Integer> courses = students.get(name).getCourses();
            if (!courses.isEmpty()) {
                double totalScore = courses.values().stream()
                    .mapToDouble(Integer::doubleValue)
                    .sum();
                return Optional.of(totalScore / courses.size());
            }
        }
        return Optional.empty();
    }

    public List<String> getAllStudentsWithFailCourse() {
        List<String> studentsWithFail = new ArrayList<>();
        for (Map.Entry<String, Student> entry : students.entrySet()) {
            String name = entry.getKey();
            Student student = entry.getValue();
            boolean hasFailing = student.getCourses().entrySet().stream()
                .anyMatch(course -> course.getValue() < 60);
            if (hasFailing) {
                studentsWithFail.add(name);
            }
        }
        return studentsWithFail;
    }

    public Optional<Double> getCourseAverage(String course) {
        double total = 0;
        int count = 0;
        for (Student student : students.values()) {
            Integer grade = student.getCourses().get(course);
            if (grade != null) {
                total += grade;
                count++;
            }
        }
        return count > 0 ? Optional.of(total / count) : Optional.empty();
    }

    public Optional<String> getTopStudent() {
        Optional<String> topStudent = Optional.empty();
        Optional<Double> highestGpa = Optional.empty();
        for (Map.Entry<String, Student> entry : students.entrySet()) {
            String name = entry.getKey();
            Optional<Double> gpa = getGPA(name);
            if (gpa.isPresent() &&
                (!highestGpa.isPresent() || gpa.get() > highestGpa.get())) {
                highestGpa = gpa;
                topStudent = Optional.of(name);
            }
        }
        return topStudent;
    }

    public Map<String, Student> getStudents() {
        return students;
    }
}