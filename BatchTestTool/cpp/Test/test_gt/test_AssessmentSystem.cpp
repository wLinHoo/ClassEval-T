#include <gtest/gtest.h>
#include "pch.h"

class AssessmentSystemTestAddStudent : public ::testing::Test {
protected:
    AssessmentSystem assessment_system;
};

TEST_F(AssessmentSystemTestAddStudent, TestAddStudent) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    auto it = assessment_system.students.find("Alice");
    ASSERT_NE(it, assessment_system.students.end());
    EXPECT_EQ(it->second.grade, 3);
    EXPECT_EQ(it->second.major, "Mathematics");
    EXPECT_TRUE(it->second.courses.empty());
}

TEST_F(AssessmentSystemTestAddStudent, TestAddStudent2) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_student("Bob", 2, "Science");
    EXPECT_EQ(assessment_system.students.size(), 2);
    EXPECT_EQ(assessment_system.students.at("Alice").grade, 3);
    EXPECT_EQ(assessment_system.students.at("Bob").grade, 2);
    EXPECT_EQ(assessment_system.students.at("Alice").major, "Mathematics");
    EXPECT_EQ(assessment_system.students.at("Bob").major, "Science");
}

TEST_F(AssessmentSystemTestAddStudent, TestAddStudent3) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_student("Bob", 2, "Science");
    assessment_system.add_student("Charlie", 4, "Chemistry");
    EXPECT_EQ(assessment_system.students.size(), 3);
    EXPECT_EQ(assessment_system.students.at("Alice").grade, 3);
    EXPECT_EQ(assessment_system.students.at("Bob").grade, 2);
    EXPECT_EQ(assessment_system.students.at("Charlie").grade, 4);
}

TEST_F(AssessmentSystemTestAddStudent, TestAddStudent4) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_student("Bob", 2, "Science");
    assessment_system.add_student("Charlie", 4, "Chemistry");
    assessment_system.add_student("David", 1, "Physics");
    EXPECT_EQ(assessment_system.students.size(), 4);
}

TEST_F(AssessmentSystemTestAddStudent, TestAddStudent5) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_student("Bob", 2, "Science");
    assessment_system.add_student("Charlie", 4, "Chemistry");
    assessment_system.add_student("David", 1, "Physics");
    assessment_system.add_student("Eve", 3, "Mathematics");
    EXPECT_EQ(assessment_system.students.size(), 5);
}

class AssessmentSystemTestAddCourseScore : public ::testing::Test {
protected:
    AssessmentSystem assessment_system;
};

TEST_F(AssessmentSystemTestAddCourseScore, TestAddCourseScore) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_course_score("Alice", "Math", 90);
    EXPECT_EQ(assessment_system.students.at("Alice").courses.at("Math"), 90);
}

TEST_F(AssessmentSystemTestAddCourseScore, TestAddCourseScore2) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_course_score("Alice", "Math", 90);
    EXPECT_EQ(assessment_system.students.at("Alice").courses.at("Math"), 90);
}

TEST_F(AssessmentSystemTestAddCourseScore, TestAddCourseScore3) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_course_score("Alice", "Math", 90);
    assessment_system.add_course_score("Alice", "Science", 80);
    assessment_system.add_course_score("Alice", "Math", 95);
    EXPECT_EQ(assessment_system.students.at("Alice").courses.at("Math"), 95);
    EXPECT_EQ(assessment_system.students.at("Alice").courses.at("Science"), 80);
}

TEST_F(AssessmentSystemTestAddCourseScore, TestAddCourseScore4) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_course_score("Alice", "Math", 90);
    assessment_system.add_course_score("Alice", "Science", 80);
    assessment_system.add_course_score("Alice", "Math", 95);
    assessment_system.add_course_score("Alice", "Science", 85);
    EXPECT_EQ(assessment_system.students.at("Alice").courses.at("Math"), 95);
    EXPECT_EQ(assessment_system.students.at("Alice").courses.at("Science"), 85);
}

TEST_F(AssessmentSystemTestAddCourseScore, TestAddCourseScore5) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_course_score("Bob", "Math", 90);
    EXPECT_TRUE(assessment_system.students.at("Alice").courses.empty());
}

class AssessmentSystemTestGetGPA : public ::testing::Test {
protected:
    AssessmentSystem assessment_system;
};

TEST_F(AssessmentSystemTestGetGPA, TestGetGPA1) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_course_score("Alice", "Mathematics", 90);
    assessment_system.add_course_score("Alice", "Science", 80);
    EXPECT_DOUBLE_EQ(*assessment_system.get_gpa("Alice"), 85.0);
}

TEST_F(AssessmentSystemTestGetGPA, TestGetGPA2) {
    EXPECT_FALSE(assessment_system.get_gpa("Alice").has_value());
}

TEST_F(AssessmentSystemTestGetGPA, TestGetGPA3) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    EXPECT_FALSE(assessment_system.get_gpa("Alice").has_value());
}

TEST_F(AssessmentSystemTestGetGPA, TestGetGPA4) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_course_score("Alice", "Mathematics", 90);
    EXPECT_FALSE(assessment_system.get_gpa("Bob").has_value());
}

TEST_F(AssessmentSystemTestGetGPA, TestGetGPA5) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_course_score("Alice", "Mathematics", 90);
    EXPECT_DOUBLE_EQ(*assessment_system.get_gpa("Alice"), 90.0);
}

class AssessmentSystemTestGetAllStudentsWithFailCourse : public ::testing::Test {
protected:
    AssessmentSystem assessment_system;
};

TEST_F(AssessmentSystemTestGetAllStudentsWithFailCourse, TestGetAllStudentsWithFailCourse) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_course_score("Alice", "Mathematics", 90);
    assessment_system.add_course_score("Alice", "Science", 80);
    assessment_system.add_student("Bob", 4, "Physics");
    assessment_system.add_course_score("Bob", "Physics", 50);
    assessment_system.add_student("Charlie", 2, "Chemistry");
    assessment_system.add_course_score("Charlie", "Chemistry", 70);
    assessment_system.add_student("David", 1, "Physics");
    assessment_system.add_course_score("David", "Physics", 60);
    assessment_system.add_student("Eve", 3, "Mathematics");
    assessment_system.add_course_score("Eve", "Mathematics", 90);

    auto result = assessment_system.get_all_students_with_fail_course();
    std::vector<std::string> expected = { "Bob" };
    EXPECT_EQ(result, expected);
}

TEST_F(AssessmentSystemTestGetAllStudentsWithFailCourse, TestGetAllStudentsWithFailCourse2) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_course_score("Alice", "Mathematics", 90);
    assessment_system.add_course_score("Alice", "Science", 80);
    assessment_system.add_student("Bob", 4, "Physics");
    assessment_system.add_course_score("Bob", "Physics", 70);
    assessment_system.add_student("Charlie", 2, "Chemistry");
    assessment_system.add_course_score("Charlie", "Chemistry", 70);
    assessment_system.add_student("David", 1, "Physics");
    assessment_system.add_course_score("David", "Physics", 70);
    assessment_system.add_student("Eve", 3, "Mathematics");
    assessment_system.add_course_score("Eve", "Mathematics", 90);

    auto result = assessment_system.get_all_students_with_fail_course();
    EXPECT_TRUE(result.empty());
}

TEST_F(AssessmentSystemTestGetAllStudentsWithFailCourse, TestGetAllStudentsWithFailCourse3) {
    auto result = assessment_system.get_all_students_with_fail_course();
    EXPECT_TRUE(result.empty());
}

TEST_F(AssessmentSystemTestGetAllStudentsWithFailCourse, TestGetAllStudentsWithFailCourse4) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    auto result = assessment_system.get_all_students_with_fail_course();
    EXPECT_TRUE(result.empty());
}

TEST_F(AssessmentSystemTestGetAllStudentsWithFailCourse, TestGetAllStudentsWithFailCourse5) {
    assessment_system.add_student("Alice", 3, "Mathematics");
    assessment_system.add_course_score("Alice", "Mathematics", 90);
    assessment_system.add_course_score("Alice", "Science", 50);
    assessment_system.add_student("Bob", 4, "Physics");
    assessment_system.add_course_score("Bob", "Physics", 50);

    auto result = assessment_system.get_all_students_with_fail_course();
    std::vector<std::string> expected = { "Alice", "Bob" };
    EXPECT_EQ(result, expected);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}