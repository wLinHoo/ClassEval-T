package org.example;

import org.junit.jupiter.api.Test;
import java.util.Arrays;
import java.util.List;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class IPAddressTest {

    @Test
    public void testIsValid1() {
        IPAddress ipaddress = new IPAddress("10.10.10.10");
        assertEquals(true, ipaddress.isValid());
    }

    @Test
    public void testIsValid2() {
        IPAddress ipaddress = new IPAddress("-1.10.10.10");
        assertEquals(false, ipaddress.isValid());
    }

    @Test
    public void testIsValid3() {
        IPAddress ipaddress = new IPAddress("10.10.10");
        assertEquals(false, ipaddress.isValid());
    }

    @Test
    public void testIsValid4() {
        IPAddress ipaddress = new IPAddress("a.10.10.10");
        assertEquals(false, ipaddress.isValid());
    }

    @Test
    public void testIsValid5() {
        IPAddress ipaddress = new IPAddress("300.10.10.10");
        assertEquals(false, ipaddress.isValid());
    }

    @Test
    public void testGetOctets1() {
        IPAddress ipaddress = new IPAddress("10.10.10.10");
        List<String> expected = Arrays.asList("10", "10", "10", "10");
        assertEquals(expected, ipaddress.getOctets());
    }

    @Test
    public void testGetOctets2() {
        IPAddress ipaddress = new IPAddress("a.10.10.10");
        List<String> expected = Arrays.asList();
        assertEquals(expected, ipaddress.getOctets());
    }

    @Test
    public void testGetOctets3() {
        IPAddress ipaddress = new IPAddress("-1.10.10.10");
        List<String> expected = Arrays.asList();
        assertEquals(expected, ipaddress.getOctets());
    }

    @Test
    public void testGetOctets4() {
        IPAddress ipaddress = new IPAddress("300.10.10.10");
        List<String> expected = Arrays.asList();
        assertEquals(expected, ipaddress.getOctets());
    }

    @Test
    public void testGetOctets5() {
        IPAddress ipaddress = new IPAddress(".10.10.10");
        List<String> expected = Arrays.asList();
        assertEquals(expected, ipaddress.getOctets());
    }

    @Test
    public void testGetBinary1() {
        IPAddress ipaddress = new IPAddress("10.10.10.10");
        assertEquals("00001010.00001010.00001010.00001010", ipaddress.getBinary());
    }

    @Test
    public void testGetBinary2() {
        IPAddress ipaddress = new IPAddress("a.10.10.10");
        assertEquals("", ipaddress.getBinary());
    }

    @Test
    public void testGetBinary3() {
        IPAddress ipaddress = new IPAddress("-1.10.10.10");
        assertEquals("", ipaddress.getBinary());
    }

    @Test
    public void testGetBinary4() {
        IPAddress ipaddress = new IPAddress("300.10.10.10");
        assertEquals("", ipaddress.getBinary());
    }

    @Test
    public void testGetBinary5() {
        IPAddress ipaddress = new IPAddress(".10.10.10");
        assertEquals("", ipaddress.getBinary());
    }
}