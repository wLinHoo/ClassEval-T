
#include <numeric>
#include <algorithm>

#include <string>
#include <map>
#include <vector>
#include <optional>


struct Student {
    int grade;
    std::string major;
    std::map<std::string, int> courses;
};


class AssessmentSystem {
public:
    void add_student(const std::string& name, int grade, const std::string& major);
    void add_course_score(const std::string& name, const std::string& course, int score);
    std::optional<double> get_gpa(const std::string& name) const;
    std::vector<std::string> get_all_students_with_fail_course() const;
    std::optional<double> get_course_average(const std::string& course) const;
    std::optional<std::string> get_top_student() const;
    std::map<std::string, Student> students;
};

void AssessmentSystem::add_student(const std::string& name, int grade, const std::string& major) {
    students[name] = { grade, major, {} };
}

void AssessmentSystem::add_course_score(const std::string& name, const std::string& course, int score) {
    auto it = students.find(name);
    if (it != students.end()) {
        it->second.courses[course] = score;
    }
}

std::optional<double> AssessmentSystem::get_gpa(const std::string& name) const {
    auto it = students.find(name);
    if (it != students.end()) {
        const auto& courses = it->second.courses;
        if (!courses.empty()) {
            double total_score = std::accumulate(courses.begin(), courses.end(), 0.0,
                [](double sum, const auto& course) { return sum + course.second; });
            return total_score / courses.size();
        }
    }
    return std::nullopt;
}

std::vector<std::string> AssessmentSystem::get_all_students_with_fail_course() const {
    std::vector<std::string> students_with_fail;
    for (const auto& [name, student] : students) {
        if (std::any_of(student.courses.begin(), student.courses.end(), [](const auto& course) { return course.second < 60; })) {
            students_with_fail.push_back(name);
        }
    }
    return students_with_fail;
}

std::optional<double> AssessmentSystem::get_course_average(const std::string& course) const {
    double total = 0;
    int count = 0;
    for (const auto& [name, student] : students) {
        auto it = student.courses.find(course);
        if (it != student.courses.end()) {
            total += it->second;
            ++count;
        }
    }
    return (count > 0) ? std::optional<double>(total / count) : std::nullopt;
}

std::optional<std::string> AssessmentSystem::get_top_student() const {
    std::optional<std::string> top_student;
    std::optional<double> highest_gpa;
    for (const auto& [name, student] : students) {
        auto gpa = get_gpa(name);
        if (gpa && (!highest_gpa || *gpa > *highest_gpa)) {
            highest_gpa = gpa;
            top_student = name;
        }
    }
    return top_student;
}
