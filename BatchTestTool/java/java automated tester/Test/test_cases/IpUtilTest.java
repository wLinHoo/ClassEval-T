package test_cases;
import to_be_tested.IpUtil;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertNull;

import org.junit.jupiter.api.Test;

import java.net.UnknownHostException;

public class IPUtilTest {

    @Test
    public void testIsValidIpv4_1() {
        boolean result = IPUtil.isValidIpv4("192.168.0.123");
        assertEquals(true, result);
    }

    @Test
    public void testIsValidIpv4_2() {
        boolean result = IPUtil.isValidIpv4("10.10.10.10");
        assertEquals(true, result);
    }

    @Test
    public void testIsValidIpv4_3() {
        boolean result = IPUtil.isValidIpv4("0.0.0.0");
        assertEquals(true, result);
    }

    @Test
    public void testIsValidIpv4_4() {
        boolean result = IPUtil.isValidIpv4("abc.168.0.123");
        assertEquals(false, result);
    }

    @Test
    public void testIsValidIpv4_5() {
        boolean result = IPUtil.isValidIpv4("256.0.0.0");
        assertEquals(false, result);
    }

    @Test
    public void testIsValidIpv6_1() {
        boolean result = IPUtil.isValidIpv6("2001:0db8:85a3:0000:0000:8a2e:0370:7334");
        assertEquals(true, result);
    }

    @Test
    public void testIsValidIpv6_2() {
        boolean result = IPUtil.isValidIpv6("2001:0db8:85a3:::8a2e:0370:7334");
        assertEquals(false, result);
    }

    @Test
    public void testIsValidIpv6_3() {
        boolean result = IPUtil.isValidIpv6("2001:0db8:85a3:2001:llll:8a2e:0370:7334");
        assertEquals(false, result);
    }

    @Test
    public void testIsValidIpv6_4() {
        boolean result = IPUtil.isValidIpv6("2001:0db8:85a3:llll:llll:8a2e:0370:7334");
        assertEquals(false, result);
    }

    @Test
    public void testIsValidIpv6_5() {
        boolean result = IPUtil.isValidIpv6("2001:0db8:85a3::llll:8a2e:0370:7334");
        assertEquals(false, result);
    }

    @Test
    public void testGetHostname_1() {
        String result = IPUtil.getHostname("110.242.68.3");
        assertNull(result);
    }

    @Test
    public void testGetHostname_2() {
        String result = IPUtil.getHostname("10.0.0.1");
        assertNull(result);
    }

    @Test
    public void testGetHostname_3() throws UnknownHostException {
        String expectedHostname = java.net.InetAddress.getLocalHost().getHostName();
        String result = IPUtil.getHostname("0.0.0.0");
        assertEquals(expectedHostname, result);
    }


    @Test
    public void testGetHostname_4() {
        String result = IPUtil.getHostname("0.0.0.1");
        assertNull(result);
    }

    @Test
    public void testGetHostname_5() {
        String result = IPUtil.getHostname("0.0.0.2");
        assertNull(result);
    }

    @Test
    public void testIPUtil() {
        boolean ipv4Result = IPUtil.isValidIpv4("192.168.0.123");
        assertEquals(true, ipv4Result);

        boolean ipv6Result = IPUtil.isValidIpv6("2001:0db8:85a3:0000:0000:8a2e:0370:7334");
        assertEquals(true, ipv6Result);

        String hostnameResult = IPUtil.getHostname("110.242.68.3");
        assertNull(hostnameResult);
    }
}
