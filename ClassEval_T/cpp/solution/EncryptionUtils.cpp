
#include <cctype>
#include <stdexcept>

#include <string>

class EncryptionUtils {
public:
    EncryptionUtils(const std::string& key);
    std::string caesar_cipher(const std::string& plaintext, int shift) const;
    std::string vigenere_cipher(const std::string& plain_text) const;
    std::string rail_fence_cipher(const std::string& plain_text, int rails) const;

private:
    std::string key;
};



EncryptionUtils::EncryptionUtils(const std::string& key) : key(key) {}


std::string EncryptionUtils::caesar_cipher(const std::string& plaintext, int shift) const {
    std::string ciphertext;
    for (char ch : plaintext) {
        if (std::isalpha(ch)) {
            int ascii_offset = std::isupper(ch) ? 65 : 97;
            char shifted_char = static_cast<char>((std::tolower(ch) - 'a' + shift) % 26 + ascii_offset);
            ciphertext += shifted_char;
        }
        else {
            ciphertext += ch;
        }
    }
    return ciphertext;
}


std::string EncryptionUtils::vigenere_cipher(const std::string& plain_text) const {
    std::string encrypted_text;
    size_t key_index = 0;
    for (char ch : plain_text) {
        if (std::isalpha(ch)) {
            int shift = std::tolower(key[key_index % key.length()]) - 'a';
            char encrypted_char = static_cast<char>((std::tolower(ch) - 'a' + shift) % 26 + 'a');
            encrypted_text += std::isupper(ch) ? std::toupper(encrypted_char) : encrypted_char;
            key_index++;
        }
        else {
            encrypted_text += ch;
        }
    }
    return encrypted_text;
}


std::string EncryptionUtils::rail_fence_cipher(const std::string& plain_text, int rails) const {
    if (rails <= 0) {
        throw std::invalid_argument("Rails must be greater than zero.");
    }
    const int N = 101;
    std::string fence[N];
    int direction = -1;
    int row = 0;

    for (char ch : plain_text) {
        if (row == 0 || row == rails - 1) {
            direction = -direction;
        }

        fence[row] += ch;
        row += direction;
    }

    std::string encrypted_text;
    for (int i = 0; i < rails; ++i) {
        encrypted_text += fence[i];
    }

    return encrypted_text;
}
