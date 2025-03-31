import java.util.HashMap;
import java.util.Map;

public class BookManagement {
    private Map<String, Integer> inventory;

    public BookManagement() {
        inventory = new HashMap<>();
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
            throw new Exception("Book not found or insufficient quantity");
        }
        inventory.put(title, inventory.get(title) - quantity);
        if (inventory.get(title) == 0) {
            inventory.remove(title);
        }
    }

    public int viewBookQuantity(String title) {
        if (!inventory.containsKey(title)) {
            return 0;
        }
        return inventory.get(title);
    }

    public Map<String, Integer> viewInventory() {
        return inventory;
    }
}