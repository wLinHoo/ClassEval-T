import java.util.ArrayList;
import java.util.List;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

class Course {
    private String startTime;
    private String endTime;

    public Course(String startTime, String endTime) {
        this.startTime = startTime;
        this.endTime = endTime;
    }

    public String getStartTime() {
        return startTime;
    }

    public String getEndTime() {
        return endTime;
    }
}

class Classroom {
    private int id;
    private List<Course> courses;

    public Classroom(int id) {
        this.id = id;
        this.courses = new ArrayList<>();
    }

    public void addCourse(Course course) {
        if (!courses.contains(course)) {
            courses.add(course);
        }
    }

    public void removeCourse(Course course) {
        courses.remove(course);
    }

    public boolean isFreeAt(String checkTime) {
        LocalTime timeToCheck = LocalTime.parse(checkTime, DateTimeFormatter.ofPattern("HH:mm"));

        for (Course course : courses) {
            LocalTime startTime = LocalTime.parse(course.getStartTime(), DateTimeFormatter.ofPattern("HH:mm"));
            LocalTime endTime = LocalTime.parse(course.getEndTime(), DateTimeFormatter.ofPattern("HH:mm"));
            if (!timeToCheck.isBefore(startTime) && !timeToCheck.isAfter(endTime)) {
                return false;
            }
        }
        return true;
    }

    public boolean checkCourseConflict(Course newCourse) {
        LocalTime newStartTime = LocalTime.parse(newCourse.getStartTime(), DateTimeFormatter.ofPattern("HH:mm"));
        LocalTime newEndTime = LocalTime.parse(newCourse.getEndTime(), DateTimeFormatter.ofPattern("HH:mm"));

        for (Course course : courses) {
            LocalTime startTime = LocalTime.parse(course.getStartTime(), DateTimeFormatter.ofPattern("HH:mm"));
            LocalTime endTime = LocalTime.parse(course.getEndTime(), DateTimeFormatter.ofPattern("HH:mm"));
            if (!startTime.isAfter(newStartTime) && !endTime.isBefore(newStartTime)) {
                return false;
            }
            if (!startTime.isAfter(newEndTime) && !endTime.isBefore(newEndTime)) {
                return false;
            }
        }
        return true;
    }
}