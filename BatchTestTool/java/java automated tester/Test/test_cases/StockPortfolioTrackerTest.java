package test_cases;
import to_be_tested.StockPortfolioTracker;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.ArrayList;
import java.util.List;

public class StockPortfolioTrackerTest {

    @Test
    void testAddStock() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        List<StockPortfolioTracker.Stock> expected = new ArrayList<>();
        expected.add(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        assertEquals(expected, tracker.getPortfolio());
    }

    @Test
    void testAddStock_2() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        List<StockPortfolioTracker.Stock> expected = new ArrayList<>();
        expected.add(new StockPortfolioTracker.Stock("AAPL", 150.0, 20));
        assertEquals(expected, tracker.getPortfolio());
    }

    @Test
    void testAddStock_3() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        tracker.addStock(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        List<StockPortfolioTracker.Stock> expected = new ArrayList<>();
        expected.add(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        expected.add(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        assertEquals(expected, tracker.getPortfolio());
    }

    @Test
    void testAddStock_4() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        tracker.addStock(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        List<StockPortfolioTracker.Stock> expected = new ArrayList<>();
        expected.add(new StockPortfolioTracker.Stock("AAPL", 150.0, 20));
        expected.add(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        assertEquals(expected, tracker.getPortfolio());
    }

    @Test
    void testAddStock_5() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        tracker.addStock(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        tracker.addStock(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        List<StockPortfolioTracker.Stock> expected = new ArrayList<>();
        expected.add(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        expected.add(new StockPortfolioTracker.Stock("MSFT", 150.0, 20));
        assertEquals(expected, tracker.getPortfolio());
    }

    @Test
    void testRemoveStock() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        assertTrue(tracker.removeStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10)));
        assertTrue(tracker.getPortfolio().isEmpty());
    }

    @Test
    void testRemoveStock_2() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        tracker.addStock(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        assertTrue(tracker.removeStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10)));
        List<StockPortfolioTracker.Stock> expected = new ArrayList<>();
        expected.add(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        assertEquals(expected, tracker.getPortfolio());
    }

    @Test
    void testRemoveStock_3() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        tracker.addStock(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        assertFalse(tracker.removeStock(new StockPortfolioTracker.Stock("MSFT", 150.0, 20)));
        List<StockPortfolioTracker.Stock> expected = new ArrayList<>();
        expected.add(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        expected.add(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        assertEquals(expected, tracker.getPortfolio());
    }

    @Test
    void testRemoveStock_4() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        assertFalse(tracker.removeStock(new StockPortfolioTracker.Stock("MSFT", 150.0, 10)));
        List<StockPortfolioTracker.Stock> expected = new ArrayList<>();
        expected.add(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        assertEquals(expected, tracker.getPortfolio());
    }

    @Test
    void testRemoveStock_5() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        tracker.addStock(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        assertTrue(tracker.removeStock(new StockPortfolioTracker.Stock("MSFT", 150.0, 10)));
        List<StockPortfolioTracker.Stock> expected = new ArrayList<>();
        expected.add(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        assertEquals(expected, tracker.getPortfolio());
    }

    @Test
    void testBuyStock() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        assertTrue(tracker.buyStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10)));
        List<StockPortfolioTracker.Stock> expected = new ArrayList<>();
        expected.add(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        assertEquals(expected, tracker.getPortfolio());
        assertEquals(10000.0 - (150.0 * 10), tracker.getCashBalance());
    }

    @Test
    void testSellStock() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        assertTrue(tracker.sellStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10)));
        List<StockPortfolioTracker.Stock> expected = new ArrayList<>();
        assertEquals(expected, tracker.getPortfolio());
        assertEquals(10000.0 + (150.0 * 10), tracker.getCashBalance());
    }

    @Test
    void testCalculatePortfolioValue() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        tracker.addStock(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        assertEquals(150.0 * 10 + 150.0 * 10, tracker.calculatePortfolioValue());
    }

    @Test
    void testGetPortfolioSummary() {
        StockPortfolioTracker tracker = new StockPortfolioTracker(10000.0);
        tracker.addStock(new StockPortfolioTracker.Stock("AAPL", 150.0, 10));
        tracker.addStock(new StockPortfolioTracker.Stock("MSFT", 150.0, 10));
        String expected = "AAPL: 10 shares at $150.0 each\n" +
                "MSFT: 10 shares at $150.0 each\n" +
                "Total Value: $3000.0\n";
        assertEquals(expected, tracker.getPortfolioSummary());
    }
}
