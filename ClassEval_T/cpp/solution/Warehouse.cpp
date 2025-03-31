#include <map>
#include <string>

class Warehouse {
public:
    Warehouse();

    void add_product(int product_id, const std::string& name, int quantity);
    void update_product_quantity(int product_id, int quantity);
    int get_product_quantity(int product_id) const;
    bool create_order(int order_id, int product_id, int quantity);
    bool change_order_status(int order_id, const std::string& status);
    std::string track_order(int order_id) const;

    
    const std::map<int, std::map<std::string, std::string>>& orders() const;
    const std::map<int, std::map<std::string, std::string>>& inventory() const;

private:
    std::map<int, std::map<std::string, std::string>> inventory_;
    std::map<int, std::map<std::string, std::string>> orders_;
};
Warehouse::Warehouse() {}

void Warehouse::add_product(int product_id, const std::string& name, int quantity) {
    auto& product = inventory_[product_id];
    if (product.empty()) {
        product["name"] = name;
        product["quantity"] = std::to_string(quantity);
    }
    else {
        int current_quantity = std::stoi(product["quantity"]);
        product["quantity"] = std::to_string(current_quantity + quantity);
    }
}

void Warehouse::update_product_quantity(int product_id, int quantity) {
    auto it = inventory_.find(product_id);
    if (it != inventory_.end()) {
        int current_quantity = std::stoi(it->second["quantity"]);
        it->second["quantity"] = std::to_string(current_quantity + quantity);
    }
}

int Warehouse::get_product_quantity(int product_id) const {
    auto it = inventory_.find(product_id);
    if (it != inventory_.end()) {
        return std::stoi(it->second.at("quantity"));
    }
    return false;  
}

bool Warehouse::create_order(int order_id, int product_id, int quantity) {
    int available_quantity = get_product_quantity(product_id);
    if (available_quantity >= quantity) {
        update_product_quantity(product_id, -quantity);
        orders_[order_id] = {
            {"product_id", std::to_string(product_id)},
            {"quantity", std::to_string(quantity)},
            {"status", "Shipped"}
        };
        return true;
    }
    return false;
}

bool Warehouse::change_order_status(int order_id, const std::string& status) {
    auto it = orders_.find(order_id);
    if (it != orders_.end()) {
        it->second["status"] = status;
        return true;
    }
    return false;
}

std::string Warehouse::track_order(int order_id) const {
    auto it = orders_.find(order_id);
    if (it != orders_.end()) {
        return it->second.at("status");
    }
    return "";  
}

const std::map<int, std::map<std::string, std::string>>& Warehouse::orders() const {
    return orders_;
}

const std::map<int, std::map<std::string, std::string>>& Warehouse::inventory() const {
    return inventory_;
}
