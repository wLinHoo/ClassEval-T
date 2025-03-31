package org.example;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Order {
    List<Map<String, Object>> menu;
    List<Map<String, Object>> selectedDishes;
    Map<String, Double> sales;

    public Order() {
        this.menu = new ArrayList<>();
        this.selectedDishes = new ArrayList<>();
        this.sales = new HashMap<>();
    }

    public boolean addDish(Map<String, Object> dish) {
        if (dish == null || !dish.containsKey("dish") || !dish.containsKey("price") || !dish.containsKey("count")) {
            return false;
        }

        for (Map<String, Object> menuDish : menu) {
            if (dish.get("dish").equals(menuDish.get("dish"))) {
                int dishCount = (int) dish.get("count");
                int menuDishCount = (int) menuDish.get("count");

                if (menuDishCount < dishCount) {
                    return false;
                } else {
                    menuDish.put("count", menuDishCount - dishCount);
                    selectedDishes.add(dish);
                    return true;
                }
            }
        }
        return false;
    }

    public double calculateTotal() {
        double total = 0;
        for (Map<String, Object> dish : selectedDishes) {
            String dishName = (String) dish.get("dish");
            double price = (double) dish.get("price");
            int count = (int) dish.get("count");
            double sale = sales.getOrDefault(dishName, 1.0); // 默认销售额为1
            total += price * count * sale;
        }
        return total;
    }

    public Object checkout() {
        if (selectedDishes.isEmpty()) {
            return false;
        }
        double total = calculateTotal();
        selectedDishes.clear();
        return total;
    }
}
