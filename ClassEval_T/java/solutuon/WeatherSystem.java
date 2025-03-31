package org.example;

import java.util.HashMap;
import java.util.Map;

class WeatherSystem {
    private Double temperature;
    private String weather;
    private String city;
    private Map<String, Map<String, Object>> weatherList;

    public WeatherSystem(String city) {
        this.city = city;
        this.weatherList = new HashMap<>();
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getCity() {
        return this.city;
    }

    public void setTemperature(Double temperature) {
        this.temperature = temperature;
    }

    public double celsiusToFahrenheit() {
        return (this.temperature * 9 / 5) + 32;
    }

    public double fahrenheitToCelsius() {
        return (this.temperature - 32) * 5 / 9;
    }

    public Object[] query(Map<String, Map<String, Object>> weatherList, String tmpUnits) {
        this.weatherList = weatherList;
        if (!weatherList.containsKey(this.city)) {
            return new Object[]{false};
        }

        Map<String, Object> cityWeather = weatherList.get(this.city);
        this.temperature = (Double) cityWeather.get("temperature");
        this.weather = (String) cityWeather.get("weather");
        String currentUnits = (String) cityWeather.get("temperature units");

        if (!currentUnits.equals(tmpUnits)) {
            if (tmpUnits.equals("celsius")) {
                this.temperature = fahrenheitToCelsius();
            } else if (tmpUnits.equals("fahrenheit")) {
                this.temperature = celsiusToFahrenheit();
            }
        }

        return new Object[]{this.temperature, this.weather};
    }
}