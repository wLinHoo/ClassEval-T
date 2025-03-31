import java.net.Inet6Address;
import java.net.InetAddress;
import java.net.UnknownHostException;

public class IpUtil {

    public static boolean isValidIpv6(String ipAddress) {
        try {
            Inet6Address.getByName(ipAddress);
            return true;
        } catch (UnknownHostException e) {
            return false;
        }
    }

    public static String getHostname(String ipAddress) {
        try {
            InetAddress inetAddress = InetAddress.getByName(ipAddress);
            return inetAddress.getHostName();
        } catch (UnknownHostException e) {
            return null;
        }
    }

    public static boolean isValidIpv4(String ipAddress) {
        try {
            InetAddress.getByName(ipAddress);
            return true;
        } catch (UnknownHostException e) {
            return false;
        }
    }

}