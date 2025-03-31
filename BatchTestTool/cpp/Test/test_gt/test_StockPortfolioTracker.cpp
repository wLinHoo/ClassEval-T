#include <gtest/gtest.h>
#include "pch.h"

class StockPortfolioTrackerTest : public ::testing::Test {
protected:
    void SetUp() override {
        
    }

    void TearDown() override {
        
    }
};

TEST_F(StockPortfolioTrackerTest, TestMain) {
    StockPortfolioTracker tracker(10000.0);

    tracker.add_stock({ "AAPL", 150.0, 10 });
    std::vector<Stock> now{ {"AAPL", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), now);
    EXPECT_TRUE(tracker.buy_stock({ "MSFT", 150.0, 10 }));
    now = { {"AAPL", 150.0, 10}, {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), now);
    EXPECT_DOUBLE_EQ(tracker.get_cash_balance(), 8500.0);
    EXPECT_TRUE(tracker.sell_stock({ "AAPL", 150.0, 9 }));
    now = { {"AAPL", 150.0, 1}, {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), now);
    EXPECT_DOUBLE_EQ(tracker.get_cash_balance(), 9850.0);
    EXPECT_TRUE(tracker.remove_stock({ "AAPL", 150.0, 1 }));
    now = { {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), now);
    EXPECT_DOUBLE_EQ(tracker.calculate_portfolio_value(), 11350.0);
    EXPECT_EQ(tracker.get_portfolio_summary(), std::make_pair(11350.0, std::vector<StockSummary>{{"MSFT", 1500.0}}));
    EXPECT_DOUBLE_EQ(tracker.get_stock_value({ "MSFT", 150.0, 10 }), 1500.0);
}

TEST_F(StockPortfolioTrackerTest, TestMain2) {
    StockPortfolioTracker tracker(10000.0);
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });

    tracker.add_stock({ "MSFT", 150.0, 10 });
    std::vector<Stock> now{ {"AAPL", 150.0, 10}, {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), now);
    EXPECT_TRUE(tracker.remove_stock({ "AAPL", 150.0, 10 }));
    now = { {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), now);
    EXPECT_DOUBLE_EQ(tracker.calculate_portfolio_value(), 11500.0);
    EXPECT_EQ(tracker.get_portfolio_summary(), std::make_pair(11500.0, std::vector<StockSummary>{{"MSFT", 1500.0}}));
    EXPECT_DOUBLE_EQ(tracker.get_stock_value({ "MSFT", 150.0, 10 }), 1500.0);
    EXPECT_TRUE(tracker.buy_stock({ "AAPL", 150.0, 10 }));
    now = { {"MSFT", 150.0, 10}, {"AAPL", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), now);
    EXPECT_DOUBLE_EQ(tracker.get_cash_balance(), 8500.0);
}

TEST_F(StockPortfolioTrackerTest, TestMain3) {
    StockPortfolioTracker tracker(10000.0);
    tracker.set_portfolio({ {"AAPL", 150.0, 10}, {"MSFT", 150.0, 10} });

    EXPECT_DOUBLE_EQ(tracker.get_stock_value({ "MSFT", 150.0, 10 }), 1500.0);
    EXPECT_TRUE(tracker.buy_stock({ "AAPL", 150.0, 10 }));
    std::vector<Stock> now{ {"AAPL", 150.0, 20}, {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), now);
    EXPECT_DOUBLE_EQ(tracker.get_cash_balance(), 8500.0);
    EXPECT_TRUE(tracker.sell_stock({ "AAPL", 150.0, 10 }));
    now = { {"AAPL", 150.0, 10}, {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), now);
    EXPECT_DOUBLE_EQ(tracker.get_cash_balance(), 10000.0);
    EXPECT_TRUE(tracker.remove_stock({ "AAPL", 150.0, 10 }));
    now = { {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), now);
    EXPECT_DOUBLE_EQ(tracker.calculate_portfolio_value(), 11500.0);
    EXPECT_EQ(tracker.get_portfolio_summary(), std::make_pair(11500.0, std::vector<StockSummary>{{"MSFT", 1500.0}}));
    EXPECT_DOUBLE_EQ(tracker.get_stock_value({ "MSFT", 150.0, 10 }), 1500.0);
    EXPECT_NO_THROW(tracker.add_stock({ "AAPL", 150.0, 10 }));
    now = { {"MSFT", 150.0, 10}, {"AAPL", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), now);
}

class StockPortfolioTrackerTestAddStock : public ::testing::Test {
protected:
    StockPortfolioTracker tracker;

    StockPortfolioTrackerTestAddStock() : tracker(10000.0) {}
};

TEST_F(StockPortfolioTrackerTestAddStock, TestAddStock) {
    tracker.add_stock({ "AAPL", 150.0, 10 });
    std::vector<Stock> expected{ {"AAPL", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
}

TEST_F(StockPortfolioTrackerTestAddStock, TestAddStock2) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    tracker.add_stock({ "AAPL", 150.0, 10 });
    std::vector<Stock> expected{ {"AAPL", 150.0, 20} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
}

TEST_F(StockPortfolioTrackerTestAddStock, TestAddStock3) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    tracker.add_stock({ "MSFT", 150.0, 10 });
    std::vector<Stock> expected{ {"AAPL", 150.0, 10}, {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
}

TEST_F(StockPortfolioTrackerTestAddStock, TestAddStock4) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    tracker.add_stock({ "AAPL", 150.0, 10 });
    tracker.add_stock({ "MSFT", 150.0, 10 });
    std::vector<Stock> expected{ {"AAPL", 150.0, 20}, {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
}

TEST_F(StockPortfolioTrackerTestAddStock, TestAddStock5) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    tracker.add_stock({ "AAPL", 150.0, 10 });
    tracker.add_stock({ "MSFT", 150.0, 10 });
    tracker.add_stock({ "MSFT", 150.0, 10 });
    std::vector<Stock> expected{ {"AAPL", 150.0, 20}, {"MSFT", 150.0, 20} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
}

class StockPortfolioTrackerTestRemoveStock : public ::testing::Test {
protected:
    StockPortfolioTracker tracker;

    StockPortfolioTrackerTestRemoveStock() : tracker(10000.0) {}
};

TEST_F(StockPortfolioTrackerTestRemoveStock, TestRemoveStock) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    EXPECT_TRUE(tracker.remove_stock({ "AAPL", 150.0, 10 }));
    std::vector<Stock> expected{};
    EXPECT_EQ(tracker.get_portfolio(), expected);
}

TEST_F(StockPortfolioTrackerTestRemoveStock, TestRemoveStock2) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10}, {"MSFT", 150.0, 10} });
    EXPECT_TRUE(tracker.remove_stock({ "AAPL", 150.0, 10 }));
    std::vector<Stock> expected{ {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
}

TEST_F(StockPortfolioTrackerTestRemoveStock, TestRemoveStock3) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10}, {"MSFT", 150.0, 10} });
    EXPECT_FALSE(tracker.remove_stock({ "MSFT", 150.0, 20 }));
    std::vector<Stock> expected{ {"AAPL", 150.0, 10}, {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
}

TEST_F(StockPortfolioTrackerTestRemoveStock, TestRemoveStock4) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    EXPECT_FALSE(tracker.remove_stock({ "MSFT", 150.0, 10 }));
    std::vector<Stock> expected{ {"AAPL", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
}

TEST_F(StockPortfolioTrackerTestRemoveStock, TestRemoveStock5) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10}, {"MSFT", 150.0, 10} });
    EXPECT_TRUE(tracker.remove_stock({ "MSFT", 150.0, 10 }));
    std::vector<Stock> expected{ {"AAPL", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
}

class StockPortfolioTrackerTestBuyStock : public ::testing::Test {
protected:
    StockPortfolioTracker tracker;

    StockPortfolioTrackerTestBuyStock() : tracker(10000.0) {}
};

TEST_F(StockPortfolioTrackerTestBuyStock, TestBuyStock) {
    EXPECT_TRUE(tracker.buy_stock({ "AAPL", 150.0, 10 }));
    std::vector<Stock> expected{ {"AAPL", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
    EXPECT_EQ(tracker.get_cash_balance(), 8500.0);
}

TEST_F(StockPortfolioTrackerTestBuyStock, TestBuyStock2) {
    StockPortfolioTracker local_tracker(1000.0);
    EXPECT_FALSE(local_tracker.buy_stock({ "AAPL", 150.0, 10 }));
    EXPECT_TRUE(local_tracker.get_portfolio().empty());
    EXPECT_EQ(local_tracker.get_cash_balance(), 1000.0);
}

TEST_F(StockPortfolioTrackerTestBuyStock, TestBuyStock3) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    EXPECT_TRUE(tracker.buy_stock({ "AAPL", 150.0, 10 }));
    std::vector<Stock> expected{ {"AAPL", 150.0, 20} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
    EXPECT_EQ(tracker.get_cash_balance(), 8500.0);
}

TEST_F(StockPortfolioTrackerTestBuyStock, TestBuyStock4) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    EXPECT_TRUE(tracker.buy_stock({ "MSFT", 150.0, 10 }));
    EXPECT_TRUE(tracker.buy_stock({ "MSFT", 150.0, 10 }));
    std::vector<Stock> expected{ {"AAPL", 150.0, 10}, {"MSFT", 150.0, 20} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
    EXPECT_EQ(tracker.get_cash_balance(), 7000.0);
}

TEST_F(StockPortfolioTrackerTestBuyStock, TestBuyStock5) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    EXPECT_TRUE(tracker.buy_stock({ "AAPL", 150.0, 10 }));
    EXPECT_TRUE(tracker.buy_stock({ "MSFT", 150.0, 10 }));
    std::vector<Stock> expected{ {"AAPL", 150.0, 20}, {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
    EXPECT_EQ(tracker.get_cash_balance(), 7000.0);
}

class StockPortfolioTrackerTestSellStock : public ::testing::Test {
protected:
    StockPortfolioTracker tracker;

    StockPortfolioTrackerTestSellStock() : tracker(10000.0) {}
};

TEST_F(StockPortfolioTrackerTestSellStock, TestSellStock) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    EXPECT_TRUE(tracker.sell_stock({ "AAPL", 150.0, 9 }));
    std::vector<Stock> expected{ {"AAPL", 150.0, 1} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
    EXPECT_EQ(tracker.get_cash_balance(), 11350.0);
}

TEST_F(StockPortfolioTrackerTestSellStock, TestSellStock2) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    EXPECT_FALSE(tracker.sell_stock({ "AAPL", 150.0, 20 }));
    std::vector<Stock> expected{ {"AAPL", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
    EXPECT_EQ(tracker.get_cash_balance(), 10000.0);
}

TEST_F(StockPortfolioTrackerTestSellStock, TestSellStock3) {
    EXPECT_FALSE(tracker.sell_stock({ "AAPL", 150.0, 10 }));
    EXPECT_TRUE(tracker.get_portfolio().empty());
    EXPECT_EQ(tracker.get_cash_balance(), 10000.0);
}

TEST_F(StockPortfolioTrackerTestSellStock, TestSellStock4) {
    tracker.set_portfolio({ {"AAPL", 150.0, 20} });
    EXPECT_TRUE(tracker.sell_stock({ "AAPL", 150.0, 20 }));
    std::vector<Stock> expected{};
    EXPECT_EQ(tracker.get_portfolio(), expected);
    EXPECT_EQ(tracker.get_cash_balance(), 13000.0);
}

TEST_F(StockPortfolioTrackerTestSellStock, TestSellStock5) {
    tracker.set_portfolio({ {"AAPL", 150.0, 20}, {"MSFT", 150.0, 10} });
    EXPECT_TRUE(tracker.sell_stock({ "AAPL", 150.0, 20 }));
    std::vector<Stock> expected{ {"MSFT", 150.0, 10} };
    EXPECT_EQ(tracker.get_portfolio(), expected);
    EXPECT_EQ(tracker.get_cash_balance(), 13000.0);
}

class StockPortfolioTrackerTestCalculatePortfolioValue : public ::testing::Test {
protected:
    StockPortfolioTracker tracker;

    StockPortfolioTrackerTestCalculatePortfolioValue() : tracker(10000.0) {}
};

TEST_F(StockPortfolioTrackerTestCalculatePortfolioValue, TestCalculatePortfolioValue) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    EXPECT_DOUBLE_EQ(tracker.calculate_portfolio_value(), 11500.0);
}

TEST_F(StockPortfolioTrackerTestCalculatePortfolioValue, TestCalculatePortfolioValue2) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10}, {"MSFT", 150.0, 10} });
    EXPECT_DOUBLE_EQ(tracker.calculate_portfolio_value(), 13000.0);
}

TEST_F(StockPortfolioTrackerTestCalculatePortfolioValue, TestCalculatePortfolioValue3) {
    EXPECT_DOUBLE_EQ(tracker.calculate_portfolio_value(), 10000.0);
}

TEST_F(StockPortfolioTrackerTestCalculatePortfolioValue, TestCalculatePortfolioValue4) {
    tracker.set_portfolio({ {"AAPL", 150.0, 0} });
    EXPECT_DOUBLE_EQ(tracker.calculate_portfolio_value(), 10000.0);
}

TEST_F(StockPortfolioTrackerTestCalculatePortfolioValue, TestCalculatePortfolioValue5) {
    tracker.set_portfolio({ {"AAPL", 0.0, 10} });
    EXPECT_DOUBLE_EQ(tracker.calculate_portfolio_value(), 10000.0);
}

class StockPortfolioTrackerTestGetPortfolioSummary : public ::testing::Test {
protected:
    StockPortfolioTracker tracker;

    StockPortfolioTrackerTestGetPortfolioSummary() : tracker(10000.0) {}
};

TEST_F(StockPortfolioTrackerTestGetPortfolioSummary, TestGetPortfolioSummary) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10} });
    std::vector<StockSummary> expected_summary{ {"AAPL", 1500.0} };
    EXPECT_EQ(tracker.get_portfolio_summary(), std::make_pair(11500.0, expected_summary));
}

TEST_F(StockPortfolioTrackerTestGetPortfolioSummary, TestGetPortfolioSummary2) {
    tracker.set_portfolio({ {"AAPL", 150.0, 10}, {"MSFT", 150.0, 10} });
    std::vector<StockSummary> expected_summary{ {"AAPL", 1500.0}, {"MSFT", 1500.0} };
    EXPECT_EQ(tracker.get_portfolio_summary(), std::make_pair(13000.0, expected_summary));
}

TEST_F(StockPortfolioTrackerTestGetPortfolioSummary, TestGetPortfolioSummary3) {
    EXPECT_EQ(tracker.get_portfolio_summary(), std::make_pair(10000.0, std::vector<StockSummary>{}));
}

TEST_F(StockPortfolioTrackerTestGetPortfolioSummary, TestGetPortfolioSummary4) {
    tracker.set_portfolio({ {"AAPL", 150.0, 0} });
    std::vector<StockSummary> expected_summary{ {"AAPL", 0.0} };
    EXPECT_EQ(tracker.get_portfolio_summary(), std::make_pair(10000.0, expected_summary));
}

TEST_F(StockPortfolioTrackerTestGetPortfolioSummary, TestGetPortfolioSummary5) {
    tracker.set_portfolio({ {"AAPL", 0.0, 10} });
    std::vector<StockSummary> expected_summary{ {"AAPL", 0.0} };
    EXPECT_EQ(tracker.get_portfolio_summary(), std::make_pair(10000.0, expected_summary));
}

class StockPortfolioTrackerTestGetStockValue : public ::testing::Test {
protected:
    StockPortfolioTracker tracker;

    StockPortfolioTrackerTestGetStockValue() : tracker(10000.0) {}
};

TEST_F(StockPortfolioTrackerTestGetStockValue, TestGetStockValue) {
    EXPECT_DOUBLE_EQ(tracker.get_stock_value({ "AAPL", 150.0, 10 }), 1500.0);
}

TEST_F(StockPortfolioTrackerTestGetStockValue, TestGetStockValue2) {
    EXPECT_DOUBLE_EQ(tracker.get_stock_value({ "AAPL", 150.0, 0 }), 0.0);
}

TEST_F(StockPortfolioTrackerTestGetStockValue, TestGetStockValue3) {
    EXPECT_DOUBLE_EQ(tracker.get_stock_value({ "AAPL", 0.0, 10 }), 0.0);
}

TEST_F(StockPortfolioTrackerTestGetStockValue, TestGetStockValue4) {
    EXPECT_DOUBLE_EQ(tracker.get_stock_value({ "AAPL", 0.0, 0 }), 0.0);
}

TEST_F(StockPortfolioTrackerTestGetStockValue, TestGetStockValue5) {
    EXPECT_DOUBLE_EQ(tracker.get_stock_value({ "MSFL", 150.0, 2 }), 300.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}