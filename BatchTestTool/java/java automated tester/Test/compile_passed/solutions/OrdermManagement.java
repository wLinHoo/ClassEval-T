import java.util.*;

class Dish {
    String dish;
    double price;
    int count;

    public Dish(String dish, double price, int count) {
        this.dish = dish;
        this.price = price;
        this.count = count;
    }
}

class Order {
    private List<Dish> menu = new ArrayList<>();
    private List<Dish> selectedDishes = new ArrayList<>();
    private Map<String, Double> sales = new HashMap<>();
    private double total = 0;

    public Order() {}

    public boolean addDish(Dish dish) {
        for (Dish menuDish : menu) {
            if (dish.dish.equals(menuDish.dish)) {
                if (menuDish.count < dish.count) {
                    return false;
                } else {
                    menuDish.count -= dish.count;
                    return true;
                }
            }
        }
        selectedDishes.add(dish);
        return true;
    }

    public double calculateTotal() {
        total = 0;
        for (Dish dish : selectedDishes) {
            Double sale = sales.get(dish.dish);
            if (sale != null) {
                total += dish.price * dish.count * sale;
            }
        }
        return total;
    }

    public double checkout() {
        if (selectedDishes.isEmpty()) {
            return 0;
        }
        double checkoutTotal = total;
        selectedDishes.clear();
        return checkoutTotal;
    }
}