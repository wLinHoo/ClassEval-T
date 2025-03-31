
#include <cmath>
#include <limits>
#include <iostream>

class TriCalculator{
public:
    TriCalculator();
    double cos(double x);
    int factorial(int a);
    double taylor(double x, int n);
    double sin(double x);
    double tan(double x);

private:
    static constexpr double PI = 3.14159265358979323846;
    double round(double value, int precision);
};


double TriCalculator::round(double value, int precision) {
    double factor = std::pow(10.0, precision);
    return std::round(value * factor) / factor;
}

TriCalculator::TriCalculator() {
    
}

double TriCalculator::cos(double x) {
    double result = taylor(x, 17);
    std::cout << "Taylor result for cos: " << result << std::endl;
    return round(result, 10);
}

int TriCalculator::factorial(int a) {
    if (a < 0) return 0; 
    if (a == 0) return 1; 
    int b = 1;
    for (int i = 1; i <= a; ++i) {
        b *= i;
    }
    return b;
}

double TriCalculator::taylor(double x, int n) {
    double a = 0.0; 
    x = x / 180.0 * PI; 
    int sign = 1; 

    for (int k = 0; k < n; ++k) {
        double term = std::pow(x, 2 * k) / factorial(2 * k);
        if (k % 2 == 0) {
            a += term;
        }
        else {
            a -= term;
        }
    }
    return a;
}

double TriCalculator::sin(double x) {
    x = x / 180.0 * PI;
    double g = 0.0;
    double t = x;
    int n = 1;

    while (std::fabs(t) >= 1e-15) {
        g += t;
        ++n;
        t = -t * x * x / ((2 * n - 1) * (2 * n - 2));
    }
    return round(g, 10);
}

double TriCalculator::tan(double x) {
    double cosine = cos(x);
    if (std::fabs(cosine) > 0.01) {
        
        double result = sin(x) / cosine;
        
        return round(result, 10);
    }
    else {
        return std::numeric_limits<double>::quiet_NaN(); 
    }
}
