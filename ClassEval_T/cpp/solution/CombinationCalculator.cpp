#include <vector>
#include <string>
#include <cmath>
#include <limits>
#include <algorithm>

class CombinationCalculator {
public:
    explicit CombinationCalculator(const std::vector<std::string>& datas);

    static int count(int n, int m);
    static double count_all(int n);

    std::vector<std::vector<std::string>> select(int m) const;
    std::vector<std::vector<std::string>> select_all() const;

    void _select(int dataIndex, std::vector<std::string>& resultList, int resultIndex, std::vector<std::vector<std::string>>& result) const;
    std::vector<std::string> datas;
};

CombinationCalculator::CombinationCalculator(const std::vector<std::string>& datas)
    : datas(datas) {}

int CombinationCalculator::count(int n, int m) {
    if (m == 0 || n == m) {
        return 1;
    }
    return std::tgamma(n + 1) / (std::tgamma(m + 1) * std::tgamma(n - m + 1));
}

double CombinationCalculator::count_all(int n) {
    if (n < 0) {
        return std::numeric_limits<double>::quiet_NaN();
    }
    if (n > 63) {
        return std::numeric_limits<double>::infinity();
    }
    return (n != 63) ? (1 << n) - 1 : std::numeric_limits<double>::infinity();
}

std::vector<std::vector<std::string>> CombinationCalculator::select(int m) const {
    std::vector<std::vector<std::string>> result;
    if (m < 0 || m > static_cast<int>(datas.size())) {
        return result;
    }
    std::vector<std::string> resultList(m);
    _select(0, resultList, 0, result);
    return result;
}

std::vector<std::vector<std::string>> CombinationCalculator::select_all() const {
    std::vector<std::vector<std::string>> result;
    for (int i = 1; i <= static_cast<int>(datas.size()); ++i) {
        std::vector<std::vector<std::string>> combinations = select(i);
        result.insert(result.end(), combinations.begin(), combinations.end());
    }
    return result;
}

void CombinationCalculator::_select(int dataIndex, std::vector<std::string>& resultList, int resultIndex, std::vector<std::vector<std::string>>& result) const {
    if (resultIndex == resultList.size()) {
        result.push_back(resultList);
        return;
    }

    for (int i = dataIndex; i <= static_cast<int>(datas.size()) - (resultList.size() - resultIndex); ++i) {
        resultList[resultIndex] = datas[i];
        _select(i + 1, resultList, resultIndex + 1, result);
    }
}
