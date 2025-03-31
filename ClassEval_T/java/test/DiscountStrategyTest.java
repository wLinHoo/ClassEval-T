package org.example;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class DiscountStrategyTest {

    @Test
    public void testTotal1() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 20.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, null);
        double expectedTotal = 250.0;
        double actualTotal = order.total();
        assertEquals(expectedTotal, actualTotal, 0.001);
    }

    @Test
    public void testTotal2() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 10.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, null);
        double expectedTotal = 150.0;
        double actualTotal = order.total();
        assertEquals(expectedTotal, actualTotal, 0.001);
    }

    @Test
    public void testTotal3() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 200.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, null);
        double expectedTotal = 2050.0;
        double actualTotal = order.total();
        assertEquals(expectedTotal, actualTotal, 0.001);
    }

    @Test
    public void testTotal4() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 1, 20.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, null);
        double expectedTotal = 70.0;
        double actualTotal = order.total();
        assertEquals(expectedTotal, actualTotal, 0.001);
    }

    @Test
    public void testTotal5() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart();
        DiscountStrategy order = new DiscountStrategy(customer, cart, null);
        double expectedTotal = 0.0;
        double actualTotal = order.total();
        assertEquals(expectedTotal, actualTotal, 0.001);
    }

    @Test
    public void testDue1() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 20.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, null);
        double expectedDue = 250.0;
        double actualDue = order.due();
        assertEquals(expectedDue, actualDue, 0.001);
    }

    @Test
    public void testDue2() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 20.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.FIDELITY_PROMO);
        double expectedDue = 237.5;
        double actualDue = order.due();
        assertEquals(expectedDue, actualDue, 0.001);
    }

    @Test
    public void testDue3() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 20, 20.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.BULK_ITEM_PROMO);
        double expectedDue = 410.0;
        double actualDue = order.due();
        assertEquals(expectedDue, actualDue, 0.001);
    }

    @Test
    public void testDue4() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart();
        for (int i = 0; i < 15; i++) {
            cart.addProduct(new DiscountStrategy.Product("product" + i, 1, 10.0));
        }
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.LARGE_ORDER_PROMO);
        double expectedDue = 139.5;
        double actualDue = order.due();
        assertEquals(expectedDue, actualDue, 0.001);
    }

    @Test
    public void testDue5() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 900);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 20.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.FIDELITY_PROMO);
        double expectedDue = 250.0; // 无折扣的情况下总金额为 250.0
        double actualDue = order.due();
        assertEquals(expectedDue, actualDue, 0.001);
    }




    @Test
    public void testFidelityPromo1() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1000);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 20.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.FIDELITY_PROMO);
        double expectedDiscount = 12.5;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testFidelityPromo2() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 800);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 20.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.FIDELITY_PROMO);
        double expectedDiscount = 0;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }


    @Test
    public void testFidelityPromo3() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 0);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 20.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.FIDELITY_PROMO);
        double expectedDiscount = 0;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testFidelityPromo4() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 10000);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 20.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.FIDELITY_PROMO);
        double expectedDiscount = 12.5;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testFidelityPromo5() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1800);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 20.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.FIDELITY_PROMO);
        double expectedDiscount = 12.5;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testBulkItemPromo1() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 20, 10.0),
                new DiscountStrategy.Product("product2", 5, 5.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.BULK_ITEM_PROMO);
        double expectedDiscount = 20.0;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testBulkItemPromo2() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 10.0),
                new DiscountStrategy.Product("product2", 5, 5.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.BULK_ITEM_PROMO);
        double expectedDiscount = 0;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testBulkItemPromo3() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 100, 10.0),
                new DiscountStrategy.Product("product2", 5, 5.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.BULK_ITEM_PROMO);
        double expectedDiscount = 100.0;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testBulkItemPromo4() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 1, 10.0),
                new DiscountStrategy.Product("product2", 5, 5.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.BULK_ITEM_PROMO);
        double expectedDiscount = 0.0;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testBulkItemPromo5() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 30, 10.0),
                new DiscountStrategy.Product("product2", 5, 5.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.BULK_ITEM_PROMO);
        double expectedDiscount = 30.0;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testLargeOrderPromo1() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart();
        for (int i = 0; i < 10; i++) {
            cart.addProduct(new DiscountStrategy.Product("product" + i, 1, 10.0));
        }
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.LARGE_ORDER_PROMO);
        double expectedDiscount = 7.0;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testLargeOrderPromo2() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart();
        for (int i = 0; i < 5; i++) {
            cart.addProduct(new DiscountStrategy.Product("product" + i, 1, 10.0));
        }
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.LARGE_ORDER_PROMO);
        double expectedDiscount = 0;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testLargeOrderPromo3() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart();
        for (int i = 0; i < 100; i++) {
            cart.addProduct(new DiscountStrategy.Product("product" + i, 1, 10.0));
        }
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.LARGE_ORDER_PROMO);
        double expectedDiscount = 70.0;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testLargeOrderPromo4() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart();
        for (int i = 0; i < 1000; i++) {
            cart.addProduct(new DiscountStrategy.Product("product" + i, 1, 10.0));
        }
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.LARGE_ORDER_PROMO);
        double expectedDiscount = 700.0;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testLargeOrderPromo5() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product0", 1, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, DiscountStrategy.LARGE_ORDER_PROMO);
        double expectedDiscount = 0.0;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }

    @Test
    public void testDiscountStrategy() {
        DiscountStrategy.Customer customer = new DiscountStrategy.Customer("John Doe", 1200);
        DiscountStrategy.Cart cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 10, 20.0),
                new DiscountStrategy.Product("product2", 5, 10.0));
        DiscountStrategy order = new DiscountStrategy(customer, cart, null);
        double expectedTotal = 250.0;
        double actualTotal = order.total();
        assertEquals(expectedTotal, actualTotal, 0.001);

        double expectedDue = 250.0;
        double actualDue = order.due();
        assertEquals(expectedDue, actualDue, 0.001);

        order = new DiscountStrategy(customer, cart, DiscountStrategy.FIDELITY_PROMO);
        double expectedDiscount = 12.5;
        double actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);

        cart = new DiscountStrategy.Cart(new DiscountStrategy.Product("product1", 20, 10.0),
                new DiscountStrategy.Product("product2", 5, 5.0));
        order = new DiscountStrategy(customer, cart, DiscountStrategy.BULK_ITEM_PROMO);
        expectedDiscount = 20.0;
        actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);

        cart = new DiscountStrategy.Cart();
        for (int i = 0; i < 10; i++) {
            cart.addProduct(new DiscountStrategy.Product("product" + i, 1, 10.0));
        }
        order = new DiscountStrategy(customer, cart, DiscountStrategy.LARGE_ORDER_PROMO);
        expectedDiscount = 7.0;
        actualDiscount = order.promotion(order);
        assertEquals(expectedDiscount, actualDiscount, 0.001);
    }
}
