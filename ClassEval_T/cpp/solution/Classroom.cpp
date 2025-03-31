
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <iostream>

#include <string>
#include <vector>
#include <ctime>

struct Course {
    std::string name;
    std::string start_time;  
    std::string end_time;    

    bool operator==(const Course& other) const {
        return name == other.name && start_time == other.start_time && end_time == other.end_time;
    }
};

class Classroom {
public:
    explicit Classroom(int id);

    void add_course(const Course& course);
    void remove_course(const Course& course);
    bool is_free_at(const std::string& check_time) const;
    bool check_course_conflict(const Course& new_course) const;
    bool has_course(const Course& course) const;

private:
    int id;
    std::vector<Course> courses;

    std::tm string_to_tm(const std::string& time_str) const;
    std::time_t tm_to_time_t(const std::tm& tm) const;
    bool is_time_conflict(const std::tm& start1, const std::tm& end1, const std::tm& start2, const std::tm& end2) const;
};


Classroom::Classroom(int id) : id(id) {}

void Classroom::add_course(const Course& course) {
    if (std::find(courses.begin(), courses.end(), course) == courses.end()) {
        courses.push_back(course);
    }
}

void Classroom::remove_course(const Course& course) {
    auto it = std::find(courses.begin(), courses.end(), course);
    if (it != courses.end()) {
        courses.erase(it);
    }
}

bool Classroom::is_free_at(const std::string& check_time) const {
    std::tm check_tm = string_to_tm(check_time);

    for (const auto& course : courses) {
        std::tm start_tm = string_to_tm(course.start_time);
        std::tm end_tm = string_to_tm(course.end_time);
        std::time_t check_tt = tm_to_time_t(check_tm);
        std::time_t start_tt = tm_to_time_t(start_tm);
        std::time_t end_tt = tm_to_time_t(end_tm);

        if (check_tt == -1 || start_tt == -1 || end_tt == -1) {
            std::cerr << "Time conversion failed" << std::endl;
            return false;
        }

        if (check_tt >= start_tt && check_tt <= end_tt) {
            return false;
        }
    }
    return true;
}

bool Classroom::check_course_conflict(const Course& new_course) const {
    std::tm new_start_tm = string_to_tm(new_course.start_time);
    std::tm new_end_tm = string_to_tm(new_course.end_time);

    if (new_start_tm.tm_hour == -1 || new_end_tm.tm_hour == -1) {
        std::cerr << "Time conversion failed" << std::endl;
        return true; 
    }

    for (const auto& course : courses) {
        std::tm start_tm = string_to_tm(course.start_time);
        std::tm end_tm = string_to_tm(course.end_time);

        if (start_tm.tm_hour == -1 || end_tm.tm_hour == -1) {
            std::cerr << "Time conversion failed" << std::endl;
            return true; 
        }

        if (is_time_conflict(start_tm, end_tm, new_start_tm, new_end_tm)) {
            return false;
        }
    }
    return true;
}

bool Classroom::has_course(const Course& course) const {
    return std::find(courses.begin(), courses.end(), course) != courses.end();
}

std::tm Classroom::string_to_tm(const std::string& time_str) const {
    std::tm tm = {};
    std::istringstream ss(time_str);
    ss >> std::get_time(&tm, "%H:%M");

    
    if (ss.fail()) {
        throw std::invalid_argument("Invalid time format: " + time_str);
    }

    
    tm.tm_year = 120; 
    tm.tm_mon = 0;    
    tm.tm_mday = 1;   

    return tm;
}

std::time_t Classroom::tm_to_time_t(const std::tm& tm) const {
    std::tm tm_copy = tm;
    std::time_t time_tt = std::mktime(&tm_copy);

    
    if (time_tt == -1) {
        throw std::runtime_error("Failed to convert std::tm to std::time_t");
    }

    return time_tt;
}

bool Classroom::is_time_conflict(const std::tm& start1, const std::tm& end1, const std::tm& start2, const std::tm& end2) const {
    std::time_t t1_start = tm_to_time_t(start1);
    std::time_t t1_end = tm_to_time_t(end1);
    std::time_t t2_start = tm_to_time_t(start2);
    std::time_t t2_end = tm_to_time_t(end2);

    return (t1_start <= t2_end && t1_end >= t2_start);
}
