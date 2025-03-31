package org.example;

import java.util.*;

public class ClassRegistrationSystem {
    private List<Student> students;
    private Map<String, List<String>> studentsRegistrationClasses;

    public ClassRegistrationSystem() {
        this.students = new ArrayList<>();
        this.studentsRegistrationClasses = new HashMap<>();
    }

    public int registerStudent(Student student) {
        if (students.contains(student)) {
            return 0;
        } else {
            students.add(student);
            return 1;
        }
    }

    public List<String> registerClass(String studentName, String className) {
        if (studentsRegistrationClasses.containsKey(studentName)) {
            studentsRegistrationClasses.get(studentName).add(className);
        } else {
            studentsRegistrationClasses.put(studentName, new ArrayList<>(Collections.singletonList(className)));
        }
        return studentsRegistrationClasses.get(studentName);
    }

    public List<String> getStudentsByMajor(String major) {
        List<String> studentList = new ArrayList<>();
        for (Student student : students) {
            if (student.getMajor().equals(major)) {
                studentList.add(student.getName());
            }
        }
        return studentList;
    }

    public List<String> getAllMajor() {
        Set<String> majorSet = new HashSet<>();
        for (Student student : students) {
            majorSet.add(student.getMajor());
        }
        return new ArrayList<>(majorSet);
    }

    public String getMostPopularClassInMajor(String major) {
        Map<String, Integer> classCount = new HashMap<>();
        for (Student student : students) {
            if (student.getMajor().equals(major)) {
                List<String> classes = studentsRegistrationClasses.getOrDefault(student.getName(), new ArrayList<>());
                for (String className : classes) {
                    classCount.put(className, classCount.getOrDefault(className, 0) + 1);
                }
            }
        }
        return Collections.max(classCount.entrySet(), Map.Entry.comparingByValue()).getKey();
    }

    // Setter methods for tests
    public void setStudents(List<Student> students) {
        this.students = students;
    }

    public void setStudentClasses(Map<String, List<String>> studentClasses) {
        this.studentsRegistrationClasses = studentClasses;
    }

    public static class Student {
        private String name;
        private String major;

        public Student(String name, String major) {
            this.name = name;
            this.major = major;
        }

        public String getName() {
            return name;
        }

        public String getMajor() {
            return major;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Student student = (Student) o;
            return Objects.equals(name, student.name) && Objects.equals(major, student.major);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name, major);
        }
    }
}
