#include <gtest/gtest.h>
#include "pch.h" 
#include <any>
#include <unordered_map>

class DiscountStrategyTestTotal : public ::testing::Test {};

TEST_F(DiscountStrategyTestTotal, test_total_1) {
    std::map<std::string, double> customer = { {"fidelity", 1200.0} };
    std::vector<std::map<std::string, double>> cart = {
        { {"product", 0}, {"quantity", 10.0}, {"price", 20.0} },
        { {"product", 1}, {"quantity", 5.0}, {"price", 10.0} }
    };
    DiscountStrategy order(customer, cart);
    double expected_total = 250.0;
    double actual_total = order.total();
    EXPECT_DOUBLE_EQ(actual_total, expected_total);
}

TEST_F(DiscountStrategyTestTotal, test_total_2) {
    std::map<std::string, double> customer = { {"fidelity", 1200.0} };
    std::vector<std::map<std::string, double>> cart = {
        { {"product", 0}, {"quantity", 10.0}, {"price", 10.0} },
        { {"product", 1}, {"quantity", 5.0}, {"price", 10.0} }
    };
    DiscountStrategy order(customer, cart);
    double expected_total = 150.0;
    double actual_total = order.total();
    EXPECT_DOUBLE_EQ(actual_total, expected_total);
}

TEST_F(DiscountStrategyTestTotal, test_total_3) {
    std::map<std::string, double> customer = { {"fidelity", 1200.0} };
    std::vector<std::map<std::string, double>> cart = {
        { {"product", 0}, {"quantity", 10.0}, {"price", 200.0} },
        { {"product", 1}, {"quantity", 5.0}, {"price", 10.0} }
    };
    DiscountStrategy order(customer, cart);
    double expected_total = 2050.0;
    double actual_total = order.total();
    EXPECT_DOUBLE_EQ(actual_total, expected_total);
}

TEST_F(DiscountStrategyTestTotal, test_total_4) {
    std::map<std::string, double> customer = { {"fidelity", 1200.0} };
    std::vector<std::map<std::string, double>> cart = {
        { {"product", 0}, {"quantity", 1.0}, {"price", 20.0} },
        { {"product", 1}, {"quantity", 5.0}, {"price", 10.0} }
    };
    DiscountStrategy order(customer, cart);
    double expected_total = 70.0;
    double actual_total = order.total();
    EXPECT_DOUBLE_EQ(actual_total, expected_total);
}

TEST_F(DiscountStrategyTestTotal, test_total_5) {
    std::map<std::string, double> customer = { {"fidelity", 1200.0} };
    std::vector<std::map<std::string, double>> cart;
    DiscountStrategy order(customer, cart);
    double expected_total = 0.0;
    double actual_total = order.total();
    EXPECT_DOUBLE_EQ(actual_total, expected_total);
}

class DiscountStrategyTestDue : public ::testing::Test {};

TEST_F(DiscountStrategyTestDue, test_due_1) {
    std::map<std::string, double> customer = { {"fidelity", 1200.0} };
    std::vector<std::map<std::string, double>> cart = {
        { {"product", 0}, {"quantity", 10.0}, {"price", 20.0} },
        { {"product", 1}, {"quantity", 5.0}, {"price", 10.0} }
    };
    DiscountStrategy order(customer, cart);
    double expected_due = 250.0;
    EXPECT_DOUBLE_EQ(order.due(), expected_due);
}

TEST_F(DiscountStrategyTestDue, test_due_2) {
    std::map<std::string, double> customer = { {"fidelity", 1200.0} };
    std::vector<std::map<std::string, double>> cart = {
        { {"product", 0}, {"quantity", 10.0}, {"price", 20.0} },
        { {"product", 1}, {"quantity", 5.0}, {"price", 10.0} }
    };
    DiscountStrategy order(customer, cart, DiscountStrategy::FidelityPromo);
    double expected_due = 237.5;
    EXPECT_DOUBLE_EQ(order.due(), expected_due);
}

TEST_F(DiscountStrategyTestDue, test_due_3) {
    std::map<std::string, double> customer = { {"fidelity", 1200.0} };
    std::vector<std::map<std::string, double>> cart = {
        { {"product", 0}, {"quantity", 20.0}, {"price", 20.0} },
        { {"product", 1}, {"quantity", 5.0}, {"price", 10.0} }
    };
    DiscountStrategy order(customer, cart, DiscountStrategy::BulkItemPromo);
    double expected_due = 410.0;
    EXPECT_DOUBLE_EQ(order.due(), expected_due);
}

TEST_F(DiscountStrategyTestDue, test_due_4) {
    std::map<std::string, double> customer = { {"fidelity", 1200.0} };
    std::vector<std::map<std::string, double>> cart;
    for (int i = 0; i < 15; ++i) {
        cart.push_back({ {"product", static_cast<double>(i)}, {"quantity", 1.0}, {"price", 10.0} });
    }
    DiscountStrategy order(customer, cart, DiscountStrategy::LargeOrderPromo);
    double expected_due = 139.5;
    EXPECT_DOUBLE_EQ(order.due(), expected_due);
}

TEST_F(DiscountStrategyTestDue, test_due_5) {
    std::map<std::string, double> customer = { {"fidelity", 900.0} };
    std::vector<std::map<std::string, double>> cart = {
        { {"product", 0}, {"quantity", 10.0}, {"price", 20.0} },
        { {"product", 1}, {"quantity", 5.0}, {"price", 10.0} }
    };
    DiscountStrategy order(customer, cart, DiscountStrategy::FidelityPromo);
    double expected_due = 250.0;
    EXPECT_DOUBLE_EQ(order.due(), expected_due);
}

class DiscountStrategyTestFidelityPromo : public ::testing::Test {};

TEST(DiscountStrategyTestFidelityPromo, TestFidelityPromo1) {
    std::map<std::string, double> customer = { {"fidelity", 1000.0} };
    std::vector<std::map<std::string, double>> cart = { 
        { {"product", 1.0}, {"quantity", 10.0}, {"price", 20.0} },
        { {"product", 2.0 }, { "quantity", 5.0 }, { "price", 10.0 } }
    };
    DiscountStrategy order(customer, cart, DiscountStrategy::FidelityPromo);
    EXPECT_DOUBLE_EQ(order.promotion(order), 12.5);
}

TEST(DiscountStrategyTestFidelityPromo, TestFidelityPromo2) {
    std::map<std::string, double> customer = { {"fidelity", 800.0} };
    std::vector<std::map<std::string, double>> cart = {
        {{"product", 1.0}, {"quantity", 10.0}, {"price", 20.0} },
    { {"product", 2.0}, {"quantity", 5.0}, {"price", 10.0} } };
    DiscountStrategy order(customer, cart, DiscountStrategy::FidelityPromo);
    EXPECT_DOUBLE_EQ(order.promotion(order), 0.0);
}

TEST(DiscountStrategyTestFidelityPromo, TestFidelityPromo3) {
    std::map<std::string, double> customer = { {"fidelity", 0.0} };
    std::vector<std::map<std::string, double>> cart = { {{"product", 1.0}, {"quantity", 10.0}, {"price", 20.0} },
    { {"product", 2.0}, {"quantity", 5.0}, {"price", 10.0} } };
    DiscountStrategy order(customer, cart, DiscountStrategy::FidelityPromo);
    EXPECT_DOUBLE_EQ(order.promotion(order), 0.0);
}

TEST(DiscountStrategyTestFidelityPromo, TestFidelityPromo4) {
    std::map<std::string, double> customer = { {"fidelity", 10000.0} };
    std::vector<std::map<std::string, double>> cart = { {{"product", 1.0}, {"quantity", 10.0}, {"price", 20.0} },
    { {"product", 2.0}, {"quantity", 5.0}, {"price", 10.0} } };
    DiscountStrategy order(customer, cart, DiscountStrategy::FidelityPromo);
    EXPECT_DOUBLE_EQ(order.promotion(order), 12.5);
}

TEST(DiscountStrategyTestFidelityPromo, TestFidelityPromo5) {
    std::map<std::string, double> customer = { {"fidelity", 1800.0} };
    std::vector<std::map<std::string, double>> cart = {{ {"product", 1.0}, {"quantity", 10.0}, {"price", 20.0} },
    { {"product", 2.0}, {"quantity", 5.0}, {"price", 10.0} } };
    DiscountStrategy order(customer, cart, DiscountStrategy::FidelityPromo);
    EXPECT_DOUBLE_EQ(order.promotion(order), 12.5);
}
class DiscountStrategyTestBulkItemPromo : public ::testing::Test {};

TEST(DiscountStrategyTestBulkItemPromo, test_bulk_item_promo_1) {
    std::map<std::string, double> customer = { {"fidelity", 1200} };
    std::vector<std::map<std::string, double>> cart = {
        {{"quantity", 20}, {"price", 10.0}},
        {{"quantity", 5}, {"price", 5.0}}
    };
    DiscountStrategy order(customer, cart, DiscountStrategy::BulkItemPromo);
    double expected_discount = 20.0;
    double actual_discount = order.promotion(order);
    EXPECT_EQ(actual_discount, expected_discount);
}

TEST(DiscountStrategyTestBulkItemPromo, test_bulk_item_promo_2) {
    std::map<std::string, double> customer = { {"fidelity", 1200} };
    std::vector<std::map<std::string, double>> cart = {
        {{"quantity", 10}, {"price", 10.0}},
        {{"quantity", 5}, {"price", 5.0}}
    };
    DiscountStrategy order(customer, cart, DiscountStrategy::BulkItemPromo);
    double expected_discount = 0.0;
    double actual_discount = order.promotion(order);
    EXPECT_EQ(actual_discount, expected_discount);
}

TEST(DiscountStrategyTestBulkItemPromo, test_bulk_item_promo_3) {
    std::map<std::string, double> customer = { {"fidelity", 1200} };
    std::vector<std::map<std::string, double>> cart = {
        {{"quantity", 100}, {"price", 10.0}},
        {{"quantity", 5}, {"price", 5.0}}
    };
    DiscountStrategy order(customer, cart, DiscountStrategy::BulkItemPromo);
    double expected_discount = 100.0;
    double actual_discount = order.promotion(order);
    EXPECT_EQ(actual_discount, expected_discount);
}

TEST(DiscountStrategyTestBulkItemPromo, test_bulk_item_promo_4) {
    std::map<std::string, double> customer = { {"fidelity", 1200} };
    std::vector<std::map<std::string, double>> cart = {
        {{"quantity", 1}, {"price", 10.0}},
        {{"quantity", 5}, {"price", 5.0}}
    };
    DiscountStrategy order(customer, cart, DiscountStrategy::BulkItemPromo);
    double expected_discount = 0.0;
    double actual_discount = order.promotion(order);
    EXPECT_EQ(actual_discount, expected_discount);
}

TEST(DiscountStrategyTestBulkItemPromo, test_bulk_item_promo_5) {
    std::map<std::string, double> customer = { {"fidelity", 1200} };
    std::vector<std::map<std::string, double>> cart = {
        {{"quantity", 30}, {"price", 10.0}},
        {{"quantity", 5}, {"price", 5.0}}
    };
    DiscountStrategy order(customer, cart, DiscountStrategy::BulkItemPromo);
    double expected_discount = 30.0;
    double actual_discount = order.promotion(order);
    EXPECT_EQ(actual_discount, expected_discount);
}

class DiscountStrategyTestLargeOrderPromo : public ::testing::Test {};

TEST(DiscountStrategyTestLargeOrderPromo, test_large_order_promo_1) {
    std::map<std::string, double> customer = { {"fidelity", 1200} };
    std::vector<std::map<std::string, double>> cart;
    for (int i = 0; i < 10; ++i) {
        cart.push_back({ {"quantity", 1}, {"price", 10.0} });
    }
    DiscountStrategy order(customer, cart, DiscountStrategy::LargeOrderPromo);
    double expected_discount = 7.0;
    double actual_discount = order.promotion(order);
    EXPECT_NEAR(actual_discount, expected_discount, 1e-9);
}

TEST(DiscountStrategyTestLargeOrderPromo, test_large_order_promo_2) {
    std::map<std::string, double> customer = { {"fidelity", 1200} };
    std::vector<std::map<std::string, double>> cart;
    for (int i = 0; i < 5; ++i) {
        cart.push_back({ {"quantity", 1}, {"price", 10.0} });
    }
    DiscountStrategy order(customer, cart, DiscountStrategy::LargeOrderPromo);
    double expected_discount = 0.0;
    double actual_discount = order.promotion(order);
    EXPECT_EQ(actual_discount, expected_discount);
}

TEST(DiscountStrategyTestLargeOrderPromo, test_large_order_promo_3) {
    std::map<std::string, double> customer = { {"fidelity", 1200} };
    std::vector<std::map<std::string, double>> cart;
    for (int i = 0; i < 100; ++i) {
        cart.push_back({ {"quantity", 1}, {"price", 10.0} });
    }
    DiscountStrategy order(customer, cart, DiscountStrategy::LargeOrderPromo);
    double expected_discount = 70.0;
    double actual_discount = order.promotion(order);
    EXPECT_NEAR(actual_discount, expected_discount, 1e-9);
}

TEST(DiscountStrategyTestLargeOrderPromo, test_large_order_promo_4) {
    std::map<std::string, double> customer = { {"fidelity", 1200} };
    std::vector<std::map<std::string, double>> cart;
    for (int i = 0; i < 1000; ++i) {
        cart.push_back({ {"quantity", 1}, {"price", 10.0} });
    }
    DiscountStrategy order(customer, cart, DiscountStrategy::LargeOrderPromo);
    double expected_discount = 700.0;
    double actual_discount = order.promotion(order);
    EXPECT_NEAR(actual_discount, expected_discount, 1e-9);
}

TEST(DiscountStrategyTestLargeOrderPromo, test_large_order_promo_5) {
    std::map<std::string, double> customer = { {"fidelity", 1200} };
    std::vector<std::map<std::string, double>> cart = {
        {{"quantity", 1}, {"price", 10.0}}
    };
    DiscountStrategy order(customer, cart, DiscountStrategy::LargeOrderPromo);
    double expected_discount = 0.0;
    double actual_discount = order.promotion(order);
    EXPECT_NEAR(actual_discount, expected_discount, 1e-9);
}

class DiscountStrategyTest : public ::testing::Test {};

TEST(DiscountStrategyTest, test_DiscountStrategy) {
    std::map<std::string, double> customer = { {"fidelity", 1200} };
    std::vector<std::map<std::string, double>> cart = {
        {{"quantity", 10}, {"price", 20.0}},
        {{"quantity", 5}, {"price", 10.0}}
    };
    DiscountStrategy order(customer, cart);
    double expected_total = 250.0;
    double actual_total = order.total();
    EXPECT_EQ(actual_total, expected_total);

    expected_total = 250.0;
    double actual_due = order.due();
    EXPECT_EQ(actual_due, expected_total);

    customer = { {"fidelity", 1000} };
    cart = {
        {{"quantity", 10}, {"price", 20.0}},
        {{"quantity", 5}, {"price", 10.0}}
    };
    DiscountStrategy order_with_promo(customer, cart, DiscountStrategy::FidelityPromo);
    double expected_discount = 12.5;
    double actual_discount = order_with_promo.promotion(order_with_promo);
    EXPECT_EQ(actual_discount, expected_discount);

    customer = { {"fidelity", 1200} };
    cart = {
        {{"quantity", 20}, {"price", 10.0}},
        {{"quantity", 5}, {"price", 5.0}}
    };
    DiscountStrategy order_with_bulk_promo(customer, cart, DiscountStrategy::BulkItemPromo);
    expected_discount = 20.0;
    actual_discount = order_with_bulk_promo.promotion(order_with_bulk_promo);
    EXPECT_EQ(actual_discount, expected_discount);

    cart.clear();
    for (int i = 0; i < 10; ++i) {
        cart.push_back({ {"quantity", 1}, {"price", 10.0} });
    }
    DiscountStrategy order_with_large_order_promo(customer, cart, DiscountStrategy::LargeOrderPromo);
    expected_discount = 7.0;
    actual_discount = order_with_large_order_promo.promotion(order_with_large_order_promo);
    EXPECT_NEAR(actual_discount, expected_discount, 1e-9);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}