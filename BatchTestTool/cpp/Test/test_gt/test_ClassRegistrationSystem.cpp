#include "pch.h"
#include <gtest/gtest.h>

class ClassRegistrationSystemTestRegisterStudent : public ::testing::Test {
protected:
    void SetUp() override {
        registration_system = ClassRegistrationSystem();
    }

    ClassRegistrationSystem registration_system;
};

class ClassRegistrationSystemTestRegisterClass : public ::testing::Test {
protected:
    void SetUp() override {
        registration_system = ClassRegistrationSystem();
    }

    ClassRegistrationSystem registration_system;
};

class ClassRegistrationSystemTestGetStudent : public ::testing::Test {
protected:
    void SetUp() override {
        registration_system = ClassRegistrationSystem();
    }

    ClassRegistrationSystem registration_system;
};

class ClassRegistrationSystemTestGetMajor : public ::testing::Test {
protected:
    void SetUp() override {
        registration_system = ClassRegistrationSystem();
    }

    ClassRegistrationSystem registration_system;
};

class ClassRegistrationSystemTestPopularClass : public ::testing::Test {
protected:
    void SetUp() override {
        registration_system = ClassRegistrationSystem();
    }

    ClassRegistrationSystem registration_system;
};

class ClassRegistrationSystemTest : public ::testing::Test {
protected:
    void SetUp() override {
        registration_system = ClassRegistrationSystem();
    }

    ClassRegistrationSystem registration_system;
};


TEST_F(ClassRegistrationSystemTestRegisterStudent, TestRegisterStudent) {
    Student student1 = { "John", "Computer Science" };
    EXPECT_EQ(registration_system.register_student(student1), 1);
}

TEST_F(ClassRegistrationSystemTestRegisterStudent, TestRegisterStudent2) {
    Student student1 = { "John", "Computer Science" };
    registration_system.register_student(student1);
    EXPECT_EQ(registration_system.register_student(student1), 0);
}

TEST_F(ClassRegistrationSystemTestRegisterStudent, TestRegisterStudent3) {
    Student student1 = { "John", "Computer Science" };
    Student student2 = { "Alice", "Mathematics" };
    EXPECT_EQ(registration_system.register_student(student1), 1);
    EXPECT_EQ(registration_system.register_student(student2), 1);
    EXPECT_EQ(registration_system.register_student(student2), 0);
}


TEST_F(ClassRegistrationSystemTestRegisterClass, TestRegisterClass) {
    std::vector<std::string> expected = { "CS101" };
    EXPECT_EQ(registration_system.register_class("John", "CS101"), expected);
}

TEST_F(ClassRegistrationSystemTestRegisterClass, TestRegisterClass2) {
    registration_system.register_class("John", "CS101");
    registration_system.register_class("John", "CS102");
    std::vector<std::string> expected = { "CS101", "CS102", "CS103" };
    EXPECT_EQ(registration_system.register_class("John", "CS103"), expected);
}

TEST_F(ClassRegistrationSystemTestRegisterClass, TestRegisterClass3) {
    registration_system.register_class("John", "CS101");
    registration_system.register_class("Tom", "CS102");
    std::vector<std::string> expected = { "CS101", "CS103" };
    EXPECT_EQ(registration_system.register_class("John", "CS103"), expected);
}


TEST_F(ClassRegistrationSystemTestGetStudent, TestGetStudentsByMajor) {
    Student student1 = { "John", "Computer Science" };
    Student student2 = { "Bob", "Computer Science" };
    registration_system.register_student(student1);
    registration_system.register_student(student2);
    std::vector<std::string> expected = { "John", "Bob" };
    EXPECT_EQ(registration_system.get_students_by_major("Computer Science"), expected);
}

TEST_F(ClassRegistrationSystemTestGetStudent, TestGetStudentsByMajor2) {
    Student student1 = { "John", "Computer Science" };
    Student student2 = { "Bob", "Computer Science" };
    Student student3 = { "Alice", "Mathematics" };
    registration_system.register_student(student1);
    registration_system.register_student(student2);
    registration_system.register_student(student3);
    std::vector<std::string> cs_students = registration_system.get_students_by_major("Computer Science");
    std::vector<std::string> math_students = registration_system.get_students_by_major("Mathematics");
    std::vector<std::string> expected_cs = { "John", "Bob" };
    std::vector<std::string> expected_math = { "Alice" };
    EXPECT_EQ(cs_students, expected_cs);
    EXPECT_EQ(math_students, expected_math);
}

TEST_F(ClassRegistrationSystemTestGetStudent, TestGetStudentsByMajor3) {
    Student student1 = { "John", "Computer Science" };
    Student student2 = { "Bob", "Computer Science" };
    Student student3 = { "Alice", "Mathematics" };
    Student student4 = { "Tom", "Mathematics" };
    Student student5 = { "Jerry", "Physics" };
    registration_system.register_student(student1);
    registration_system.register_student(student2);
    registration_system.register_student(student3);
    registration_system.register_student(student4);
    registration_system.register_student(student5);
    std::vector<std::string> cs_students = registration_system.get_students_by_major("Computer Science");
    std::vector<std::string> math_students = registration_system.get_students_by_major("Mathematics");
    std::vector<std::string> expected_cs = { "John", "Bob" };
    std::vector<std::string> expected_math = { "Alice", "Tom" };
    std::vector<std::string> expected_physics = { "Jerry" };
    EXPECT_EQ(cs_students, expected_cs);
    EXPECT_EQ(math_students, expected_math);
    EXPECT_EQ(registration_system.get_students_by_major("Physics"), expected_physics);
}

TEST_F(ClassRegistrationSystemTestGetStudent, TestGetStudentsByMajor4) {
    registration_system.students = {
        {"John", "Computer Science"},
        {"Bob", "Computer Science"},
        {"Alice", "Mathematics"},
        {"Tom", "Mathematics"},
        {"Jerry", "Mathematics"}
    };
    std::vector<std::string> cs_students = registration_system.get_students_by_major("Computer Science");
    std::vector<std::string> math_students = registration_system.get_students_by_major("Mathematics");
    std::vector<std::string> expected_cs = { "John", "Bob" };
    std::vector<std::string> expected_math = { "Alice", "Tom", "Jerry" };
    EXPECT_EQ(cs_students, expected_cs);
    EXPECT_EQ(math_students, expected_math);
}


TEST_F(ClassRegistrationSystemTestGetMajor, TestGetAllMajor) {
    Student student1 = { "John", "Computer Science" };
    Student student2 = { "Bob", "Computer Science" };
    registration_system.register_student(student1);
    registration_system.register_student(student2);
    std::vector<std::string> expected = { "Computer Science" };
    EXPECT_EQ(registration_system.get_all_major(), expected);
}

TEST_F(ClassRegistrationSystemTestGetMajor, TestGetAllMajor2) {
    Student student1 = { "John", "Computer Science" };
    Student student2 = { "Bob", "Computer Science" };
    Student student3 = { "Alice", "Mathematics" };
    registration_system.register_student(student1);
    registration_system.register_student(student2);
    registration_system.register_student(student3);
    std::vector<std::string> expected = { "Computer Science", "Mathematics" };
    EXPECT_EQ(registration_system.get_all_major(), expected);
}

TEST_F(ClassRegistrationSystemTestGetMajor, TestGetAllMajor3) {
    Student student1 = { "John", "Computer Science" };
    Student student2 = { "Bob", "Computer Science" };
    Student student3 = { "Alice", "Mathematics" };
    Student student4 = { "Tom", "Mathematics" };
    Student student5 = { "Jerry", "Physics" };
    registration_system.register_student(student1);
    registration_system.register_student(student2);
    registration_system.register_student(student3);
    registration_system.register_student(student4);
    registration_system.register_student(student5);
    std::vector<std::string> expected = { "Computer Science", "Mathematics", "Physics" };
    EXPECT_EQ(registration_system.get_all_major(), expected);
}


TEST_F(ClassRegistrationSystemTestPopularClass, TestGetMostPopularClassInMajor) {
    Student student1 = { "John", "Computer Science" };
    Student student2 = { "Bob", "Computer Science" };
    Student student3 = { "Alice", "Computer Science" };
    registration_system.register_student(student1);
    registration_system.register_student(student2);
    registration_system.register_student(student3);
    registration_system.register_class("John", "Algorithms");
    registration_system.register_class("John", "Data Structures");
    registration_system.register_class("Bob", "Operating Systems");
    registration_system.register_class("Bob", "Data Structures");
    registration_system.register_class("Alice", "Data Structures");
    std::string expected = "Data Structures";
    EXPECT_EQ(registration_system.get_most_popular_class_in_major("Computer Science"), expected);
}

TEST_F(ClassRegistrationSystemTestPopularClass, TestGetMostPopularClassInMajor2) {
    Student student1 = { "John", "Computer Science" };
    Student student2 = { "Bob", "Computer Science" };
    Student student3 = { "Alice", "Computer Science" };
    Student student4 = { "Tom", "Mathematics" };
    Student student5 = { "Jerry", "Mathematics" };
    registration_system.register_student(student1);
    registration_system.register_student(student2);
    registration_system.register_student(student3);
    registration_system.register_student(student4);
    registration_system.register_student(student5);
    registration_system.register_class("John", "Algorithms");
    registration_system.register_class("John", "Data Structures");
    registration_system.register_class("Bob", "Data Structures");
    registration_system.register_class("Bob", "Algorithms");
    registration_system.register_class("Bob", "Operating Systems");
    registration_system.register_class("Alice", "Data Structures");
    registration_system.register_class("Alice", "Operating Systems");
    registration_system.register_class("Alice", "Claculus");
    registration_system.register_class("Tom", "Calculus");
    registration_system.register_class("Tom", "Linear Algebra");
    registration_system.register_class("Jerry", "Linear Algebra");
    registration_system.register_class("Jerry", "Statistics");
    std::string expected_cs = "Data Structures";
    std::string expected_math = "Linear Algebra";
    EXPECT_EQ(registration_system.get_most_popular_class_in_major("Computer Science"), expected_cs);
    EXPECT_EQ(registration_system.get_most_popular_class_in_major("Mathematics"), expected_math);
}


TEST_F(ClassRegistrationSystemTest, Test) {
    Student student1 = { "John", "Computer Science" };
    Student student2 = { "Bob", "Computer Science" };
    Student student3 = { "Alice", "Mathematics" };
    Student student4 = { "Tom", "Mathematics" };
    registration_system.register_student(student1);
    registration_system.register_student(student2);
    registration_system.register_student(student3);
    registration_system.register_student(student4);
    registration_system.register_class("John", "Algorithms");
    registration_system.register_class("John", "Data Structures");
    registration_system.register_class("Bob", "Operating Systems");
    registration_system.register_class("Bob", "Data Structures");
    std::vector<std::string> expected_cs = { "John", "Bob" };
    std::vector<std::string> expected_math = { "Alice", "Tom" };
    std::vector<std::string> expected_major = { "Computer Science", "Mathematics" };
    EXPECT_EQ(registration_system.get_students_by_major("Computer Science"), expected_cs);
    EXPECT_EQ(registration_system.get_students_by_major("Mathematics"), expected_math);
    EXPECT_EQ(registration_system.get_all_major(), expected_major);
    EXPECT_EQ(registration_system.get_most_popular_class_in_major("Computer Science"), "Data Structures");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}