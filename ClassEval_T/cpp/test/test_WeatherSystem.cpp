#include <gtest/gtest.h>
#include "pch.h"  

class WeatherSystemTestMain : public ::testing::Test {
protected:
    void SetUp() override {
        
        weatherSystem = new WeatherSystem("New York");
        weather_list["New York"] = { "sunny", 27, "celsius" };
        weather_list["Beijing"] = { "cloudy", 23, "celsius" };
    }

    void TearDown() override {
        
        delete weatherSystem;
    }

    WeatherSystem* weatherSystem;
    std::map<std::string, WeatherInfo> weather_list;  
};

TEST_F(WeatherSystemTestMain, test_main) {
    
    auto result = weatherSystem->query(weather_list);
    EXPECT_EQ(result.first, 27);
    EXPECT_EQ(result.second, "sunny");

    
    weatherSystem->set_city("Beijing");
    EXPECT_EQ(weatherSystem->get_city(), "Beijing");

    
    weatherSystem->set_temperature(27);
    EXPECT_EQ(weatherSystem->celsius_to_fahrenheit(), 80.6);

    
    weatherSystem->set_temperature(80.6);
    EXPECT_EQ(weatherSystem->fahrenheit_to_celsius(), 26.999999999999996);
}


class WeatherSystemTestQuery : public ::testing::Test {
protected:
    void SetUp() override {
        
        weather_list["New York"] = { "sunny", 27, "celsius" };
        weather_list["Beijing"] = { "cloudy", 23, "celsius" };
    }

    std::map<std::string, WeatherInfo> weather_list;
};

TEST_F(WeatherSystemTestQuery, test_query) {
    WeatherSystem weatherSystem("New York");
    auto result = weatherSystem.query(weather_list);
    EXPECT_EQ(result.first, 27);
    EXPECT_EQ(result.second, "sunny");
}

TEST_F(WeatherSystemTestQuery, test_query_2) {
    WeatherSystem weatherSystem("Shanghai");
    auto result = weatherSystem.query(weather_list);
    EXPECT_EQ(result.first, 0.0);
    EXPECT_EQ(result.second, "");
}

TEST_F(WeatherSystemTestQuery, test_query_3) {
    WeatherSystem weatherSystem("Beijing");
    auto result = weatherSystem.query(weather_list, "fahrenheit");
    EXPECT_NEAR(result.first, 73.4, 1e-1);
    EXPECT_EQ(result.second, "cloudy");
}

TEST_F(WeatherSystemTestQuery, test_query_4) {
    weather_list["New York"].temperature = 73.47;
    weather_list["New York"].temperature_units = "fahrenheit";
    weather_list["Beijing"].temperature = 73.4;
    weather_list["Beijing"].temperature_units = "fahrenheit";

    WeatherSystem weatherSystem("Beijing");
    auto result = weatherSystem.query(weather_list, "celsius");
    EXPECT_NEAR(result.first, 23.0, 1e-1);
    EXPECT_EQ(result.second, "cloudy");
}

TEST_F(WeatherSystemTestQuery, test_query_5) {
    weather_list["New York"].temperature = 80.6;
    weather_list["New York"].temperature_units = "fahrenheit";

    WeatherSystem weatherSystem("New York");
    auto result = weatherSystem.query(weather_list, "celsius");
    EXPECT_NEAR(result.first, 27.0, 1e-1);
    EXPECT_EQ(result.second, "sunny");
}

TEST_F(WeatherSystemTestQuery, test_query_6) {
    WeatherSystem weatherSystem("New York");
    auto result = weatherSystem.query(weather_list, "fahrenheit");
    EXPECT_NEAR(result.first, 80.6, 1e-1);
    EXPECT_EQ(result.second, "sunny");
}

class WeatherSystemTestSetCity : public ::testing::Test {
protected:
    void SetUp() override {
        
    }
};

TEST_F(WeatherSystemTestSetCity, test_set_city) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_city("Beijing");
    EXPECT_EQ(weatherSystem.get_city(), "Beijing");
}

TEST_F(WeatherSystemTestSetCity, test_set_city_2) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_city("Shanghai");
    EXPECT_EQ(weatherSystem.get_city(), "Shanghai");
}

TEST_F(WeatherSystemTestSetCity, test_set_city_3) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_city("Shanghai");
    EXPECT_NE(weatherSystem.get_city(), "Beijing");
}

TEST_F(WeatherSystemTestSetCity, test_set_city_4) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_city("Shanghai");
    EXPECT_NE(weatherSystem.get_city(), "New York");
}

TEST_F(WeatherSystemTestSetCity, test_set_city_5) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_city("Shanghai");
    EXPECT_NE(weatherSystem.get_city(), "Tokyo");
}

class WeatherSystemTestCelsiusToFahrenheit : public ::testing::Test {
protected:
    void SetUp() override {
        
    }
};

TEST_F(WeatherSystemTestCelsiusToFahrenheit, test_celsius_to_fahrenheit) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_temperature(27);
    EXPECT_NEAR(weatherSystem.celsius_to_fahrenheit(), 80.6, 1e-1);
}

TEST_F(WeatherSystemTestCelsiusToFahrenheit, test_celsius_to_fahrenheit_2) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_temperature(23);
    EXPECT_NEAR(weatherSystem.celsius_to_fahrenheit(), 73.4, 1e-1);
}

TEST_F(WeatherSystemTestCelsiusToFahrenheit, test_celsius_to_fahrenheit_3) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_temperature(23);
    EXPECT_NE(weatherSystem.celsius_to_fahrenheit(), 80.6);
}

TEST_F(WeatherSystemTestCelsiusToFahrenheit, test_celsius_to_fahrenheit_4) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_temperature(27);
    EXPECT_NE(weatherSystem.celsius_to_fahrenheit(), 73.4);
}

TEST_F(WeatherSystemTestCelsiusToFahrenheit, test_celsius_to_fahrenheit_5) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_temperature(27);
    EXPECT_NE(weatherSystem.celsius_to_fahrenheit(), 23);
}

class WeatherSystemTestFahrenheitToCelsius : public ::testing::Test {
protected:
    void SetUp() override {
        
    }
};

TEST_F(WeatherSystemTestFahrenheitToCelsius, test_fahrenheit_to_celsius) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_temperature(80.6);
    EXPECT_NEAR(weatherSystem.fahrenheit_to_celsius(), 26.999999999999996, 1e-1);
}

TEST_F(WeatherSystemTestFahrenheitToCelsius, test_fahrenheit_to_celsius_2) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_temperature(73.4);
    EXPECT_NEAR(weatherSystem.fahrenheit_to_celsius(), 23.000000000000004, 1e-1);
}

TEST_F(WeatherSystemTestFahrenheitToCelsius, test_fahrenheit_to_celsius_3) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_temperature(80);
    EXPECT_NE(weatherSystem.fahrenheit_to_celsius(), 23);
}

TEST_F(WeatherSystemTestFahrenheitToCelsius, test_fahrenheit_to_celsius_4) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_temperature(73);
    EXPECT_NE(weatherSystem.fahrenheit_to_celsius(), 27);
}

TEST_F(WeatherSystemTestFahrenheitToCelsius, test_fahrenheit_to_celsius_5) {
    WeatherSystem weatherSystem("New York");
    weatherSystem.set_temperature(80);
    EXPECT_NE(weatherSystem.fahrenheit_to_celsius(), 27);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}