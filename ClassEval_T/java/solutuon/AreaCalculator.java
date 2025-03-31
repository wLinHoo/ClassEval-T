package org.example;

import java.lang.Math;

public class AreaCalculator {

    private double radius;

    public AreaCalculator(double radius) {
        this.radius = radius;
    }

    public double calculateCircleArea() {
        return Math.PI * Math.pow(this.radius, 2);
    }

    public double calculateSphereArea() {
        return 4 * Math.PI * Math.pow(this.radius, 2);
    }

    public double calculateCylinderArea(double height) {
        return 2 * Math.PI * this.radius * (this.radius + height);
    }

    public double calculateSectorArea(double angle) {
        return Math.pow(this.radius, 2) * angle / 2;
    }

    public double calculateAnnulusArea(double innerRadius, double outerRadius) {
        return Math.PI * (Math.pow(outerRadius, 2) - Math.pow(innerRadius, 2));
    }

    public static void main(String[] args) {
        AreaCalculator areaCalculator = new AreaCalculator(2);

        System.out.println("Circle Area: " + areaCalculator.calculateCircleArea());
        System.out.println("Sphere Area: " + areaCalculator.calculateSphereArea());
        System.out.println("Cylinder Area: " + areaCalculator.calculateCylinderArea(3));
        System.out.println("Sector Area: " + areaCalculator.calculateSectorArea(Math.PI));
        System.out.println("Annulus Area: " + areaCalculator.calculateAnnulusArea(2, 3));
    }
}