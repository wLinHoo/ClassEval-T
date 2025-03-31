package org.example;

import java.util.*;

public class HRManagementSystem {
    public Map<Integer, Map<String, Object>> employees;

    public HRManagementSystem() {
        this.employees = new HashMap<>();
    }

    public boolean addEmployee(int employeeId, String name, String position, String department, double salary) {
        if (employees.containsKey(employeeId)) {
            return false;
        } else {
            Map<String, Object> employeeInfo = new HashMap<>();
            employeeInfo.put("name", name);
            employeeInfo.put("position", position);
            employeeInfo.put("department", department);
            employeeInfo.put("salary", salary);
            employees.put(employeeId, employeeInfo);
            return true;
        }
    }

    public boolean removeEmployee(int employeeId) {
        if (employees.containsKey(employeeId)) {
            employees.remove(employeeId);
            return true;
        }
        else {
            return false;
        }
    }

    public boolean updateEmployee(int employeeId, Map<String, Object> updatedEmployeeInfo) {
        Map<String, Object> employeeInfo = employees.get(employeeId);
        if (employeeInfo == null) {
            return false;
        }
        else {
            Set<String> validKeys = Set.of("name", "position", "department", "salary");
            for (String key : updatedEmployeeInfo.keySet()) {
                if (!validKeys.contains(key)) {
                    return false;
                }
            }
            employeeInfo.putAll(updatedEmployeeInfo);
            return true;
        }
    }

    public Object getEmployee(int employeeId) {
        Map<String, Object> employeeInfo = employees.get(employeeId);
        if (employeeInfo == null) {
            return false;
        } else {
            return employeeInfo;
        }
    }

    public Map<Integer, Map<String, Object>> listEmployees() {
        Map<Integer, Map<String, Object>> employeeData = new HashMap<>();
        for (Map.Entry<Integer, Map<String, Object>> entry : employees.entrySet()) {
            int employeeId = entry.getKey();
            Map<String, Object> employeeInfo = new HashMap<>(entry.getValue());
            employeeInfo.put("employee_ID", employeeId);
            employeeData.put(employeeId, employeeInfo);
        }
        return employeeData;
    }
}