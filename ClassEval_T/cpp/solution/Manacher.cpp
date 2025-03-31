
#include <string>

class Manacher {
private:
    std::string input_string;

public:
    Manacher(const std::string& input_string);
    int palindromic_length(int center, int diff, const std::string& str);
    std::string palindromic_string();
};

Manacher::Manacher(const std::string& input_string) {
    this->input_string = input_string;
}

int Manacher::palindromic_length(int center, int diff, const std::string& str) {
    if ((center - diff == -1) || (center + diff == str.length()) || (str[center - diff] != str[center + diff])) {
        return 0;
    }
    return 1 + palindromic_length(center, diff + 1, str);
}

std::string Manacher::palindromic_string() {
    int max_length = 0;
    std::string new_input_string = "";
    std::string output_string = "";

    for (size_t i = 0; i < input_string.length() - 1; ++i) {
        new_input_string += input_string[i] + std::string("|");
    }
    new_input_string += input_string.back();

    int start = 0;
    for (size_t i = 0; i < new_input_string.length(); ++i) {
        int length = palindromic_length(static_cast<int>(i), 1, new_input_string);

        if (max_length < length) {
            max_length = length;
            start = static_cast<int>(i);
        }
    }

    for (int i = start - max_length; i <= start + max_length; ++i) {
        if (new_input_string[i] != '|') {
            output_string += new_input_string[i];
        }
    }

    return output_string;
}
