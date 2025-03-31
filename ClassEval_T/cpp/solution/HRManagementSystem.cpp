#include <string>
#include <map>
#include <variant>
#include <optional>
#include<unordered_map>

class HRManagementSystem {
public:
    HRManagementSystem();
    bool add_employee(int employee_id, const std::string& name, const std::string& position, const std::string& department, int salary);
    bool remove_employee(int employee_id);
    bool update_employee(int employee_id, const std::unordered_map<std::string, std::variant<std::string, int>>& employee_info);
    std::optional<std::unordered_map<std::string, std::variant<std::string, int>>> get_employee(int employee_id) const;
    std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>> employees;
    std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>> list_employees() const;
};

HRManagementSystem::HRManagementSystem() : employees() {}

bool HRManagementSystem::add_employee(int employee_id, const std::string& name, const std::string& position, const std::string& department, int salary) {
    if (employees.find(employee_id) != employees.end()) {
        return false;
    }
    else {
        employees[employee_id] = {
            {"name", name},
            {"position", position},
            {"department", department},
            {"salary", salary}
        };
        return true;
    }
}

bool HRManagementSystem::remove_employee(int employee_id) {
    auto it = employees.find(employee_id);
    if (it != employees.end()) {
        employees.erase(it);
        return true;
    }
    else {
        return false;
    }
}
bool HRManagementSystem::update_employee(int employee_id, const std::unordered_map<std::string, std::variant<std::string, int>>& employee_info) {
    auto employee_it = employees.find(employee_id);
    if (employee_it == employees.end()) {
        return false;
    }

    for (const auto& [key, value] : employee_info) {
        if (employee_it->second.find(key) == employee_it->second.end()) {
            return false;
        }
    }

    for (const auto& [key, value] : employee_info) {
        employee_it->second[key] = value;
    }

    return true;
}

std::optional<std::unordered_map<std::string, std::variant<std::string, int>>> HRManagementSystem::get_employee(int employee_id) const {
    auto it = employees.find(employee_id);
    if (it != employees.end()) {
        return it->second;
    }
    return std::nullopt;
}

std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>> HRManagementSystem::list_employees() const {
    std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>> employee_data;

    for (const auto& [employee_id, employee_info] : employees) {
        std::unordered_map<std::string, std::variant<std::string, int>> employee_details;
        employee_details["employee_ID"] = employee_id;
        for (const auto& [key, value] : employee_info) {
            employee_details[key] = value;
        }
        employee_data[employee_id] = employee_details;
    }

    return employee_data;
}

