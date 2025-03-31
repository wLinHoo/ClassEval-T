
#include <boost/regex.hpp>
#include <sstream>
#include <algorithm>
#include <cctype>

#include <string>
#include <vector>

class SplitSentence {
public:
    std::vector<std::string> split_sentences(const std::string& sentences_string);
    int count_words(const std::string& sentence);
    int process_text_file(const std::string& sentences_string);
};


std::vector<std::string> SplitSentence::split_sentences(const std::string& sentences_string) {
    std::vector<std::string> sentences;
    boost::regex regex(R"((?<!\w\.\w.)(?<![A-Z][a-z]\.)(?<=\.|\?)\s)");
    boost::sregex_token_iterator iter(sentences_string.begin(), sentences_string.end(), regex, -1);
    boost::sregex_token_iterator end;

    for (; iter != end; ++iter) {
        std::string sentence = iter->str();
        
        if (!sentence.empty()) {
            
            sentence.erase(std::find_if(sentence.rbegin(), sentence.rend(), [](char ch) {
                return !std::isspace(ch);
                }).base(), sentence.end());
            if (!sentence.empty()) {
                sentences.push_back(sentence);
            }
        }
    }

    return sentences;
}


int SplitSentence::count_words(const std::string& sentence) {
    std::string cleaned_sentence;
    std::remove_copy_if(sentence.begin(), sentence.end(), std::back_inserter(cleaned_sentence),
        [](char c) { return !std::isalpha(c) && !std::isspace(c); });

    std::istringstream stream(cleaned_sentence);
    std::string word;
    int count = 0;

    while (stream >> word) {
        ++count;
    }

    return count;
}


int SplitSentence::process_text_file(const std::string& sentences_string) {
    std::vector<std::string> sentences = split_sentences(sentences_string);
    int max_count = 0;

    for (const auto& sentence : sentences) {
        int count = count_words(sentence);
        if (count > max_count) {
            max_count = count;
        }
    }

    return max_count;
}
