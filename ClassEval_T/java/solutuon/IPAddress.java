package org.example;

import java.util.ArrayList;
import java.util.List;

public class IPAddress {
    private String ipAddress;

    public IPAddress(String ipAddress) {
        this.ipAddress = ipAddress;
    }

    public boolean isValid() {
        String[] octets = ipAddress.split("\\.");
        if (octets.length != 4) {
            return false;
        }
        for (String octet : octets) {
            try {
                int num = Integer.parseInt(octet);
                if (num < 0 || num > 255) {
                    return false;
                }
            } catch (NumberFormatException e) {
                return false;
            }
        }
        return true;
    }

    public List<String> getOctets() {
        List<String> octetsList = new ArrayList<>();
        if (isValid()) {
            String[] octets = ipAddress.split("\\.");
            for (String octet : octets) {
                octetsList.add(octet);
            }
        }
        return octetsList;
    }

    public String getBinary() {
        if (isValid()) {
            StringBuilder binaryString = new StringBuilder();
            String[] octets = ipAddress.split("\\.");
            for (String octet : octets) {
                int num = Integer.parseInt(octet);
                String binaryOctet = String.format("%08d", Integer.parseInt(Integer.toBinaryString(num)));
                binaryString.append(binaryOctet).append(".");
            }
            return binaryString.substring(0, binaryString.length() - 1);
        }
        return "";
    }
}