package org.example;

public class ComplexCalculator {

    public ComplexNumber add(ComplexNumber c1, ComplexNumber c2) {
        double real = c1.getReal() + c2.getReal();
        double imaginary = c1.getImaginary() + c2.getImaginary();
        return new ComplexNumber(real, imaginary);
    }

    public ComplexNumber subtract(ComplexNumber c1, ComplexNumber c2) {
        double real = c1.getReal() - c2.getReal();
        double imaginary = c1.getImaginary() - c2.getImaginary();
        return new ComplexNumber(real, imaginary);
    }

    public ComplexNumber multiply(ComplexNumber c1, ComplexNumber c2) {
        double real = c1.getReal() * c2.getReal() - c1.getImaginary() * c2.getImaginary();
        double imaginary = c1.getReal() * c2.getImaginary() + c1.getImaginary() * c2.getReal();
        return new ComplexNumber(real, imaginary);
    }

    public ComplexNumber divide(ComplexNumber c1, ComplexNumber c2) {
        double denominator = c2.getReal() * c2.getReal() + c2.getImaginary() * c2.getImaginary();
        double real = (c1.getReal() * c2.getReal() + c1.getImaginary() * c2.getImaginary()) / denominator;
        double imaginary = (c1.getImaginary() * c2.getReal() - c1.getReal() * c2.getImaginary()) / denominator;
        return new ComplexNumber(real, imaginary);
    }

    public static class ComplexNumber {
        private double real;
        private double imaginary;

        public ComplexNumber(double real, double imaginary) {
            this.real = real;
            this.imaginary = imaginary;
        }

        public double getReal() {
            return real;
        }

        public double getImaginary() {
            return imaginary;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            ComplexNumber that = (ComplexNumber) obj;
            return Double.compare(that.real, real) == 0 && Double.compare(that.imaginary, imaginary) == 0;
        }

        @Override
        public String toString() {
            return real + (imaginary >= 0 ? "+" : "") + imaginary + "j";
        }
    }
}
