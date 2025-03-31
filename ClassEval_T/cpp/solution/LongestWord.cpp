
#include <sstream>
#include <cctype>
#include <algorithm>

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <regex>

class LongestWord {
public:
    LongestWord();
    void add_word(const std::string& word);
    std::string find_longest_word(const std::string& sentence) const;
    std::vector<std::string> get_word_list() const; 

private:
    std::vector<std::string> word_list;
};

LongestWord::LongestWord() : word_list() {}

void LongestWord::add_word(const std::string& word) {
    word_list.push_back(word);
}

std::string LongestWord::find_longest_word(const std::string& sentence) const {
    std::string longest_word;
    std::string lower_sentence = sentence;

    
    std::transform(lower_sentence.begin(), lower_sentence.end(), lower_sentence.begin(), ::tolower);

    
    lower_sentence.erase(std::remove_if(lower_sentence.begin(), lower_sentence.end(),
        [](unsigned char c) { return std::ispunct(c); }), lower_sentence.end());

    
    std::istringstream stream(lower_sentence);
    std::string word;

    while (stream >> word) {
        if (std::find(word_list.begin(), word_list.end(), word) != word_list.end() &&
            word.length() > longest_word.length()) {
            longest_word = word;
        }
    }

    return longest_word;
}

std::vector<std::string> LongestWord::get_word_list() const {
    return word_list; 
}
