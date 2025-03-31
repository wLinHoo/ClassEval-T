#include "pch.h"
#include <gtest/gtest.h>

class ShoppingCartTestAddItem : public ::testing::Test {
protected:
    ShoppingCart shoppingcart;
};

TEST_F(ShoppingCartTestAddItem, TestAddItem1) {
    shoppingcart.add_item("apple", 1, 5);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 5 }}}));
}

TEST_F(ShoppingCartTestAddItem, TestAddItem2) {
    shoppingcart.add_item("apple", 1);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 1 }}}));
}

TEST_F(ShoppingCartTestAddItem, TestAddItem3) {
    shoppingcart.add_item("aaa", 1);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"aaa", { 1, 1 }}}));
}

TEST_F(ShoppingCartTestAddItem, TestAddItem4) {
    shoppingcart.add_item("bbb", 1);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"bbb", { 1, 1 }}}));
}

TEST_F(ShoppingCartTestAddItem, TestAddItem5) {
    shoppingcart.add_item("ccc", 1);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"ccc", { 1, 1 }}}));
}

TEST_F(ShoppingCartTestAddItem, TestAddItem6) {
    shoppingcart.add_item("apple", 1, 5);
    shoppingcart.add_item("apple", 1, 5);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 5 }}}));
}

class ShoppingCartTestRemoveItem : public ::testing::Test {
protected:
    ShoppingCart shoppingcart;
};

TEST_F(ShoppingCartTestRemoveItem, TestRemoveItem1) {
    shoppingcart.add_item("apple", 1, 5);
    shoppingcart.remove_item("apple", 3);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 2 }}}));
}

TEST_F(ShoppingCartTestRemoveItem, TestRemoveItem2) {
    shoppingcart.add_item("apple", 1, 5);
    shoppingcart.remove_item("apple");
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 4 }}}));
}

TEST_F(ShoppingCartTestRemoveItem, TestRemoveItem3) {
    shoppingcart.add_item("apple", 1, 5);
    shoppingcart.remove_item("apple", 1);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 4 }}}));
}

TEST_F(ShoppingCartTestRemoveItem, TestRemoveItem4) {
    shoppingcart.add_item("apple", 1, 5);
    shoppingcart.remove_item("apple", 2);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 3 }}}));
}

TEST_F(ShoppingCartTestRemoveItem, TestRemoveItem5) {
    shoppingcart.add_item("apple", 1, 5);
    shoppingcart.remove_item("apple", 4);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 1 }}}));
}

TEST_F(ShoppingCartTestRemoveItem, TestRemoveItem6) {
    shoppingcart.add_item("apple", 1, 5);
    shoppingcart.remove_item("banana", 4);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 5 }}}));
}

class ShoppingCartTestViewItems : public ::testing::Test {
protected:
    ShoppingCart shoppingcart;
};

TEST_F(ShoppingCartTestViewItems, TestViewItems1) {
    shoppingcart.add_item("apple", 1, 5);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 5 }}}));
}

TEST_F(ShoppingCartTestViewItems, TestViewItems2) {
    shoppingcart.add_item("apple", 1, 4);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 4 }}}));
}

TEST_F(ShoppingCartTestViewItems, TestViewItems3) {
    shoppingcart.add_item("apple", 1, 3);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 3 }}}));
}

TEST_F(ShoppingCartTestViewItems, TestViewItems4) {
    shoppingcart.add_item("apple", 1, 2);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 2 }}}));
}

TEST_F(ShoppingCartTestViewItems, TestViewItems5) {
    shoppingcart.add_item("apple", 1, 1);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 1 }}}));
}

class ShoppingCartTestTotalPrice : public ::testing::Test {
protected:
    ShoppingCart shoppingcart;
};

TEST_F(ShoppingCartTestTotalPrice, TestTotalPrice1) {
    shoppingcart.add_item("apple", 1, 5);
    shoppingcart.add_item("banana", 2, 3);
    EXPECT_DOUBLE_EQ(shoppingcart.total_price(), 11.0);
}

TEST_F(ShoppingCartTestTotalPrice, TestTotalPrice2) {
    shoppingcart.add_item("apple", 1, 5);
    shoppingcart.add_item("banana", 2, 3);
    shoppingcart.remove_item("apple", 3);
    EXPECT_DOUBLE_EQ(shoppingcart.total_price(), 8.0);
}

TEST_F(ShoppingCartTestTotalPrice, TestTotalPrice3) {
    shoppingcart.add_item("apple", 1, 1);
    shoppingcart.add_item("banana", 2, 1);
    EXPECT_DOUBLE_EQ(shoppingcart.total_price(), 3.0);
}

TEST_F(ShoppingCartTestTotalPrice, TestTotalPrice4) {
    shoppingcart.add_item("apple", 1, 2);
    shoppingcart.add_item("banana", 2, 1);
    EXPECT_DOUBLE_EQ(shoppingcart.total_price(), 4.0);
}

TEST_F(ShoppingCartTestTotalPrice, TestTotalPrice5) {
    shoppingcart.add_item("apple", 1, 3);
    shoppingcart.add_item("banana", 2, 1);
    EXPECT_DOUBLE_EQ(shoppingcart.total_price(), 5.0);
}

class ShoppingCartTest : public ::testing::Test {
protected:
    ShoppingCart shoppingcart;
};

TEST_F(ShoppingCartTest, TestShoppingCart) {
    shoppingcart.add_item("apple", 1, 5);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 5 }}}));
    shoppingcart.remove_item("apple", 3);
    EXPECT_EQ(shoppingcart.view_items(), (std::unordered_map<std::string, std::pair<double, int>>{{"apple", { 1, 2 }}}));
    shoppingcart.add_item("banana", 2, 3);
    EXPECT_DOUBLE_EQ(shoppingcart.total_price(), 8.0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
