package org.example;

import java.util.LinkedHashMap;
import java.util.Map;

public class VendingMachine {
    private Map<String, Product> inventory;
    private double balance;

    public VendingMachine() {
        this.inventory = new LinkedHashMap<>();
        this.balance = 0;
    }

    public void addItem(String itemName, double price, int quantity) {
        if (!restockItem(itemName, quantity)) {
            inventory.put(itemName, new Product(price, quantity));
        }
    }

    public double insertCoin(double amount) {
        balance += amount;
        return balance;
    }

    public Object purchaseItem(String itemName) {
        if (inventory.containsKey(itemName)) {
            Product item = inventory.get(itemName);
            if (item.getQuantity() > 0 && balance >= item.getPrice()) {
                balance -= item.getPrice();
                item.setQuantity(item.getQuantity() - 1);
                return balance;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    public boolean restockItem(String itemName, int quantity) {
        if (inventory.containsKey(itemName)) {
            Product item = inventory.get(itemName);
            item.setQuantity(item.getQuantity() + quantity);
            return true;
        } else {
            return false;
        }
    }

    public Object displayItems() {
        if (inventory.isEmpty()) {
            return false;
        } else {
            StringBuilder items = new StringBuilder();
            for (Map.Entry<String, Product> entry : inventory.entrySet()) {
                Product item = entry.getValue();
                items.append(String.format("%s - $%.2f [%d]\n", entry.getKey(), item.getPrice(), item.getQuantity()));
            }
            return items.toString().trim();
        }
    }


    public Map<String, Product> getInventory() {
        return inventory;
    }

    public void setInventory(Map<String, Product> inventory) {
        this.inventory = inventory;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public static class Product {
        private double price;
        private int quantity;

        public Product(double price, int quantity) {
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
    }
}
