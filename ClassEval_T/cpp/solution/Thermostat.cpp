#include <string>

class Thermostat {
public:
    Thermostat(double current_temperature, double target_temperature, const std::string& mode);

    double get_target_temperature() const;
    void set_target_temperature(double temperature);

    std::string get_mode() const;
    bool set_mode(const std::string& mode);

    void auto_set_mode();
    bool auto_check_conflict();
    int simulate_operation();

    double current_temperature;
    double target_temperature;
    std::string mode;
};
Thermostat::Thermostat(double current_temperature, double target_temperature, const std::string& mode)
    : current_temperature(current_temperature), target_temperature(target_temperature), mode(mode) {}

double Thermostat::get_target_temperature() const {
    return target_temperature;
}

void Thermostat::set_target_temperature(double temperature) {
    target_temperature = temperature;
}

std::string Thermostat::get_mode() const {
    return mode;
}

bool Thermostat::set_mode(const std::string& new_mode) {
    if (new_mode == "heat" || new_mode == "cool") {
        mode = new_mode;
        return true;
    }
    return false;
}

void Thermostat::auto_set_mode() {
    if (current_temperature < target_temperature) {
        mode = "heat";
    }
    else {
        mode = "cool";
    }
}

bool Thermostat::auto_check_conflict() {
    if (current_temperature > target_temperature) {
        if (mode == "cool") {
            return true;
        }
        else {
            auto_set_mode();
            return false;
        }
    }
    else {
        if (mode == "heat") {
            return true;
        }
        else {
            auto_set_mode();
            return false;
        }
    }
}

int Thermostat::simulate_operation() {
    auto_set_mode();
    int use_time = 0;
    if (mode == "heat") {
        while (current_temperature < target_temperature) {
            current_temperature += 1;
            use_time += 1;
        }
    }
    else {
        while (current_temperature > target_temperature) {
            current_temperature -= 1;
            use_time += 1;
        }
    }
    return use_time;
}
