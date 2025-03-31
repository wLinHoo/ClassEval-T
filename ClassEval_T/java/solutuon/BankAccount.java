package org.example;

public class BankAccount {
    private int balance;

    public BankAccount(int balance) {
        this.balance = balance;
    }

    public BankAccount() {
        this(0);
    }

    public int deposit(int amount) {
        if (amount < 0) {
            throw new IllegalArgumentException("Invalid amount");
        }
        this.balance += amount;
        return this.balance;
    }

    public int withdraw(int amount) {
        if (amount < 0) {
            throw new IllegalArgumentException("Invalid amount");
        }
        if (amount > this.balance) {
            throw new IllegalArgumentException("Insufficient balance.");
        }
        this.balance -= amount;
        return this.balance;
    }

    public int viewBalance() {
        return this.balance;
    }

    public void transfer(BankAccount otherAccount, int amount) {
        this.withdraw(amount);
        otherAccount.deposit(amount);
    }

    public static void main(String[] args) {
        BankAccount account1 = new BankAccount();
        BankAccount account2 = new BankAccount();
        account1.deposit(1000);
        account1.transfer(account2, 300);
        System.out.println("account1.balance = " + account1.viewBalance());
        System.out.println("account2.balance = " + account2.viewBalance());
    }
}
