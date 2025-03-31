
#include <bitset>
#include <sstream>
#include <iomanip>

#include <string>

class NumberConverter {
public:
    static std::string decimal_to_binary(int decimal_num);
    static int binary_to_decimal(const std::string& binary_num);
    static std::string decimal_to_octal(int decimal_num);
    static int octal_to_decimal(const std::string& octal_num);
    static std::string decimal_to_hex(int decimal_num);
    static int hex_to_decimal(const std::string& hex_num);
};

std::string NumberConverter::decimal_to_binary(int decimal_num) {
    std::string binary_num = std::bitset<32>(decimal_num).to_string();
    binary_num.erase(0, binary_num.find_first_not_of('0')); 
    return binary_num.empty() ? "0" : binary_num;
}

int NumberConverter::binary_to_decimal(const std::string& binary_num) {
    return std::stoi(binary_num, nullptr, 2);
}

std::string NumberConverter::decimal_to_octal(int decimal_num) {
    std::stringstream ss;
    ss << std::oct << decimal_num;
    return ss.str();
}

int NumberConverter::octal_to_decimal(const std::string& octal_num) {
    return std::stoi(octal_num, nullptr, 8);
}

std::string NumberConverter::decimal_to_hex(int decimal_num) {
    std::stringstream ss;
    ss << std::hex << decimal_num;
    return ss.str();
}

int NumberConverter::hex_to_decimal(const std::string& hex_num) {
    return std::stoi(hex_num, nullptr, 16);
}
