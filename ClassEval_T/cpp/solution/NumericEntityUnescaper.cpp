
#include <cctype>
#include <sstream>

#include <string>

class NumericEntityUnescaper {
public:
    NumericEntityUnescaper() = default;
    std::string replace(const std::string& input);
    static bool is_hex_char(char c);
};

std::string NumericEntityUnescaper::replace(const std::string& input) {
    std::string out;
    size_t pos = 0;
    size_t length = input.size();
    if (input.empty())
    {
        return "";
    }
    while (pos < length - 2) {
        if (input[pos] == '&' && input[pos + 1] == '#') {
            size_t start = pos + 2;
            bool is_hex = false;

            if (start < length && (input[start] == 'x' || input[start] == 'X')) {
                ++start;
                is_hex = true;
            }

            if (start == length) {
                return out; 
            }

            size_t end = start;
            while (end < length && is_hex_char(input[end])) {
                ++end;
            }

            if (end < length && input[end] == ';') {
                try {
                    int entity_value;
                    std::string number_str = input.substr(start, end - start);
                    std::stringstream ss;
                    if (is_hex) {
                        ss << std::hex << number_str;
                    }
                    else {
                        ss << number_str;
                    }
                    ss >> entity_value;

                    if (ss.fail()) {
                        return out; 
                    }

                    out.push_back(static_cast<char>(entity_value));
                    pos = end + 1;
                    continue;
                }
                catch (const std::exception&) {
                    return out; 
                }
            }
        }

        out.push_back(input[pos]);
        ++pos;
    }

    return out;
}

bool NumericEntityUnescaper::is_hex_char(char c) {
    return std::isdigit(c) || (std::tolower(c) >= 'a' && std::tolower(c) <= 'f');
}
