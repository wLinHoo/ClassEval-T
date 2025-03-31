package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class BankAccountTest {

    @org.junit.Test
    @Test
    public void testDeposit() {
        BankAccount account1 = new BankAccount();
        int ret = account1.deposit(1000);
        assertEquals(1000, ret);
    }

    @Test
    public void testDeposit2() {
        BankAccount account1 = new BankAccount();
        account1.deposit(1000);
        int ret = account1.deposit(2000);
        assertEquals(3000, ret);
    }

    @Test
    public void testDeposit3() {
        BankAccount account1 = new BankAccount();
        IllegalArgumentException exception = assertThrows(IllegalArgumentException.class, () -> {
            account1.deposit(-1000);
        });
        assertEquals("Invalid amount", exception.getMessage());
    }

    @Test
    public void testDeposit4() {
        BankAccount account1 = new BankAccount();
        int ret = account1.deposit(0);
        assertEquals(0, ret);
    }

    @Test
    public void testDeposit5() {
        BankAccount account1 = new BankAccount();
        account1.deposit(1000);
        int ret = account1.deposit(1000);
        assertEquals(2000, ret);
    }

    @Test
    public void testWithdraw() {
        BankAccount account1 = new BankAccount(1000);
        int ret = account1.withdraw(200);
        assertEquals(800, ret);
    }

    @Test
    public void testWithdraw2() {
        BankAccount account1 = new BankAccount(500);
        IllegalArgumentException exception = assertThrows(IllegalArgumentException.class, () -> {
            account1.withdraw(1000);
        });
        assertEquals("Insufficient balance.", exception.getMessage());
    }

    @Test
    public void testWithdraw3() {
        BankAccount account1 = new BankAccount();
        IllegalArgumentException exception = assertThrows(IllegalArgumentException.class, () -> {
            account1.withdraw(-1000);
        });
        assertEquals("Invalid amount", exception.getMessage());
    }

    @Test
    public void testWithdraw4() {
        BankAccount account1 = new BankAccount(1000);
        int ret = account1.withdraw(500);
        assertEquals(500, ret);
    }

    @Test
    public void testWithdraw5() {
        BankAccount account1 = new BankAccount(1000);
        int ret = account1.withdraw(1000);
        assertEquals(0, ret);
    }

    @Test
    public void testViewBalance() {
        BankAccount account1 = new BankAccount();
        assertEquals(0, account1.viewBalance());
    }

    @Test
    public void testViewBalance2() {
        BankAccount account1 = new BankAccount(1000);
        assertEquals(1000, account1.viewBalance());
    }

    @Test
    public void testViewBalance3() {
        BankAccount account1 = new BankAccount(500);
        assertEquals(500, account1.viewBalance());
    }

    @Test
    public void testViewBalance4() {
        BankAccount account1 = new BankAccount(1500);
        assertEquals(1500, account1.viewBalance());
    }

    @Test
    public void testViewBalance5() {
        BankAccount account1 = new BankAccount(2000);
        assertEquals(2000, account1.viewBalance());
    }

    @Test
    public void testTransfer() {
        BankAccount account1 = new BankAccount(800);
        BankAccount account2 = new BankAccount(1000);
        account1.transfer(account2, 300);
        assertEquals(500, account1.viewBalance());
        assertEquals(1300, account2.viewBalance());
    }

    @Test
    public void testTransfer2() {
        BankAccount account1 = new BankAccount(500);
        BankAccount account2 = new BankAccount();
        IllegalArgumentException exception = assertThrows(IllegalArgumentException.class, () -> {
            account1.transfer(account2, 600);
        });
        assertEquals("Insufficient balance.", exception.getMessage());
    }

    @Test
    public void testTransfer3() {
        BankAccount account1 = new BankAccount(500);
        BankAccount account2 = new BankAccount(1000);
        IllegalArgumentException exception = assertThrows(IllegalArgumentException.class, () -> {
            account1.transfer(account2, -600);
        });
        assertEquals("Invalid amount", exception.getMessage());
    }

    @Test
    public void testTransfer4() {
        BankAccount account1 = new BankAccount(500);
        BankAccount account2 = new BankAccount(1000);
        account1.transfer(account2, 500);
        assertEquals(0, account1.viewBalance());
        assertEquals(1500, account2.viewBalance());
    }

    @Test
    public void testTransfer5() {
        BankAccount account1 = new BankAccount(500);
        BankAccount account2 = new BankAccount(1000);
        account1.transfer(account2, 200);
        assertEquals(300, account1.viewBalance());
        assertEquals(1200, account2.viewBalance());
    }

    @Test
    public void testAll() {
        BankAccount account1 = new BankAccount();
        BankAccount account2 = new BankAccount();
        account1.deposit(1000);
        account1.withdraw(200);
        account1.transfer(account2, 300);
        assertEquals(500, account1.viewBalance());
        assertEquals(300, account2.viewBalance());
    }

    @Test
    public void testAll2() {
        BankAccount account1 = new BankAccount();
        BankAccount account2 = new BankAccount();
        account1.deposit(1000);
        account1.withdraw(200);
        account1.transfer(account2, 300);
        account2.withdraw(100);
        assertEquals(500, account1.viewBalance());
        assertEquals(200, account2.viewBalance());
    }
}
