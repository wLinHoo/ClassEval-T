#include <cmath>
#include <stdexcept>
#include <gtest/gtest.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class AreaCalculator {
public:
    explicit AreaCalculator(double radius);

    double calculate_circle_area() const;
    double calculate_sphere_area() const;
    double calculate_cylinder_area(double height) const;
    double calculate_sector_area(double angle) const;
    double calculate_annulus_area(double inner_radius, double outer_radius) const;

private:
    double radius;
};
AreaCalculator::AreaCalculator(double radius) : radius(radius) {
    if (radius < 0) throw std::invalid_argument("Radius cannot be negative.");
}

double AreaCalculator::calculate_circle_area() const {
    return M_PI * radius * radius;
}

double AreaCalculator::calculate_sphere_area() const {
    return 4 * M_PI * radius * radius;
}

double AreaCalculator::calculate_cylinder_area(double height) const {
    if (height < 0) throw std::invalid_argument("Height cannot be negative.");
    return 2 * M_PI * radius * (radius + height);
}

double AreaCalculator::calculate_sector_area(double angle) const {
    return 0.5 * radius * radius * angle;
}

double AreaCalculator::calculate_annulus_area(double inner_radius, double outer_radius) const {
    if (inner_radius > outer_radius) throw std::invalid_argument("Inner radius cannot be greater than outer radius.");
    return M_PI * (outer_radius * outer_radius - inner_radius * inner_radius);
}
