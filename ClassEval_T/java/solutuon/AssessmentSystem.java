package org.example;

import java.util.*;

public class AssessmentSystem {
    Map<String, Student> students;

    public AssessmentSystem() {
        this.students = new HashMap<>();
    }

    public void addStudent(String name, int grade, String major) {
        students.put(name, new Student(name, grade, major));
    }

    public void addCourseScore(String name, String course, int score) {
        if (students.containsKey(name)) {
            students.get(name).addCourseScore(course, score);
        }
    }

    public Double getGPA(String name) {
        if (students.containsKey(name)) {
            return students.get(name).calculateGPA();
        }
        return null;
    }

    public List<String> getAllStudentsWithFailCourse() {
        List<String> failingStudents = new ArrayList<>();
        for (Student student : students.values()) {
            if (student.hasFailingCourse()) {
                failingStudents.add(student.getName());
            }
        }
        return failingStudents;
    }

    public Double getCourseAverage(String course) {
        int totalScore = 0;
        int count = 0;
        for (Student student : students.values()) {
            Integer score = student.getCourseScore(course);
            if (score != null) {
                totalScore += score;
                count++;
            }
        }
        return count > 0 ? (double) totalScore / count : null;
    }

    public String getTopStudent() {
        String topStudent = null;
        double topGPA = 0;
        for (Student student : students.values()) {
            Double gpa = student.calculateGPA();
            if (gpa != null && gpa > topGPA) {
                topGPA = gpa;
                topStudent = student.getName();
            }
        }
        return topStudent;
    }

    public static class Student {
        private String name;
        private int grade;
        private String major;
        Map<String, Integer> courses;

        public Student(String name, int grade, String major) {
            this.name = name;
            this.grade = grade;
            this.major = major;
            this.courses = new HashMap<>();
        }

        public String getName() {
            return name;
        }

        public void addCourseScore(String course, int score) {
            courses.put(course, score);
        }

        public Double calculateGPA() {
            if (courses.isEmpty()) {
                return null;
            }
            int totalScore = 0;
            for (int score : courses.values()) {
                totalScore += score;
            }
            return (double) totalScore / courses.size();
        }

        public boolean hasFailingCourse() {
            for (int score : courses.values()) {
                if (score < 60) {
                    return true;
                }
            }
            return false;
        }

        public Integer getCourseScore(String course) {
            return courses.get(course);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Student student = (Student) o;
            return grade == student.grade &&
                    Objects.equals(name, student.name) &&
                    Objects.equals(major, student.major) &&
                    Objects.equals(courses, student.courses);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name, grade, major, courses);
        }
    }

    public static void main(String[] args) {
        AssessmentSystem system = new AssessmentSystem();
        system.addStudent("student 1", 3, "SE");
        system.addStudent("student 2", 2, "SE");
        system.addCourseScore("student 1", "course 1", 86);
        system.addCourseScore("student 2", "course 1", 59);
        system.addCourseScore("student 1", "course 2", 78);
        system.addCourseScore("student 2", "course 2", 90);

        System.out.println(system.getAllStudentsWithFailCourse());
        System.out.println(system.getCourseAverage("course 1"));
        System.out.println(system.getCourseAverage("course 2"));
        System.out.println(system.getGPA("student 1"));
        System.out.println(system.getGPA("student 2"));
        System.out.println(system.getTopStudent());
    }
}