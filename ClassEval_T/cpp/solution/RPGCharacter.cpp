#include <string>

class RPGCharacter {
public:
    RPGCharacter(const std::string& name, int hp, int attack_power, int defense, int level = 1);

    void attack(RPGCharacter& other_character);
    int heal();
    void gain_exp(int amount);
    bool is_alive() const;

    
    int get_hp() const;
    int get_exp() const;
    int get_attack_power() const;
    int get_defense() const;
    int get_level() const;
    void set_hp(int x);

    void level_up();

    std::string name;
    int hp;
    int attack_power;
    int defense;
    int level;
    int exp;
};
RPGCharacter::RPGCharacter(const std::string& name, int hp, int attack_power, int defense, int level)
    : name(name), hp(hp), attack_power(attack_power), defense(defense), level(level), exp(0) {
}

void RPGCharacter::attack(RPGCharacter& other_character) {
    int damage = std::max(attack_power - other_character.defense, 1);
    other_character.hp -= damage;
}

int RPGCharacter::heal() {
    hp += 10;
    if (hp > 100) {
        hp = 100;
    }
    return hp;
}

void RPGCharacter::gain_exp(int amount) {
    while (amount != 0) {
        if (exp + amount >= level * 100) {
            amount -= (level * 100 - exp);
            level_up();
        }
        else {
            exp += amount;
            amount = 0;
        }
    }
}

void RPGCharacter::level_up() {
    if (level < 100) {
        level++;
        exp = 0;
        hp += 20;
        attack_power += 5;
        defense += 5;
    }
}

bool RPGCharacter::is_alive() const {
    return hp > 0;
}

int RPGCharacter::get_hp() const {
    return hp;
}

int RPGCharacter::get_exp() const {
    return exp;
}

int RPGCharacter::get_attack_power() const {
    return attack_power;
}

int RPGCharacter::get_defense() const {
    return defense;
}

int RPGCharacter::get_level() const {
    return level;
}

void RPGCharacter::set_hp(int x)
{
    this->hp = x;
}