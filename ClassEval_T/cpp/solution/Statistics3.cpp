
#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <stdexcept>

#include <vector>

class Statistics3 {
public:
    static double median(const std::vector<int>& data);
    static std::vector<int> mode(const std::vector<int>& data);
    static double correlation(const std::vector<int>& x, const std::vector<int>& y);
    static double mean(const std::vector<int>& data);
    static std::vector<std::vector<double>> correlation_matrix(const std::vector<std::vector<int>>& data);
    static double standard_deviation(const std::vector<int>& data);
    static std::vector<double> z_score(const std::vector<int>& data);
};


double Statistics3::mean(const std::vector<int>& data) {
    if (data.empty()) return NAN;
    return static_cast<double>(std::accumulate(data.begin(), data.end(), 0)) / data.size();
}


double variance(const std::vector<int>& data, double mean_value) {
    double variance_sum = 0.0;
    for (int x : data) {
        double diff = x - mean_value;
        variance_sum += diff * diff;
    }
    return variance_sum / (data.size() - 1);
}


double Statistics3::median(const std::vector<int>& data) {
    std::vector<int> sorted_data = data;
    std::sort(sorted_data.begin(), sorted_data.end());
    size_t n = sorted_data.size();
    if (n % 2 == 1) {
        return sorted_data[n / 2];
    }
    else {
        return (sorted_data[n / 2 - 1] + sorted_data[n / 2]) / 2.0;
    }
}


std::vector<int> Statistics3::mode(const std::vector<int>& data) {
    std::map<int, int> counts;
    for (int value : data) {
        counts[value]++;
    }
    int max_count = 0;
    for (const auto& pair : counts) {
        if (pair.second > max_count) {
            max_count = pair.second;
        }
    }
    std::vector<int> mode_values;
    for (const auto& pair : counts) {
        if (pair.second == max_count) {
            mode_values.push_back(pair.first);
        }
    }
    return mode_values;
}


double Statistics3::correlation(const std::vector<int>& x, const std::vector<int>& y) {
    size_t n = x.size();
    if (n != y.size()) throw std::invalid_argument("Vectors must be of the same length");

    double mean_x = mean(x);
    double mean_y = mean(y);
    double numerator = 0.0;
    double denominator_x = 0.0;
    double denominator_y = 0.0;

    for (size_t i = 0; i < n; ++i) {
        double diff_x = x[i] - mean_x;
        double diff_y = y[i] - mean_y;
        numerator += diff_x * diff_y;
        denominator_x += diff_x * diff_x;
        denominator_y += diff_y * diff_y;
    }

    double denominator = std::sqrt(denominator_x * denominator_y);
    if (denominator == 0) return NAN;
    return numerator / denominator;
}


std::vector<std::vector<double>> Statistics3::correlation_matrix(const std::vector<std::vector<int>>& data) {
    size_t num_rows = data.size();
    size_t num_cols = data[0].size();
    std::vector<std::vector<double>> matrix(num_cols, std::vector<double>(num_cols, 0.0));

    for (size_t i = 0; i < num_cols; ++i) {
        for (size_t j = 0; j < num_cols; ++j) {
            std::vector<int> column1(num_rows);
            std::vector<int> column2(num_rows);
            for (size_t k = 0; k < num_rows; ++k) {
                column1[k] = data[k][i];
                column2[k] = data[k][j];
            }
            matrix[i][j] = correlation(column1, column2);
        }
    }
    return matrix;
}


double Statistics3::standard_deviation(const std::vector<int>& data) {
    size_t n = data.size();
    if (n < 2) return NAN;
    double mean_value = mean(data);
    double var = variance(data, mean_value);
    return std::sqrt(var);
}


std::vector<double> Statistics3::z_score(const std::vector<int>& data) {
    double mean_value = mean(data);
    double std_deviation = standard_deviation(data);
    if (std_deviation == NAN || std_deviation == 0) return std::vector<double>(data.size(), NAN);

    std::vector<double> z_scores;
    z_scores.reserve(data.size());
    for (int x : data) {
        z_scores.push_back((x - mean_value) / std_deviation);
    }
    return z_scores;
}
