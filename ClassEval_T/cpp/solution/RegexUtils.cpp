#include <string>
#include <vector>
#include <regex>

class RegexUtils {
public:
    bool match(const std::string& pattern, const std::string& text);
    std::vector<std::string> findall(const std::string& pattern, const std::string& text);
    std::vector<std::string> split(const std::string& pattern, const std::string& text);
    std::string sub(const std::string& pattern, const std::string& replacement, const std::string& text);
    std::string generate_email_pattern();
    std::string generate_phone_number_pattern();
    std::string generate_split_sentences_pattern();
    std::vector<std::string> split_sentences(const std::string& text);
    bool validate_phone_number(const std::string& phone_number);
    std::vector<std::string> extract_email(const std::string& text);
};

bool RegexUtils::match(const std::string& pattern, const std::string& text) {
    std::regex re(pattern);
    std::smatch match;
    return std::regex_search(text, match, re);
}


std::vector<std::string> RegexUtils::findall(const std::string& pattern, const std::string& text) {
    std::regex re(pattern);
    std::sregex_iterator begin(text.begin(), text.end(), re);
    std::sregex_iterator end;
    std::vector<std::string> results;
    for (std::sregex_iterator i = begin; i != end; ++i) {
        results.push_back(i->str());
    }
    return results;
}


std::vector<std::string> RegexUtils::split(const std::string& pattern, const std::string& text) {
    std::regex re(pattern);
    std::sregex_token_iterator it(text.begin(), text.end(), re, -1);
    std::sregex_token_iterator reg_end;

    std::vector<std::string> result;
    for (; it != reg_end; ++it) {

        result.push_back(it->str());
    }
    
    
    if (text.empty()) {
        return result;
    }
    if (result[0] != text)
    {
        result.push_back("");
    }
    


    return result;
}

std::string RegexUtils::sub(const std::string& pattern, const std::string& replacement, const std::string& text) {
    std::regex re(pattern);
    return std::regex_replace(text, re, replacement);
}

std::string RegexUtils::generate_email_pattern() {
    return R"(\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b)";
}

std::string RegexUtils::generate_phone_number_pattern() {
    return R"(\b\d{3}-\d{3}-\d{4}\b)";
}

std::string RegexUtils::generate_split_sentences_pattern() {
    return R"([.!?][\s]{1,2}(?=[A-Z]))";
}

std::vector<std::string> RegexUtils::split_sentences(const std::string& text) {
    std::string pattern = generate_split_sentences_pattern();
    std::vector<std::string> sentences = split(pattern, text);

    
    if (!sentences.empty() && sentences.front().empty()) {
        sentences.erase(sentences.begin());  
    }
    if (!sentences.empty() && sentences.back().empty()) {
        sentences.pop_back();  
    }

    return sentences;
}

bool RegexUtils::validate_phone_number(const std::string& phone_number) {
    std::string pattern = generate_phone_number_pattern();
    return match(pattern, phone_number);
}

std::vector<std::string> RegexUtils::extract_email(const std::string& text) {
    std::string pattern = generate_email_pattern();
    return findall(pattern, text);
}

