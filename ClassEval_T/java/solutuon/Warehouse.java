package org.example;

import java.util.HashMap;
import java.util.Map;

class Warehouse {
    private Map<Integer, Product> inventory;
    private Map<Integer, Order> orders;

    public Warehouse() {
        this.inventory = new HashMap<>();
        this.orders = new HashMap<>();
    }

    public void addProduct(int productId, String name, int quantity) {
        if (inventory.containsKey(productId)) {
            inventory.get(productId).addQuantity(quantity);
        } else {
            inventory.put(productId, new Product(name, quantity));
        }
    }

    public void updateProductQuantity(int productId, int quantity) {
        if (inventory.containsKey(productId)) {
            inventory.get(productId).addQuantity(quantity);
        }
    }

    public int getProductQuantity(int productId) {
        if (inventory.containsKey(productId)) {
            return inventory.get(productId).getQuantity();
        } else {
            return -1;
        }
    }

    public boolean createOrder(int orderId, int productId, int quantity) {
        if (inventory.containsKey(productId) && inventory.get(productId).getQuantity() >= quantity) {
            inventory.get(productId).addQuantity(-quantity);
            orders.put(orderId, new Order(productId, quantity, "Shipped"));
            return true;
        } else {
            return false;
        }
    }

    public boolean changeOrderStatus(int orderId, String status) {
        if (orders.containsKey(orderId)) {
            orders.get(orderId).setStatus(status);
            return true;
        } else {
            return false;
        }
    }

    public String trackOrder(int orderId) {
        if (orders.containsKey(orderId)) {
            return orders.get(orderId).getStatus();
        } else {
            return null;
        }
    }

    private static class Product {
        private String name;
        private int quantity;

        public Product(String name, int quantity) {
            this.name = name;
            this.quantity = quantity;
        }

        public void addQuantity(int quantity) {
            this.quantity += quantity;
        }

        public int getQuantity() {
            return quantity;
        }
    }

    private static class Order {
        private int productId;
        private int quantity;
        private String status;

        public Order(int productId, int quantity, String status) {
            this.productId = productId;
            this.quantity = quantity;
            this.status = status;
        }

        public String getStatus() {
            return status;
        }

        public void setStatus(String status) {
            this.status = status;
        }
    }
}