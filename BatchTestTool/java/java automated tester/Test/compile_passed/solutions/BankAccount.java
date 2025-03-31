public class BankAccount {
    // Instance variable
    private double balance;

    // Constructor with parameter
    public BankAccount(double balance) {
        this.balance = balance;
    }

    // Default constructor (no parameters)
    public BankAccount() {
        this(0); // Calls the parameterized constructor with default value 0
    }

    // BankAccount.deposit method
    public double deposit(double amount) {
        if (amount < 0) {
            throw new IllegalArgumentException("Invalid amount");
        }
        this.balance += amount;
        return this.balance;
    }

    // BankAccount.withdraw method
    public double withdraw(double amount) {
        if (amount < 0) {
            throw new IllegalArgumentException("Invalid amount");
        }
        if (amount > this.balance) {
            throw new IllegalArgumentException("Insufficient balance.");
        }
        this.balance -= amount;
        return this.balance;
    }

    // BankAccount.transfer method
    public void transfer(BankAccount otherAccount, double amount) {
        this.withdraw(amount);
        otherAccount.deposit(amount);
    }

    // BankAccount class method
    public double viewBalance() {
        return this.balance;
    }
}