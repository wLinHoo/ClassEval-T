#include <map>
#include <vector>
#include <string>

class DiscountStrategy {
public:
    enum PromoType {
        FidelityPromo,
        BulkItemPromo,
        LargeOrderPromo,
        NoPromo
    };

    DiscountStrategy(const std::map<std::string, double>& customer,
        const std::vector<std::map<std::string, double>>& cart,
        PromoType promo = NoPromo);

    double total() const;
    double due() const;
    double promotion(const DiscountStrategy& order) const;

private:
    std::map<std::string, double> customer_;
    std::vector<std::map<std::string, double>> cart_;
    PromoType promo_;

    double fidelity_discount() const;
    double bulk_item_discount() const;
    double large_order_discount() const;
};


DiscountStrategy::DiscountStrategy(const std::map<std::string, double>& customer,
    const std::vector<std::map<std::string, double>>& cart,
    PromoType promo)
    : customer_(customer), cart_(cart), promo_(promo) {}

double DiscountStrategy::total() const {
    double total = 0.0;
    for (const auto& item : cart_) {
        total += item.at("quantity") * item.at("price");
    }
    return total;
}

double DiscountStrategy::due() const {
    return total() - promotion(*this);
}

double DiscountStrategy::promotion(const DiscountStrategy& order) const {
    switch (promo_) {
    case FidelityPromo:
        return fidelity_discount();
    case BulkItemPromo:
        return bulk_item_discount();
    case LargeOrderPromo:
        return large_order_discount();
    default:
        return 0.0;
    }
}

double DiscountStrategy::fidelity_discount() const {
    double total = 0.0;
    double fidelity = customer_.at("fidelity");
    if (fidelity >= 1000.0) {
        total = 0.05 * this->total(); 
    }
    return total;
}

double DiscountStrategy::bulk_item_discount() const {
    double discount = 0.0;
    for (const auto& item : cart_) {
        if (item.at("quantity") >= 20) {
            discount += item.at("quantity") * item.at("price") * 0.1; 
        }
    }
    return discount;
}

double DiscountStrategy::large_order_discount() const {
    int num_items = cart_.size();
    double discount = 0.0;
    if (num_items >= 10) {
        discount = 0.07 * total(); 
    }
    return discount;
}
