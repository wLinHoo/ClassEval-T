import java.util.HashMap;
import java.util.Map;

public class Warehouse {
    private Map<Integer, Map<String, String>> inventory;
    private Map<Integer, Map<String, String>> orders;

    public Warehouse() {
        inventory = new HashMap<>();
        orders = new HashMap<>();
    }

    public void addProduct(int productId, String name, int quantity) {
        Map<String, String> product = inventory.computeIfAbsent(productId, k -> new HashMap<>());

        if (product.isEmpty()) {
            product.put("name", name);
            product.put("quantity", String.valueOf(quantity));
        } else {
            int currentQuantity = Integer.parseInt(product.get("quantity"));
            product.put("quantity", String.valueOf(currentQuantity + quantity));
        }
    }

    public void updateProductQuantity(int productId, int quantity) {
        if (inventory.containsKey(productId)) {
            Map<String, String> product = inventory.get(productId);
            int currentQuantity = Integer.parseInt(product.get("quantity"));
            product.put("quantity", String.valueOf(currentQuantity + quantity));
        }
    }

    public int getProductQuantity(int productId) {
        if (inventory.containsKey(productId)) {
            return Integer.parseInt(inventory.get(productId).get("quantity"));
        }
        return -1;
    }

    public boolean createOrder(int orderId, int productId, int quantity) {
        int availableQuantity = getProductQuantity(productId);
        if (availableQuantity >= quantity) {
            updateProductQuantity(productId, -quantity);

            Map<String, String> orderDetails = new HashMap<>();
            orderDetails.put("product_id", String.valueOf(productId));
            orderDetails.put("quantity", String.valueOf(quantity));
            orderDetails.put("status", "Shipped");

            orders.put(orderId, orderDetails);

            return true;
        }
        return false;
    }

    public boolean changeOrderStatus(int orderId, String status) {
        if (orders.containsKey(orderId)) {
            orders.get(orderId).put("status", status);
            return true;
        }
        return false;
    }

    public String trackOrder(int orderId) {
        if (orders.containsKey(orderId)) {
            return orders.get(orderId).get("status");
        }
        return "";
    }

    public Map<Integer, Map<String, String>> getOrders() {
        return new HashMap<>(orders);
    }

    public Map<Integer, Map<String, String>> getInventory() {
        return new HashMap<>(inventory);
    }
}