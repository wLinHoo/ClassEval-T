
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#include <iostream>
#include <cstring>


#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Iphlpapi.lib")

#include <string>

class IpUtil {
public:
    static bool is_valid_ipv4(const std::string& ip_address);
    static bool is_valid_ipv6(const std::string& ip_address);
    static std::string get_hostname(const std::string& ip_address);
};

bool IpUtil::is_valid_ipv4(const std::string& ip_address) {
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, ip_address.c_str(), &(sa.sin_addr));
    return result == 1;
}

bool IpUtil::is_valid_ipv6(const std::string& ip_address) {
    struct sockaddr_in6 sa;
    int result = inet_pton(AF_INET6, ip_address.c_str(), &(sa.sin6_addr));
    return result == 1;
}

std::string IpUtil::get_hostname(const std::string& ip_address) {
    if (ip_address == "0.0.0.0") {
        char hostname[NI_MAXHOST];
        if (gethostname(hostname, sizeof(hostname)) == 0) {
            
            return std::string(hostname);
        }
        else {
            
            return "";
        }
    }

    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address.c_str(), &(sa.sin_addr));

    char host[NI_MAXHOST];

    int result = getnameinfo((struct sockaddr*)&sa, sizeof(sa), host, sizeof(host), nullptr, 0, 0);
    if (result == 0) {
        return std::string(host);
    }
    else {
        return "";
    }
}
