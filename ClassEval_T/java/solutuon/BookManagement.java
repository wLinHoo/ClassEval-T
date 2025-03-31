package org.example;

import java.util.HashMap;
import java.util.Map;

public class BookManagement {
    private Map<String, Integer> inventory;

    public BookManagement() {
        this.inventory = new HashMap<>();
    }

    public void addBook(String title, int quantity) {
        if (inventory.containsKey(title)) {
            inventory.put(title, inventory.get(title) + quantity);
        } else {
            inventory.put(title, quantity);
        }
    }

    public void removeBook(String title, int quantity) throws Exception {
        if (!inventory.containsKey(title) || inventory.get(title) < quantity) {
            throw new Exception("Invalid operation");
        }
        int newQuantity = inventory.get(title) - quantity;
        if (newQuantity == 0) {
            inventory.remove(title);
        } else {
            inventory.put(title, newQuantity);
        }
    }

    public Map<String, Integer> viewInventory() {
        return new HashMap<>(inventory);
    }

    public int viewBookQuantity(String title) {
        return inventory.getOrDefault(title, 0);
    }
}