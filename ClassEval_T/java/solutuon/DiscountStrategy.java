package org.example;

import java.util.ArrayList;
import java.util.List;

public class DiscountStrategy {
    public static final Promotion FIDELITY_PROMO = order ->
            order.customer.getFidelity() >= 1000 ? order.total() * 0.05 : 0;

    public static final Promotion BULK_ITEM_PROMO = order -> {
        double discount = 0;
        for (Product item : order.cart.getProducts()) {
            if (item.getQuantity() >= 20) {
                discount += item.getQuantity() * item.getPrice() * 0.1;
            }
        }
        return discount;
    };

    public static final Promotion LARGE_ORDER_PROMO = order ->
            order.cart.getProducts().size() >= 10 ? order.total() * 0.07 : 0;

    private Customer customer;
    private Cart cart;
    private Promotion promotion;
    private double total;

    public DiscountStrategy(Customer customer, Cart cart, Promotion promotion) {
        this.customer = customer;
        this.cart = cart;
        this.promotion = promotion;
        this.total = total();
    }

    public double total() {
        total = cart.getProducts().stream()
                .mapToDouble(p -> p.getQuantity() * p.getPrice())
                .sum();
        return total;
    }

    public double due() {
        double discount = (promotion == null) ? 0 : promotion.apply(this);
        return total - discount;
    }

    public double promotion(DiscountStrategy order) {
        return promotion == null ? 0 : promotion.apply(this);
    }

    @FunctionalInterface
    public interface Promotion {
        double apply(DiscountStrategy order);
    }

    public static class Customer {
        private String name;
        private int fidelity;

        public Customer(String name, int fidelity) {
            this.name = name;
            this.fidelity = fidelity;
        }

        public String getName() {
            return name;
        }

        public int getFidelity() {
            return fidelity;
        }
    }

    public static class Cart {
        private List<Product> products;

        public Cart(Product... products) {
            this.products = new ArrayList<>();
            for (Product product : products) {
                this.products.add(product);
            }
        }

        public void addProduct(Product product) {
            this.products.add(product);
        }

        public List<Product> getProducts() {
            return products;
        }
    }

    public static class Product {
        private String name;
        private int quantity;
        private double price;

        public Product(String name, int quantity, double price) {
            this.name = name;
            this.quantity = quantity;
            this.price = price;
        }

        public String getName() {
            return name;
        }

        public int getQuantity() {
            return quantity;
        }

        public double getPrice() {
            return price;
        }
    }
}
