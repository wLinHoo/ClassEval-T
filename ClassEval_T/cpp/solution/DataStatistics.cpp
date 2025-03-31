#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <stdexcept>

class DataStatistics {
public:
    double mean(const std::vector<double>& data) const;

    double median(std::vector<double> data) const;

    std::vector<int> mode(const std::vector<int>& data) const;
};


double DataStatistics::mean(const std::vector<double>& data) const {
    if (data.empty()) {
        throw std::invalid_argument("Data vector is empty.");
    }
    double sum = std::accumulate(data.begin(), data.end(), 0.0);
    return std::round(sum / data.size() * 100) / 100; 
}


double DataStatistics::median(std::vector<double> data) const {
    if (data.empty()) {
        throw std::invalid_argument("Data vector is empty.");
    }
    std::sort(data.begin(), data.end());
    size_t n = data.size();
    if (n % 2 == 0) {
        return std::round(((data[n / 2 - 1] + data[n / 2]) / 2) * 100) / 100; 
    }
    else {
        return data[n / 2];
    }
}


std::vector<int> DataStatistics::mode(const std::vector<int>& data) const {
    if (data.empty()) {
        throw std::invalid_argument("Data vector is empty.");
    }

    std::map<int, int> count_map;
    for (int num : data) {
        ++count_map[num];
    }

    int max_count = 0;
    for (const auto& pair : count_map) {
        if (pair.second > max_count) {
            max_count = pair.second;
        }
    }

    std::vector<int> modes;
    for (const auto& pair : count_map) {
        if (pair.second == max_count) {
            modes.push_back(pair.first);
        }
    }

    return modes;
}
