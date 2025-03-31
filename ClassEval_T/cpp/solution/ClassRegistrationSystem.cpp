#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Student {
public:
    Student(const std::string& name, const std::string& major);

    std::string get_name() const;
    std::string get_major() const;

    void set_name(const std::string& name);
    void set_major(const std::string& major);

    bool operator==(const Student& other) const;

    std::string name;
    std::string major;
};

class ClassRegistrationSystem {
public:
    int register_student(const Student new_student);
    std::vector<std::string> register_class(const std::string& student_name, const std::string& class_name);
    std::vector<std::string> get_students_by_major(const std::string& major) const;
    std::vector<std::string> get_all_major() const;
    std::string get_most_popular_class_in_major(const std::string& major) const;
    std::vector<Student> students;
    std::unordered_map<std::string, std::vector<std::string>> students_registration_classes;
};


Student::Student(const std::string& name, const std::string& major) : name(name), major(major) {}

std::string Student::get_name() const {
    return name;
}

std::string Student::get_major() const {
    return major;
}

void Student::set_name(const std::string& name) {
    this->name = name;
}

void Student::set_major(const std::string& major) {
    this->major = major;
}

bool Student::operator==(const Student& other) const {
    return name == other.name && major == other.major;
}


int ClassRegistrationSystem::register_student(const Student new_student) {
    
    std::string name = new_student.get_name();
    std::string major = new_student.get_major();
    for (const auto& student : students) {
        if (student.get_name() == name) {
            return 0; 
        }
    }
    students.emplace_back(name, major);
    return 1; 
}

std::vector<std::string> ClassRegistrationSystem::register_class(const std::string& student_name, const std::string& class_name) {
    auto& classes = students_registration_classes[student_name];
    if (std::find(classes.begin(), classes.end(), class_name) == classes.end()) {
        classes.push_back(class_name);
    }
    return classes;
}

std::vector<std::string> ClassRegistrationSystem::get_students_by_major(const std::string& major) const {
    std::vector<std::string> student_list;
    for (const auto& student : students) {
        if (student.get_major() == major) {
            student_list.push_back(student.get_name());
        }
    }
    return student_list;
}

std::vector<std::string> ClassRegistrationSystem::get_all_major() const {
    std::set<std::string> majors;
    for (const auto& student : students) {
        
        majors.insert(student.get_major());
    }
    return std::vector<std::string>(majors.begin(), majors.end());
}

std::string ClassRegistrationSystem::get_most_popular_class_in_major(const std::string& major) const {
    std::unordered_map<std::string, int> class_count;

    
    for (const auto& student : students) {
        if (student.get_major() == major) {
            auto it = students_registration_classes.find(student.get_name());
            if (it != students_registration_classes.end()) {
                for (const auto& class_name : it->second) {
                    class_count[class_name]++;
                }
            }
        }
    }

    
    std::string most_popular_class;
    int max_count = 0;
    for (const auto& [class_name, count] : class_count) {
        if (count > max_count) {
            most_popular_class = class_name;
            max_count = count;
        }
    }

    return most_popular_class;
}

