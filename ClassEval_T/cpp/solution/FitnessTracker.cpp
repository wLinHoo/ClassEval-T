#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
class FitnessTracker {
public:
    FitnessTracker(double height, double weight, int age, const std::string& sex);
    double get_BMI() const;
    int condition_judge() const;
    double calculate_calorie_intake() const;

private:
    double height;
    double weight;
    int age;
    std::string sex;
    static const std::unordered_map<std::string, std::vector<double>> BMI_std;
};


const std::unordered_map<std::string, std::vector<double>> FitnessTracker::BMI_std = {
    {"male", {20.0, 25.0}},
    {"female", {19.0, 24.0}}
};

FitnessTracker::FitnessTracker(double height, double weight, int age, const std::string& sex)
    : height(height), weight(weight), age(age), sex(sex) {}

double FitnessTracker::get_BMI() const {
    return weight / (height * height);
}

int FitnessTracker::condition_judge() const {
    double BMI = get_BMI();
    const auto& BMI_range = BMI_std.at(sex);
    if (BMI > BMI_range[1]) {
        
        return 1;
    }
    else if (BMI < BMI_range[0]) {
        
        return -1;
    }
    else {
        
        return 0;
    }
}

double FitnessTracker::calculate_calorie_intake() const {
    double BMR;
    if (sex == "male") {
        BMR = 10 * weight + 6.25 * height - 5 * age + 5;
    }
    else {
        BMR = 10 * weight + 6.25 * height - 5 * age - 161;
    }

    int condition = condition_judge();
    double calorie_intake;
    if (condition == 1) {
        calorie_intake = BMR * 1.2;  
    }
    else if (condition == -1) {
        calorie_intake = BMR * 1.6;  
    }
    else {
        calorie_intake = BMR * 1.4;  
    }
    return calorie_intake;
}
