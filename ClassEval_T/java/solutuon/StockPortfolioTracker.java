package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class StockPortfolioTracker {
    private final double initialCashBalance;
    private double cashBalance;
    private final List<Stock> portfolio;

    public StockPortfolioTracker(double initialCashBalance) {
        this.initialCashBalance = initialCashBalance;
        this.cashBalance = initialCashBalance;
        this.portfolio = new ArrayList<>();
    }

    public void addStock(Stock stock) {
        for (Stock s : portfolio) {
            if (s.getName().equals(stock.getName()) && s.getPrice() == stock.getPrice()) {
                s.setQuantity(s.getQuantity() + stock.getQuantity());
                return;
            }
        }
        portfolio.add(stock);
    }

    public boolean removeStock(Stock stock) {
        for (Stock s : portfolio) {
            if (s.getName().equals(stock.getName()) && s.getPrice() == stock.getPrice()) {
                if (s.getQuantity() >= stock.getQuantity()) {
                    s.setQuantity(s.getQuantity() - stock.getQuantity());
                    if (s.getQuantity() == 0) {
                        portfolio.remove(s);
                    }
                    return true;
                }
            }
        }
        return false;
    }

    public boolean buyStock(Stock stock) {
        double cost = stock.getPrice() * stock.getQuantity();
        if (cashBalance >= cost) {
            addStock(stock);
            cashBalance -= cost;
            return true;
        }
        return false;
    }

    public boolean sellStock(Stock stock) {
        double revenue = stock.getPrice() * stock.getQuantity();
        if (removeStock(stock)) {
            cashBalance += revenue;
            return true;
        }
        return false;
    }

    public List<Stock> getPortfolio() {
        return new ArrayList<>(portfolio);
    }

    public double getCashBalance() {
        return cashBalance;
    }

    public double calculatePortfolioValue() {
        double totalValue = 0.0;
        for (Stock stock : portfolio) {
            totalValue += stock.getPrice() * stock.getQuantity();
        }
        return totalValue;
    }

    public String getPortfolioSummary() {
        StringBuilder summary = new StringBuilder();
        for (Stock stock : portfolio) {
            summary.append(stock.toString()).append("\n");
        }
        summary.append("Total Value: $").append(calculatePortfolioValue()).append("\n");
        return summary.toString();
    }

    public static class Stock {
        private final String name;
        private final double price;
        private int quantity;

        public Stock(String name, double price, int quantity) {
            this.name = name;
            this.price = price;
            this.quantity = quantity;
        }

        public String getName() {
            return name;
        }

        public double getPrice() {
            return price;
        }

        public int getQuantity() {
            return quantity;
        }

        public void setQuantity(int quantity) {
            this.quantity = quantity;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Stock stock = (Stock) obj;
            return Double.compare(stock.price, price) == 0 &&
                    quantity == stock.quantity &&
                    name.equals(stock.name);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name, price, quantity);
        }

        @Override
        public String toString() {
            return name + ": " + quantity + " shares at $" + price + " each";
        }
    }
}
