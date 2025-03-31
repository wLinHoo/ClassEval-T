
#include <stdexcept>
#include <algorithm>
#include <numeric>

#include <vector>
#include <utility>

class MetricsCalculator2 {
public:
    static std::pair<double, std::vector<double>> mrr(const std::vector<std::pair<std::vector<int>, int>>& data);
    static std::pair<double, std::vector<double>> map(const std::vector<std::pair<std::vector<int>, int>>& data);
};

namespace {
    double calculate_mrr(const std::vector<int>& vec, int k) {
        auto it = std::find(vec.begin(), vec.end(), 1);
        if (it == vec.end()) return 0.0;
        return 1.0 / (std::distance(vec.begin(), it) + 1);
    }

    double calculate_map(const std::vector<int>& vec, int k) {
        double sum = 0.0;
        int count = 0;
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] == 1) {
                ++count;
                sum += count / static_cast<double>(i + 1);
            }
        }
        return count ? sum / count : 0.0;
    }
}

std::pair<double, std::vector<double>> MetricsCalculator2::mrr(const std::vector<std::pair<std::vector<int>, int>>& data) {
    if (data.empty()) return { 0.0, std::vector<double>{0.0} };

    double sum_mrr = 0.0;
    std::vector<double> individual_mrr;

    for (const auto& [vec, k] : data) {
        if (k <= 0 || vec.empty()) {
            individual_mrr.push_back(0.0);
        }
        else {
            double mrr = calculate_mrr(vec, k);
            individual_mrr.push_back(mrr);
            sum_mrr += mrr;
        }
    }

    double average_mrr = data.size() ? sum_mrr / data.size() : 0.0;
    return { average_mrr, individual_mrr };
}

std::pair<double, std::vector<double>> MetricsCalculator2::map(const std::vector<std::pair<std::vector<int>, int>>& data) {
    if (data.empty()) {
        return { 0.0, {0.0} };
    }

    std::vector<double> separate_result;

    for (const auto& [sub_list, total_num] : data) {
        if (total_num == 0) {
            separate_result.push_back(0.0);
            continue;
        }

        size_t len = sub_list.size();
        std::vector<double> ranking_array(len);
        std::iota(ranking_array.begin(), ranking_array.end(), 1.0);
        std::transform(ranking_array.begin(), ranking_array.end(), ranking_array.begin(),
            [](double i) { return 1.0 / i; });

        std::vector<double> right_ranking_list(len, 0.0);
        int count = 1;

        for (size_t i = 0; i < len; ++i) {
            if (sub_list[i] != 0) {
                right_ranking_list[i] = count++;
            }
        }

        double ap = std::inner_product(right_ranking_list.begin(), right_ranking_list.end(),
            ranking_array.begin(), 0.0) / total_num;
        separate_result.push_back(ap);
    }

    double mean_ap = std::accumulate(separate_result.begin(), separate_result.end(), 0.0) / separate_result.size();
    return { mean_ap, separate_result };
}
