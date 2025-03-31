
#include <cctype>
#include <vector>

#include <string>
#include <vector>

class DecryptionUtils {
public:
    DecryptionUtils(const std::string& key);

    std::string caesar_decipher(const std::string& ciphertext, int shift);
    std::string vigenere_decipher(const std::string& ciphertext);
    std::string rail_fence_decipher(const std::string& encrypted_text, int rails);

private:
    std::string key_;
};

DecryptionUtils::DecryptionUtils(const std::string& key) : key_(key) {}

std::string DecryptionUtils::caesar_decipher(const std::string& ciphertext, int shift) {
    shift = shift % 26; 
    std::string plaintext;
    for (char c : ciphertext) {
        if (std::isalpha(c)) {
            char base = std::isupper(c) ? 'A' : 'a';
            char shifted_char = (c - base - shift + 26) % 26 + base;
            plaintext += shifted_char;
        }
        else {
            plaintext += c;
        }
    }
    return plaintext;
}

std::string DecryptionUtils::vigenere_decipher(const std::string& ciphertext) {
    std::string decrypted_text;
    size_t key_length = key_.length();
    size_t key_index = 0;

    for (char c : ciphertext) {
        if (std::isalpha(c)) {
            int shift = std::tolower(key_[key_index % key_length]) - 'a';
            char base = std::islower(c) ? 'a' : 'A';
            char decrypted_char = (std::tolower(c) - 'a' - shift + 26) % 26 + 'a';
            decrypted_text += std::isupper(c) ? std::toupper(decrypted_char) : decrypted_char;
            ++key_index;
        }
        else {
            decrypted_text += c;
        }
    }
    return decrypted_text;
}

std::string DecryptionUtils::rail_fence_decipher(const std::string& encrypted_text, int rails) {
    std::string plain_text;
    size_t n = encrypted_text.length();
    if (rails <= 1) return encrypted_text;

    std::vector<std::string> fence(rails, std::string(n, '\n'));

    int direction = -1;
    int row = 0;
    int col = 0;

    for (size_t i = 0; i < n; ++i) {
        if (row == 0 || row == rails - 1) {
            direction = -direction;
        }
        fence[row][col++] = '*';
        row += direction;
    }

    size_t index = 0;
    for (int r = 0; r < rails; ++r) {
        for (int c = 0; c < n; ++c) {
            if (fence[r][c] == '*') {
                fence[r][c] = encrypted_text[index++];
            }
        }
    }

    direction = -1;
    row = 0;
    col = 0;

    for (size_t i = 0; i < n; ++i) {
        if (row == 0 || row == rails - 1) {
            direction = -direction;
        }
        plain_text += fence[row][col++];
        row += direction;
    }

    return plain_text;
}
