
#include <algorithm>
#include <cctype>
#include <map>
#include <regex>
#include <string>
#include <vector>
#include <locale>

#include <vector>
#include <string>
#include <map>

class NLPDataProcessor2 {
public:
    std::vector<std::vector<std::string>> process_data(const std::vector<std::string>& string_list);
    std::map<std::string, int> calculate_word_frequency(const std::vector<std::vector<std::string>>& words_list);
    std::map<std::string, int> process(const std::vector<std::string>& string_list);
};


std::string to_lowercase(const std::string& str) {
    std::string result;
    std::locale loc;
    for (char c : str) {
        result += std::tolower(c, loc);
    }
    return result;
}


std::string remove_non_alpha(const std::string& str) {
    std::string result;
    std::locale loc;
    for (char c : str) {
        if (std::isalpha(c, loc) || std::isspace(c, loc)) {
            result += c;
        }
    }
    return result;
}

std::vector<std::vector<std::string>> NLPDataProcessor2::process_data(const std::vector<std::string>& string_list) {
    std::vector<std::vector<std::string>> words_list;
    std::regex word_regex("\\s+");

    for (const auto& str : string_list) {
        std::string processed_string = to_lowercase(remove_non_alpha(str));
        std::sregex_token_iterator iter(processed_string.begin(), processed_string.end(), word_regex, -1);
        std::sregex_token_iterator end;

        std::vector<std::string> words;
        for (; iter != end; ++iter) {
            if (!iter->str().empty()) {  
                words.push_back(iter->str());
            }
        }
        words_list.push_back(words);
    }

    return words_list;
}

std::map<std::string, int> first_appear;

int cmp(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) 
{
    if (a.second == b.second)
    {
        return first_appear[a.first] < first_appear[b.first];
    }
    return b.second < a.second;
}

std::map<std::string, int> NLPDataProcessor2::calculate_word_frequency(const std::vector<std::vector<std::string>>& words_list) {
    std::map<std::string, int> word_frequency;
    first_appear.clear();
    int js = 0;
    for (const auto& words : words_list) {
        for (const auto& word : words) {
            if (!word_frequency[word])
            {
                first_appear[word] = ++js;
            }
            word_frequency[word]++;
        }
    }

    std::vector<std::pair<std::string, int>> sorted_word_frequency(word_frequency.begin(), word_frequency.end());
    std::sort(sorted_word_frequency.begin(), sorted_word_frequency.end(),cmp);

    std::map<std::string, int> top_5_word_frequency;
    for (size_t i = 0; i < std::min<size_t>(5, sorted_word_frequency.size()); ++i) {
        top_5_word_frequency[sorted_word_frequency[i].first] = sorted_word_frequency[i].second;
    }

    return top_5_word_frequency;
}

std::map<std::string, int> NLPDataProcessor2::process(const std::vector<std::string>& string_list) {
    std::vector<std::vector<std::string>> words_list = process_data(string_list);
    return calculate_word_frequency(words_list);
}
