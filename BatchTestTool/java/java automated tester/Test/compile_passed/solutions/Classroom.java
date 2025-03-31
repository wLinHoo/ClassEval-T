import java.util.ArrayList;
import java.util.List;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class Classroom {
    private Integer id;
    private List<Course> courses;

    public Classroom(Integer id) {
        this.id = id;
        this.courses = new ArrayList<>();
    }

    public void addCourse(Course course) {
        if (!courses.contains(course)) {
            courses.add(course);
        }
    }

    public void removeCourse(Course course) {
        if (courses.contains(course)) {
            courses.remove(course);
        }
    }

    public boolean isFreeAt(String checkTime) {
        LocalTime checkTimeLocal = LocalTime.parse(checkTime, DateTimeFormatter.ofPattern("HH:mm"));

        for (Course course : courses) {
            LocalTime startTimeLocal = LocalTime.parse(course.getStartTime(), DateTimeFormatter.ofPattern("HH:mm"));
            LocalTime endTimeLocal = LocalTime.parse(course.getEndTime(), DateTimeFormatter.ofPattern("HH:mm"));

            if (startTimeLocal.isBefore(checkTimeLocal) && endTimeLocal.isAfter(checkTimeLocal)) {
                return false;
            }
        }

        return true;
    }

    public boolean checkCourseConflict(Course newCourse) {
        LocalTime newStartTime = LocalTime.parse(newCourse.getStartTime(), DateTimeFormatter.ofPattern("H:m"));
        LocalTime newEndTime = LocalTime.parse(newCourse.getEndTime(), DateTimeFormatter.ofPattern("H:m"));

        boolean flag = true;
        for (Course course : courses) {
            LocalTime startTime = LocalTime.parse(course.getStartTime(), DateTimeFormatter.ofPattern("H:m"));
            LocalTime endTime = LocalTime.parse(course.getEndTime(), DateTimeFormatter.ofPattern("H:m"));

            if (startTime.isBefore(newStartTime) && endTime.isAfter(newStartTime)) {
                flag = false;
            }

            if (startTime.isBefore(newEndTime) && endTime.isAfter(newEndTime)) {
                flag = false;
            }
        }
        return flag;
    }
}

class Course {
    private Integer id;
    private String name;
    private Integer teacherId;
    private Integer classroomId;
    private String startTime;
    private String endTime;

    public Course(Integer id, String name, Integer teacherId, Integer classroomId, String startTime, String endTime) {
        this.id = id;
        this.name = name;
        this.teacherId = teacherId;
        this.classroomId = classroomId;
        this.startTime = startTime;
        this.endTime = endTime;
    }

    public Course(String startTime, String endTime) {
        this.startTime = startTime;
        this.endTime = endTime;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getTeacherId() {
        return teacherId;
    }

    public void setTeacherId(Integer teacherId) {
        this.teacherId = teacherId;
    }

    public Integer getClassroomId() {
        return classroomId;
    }

    public void setClassroomId(Integer classroomId) {
        this.classroomId = classroomId;
    }

    public String getStartTime() {
        return startTime;
    }

    public void setStartTime(String startTime) {
        this.startTime = startTime;
    }

    public String getEndTime() {
        return endTime;
    }

    public void setEndTime(String endTime) {
        this.endTime = endTime;
    }
}