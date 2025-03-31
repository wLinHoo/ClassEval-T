package org.example;

import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;



public class Classroom {
    private int id;
    List<ClassroomManagementTest.Course> courses;

    public Classroom(int id) {
        this.id = id;
        this.courses = new ArrayList<>();
    }

    public void addCourse(ClassroomManagementTest.Course course) {
        if (!courses.contains(course)) {
            courses.add(course);
        }
    }

    public void removeCourse(ClassroomManagementTest.Course course) {
        courses.remove(course);
    }

    public boolean isFreeAt(String checkTime) {
        LocalTime time = LocalTime.parse(checkTime);
        for (ClassroomManagementTest.Course course : courses) {
            if (!time.isBefore(course.startTime) && !time.isAfter(course.endTime)) {
                return false;
            }
        }
        return true;
    }

    public boolean checkCourseConflict(ClassroomManagementTest.Course newCourse) {
        LocalTime newStartTime = newCourse.startTime;
        LocalTime newEndTime = newCourse.endTime;

        for (ClassroomManagementTest.Course course : courses) {
            if (!(newEndTime.isBefore(course.startTime) || newStartTime.isAfter(course.endTime))) {
                return false;
            }
        }
        return true;
    }
}

