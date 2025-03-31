#include <vector>
#include <string>


struct Stock {
    std::string name;
    double price;
    int quantity;

    
    bool operator==(const Stock& other) const {
        return name == other.name && price == other.price && quantity == other.quantity;
    }
};


struct StockSummary {
    std::string name;
    double value;

    
    bool operator==(const StockSummary& other) const {
        return name == other.name && value == other.value;
    }
};


class StockPortfolioTracker {
public:
    explicit StockPortfolioTracker(double cash_balance);

    void add_stock(const Stock& stock);
    bool remove_stock(const Stock& stock);
    bool buy_stock(const Stock& stock);
    bool sell_stock(const Stock& stock);
    double calculate_portfolio_value() const;
    std::pair<double, std::vector<StockSummary>> get_portfolio_summary() const;
    double get_stock_value(const Stock& stock) const;
    const std::vector<Stock>& get_portfolio() const;
    double get_cash_balance() const;
    void set_portfolio(const std::vector<Stock>& portfolio);

private:
    std::vector<Stock> portfolio;
    double cash_balance;
};

StockPortfolioTracker::StockPortfolioTracker(double cash_balance)
    : cash_balance(cash_balance) {
}

void StockPortfolioTracker::add_stock(const Stock& stock) {
    for (auto& pf : portfolio) {
        if (pf.name == stock.name) {
            pf.quantity += stock.quantity;
            return;
        }
    }
    portfolio.push_back(stock);
}

bool StockPortfolioTracker::remove_stock(const Stock& stock) {
    for (auto it = portfolio.begin(); it != portfolio.end(); ++it) {
        if (it->name == stock.name && it->quantity >= stock.quantity) {
            it->quantity -= stock.quantity;
            if (it->quantity == 0) {
                portfolio.erase(it);
            }
            return true;
        }
    }
    return false;
}

bool StockPortfolioTracker::buy_stock(const Stock& stock) {
    if (stock.price * stock.quantity > cash_balance) {
        return false;
    }
    else {
        add_stock(stock);
        cash_balance -= stock.price * stock.quantity;
        return true;
    }
}

bool StockPortfolioTracker::sell_stock(const Stock& stock) {
    if (!remove_stock(stock)) {
        return false;
    }
    cash_balance += stock.price * stock.quantity;
    return true;
}

double StockPortfolioTracker::calculate_portfolio_value() const {
    double total_value = cash_balance;
    for (const auto& stock : portfolio) {
        total_value += stock.price * stock.quantity;
    }
    return total_value;
}

std::pair<double, std::vector<StockSummary>> StockPortfolioTracker::get_portfolio_summary() const {
    std::vector<StockSummary> summary;
    for (const auto& stock : portfolio) {
        summary.push_back({ stock.name, get_stock_value(stock) });
    }
    return { calculate_portfolio_value(), summary };
}

double StockPortfolioTracker::get_stock_value(const Stock& stock) const {
    return stock.price * stock.quantity;
}

const std::vector<Stock>& StockPortfolioTracker::get_portfolio() const {
    return portfolio;
}

double StockPortfolioTracker::get_cash_balance() const {
    return cash_balance;
}

void StockPortfolioTracker::set_portfolio(const std::vector<Stock>& p) {
    portfolio = p;
}
