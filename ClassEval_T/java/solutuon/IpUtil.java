package org.example;

import java.net.InetAddress;
import java.net.UnknownHostException;

public class IpUtil {

    public static boolean isValidIpv4(String ipAddress) {
        try {
            InetAddress.getByName(ipAddress);
            return ipAddress.contains(".") && !ipAddress.contains(":");
        } catch (UnknownHostException e) {
            return false;
        }
    }

    public static boolean isValidIpv6(String ipAddress) {
        try {
            InetAddress.getByName(ipAddress);
            return ipAddress.contains(":");
        } catch (UnknownHostException e) {
            return false;
        }
    }

    public static String getHostname(String ipAddress) {
        try {
            InetAddress inetAddress = InetAddress.getByName(ipAddress);

            if ("0.0.0.0".equals(ipAddress)) {
                return InetAddress.getLocalHost().getHostName();
            }

            String hostname = inetAddress.getCanonicalHostName();
            if (hostname.equals(ipAddress)) {
                return null;
            }
            return hostname;
        } catch (UnknownHostException e) {
            return null;
        }
    }
}
