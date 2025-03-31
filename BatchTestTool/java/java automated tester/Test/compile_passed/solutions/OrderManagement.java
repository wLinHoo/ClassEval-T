import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Order {
    private List<Map<String, Integer>> menu;
    private List<Map<String, Integer>> selectedDishes;
    private Map<String, Double> sales;

    public Order() {
        this.menu = new ArrayList<>();
        this.selectedDishes = new ArrayList<>();
        this.sales = new HashMap<>();
    }

    public boolean addDish(Map<String, Integer> dish) {
        for (Map<String, Integer> menuDish : menu) {
            if (dish.get("dish").equals(menuDish.get("dish"))) {
                if (menuDish.get("count") < dish.get("count")) {
                    return false;
                } else {
                    menuDish.put("count", menuDish.get("count") - dish.get("count"));
                    break;
                }
            }
        }
        selectedDishes.add(dish);
        return true;
    }

    public double calculateTotal() {
        double total = 0;
        for (Map<String, Integer> dish : selectedDishes) {
            total += dish.get("price") * dish.get("count") * sales.getOrDefault(dish.get("dish"), 1.0);
        }
        return total;
    }

    public double checkout() {
        if (selectedDishes.isEmpty()) {
            return -1; // or any other default value
        }
        double total = calculateTotal();
        selectedDishes.clear();
        return total;
    }
}