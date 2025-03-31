package org.example;

public class FitnessTracker {
    private double height;
    private double weight;
    private int age;
    private String sex;
    private double[][] BMI_std = { {20, 25}, {19, 24} };

    public FitnessTracker(double height, double weight, int age, String sex) {
        this.height = height;
        this.weight = weight;
        this.age = age;
        this.sex = sex;
    }

    public double getBMI() {
        return weight / (height * height);
    }

    public int conditionJudge() {
        double BMI = getBMI();
        int index = sex.equals("male") ? 0 : 1;
        if (BMI > BMI_std[index][1]) {
            return 1;
        }
        else if (BMI < BMI_std[index][0]) {
            return -1;
        }
        else {
            return 0;
        }
    }

    public double calculateCalorieIntake() {
        double BMR;
        if (sex.equals("male")) {
            BMR = 10 * weight + 6.25 * height - 5 * age + 5;
        }
        else {
            BMR = 10 * weight + 6.25 * height - 5 * age - 161;
        }

        int condition = conditionJudge();
        if (condition == 1) {
            return BMR * 1.2;
        }
        else if (condition == -1) {
            return BMR * 1.6;
        }
        else {
            return BMR * 1.4;
        }
    }
}