import java.util.HashMap;
import java.util.Map;

public class ShoppingCart {
    private Map<String, Map<String, Integer>> items;
    private Map<String, Map<String, Object>> items2;
    private HashMap<String, Item> items3;

    public ShoppingCart() {
        this.items = new HashMap<>();
        this.items2 = new HashMap<>();
        this.items3 = new HashMap<>();
    }

    public void removeItem(String item, int quantity) {
        if (this.items.containsKey(item)) {
            int currentQuantity = this.items.get(item).get("quantity");
            currentQuantity -= quantity;
            this.items.get(item).put("quantity", currentQuantity);
        }
    }

    public double totalPrice() {
        double total = 0.0;

        for (Map<String, Object> item : items2.values()) {
            int quantity = (int) item.get("quantity");
            double price = (double) item.get("price");
            total += quantity * price;
        }

        return total;
    }

    public void addItem(String item, int price, int quantity) {
        if (items3.containsKey(item)) {
            items3.get(item).setQuantity(quantity);
        } else {
            items3.put(item, new Item(price, quantity));
        }
    }

    private static class Item {
        private int price;
        private int quantity;

        public Item(int price, int quantity) {
            this.price = price;
            this.quantity = quantity;
        }

        public void setQuantity(int quantity) {
            this.quantity = quantity;
        }
    }
}