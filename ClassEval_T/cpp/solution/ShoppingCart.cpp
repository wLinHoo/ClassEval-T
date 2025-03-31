#include <unordered_map>
#include <string>

class ShoppingCart {
public:
    ShoppingCart();

    void add_item(const std::string& item, double price, int quantity = 1);
    void remove_item(const std::string& item, int quantity = 1);
    std::unordered_map<std::string, std::pair<double, int>> view_items() const;
    double total_price() const;

private:
    std::unordered_map<std::string, std::pair<double, int>> items;
};

ShoppingCart::ShoppingCart() {}

void ShoppingCart::add_item(const std::string& item, double price, int quantity) {
    if (items.find(item) != items.end()) {
        items[item] = { price, quantity };
    }
    else {
        items[item] = { price, quantity };
    }
}

void ShoppingCart::remove_item(const std::string& item, int quantity) {
    auto it = items.find(item);
    if (it != items.end()) {
        it->second.second -= quantity;
        if (it->second.second <= 0) {
            items.erase(it);
        }
    }
}

std::unordered_map<std::string, std::pair<double, int>> ShoppingCart::view_items() const {
    return items;
}

double ShoppingCart::total_price() const {
    double total = 0.0;
    for (const auto& [item, info] : items) {
        total += info.first * info.second;
    }
    return total;
}
