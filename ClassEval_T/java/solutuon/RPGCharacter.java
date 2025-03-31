package org.example;

public class RPGCharacter {
    private String name;
    private int hp;
    private int attackPower;
    private int defense;
    private int level;
    private int exp;

    public RPGCharacter(String name, int hp, int attackPower, int defense, int level) {
        this.name = name;
        this.hp = hp;
        this.attackPower = attackPower;
        this.defense = defense;
        this.level = level;
        this.exp = 0;
    }

    public RPGCharacter(String name, int hp, int attackPower, int defense) {
        this(name, hp, attackPower, defense, 1);
    }

    public void attack(RPGCharacter otherCharacter) {
        int damage = Math.max(this.attackPower - otherCharacter.defense, 1);
        otherCharacter.hp -= damage;
    }

    public int heal() {
        this.hp += 10;
        if (this.hp > 100) {
            this.hp = 100;
        }
        return this.hp;
    }

    public void gainExp(int amount) {
        while (amount != 0) {
            if (this.exp + amount >= this.level * 100) {
                amount -= (this.level * 100 - this.exp);
                levelUp();
            } else {
                this.exp += amount;
                amount = 0;
            }
        }
    }

    public int[] levelUp() {
        if (this.level < 100) {
            this.level += 1;
            this.exp = 0;
            this.hp += 20;
            this.attackPower += 5;
            this.defense += 5;
        }
        return new int[]{this.level, this.hp, this.attackPower, this.defense};
    }

    public boolean isAlive() {
        return this.hp > 0;
    }

    // Getters and Setters
    public String getName() {
        return name;
    }

    public int getHp() {
        return hp;
    }

    public int getAttackPower() {
        return attackPower;
    }

    public int getDefense() {
        return defense;
    }

    public int getLevel() {
        return level;
    }

    public int getExp() {
        return exp;
    }
}