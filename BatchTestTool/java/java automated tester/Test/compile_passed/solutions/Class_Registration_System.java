import java.util.*;

class Student {
    String name;
    String major;

    public Student(String name, String major) {
        this.name = name;
        this.major = major;
    }
}

class ClassRegistrationSystem {
    List<Student> students = new ArrayList<>();
    Map<String, List<String>> studentsRegistrationClasses = new HashMap<>();

    public void registerStudent(Student student) {
        if (students.contains(student)) {
            return;
        } else {
            students.add(student);
            return;
        }
    }

    public List<String> registerClass(Student student, String className) {
        if (studentsRegistrationClasses.containsKey(student.name)) {
            studentsRegistrationClasses.get(student.name).add(className);
        } else {
            studentsRegistrationClasses.put(student.name, new ArrayList<>(Collections.singletonList(className)));
        }
        return studentsRegistrationClasses.get(student.name);
    }

    public List<String> getStudentsByMajor(String major) {
        List<String> studentList = new ArrayList<>();
        for (Student student : students) {
            if (student.major.equals(major)) {
                studentList.add(student.name);
            }
        }
        return studentList;
    }

    public List<String> getAllMajor() {
        List<String> majorList = new ArrayList<>();
        for (Student student : students) {
            if (!majorList.contains(student.major)) {
                majorList.add(student.major);
            }
        }
        return majorList;
    }

    public String getMostPopularClassInMajor(String major) {
        List<String> classList = new ArrayList<>();
        for (Student student : students) {
            if (student.major.equals(major)) {
                classList.addAll(studentsRegistrationClasses.get(student.name));
            }
        }
        String mostPopularClass = null;
        int maxCount = 0;
        for (String className : classList) {
            int count = Collections.frequency(classList, className);
            if (count > maxCount) {
                maxCount = count;
                mostPopularClass = className;
            }
        }
        return mostPopularClass;
    }
}