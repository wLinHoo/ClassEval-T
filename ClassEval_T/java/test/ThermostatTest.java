package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class ThermostatTest {

    @Test
    public void testGetTargetTemperature1() {
        Thermostat t = new Thermostat(20, 25, "heat");
        assertEquals(25, t.getTargetTemperature());
    }

    @Test
    public void testGetTargetTemperature2() {
        Thermostat t = new Thermostat(20, 25, "cool");
        assertEquals(25, t.getTargetTemperature());
    }

    @Test
    public void testGetTargetTemperature3() {
        Thermostat t = new Thermostat(20, 25, "test");
        assertEquals(25, t.getTargetTemperature());
    }

    @Test
    public void testGetTargetTemperature4() {
        Thermostat t = new Thermostat(25, 25, "cool");
        assertEquals(25, t.getTargetTemperature());
    }

    @Test
    public void testGetTargetTemperature5() {
        Thermostat t = new Thermostat(25, 25, "heat");
        assertEquals(25, t.getTargetTemperature());
    }

    @Test
    public void testSetTargetTemperature1() {
        Thermostat t = new Thermostat(20, 25, "heat");
        t.setTargetTemperature(30);
        assertEquals(30, t.getTargetTemperature());
    }

    @Test
    public void testSetTargetTemperature2() {
        Thermostat t = new Thermostat(20, 25, "cool");
        t.setTargetTemperature(10);
        assertEquals(10, t.getTargetTemperature());
    }

    @Test
    public void testSetTargetTemperature3() {
        Thermostat t = new Thermostat(20, 25, "test");
        t.setTargetTemperature(10);
        assertEquals(10, t.getTargetTemperature());
    }

    @Test
    public void testSetTargetTemperature4() {
        Thermostat t = new Thermostat(25, 25, "cool");
        t.setTargetTemperature(10);
        assertEquals(10, t.getTargetTemperature());
    }

    @Test
    public void testSetTargetTemperature5() {
        Thermostat t = new Thermostat(25, 25, "heat");
        t.setTargetTemperature(10);
        assertEquals(10, t.getTargetTemperature());
    }

    @Test
    public void testGetMode1() {
        Thermostat t = new Thermostat(20, 25, "heat");
        assertEquals("heat", t.getMode());
    }

    @Test
    public void testGetMode2() {
        Thermostat t = new Thermostat(20, 25, "cool");
        assertEquals("cool", t.getMode());
    }

    @Test
    public void testGetMode3() {
        Thermostat t = new Thermostat(20, 25, "test");
        assertEquals("test", t.getMode());
    }

    @Test
    public void testGetMode4() {
        Thermostat t = new Thermostat(25, 25, "cool");
        assertEquals("cool", t.getMode());
    }

    @Test
    public void testGetMode5() {
        Thermostat t = new Thermostat(25, 25, "heat");
        assertEquals("heat", t.getMode());
    }

    @Test
    public void testSetMode1() {
        Thermostat t = new Thermostat(20, 25, "heat");
        assertTrue(t.setMode("cool"));
        assertEquals("cool", t.getMode());
    }

    @Test
    public void testSetMode2() {
        Thermostat t = new Thermostat(20, 25, "heat");
        assertFalse(t.setMode("test"));
    }

    @Test
    public void testSetMode3() {
        Thermostat t = new Thermostat(20, 25, "cool");
        assertTrue(t.setMode("heat"));
        assertEquals("heat", t.getMode());
    }

    @Test
    public void testSetMode4() {
        Thermostat t = new Thermostat(20, 25, "test");
        assertTrue(t.setMode("heat"));
        assertEquals("heat", t.getMode());
    }

    @Test
    public void testSetMode5() {
        Thermostat t = new Thermostat(25, 25, "cool");
        assertTrue(t.setMode("heat"));
        assertEquals("heat", t.getMode());
    }

    @Test
    public void testAutoSetMode1() {
        Thermostat t = new Thermostat(20, 25, "heat");
        t.autoSetMode();
        assertEquals("heat", t.getMode());
    }

    @Test
    public void testAutoSetMode2() {
        Thermostat t = new Thermostat(25, 20, "heat");
        t.autoSetMode();
        assertEquals("cool", t.getMode());
    }

    @Test
    public void testAutoSetMode3() {
        Thermostat t = new Thermostat(25, 20, "cool");
        t.autoSetMode();
        assertEquals("cool", t.getMode());
    }

    @Test
    public void testAutoSetMode4() {
        Thermostat t = new Thermostat(20, 25, "cool");
        t.autoSetMode();
        assertEquals("heat", t.getMode());
    }

    @Test
    public void testAutoSetMode5() {
        Thermostat t = new Thermostat(25, 25, "cool");
        t.autoSetMode();
        assertEquals("cool", t.getMode());
    }

    @Test
    public void testAutoCheckConflict1() {
        Thermostat t = new Thermostat(30, 25, "cool");
        assertTrue(t.autoCheckConflict());
    }

    @Test
    public void testAutoCheckConflict2() {
        Thermostat t = new Thermostat(30, 25, "heat");
        assertFalse(t.autoCheckConflict());
        assertEquals("cool", t.getMode());
    }

    @Test
    public void testAutoCheckConflict3() {
        Thermostat t = new Thermostat(25, 30, "heat");
        assertTrue(t.autoCheckConflict());
    }

    @Test
    public void testAutoCheckConflict4() {
        Thermostat t = new Thermostat(25, 30, "cool");
        assertFalse(t.autoCheckConflict());
        assertEquals("heat", t.getMode());
    }

    @Test
    public void testAutoCheckConflict5() {
        Thermostat t = new Thermostat(25, 25, "cool");
        assertFalse(t.autoCheckConflict());
        assertEquals("cool", t.getMode());
    }

    @Test
    public void testSimulateOperation1() {
        Thermostat t = new Thermostat(20, 25, "heat");
        assertEquals(5, t.simulateOperation());
        assertEquals("heat", t.getMode());
        assertEquals(25, t.currentTemperature);
    }

    @Test
    public void testSimulateOperation2() {
        Thermostat t = new Thermostat(25.7, 20, "cool");
        assertEquals(6, t.simulateOperation());
        assertEquals("cool", t.getMode());
        assertEquals(19.7, t.currentTemperature);
    }

    @Test
    public void testSimulateOperation3() {
        Thermostat t = new Thermostat(25, 25, "heat");
        assertEquals(0, t.simulateOperation());
        assertEquals("cool", t.getMode());
        assertEquals(25, t.currentTemperature);
    }

    @Test
    public void testSimulateOperation4() {
        Thermostat t = new Thermostat(25, 25, "cool");
        assertEquals(0, t.simulateOperation());
        assertEquals("cool", t.getMode());
        assertEquals(25, t.currentTemperature);
    }

    @Test
    public void testSimulateOperation5() {
        Thermostat t = new Thermostat(25, 25, "test");
        assertEquals(0, t.simulateOperation());
        assertEquals("cool", t.getMode());
        assertEquals(25, t.currentTemperature);
    }

    @Test
    public void testMain() {
        Thermostat t = new Thermostat(20, 37.5, "cool");
        assertEquals(37.5, t.getTargetTemperature());

        t.setTargetTemperature(37.6);
        assertEquals(37.6, t.getTargetTemperature());

        assertEquals("cool", t.getMode());
        assertFalse(t.setMode("test"));

        assertFalse(t.autoCheckConflict());
        assertEquals("heat", t.getMode());
        assertEquals(18, t.simulateOperation());
    }
}