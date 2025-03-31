package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.*;

class HRManagementSystemTestAddEmployee {

    @Test
    public void testAddEmployee() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        assertEquals(true, hrSystem.addEmployee(1, "John Doe", "Manager", "HR", 5000));

        Map<String, Object> expected = new HashMap<>();
        expected.put("name", "John Doe");
        expected.put("position", "Manager");
        expected.put("department", "HR");
        expected.put("salary", 5000.0);

        assertEquals(expected, hrSystem.employees.get(1));
    }

    @Test
    public void testAddEmployee2() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        assertEquals(true, hrSystem.addEmployee(1, "John Doe", "Manager", "HR", 5000));
        assertEquals(false, hrSystem.addEmployee(1, "John Doe", "Manager", "HR", 5000));

        Map<String, Object> expected = new HashMap<>();
        expected.put("name", "John Doe");
        expected.put("position", "Manager");
        expected.put("department", "HR");
        expected.put("salary", 5000.0);

        assertEquals(expected, hrSystem.employees.get(1));
    }

    @Test
    public void testAddEmployee3() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        assertEquals(true, hrSystem.addEmployee(1, "John Doe", "Manager", "HR", 5000));
        assertEquals(true, hrSystem.addEmployee(2, "John Doe", "Manager", "HR", 5000));

        Map<Integer, Map<String, Object>> expected = new HashMap<>();

        Map<String, Object> employee1 = new HashMap<>();
        employee1.put("name", "John Doe");
        employee1.put("position", "Manager");
        employee1.put("department", "HR");
        employee1.put("salary", 5000.0);

        Map<String, Object> employee2 = new HashMap<>();
        employee2.put("name", "John Doe");
        employee2.put("position", "Manager");
        employee2.put("department", "HR");
        employee2.put("salary", 5000.0);

        expected.put(1, employee1);
        expected.put(2, employee2);

        assertEquals(expected, hrSystem.employees);
    }

    @Test
    public void testAddEmployee4() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        assertEquals(true, hrSystem.addEmployee(1, "John Doe", "Manager", "HR", 5000));
        assertEquals(true, hrSystem.addEmployee(2, "John Doe", "Manager", "HR", 5000));
        assertEquals(false, hrSystem.addEmployee(1, "John Doe", "Manager", "HR", 5000));

        Map<Integer, Map<String, Object>> expected = new HashMap<>();

        Map<String, Object> employee1 = new HashMap<>();
        employee1.put("name", "John Doe");
        employee1.put("position", "Manager");
        employee1.put("department", "HR");
        employee1.put("salary", 5000.0);

        Map<String, Object> employee2 = new HashMap<>();
        employee2.put("name", "John Doe");
        employee2.put("position", "Manager");
        employee2.put("department", "HR");
        employee2.put("salary", 5000.0);

        expected.put(1, employee1);
        expected.put(2, employee2);

        assertEquals(expected, hrSystem.employees);
    }

    @Test
    public void testAddEmployee5() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        assertEquals(true, hrSystem.addEmployee(1, "John Doe", "Manager", "HR", 5000));
        assertEquals(true, hrSystem.addEmployee(2, "John Doe", "Manager", "HR", 5000));
        assertEquals(false, hrSystem.addEmployee(1, "John Doe", "Manager", "HR", 5000));
        assertEquals(false, hrSystem.addEmployee(2, "John Doe", "Manager", "HR", 5000));

        Map<Integer, Map<String, Object>> expected = new HashMap<>();

        Map<String, Object> employee1 = new HashMap<>();
        employee1.put("name", "John Doe");
        employee1.put("position", "Manager");
        employee1.put("department", "HR");
        employee1.put("salary", 5000.0);

        Map<String, Object> employee2 = new HashMap<>();
        employee2.put("name", "John Doe");
        employee2.put("position", "Manager");
        employee2.put("department", "HR");
        employee2.put("salary", 5000.0);

        expected.put(1, employee1);
        expected.put(2, employee2);

        assertEquals(expected, hrSystem.employees);
    }
}

class HRManagementSystemTestRemoveEmployee {

    @Test
    public void testRemoveEmployee() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        hrSystem.employees = new HashMap<>();
        Map<String, Object> employee = new HashMap<>();
        employee.put("name", "John");
        employee.put("position", "Manager");
        employee.put("department", "Sales");
        employee.put("salary", 100000);
        hrSystem.employees.put(1, employee);

        assertEquals(true, hrSystem.removeEmployee(1));
        assertEquals(new HashMap<Integer, Map<String, Object>>(), hrSystem.employees);
    }

    @Test
    public void testRemoveEmployee2() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        hrSystem.employees = new HashMap<>();
        Map<String, Object> employee = new HashMap<>();
        employee.put("name", "John");
        employee.put("position", "Manager");
        employee.put("department", "Sales");
        employee.put("salary", 100000);
        hrSystem.employees.put(1, employee);

        assertEquals(true, hrSystem.removeEmployee(1));
        assertEquals(false, hrSystem.removeEmployee(1));
        assertEquals(new HashMap<Integer, Map<String, Object>>(), hrSystem.employees);
    }

    @Test
    public void testRemoveEmployee3() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        hrSystem.employees = new HashMap<>();

        Map<String, Object> employee1 = new HashMap<>();
        employee1.put("name", "John");
        employee1.put("position", "Manager");
        employee1.put("department", "Sales");
        employee1.put("salary", 100000);

        Map<String, Object> employee2 = new HashMap<>();
        employee2.put("name", "John");
        employee2.put("position", "Manager");
        employee2.put("department", "Sales");
        employee2.put("salary", 100000);

        hrSystem.employees.put(1, employee1);
        hrSystem.employees.put(2, employee2);

        assertEquals(true, hrSystem.removeEmployee(1));

        Map<Integer, Map<String, Object>> expected = new HashMap<>();
        expected.put(2, employee2);

        assertEquals(expected, hrSystem.employees);
    }

    @Test
    public void testRemoveEmployee4() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        hrSystem.employees = new HashMap<>();

        Map<String, Object> employee1 = new HashMap<>();
        employee1.put("name", "John");
        employee1.put("position", "Manager");
        employee1.put("department", "Sales");
        employee1.put("salary", 100000);

        Map<String, Object> employee2 = new HashMap<>();
        employee2.put("name", "John");
        employee2.put("position", "Manager");
        employee2.put("department", "Sales");
        employee2.put("salary", 100000);

        hrSystem.employees.put(1, employee1);
        hrSystem.employees.put(2, employee2);

        assertEquals(true, hrSystem.removeEmployee(1));
        assertEquals(true, hrSystem.removeEmployee(2));

        assertEquals(new HashMap<Integer, Map<String, Object>>(), hrSystem.employees);
    }

    @Test
    public void testRemoveEmployee5() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        hrSystem.employees = new HashMap<>();

        Map<String, Object> employee1 = new HashMap<>();
        employee1.put("name", "John");
        employee1.put("position", "Manager");
        employee1.put("department", "Sales");
        employee1.put("salary", 100000);

        Map<String, Object> employee2 = new HashMap<>();
        employee2.put("name", "John");
        employee2.put("position", "Manager");
        employee2.put("department", "Sales");
        employee2.put("salary", 100000);

        hrSystem.employees.put(1, employee1);
        hrSystem.employees.put(2, employee2);

        assertEquals(true, hrSystem.removeEmployee(1));
        assertEquals(true, hrSystem.removeEmployee(2));
        assertEquals(false, hrSystem.removeEmployee(1));
        assertEquals(false, hrSystem.removeEmployee(2));

        assertEquals(new HashMap<Integer, Map<String, Object>>(), hrSystem.employees);
    }
}

class HRManagementSystemTestUpdateEmployee {

    @Test
    public void testUpdateEmployee() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee = new HashMap<>();
        employee.put("name", "John");
        employee.put("position", "Manager");
        employee.put("department", "Sales");
        employee.put("salary", 100000);

        hrSystem.employees.put(1, employee);

        Map<String, Object> updatedEmployee = new HashMap<>();
        updatedEmployee.put("name", "John");
        updatedEmployee.put("position", "Manager");
        updatedEmployee.put("department", "Sales");
        updatedEmployee.put("salary", 20000);

        assertEquals(true, hrSystem.updateEmployee(1, updatedEmployee));
        assertEquals(updatedEmployee, hrSystem.employees.get(1));
    }

    @Test
    public void testUpdateEmployee2() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        hrSystem.employees = new HashMap<>();

        Map<String, Object> updatedEmployee = new HashMap<>();
        updatedEmployee.put("name", "John");
        updatedEmployee.put("position", "Manager");
        updatedEmployee.put("department", "Sales");
        updatedEmployee.put("salary", 20000);

        assertEquals(false, hrSystem.updateEmployee(1, updatedEmployee));
        assertEquals(new HashMap<Integer, Map<String, Object>>(), hrSystem.employees);
    }

    @Test
    public void testUpdateEmployee3() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee = new HashMap<>();
        employee.put("name", "John");
        employee.put("position", "Manager");
        employee.put("department", "Sales");
        employee.put("salary", 100000);

        hrSystem.employees.put(1, employee);

        Map<String, Object> updatedEmployee = new HashMap<>();
        updatedEmployee.put("name", "John");
        updatedEmployee.put("position", "Manager");
        updatedEmployee.put("department", "Sales");
        updatedEmployee.put("salary", 20000);

        assertEquals(false, hrSystem.updateEmployee(2, updatedEmployee));
        assertEquals(employee, hrSystem.employees.get(1));
    }

    @Test
    public void testUpdateEmployee4() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee = new HashMap<>();
        employee.put("name", "John");
        employee.put("position", "Manager");
        employee.put("department", "Sales");
        employee.put("salary", 100000);

        hrSystem.employees.put(1, employee);

        Map<String, Object> updatedEmployee = new HashMap<>();
        updatedEmployee.put("name", "John");
        updatedEmployee.put("position", "Manager");
        updatedEmployee.put("department", "Sales");
        updatedEmployee.put("salary", 20000);

        assertEquals(true, hrSystem.updateEmployee(1, updatedEmployee));
        assertEquals(true, hrSystem.updateEmployee(1, updatedEmployee));
        assertEquals(updatedEmployee, hrSystem.employees.get(1));
    }

    @Test
    public void testUpdateEmployee5() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee = new HashMap<>();
        employee.put("name", "John");
        employee.put("position", "Manager");
        employee.put("department", "Sales");
        employee.put("salary", 100000);

        hrSystem.employees.put(1, employee);

        Map<String, Object> updatedEmployee1 = new HashMap<>();
        updatedEmployee1.put("name", "John");
        updatedEmployee1.put("position", "Manager");
        updatedEmployee1.put("department", "Sales");
        updatedEmployee1.put("salary", 20000);

        Map<String, Object> updatedEmployee2 = new HashMap<>();
        updatedEmployee2.put("name", "John");
        updatedEmployee2.put("position", "Manager");
        updatedEmployee2.put("department", "Sales");
        updatedEmployee2.put("salary", 100000);

        assertEquals(true, hrSystem.updateEmployee(1, updatedEmployee1));
        assertEquals(true, hrSystem.updateEmployee(1, updatedEmployee1));
        assertEquals(true, hrSystem.updateEmployee(1, updatedEmployee2));
        assertEquals(updatedEmployee2, hrSystem.employees.get(1));
    }

    @Test
    public void testUpdateEmployee6() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee = new HashMap<>();
        employee.put("name", "John");
        employee.put("position", "Manager");
        employee.put("department", "Sales");
        employee.put("salary", 100000);

        hrSystem.employees.put(1, employee);

        Map<String, Object> updatedEmployee = new HashMap<>();
        updatedEmployee.put("Name", "John");
        updatedEmployee.put("position", "Manager");
        updatedEmployee.put("department", "Sales");
        updatedEmployee.put("salary", 20000);

        assertEquals(false, hrSystem.updateEmployee(1, updatedEmployee));
    }
}

class HRManagementSystemTestGetEmployee {

    @Test
    public void testGetEmployee() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee = new HashMap<>();
        employee.put("name", "John");
        employee.put("position", "Manager");
        employee.put("department", "Sales");
        employee.put("salary", 100000);

        hrSystem.employees.put(1, employee);

        assertEquals(employee, hrSystem.getEmployee(1));
    }

    @Test
    public void testGetEmployee2() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        hrSystem.employees = new HashMap<>();

        assertEquals(false, hrSystem.getEmployee(1));
    }

    @Test
    public void testGetEmployee3() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee = new HashMap<>();
        employee.put("name", "John");
        employee.put("position", "Manager");
        employee.put("department", "Sales");
        employee.put("salary", 100000);

        hrSystem.employees.put(1, employee);

        assertEquals(false, hrSystem.getEmployee(2));
    }

    @Test
    public void testGetEmployee4() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee = new HashMap<>();
        employee.put("name", "John");
        employee.put("position", "Manager");
        employee.put("department", "Sales");
        employee.put("salary", 100000);

        hrSystem.employees.put(1, employee);

        assertEquals(employee, hrSystem.getEmployee(1));
        assertEquals(employee, hrSystem.getEmployee(1));
    }

    @Test
    public void testGetEmployee5() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee1 = new HashMap<>();
        employee1.put("name", "John");
        employee1.put("position", "Manager");
        employee1.put("department", "Sales");
        employee1.put("salary", 100000);

        Map<String, Object> employee2 = new HashMap<>();
        employee2.put("name", "Jane");
        employee2.put("position", "Manager");
        employee2.put("department", "Sales");
        employee2.put("salary", 100000);

        hrSystem.employees.put(1, employee1);
        hrSystem.employees.put(2, employee2);

        assertEquals(employee1, hrSystem.getEmployee(1));
        assertEquals(employee2, hrSystem.getEmployee(2));
    }
}

class HRManagementSystemTestListEmployees {

    @Test
    public void testListEmployees() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee = new HashMap<>();
        employee.put("name", "John");
        employee.put("position", "Manager");
        employee.put("department", "Sales");
        employee.put("salary", 100000);

        hrSystem.employees.put(1, employee);

        Map<Integer, Map<String, Object>> expected = new HashMap<>();
        Map<String, Object> expectedEmployee = new HashMap<>(employee);
        expectedEmployee.put("employee_ID", 1);
        expected.put(1, expectedEmployee);

        assertEquals(expected, hrSystem.listEmployees());
    }

    @Test
    public void testListEmployees2() {
        HRManagementSystem hrSystem = new HRManagementSystem();
        hrSystem.employees = new HashMap<>();

        assertEquals(new HashMap<Integer, Map<String, Object>>(), hrSystem.listEmployees());
    }

    @Test
    public void testListEmployees3() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee1 = new HashMap<>();
        employee1.put("name", "John");
        employee1.put("position", "Manager");
        employee1.put("department", "Sales");
        employee1.put("salary", 100000);

        Map<String, Object> employee2 = new HashMap<>();
        employee2.put("name", "Jane");
        employee2.put("position", "Manager");
        employee2.put("department", "Sales");
        employee2.put("salary", 100000);

        hrSystem.employees.put(1, employee1);
        hrSystem.employees.put(2, employee2);

        Map<Integer, Map<String, Object>> expected = new HashMap<>();

        Map<String, Object> expectedEmployee1 = new HashMap<>(employee1);
        expectedEmployee1.put("employee_ID", 1);

        Map<String, Object> expectedEmployee2 = new HashMap<>(employee2);
        expectedEmployee2.put("employee_ID", 2);

        expected.put(1, expectedEmployee1);
        expected.put(2, expectedEmployee2);

        assertEquals(expected, hrSystem.listEmployees());
    }

    @Test
    public void testListEmployees4() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee1 = new HashMap<>();
        employee1.put("name", "John");
        employee1.put("position", "Manager");
        employee1.put("department", "Sales");
        employee1.put("salary", 100000);

        Map<String, Object> employee2 = new HashMap<>();
        employee2.put("name", "Jane");
        employee2.put("position", "Manager");
        employee2.put("department", "Sales");
        employee2.put("salary", 100000);

        hrSystem.employees.put(1, employee1);
        hrSystem.employees.put(2, employee2);

        Map<Integer, Map<String, Object>> expected = new HashMap<>();

        Map<String, Object> expectedEmployee1 = new HashMap<>(employee1);
        expectedEmployee1.put("employee_ID", 1);

        Map<String, Object> expectedEmployee2 = new HashMap<>(employee2);
        expectedEmployee2.put("employee_ID", 2);

        expected.put(1, expectedEmployee1);
        expected.put(2, expectedEmployee2);

        assertEquals(expected, hrSystem.listEmployees());

        hrSystem.employees = new HashMap<>();
        hrSystem.employees.put(1, employee1);

        expected = new HashMap<>();
        expectedEmployee1 = new HashMap<>(employee1);
        expectedEmployee1.put("employee_ID", 1);
        expected.put(1, expectedEmployee1);

        assertEquals(expected, hrSystem.listEmployees());
    }

    @Test
    public void testListEmployees5() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        Map<String, Object> employee1 = new HashMap<>();
        employee1.put("name", "John");
        employee1.put("position", "Manager");
        employee1.put("department", "Sales");
        employee1.put("salary", 100000);

        Map<String, Object> employee2 = new HashMap<>();
        employee2.put("name", "Jane");
        employee2.put("position", "Manager");
        employee2.put("department", "Sales");
        employee2.put("salary", 100000);

        hrSystem.employees.put(1, employee1);
        hrSystem.employees.put(2, employee2);

        Map<Integer, Map<String, Object>> expected = new HashMap<>();

        Map<String, Object> expectedEmployee1 = new HashMap<>(employee1);
        expectedEmployee1.put("employee_ID", 1);

        Map<String, Object> expectedEmployee2 = new HashMap<>(employee2);
        expectedEmployee2.put("employee_ID", 2);

        expected.put(1, expectedEmployee1);
        expected.put(2, expectedEmployee2);

        assertEquals(expected, hrSystem.listEmployees());

        hrSystem.employees = new HashMap<>();

        assertEquals(new HashMap<Integer, Map<String, Object>>(), hrSystem.listEmployees());
    }
}

class HRManagementSystemTestMain {

    @Test
    public void testMain() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        hrSystem.addEmployee(1, "John Doe", "Manager", "HR", 5000);
        hrSystem.addEmployee(2, "Jane Smith", "Developer", "IT", 4000);

        Map<Integer, Map<String, Object>> expected = new HashMap<>();

        Map<String, Object> employee1 = new HashMap<>();
        employee1.put("employee_ID", 1);
        employee1.put("name", "John Doe");
        employee1.put("position", "Manager");
        employee1.put("department", "HR");
        employee1.put("salary", 5000.0);

        Map<String, Object> employee2 = new HashMap<>();
        employee2.put("employee_ID", 2);
        employee2.put("name", "Jane Smith");
        employee2.put("position", "Developer");
        employee2.put("department", "IT");
        employee2.put("salary", 4000.0);

        expected.put(1, employee1);
        expected.put(2, employee2);

        assertEquals(expected, hrSystem.listEmployees());

        hrSystem.removeEmployee(2);

        expected.remove(2);

        assertEquals(expected, hrSystem.listEmployees());
        assertFalse(hrSystem.removeEmployee(2));

        Map<String, Object> updatedEmployee = new HashMap<>();
        updatedEmployee.put("name", "John Doe Jr.");
        updatedEmployee.put("salary", 5500.0
        );

        assertTrue(hrSystem.updateEmployee(1, updatedEmployee));

        Map<String, Object> expectedEmployee1 = new HashMap<>();
        expectedEmployee1.put("name", "John Doe Jr.");
        expectedEmployee1.put("position", "Manager");
        expectedEmployee1.put("department", "HR");
        expectedEmployee1.put("salary", 5500.0);

        assertEquals(expectedEmployee1, hrSystem.employees.get(1));

        Map<String, Object> invalidEmployee = new HashMap<>();
        invalidEmployee.put("name", "Invalid Employee");

        assertFalse(hrSystem.updateEmployee(3, invalidEmployee));

        assertEquals(expectedEmployee1, hrSystem.getEmployee(1));
        assertFalse(hrSystem.getEmployee(2) instanceof Map);

        expected.put(1, new HashMap<>(expectedEmployee1));
        expected.get(1).put("employee_ID", 1);

        assertEquals(expected, hrSystem.listEmployees());
    }

    @Test
    public void testMain2() {
        HRManagementSystem hrSystem = new HRManagementSystem();

        assertFalse(hrSystem.removeEmployee(2));

        Map<String, Object> updatedEmployee = new HashMap<>();
        updatedEmployee.put("name", "John Doe Jr.");
        updatedEmployee.put("salary", 5500.0);

        assertFalse(hrSystem.updateEmployee(1, updatedEmployee));

        hrSystem.addEmployee(1, "John Doe", "Manager", "HR", 5000);
        hrSystem.addEmployee(2, "Jane Smith", "Developer", "IT", 4000);

        Map<Integer, Map<String, Object>> expected = new HashMap<>();

        Map<String, Object> employee1 = new HashMap<>();
        employee1.put("employee_ID", 1);
        employee1.put("name", "John Doe");
        employee1.put("position", "Manager");
        employee1.put("department", "HR");
        employee1.put("salary", 5000.0);

        Map<String, Object> employee2 = new HashMap<>();
        employee2.put("employee_ID", 2);
        employee2.put("name", "Jane Smith");
        employee2.put("position", "Developer");
        employee2.put("department", "IT");
        employee2.put("salary", 4000.0);

        expected.put(1, employee1);
        expected.put(2, employee2);

        assertEquals(expected, hrSystem.listEmployees());

        assertTrue(hrSystem.removeEmployee(2));
        hrSystem.employees.remove(2);
        expected.remove(2);

        assertEquals(expected, hrSystem.listEmployees());

        updatedEmployee = new HashMap<>();
        updatedEmployee.put("name", "John Doe Jr.");
        updatedEmployee.put("salary", 5500.0);

        assertTrue(hrSystem.updateEmployee(1, updatedEmployee));

        Map<String, Object> expectedEmployee1 = new HashMap<>();
        expectedEmployee1.put("name", "John Doe Jr.");
        expectedEmployee1.put("position", "Manager");
        expectedEmployee1.put("department", "HR");
        expectedEmployee1.put("salary", 5500.0);

        assertEquals(expectedEmployee1, hrSystem.employees.get(1));
        assertEquals(expectedEmployee1, hrSystem.getEmployee(1));
        assertFalse(hrSystem.getEmployee(2) instanceof Map);
    }
}

