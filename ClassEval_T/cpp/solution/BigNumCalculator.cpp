
#include <algorithm>
#include <vector>
#include <sstream>


#include <string>

class BigNumCalculator {
public:
    static std::string add(const std::string& num1, const std::string& num2);
    static std::string subtract(const std::string& num1, const std::string& num2);
    static std::string multiply(const std::string& num1, const std::string& num2);
};

std::string BigNumCalculator::add(const std::string& num1, const std::string& num2) {
    int max_length = std::max(num1.size(), num2.size());
    std::string num1_padded = std::string(max_length - num1.size(), '0') + num1;
    std::string num2_padded = std::string(max_length - num2.size(), '0') + num2;

    int carry = 0;
    std::string result;
    for (int i = max_length - 1; i >= 0; --i) {
        int digit_sum = (num1_padded[i] - '0') + (num2_padded[i] - '0') + carry;
        carry = digit_sum / 10;
        int digit = digit_sum % 10;
        result.insert(result.begin(), digit + '0');
    }

    if (carry > 0) {
        result.insert(result.begin(), carry + '0');
    }

    return result;
}

std::string BigNumCalculator::subtract(const std::string& num1, const std::string& num2) {
    std::string num1_local = num1;
    std::string num2_local = num2;
    bool negative = false;

    if (num1_local.size() < num2_local.size() || (num1_local.size() == num2_local.size() && num1_local < num2_local)) {
        std::swap(num1_local, num2_local);
        negative = true;
    }

    int max_length = std::max(num1_local.size(), num2_local.size());
    num1_local = std::string(max_length - num1_local.size(), '0') + num1_local;
    num2_local = std::string(max_length - num2_local.size(), '0') + num2_local;

    int borrow = 0;
    std::string result;
    for (int i = max_length - 1; i >= 0; --i) {
        int digit_diff = (num1_local[i] - '0') - (num2_local[i] - '0') - borrow;

        if (digit_diff < 0) {
            digit_diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        result.insert(result.begin(), digit_diff + '0');
    }

    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    if (negative) {
        result.insert(result.begin(), '-');
    }

    return result;
}

std::string BigNumCalculator::multiply(const std::string& num1, const std::string& num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    std::vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int p1 = i + j;
            int p2 = i + j + 1;
            int total = mul + result[p2];

            result[p1] += total / 10;
            result[p2] = total % 10;
        }
    }

    std::ostringstream oss;
    bool leadingZero = true;
    for (int num : result) {
        if (num == 0 && leadingZero) continue;
        leadingZero = false;
        oss << num;
    }

    return oss.str().empty() ? "0" : oss.str();
}
