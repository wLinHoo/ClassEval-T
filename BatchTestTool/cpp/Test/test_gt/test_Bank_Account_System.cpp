#include "pch.h"
#include <gtest/gtest.h>
#include <stdexcept>

class BankAccountTestDeposit : public ::testing::Test {
protected:
    BankAccount account1;
};

TEST_F(BankAccountTestDeposit, test_deposit) {
    double ret = account1.deposit(1000);
    EXPECT_EQ(ret, 1000);
}

TEST_F(BankAccountTestDeposit, test_deposit_2) {
    account1.deposit(1000);
    double ret = account1.deposit(2000);
    EXPECT_EQ(ret, 3000);
}

TEST_F(BankAccountTestDeposit, test_deposit_3) {
    EXPECT_THROW({
        try {
            account1.deposit(-1000);
        }
        catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Invalid amount", e.what());
            throw;
        }
        }, std::invalid_argument);
}

TEST_F(BankAccountTestDeposit, test_deposit_4) {
    double ret = account1.deposit(0);
    EXPECT_EQ(ret, 0);
}

TEST_F(BankAccountTestDeposit, test_deposit_5) {
    account1.deposit(1000);
    double ret = account1.deposit(1000);
    EXPECT_EQ(ret, 2000);
}

class BankAccountTestWithdraw : public ::testing::Test {
protected:
    BankAccount account1;
};

TEST_F(BankAccountTestWithdraw, test_withdraw) {
    account1.deposit(1000);
    double ret = account1.withdraw(200);
    EXPECT_EQ(ret, 800);
}

TEST_F(BankAccountTestWithdraw, test_withdraw_2) {
    account1.deposit(500);
    EXPECT_THROW({
        try {
            account1.withdraw(1000);
        }
        catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Insufficient balance.", e.what());
            throw;
        }
        }, std::invalid_argument);
}

TEST_F(BankAccountTestWithdraw, test_withdraw_3) {
    EXPECT_THROW({
        try {
            account1.withdraw(-1000);
        }
        catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Invalid amount", e.what());
            throw;
        }
        }, std::invalid_argument);
}

TEST_F(BankAccountTestWithdraw, test_withdraw_4) {
    account1.deposit(1000);
    double ret = account1.withdraw(500);
    EXPECT_EQ(ret, 500);
}

TEST_F(BankAccountTestWithdraw, test_withdraw_5) {
    account1.deposit(1000);
    double ret = account1.withdraw(1000);
    EXPECT_EQ(ret, 0);
}

class BankAccountTestViewBalance : public ::testing::Test {
protected:
    BankAccount account1;
};

TEST_F(BankAccountTestViewBalance, test_view_balance) {
    EXPECT_EQ(account1.view_balance(), 0);
}

TEST_F(BankAccountTestViewBalance, test_view_balance_2) {
    account1.deposit(1000);
    EXPECT_EQ(account1.view_balance(), 1000);
}

TEST_F(BankAccountTestViewBalance, test_view_balance_3) {
    account1.deposit(500);
    EXPECT_EQ(account1.view_balance(), 500);
}

TEST_F(BankAccountTestViewBalance, test_view_balance_4) {
    account1.deposit(1500);
    EXPECT_EQ(account1.view_balance(), 1500);
}

TEST_F(BankAccountTestViewBalance, test_view_balance_5) {
    account1.deposit(2000);
    EXPECT_EQ(account1.view_balance(), 2000);
}

class BankAccountTestTransfer : public ::testing::Test {
protected:
    BankAccount account1;
    BankAccount account2;
};

TEST_F(BankAccountTestTransfer, test_transfer) {
    account1.deposit(800);
    account2.deposit(1000);
    account1.transfer(account2, 300);
    EXPECT_EQ(account1.view_balance(), 500);
    EXPECT_EQ(account2.view_balance(), 1300);
}

TEST_F(BankAccountTestTransfer, test_transfer_2) {
    account1.deposit(500);
    EXPECT_THROW({
        try {
            account1.transfer(account2, 600);
        }
        catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Insufficient balance.", e.what());
            throw;
        }
        }, std::invalid_argument);
}

TEST_F(BankAccountTestTransfer, test_transfer_3) {
    account1.deposit(500);
    account2.deposit(1000);
    EXPECT_THROW({
        try {
            account1.transfer(account2, -600);
        }
        catch (const std::invalid_argument& e) {
            EXPECT_STREQ("Invalid amount", e.what());
            throw;
        }
        }, std::invalid_argument);
}

TEST_F(BankAccountTestTransfer, test_transfer_4) {
    account1.deposit(500);
    account2.deposit(1000);
    account1.transfer(account2, 500);
    EXPECT_EQ(account1.view_balance(), 0);
    EXPECT_EQ(account2.view_balance(), 1500);
}

TEST_F(BankAccountTestTransfer, test_transfer_5) {
    account1.deposit(500);
    account2.deposit(1000);
    account1.transfer(account2, 200);
    EXPECT_EQ(account1.view_balance(), 300);
    EXPECT_EQ(account2.view_balance(), 1200);
}

class BankAccountTest : public ::testing::Test {
protected:
    BankAccount account1;
    BankAccount account2;
};

TEST_F(BankAccountTest, test_all) {
    account1.deposit(1000);
    account1.withdraw(200);
    account1.transfer(account2, 300);
    EXPECT_EQ(account1.view_balance(), 500);
    EXPECT_EQ(account2.view_balance(), 300);
}

TEST_F(BankAccountTest, test_all2) {
    account1.deposit(1000);
    account1.withdraw(200);
    account1.transfer(account2, 300);
    account2.withdraw(100);
    EXPECT_EQ(account1.view_balance(), 500);
    EXPECT_EQ(account2.view_balance(), 200);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
