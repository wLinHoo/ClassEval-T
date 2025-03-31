
#include <algorithm>
#include <bitset>
#include <sstream>
#include <stdexcept>

#include <string>
#include <unordered_map>

class BinaryDataProcessor {
public:
    BinaryDataProcessor(const std::string& binary_string);
    void clean_non_binary_chars();
    std::unordered_map<std::string, double> calculate_binary_info();
    std::string convert_to_ascii();
    std::string convert_to_utf8();

    std::string binary_string;
};

BinaryDataProcessor::BinaryDataProcessor(const std::string& binary_string) {
    this->binary_string = binary_string;
    clean_non_binary_chars();
}

void BinaryDataProcessor::clean_non_binary_chars() {
    binary_string.erase(std::remove_if(binary_string.begin(), binary_string.end(),
        [](char c) { return c != '0' && c != '1'; }), binary_string.end());
}

std::unordered_map<std::string, double> BinaryDataProcessor::calculate_binary_info() {
    int zeroes_count = std::count(binary_string.begin(), binary_string.end(), '0');
    int ones_count = binary_string.size() - zeroes_count;
    int total_length = binary_string.size();

    double zeroes_percentage = static_cast<double>(zeroes_count) / total_length;
    double ones_percentage = static_cast<double>(ones_count) / total_length;

    return {
        {"Zeroes", zeroes_percentage},
        {"Ones", ones_percentage},
        {"Bit length", static_cast<double>(total_length)}
    };
}

std::string BinaryDataProcessor::convert_to_ascii() {
    std::stringstream ss;
    for (size_t i = 0; i < binary_string.size(); i += 8) {
        std::bitset<8> byte(binary_string.substr(i, 8));
        ss << static_cast<char>(byte.to_ulong());
    }
    return ss.str();
}

std::string BinaryDataProcessor::convert_to_utf8() {
    return convert_to_ascii(); 
}
