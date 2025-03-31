package to_be_tested;

public class IPAddress {

    public String ipAddress;

    public IPAddress(String ipAddress) {
        this.ipAddress = ipAddress;
    }

    public boolean isValid() {
        String[] octets = ipAddress.split("\\.");
        if (octets.length != 4) {
            return false;
        }
        for (String octet : octets) {
            if (!octet.matches("\\d+") || Integer.parseInt(octet) < 0 || Integer.parseInt(octet) > 255) {
                return false;
            }
        }
        return true;
    }

    public String[] getOctets() {
        if (isValid()) {
            return ipAddress.split("\\.");
        } else {
            return new String[0];
        }
    }

    public String getBinary() {
        if (isValid()) {
            StringBuilder binaryOctets = new StringBuilder();
            for (String octet : getOctets()) {
                binaryOctets.append(Integer.toBinaryString(Integer.parseInt(octet)));
            }
            return binaryOctets.toString();
        } else {
            return "";
        }
    }
}
