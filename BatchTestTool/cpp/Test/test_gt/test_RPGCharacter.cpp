#include <gtest/gtest.h>
#include "pch.h"

class RPGCharacterTest : public ::testing::Test {};


TEST_F(RPGCharacterTest, TestMain) {
    RPGCharacter character1("John", 100, 20, 10);
    RPGCharacter character2("Enemy", 100, 15, 5);

    character1.attack(character2);
    EXPECT_EQ(character2.get_hp(), 85);

    character2.heal();
    EXPECT_EQ(character2.get_hp(), 95);

    character1.gain_exp(200);
    EXPECT_EQ(character1.get_exp(), 100);
    EXPECT_EQ(character1.get_hp(), 120);
    EXPECT_EQ(character1.get_attack_power(), 25);
    EXPECT_EQ(character1.get_defense(), 15);
    EXPECT_TRUE(character1.is_alive());
}


class RPGCharacterTestAttack : public ::testing::Test {};

TEST_F(RPGCharacterTestAttack, TestAttack) {
    RPGCharacter character1("John", 100, 20, 10);
    RPGCharacter character2("Enemy", 100, 15, 5);
    character1.attack(character2);
    EXPECT_EQ(character2.get_hp(), 85);
}

TEST_F(RPGCharacterTestAttack, TestAttack2) {
    RPGCharacter character1("John", 100, 20, 10);
    RPGCharacter character2("Enemy", 100, 15, 5);
    character2.attack(character1);
    EXPECT_EQ(character1.get_hp(), 95);
}

TEST_F(RPGCharacterTestAttack, TestAttack3) {
    RPGCharacter character1("John", 100, 20, 10);
    RPGCharacter character2("Enemy", 100, 15, 5);
    character1.attack(character2);
    character2.attack(character1);
    EXPECT_EQ(character1.get_hp(), 95);
    EXPECT_EQ(character2.get_hp(), 85);
}

TEST_F(RPGCharacterTestAttack, TestAttack4) {
    RPGCharacter character1("John", 100, 20, 10);
    RPGCharacter character2("Enemy", 100, 15, 5);
    character1.attack(character2);
    character1.attack(character2);
    EXPECT_EQ(character2.get_hp(), 70);
}

TEST_F(RPGCharacterTestAttack, TestAttack5) {
    RPGCharacter character1("John", 100, 20, 10);
    RPGCharacter character2("Enemy", 100, 15, 5);
    character1.attack(character2);
    character1.attack(character2);
    character1.attack(character2);
    EXPECT_EQ(character2.get_hp(), 55);
}


class RPGCharacterTestHeal : public ::testing::Test {};

TEST_F(RPGCharacterTestHeal, TestHeal1) {
    RPGCharacter character("John", 90, 20, 10);
    character.heal();
    EXPECT_EQ(character.get_hp(), 100);
}

TEST_F(RPGCharacterTestHeal, TestHeal2) {
    RPGCharacter character("John", 97, 20, 10);
    character.heal();
    EXPECT_EQ(character.get_hp(), 100);
}

TEST_F(RPGCharacterTestHeal, TestHeal3) {
    RPGCharacter character("John", 100, 20, 10);
    character.heal();
    EXPECT_EQ(character.get_hp(), 100);
}

TEST_F(RPGCharacterTestHeal, TestHeal4) {
    RPGCharacter character("John", 100, 20, 10);
    character.set_hp(50); 
    character.heal();
    EXPECT_EQ(character.get_hp(), 60);
}

TEST_F(RPGCharacterTestHeal, TestHeal5) {
    RPGCharacter character("John", 100, 20, 10);
    character.set_hp(10); 
    character.heal();
    EXPECT_EQ(character.get_hp(), 20);
}



class RPGCharacterTestGainExp : public ::testing::Test {};

TEST_F(RPGCharacterTestGainExp, TestGainExp1) {
    RPGCharacter character("John", 100, 20, 10);
    character.gain_exp(100);
    EXPECT_EQ(character.get_exp(), 0);
    EXPECT_EQ(character.get_hp(), 120);
}

TEST_F(RPGCharacterTestGainExp, TestGainExp2) {
    RPGCharacter character("John", 100, 20, 10);
    character.gain_exp(1100);
    EXPECT_EQ(character.get_level(), 5);
    EXPECT_EQ(character.get_exp(), 100);
}

TEST_F(RPGCharacterTestGainExp, TestGainExp3) {
    RPGCharacter character("John", 100, 20, 10);
    character.gain_exp(200);
    EXPECT_EQ(character.get_level(), 2);
    EXPECT_EQ(character.get_exp(), 100);
}

TEST_F(RPGCharacterTestGainExp, TestGainExp4) {
    RPGCharacter character("John", 100, 20, 10);
    character.gain_exp(300);
    EXPECT_EQ(character.get_level(), 3);
    EXPECT_EQ(character.get_exp(), 0);
}

TEST_F(RPGCharacterTestGainExp, TestGainExp5) {
    RPGCharacter character("John", 100, 20, 10);
    character.gain_exp(400);
    EXPECT_EQ(character.get_level(), 3);
    EXPECT_EQ(character.get_exp(), 100);
}


class RPGCharacterTestLevelUp : public ::testing::Test {};

TEST_F(RPGCharacterTestLevelUp, TestLevelUp1) {
    RPGCharacter character("John", 100, 20, 10);
    character.level_up();
    EXPECT_EQ(character.get_exp(), 0);
    EXPECT_EQ(character.get_hp(), 120);
    EXPECT_EQ(character.get_attack_power(), 25);
    EXPECT_EQ(character.get_defense(), 15);
}

TEST_F(RPGCharacterTestLevelUp, TestLevelUp2) {
    RPGCharacter character("John", 100, 20, 10, 100);
    character.level_up();
    EXPECT_EQ(character.get_level(), 100);
    EXPECT_EQ(character.get_exp(), 0);
    EXPECT_EQ(character.get_hp(), 100);
    EXPECT_EQ(character.get_attack_power(), 20);
    EXPECT_EQ(character.get_defense(), 10);
}

TEST_F(RPGCharacterTestLevelUp, TestLevelUp3) {
    RPGCharacter character("John", 100, 20, 10, 2);
    character.level_up();
    EXPECT_EQ(character.get_level(), 3);
    EXPECT_EQ(character.get_exp(), 0);
    EXPECT_EQ(character.get_hp(), 120);
    EXPECT_EQ(character.get_attack_power(), 25);
    EXPECT_EQ(character.get_defense(), 15);
}

TEST_F(RPGCharacterTestLevelUp, TestLevelUp4) {
    RPGCharacter character("John", 100, 20, 10, 3);
    character.level_up();
    EXPECT_EQ(character.get_level(), 4);
    EXPECT_EQ(character.get_exp(), 0);
    EXPECT_EQ(character.get_hp(), 120);
    EXPECT_EQ(character.get_attack_power(), 25);
    EXPECT_EQ(character.get_defense(), 15);
}

TEST_F(RPGCharacterTestLevelUp, TestLevelUp5) {
    RPGCharacter character("John", 100, 20, 10, 4);
    character.level_up();
    EXPECT_EQ(character.get_level(), 5);
    EXPECT_EQ(character.get_exp(), 0);
    EXPECT_EQ(character.get_hp(), 120);
    EXPECT_EQ(character.get_attack_power(), 25);
    EXPECT_EQ(character.get_defense(), 15);
}


class RPGCharacterTestIsAlive : public ::testing::Test {};

TEST_F(RPGCharacterTestIsAlive, TestIsAlive1) {
    RPGCharacter character("John", 100, 20, 10);
    EXPECT_TRUE(character.is_alive());
}

TEST_F(RPGCharacterTestIsAlive, TestIsAlive2) {
    RPGCharacter character("John", 0, 20, 10);
    EXPECT_FALSE(character.is_alive());
}

TEST_F(RPGCharacterTestIsAlive, TestIsAlive3) {
    RPGCharacter character("John", -10, 20, 10);
    EXPECT_FALSE(character.is_alive());
}

TEST_F(RPGCharacterTestIsAlive, TestIsAlive4) {
    RPGCharacter character("John", 1, 20, 10);
    EXPECT_TRUE(character.is_alive());
}

TEST_F(RPGCharacterTestIsAlive, TestIsAlive5) {
    RPGCharacter character("John", 10, 20, 10);
    EXPECT_TRUE(character.is_alive());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}