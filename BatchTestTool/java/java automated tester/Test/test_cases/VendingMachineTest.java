package test_cases;
import to_be_tested.VendingMachine;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;
import java.util.Map;
import java.util.HashMap;

public class VendingMachineTest {

    @Test
    public void testAddItem() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        assertEquals("Coke - $1.25 [10]", vendingMachine.displayItems());
    }

    @Test
    public void testAddItem2() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        vendingMachine.addItem("Coke", 1.25, 10);
        assertEquals("Coke - $1.25 [20]", vendingMachine.displayItems());
    }

    @Test
    public void testAddItem3() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        vendingMachine.addItem("Pizza", 1.25, 10);
        assertEquals("Coke - $1.25 [10]\nPizza - $1.25 [10]", vendingMachine.displayItems());
    }

    @Test
    public void testAddItem4() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        vendingMachine.addItem("Pizza", 1.25, 10);
        vendingMachine.addItem("Pizza", 1.25, 10);
        assertEquals("Coke - $1.25 [10]\nPizza - $1.25 [20]", vendingMachine.displayItems());
    }

    @Test
    public void testAddItem5() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        vendingMachine.addItem("Pizza", 1.25, 10);
        vendingMachine.addItem("Pizza", 1.25, 10);
        vendingMachine.addItem("Coke", 1.25, 10);
        assertEquals("Coke - $1.25 [20]\nPizza - $1.25 [20]", vendingMachine.displayItems());
    }

    @Test
    public void testInsertCoin() {
        VendingMachine vendingMachine = new VendingMachine();
        assertEquals(1.25, vendingMachine.insertCoin(1.25));
    }

    @Test
    public void testInsertCoin2() {
        VendingMachine vendingMachine = new VendingMachine();
        assertEquals(2.5, vendingMachine.insertCoin(2.5));
    }

    @Test
    public void testInsertCoin3() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.insertCoin(1.25);
        vendingMachine.insertCoin(1.25);
        assertEquals(2.50, vendingMachine.getBalance());
    }

    @Test
    public void testInsertCoin4() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.setBalance(1.25);
        vendingMachine.insertCoin(1.25);
        vendingMachine.insertCoin(1.25);
        vendingMachine.insertCoin(1.25);
        assertEquals(5.0, vendingMachine.getBalance());
    }

    @Test
    public void testInsertCoin5() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.setBalance(1.25);
        vendingMachine.insertCoin(1.25);
        vendingMachine.insertCoin(1.25);
        vendingMachine.insertCoin(1.25);
        vendingMachine.insertCoin(1.25);
        assertEquals(6.25, vendingMachine.getBalance());
    }

    @Test
    public void testPurchaseItem() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        vendingMachine.setBalance(1.25);
        assertEquals(0.0, vendingMachine.purchaseItem("Coke"));
        assertEquals("Coke - $1.25 [9]", vendingMachine.displayItems());
    }

    @Test
    public void testPurchaseItem2() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        vendingMachine.setBalance(1.25);
        assertEquals(false, vendingMachine.purchaseItem("Pizza"));
        assertEquals("Coke - $1.25 [10]", vendingMachine.displayItems());
    }

    @Test
    public void testPurchaseItem3() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        vendingMachine.setBalance(0);
        assertEquals(false, vendingMachine.purchaseItem("Coke"));
        assertEquals("Coke - $1.25 [10]", vendingMachine.displayItems());
    }

    @Test
    public void testPurchaseItem4() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 0);
        vendingMachine.setBalance(1.25);
        assertEquals(false, vendingMachine.purchaseItem("Coke"));
        assertEquals("Coke - $1.25 [0]", vendingMachine.displayItems());
    }

    @Test
    public void testPurchaseItem5() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        vendingMachine.addItem("Pizza", 1.25, 10);
        vendingMachine.setBalance(1.25);
        assertEquals(0.0, vendingMachine.purchaseItem("Pizza"));
        assertEquals("Coke - $1.25 [10]\nPizza - $1.25 [9]", vendingMachine.displayItems());
    }

    @Test
    public void testRestockItem() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        assertEquals(true, vendingMachine.restockItem("Coke", 10));
        assertEquals("Coke - $1.25 [20]", vendingMachine.displayItems());
    }

    @Test
    public void testRestockItem2() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        assertEquals(false, vendingMachine.restockItem("Pizza", 10));
        assertEquals("Coke - $1.25 [10]", vendingMachine.displayItems());
    }

    @Test
    public void testRestockItem3() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 0);
        assertEquals(true, vendingMachine.restockItem("Coke", 10));
        assertEquals("Coke - $1.25 [10]", vendingMachine.displayItems());
    }

    @Test
    public void testRestockItem4() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        vendingMachine.addItem("Pizza", 1.25, 10);
        assertEquals(true, vendingMachine.restockItem("Pizza", 10));
        assertEquals("Coke - $1.25 [10]\nPizza - $1.25 [20]", vendingMachine.displayItems());
    }

    @Test
    public void testRestockItem5() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        vendingMachine.addItem("Pizza", 1.25, 10);
        assertEquals(true, vendingMachine.restockItem("Pizza", 0));
        assertEquals("Coke - $1.25 [10]\nPizza - $1.25 [10]", vendingMachine.displayItems());
    }

    @Test
    public void testDisplayItems() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        assertEquals("Coke - $1.25 [10]", vendingMachine.displayItems());
    }

    @Test
    public void testDisplayItems2() {
        VendingMachine vendingMachine = new VendingMachine();
        assertEquals(false, vendingMachine.displayItems());
    }

    @Test
    public void testDisplayItems3() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 10);
        vendingMachine.addItem("Pizza", 1.25, 10);
        assertEquals("Coke - $1.25 [10]\nPizza - $1.25 [10]", vendingMachine.displayItems());
    }

    @Test
    public void testDisplayItems4() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 0);
        assertEquals("Coke - $1.25 [0]", vendingMachine.displayItems());
    }

    @Test
    public void testDisplayItems5() {
        VendingMachine vendingMachine = new VendingMachine();
        vendingMachine.addItem("Coke", 1.25, 0);
        vendingMachine.addItem("Pizza", 1.25, 10);
        assertEquals("Coke - $1.25 [0]\nPizza - $1.25 [10]", vendingMachine.displayItems());
    }

    @Test
    public void testMain() {
        VendingMachine vendingMachine = new VendingMachine();
        assertEquals(false, vendingMachine.displayItems());
        vendingMachine.addItem("Coke", 1.25, 10);
        assertEquals("Coke - $1.25 [10]", vendingMachine.displayItems());
        assertEquals(1.25, vendingMachine.insertCoin(1.25));
        assertEquals(0.0, vendingMachine.purchaseItem("Coke"));
        assertEquals("Coke - $1.25 [9]", vendingMachine.displayItems());
        assertEquals(false, vendingMachine.purchaseItem("Pizza"));
        assertEquals(true, vendingMachine.restockItem("Coke", 10));
        assertEquals("Coke - $1.25 [19]", vendingMachine.displayItems());
        assertEquals(false, vendingMachine.restockItem("Pizza", 10));
        assertEquals("Coke - $1.25 [19]", vendingMachine.displayItems());
    }

    @Test
    public void testMain2() {
        VendingMachine vendingMachine = new VendingMachine();
        assertEquals(false, vendingMachine.purchaseItem("Coke"));
        vendingMachine.addItem("Coke", 1.25, 10);
        assertEquals("Coke - $1.25 [10]", vendingMachine.displayItems());
        assertEquals(false, vendingMachine.restockItem("Pizza", 10));
        assertEquals("Coke - $1.25 [10]", vendingMachine.displayItems());
        assertEquals(1.25, vendingMachine.insertCoin(1.25));
        assertEquals(0.0, vendingMachine.purchaseItem("Coke"));
        assertEquals("Coke - $1.25 [9]", vendingMachine.displayItems());
    }
}
