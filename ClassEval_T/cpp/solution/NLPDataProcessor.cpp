
#include <algorithm> 
#include <sstream>

#include <vector>
#include <string>

class NLPDataProcessor {
public:
    std::vector<std::string> construct_stop_word_list();
    std::vector<std::vector<std::string>> remove_stop_words(
        const std::vector<std::string>& string_list,
        const std::vector<std::string>& stop_word_list);
    std::vector<std::vector<std::string>> process(const std::vector<std::string>& string_list);
};

std::vector<std::string> NLPDataProcessor::construct_stop_word_list() {
    return { "a", "an", "the" };
}

std::vector<std::vector<std::string>> NLPDataProcessor::remove_stop_words(
    const std::vector<std::string>& string_list,
    const std::vector<std::string>& stop_word_list) {

    std::vector<std::vector<std::string>> answer;

    for (const auto& str : string_list) {
        std::vector<std::string> string_split;
        std::string word;
        std::istringstream stream(str);

        
        while (stream >> word) {
            if (std::find(stop_word_list.begin(), stop_word_list.end(), word) == stop_word_list.end()) {
                string_split.push_back(word);
            }
        }

        answer.push_back(string_split);
    }

    return answer;
}


std::vector<std::vector<std::string>> NLPDataProcessor::process(const std::vector<std::string>& string_list) {
    std::vector<std::string> stop_word_list = construct_stop_word_list();
    return remove_stop_words(string_list, stop_word_list);
}
