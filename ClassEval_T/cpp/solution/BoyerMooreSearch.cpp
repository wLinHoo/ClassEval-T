#include <string>
#include <vector>

class BoyerMooreSearch {
public:
    BoyerMooreSearch(const std::string& text, const std::string& pattern);

    int match_in_pattern(char c) const;
    int mismatch_in_text(int currentPos) const;
    std::vector<int> bad_character_heuristic() const;

private:
    std::string text;
    std::string pattern;
    int text_len;
    int pat_len;
};

BoyerMooreSearch::BoyerMooreSearch(const std::string& text, const std::string& pattern)
    : text(text), pattern(pattern), text_len(text.size()), pat_len(pattern.size()) {}

int BoyerMooreSearch::match_in_pattern(char c) const {
    for (int i = pat_len - 1; i >= 0; --i) {
        if (c == pattern[i]) {
            return i;
        }
    }
    return -1;
}

int BoyerMooreSearch::mismatch_in_text(int currentPos) const {
    for (int i = pat_len - 1; i >= 0; --i) {
        if (pattern[i] != text[currentPos + i]) {
            return currentPos + i;
        }
    }
    return -1;
}

std::vector<int> BoyerMooreSearch::bad_character_heuristic() const {
    std::vector<int> positions;
    int i = 0;
    while (i <= text_len - pat_len) {
        int mismatch_index = mismatch_in_text(i);
        if (mismatch_index == -1) {
            positions.push_back(i);
            i += 1;  
        }
        else {
            char mismatched_char = text[mismatch_index];
            int match_index = match_in_pattern(mismatched_char);
            if (match_index == -1) {
                i += (mismatch_index - i + 1);
            }
            else {
                i += (mismatch_index - match_index);
            }
        }
    }
    return positions;
}

