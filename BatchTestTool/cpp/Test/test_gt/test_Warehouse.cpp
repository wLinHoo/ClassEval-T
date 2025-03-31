#include <gtest/gtest.h>
#include "pch.h"

class WarehouseTestMain : public ::testing::Test {
protected:
    Warehouse warehouse;

    void SetUp() override {
    }
};

TEST_F(WarehouseTestMain, test_main) {
    warehouse.add_product(1, "product 1", 10);

    std::map<int, std::map<std::string, std::string>> expected_inventory = {
        {1, {{"name", "product 1"}, {"quantity", "10"}}}
    };
    EXPECT_EQ(expected_inventory, warehouse.inventory());

    warehouse.update_product_quantity(1, -5);
    expected_inventory[1]["quantity"] = "5";
    EXPECT_EQ(expected_inventory, warehouse.inventory());

    EXPECT_EQ(5, warehouse.get_product_quantity(1));

    EXPECT_TRUE(warehouse.create_order(1, 1, 3));
    std::map<int, std::map<std::string, std::string>> expected_orders = {
        {1, {{"product_id", "1"}, {"quantity", "3"}, {"status", "Shipped"}}}
    };
    EXPECT_EQ(expected_orders, warehouse.orders());

    EXPECT_TRUE(warehouse.change_order_status(1, "Delivered"));
    expected_orders[1]["status"] = "Delivered";
    EXPECT_EQ(expected_orders, warehouse.orders());

    EXPECT_EQ("Delivered", warehouse.track_order(1));
}

class WarehouseTestAddProduct : public ::testing::Test {
protected:
    Warehouse warehouse;
};

TEST_F(WarehouseTestAddProduct, test_add_product_1) {
    warehouse.add_product(1, "product 1", 10);
    std::map<int, std::map<std::string, std::string>> expected_inventory = {
        {1, {{"name", "product 1"}, {"quantity", "10"}}}
    };
    EXPECT_EQ(expected_inventory, warehouse.inventory());
}

TEST_F(WarehouseTestAddProduct, test_add_product_2) {
    warehouse.add_product(1, "product 1", 10);
    warehouse.add_product(2, "product 2", 5);
    std::map<int, std::map<std::string, std::string>> expected_inventory = {
        {1, {{"name", "product 1"}, {"quantity", "10"}}},
        {2, {{"name", "product 2"}, {"quantity", "5"}}}
    };
    EXPECT_EQ(expected_inventory, warehouse.inventory());
}

TEST_F(WarehouseTestAddProduct, test_add_product_3) {
    warehouse.add_product(1, "product 3", 10);
    std::map<int, std::map<std::string, std::string>> expected_inventory = {
        {1, {{"name", "product 3"}, {"quantity", "10"}}}
    };
    EXPECT_EQ(expected_inventory, warehouse.inventory());
}

TEST_F(WarehouseTestAddProduct, test_add_product_4) {
    warehouse.add_product(1, "product 4", 10);
    std::map<int, std::map<std::string, std::string>> expected_inventory = {
        {1, {{"name", "product 4"}, {"quantity", "10"}}}
    };
    EXPECT_EQ(expected_inventory, warehouse.inventory());
}

TEST_F(WarehouseTestAddProduct, test_add_product_5) {
    warehouse.add_product(1, "product 5", 10);
    std::map<int, std::map<std::string, std::string>> expected_inventory = {
        {1, {{"name", "product 5"}, {"quantity", "10"}}}
    };
    EXPECT_EQ(expected_inventory, warehouse.inventory());
}

TEST_F(WarehouseTestAddProduct, test_add_product_6) {
    warehouse.add_product(1, "product 5", 10);
    warehouse.add_product(1, "product 5", 10);
    std::map<int, std::map<std::string, std::string>> expected_inventory = {
        {1, {{"name", "product 5"}, {"quantity", "20"}}}
    };
    EXPECT_EQ(expected_inventory, warehouse.inventory());
}

class WarehouseTestUpdateProductQuantity : public ::testing::Test {
protected:
    Warehouse warehouse;
};

TEST_F(WarehouseTestUpdateProductQuantity, test_update_product_quantity_1) {
    warehouse.add_product(1, "product 1", 10);
    warehouse.update_product_quantity(1, 5);
    std::map<int, std::map<std::string, std::string>> expected_inventory = {
        {1, {{"name", "product 1"}, {"quantity", "15"}}}
    };
    EXPECT_EQ(expected_inventory, warehouse.inventory());
}

TEST_F(WarehouseTestUpdateProductQuantity, test_update_product_quantity_2) {
    warehouse.add_product(1, "product 1", 10);
    warehouse.update_product_quantity(1, -5);
    std::map<int, std::map<std::string, std::string>> expected_inventory = {
        {1, {{"name", "product 1"}, {"quantity", "5"}}}
    };
    EXPECT_EQ(expected_inventory, warehouse.inventory());
}

TEST_F(WarehouseTestUpdateProductQuantity, test_update_product_quantity_3) {
    warehouse.update_product_quantity(1, -5);
    std::map<int, std::map<std::string, std::string>> expected_inventory = {};
    EXPECT_EQ(expected_inventory, warehouse.inventory());
}

TEST_F(WarehouseTestUpdateProductQuantity, test_update_product_quantity_4) {
    warehouse.add_product(1, "product 1", 10);
    warehouse.update_product_quantity(1, 1);
    std::map<int, std::map<std::string, std::string>> expected_inventory = {
        {1, {{"name", "product 1"}, {"quantity", "11"}}}
    };
    EXPECT_EQ(expected_inventory, warehouse.inventory());
}

TEST_F(WarehouseTestUpdateProductQuantity, test_update_product_quantity_5) {
    warehouse.add_product(1, "product 1", 10);
    warehouse.update_product_quantity(1, -9);
    std::map<int, std::map<std::string, std::string>> expected_inventory = {
        {1, {{"name", "product 1"}, {"quantity", "1"}}}
    };
    EXPECT_EQ(expected_inventory, warehouse.inventory());
}

class WarehouseTestGetProductQuantity : public ::testing::Test {
protected:
    Warehouse warehouse;
};

TEST_F(WarehouseTestGetProductQuantity, test_get_product_quantity_1) {
    warehouse.add_product(1, "product 1", 10);
    EXPECT_EQ(10, warehouse.get_product_quantity(1));
}

TEST_F(WarehouseTestGetProductQuantity, test_get_product_quantity_2) {
    EXPECT_EQ(false, warehouse.get_product_quantity(1));
}

TEST_F(WarehouseTestGetProductQuantity, test_get_product_quantity_3) {
    warehouse.add_product(1, "product 1", 5);
    EXPECT_EQ(5, warehouse.get_product_quantity(1));
}

TEST_F(WarehouseTestGetProductQuantity, test_get_product_quantity_4) {
    warehouse.add_product(1, "product 1", 100);
    EXPECT_EQ(100, warehouse.get_product_quantity(1));
}

TEST_F(WarehouseTestGetProductQuantity, test_get_product_quantity_5) {
    warehouse.add_product(5, "product 1", 10);
    EXPECT_EQ(10, warehouse.get_product_quantity(5));
}

class WarehouseTestCreateOrder : public ::testing::Test {
protected:
    Warehouse warehouse;
};

TEST_F(WarehouseTestCreateOrder, test_create_order_1) {
    warehouse.add_product(1, "product 1", 10);
    EXPECT_TRUE(warehouse.create_order(1, 1, 5));
    std::map<int, std::map<std::string, std::string>> expected_orders = {
        {1, {{"product_id", "1"}, {"quantity", "5"}, {"status", "Shipped"}}}
    };
    EXPECT_EQ(expected_orders, warehouse.orders());
}

TEST_F(WarehouseTestCreateOrder, test_create_order_2) {
    warehouse.add_product(1, "product 1", 10);
    EXPECT_FALSE(warehouse.create_order(1, 1, 15));
}

TEST_F(WarehouseTestCreateOrder, test_create_order_3) {
    warehouse.add_product(1, "product 1", 1);
    EXPECT_TRUE(warehouse.create_order(1, 1, 1));
    std::map<int, std::map<std::string, std::string>> expected_orders = {
        {1, {{"product_id", "1"}, {"quantity", "1"}, {"status", "Shipped"}}}
    };
    EXPECT_EQ(expected_orders, warehouse.orders());
}

TEST_F(WarehouseTestCreateOrder, test_create_order_4) {
    warehouse.add_product(1, "product 4", 5);
    EXPECT_TRUE(warehouse.create_order(1, 1, 5));
    std::map<int, std::map<std::string, std::string>> expected_orders = {
        {1, {{"product_id", "1"}, {"quantity", "5"}, {"status", "Shipped"}}}
    };
    EXPECT_EQ(expected_orders, warehouse.orders());
}

TEST_F(WarehouseTestCreateOrder, test_create_order_5) {
    warehouse.add_product(1, "product 5", 100);
    EXPECT_TRUE(warehouse.create_order(1, 1, 50));
    std::map<int, std::map<std::string, std::string>> expected_orders = {
        {1, {{"product_id", "1"}, {"quantity", "50"}, {"status", "Shipped"}}}
    };
    EXPECT_EQ(expected_orders, warehouse.orders());
}

class WarehouseTestChangeOrderStatus : public ::testing::Test {
protected:
    Warehouse warehouse;
};

TEST_F(WarehouseTestChangeOrderStatus, test_change_order_status_1) {
    warehouse.add_product(1, "product 1", 10);
    warehouse.create_order(1, 1, 5);
    EXPECT_TRUE(warehouse.change_order_status(1, "Delivered"));
    std::map<int, std::map<std::string, std::string>> expected_orders = {
        {1, {{"product_id", "1"}, {"quantity", "5"}, {"status", "Delivered"}}}
    };
    EXPECT_EQ(expected_orders, warehouse.orders());
}

TEST_F(WarehouseTestChangeOrderStatus, test_change_order_status_2) {
    EXPECT_FALSE(warehouse.change_order_status(1, "Delivered"));
}

TEST_F(WarehouseTestChangeOrderStatus, test_change_order_status_3) {
    warehouse.add_product(1, "product 3", 5);
    warehouse.create_order(1, 1, 5);
    EXPECT_TRUE(warehouse.change_order_status(1, "Delivered"));
    std::map<int, std::map<std::string, std::string>> expected_orders = {
        {1, {{"product_id", "1"}, {"quantity", "5"}, {"status", "Delivered"}}}
    };
    EXPECT_EQ(expected_orders, warehouse.orders());
}

TEST_F(WarehouseTestChangeOrderStatus, test_change_order_status_4) {
    warehouse.add_product(1, "product 4", 100);
    warehouse.create_order(1, 1, 50);
    EXPECT_TRUE(warehouse.change_order_status(1, "Delivered"));
    std::map<int, std::map<std::string, std::string>> expected_orders = {
        {1, {{"product_id", "1"}, {"quantity", "50"}, {"status", "Delivered"}}}
    };
    EXPECT_EQ(expected_orders, warehouse.orders());
}

TEST_F(WarehouseTestChangeOrderStatus, test_change_order_status_5) {
    EXPECT_FALSE(warehouse.change_order_status(2, "Delivered"));
}

class WarehouseTestTrackOrder : public ::testing::Test {
protected:
    Warehouse warehouse;
};

TEST_F(WarehouseTestTrackOrder, test_track_order_1) {
    warehouse.add_product(1, "product 1", 10);
    warehouse.create_order(1, 1, 5);
    EXPECT_EQ("Shipped", warehouse.track_order(1));
}

TEST_F(WarehouseTestTrackOrder, test_track_order_2) {
    EXPECT_EQ("", warehouse.track_order(1));
}

TEST_F(WarehouseTestTrackOrder, test_track_order_3) {
    warehouse.add_product(1, "product 3", 10);
    warehouse.create_order(1, 1, 1);
    EXPECT_EQ("Shipped", warehouse.track_order(1));
}

TEST_F(WarehouseTestTrackOrder, test_track_order_4) {
    warehouse.add_product(1, "product 4", 100);
    warehouse.create_order(1, 1, 50);
    EXPECT_EQ("Shipped", warehouse.track_order(1));
}

TEST_F(WarehouseTestTrackOrder, test_track_order_5) {
    warehouse.add_product(1, "product 5", 100);
    warehouse.create_order(1, 1, 10);
    EXPECT_EQ("Shipped", warehouse.track_order(1));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}