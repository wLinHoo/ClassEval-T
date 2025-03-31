
#include <sstream>
#include <iomanip>
#include <bitset>

#include <string>
#include <vector>

class IPAddress {
public:
    explicit IPAddress(const std::string& ip_address);
    bool is_valid() const;
    std::vector<std::string> get_octets() const;
    std::string get_binary() const;

private:
    std::string ip_address;
    bool is_valid_octet(const std::string& octet) const;
};

IPAddress::IPAddress(const std::string& ip_address) : ip_address(ip_address) {}

bool IPAddress::is_valid() const {
    std::stringstream ss(ip_address);
    std::string octet;
    std::vector<std::string> octets;

    while (std::getline(ss, octet, '.')) {
        octets.push_back(octet);
    }

    if (octets.size() != 4) {
        return false;
    }

    for (const std::string& octet : octets) {
        if (!is_valid_octet(octet)) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> IPAddress::get_octets() const {
    if (is_valid()) {
        std::stringstream ss(ip_address);
        std::string octet;
        std::vector<std::string> octets;

        while (std::getline(ss, octet, '.')) {
            octets.push_back(octet);
        }

        return octets;
    }
    else {
        return {};
    }
}

std::string IPAddress::get_binary() const {
    if (is_valid()) {
        std::stringstream result;
        std::vector<std::string> octets = get_octets();

        for (size_t i = 0; i < octets.size(); ++i) {
            int num = std::stoi(octets[i]);
            if (i > 0) {
                result << '.';
            }
            result << std::setw(8) << std::setfill('0') << std::bitset<8>(num);
        }
        return result.str();
    }
    else {
        return "";
    }
}

bool IPAddress::is_valid_octet(const std::string& octet) const {
    if (octet.empty() || octet.size() > 3) {
        return false;
    }

    for (char c : octet) {
        if (!isdigit(c)) {
            return false;
        }
    }

    int value = std::stoi(octet);
    return value >= 0 && value <= 255;
}
