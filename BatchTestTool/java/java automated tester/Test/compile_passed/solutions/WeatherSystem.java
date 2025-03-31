import java.util.HashMap;
import java.util.Map;

public class WeatherSystem {
    private Double temperature;
    private String weather;
    private String city;
    private Map<String, Map<String, Object>> weatherList;

    public WeatherSystem(String city) {
        this.temperature = null;
        this.weather = null;
        this.city = city;
        this.weatherList = new HashMap<>();
    }

    public void setCity(String city) {
        this.city = city;
    }

    public Object[] query(Map<String, Map<String, Object>> weatherList, String tmpUnits) {
        this.weatherList = weatherList;
        if (!this.weatherList.containsKey(this.city)) {
            return new Object[]{false};
        } else {
            this.temperature = (Double) this.weatherList.get(this.city).get("temperature");
            this.weather = (String) this.weatherList.get(this.city).get("weather");
        }
        if (!tmpUnits.equals(this.weatherList.get(this.city).get("temperature units"))) {
            if (tmpUnits.equals("celsius")) {
                return new Object[]{fahrenheitToCelsius(), this.weather};
            } else if (tmpUnits.equals("fahrenheit")) {
                return new Object[]{celsiusToFahrenheit(), this.weather};
            }
        }
        return new Object[]{this.temperature, this.weather};
    }

    private double fahrenheitToCelsius() {
        return (this.temperature - 32) * 5 / 9;
    }

    private double celsiusToFahrenheit() {
        return (this.temperature * 9 / 5) + 32;
    }
}