package to_be_tested;

public class RPGCharacter {

    public String name;

    public int hp;

    public int attackPower;

    public int defense;

    public int level;

    public int exp;

    public RPGCharacter(String name, int hp, int attackPower, int defense, int level) {
        this.name = name;
        this.hp = hp;
        this.attackPower = attackPower;
        this.defense = defense;
        this.level = level;
        this.exp = 0;
    }

    public void attack(RPGCharacter otherCharacter) {
        int damage = Math.max(attackPower - otherCharacter.defense, 1);
        otherCharacter.hp -= damage;
    }

    public int heal() {
        hp += 10;
        if (hp > 100) {
            hp = 100;
        }
        return hp;
    }

    public boolean isAlive() {
        return hp > 0;
    }

    public void gainExp(int amount) {
        while (amount != 0) {
            if (exp + amount >= level * 100) {
                amount -= (level * 100 - exp);
                levelUp();
            } else {
                exp += amount;
                amount = 0;
            }
        }
    }

    public void levelUp() {
        if (level < 100) {
            level++;
            exp = 0;
            hp += 20;
            attackPower += 5;
            defense += 5;
        }
    }
}
