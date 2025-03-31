package org.example;

import org.junit.jupiter.api.Test;
import java.util.HashMap;
import java.util.Map;
import static org.junit.jupiter.api.Assertions.*;

public class WeatherSystemTest {

    @Test
    public void testQuery() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        Map<String, Map<String, Object>> weatherList = new HashMap<>();
        Map<String, Object> newYorkWeather = new HashMap<>();
        newYorkWeather.put("weather", "sunny");
        newYorkWeather.put("temperature", 27.0);
        newYorkWeather.put("temperature units", "celsius");
        weatherList.put("New York", newYorkWeather);

        Map<String, Object> beijingWeather = new HashMap<>();
        beijingWeather.put("weather", "cloudy");
        beijingWeather.put("temperature", 23.0);
        beijingWeather.put("temperature units", "celsius");
        weatherList.put("Beijing", beijingWeather);

        Object[] result = weatherSystem.query(weatherList, "celsius");
        assertArrayEquals(new Object[]{27.0, "sunny"}, result);
    }

    @Test
    public void testQuery2() {
        WeatherSystem weatherSystem = new WeatherSystem("Shanghai");
        Map<String, Map<String, Object>> weatherList = new HashMap<>();
        Map<String, Object> newYorkWeather = new HashMap<>();
        newYorkWeather.put("weather", "sunny");
        newYorkWeather.put("temperature", 27.0);
        newYorkWeather.put("temperature units", "celsius");
        weatherList.put("New York", newYorkWeather);

        Map<String, Object> beijingWeather = new HashMap<>();
        beijingWeather.put("weather", "cloudy");
        beijingWeather.put("temperature", 23.0);
        beijingWeather.put("temperature units", "celsius");
        weatherList.put("Beijing", beijingWeather);

        Object[] result = weatherSystem.query(weatherList, "celsius");
        assertArrayEquals(new Object[]{false}, result);
    }

    @Test
    public void testQuery3() {
        WeatherSystem weatherSystem = new WeatherSystem("Beijing");
        Map<String, Map<String, Object>> weatherList = new HashMap<>();
        Map<String, Object> newYorkWeather = new HashMap<>();
        newYorkWeather.put("weather", "sunny");
        newYorkWeather.put("temperature", 27.0);
        newYorkWeather.put("temperature units", "celsius");
        weatherList.put("New York", newYorkWeather);

        Map<String, Object> beijingWeather = new HashMap<>();
        beijingWeather.put("weather", "cloudy");
        beijingWeather.put("temperature", 23.0);
        beijingWeather.put("temperature units", "celsius");
        weatherList.put("Beijing", beijingWeather);

        Object[] result = weatherSystem.query(weatherList, "fahrenheit");
        assertArrayEquals(new Object[]{73.4, "cloudy"}, result);
    }

    @Test
    public void testQuery4() {
        WeatherSystem weatherSystem = new WeatherSystem("Beijing");
        Map<String, Map<String, Object>> weatherList = new HashMap<>();
        Map<String, Object> newYorkWeather = new HashMap<>();
        newYorkWeather.put("weather", "sunny");
        newYorkWeather.put("temperature", 73.47);
        newYorkWeather.put("temperature units", "fahrenheit");
        weatherList.put("New York", newYorkWeather);

        Map<String, Object> beijingWeather = new HashMap<>();
        beijingWeather.put("weather", "cloudy");
        beijingWeather.put("temperature", 73.4);
        beijingWeather.put("temperature units", "fahrenheit");
        weatherList.put("Beijing", beijingWeather);

        Object[] result = weatherSystem.query(weatherList, "celsius");
        assertArrayEquals(new Object[]{23.000000000000004, "cloudy"}, result);
    }

    @Test
    public void testQuery5() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        Map<String, Map<String, Object>> weatherList = new HashMap<>();
        Map<String, Object> newYorkWeather = new HashMap<>();
        newYorkWeather.put("weather", "sunny");
        newYorkWeather.put("temperature", 80.6);
        newYorkWeather.put("temperature units", "fahrenheit");
        weatherList.put("New York", newYorkWeather);

        Map<String, Object> beijingWeather = new HashMap<>();
        beijingWeather.put("weather", "cloudy");
        beijingWeather.put("temperature", 23.0);
        beijingWeather.put("temperature units", "celsius");
        weatherList.put("Beijing", beijingWeather);

        Object[] result = weatherSystem.query(weatherList, "celsius");
        assertArrayEquals(new Object[]{26.999999999999996, "sunny"}, result);
    }

    @Test
    public void testQuery6() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        Map<String, Map<String, Object>> weatherList = new HashMap<>();
        Map<String, Object> newYorkWeather = new HashMap<>();
        newYorkWeather.put("weather", "sunny");
        newYorkWeather.put("temperature", 27.0);
        newYorkWeather.put("temperature units", "celsius");
        weatherList.put("New York", newYorkWeather);

        Map<String, Object> beijingWeather = new HashMap<>();
        beijingWeather.put("weather", "cloudy");
        beijingWeather.put("temperature", 23.0);
        beijingWeather.put("temperature units", "celsius");
        weatherList.put("Beijing", beijingWeather);

        Object[] result = weatherSystem.query(weatherList, "fahrenheit");
        assertArrayEquals(new Object[]{80.6, "sunny"}, result);
    }

    @Test
    public void testSetCity() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setCity("Beijing");
        assertEquals("Beijing", weatherSystem.getCity());
    }

    @Test
    public void testSetCity2() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setCity("Shanghai");
        assertEquals("Shanghai", weatherSystem.getCity());
    }

    @Test
    public void testSetCity3() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setCity("Shanghai");
        assertNotEquals("Beijing", weatherSystem.getCity());
    }

    @Test
    public void testSetCity4() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setCity("Shanghai");
        assertNotEquals("New York", weatherSystem.getCity());
    }

    @Test
    public void testSetCity5() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setCity("Shanghai");
        assertNotEquals("Tokyo", weatherSystem.getCity());
    }

    @Test
    public void testCelsiusToFahrenheit() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setTemperature(27.0);
        assertEquals(80.6, weatherSystem.celsiusToFahrenheit(), 0.01);
    }

    @Test
    public void testCelsiusToFahrenheit2() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setTemperature(23.0);
        assertEquals(73.4, weatherSystem.celsiusToFahrenheit(), 0.01);
    }

    @Test
    public void testCelsiusToFahrenheit3() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setTemperature(23.0);
        assertNotEquals(80.6, weatherSystem.celsiusToFahrenheit(), 0.01);
    }

    @Test
    public void testCelsiusToFahrenheit4() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setTemperature(27.0);
        assertNotEquals(73.4, weatherSystem.celsiusToFahrenheit(), 0.01);
    }

    @Test
    public void testCelsiusToFahrenheit5() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setTemperature(27.0);
        assertNotEquals(23.0, weatherSystem.celsiusToFahrenheit(), 0.01);
    }

    @Test
    public void testFahrenheitToCelsius() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setTemperature(80.6);
        assertEquals(26.999999999999996, weatherSystem.fahrenheitToCelsius(), 0.01);
    }

    @Test
    public void testFahrenheitToCelsius2() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setTemperature(73.4);
        assertEquals(23.000000000000004, weatherSystem.fahrenheitToCelsius(), 0.01);
    }

    @Test
    public void testFahrenheitToCelsius3() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setTemperature(80.0);
        assertNotEquals(23.0, weatherSystem.fahrenheitToCelsius(), 0.01);
    }

    @Test
    public void testFahrenheitToCelsius4() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setTemperature(73.0);
        assertNotEquals(27.0, weatherSystem.fahrenheitToCelsius(), 0.01);
    }

    @Test
    public void testFahrenheitToCelsius5() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        weatherSystem.setTemperature(80.0);
        assertNotEquals(27.0, weatherSystem.fahrenheitToCelsius(), 0.01);
    }

    @Test
    public void testMain() {
        WeatherSystem weatherSystem = new WeatherSystem("New York");
        Map<String, Map<String, Object>> weatherList = new HashMap<>();
        Map<String, Object> newYorkWeather = new HashMap<>();
        newYorkWeather.put("weather", "sunny");
        newYorkWeather.put("temperature", 27.0);
        newYorkWeather.put("temperature units", "celsius");
        weatherList.put("New York", newYorkWeather);

        Map<String, Object> beijingWeather = new HashMap<>();
        beijingWeather.put("weather", "cloudy");
        beijingWeather.put("temperature", 23.0);
        beijingWeather.put("temperature units", "celsius");
        weatherList.put("Beijing", beijingWeather);

        Object[] result = weatherSystem.query(weatherList, "celsius");
        assertArrayEquals(new Object[]{27.0, "sunny"}, result);

        weatherSystem.setCity("Beijing");
        assertEquals("Beijing", weatherSystem.getCity());

        weatherSystem.setTemperature(27.0);
        assertEquals(80.6, weatherSystem.celsiusToFahrenheit(), 0.01);

        weatherSystem.setTemperature(80.6);
        assertEquals(26.999999999999996, weatherSystem.fahrenheitToCelsius(), 0.01);
    }
}