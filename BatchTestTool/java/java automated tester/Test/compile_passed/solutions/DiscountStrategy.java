import java.util.*;

public class DiscountStrategy {
    private Customer customer;
    private List<Map<String, Object>> cart;
    private Promotion promotion;
    private double total;

    public DiscountStrategy(Customer customer, List<Map<String, Object>> cart, Promotion promotion) {
        this.customer = customer;
        this.cart = cart;
        this.promotion = promotion;
        this.total = total();
    }

    public double total() {
        total = 0;
        for (Map<String, Object> item : cart) {
            total += (int) item.get("quantity") * (double) item.get("price");
        }
        return total;
    }

    public double due() {
        double discount = 0;
        if (promotion != null) {
            discount = promotion.apply(this);
        }
        return total - discount;
    }

    public static double FidelityPromo(DiscountStrategy order) {
        return order.customer.getFidelity() >= 1000 ? order.total() * 0.05 : 0;
    }

    public static double BulkItemPromo(DiscountStrategy order) {
        double discount = 0;
        for (Map<String, Object> item : order.cart) {
            if ((int) item.get("quantity") >= 20) {
                discount += (int) item.get("quantity") * (double) item.get("price") * 0.1;
            }
        }
        return discount;
    }

    public static double LargeOrderPromo(DiscountStrategy order) {
        Set<Object> products = new HashSet<>();
        for (Map<String, Object> item : order.cart) {
            products.add(item.get("product"));
        }
        return products.size() >= 10 ? order.total() * 0.07 : 0;
    }

    @FunctionalInterface
    interface Promotion {
        double apply(DiscountStrategy order);
    }

    public static Promotion FidelityPromo = order -> order.total() * 0.05d * (order.customer.getFidelity() >= 1000 ? 1 : 0);

    public static Promotion LargeOrderPromo = order -> order.total() * 0.07d * (order.getUniqueProducts() >= 10 ? 1 : 0);

    private int getUniqueProducts() {
        Set<Object> products = new HashSet<>();
        for (Map<String, Object> item : cart) {
            products.add(item.get("product"));
        }
        return products.size();
    }
}

class Customer {
    private int fidelity;

    public Customer(int fidelity) {
        this.fidelity = fidelity;
    }

    public int getFidelity() {
        return fidelity;
    }
}