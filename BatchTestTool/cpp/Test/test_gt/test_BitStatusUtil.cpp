#include <gtest/gtest.h>
#include "pch.h"  

class BitStatusUtilTestAdd : public ::testing::Test {
protected:
    BitStatusUtil bit_status_util;
};

TEST_F(BitStatusUtilTestAdd, test_add) {
    EXPECT_EQ(bit_status_util.add(2, 4), 6);
}

TEST_F(BitStatusUtilTestAdd, test_add_2) {
    EXPECT_EQ(bit_status_util.add(2, 0), 2);
}

TEST_F(BitStatusUtilTestAdd, test_add_3) {
    EXPECT_EQ(bit_status_util.add(0, 0), 0);
}

TEST_F(BitStatusUtilTestAdd, test_add_4) {
    EXPECT_EQ(bit_status_util.add(0, 2), 2);
}

TEST_F(BitStatusUtilTestAdd, test_add_5) {
    EXPECT_EQ(bit_status_util.add(2, 2), 2); 
}

class BitStatusUtilTestHas : public ::testing::Test {
protected:
    BitStatusUtil bit_status_util;
};

TEST_F(BitStatusUtilTestHas, test_has) {
    EXPECT_TRUE(bit_status_util.has(6, 2));
}

TEST_F(BitStatusUtilTestHas, test_has_2) {
    EXPECT_FALSE(bit_status_util.has(8, 2));
}

TEST_F(BitStatusUtilTestHas, test_has_3) {
    EXPECT_TRUE(bit_status_util.has(6, 4));
}

TEST_F(BitStatusUtilTestHas, test_has_4) {
    EXPECT_FALSE(bit_status_util.has(8, 6));
}

TEST_F(BitStatusUtilTestHas, test_has_5) {
    EXPECT_TRUE(bit_status_util.has(6, 6));
}

class BitStatusUtilTestRemove : public ::testing::Test {
protected:
    BitStatusUtil bit_status_util;
};

TEST_F(BitStatusUtilTestRemove, test_remove) {
    EXPECT_EQ(bit_status_util.remove(6, 2), 4);
}

TEST_F(BitStatusUtilTestRemove, test_remove_2) {
    EXPECT_EQ(bit_status_util.remove(8, 2), 8);
}

TEST_F(BitStatusUtilTestRemove, test_remove_3) {
    EXPECT_EQ(bit_status_util.remove(6, 4), 2);
}

TEST_F(BitStatusUtilTestRemove, test_remove_4) {
    EXPECT_EQ(bit_status_util.remove(8, 6), 8);
}

TEST_F(BitStatusUtilTestRemove, test_remove_5) {
    EXPECT_EQ(bit_status_util.remove(6, 6), 0);
}

class BitStatusUtilTestCheck : public ::testing::Test {
protected:
    BitStatusUtil bit_status_util;
};

TEST_F(BitStatusUtilTestCheck, test_check) {
    EXPECT_NO_THROW(bit_status_util.check({ 2 }));
}

TEST_F(BitStatusUtilTestCheck, test_check_2) {
    EXPECT_THROW(bit_status_util.check({ 3 }), std::invalid_argument);
}

TEST_F(BitStatusUtilTestCheck, test_check_3) {
    EXPECT_THROW(bit_status_util.check({ -1 }), std::invalid_argument);
}

TEST_F(BitStatusUtilTestCheck, test_check_4) {
    EXPECT_THROW(bit_status_util.check({ 2, 3, 4 }), std::invalid_argument);
}

TEST_F(BitStatusUtilTestCheck, test_check_5) {
    EXPECT_THROW(bit_status_util.check({ 2, 3, 4, 5 }), std::invalid_argument);
}

class BitStatusUtilTestMain : public ::testing::Test {
protected:
    BitStatusUtil bit_status_util;
};

TEST_F(BitStatusUtilTestMain, test_main) {
    EXPECT_EQ(bit_status_util.add(2, 4), 6);
    EXPECT_TRUE(bit_status_util.has(6, 2));
    EXPECT_EQ(bit_status_util.remove(6, 2), 4);
    EXPECT_THROW(bit_status_util.check({ 2, 3, 4 }), std::invalid_argument);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}