package test_cases;
import to_be_tested.Warehouse;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class WarehouseTest {

    @Test
    public void testAddProduct1() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 10);
        assertEquals(10, warehouse.getProductQuantity(1));
    }

    @Test
    public void testAddProduct2() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 10);
        warehouse.addProduct(2, "product 2", 5);
        assertEquals(10, warehouse.getProductQuantity(1));
        assertEquals(5, warehouse.getProductQuantity(2));
    }

    @Test
    public void testAddProduct3() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 3", 10);
        assertEquals(10, warehouse.getProductQuantity(1));
    }

    @Test
    public void testAddProduct4() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 4", 10);
        assertEquals(10, warehouse.getProductQuantity(1));
    }

    @Test
    public void testAddProduct5() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 5", 10);
        assertEquals(10, warehouse.getProductQuantity(1));
    }

    @Test
    public void testAddProduct6() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 5", 10);
        warehouse.addProduct(1, "product 5", 10);
        assertEquals(20, warehouse.getProductQuantity(1));
    }

    @Test
    public void testUpdateProductQuantity1() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 10);
        warehouse.updateProductQuantity(1, 5);
        assertEquals(15, warehouse.getProductQuantity(1));
    }

    @Test
    public void testUpdateProductQuantity2() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 10);
        warehouse.updateProductQuantity(1, -5);
        assertEquals(5, warehouse.getProductQuantity(1));
    }

    @Test
    public void testUpdateProductQuantity3() {
        Warehouse warehouse = new Warehouse();
        warehouse.updateProductQuantity(1, -5);
        assertEquals(-1, warehouse.getProductQuantity(1));
    }

    @Test
    public void testUpdateProductQuantity4() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 10);
        warehouse.updateProductQuantity(1, 1);
        assertEquals(11, warehouse.getProductQuantity(1));
    }

    @Test
    public void testUpdateProductQuantity5() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 10);
        warehouse.updateProductQuantity(1, -9);
        assertEquals(1, warehouse.getProductQuantity(1));
    }

    @Test
    public void testGetProductQuantity1() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 10);
        assertEquals(10, warehouse.getProductQuantity(1));
    }

    @Test
    public void testGetProductQuantity2() {
        Warehouse warehouse = new Warehouse();
        assertEquals(-1, warehouse.getProductQuantity(1));
    }

    @Test
    public void testGetProductQuantity3() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 5);
        assertEquals(5, warehouse.getProductQuantity(1));
    }

    @Test
    public void testGetProductQuantity4() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 100);
        assertEquals(100, warehouse.getProductQuantity(1));
    }

    @Test
    public void testGetProductQuantity5() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(5, "product 1", 10);
        assertEquals(10, warehouse.getProductQuantity(5));
    }

    @Test
    public void testCreateOrder1() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 10);
        assertTrue(warehouse.createOrder(1, 1, 5));
        assertEquals("Shipped", warehouse.trackOrder(1));
    }

    @Test
    public void testCreateOrder2() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 10);
        assertFalse(warehouse.createOrder(1, 1, 15));
    }

    @Test
    public void testCreateOrder3() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 1);
        assertTrue(warehouse.createOrder(1, 1, 1));
        assertEquals("Shipped", warehouse.trackOrder(1));
    }

    @Test
    public void testCreateOrder4() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 4", 5);
        assertTrue(warehouse.createOrder(1, 1, 5));
        assertEquals("Shipped", warehouse.trackOrder(1));
    }

    @Test
    public void testCreateOrder5() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 5", 100);
        assertTrue(warehouse.createOrder(1, 1, 50));
        assertEquals("Shipped", warehouse.trackOrder(1));
    }

    @Test
    public void testChangeOrderStatus1() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 10);
        warehouse.createOrder(1, 1, 5);
        assertTrue(warehouse.changeOrderStatus(1, "Delivered"));
        assertEquals("Delivered", warehouse.trackOrder(1));
    }

    @Test
    public void testChangeOrderStatus2() {
        Warehouse warehouse = new Warehouse();
        assertFalse(warehouse.changeOrderStatus(1, "Delivered"));
    }

    @Test
    public void testChangeOrderStatus3() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 3", 5);
        warehouse.createOrder(1, 1, 5);
        assertTrue(warehouse.changeOrderStatus(1, "Delivered"));
        assertEquals("Delivered", warehouse.trackOrder(1));
    }

    @Test
    public void testChangeOrderStatus4() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 4", 100);
        warehouse.createOrder(1, 1, 50);
        assertTrue(warehouse.changeOrderStatus(1, "Delivered"));
        assertEquals("Delivered", warehouse.trackOrder(1));
    }

    @Test
    public void testChangeOrderStatus5() {
        Warehouse warehouse = new Warehouse();
        assertFalse(warehouse.changeOrderStatus(2, "Delivered"));
    }

    @Test
    public void testTrackOrder1() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 10);
        warehouse.createOrder(1, 1, 5);
        assertEquals("Shipped", warehouse.trackOrder(1));
    }

    @Test
    public void testTrackOrder2() {
        Warehouse warehouse = new Warehouse();
        assertNull(warehouse.trackOrder(1));
    }

    @Test
    public void testTrackOrder3() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 3", 10);
        warehouse.createOrder(1, 1, 1);
        assertEquals("Shipped", warehouse.trackOrder(1));
    }

    @Test
    public void testTrackOrder4() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 4", 100);
        warehouse.createOrder(1, 1, 50);
        assertEquals("Shipped", warehouse.trackOrder(1));
    }

    @Test
    public void testTrackOrder5() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 5", 100);
        warehouse.createOrder(1, 1, 10);
        assertEquals("Shipped", warehouse.trackOrder(1));
    }

    @Test
    public void testMain() {
        Warehouse warehouse = new Warehouse();
        warehouse.addProduct(1, "product 1", 10);
        assertEquals(10, warehouse.getProductQuantity(1));

        warehouse.updateProductQuantity(1, -5);
        assertEquals(5, warehouse.getProductQuantity(1));

        assertEquals(5, warehouse.getProductQuantity(1));

        assertTrue(warehouse.createOrder(1, 1, 3));
        assertEquals("Shipped", warehouse.trackOrder(1));

        assertTrue(warehouse.changeOrderStatus(1, "Delivered"));
        assertEquals("Delivered", warehouse.trackOrder(1));
    }
}