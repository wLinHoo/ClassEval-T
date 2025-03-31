#include <string>
#include <map>


struct WeatherInfo {
    std::string weather;
    double temperature;
    std::string temperature_units;
};

class WeatherSystem {
public:
    WeatherSystem(const std::string& city);

    std::pair<double, std::string> query(const std::map<std::string, WeatherInfo>& weather_list, const std::string& tmp_units = "celsius");
    void set_city(const std::string& city);
    void set_temperature(double temperature);

    double celsius_to_fahrenheit() const;
    double fahrenheit_to_celsius() const;

    std::string get_city() const;

private:
    double temperature;
    std::string weather;
    std::string city;
    std::map<std::string, WeatherInfo> weather_list;
};



WeatherSystem::WeatherSystem(const std::string& city) : city(city), temperature(0.0), weather("") {}


std::pair<double, std::string> WeatherSystem::query(const std::map<std::string, WeatherInfo>& weather_list, const std::string& tmp_units) {
    this->weather_list = weather_list;
    auto it = this->weather_list.find(this->city);
    if (it == this->weather_list.end()) {
        return { 0.0, "" };
    }
    else {
        this->temperature = it->second.temperature;
        this->weather = it->second.weather;
    }

    if (it->second.temperature_units != tmp_units) {
        if (tmp_units == "celsius") {
            return { fahrenheit_to_celsius(), this->weather };
        }
        else if (tmp_units == "fahrenheit") {
            return { celsius_to_fahrenheit(), this->weather };
        }
    }
    else {
        return { this->temperature, this->weather };
    }
}


void WeatherSystem::set_city(const std::string& city) {
    this->city = city;
}


void WeatherSystem::set_temperature(double temperature) {
    this->temperature = temperature;
}


double WeatherSystem::celsius_to_fahrenheit() const {
    return (this->temperature * 9 / 5) + 32;
}


double WeatherSystem::fahrenheit_to_celsius() const {
    return (this->temperature - 32) * 5 / 9;
}


std::string WeatherSystem::get_city() const {
    return this->city;
}
