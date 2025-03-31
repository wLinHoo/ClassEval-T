#include <unordered_map>
#include <string>
#include <vector>

class CurrencyConverter {
public:
    CurrencyConverter();

    double convert(double amount, const std::string& from_currency, const std::string& to_currency);
    std::vector<std::string> get_supported_currencies();
    bool add_currency_rate(const std::string& currency, double rate);
    bool update_currency_rate(const std::string& currency, double new_rate);

    std::unordered_map<std::string, double> rates;
    std::vector<std::string> currency_order;
};

CurrencyConverter::CurrencyConverter() {
    rates = {
        {"USD", 1.0},
        {"EUR", 0.85},
        {"GBP", 0.72},
        {"JPY", 110.15},
        {"CAD", 1.23},
        {"AUD", 1.34},
        {"CNY", 6.40},
    };

    currency_order = { "USD", "EUR", "GBP", "JPY", "CAD", "AUD", "CNY" };
}

double CurrencyConverter::convert(double amount, const std::string& from_currency, const std::string& to_currency) {
    if (from_currency == to_currency) {
        return amount;
    }

    if (rates.find(from_currency) == rates.end() || rates.find(to_currency) == rates.end()) {
        return false;
    }

    double from_rate = rates[from_currency];
    double to_rate = rates[to_currency];

    double converted_amount = (amount / from_rate) * to_rate;
    return converted_amount;
}

std::vector<std::string> CurrencyConverter::get_supported_currencies() {
    return currency_order;
}

bool CurrencyConverter::add_currency_rate(const std::string& currency, double rate) {
    if (rates.find(currency) != rates.end()) {
        return false;
    }
    rates[currency] = rate;
    currency_order.push_back(currency);
    return true;
}

bool CurrencyConverter::update_currency_rate(const std::string& currency, double new_rate) {
    if (rates.find(currency) == rates.end()) {
        return false;
    }
    rates[currency] = new_rate;
    return true;
}
