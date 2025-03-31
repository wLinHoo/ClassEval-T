import java.util.*;

class Student {
    private String name;
    private String major;

    public Student(String name, String major) {
        this.name = name;
        this.major = major;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getMajor() {
        return major;
    }

    public void setMajor(String major) {
        this.major = major;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Student student = (Student) o;
        return Objects.equals(name, student.name) &&
               Objects.equals(major, student.major);
    }

    @Override
    public int hashCode() {
        return Objects.hash(name, major);
    }
}

class ClassRegistrationSystem {
    private List<Student> students;
    private Map<String, List<String>> studentsRegistrationClasses;

    public ClassRegistrationSystem() {
        students = new ArrayList<>();
        studentsRegistrationClasses = new HashMap<>();
    }

    public int registerStudent(Student newStudent) {
        String name = newStudent.getName();
        String major = newStudent.getMajor();

        for (Student student : students) {
            if (student.getName().equals(name)) {
                return 0; // Student already exists
            }
        }

        students.add(new Student(name, major));
        return 1; // New student added
    }

    public List<String> registerClass(String studentName, String className) {
        List<String> classes = studentsRegistrationClasses.computeIfAbsent(studentName, k -> new ArrayList<>());

        if (!classes.contains(className)) {
            classes.add(className);
        }

        return classes;
    }

    public List<String> getStudentsByMajor(String major) {
        ArrayList<String> studentList = new ArrayList<>();
        for (Student student : students) {
            if (student.getMajor().equals(major)) {
                studentList.add(student.getName());
            }
        }
        return studentList;
    }

    public List<String> getAllMajor() {
        Set<String> majors = new HashSet<>();
        for (Student student : students) {
            majors.add(student.getMajor());
        }
        return new ArrayList<>(majors);
    }

    public String getMostPopularClassInMajor(String major) {
        Map<String, Integer> classCount = new HashMap<>();

        for (Student student : students) {
            if (student.getMajor().equals(major)) {
                List<String> classes = studentsRegistrationClasses.get(student.getName());
                if (classes != null) {
                    for (String className : classes) {
                        classCount.put(className,
                            classCount.getOrDefault(className, 0) + 1);
                    }
                }
            }
        }

        String mostPopularClass = "";
        int maxCount = 0;

        for (Map.Entry<String, Integer> entry : classCount.entrySet()) {
            if (entry.getValue() > maxCount) {
                mostPopularClass = entry.getKey();
                maxCount = entry.getValue();
            }
        }

        return mostPopularClass;
    }

    public List<Student> getStudents() {
        return students;
    }

    public Map<String, List<String>> getStudentsRegistrationClasses() {
        return studentsRegistrationClasses;
    }
}