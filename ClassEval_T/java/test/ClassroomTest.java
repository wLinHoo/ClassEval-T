package org.example;

import org.junit.jupiter.api.Test;
import static org.testng.Assert.assertTrue;
import static org.testng.Assert.assertFalse;
import static org.testng.Assert.assertNotNull;
import static org.testng.Assert.assertNull;
import static org.testng.Assert.assertEquals;

import java.time.LocalTime;
import java.util.Objects;

class ClassroomTest {
    static class Course {
        String name;
        LocalTime startTime;
        LocalTime endTime;

        public Course(String name, String startTime, String endTime) {
            this.name = name;
            this.startTime = LocalTime.parse(startTime);
            this.endTime = LocalTime.parse(endTime);
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;

            Course course = (Course) obj;
            return name.equals(course.name) &&
                    startTime.equals(course.startTime) &&
                    endTime.equals(course.endTime);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name, startTime, endTime);
        }
    }

    @Test
    public void testAddCourse1() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("math", "09:00", "10:00");
        classroom.addCourse(course);
        assertTrue(classroom.courses.contains(course));
    }

    @Test
    public void testAddCourse2() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("Chinese", "10:00", "11:00");
        classroom.addCourse(course);
        assertTrue(classroom.courses.contains(course));
    }

    @Test
    public void testAddCourse3() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("English", "11:00", "12:00");
        classroom.addCourse(course);
        assertTrue(classroom.courses.contains(course));
    }

    @Test
    public void testAddCourse4() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("Art", "14:00", "15:00");
        classroom.addCourse(course);
        assertTrue(classroom.courses.contains(course));
    }

    @Test
    public void testAddCourse5() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("P.E.", "15:00", "16:00");
        classroom.addCourse(course);
        assertTrue(classroom.courses.contains(course));
    }

    @Test
    public void testAddCourse6() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("math", "09:00", "10:00");
        classroom.addCourse(course);
        classroom.addCourse(course);
        assertTrue(classroom.courses.contains(course));
    }

    // Tests for removing courses
    @Test
    public void testRemoveCourse1() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("math", "09:00", "10:00");
        classroom.addCourse(course);
        classroom.removeCourse(course);
        assertFalse(classroom.courses.contains(course));
    }

    @Test
    public void testRemoveCourse2() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("Chinese", "10:00", "11:00");
        classroom.addCourse(course);
        classroom.removeCourse(course);
        assertFalse(classroom.courses.contains(course));
    }

    @Test
    public void testRemoveCourse3() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("English", "11:00", "12:00");
        classroom.addCourse(course);
        classroom.removeCourse(course);
        assertFalse(classroom.courses.contains(course));
    }

    @Test
    public void testRemoveCourse4() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("Art", "14:00", "15:00");
        classroom.addCourse(course);
        classroom.removeCourse(course);
        assertFalse(classroom.courses.contains(course));
    }

    @Test
    public void testRemoveCourse5() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("P.E.", "15:00", "16:00");
        classroom.addCourse(course);
        classroom.removeCourse(course);
        assertFalse(classroom.courses.contains(course));
    }

    @Test
    public void testRemoveCourse6() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("math", "09:00", "10:00");
        classroom.removeCourse(course);
        assertFalse(classroom.courses.contains(course));
    }

    // Tests for checking availability
    @Test
    public void testIsFreeAt1() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("math", "09:00", "10:00");
        classroom.addCourse(course);
        String checkTime = "11:00";
        boolean result = classroom.isFreeAt(checkTime);
        assertTrue(result);
    }

    @Test
    public void testIsFreeAt2() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("math", "09:00", "10:00");
        classroom.addCourse(course);
        String checkTime = "09:30";
        boolean result = classroom.isFreeAt(checkTime);
        assertFalse(result);
    }

    @Test
    public void testIsFreeAt3() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("math", "09:00", "10:00");
        classroom.addCourse(course);
        String checkTime = "12:00";
        boolean result = classroom.isFreeAt(checkTime);
        assertTrue(result);
    }

    @Test
    public void testIsFreeAt4() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("math", "09:00", "10:00");
        classroom.addCourse(course);
        String checkTime = "14:00";
        boolean result = classroom.isFreeAt(checkTime);
        assertTrue(result);
    }

    @Test
    public void testIsFreeAt5() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("math", "09:00", "10:00");
        classroom.addCourse(course);
        String checkTime = "09:40";
        boolean result = classroom.isFreeAt(checkTime);
        assertFalse(result);
    }

    // Tests for checking course conflicts
    @Test
    public void testCheckCourseConflict1() {
        Classroom classroom = new Classroom(1);
        Course existingCourse = new Course("math", "09:00", "10:00");
        classroom.addCourse(existingCourse);
        Course newCourse = new Course("SE", "10:30", "11:30");
        boolean result = classroom.checkCourseConflict(newCourse);
        assertTrue(result);
    }

    @Test
    public void testCheckCourseConflict2() {
        Classroom classroom = new Classroom(1);
        Course existingCourse = new Course("math", "09:00", "10:00");
        classroom.addCourse(existingCourse);
        Course newCourse = new Course("SE", "09:30", "10:30");
        boolean result = classroom.checkCourseConflict(newCourse);
        assertFalse(result);
    }

    @Test
    public void testCheckCourseConflict3() {
        Classroom classroom = new Classroom(1);
        Course existingCourse = new Course("math", "09:00", "10:00");
        classroom.addCourse(existingCourse);
        Course newCourse = new Course("SE", "10:00", "11:30");
        boolean result = classroom.checkCourseConflict(newCourse);
        assertFalse(result);
    }

    @Test
    public void testCheckCourseConflict4() {
        Classroom classroom = new Classroom(1);
        Course existingCourse = new Course("math", "09:00", "10:00");
        classroom.addCourse(existingCourse);
        Course newCourse = new Course("SE", "09:40", "10:40");
        boolean result = classroom.checkCourseConflict(newCourse);
        assertFalse(result);
    }

    @Test
    public void testCheckCourseConflict5() {
        Classroom classroom = new Classroom(1);
        Course existingCourse = new Course("math", "09:00", "10:00");
        classroom.addCourse(existingCourse);
        Course newCourse = new Course("SE", "14:30", "15:30");
        boolean result = classroom.checkCourseConflict(newCourse);
        assertTrue(result);
    }

    @Test
    public void testCheckCourseConflict6() {
        Classroom classroom = new Classroom(1);
        Course existingCourse = new Course("math", "09:00", "10:00");
        classroom.addCourse(existingCourse);
        Course newCourse = new Course("SE", "08:30", "09:30");
        boolean result = classroom.checkCourseConflict(newCourse);
        assertFalse(result);
    }

    // Test for main scenario
    @Test
    public void testMain() {
        Classroom classroom = new Classroom(1);
        Course course = new Course("math", "09:00", "10:00");
        classroom.addCourse(course);
        assertTrue(classroom.courses.contains(course));

        classroom.removeCourse(course);
        assertFalse(classroom.courses.contains(course));

        classroom.addCourse(course);
        assertTrue(classroom.courses.contains(course));

        String checkTime = "09:30";
        boolean result = classroom.isFreeAt(checkTime);
        assertFalse(result);

        Course newCourse = new Course("SE", "09:30", "10:30");
        result = classroom.checkCourseConflict(newCourse);
        assertFalse(result);
    }
}
