import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Order {

    private List<Map<String, Object>> menu;
    private List<Map<String, Object>> selectedDishes;
    private Map<String, Integer> sales;
    private Map<String, Double> salesDouble;

    public Order() {
        this.menu = new ArrayList<>();
        this.selectedDishes = new ArrayList<>();
        this.sales = new HashMap<>();
        this.salesDouble = new HashMap<>();
    }

    public boolean addDish(Map<String, Object> dish) {
        for (Map<String, Object> menuDish : menu) {
            if (dish.get("dish").equals(menuDish.get("dish"))) {
                int count = (int) dish.get("count");
                if (menuDish.get("count").equals(count)) {
                    return false;
                } else {
                    menuDish.put("count", (int) menuDish.get("count") - count);
                    break;
                }
            }
        }
        selectedDishes.add(dish);
        return true;
    }

    public double calculateTotal() {
        double total = 0;
        for (Map<String, Object> dish : selectedDishes) {
            total += (double) dish.get("price") * (int) dish.get("count") * salesDouble.get((String) dish.get("dish"));
        }
        return total;
    }

    public double checkout() {
        if (selectedDishes.isEmpty()) {
            return 0;
        }
        double total = calculateTotal();
        selectedDishes.clear();
        return total;
    }
}