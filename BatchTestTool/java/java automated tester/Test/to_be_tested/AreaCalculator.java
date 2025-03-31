package to_be_tested;

import java.lang.Math;

public class AreaCalculator {

    public double radius;

    public AreaCalculator(double radius) {
        this.radius = radius;
    }

    public double calculateSphereArea() {
        return 4 * Math.PI * Math.pow(radius, 2);
    }

    public double calculateCylinderArea(double height) {
        return 2 * Math.PI * radius * (radius + height);
    }

    public double calculateSectorArea(double angle) {
        return radius * radius * angle / 2;
    }

    public double calculateAnnulusArea(double innerRadius, double outerRadius) {
        return Math.PI * (outerRadius * outerRadius - innerRadius * innerRadius);
    }

    public double calculateCircleArea() {
        return Math.PI * Math.pow(radius, 2);
    }
}
