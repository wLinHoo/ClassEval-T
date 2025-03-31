package to_be_tested;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class StockPortfolioTracker {

    public List<Map<String, Object>> portfolio;

    public double cashBalance;

    public StockPortfolioTracker(double cashBalance) {
        this.portfolio = new ArrayList<>();
        this.cashBalance = cashBalance;
    }

    public void addStock(Map<String, Object> stock) {
        for (Map<String, Object> pf : portfolio) {
            if (pf.get("name").equals(stock.get("name"))) {
                int quantity = (int) pf.get("quantity");
                int newQuantity = quantity + (int) stock.get("quantity");
                pf.put("quantity", newQuantity);
                return;
            }
        }
        portfolio.add(stock);
    }

    public boolean removeStock(Map<String, Object> stock) {
        for (Map<String, Object> pf : portfolio) {
            if (pf.get("name").equals(stock.get("name")) && (int) pf.get("quantity") >= (int) stock.get("quantity")) {
                int newQuantity = (int) pf.get("quantity") - (int) stock.get("quantity");
                if (newQuantity == 0) {
                    portfolio.remove(pf);
                } else {
                    pf.put("quantity", newQuantity);
                }
                return true;
            }
        }
        return false;
    }

    public boolean buyStock(Map<String, Object> stock) {
        if ((double) stock.get("price") * (int) stock.get("quantity") > cashBalance) {
            return false;
        } else {
            addStock(stock);
            cashBalance -= (double) stock.get("price") * (int) stock.get("quantity");
            return true;
        }
    }

    public boolean sellStock(Map<String, Object> stock) {
        if (removeStock(stock) == false) {
            return false;
        }
        cashBalance += (double) stock.get("price") * (int) stock.get("quantity");
        return true;
    }

    public double calculatePortfolioValue() {
        double totalValue = cashBalance;
        for (Map<String, Object> stock : portfolio) {
            totalValue += (double) stock.get("price") * (int) stock.get("quantity");
        }
        return totalValue;
    }

    public double[] getPortfolioSummary() {
        List<Map<String, Object>> summary = new ArrayList<>();
        for (Map<String, Object> stock : portfolio) {
            double value = (double) stock.get("price") * (int) stock.get("quantity");
            summary.add(Map.of("name", stock.get("name"), "value", value));
        }
        double portfolioValue = calculatePortfolioValue();
        return new double[] { portfolioValue, (double) summary.size() };
    }

    public double getStockValue(Map<String, Object> stock) {
        return (double) stock.get("price") * (int) stock.get("quantity");
    }
}
