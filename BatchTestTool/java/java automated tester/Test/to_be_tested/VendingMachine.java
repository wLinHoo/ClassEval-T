package to_be_tested;

import java.util.HashMap;
import java.util.Map;

public class VendingMachine {

    public Map<String, Map<String, Integer>> inventory;

    public int balance;

    public VendingMachine() {
        this.inventory = new HashMap<>();
        this.balance = 0;
    }

    public int insertCoin(int amount) {
        balance += amount;
        return balance;
    }

    public int purchaseItem(String item_name) {
        if (inventory.containsKey(item_name)) {
            Map<String, Integer> item = inventory.get(item_name);
            if (item.get("quantity") > 0 && balance >= item.get("price")) {
                balance -= item.get("price");
                item.put("quantity", item.get("quantity") - 1);
                return balance;
            } else {
                // Return -1 to indicate an error
                return -1;
            }
        } else {
            // Return -1 to indicate an error
            return -1;
        }
    }

    public String displayItems() {
        if (inventory.isEmpty()) {
            return "No items available";
        } else {
            StringBuilder sb = new StringBuilder();
            for (Map.Entry<String, Map<String, Integer>> entry : inventory.entrySet()) {
                String itemName = entry.getKey();
                Map<String, Integer> itemInfo = entry.getValue();
                sb.append(itemName).append(" - $").append(itemInfo.get("price")).append(" [").append(itemInfo.get("quantity")).append("]\n");
            }
            return sb.toString();
        }
    }

    public void addItem(String itemName, int price, int quantity) {
        if (!restockItem(itemName, quantity)) {
            Map<String, Integer> item = new HashMap<>();
            item.put("price", price);
            item.put("quantity", quantity);
            this.inventory.put(itemName, item);
        }
    }

    public boolean restockItem(String itemName, int quantity) {
        if (this.inventory.containsKey(itemName)) {
            Map<String, Integer> item = this.inventory.get(itemName);
            item.put("quantity", item.get("quantity") + quantity);
            return true;
        }
        return false;
    }
}
