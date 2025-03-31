
#include <algorithm>
#include <numeric>
#include <cmath>

class DataStatistics2 {
public:
    DataStatistics2(const std::vector<double>& data);

    double get_sum() const;
    double get_min() const;
    double get_max() const;
    double get_variance() const;
    double get_std_deviation() const;
    double get_correlation() const;

private:
    std::vector<double> data;
};

DataStatistics2::DataStatistics2(const std::vector<double>& data) : data(data) {}

double DataStatistics2::get_sum() const {
    return std::accumulate(data.begin(), data.end(), 0.0);
}

double DataStatistics2::get_min() const {
    return *std::min_element(data.begin(), data.end());
}

double DataStatistics2::get_max() const {
    return *std::max_element(data.begin(), data.end());
}

double DataStatistics2::get_variance() const {
    double mean = get_sum() / data.size();
    double variance = 0.0;
    for (const auto& value : data) {
        variance += std::pow(value - mean, 2);
    }
    variance /= data.size();
    return std::round(variance * 100) / 100;  
}

double DataStatistics2::get_std_deviation() const {
    double variance = get_variance();
    double std_dev = std::sqrt(variance);
    return std::round(std_dev * 100) / 100;  
}

double DataStatistics2::get_correlation() const {
    if (data.size() < 2) return 1.0;  
    double mean = get_sum() / data.size();
    double sum_prod = 0.0, sum_sq = 0.0;
    for (const auto& value : data) {
        sum_prod += (value - mean) * (value - mean);
        sum_sq += (value - mean) * (value - mean);
    }
    return sum_prod / sum_sq;
}
