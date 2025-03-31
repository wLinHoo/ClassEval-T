#include "pch.h"
#include <gtest/gtest.h>

class HRManagementSystemTestAddEmployee : public ::testing::Test {};

TEST_F(HRManagementSystemTestAddEmployee, test_add_employee) {
    HRManagementSystem hr_system;
    EXPECT_EQ(hr_system.add_employee(1, "John Doe", "Manager", "HR", 5000), true);
    EXPECT_EQ(std::get<std::string>(hr_system.employees[1]["name"]), "John Doe");
    EXPECT_EQ(std::get<std::string>(hr_system.employees[1]["position"]), "Manager");
    EXPECT_EQ(std::get<std::string>(hr_system.employees[1]["department"]), "HR");
    EXPECT_EQ(std::get<int>(hr_system.employees[1]["salary"]), 5000);
}

TEST_F(HRManagementSystemTestAddEmployee, test_add_employee_2) {
    HRManagementSystem hr_system;
    EXPECT_EQ(hr_system.add_employee(1, "John Doe", "Manager", "HR", 5000), true);
    EXPECT_EQ(hr_system.add_employee(1, "John Doe", "Manager", "HR", 5000), false);
    EXPECT_EQ(std::get<std::string>(hr_system.employees[1]["name"]), "John Doe");
    EXPECT_EQ(std::get<std::string>(hr_system.employees[1]["position"]), "Manager");
    EXPECT_EQ(std::get<std::string>(hr_system.employees[1]["department"]), "HR");
    EXPECT_EQ(std::get<int>(hr_system.employees[1]["salary"]), 5000);
}

TEST_F(HRManagementSystemTestAddEmployee, test_add_employee_3) {
    HRManagementSystem hr_system;
    EXPECT_EQ(hr_system.add_employee(1, "John Doe", "Manager", "HR", 5000), true);
    EXPECT_EQ(hr_system.add_employee(2, "John Doe", "Manager", "HR", 5000), true);
    EXPECT_EQ(std::get<std::string>(hr_system.employees[1]["name"]), "John Doe");
    EXPECT_EQ(std::get<std::string>(hr_system.employees[2]["name"]), "John Doe");
}

TEST_F(HRManagementSystemTestAddEmployee, test_add_employee_4) {
    HRManagementSystem hr_system;
    EXPECT_EQ(hr_system.add_employee(1, "John Doe", "Manager", "HR", 5000), true);
    EXPECT_EQ(hr_system.add_employee(2, "John Doe", "Manager", "HR", 5000), true);
    EXPECT_EQ(hr_system.add_employee(1, "John Doe", "Manager", "HR", 5000), false);
    EXPECT_EQ(std::get<std::string>(hr_system.employees[1]["name"]), "John Doe");
    EXPECT_EQ(std::get<std::string>(hr_system.employees[2]["name"]), "John Doe");
}

TEST_F(HRManagementSystemTestAddEmployee, test_add_employee_5) {
    HRManagementSystem hr_system;
    EXPECT_EQ(hr_system.add_employee(1, "John Doe", "Manager", "HR", 5000), true);
    EXPECT_EQ(hr_system.add_employee(2, "John Doe", "Manager", "HR", 5000), true);
    EXPECT_EQ(hr_system.add_employee(1, "John Doe", "Manager", "HR", 5000), false);
    EXPECT_EQ(hr_system.add_employee(2, "John Doe", "Manager", "HR", 5000), false);
    EXPECT_EQ(std::get<std::string>(hr_system.employees[1]["name"]), "John Doe");
    EXPECT_EQ(std::get<std::string>(hr_system.employees[2]["name"]), "John Doe");
}

class HRManagementSystemTestRemoveEmployee : public ::testing::Test {};

TEST_F(HRManagementSystemTestRemoveEmployee, test_remove_employee) {
    HRManagementSystem hr_system;
    hr_system.employees = { {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}} };
    EXPECT_EQ(hr_system.remove_employee(1), true);
    EXPECT_TRUE(hr_system.employees.empty());
}

TEST_F(HRManagementSystemTestRemoveEmployee, test_remove_employee_2) {
    HRManagementSystem hr_system;
    hr_system.employees = { {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}} };
    EXPECT_EQ(hr_system.remove_employee(1), true);
    EXPECT_EQ(hr_system.remove_employee(1), false);
    EXPECT_TRUE(hr_system.employees.empty());
}

TEST_F(HRManagementSystemTestRemoveEmployee, test_remove_employee_3) {
    HRManagementSystem hr_system;
    hr_system.employees = {
        {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}},
        {2, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    EXPECT_EQ(hr_system.remove_employee(1), true);
    EXPECT_EQ(hr_system.employees.size(), 1);
    EXPECT_EQ(std::get<std::string>(hr_system.employees[2]["name"]), "John");
}

TEST_F(HRManagementSystemTestRemoveEmployee, test_remove_employee_4) {
    HRManagementSystem hr_system;
    hr_system.employees = {
        {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}},
        {2, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    EXPECT_EQ(hr_system.remove_employee(1), true);
    EXPECT_EQ(hr_system.remove_employee(2), true);
    EXPECT_TRUE(hr_system.employees.empty());
}

TEST_F(HRManagementSystemTestRemoveEmployee, test_remove_employee_5) {
    HRManagementSystem hr_system;
    hr_system.employees = {
        {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}},
        {2, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    EXPECT_EQ(hr_system.remove_employee(1), true);
    EXPECT_EQ(hr_system.remove_employee(2), true);
    EXPECT_EQ(hr_system.remove_employee(1), false);
    EXPECT_EQ(hr_system.remove_employee(2), false);
    EXPECT_TRUE(hr_system.employees.empty());
}
class HRManagementSystemTestUpdateEmployee : public ::testing::Test {};

TEST(HRManagementSystemTestUpdateEmployee, test_update_employee) {
    HRManagementSystem hr_system;
    hr_system.employees[1] = { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000} };
    EXPECT_TRUE(hr_system.update_employee(1, { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 20000} }));
    EXPECT_EQ(std::get<int>(hr_system.employees[1]["salary"]), 20000);
}

TEST(HRManagementSystemTestUpdateEmployee, test_update_employee_2) {
    HRManagementSystem hr_system;
    EXPECT_FALSE(hr_system.update_employee(1, { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 20000} }));
    EXPECT_TRUE(hr_system.employees.empty());
}

TEST(HRManagementSystemTestUpdateEmployee, test_update_employee_3) {
    HRManagementSystem hr_system;
    hr_system.employees[1] = { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000} };
    EXPECT_FALSE(hr_system.update_employee(2, { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 20000} }));
    EXPECT_EQ(std::get<int>(hr_system.employees[1]["salary"]), 100000);
}

TEST(HRManagementSystemTestUpdateEmployee, test_update_employee_4) {
    HRManagementSystem hr_system;
    hr_system.employees[1] = { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000} };
    EXPECT_TRUE(hr_system.update_employee(1, { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 20000} }));
    EXPECT_TRUE(hr_system.update_employee(1, { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 20000} }));
    EXPECT_EQ(std::get<int>(hr_system.employees[1]["salary"]), 20000);
}

TEST(HRManagementSystemTestUpdateEmployee, test_update_employee_5) {
    HRManagementSystem hr_system;
    hr_system.employees[1] = { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000} };
    EXPECT_TRUE(hr_system.update_employee(1, { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 20000} }));
    EXPECT_TRUE(hr_system.update_employee(1, { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 20000} }));
    EXPECT_TRUE(hr_system.update_employee(1, { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000} }));
    EXPECT_EQ(std::get<int>(hr_system.employees[1]["salary"]), 100000);
}

TEST(HRManagementSystemTestUpdateEmployee, test_update_employee_6) {
    HRManagementSystem hr_system;
    hr_system.employees[1] = { {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000} };
    EXPECT_FALSE(hr_system.update_employee(1, { {"Name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 20000} }));
}

class HRManagementSystemTestGetEmployee : public ::testing::Test {};

TEST(HRManagementSystemTestGetEmployee, test_get_employee) {
    HRManagementSystem hr_system;
    hr_system.employees = {
        {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    auto result = hr_system.get_employee(1);
    ASSERT_TRUE(result.has_value());
    EXPECT_EQ(std::get<std::string>(result->at("name")), "John");
    EXPECT_EQ(std::get<std::string>(result->at("position")), "Manager");
    EXPECT_EQ(std::get<std::string>(result->at("department")), "Sales");
    EXPECT_EQ(std::get<int>(result->at("salary")), 100000);
}

TEST(HRManagementSystemTestGetEmployee, test_get_employee_2) {
    HRManagementSystem hr_system;
    hr_system.employees = {};
    auto result = hr_system.get_employee(1);
    EXPECT_FALSE(result.has_value());
}

TEST(HRManagementSystemTestGetEmployee, test_get_employee_3) {
    HRManagementSystem hr_system;
    hr_system.employees = {
        {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    auto result = hr_system.get_employee(2);
    EXPECT_FALSE(result.has_value());
}

TEST(HRManagementSystemTestGetEmployee, test_get_employee_4) {
    HRManagementSystem hr_system;
    hr_system.employees = {
        {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    auto result1 = hr_system.get_employee(1);
    ASSERT_TRUE(result1.has_value());
    EXPECT_EQ(std::get<std::string>(result1->at("name")), "John");

    auto result2 = hr_system.get_employee(1);
    ASSERT_TRUE(result2.has_value());
    EXPECT_EQ(std::get<std::string>(result2->at("name")), "John");
}

TEST(HRManagementSystemTestGetEmployee, test_get_employee_5) {
    HRManagementSystem hr_system;
    hr_system.employees = {
        {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}},
        {2, {{"name", "Jane"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    auto result1 = hr_system.get_employee(1);
    ASSERT_TRUE(result1.has_value());
    EXPECT_EQ(std::get<std::string>(result1->at("name")), "John");

    auto result2 = hr_system.get_employee(2);
    ASSERT_TRUE(result2.has_value());
    EXPECT_EQ(std::get<std::string>(result2->at("name")), "Jane");
}

class HRManagementSystemTestListEmployees :public testing::Test {};

TEST(HRManagementSystemTestListEmployees, test_list_employees) {
    HRManagementSystem hr_system;
    hr_system.employees = {
        {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    auto expected = std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>{
        {1, {{"employee_ID", 1}, {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    EXPECT_EQ(hr_system.list_employees(), expected);
}

TEST(HRManagementSystemTestListEmployees, test_list_employees_2) {
    HRManagementSystem hr_system;
    hr_system.employees = {};
    EXPECT_TRUE(hr_system.list_employees().empty());
}

TEST(HRManagementSystemTestListEmployees, test_list_employees_3) {
    HRManagementSystem hr_system;
    hr_system.employees = {
        {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}},
        {2, {{"name", "Jane"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    auto expected = std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>{
        {1, {{"employee_ID", 1}, {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}},
        {2, {{"employee_ID", 2}, {"name", "Jane"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    EXPECT_EQ(hr_system.list_employees(), expected);
}

TEST(HRManagementSystemTestListEmployees, test_list_employees_4) {
    HRManagementSystem hr_system;
    hr_system.employees = {
        {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}},
        {2, {{"name", "Jane"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    auto expected1 = std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>{
        {1, {{"employee_ID", 1}, {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}},
        {2, {{"employee_ID", 2}, {"name", "Jane"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    EXPECT_EQ(hr_system.list_employees(), expected1);

    hr_system.employees = {
        {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    auto expected2 = std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>{
        {1, {{"employee_ID", 1}, {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    EXPECT_EQ(hr_system.list_employees(), expected2);
}

TEST(HRManagementSystemTestListEmployees, test_list_employees_5) {
    HRManagementSystem hr_system;
    hr_system.employees = {
        {1, {{"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}},
        {2, {{"name", "Jane"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    auto expected1 = std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>{
        {1, {{"employee_ID", 1}, {"name", "John"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}},
        {2, {{"employee_ID", 2}, {"name", "Jane"}, {"position", "Manager"}, {"department", "Sales"}, {"salary", 100000}}}
    };
    EXPECT_EQ(hr_system.list_employees(), expected1);

    hr_system.employees = {};
    EXPECT_TRUE(hr_system.list_employees().empty());
}

class HRManagementSystemTestMain : public testing::Test {};

TEST(HRManagementSystemTestMain, test_main) {
    HRManagementSystem hr_system;
    hr_system.add_employee(1, "John Doe", "Manager", "HR", 5000);
    hr_system.add_employee(2, "Jane Smith", "Developer", "IT", 4000);

    auto expected_after_addition = std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>{
        {1, {{"employee_ID", 1}, {"name", "John Doe"}, {"position", "Manager"}, {"department", "HR"}, {"salary", 5000}}},
        {2, {{"employee_ID", 2}, {"name", "Jane Smith"}, {"position", "Developer"}, {"department", "IT"}, {"salary", 4000}}}
    };
    EXPECT_EQ(hr_system.list_employees(), expected_after_addition);

    EXPECT_EQ(hr_system.remove_employee(2), true);

    auto expected_after_removal = std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>{
        {1, {{"employee_ID", 1}, {"name", "John Doe"}, {"position", "Manager"}, {"department", "HR"}, {"salary", 5000}}}
    };
    EXPECT_EQ(hr_system.list_employees(), expected_after_removal);
    EXPECT_EQ(hr_system.remove_employee(2), false);

    EXPECT_EQ(hr_system.update_employee(1, { {"name", "John Doe Jr."}, {"salary", 5500} }), true);

    EXPECT_EQ(hr_system.employees[1], (std::unordered_map<std::string, std::variant<std::string, int>>{
        {"name", "John Doe Jr."},
        { "position", "Manager" },
        { "department", "HR" },
        { "salary", 5500 }
    }));

    EXPECT_EQ(hr_system.update_employee(3, { {"name", "Invalid Employee"} }), false);

    EXPECT_EQ(hr_system.get_employee(1), (std::unordered_map<std::string, std::variant<std::string, int>>{
        {"name", "John Doe Jr."},
        { "position", "Manager" },
        { "department", "HR" },
        { "salary", 5500 }
    }));

    EXPECT_EQ(hr_system.get_employee(2).has_value(), false);

    auto expected_final_list = std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>{
        {1, {{"employee_ID", 1}, {"name", "John Doe Jr."}, {"position", "Manager"}, {"department", "HR"}, {"salary", 5500}}}
    };
    EXPECT_EQ(hr_system.list_employees(), expected_final_list);
}

bool compare_employee_maps(
    const std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>& map1,
    const std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>& map2
) {
    if (map1.size() != map2.size()) return false;
    for (const auto& [id, emp1] : map1) {
        auto it = map2.find(id);
        if (it == map2.end()) return false;
        const auto& emp2 = it->second;
        if (emp1 != emp2) return false;
    }
    return true;
}

TEST(HRManagementSystemTestMain, test_main_2) {
    HRManagementSystem hr_system;

    EXPECT_EQ(hr_system.remove_employee(2), false);
    EXPECT_EQ(hr_system.update_employee(1, { {"name", "John Doe Jr."}, {"salary", 5500} }), false);

    hr_system.add_employee(1, "John Doe", "Manager", "HR", 5000);
    hr_system.add_employee(2, "Jane Smith", "Developer", "IT", 4000);

    auto expected_after_addition = std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>{
        {1, {{"employee_ID", 1}, {"name", "John Doe"}, {"position", "Manager"}, {"department", "HR"}, {"salary", 5000}}},
        {2, {{"employee_ID", 2}, {"name", "Jane Smith"}, {"position", "Developer"}, {"department", "IT"}, {"salary", 4000}}}
    };
    EXPECT_TRUE(compare_employee_maps(hr_system.list_employees(), expected_after_addition));

    EXPECT_EQ(hr_system.remove_employee(2), true);

    auto expected_after_removal_list = std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>{
        {1, {{"employee_ID", 1}, {"name", "John Doe"}, {"position", "Manager"}, {"department", "HR"}, {"salary", 5000}}}
    };
    auto expected_after_removal = std::unordered_map<int, std::unordered_map<std::string, std::variant<std::string, int>>>{
        {1,{{"name", "John Doe"}, {"position", "Manager"}, {"department", "HR"}, {"salary", 5000}}}
    };
    EXPECT_TRUE(compare_employee_maps(hr_system.employees, expected_after_removal));
    EXPECT_TRUE(compare_employee_maps(hr_system.list_employees(), expected_after_removal_list));

    EXPECT_EQ(hr_system.update_employee(1, { {"name", "John Doe Jr."}, {"salary", 5500} }), true);

    EXPECT_EQ(hr_system.employees[1], (std::unordered_map<std::string, std::variant<std::string, int>>{
        {"name", "John Doe Jr."},
        { "position", "Manager" },
        { "department", "HR" },
        { "salary", 5500 }
    }));

    EXPECT_EQ(hr_system.get_employee(1), (std::unordered_map<std::string, std::variant<std::string, int>>{
        {"name", "John Doe Jr."},
        { "position", "Manager" },
        { "department", "HR" },
        { "salary", 5500 }
    }));

    EXPECT_EQ(hr_system.get_employee(2).has_value(), false);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}