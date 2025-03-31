#include <vector>
#include <string>

class ArrangementCalculator {
public:
    ArrangementCalculator(const std::vector<std::string>& datas);
    static int count(int n, int m = -1);
    static int count_all(int n);
    std::vector<std::vector<std::string>> select(int m = -1) const;
    std::vector<std::vector<std::string>> select_all() const;
    static int factorial(int n);

private:
    std::vector<std::string> datas;
    void permutations_recursive(std::vector<std::string>& current, std::vector<std::string>& remaining, int m, std::vector<std::vector<std::string>>& result) const;
};

ArrangementCalculator::ArrangementCalculator(const std::vector<std::string>& datas) : datas(datas) {}

int ArrangementCalculator::count(int n, int m) {
    if (m == -1 || n == m) {
        return ArrangementCalculator::factorial(n);
    }
    else {
        return ArrangementCalculator::factorial(n) / ArrangementCalculator::factorial(n - m);
    }
}

int ArrangementCalculator::count_all(int n) {
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        total += ArrangementCalculator::count(n, i);
    }
    return total;
}

void ArrangementCalculator::permutations_recursive(std::vector<std::string>& current, std::vector<std::string>& remaining, int m, std::vector<std::vector<std::string>>& result) const {
    if (current.size() == m) {
        result.push_back(current);
    }
    else {
        for (size_t i = 0; i < remaining.size(); ++i) {
            std::vector<std::string> new_current = current;
            new_current.push_back(remaining[i]);
            std::vector<std::string> new_remaining = remaining;
            new_remaining.erase(new_remaining.begin() + i);
            permutations_recursive(new_current, new_remaining, m, result);
        }
    }
}

std::vector<std::vector<std::string>> ArrangementCalculator::select(int m) const {
    std::vector<std::vector<std::string>> result;
    if (m == -1) {
        m = datas.size();
    }

    std::vector<std::string> current;
    std::vector<std::string> remaining = datas;

    permutations_recursive(current, remaining, m, result);

    return result;
}

std::vector<std::vector<std::string>> ArrangementCalculator::select_all() const {
    std::vector<std::vector<std::string>> result;
    for (size_t i = 1; i <= datas.size(); ++i) {
        std::vector<std::vector<std::string>> partial_result = select(i);
        result.insert(result.end(), partial_result.begin(), partial_result.end());
    }
    return result;
}

int ArrangementCalculator::factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}
