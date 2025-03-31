package org.example;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class RPGCharacterTest {

    private RPGCharacter character1;
    private RPGCharacter character2;

    @BeforeEach
    public void setUp() {
        character1 = new RPGCharacter("John", 100, 20, 10);
        character2 = new RPGCharacter("Enemy", 100, 15, 5);
    }

    @Test
    public void testAttack() {
        character1.attack(character2);
        assertEquals(85, character2.getHp());
    }

    @Test
    public void testAttack2() {
        character2.attack(character1);
        assertEquals(95, character1.getHp());
    }

    @Test
    public void testAttack3() {
        character1.attack(character2);
        character2.attack(character1);
        assertEquals(95, character1.getHp());
        assertEquals(85, character2.getHp());
    }

    @Test
    public void testAttack4() {
        character1.attack(character2);
        character1.attack(character2);
        assertEquals(70, character2.getHp());
    }

    @Test
    public void testAttack5() {
        character1.attack(character2);
        character1.attack(character2);
        character1.attack(character2);
        assertEquals(55, character2.getHp());
    }

    @Test
    public void testHeal1() {
        RPGCharacter character = new RPGCharacter("John", 90, 20, 10);
        character.heal();
        assertEquals(100, character.getHp());
    }

    @Test
    public void testHeal2() {
        RPGCharacter character = new RPGCharacter("John", 97, 20, 10);
        character.heal();
        assertEquals(100, character.getHp());
    }

    @Test
    public void testHeal3() {
        RPGCharacter character = new RPGCharacter("John", 100, 20, 10);
        character.heal();
        assertEquals(100, character.getHp());
    }

    @Test
    public void testHeal4() {
        RPGCharacter character = new RPGCharacter("John", 50, 20, 10);
        character.heal();
        assertEquals(60, character.getHp());
    }

    @Test
    public void testHeal5() {
        RPGCharacter character = new RPGCharacter("John", 10, 20, 10);
        character.heal();
        assertEquals(20, character.getHp());
    }

    @Test
    public void testGainExp1() {
        RPGCharacter character = new RPGCharacter("John", 100, 20, 10);
        character.gainExp(100);
        assertEquals(2, character.getLevel());
        assertEquals(0, character.getExp());
    }

    @Test
    public void testGainExp2() {
        RPGCharacter character = new RPGCharacter("John", 100, 20, 10);
        character.gainExp(1100);
        assertEquals(5, character.getLevel());
        assertEquals(100, character.getExp());
    }

    @Test
    public void testGainExp3() {
        RPGCharacter character = new RPGCharacter("John", 100, 20, 10);
        character.gainExp(200);
        assertEquals(2, character.getLevel());
        assertEquals(100, character.getExp());
    }

    @Test
    public void testGainExp4() {
        RPGCharacter character = new RPGCharacter("John", 100, 20, 10);
        character.gainExp(300);
        assertEquals(3, character.getLevel());
        assertEquals(0, character.getExp());
    }

    @Test
    public void testGainExp5() {
        RPGCharacter character = new RPGCharacter("John", 100, 20, 10);
        character.gainExp(400);
        assertEquals(3, character.getLevel());
        assertEquals(100, character.getExp());
    }

    @Test
    public void testLevelUp1() {
        RPGCharacter character = new RPGCharacter("John", 100, 20, 10);
        character.levelUp();
        assertEquals(2, character.getLevel());
        assertEquals(0, character.getExp());
        assertEquals(120, character.getHp());
        assertEquals(25, character.getAttackPower());
        assertEquals(15, character.getDefense());
    }

    @Test
    public void testLevelUp2() {
        RPGCharacter character = new RPGCharacter("John", 100, 20, 10, 100);
        character.levelUp();
        assertEquals(100, character.getLevel());
        assertEquals(0, character.getExp());
        assertEquals(100, character.getHp());
        assertEquals(20, character.getAttackPower());
        assertEquals(10, character.getDefense());
    }

    @Test
    public void testLevelUp3() {
        RPGCharacter character = new RPGCharacter("John", 100, 20, 10, 2);
        character.levelUp();
        assertEquals(3, character.getLevel());
        assertEquals(0, character.getExp());
        assertEquals(120, character.getHp());
        assertEquals(25, character.getAttackPower());
        assertEquals(15, character.getDefense());
    }

    @Test
    public void testLevelUp4() {
        RPGCharacter character = new RPGCharacter("John", 100, 20, 10, 3);
        character.levelUp();
        assertEquals(4, character.getLevel());
        assertEquals(0, character.getExp());
        assertEquals(120, character.getHp());
        assertEquals(25, character.getAttackPower());
        assertEquals(15, character.getDefense());
    }

    @Test
    public void testLevelUp5() {
        RPGCharacter character = new RPGCharacter("John", 100, 20, 10, 4);
        character.levelUp();
        assertEquals(5, character.getLevel());
        assertEquals(0, character.getExp());
        assertEquals(120, character.getHp());
        assertEquals(25, character.getAttackPower());
        assertEquals(15, character.getDefense());
    }

    @Test
    public void testIsAlive1() {
        RPGCharacter character = new RPGCharacter("John", 100, 20, 10);
        assertTrue(character.isAlive());
    }

    @Test
    public void testIsAlive2() {
        RPGCharacter character = new RPGCharacter("John", 0, 20, 10);
        assertFalse(character.isAlive());
    }

    @Test
    public void testIsAlive3() {
        RPGCharacter character = new RPGCharacter("John", -10, 20, 10);
        assertFalse(character.isAlive());
    }

    @Test
    public void testIsAlive4() {
        RPGCharacter character = new RPGCharacter("John", 1, 20, 10);
        assertTrue(character.isAlive());
    }

    @Test
    public void testIsAlive5() {
        RPGCharacter character = new RPGCharacter("John", 10, 20, 10);
        assertTrue(character.isAlive());
    }

    @Test
    public void testMain() {
        RPGCharacter character1 = new RPGCharacter("John", 100, 20, 10);
        RPGCharacter character2 = new RPGCharacter("Enemy", 100, 15, 5);
        character1.attack(character2);
        assertEquals(85, character2.getHp());
        character2.heal();
        assertEquals(95, character2.getHp());
        character1.gainExp(200);
        assertEquals(100, character1.getExp());
        assertEquals(120, character1.getHp());
        assertEquals(25, character1.getAttackPower());
        assertEquals(15, character1.getDefense());
        assertTrue(character1.isAlive());
    }
}