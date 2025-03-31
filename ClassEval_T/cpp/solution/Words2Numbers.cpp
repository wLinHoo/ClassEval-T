#include <sstream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <stdexcept>

#include <string>
#include <unordered_map>
#include <vector>

class Words2Numbers {
public:
    Words2Numbers();
    std::string text2int(const std::string& textnum);
    bool is_valid_input(const std::string& textnum) const;

private:
    std::unordered_map<std::string, std::pair<int, int>> numwords;
    std::vector<std::string> units;
    std::vector<std::string> tens;
    std::vector<std::string> scales;
    std::unordered_map<std::string, int> ordinal_words;
    std::vector<std::pair<std::string, std::string>> ordinal_endings;
};


Words2Numbers::Words2Numbers() {
    units = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
             "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
             "eighteen", "nineteen" };

    tens = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

    scales = { "hundred", "thousand", "million", "billion", "trillion" };

    numwords["and"] = { 1, 0 };
    for (size_t idx = 0; idx < units.size(); ++idx) {
        numwords[units[idx]] = { 1, static_cast<int>(idx) };
    }
    for (size_t idx = 0; idx < tens.size(); ++idx) {
        numwords[tens[idx]] = { 1, static_cast<int>(idx) * 10 };
    }
    for (size_t idx = 0; idx < scales.size(); ++idx) {
        numwords[scales[idx]] = { static_cast<int>(std::pow(10, idx * 3)), 0 };
    }
    numwords["hundred"] = { 100,0 };
    ordinal_words = { {"first", 1}, {"second", 2}, {"third", 3}, {"fifth", 5}, {"eighth", 8},
                     {"ninth", 9}, {"twelfth", 12} };
    ordinal_endings = { {"ieth", "y"}, {"th", ""} };
}

std::string Words2Numbers::text2int(const std::string& textnum) {
    std::string text = textnum;
    std::replace(text.begin(), text.end(), '-', ' ');

    int current = 0, result = 0;
    std::string curstring;

    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        auto it = ordinal_words.find(word);
        if (it != ordinal_words.end()) {
            int scale = 1, increment = it->second;
            current = current * scale + increment;
        }
        else {
            for (const auto& ending : ordinal_endings) {
                if (word.size() > ending.first.size() &&
                    word.compare(word.size() - ending.first.size(), ending.first.size(), ending.first) == 0) {
                    word = word.substr(0, word.size() - ending.first.size()) + ending.second;
                }
            }

            auto numword_it = numwords.find(word);
            if (numword_it == numwords.end()) {
                if (current > 0) {
                    result += current;
                    current = 0;
                }
                curstring += word + " ";
            }
            else {
                auto [scale, increment] = numword_it->second;
                if (scale == 1) {
                    current += increment;
                }
                else {
                    current *= scale;
                    result += current;
                    current = 0;
                }
            }
        }
    }

    if (current > 0) {
        result += current;
    }

    curstring += std::to_string(result);
    return curstring;
}

bool Words2Numbers::is_valid_input(const std::string& textnum) const {
    std::string text = textnum;
    std::replace(text.begin(), text.end(), '-', ' ');

    std::istringstream iss(text);
    std::string word;
    while (iss >> word) {
        if (ordinal_words.find(word) != ordinal_words.end()) {
            continue;
        }
        else {
            for (const auto& ending : ordinal_endings) {
                if (word.size() > ending.first.size() &&
                    word.compare(word.size() - ending.first.size(), ending.first.size(), ending.first) == 0) {
                    word = word.substr(0, word.size() - ending.first.size()) + ending.second;
                }
            }

            if (numwords.find(word) == numwords.end()) {
                return false;
            }
        }
    }

    return true;
}
