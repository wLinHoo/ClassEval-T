package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class AreaCalculatorTest {

    @Test
    public void testCalculateCircleArea() {
        AreaCalculator areaCalculator = new AreaCalculator(2);
        assertEquals(12.56, areaCalculator.calculateCircleArea(), 0.01);
    }

    @Test
    public void testCalculateCircleArea2() {
        AreaCalculator areaCalculator = new AreaCalculator(2.5);
        assertEquals(19.63, areaCalculator.calculateCircleArea(), 0.01);
    }

    @Test
    public void testCalculateCircleArea3() {
        AreaCalculator areaCalculator = new AreaCalculator(2000);
        assertEquals(12566370.61, areaCalculator.calculateCircleArea(), 0.01);
    }

    @Test
    public void testCalculateCircleArea4() {
        AreaCalculator areaCalculator = new AreaCalculator(0);
        assertEquals(0, areaCalculator.calculateCircleArea(), 0.01);
    }

    @Test
    public void testCalculateCircleArea5() {
        AreaCalculator areaCalculator = new AreaCalculator(0.1);
        assertEquals(0.031, areaCalculator.calculateCircleArea(), 0.01);
    }

    @Test
    public void testCalculateSphereArea() {
        AreaCalculator areaCalculator = new AreaCalculator(2);
        assertEquals(50.27, areaCalculator.calculateSphereArea(), 0.01);
    }

    @Test
    public void testCalculateSphereArea2() {
        AreaCalculator areaCalculator = new AreaCalculator(2.5);
        assertEquals(78.54, areaCalculator.calculateSphereArea(), 0.01);
    }

    @Test
    public void testCalculateSphereArea3() {
        AreaCalculator areaCalculator = new AreaCalculator(2000);
        assertEquals(50265482.45743669, areaCalculator.calculateSphereArea(), 0.01);
    }

    @Test
    public void testCalculateSphereArea4() {
        AreaCalculator areaCalculator = new AreaCalculator(0);
        assertEquals(0, areaCalculator.calculateSphereArea(), 0.01);
    }

    @Test
    public void testCalculateSphereArea5() {
        AreaCalculator areaCalculator = new AreaCalculator(0.1);
        assertEquals(0.1256, areaCalculator.calculateSphereArea(), 0.01);
    }

    @Test
    public void testCalculateCylinderArea() {
        AreaCalculator areaCalculator = new AreaCalculator(2);
        assertEquals(50.27, areaCalculator.calculateCylinderArea(2), 0.01);
    }

    @Test
    public void testCalculateCylinderArea2() {
        AreaCalculator areaCalculator = new AreaCalculator(2);
        assertEquals(25.13, areaCalculator.calculateCylinderArea(0), 0.01);
    }

    @Test
    public void testCalculateCylinderArea3() {
        AreaCalculator areaCalculator = new AreaCalculator(0);
        assertEquals(0, areaCalculator.calculateCylinderArea(2000), 0.01);
    }

    @Test
    public void testCalculateCylinderArea4() {
        AreaCalculator areaCalculator = new AreaCalculator(2.5);
        assertEquals(70.68, areaCalculator.calculateCylinderArea(2), 0.01);
    }

    @Test
    public void testCalculateCylinderArea5() {
        AreaCalculator areaCalculator = new AreaCalculator(2.5);
        assertEquals(62.83, areaCalculator.calculateCylinderArea(1.5), 0.01);
    }

    @Test
    public void testCalculateSectorArea() {
        AreaCalculator areaCalculator = new AreaCalculator(1.5);
        assertEquals(3.53, areaCalculator.calculateSectorArea(Math.PI), 0.01);
    }

    @Test
    public void testCalculateSectorArea2() {
        AreaCalculator areaCalculator = new AreaCalculator(2);
        assertEquals(3.14, areaCalculator.calculateSectorArea(Math.PI / 2), 0.01);
    }

    @Test
    public void testCalculateSectorArea3() {
        AreaCalculator areaCalculator = new AreaCalculator(2);
        assertEquals(0, areaCalculator.calculateSectorArea(0), 0.01);
    }

    @Test
    public void testCalculateSectorArea4() {
        AreaCalculator areaCalculator = new AreaCalculator(2);
        assertEquals(12.56, areaCalculator.calculateSectorArea(2 * Math.PI), 0.01);
    }

    @Test
    public void testCalculateSectorArea5() {
        AreaCalculator areaCalculator = new AreaCalculator(0);
        assertEquals(0, areaCalculator.calculateSectorArea(Math.PI), 0.01);
    }

    @Test
    public void testCalculateAnnulusArea() {
        AreaCalculator areaCalculator = new AreaCalculator(2);
        assertEquals(25.13, areaCalculator.calculateAnnulusArea(1, 3), 0.01);
    }

    @Test
    public void testCalculateAnnulusArea2() {
        AreaCalculator areaCalculator = new AreaCalculator(2.5);
        assertEquals(0, areaCalculator.calculateAnnulusArea(3, 3), 0.01);
    }

    @Test
    public void testCalculateAnnulusArea3() {
        AreaCalculator areaCalculator = new AreaCalculator(2000);
        assertEquals(3.14, areaCalculator.calculateAnnulusArea(0, 1), 0.01);
    }

    @Test
    public void testCalculateAnnulusArea4() {
        AreaCalculator areaCalculator = new AreaCalculator(0);
        assertEquals(25.13, areaCalculator.calculateAnnulusArea(1, 3), 0.01);
    }

    @Test
    public void testCalculateAnnulusArea5() {
        AreaCalculator areaCalculator = new AreaCalculator(2.5);
        assertEquals(25.13, areaCalculator.calculateAnnulusArea(1, 3), 0.01);
    }

    @Test
    public void testMain() {
        AreaCalculator areaCalculator = new AreaCalculator(2);
        assertEquals(12.56, areaCalculator.calculateCircleArea(), 0.01);
        assertEquals(50.27, areaCalculator.calculateSphereArea(), 0.01);
        assertEquals(50.27, areaCalculator.calculateCylinderArea(2), 0.01);
        assertEquals(6.28, areaCalculator.calculateSectorArea(Math.PI), 0.01);
        assertEquals(25.13, areaCalculator.calculateAnnulusArea(1, 3), 0.01);
    }
}