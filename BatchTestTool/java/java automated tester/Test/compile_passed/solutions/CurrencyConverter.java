import java.util.HashMap;
import java.util.Map;

public class CurrencyConverter {
    private Map<String, Double> rates;

    public CurrencyConverter() {
        rates = new HashMap<>();
        rates.put("USD", 1.0);
        rates.put("EUR", 0.85);
        rates.put("GBP", 0.72);
        rates.put("JPY", 110.15);
        rates.put("CAD", 1.23);
        rates.put("AUD", 1.34);
        rates.put("CNY", 6.40);
    }

    public String[] getSupportedCurrencies() {
        return rates.keySet().toArray(new String[0]);
    }

    public boolean addCurrencyRate(String currency, double rate) {
        if (rates.containsKey(currency)) {
            return false;
        }
        rates.put(currency, rate);
        return true;
    }

    public boolean updateCurrencyRate(String currency, double newRate) {
        if (!rates.containsKey(currency)) {
            return false;
        }
        rates.put(currency, newRate);
        return true;
    }

    public double convert(double amount, String fromCurrency, String toCurrency) {
        if (fromCurrency.equals(toCurrency)) {
            return amount;
        }

        if (!rates.containsKey(fromCurrency) || !rates.containsKey(toCurrency)) {
            return -1.0; // Return -1.0 to indicate invalid conversion
        }

        double fromRate = rates.get(fromCurrency);
        double toRate = rates.get(toCurrency);

        double convertedAmount = (amount / fromRate) * toRate;
        return convertedAmount;
    }
}