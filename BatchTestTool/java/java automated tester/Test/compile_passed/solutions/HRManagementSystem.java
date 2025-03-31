import java.util.HashMap;
import java.util.Map;

public class HRManagementSystem {
    private Map<Integer, Employee> employees;
    private HashMap<Integer, String> employeesMap;
    private Map<Integer, Map<String, String>> employeesInfo;

    public HRManagementSystem() {
        this.employees = new HashMap<>();
        this.employeesMap = new HashMap<>();
        this.employeesInfo = new HashMap<>();
    }

    public boolean addEmployee(int employeeId, String name, String position, String department, double salary) {
        if (employees.containsKey(employeeId)) {
            return false;
        } else {
            Employee employee = new Employee(name, position, department, salary);
            employees.put(employeeId, employee);
            return true;
        }
    }

    public boolean removeEmployee(int employeeId) {
        if (employeesMap.containsKey(employeeId)) {
            employeesMap.remove(employeeId);
            return true;
        } else {
            return false;
        }
    }

    public Map<Integer, Map<String, String>> listEmployees() {
        Map<Integer, Map<String, String>> employeeData = new HashMap<>();
        if (!employeesInfo.isEmpty()) {
            for (Map.Entry<Integer, Map<String, String>> entry : employeesInfo.entrySet()) {
                int employeeId = entry.getKey();
                Map<String, String> employeeInfo = entry.getValue();
                Map<String, String> employeeDetails = new HashMap<>();
                employeeDetails.put("employee_ID", String.valueOf(employeeId));
                for (Map.Entry<String, String> infoEntry : employeeInfo.entrySet()) {
                    employeeDetails.put(infoEntry.getKey(), infoEntry.getValue());
                }
                employeeData.put(employeeId, employeeDetails);
            }
        }
        return employeeData;
    }

    public boolean updateEmployee(int employeeId, Map<String, String> employeeInfo) {
        Map<String, String> employee = getEmployee(employeeId);
        if (employee == null) {
            return false;
        } else {
            for (String key : employeeInfo.keySet()) {
                if (!employee.containsKey(key)) {
                    return false;
                }
            }
            employee.putAll(employeeInfo);
            return true;
        }
    }

    public Map<String, String> getEmployee(int employeeId) {
        return employeesInfo.get(employeeId);
    }

    private static class Employee {
        private String name;
        private String position;
        private String department;
        private double salary;

        public Employee(String name, String position, String department, double salary) {
            this.name = name;
            this.position = position;
            this.department = department;
            this.salary = salary;
        }
    }
}