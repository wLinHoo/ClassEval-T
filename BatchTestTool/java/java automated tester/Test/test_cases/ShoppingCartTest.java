package test_cases;
import to_be_tested.ShoppingCart;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Map;

import static org.junit.jupiter.api.Assertions.*;

public class ShoppingCartTest {

    private ShoppingCart shoppingCart;

    @BeforeEach
    public void setUp() {
        shoppingCart = new ShoppingCart();
    }

    @Test
    public void testAddItem1() {
        shoppingCart.addItem("apple", 1, 5);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 5)));
    }

    @Test
    public void testAddItem2() {
        shoppingCart.addItem("apple", 1, 1);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 1)));
    }

    @Test
    public void testAddItem3() {
        shoppingCart.addItem("aaa", 1, 1);
        assertEquals(shoppingCart.viewItems(), Map.of("aaa", new ShoppingCart.Item(1, 1)));
    }

    @Test
    public void testAddItem4() {
        shoppingCart.addItem("bbb", 1, 1);
        assertEquals(shoppingCart.viewItems(), Map.of("bbb", new ShoppingCart.Item(1, 1)));
    }

    @Test
    public void testAddItem5() {
        shoppingCart.addItem("ccc", 1, 1);
        assertEquals(shoppingCart.viewItems(), Map.of("ccc", new ShoppingCart.Item(1, 1)));
    }

    @Test
    public void testAddItem6() {
        shoppingCart.addItem("apple", 1, 5);
        shoppingCart.addItem("apple", 1, 5);

        Map<String, ShoppingCart.Item> items = shoppingCart.viewItems();
        ShoppingCart.Item expectedItem = new ShoppingCart.Item(1, 10);
        ShoppingCart.Item actualItem = items.get("apple");

        assertNotNull(actualItem);
        assertTrue(expectedItem.equals(actualItem), "Items should be equal");
    }


    @Test
    public void testRemoveItem1() {
        shoppingCart.addItem("apple", 1, 5);
        shoppingCart.removeItem("apple", 3);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 2)));
    }

    @Test
    public void testRemoveItem2() {
        shoppingCart.addItem("apple", 1, 5);
        shoppingCart.removeItem("apple", 1);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 4)));
    }

    @Test
    public void testRemoveItem3() {
        shoppingCart.addItem("apple", 1, 5);
        shoppingCart.removeItem("apple", 1);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 4)));
    }

    @Test
    public void testRemoveItem4() {
        shoppingCart.addItem("apple", 1, 5);
        shoppingCart.removeItem("apple", 2);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 3)));
    }

    @Test
    public void testRemoveItem5() {
        shoppingCart.addItem("apple", 1, 5);
        shoppingCart.removeItem("apple", 4);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 1)));
    }

    @Test
    public void testRemoveItem6() {
        shoppingCart.addItem("apple", 1, 5);
        shoppingCart.removeItem("banana", 4);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 5)));
    }

    @Test
    public void testViewItems1() {
        shoppingCart.addItem("apple", 1, 5);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 5)));
    }

    @Test
    public void testViewItems2() {
        shoppingCart.addItem("apple", 1, 4);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 4)));
    }

    @Test
    public void testViewItems3() {
        shoppingCart.addItem("apple", 1, 3);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 3)));
    }

    @Test
    public void testViewItems4() {
        shoppingCart.addItem("apple", 1, 2);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 2)));
    }

    @Test
    public void testViewItems5() {
        shoppingCart.addItem("apple", 1, 1);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 1)));
    }

    @Test
    public void testTotalPrice1() {
        shoppingCart.addItem("apple", 1, 5);
        shoppingCart.addItem("banana", 2, 3);
        assertEquals(shoppingCart.totalPrice(), 11.0);
    }

    @Test
    public void testTotalPrice2() {
        shoppingCart.addItem("apple", 1, 5);
        shoppingCart.addItem("banana", 2, 3);
        shoppingCart.removeItem("apple", 3);
        assertEquals(shoppingCart.totalPrice(), 8.0);
    }

    @Test
    public void testTotalPrice3() {
        shoppingCart.addItem("apple", 1, 1);
        shoppingCart.addItem("banana", 2, 1);
        assertEquals(shoppingCart.totalPrice(), 3.0);
    }

    @Test
    public void testTotalPrice4() {
        shoppingCart.addItem("apple", 1, 2);
        shoppingCart.addItem("banana", 2, 1);
        assertEquals(shoppingCart.totalPrice(), 4.0);
    }

    @Test
    public void testTotalPrice5() {
        shoppingCart.addItem("apple", 1, 3);
        shoppingCart.addItem("banana", 2, 1);
        assertEquals(shoppingCart.totalPrice(), 5.0);
    }

    @Test
    public void testShoppingCart() {
        shoppingCart.addItem("apple", 1, 5);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 5)));
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 5)));
        shoppingCart.removeItem("apple", 3);
        assertEquals(shoppingCart.viewItems(), Map.of("apple", new ShoppingCart.Item(1, 2)));
        shoppingCart.addItem("banana", 2, 3);
        assertEquals(shoppingCart.totalPrice(), 8.0);
    }
}