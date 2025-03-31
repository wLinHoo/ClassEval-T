#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include "pch.h"

class VendingMachineTestMain : public ::testing::Test {
protected:
    VendingMachine vendingMachine;
};

TEST_F(VendingMachineTestMain, test_main) {
    EXPECT_EQ(vendingMachine.display_items(), "false");
    vendingMachine.add_item("Coke", 1.25, 10);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }}
    }));
    EXPECT_EQ(vendingMachine.insert_coin(1.25), 1.25);
    EXPECT_EQ(vendingMachine.purchase_item("Coke"), 0.0);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 9} }}
    }));
    EXPECT_EQ(vendingMachine.purchase_item("Pizza"), false);
    EXPECT_EQ(vendingMachine.restock_item("Coke", 10), true);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 19} }}
    }));
    EXPECT_EQ(vendingMachine.restock_item("Pizza", 10), false);
    EXPECT_EQ(vendingMachine.display_items(), "Coke - $1.25 [19]");
}

TEST_F(VendingMachineTestMain, test_main_2) {
    EXPECT_EQ(vendingMachine.purchase_item("Coke"), false);
    vendingMachine.add_item("Coke", 1.25, 10);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }}
    }));
    EXPECT_EQ(vendingMachine.restock_item("Pizza", 10), false);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }}
    }));
    EXPECT_EQ(vendingMachine.insert_coin(1.25), 1.25);
    EXPECT_EQ(vendingMachine.purchase_item("Coke"), 0.0);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 9} }}
    }));
    EXPECT_EQ(vendingMachine.display_items(), "Coke - $1.25 [9]");
}

class VendingMachineTestAddItem : public ::testing::Test {
protected:
    VendingMachine vendingMachine;
};

TEST_F(VendingMachineTestAddItem, test_add_item) {
    vendingMachine.add_item("Coke", 1.25, 10);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }}
    }));
}

TEST_F(VendingMachineTestAddItem, test_add_item_2) {
    vendingMachine.add_item("Coke", 1.25, 10);
    vendingMachine.add_item("Coke", 1.25, 10);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 20} }}
    }));
}

TEST_F(VendingMachineTestAddItem, test_add_item_3) {
    vendingMachine.add_item("Coke", 1.25, 10);
    vendingMachine.add_item("Pizza", 1.25, 10);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }},
        { "Pizza", {{"price", 1.25}, {"quantity", 10}} }
    }));
}

TEST_F(VendingMachineTestAddItem, test_add_item_4) {
    vendingMachine.add_item("Coke", 1.25, 10);
    vendingMachine.add_item("Pizza", 1.25, 10);
    vendingMachine.add_item("Pizza", 1.25, 10);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }},
        { "Pizza", {{"price", 1.25}, {"quantity", 20}} }
    }));
}

TEST_F(VendingMachineTestAddItem, test_add_item_5) {
    vendingMachine.add_item("Coke", 1.25, 10);
    vendingMachine.add_item("Pizza", 1.25, 10);
    vendingMachine.add_item("Pizza", 1.25, 10);
    vendingMachine.add_item("Coke", 1.25, 10);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 20} }},
        { "Pizza", {{"price", 1.25}, {"quantity", 20}} }
    }));
}

class VendingMachineTestInsertCoin : public ::testing::Test {
protected:
    VendingMachine vendingMachine;
};

TEST_F(VendingMachineTestInsertCoin, test_insert_coin) {
    EXPECT_EQ(vendingMachine.insert_coin(1.25), 1.25);
}

TEST_F(VendingMachineTestInsertCoin, test_insert_coin_2) {
    EXPECT_EQ(vendingMachine.insert_coin(2.5), 2.5);
}

TEST_F(VendingMachineTestInsertCoin, test_insert_coin_3) {
    vendingMachine.insert_coin(1.25);
    vendingMachine.insert_coin(1.25);
    EXPECT_EQ(vendingMachine.insert_coin(0), 2.50); 
}

TEST_F(VendingMachineTestInsertCoin, test_insert_coin_4) {
    vendingMachine.insert_coin(1.25); 
    vendingMachine.insert_coin(1.25);
    vendingMachine.insert_coin(1.25);
    vendingMachine.insert_coin(1.25);
    EXPECT_EQ(vendingMachine.insert_coin(0), 5.0); 
}

TEST_F(VendingMachineTestInsertCoin, test_insert_coin_5) {
    vendingMachine.insert_coin(1.25); 
    vendingMachine.insert_coin(1.25);
    vendingMachine.insert_coin(1.25);
    vendingMachine.insert_coin(1.25);
    vendingMachine.insert_coin(1.25);
    EXPECT_EQ(vendingMachine.insert_coin(0), 6.25); 
}

class VendingMachineTestPurchaseItem : public ::testing::Test {
protected:
    VendingMachine vendingMachine;
};

TEST_F(VendingMachineTestPurchaseItem, test_purchase_item) {
    vendingMachine.set_inventory({ {"Coke", {{"price", 1.25}, {"quantity", 10} }} });
    vendingMachine.set_balance(1.25);
    EXPECT_EQ(vendingMachine.purchase_item("Coke"), 0.0);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 9} }}
    }));
}

TEST_F(VendingMachineTestPurchaseItem, test_purchase_item_2) {
    vendingMachine.set_inventory({ {"Coke", {{"price", 1.25}, {"quantity", 10} }} });
    vendingMachine.set_balance(1.25);
    EXPECT_EQ(vendingMachine.purchase_item("Pizza"), false);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }}
    }));
}

TEST_F(VendingMachineTestPurchaseItem, test_purchase_item_3) {
    vendingMachine.set_inventory({ {"Coke", {{"price", 1.25}, {"quantity", 10} }} });
    vendingMachine.set_balance(0);
    EXPECT_EQ(vendingMachine.purchase_item("Coke"), false);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }}
    }));
}

TEST_F(VendingMachineTestPurchaseItem, test_purchase_item_4) {
    vendingMachine.set_inventory({ {"Coke", {{"price", 1.25}, {"quantity", 0} }} });
    vendingMachine.set_balance(1.25);
    EXPECT_EQ(vendingMachine.purchase_item("Coke"), false);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 0} }}
    }));
}

TEST_F(VendingMachineTestPurchaseItem, test_purchase_item_5) {
    vendingMachine.set_inventory({
        {"Coke", {{"price", 1.25}, {"quantity", 10} }},
        {"Pizza", {{"price", 1.25}, {"quantity", 10}}}
        });
    vendingMachine.set_balance(1.25);
    EXPECT_EQ(vendingMachine.purchase_item("Pizza"), 0.0);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }},
        { "Pizza", {{"price", 1.25}, {"quantity", 9}} }
    }));
}

class VendingMachineTestRestockItem : public ::testing::Test {
protected:
    VendingMachine vendingMachine;
};

TEST_F(VendingMachineTestRestockItem, test_restock_item) {
    vendingMachine.set_inventory({ {"Coke", {{"price", 1.25}, {"quantity", 10} }} });
    EXPECT_EQ(vendingMachine.restock_item("Coke", 10), true);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 20} }}
    }));
}

TEST_F(VendingMachineTestRestockItem, test_restock_item_2) {
    vendingMachine.set_inventory({ {"Coke", {{"price", 1.25}, {"quantity", 10} }} });
    EXPECT_EQ(vendingMachine.restock_item("Pizza", 10), false);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }}
    }));
}

TEST_F(VendingMachineTestRestockItem, test_restock_item_3) {
    vendingMachine.set_inventory({ {"Coke", {{"price", 1.25}, {"quantity", 0} }} });
    EXPECT_EQ(vendingMachine.restock_item("Coke", 10), true);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }}
    }));
}

TEST_F(VendingMachineTestRestockItem, test_restock_item_4) {
    vendingMachine.set_inventory({
        {"Coke", {{"price", 1.25}, {"quantity", 10} }},
        {"Pizza", {{"price", 1.25}, {"quantity", 10} }}
        });
    EXPECT_EQ(vendingMachine.restock_item("Pizza", 10), true);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }},
        { "Pizza", {{"price", 1.25}, {"quantity", 20}} }
    }));
}

TEST_F(VendingMachineTestRestockItem, test_restock_item_5) {
    vendingMachine.set_inventory({
        {"Coke", {{"price", 1.25}, {"quantity", 10} }},
        {"Pizza", {{"price", 1.25}, {"quantity", 10} }}
        });
    EXPECT_EQ(vendingMachine.restock_item("Pizza", 0), true);
    EXPECT_EQ(vendingMachine.inventory(), (std::unordered_map<std::string, std::unordered_map<std::string, double>>{
        {"Coke", { {"price", 1.25}, {"quantity", 10} }},
        { "Pizza", {{"price", 1.25}, {"quantity", 10}} }
    }));
}

class VendingMachineTestDisplayItems : public ::testing::Test {
protected:
    VendingMachine vendingMachine;
};

TEST_F(VendingMachineTestDisplayItems, test_display_items) {
    vendingMachine.set_inventory({ {"Coke", {{"price", 1.25}, {"quantity", 10} }} });
    EXPECT_EQ(vendingMachine.display_items(), "Coke - $1.25 [10]");
}

TEST_F(VendingMachineTestDisplayItems, test_display_items_2) {
    EXPECT_EQ(vendingMachine.display_items(), "false");
}

TEST_F(VendingMachineTestDisplayItems, test_display_items_3) {
    vendingMachine.set_inventory({
        {"Coke", {{"price", 1.25}, {"quantity", 10} }},
        {"Pizza", {{"price", 1.25}, {"quantity", 10} }}
        });
    EXPECT_EQ(vendingMachine.display_items(), "Coke - $1.25 [10]\nPizza - $1.25 [10]");
}

TEST_F(VendingMachineTestDisplayItems, test_display_items_4) {
    vendingMachine.set_inventory({ {"Coke", {{"price", 1.25}, {"quantity", 0} }} });
    EXPECT_EQ(vendingMachine.display_items(), "Coke - $1.25 [0]");
}

TEST_F(VendingMachineTestDisplayItems, test_display_items_5) {
    vendingMachine.set_inventory({
        {"Coke", {{"price", 1.25}, {"quantity", 0} }},
        {"Pizza", {{"price", 1.25}, {"quantity", 10} }}
        });
    EXPECT_EQ(vendingMachine.display_items(), "Coke - $1.25 [0]\nPizza - $1.25 [10]");
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}