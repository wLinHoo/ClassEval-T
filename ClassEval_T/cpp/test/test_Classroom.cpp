#include <gtest/gtest.h>
#include "pch.h"  

class ClassroomTestAddCourse : public ::testing::Test {
protected:
    void SetUp() override {
        classroom = new Classroom(1);
    }

    void TearDown() override {
        delete classroom;
    }

    Classroom* classroom;
};

TEST_F(ClassroomTestAddCourse, test_add_course_1) {
    Course course = { "math", "09:00", "10:00" };
    classroom->add_course(course);
    ASSERT_TRUE(classroom->has_course(course));
}

TEST_F(ClassroomTestAddCourse, test_add_course_2) {
    Course course = { "Chinese", "10:00", "11:00" };
    classroom->add_course(course);
    ASSERT_TRUE(classroom->has_course(course));
}

TEST_F(ClassroomTestAddCourse, test_add_course_3) {
    Course course = { "English", "11:00", "12:00" };
    classroom->add_course(course);
    ASSERT_TRUE(classroom->has_course(course));
}

TEST_F(ClassroomTestAddCourse, test_add_course_4) {
    Course course = { "Art", "14:00", "15:00" };
    classroom->add_course(course);
    ASSERT_TRUE(classroom->has_course(course));
}

TEST_F(ClassroomTestAddCourse, test_add_course_5) {
    Course course = { "P.E.", "15:00", "16:00" };
    classroom->add_course(course);
    ASSERT_TRUE(classroom->has_course(course));
}

TEST_F(ClassroomTestAddCourse, test_add_course_6) {
    Course course = { "math", "09:00", "10:00" };
    classroom->add_course(course);
    classroom->add_course(course);  
    ASSERT_TRUE(classroom->has_course(course));
}

class ClassroomTestRemoveCourse : public ::testing::Test {
protected:
    void SetUp() override {
        classroom = new Classroom(1);
    }

    void TearDown() override {
        delete classroom;
    }

    Classroom* classroom;
};

TEST_F(ClassroomTestRemoveCourse, test_remove_course_1) {
    Course course = { "math", "09:00", "10:00" };
    classroom->add_course(course);
    classroom->remove_course(course);
    ASSERT_FALSE(classroom->has_course(course));
}

TEST_F(ClassroomTestRemoveCourse, test_remove_course_2) {
    Course course = { "Chinese", "10:00", "11:00" };
    classroom->add_course(course);
    classroom->remove_course(course);
    ASSERT_FALSE(classroom->has_course(course));
}

TEST_F(ClassroomTestRemoveCourse, test_remove_course_3) {
    Course course = { "English", "11:00", "12:00" };
    classroom->add_course(course);
    classroom->remove_course(course);
    ASSERT_FALSE(classroom->has_course(course));
}

TEST_F(ClassroomTestRemoveCourse, test_remove_course_4) {
    Course course = { "Art", "14:00", "15:00" };
    classroom->add_course(course);
    classroom->remove_course(course);
    ASSERT_FALSE(classroom->has_course(course));
}

TEST_F(ClassroomTestRemoveCourse, test_remove_course_5) {
    Course course = { "P.E.", "15:00", "16:00" };
    classroom->add_course(course);
    classroom->remove_course(course);
    ASSERT_FALSE(classroom->has_course(course));
}

TEST_F(ClassroomTestRemoveCourse, test_remove_course_6) {
    Course course = { "math", "09:00", "10:00" };
    classroom->remove_course(course);  
    ASSERT_FALSE(classroom->has_course(course));
}

class ClassroomTestIsFreeAt : public ::testing::Test {
protected:
    void SetUp() override {
        classroom = new Classroom(1);
    }

    void TearDown() override {
        delete classroom;
    }

    Classroom* classroom;
};

TEST_F(ClassroomTestIsFreeAt, test_is_free_at_1) {
    Course course = { "math", "09:00", "10:00" };
    classroom->add_course(course);
    std::string check_time = "11:00";
    bool result = classroom->is_free_at(check_time);
    ASSERT_TRUE(result);
}

TEST_F(ClassroomTestIsFreeAt, test_is_free_at_2) {
    Course course = { "math", "09:00", "10:00" };
    classroom->add_course(course);
    std::string check_time = "09:30";
    bool result = classroom->is_free_at(check_time);
    ASSERT_FALSE(result);
}

TEST_F(ClassroomTestIsFreeAt, test_is_free_at_3) {
    Course course = { "math", "09:00", "10:00" };
    classroom->add_course(course);
    std::string check_time = "12:00";
    bool result = classroom->is_free_at(check_time);
    ASSERT_TRUE(result);
}

TEST_F(ClassroomTestIsFreeAt, test_is_free_at_4) {
    Course course = { "math", "09:00", "10:00" };
    classroom->add_course(course);
    std::string check_time = "14:00";
    bool result = classroom->is_free_at(check_time);
    ASSERT_TRUE(result);
}

TEST_F(ClassroomTestIsFreeAt, test_is_free_at_5) {
    Course course = { "math", "09:00", "10:00" };
    classroom->add_course(course);
    std::string check_time = "09:40";
    bool result = classroom->is_free_at(check_time);
    ASSERT_FALSE(result);
}

class ClassroomTestCheckCourseConflict : public ::testing::Test {
protected:
    void SetUp() override {
        classroom = new Classroom(1);
    }

    void TearDown() override {
        delete classroom;
    }

    Classroom* classroom;
};

TEST_F(ClassroomTestCheckCourseConflict, test_check_course_conflict_1) {
    Course existing_course = { "math", "09:00", "10:00" };
    classroom->add_course(existing_course);
    Course new_course = { "SE", "10:30", "11:30" };
    bool result = classroom->check_course_conflict(new_course);
    ASSERT_TRUE(result);
}

TEST_F(ClassroomTestCheckCourseConflict, test_check_course_conflict_2) {
    Course existing_course = { "math", "09:00", "10:00" };
    classroom->add_course(existing_course);
    Course new_course = { "SE", "09:30", "10:30" };
    bool result = classroom->check_course_conflict(new_course);
    ASSERT_FALSE(result);
}

TEST_F(ClassroomTestCheckCourseConflict, test_check_course_conflict_3) {
    Course existing_course = { "math", "09:00", "10:00" };
    classroom->add_course(existing_course);
    Course new_course = { "SE", "10:00", "11:30" };
    bool result = classroom->check_course_conflict(new_course);
    ASSERT_FALSE(result);
}

TEST_F(ClassroomTestCheckCourseConflict, test_check_course_conflict_4) {
    Course existing_course = { "math", "09:00", "10:00" };
    classroom->add_course(existing_course);
    Course new_course = { "SE", "09:40", "10:40" };
    bool result = classroom->check_course_conflict(new_course);
    ASSERT_FALSE(result);
}

TEST_F(ClassroomTestCheckCourseConflict, test_check_course_conflict_5) {
    Course existing_course = { "math", "09:00", "10:00" };
    classroom->add_course(existing_course);
    Course new_course = { "SE", "14:30", "15:30" };
    bool result = classroom->check_course_conflict(new_course);
    ASSERT_TRUE(result);
}

TEST_F(ClassroomTestCheckCourseConflict, test_check_course_conflict_6) {
    Course existing_course = { "math", "09:00", "10:00" };
    classroom->add_course(existing_course);
    Course new_course = { "SE", "08:30", "09:30" };
    bool result = classroom->check_course_conflict(new_course);
    ASSERT_FALSE(result);
}

class ClassroomTestMain : public ::testing::Test {
protected:
    void SetUp() override {
        classroom = new Classroom(1);
    }

    void TearDown() override {
        delete classroom;
    }

    Classroom* classroom;
};

TEST_F(ClassroomTestMain, test_main) {
    Course course = { "math", "09:00", "10:00" };
    classroom->add_course(course);
    ASSERT_TRUE(classroom->has_course(course));

    classroom->remove_course(course);
    ASSERT_FALSE(classroom->has_course(course));

    classroom->add_course(course);
    ASSERT_TRUE(classroom->has_course(course));
    std::string check_time = "09:30";
    bool result = classroom->is_free_at(check_time);
    ASSERT_FALSE(result);

    Course new_course = { "SE", "09:30", "10:30" };
    bool conflict = classroom->check_course_conflict(new_course);
    ASSERT_FALSE(conflict);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
