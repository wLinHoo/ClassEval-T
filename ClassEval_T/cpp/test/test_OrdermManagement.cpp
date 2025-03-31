#include <gtest/gtest.h>
#include "pch.h"

bool operator==(const Dish& lhs, const Dish& rhs) {
    return lhs.dish == rhs.dish && lhs.price == rhs.price && lhs.count == rhs.count;
}

bool operator==(const std::vector<Dish>& lhs, const std::vector<Dish>& rhs) {
    if (lhs.size() != rhs.size()) return false;
    for (size_t i = 0; i < lhs.size(); ++i) {
        if (!(lhs[i] == rhs[i])) return false;
    }
    return true;
}

class OrderTestAddDish : public ::testing::Test {
protected:
    void SetUp() override {
        order = Order();

        order.menu.push_back({ "dish1", 10, 5 });
        order.menu.push_back({ "dish2", 15, 3 });
        order.menu.push_back({ "dish3", 20, 7 });
        order.sales = { {"dish1", 0.9}, {"dish2", 1}, {"dish3", 0.8} };
    }

    Order order;
};


TEST_F(OrderTestAddDish, test_add_dish_1) {
    bool result = order.add_dish({ "dish3", 15, 4 });
    EXPECT_TRUE(result);

    
    for (const auto& menu_dish : order.menu) {
        if (menu_dish.dish == "dish1") {
            EXPECT_EQ(menu_dish.count, 5);
        }
        if (menu_dish.dish == "dish2") {
            EXPECT_EQ(menu_dish.count, 3);
        }
        if (menu_dish.dish == "dish3") {
            EXPECT_EQ(menu_dish.count, 3);
        }
    }
    EXPECT_EQ(order.selected_dishes, (std::vector<Dish>{{"dish3", 15, 4}}));
}


TEST_F(OrderTestAddDish, test_add_dish_2) {
    bool result = order.add_dish({ "dish3", 15, 8 });
    EXPECT_FALSE(result);

    for (const auto& menu_dish : order.menu) {
        if (menu_dish.dish == "dish1") {
            EXPECT_EQ(menu_dish.count, 5);
        }
        if (menu_dish.dish == "dish2") {
            EXPECT_EQ(menu_dish.count, 3);
        }
        if (menu_dish.dish == "dish3") {
            EXPECT_EQ(menu_dish.count, 7);
        }
    }
    EXPECT_EQ(order.selected_dishes, std::vector<Dish>{});
}

TEST_F(OrderTestAddDish, test_add_dish_3) {
    bool result = order.add_dish({ "dish3", 15, 7 });
    EXPECT_TRUE(result);

    
    for (const auto& menu_dish : order.menu) {
        if (menu_dish.dish == "dish1") {
            EXPECT_EQ(menu_dish.count, 5);
        }
        if (menu_dish.dish == "dish2") {
            EXPECT_EQ(menu_dish.count, 3);
        }
        if (menu_dish.dish == "dish3") {
            EXPECT_EQ(menu_dish.count, 0);
        }
    }
    EXPECT_EQ(order.selected_dishes, (std::vector<Dish>{{"dish3", 15, 7}}));
}

TEST_F(OrderTestAddDish, test_add_dish_4) {
    bool result = order.add_dish({ "dish3", 15, 6 });
    EXPECT_TRUE(result);

    
    for (const auto& menu_dish : order.menu) {
        if (menu_dish.dish == "dish1") {
            EXPECT_EQ(menu_dish.count, 5);
        }
        if (menu_dish.dish == "dish2") {
            EXPECT_EQ(menu_dish.count, 3);
        }
        if (menu_dish.dish == "dish3") {
            EXPECT_EQ(menu_dish.count, 1);
        }
    }
    EXPECT_EQ(order.selected_dishes, (std::vector<Dish>{{"dish3", 15, 6}}));
}

TEST_F(OrderTestAddDish, test_add_dish_5) {
    bool result = order.add_dish({ "dish3", 15, 5 });
    EXPECT_TRUE(result);

    
    for (const auto& menu_dish : order.menu) {
        if (menu_dish.dish == "dish1") {
            EXPECT_EQ(menu_dish.count, 5);
        }
        if (menu_dish.dish == "dish2") {
            EXPECT_EQ(menu_dish.count, 3);
        }
        if (menu_dish.dish == "dish3") {
            EXPECT_EQ(menu_dish.count, 2);
        }
    }
    EXPECT_EQ(order.selected_dishes, (std::vector<Dish>{{"dish3", 15, 5}}));
}

TEST_F(OrderTestAddDish, test_add_dish_6) {
    order.menu.clear();
    bool result = order.add_dish({});
    EXPECT_TRUE(result);
}

class OrderTestCalculateTotal : public ::testing::Test {
protected:
    void SetUp() override {
        order = Order();
        order.menu.push_back({ "dish1", 10, 5 });
        order.menu.push_back({ "dish2", 15, 3 });
        order.menu.push_back({ "dish3", 20, 7 });
        order.sales = { {"dish1", 0.9}, {"dish2", 1}, {"dish3", 0.8} };
    }

    Order order;
};

TEST_F(OrderTestCalculateTotal, test_calculate_total_1) {
    order.add_dish({ "dish1", 10, 2 });
    order.add_dish({ "dish3", 20, 2 });
    double result = order.calculate_total();
    EXPECT_EQ(50, result);
}

TEST_F(OrderTestCalculateTotal, test_calculate_total_2) {
    order.add_dish({ "dish1", 10, 2 });
    order.add_dish({ "dish2", 15, 2 });
    double result = order.calculate_total();
    EXPECT_EQ(48, result);
}

TEST_F(OrderTestCalculateTotal, test_calculate_total_3) {
    order.add_dish({ "dish1", 10, 1 });
    order.add_dish({ "dish3", 20, 1 });
    double result = order.calculate_total();
    EXPECT_EQ(25, result);
}

TEST_F(OrderTestCalculateTotal, test_calculate_total_4) {
    order.add_dish({ "dish1", 10, 3 });
    order.add_dish({ "dish3", 20, 3 });
    double result = order.calculate_total();
    EXPECT_EQ(75, result);
}

TEST_F(OrderTestCalculateTotal, test_calculate_total_5) {
    order.add_dish({ "dish1", 10, 4 });
    order.add_dish({ "dish3", 20, 4 });
    double result = order.calculate_total();
    EXPECT_EQ(100, result);
}

class OrderTestCheckout : public ::testing::Test {
protected:
    void SetUp() override {
        order = Order();
        order.menu.push_back({ "dish1", 10, 5 });
        order.menu.push_back({ "dish2", 15, 3 });
        order.menu.push_back({ "dish3", 20, 7 });
        order.sales = { {"dish1", 0.9}, {"dish2", 1}, {"dish3", 0.8} };
    }

    Order order;
};


TEST_F(OrderTestCheckout, test_checkout_1) {
    order.add_dish({ "dish1", 10, 2 });
    order.add_dish({ "dish3", 20, 2 });
    double result = order.checkout();
    EXPECT_EQ(50, result);

    for (const auto& menu_dish : order.menu) {
        if (menu_dish.dish == "dish1") {
            EXPECT_EQ(menu_dish.count, 3);
        }
        if (menu_dish.dish == "dish2") {
            EXPECT_EQ(menu_dish.count, 3);
        }
        if (menu_dish.dish == "dish3") {
            EXPECT_EQ(menu_dish.count, 5);
        }
    }
    EXPECT_TRUE(order.selected_dishes.empty());
}



TEST_F(OrderTestCheckout, test_checkout_2) {
    double result = order.checkout();
    EXPECT_FALSE(result);
}

TEST_F(OrderTestCheckout, test_checkout_3) {
    order.add_dish({ "dish1", 10, 1 });
    order.add_dish({ "dish3", 20, 1 });
    double result = order.checkout();
    EXPECT_EQ(25, result);

    for (const auto& menu_dish : order.menu) {
        if (menu_dish.dish == "dish1") {
            EXPECT_EQ(menu_dish.count, 4);
        }
        if (menu_dish.dish == "dish2") {
            EXPECT_EQ(menu_dish.count, 3);
        }
        if (menu_dish.dish == "dish3") {
            EXPECT_EQ(menu_dish.count, 6);
        }
    }
    EXPECT_TRUE(order.selected_dishes.empty());
}

TEST_F(OrderTestCheckout, test_checkout_4) {
    order.add_dish({ "dish1", 10, 3 });
    order.add_dish({ "dish3", 20, 3 });
    double result = order.checkout();
    EXPECT_EQ(75, result);

    for (const auto& menu_dish : order.menu) {
        if (menu_dish.dish == "dish1") {
            EXPECT_EQ(menu_dish.count, 2);
        }
        if (menu_dish.dish == "dish2") {
            EXPECT_EQ(menu_dish.count, 3);
        }
        if (menu_dish.dish == "dish3") {
            EXPECT_EQ(menu_dish.count, 4);
        }
    }
    EXPECT_TRUE(order.selected_dishes.empty());
}

TEST_F(OrderTestCheckout, test_checkout_5) {
    order.add_dish({ "dish1", 10, 5 });
    order.add_dish({ "dish3", 20, 5 });
    double result = order.checkout();
    EXPECT_EQ(125, result);

    for (const auto& menu_dish : order.menu) {
        if (menu_dish.dish == "dish1") {
            EXPECT_EQ(menu_dish.count, 0);
        }
        if (menu_dish.dish == "dish2") {
            EXPECT_EQ(menu_dish.count, 3);
        }
        if (menu_dish.dish == "dish3") {
            EXPECT_EQ(menu_dish.count, 2);
        }
    }
    EXPECT_TRUE(order.selected_dishes.empty());
}

class OrderTest : public ::testing::Test {
protected:
    void SetUp() override {
        order = Order();
        order.menu.push_back({ "dish1", 10, 5 });
        order.menu.push_back({ "dish2", 15, 3 });
        order.menu.push_back({ "dish3", 20, 7 });
        order.sales = { {"dish1", 0.9}, {"dish2", 1}, {"dish3", 0.8} };
    }

    Order order;
};

TEST_F(OrderTest, test_order) {
    order.add_dish({ "dish1", 10, 2 });
    order.add_dish({ "dish3", 20, 2 });
    double result = order.checkout();
    EXPECT_EQ(50, result);

    for (const auto& menu_dish : order.menu) {
        if (menu_dish.dish == "dish1") {
            EXPECT_EQ(menu_dish.count, 3);
        }
        if (menu_dish.dish == "dish2") {
            EXPECT_EQ(menu_dish.count, 3);
        }
        if (menu_dish.dish == "dish3") {
            EXPECT_EQ(menu_dish.count, 5);
        }
    }
    EXPECT_TRUE(order.selected_dishes.empty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}