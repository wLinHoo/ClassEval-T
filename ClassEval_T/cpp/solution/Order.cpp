#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

struct Dish {
    std::string dish;
    double price;
    int count;
};

class Order {
public:
    Order();
    bool add_dish(const Dish& dish);
    double calculate_total() const;
    double checkout();

    std::vector<Dish> menu;
    std::vector<Dish> selected_dishes;
    std::unordered_map<std::string, double> sales;
};

Order::Order() {}


bool Order::add_dish(const Dish& dish) {
    for (auto& menu_dish : menu) {
        if (dish.dish == menu_dish.dish) {
            if (menu_dish.count < dish.count) {
                return false;
            }
            else {
                menu_dish.count -= dish.count;
                break;
            }
        }
    }
    selected_dishes.push_back(dish);
    return true;
}


double Order::calculate_total() const {
    double total = 0;
    for (const auto& dish : selected_dishes) {
        auto it = sales.find(dish.dish);
        if (it != sales.end()) {
            total += dish.price * dish.count * it->second;
        }
    }
    return total;
}


double Order::checkout() {
    if (selected_dishes.empty()) {
        return 0;
    }
    double total = calculate_total();
    selected_dishes.clear();
    return total;
}
