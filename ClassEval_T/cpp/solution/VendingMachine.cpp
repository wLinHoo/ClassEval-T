
#include <sstream>

#include <string>
#include <unordered_map>

class VendingMachine {
public:
    VendingMachine();
    void add_item(const std::string& item_name, double price, int quantity);
    double insert_coin(double amount);
    double purchase_item(const std::string& item_name);
    bool restock_item(const std::string& item_name, int quantity);
    std::string display_items() const;
    std::unordered_map<std::string, std::unordered_map<std::string, double>> inventory() const;
    void set_inventory(std::unordered_map<std::string, std::unordered_map<std::string, double>> x);
    void set_balance(double y);

private:
    std::unordered_map<std::string, std::unordered_map<std::string, double>> inventory_;
    double balance_;
};

VendingMachine::VendingMachine() : balance_(0) {}

void VendingMachine::add_item(const std::string& item_name, double price, int quantity) {
    if (!restock_item(item_name, quantity)) {
        inventory_[item_name] = { {"price", price}, {"quantity", static_cast<double>(quantity)} };
    }
}

double VendingMachine::insert_coin(double amount) {
    balance_ += amount;
    return balance_;
}

double VendingMachine::purchase_item(const std::string& item_name) {
    if (inventory_.count(item_name)) {
        auto& item = inventory_[item_name];
        if (item["quantity"] > 0 && balance_ >= item["price"]) {
            balance_ -= item["price"];
            item["quantity"] -= 1;
            return balance_;
        }
    }
    return false;
}

bool VendingMachine::restock_item(const std::string& item_name, int quantity) {
    if (inventory_.count(item_name)) {
        inventory_[item_name]["quantity"] += static_cast<double>(quantity);
        return true;
    }
    return false;
}

std::string VendingMachine::display_items() const {
    if (inventory_.empty()) {
        return "false";
    }

    std::ostringstream oss;
    for (const auto& item : inventory_) {
        oss << item.first << " - $" << item.second.at("price") << " [" << item.second.at("quantity") << "]\n";
    }

    std::string result = oss.str();
    result.pop_back(); 
    return result;
}

std::unordered_map<std::string, std::unordered_map<std::string, double>> VendingMachine::inventory() const {
    return inventory_;
}

void VendingMachine::set_inventory(std::unordered_map<std::string, std::unordered_map<std::string, double>> x)
{
    this->inventory_ = x;
}

void VendingMachine::set_balance(double y)
{
    this->balance_ = y;
}