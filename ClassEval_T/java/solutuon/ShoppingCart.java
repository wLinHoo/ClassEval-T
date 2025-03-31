package org.example;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class ShoppingCart {
    private Map<String, Item> items;

    public ShoppingCart() {
        this.items = new HashMap<>();
    }

    public void addItem(String item, double price, int quantity) {
        if (items.containsKey(item)) {
            Item existingItem = items.get(item);
            existingItem.setPrice(price);
            existingItem.setQuantity(existingItem.getQuantity() + quantity);
        } else {
            items.put(item, new Item(price, quantity));
        }
    }

    public void removeItem(String item, int quantity) {
        if (items.containsKey(item)) {
            Item existingItem = items.get(item);
            int newQuantity = existingItem.getQuantity() - quantity;
            if (newQuantity <= 0) {
                items.remove(item);
            } else {
                existingItem.setQuantity(newQuantity);
            }
        }
    }

    public Map<String, Item> viewItems() {
        return new HashMap<>(items);
    }

    public double totalPrice() {
        double total = 0.0;
        for (Item item : items.values()) {
            total += item.getPrice() * item.getQuantity();
        }
        return total;
    }

    public static class Item {
        private double price;
        private int quantity;

        public Item(double price, int quantity) {
            this.price = price;
            this.quantity = quantity;
        }

        public double getPrice() {
            return price;
        }

        public void setPrice(double price) {
            this.price = price;
        }

        public int getQuantity() {
            return quantity;
        }

        public void setQuantity(int quantity) {
            this.quantity = quantity;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Item item = (Item) o;
            return Double.compare(item.price, price) == 0 && quantity == item.quantity;
        }

        @Override
        public int hashCode() {
            return Objects.hash(price, quantity);
        }
    }
}