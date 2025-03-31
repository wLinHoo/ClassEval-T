#include <vector>
#include <cmath>

class DataStatistics4 {
public:
    static double correlation_coefficient(const std::vector<double>& data1, const std::vector<double>& data2);
    static double skewness(const std::vector<double>& data);
    static double kurtosis(const std::vector<double>& data);
    static std::vector<double> pdf(const std::vector<double>& data, double mu, double sigma);
};

const double pai = 3.141592653589793;
double DataStatistics4::correlation_coefficient(const std::vector<double>& data1, const std::vector<double>& data2) {
    size_t n = data1.size();
    double mean1 = 0.0, mean2 = 0.0;

    for (size_t i = 0; i < n; ++i) {
        mean1 += data1[i];
        mean2 += data2[i];
    }
    mean1 /= n;
    mean2 /= n;

    double numerator = 0.0, denominator1 = 0.0, denominator2 = 0.0;
    for (size_t i = 0; i < n; ++i) {
        double diff1 = data1[i] - mean1;
        double diff2 = data2[i] - mean2;
        numerator += diff1 * diff2;
        denominator1 += diff1 * diff1;
        denominator2 += diff2 * diff2;
    }

    double denominator = std::sqrt(denominator1) * std::sqrt(denominator2);
    return (denominator != 0) ? (numerator / denominator) : 0;
}

double DataStatistics4::skewness(const std::vector<double>& data) {
    size_t n = data.size();
    double mean = 0.0;

    for (double x : data) {
        mean += x;
    }
    mean /= n;

    double variance = 0.0;
    for (double x : data) {
        variance += (x - mean) * (x - mean);
    }
    variance /= n;

    double std_deviation = std::sqrt(variance);

    if (std_deviation == 0) {
        return 0.0;
    }

    double skewness = 0.0;
    for (double x : data) {
        skewness += std::pow((x - mean), 3);
    }

    skewness *= static_cast<double>(n) / ((n - 1) * (n - 2) * std::pow(std_deviation, 3));
    return skewness;
}

double DataStatistics4::kurtosis(const std::vector<double>& data) {
    size_t n = data.size();
    double mean = 0.0;

    for (double x : data) {
        mean += x;
    }
    mean /= n;

    double variance = 0.0;
    for (double x : data) {
        variance += (x - mean) * (x - mean);
    }
    variance /= n;

    double std_dev = std::sqrt(variance);

    if (std_dev == 0) {
        return std::numeric_limits<double>::quiet_NaN();
    }

    double fourth_moment = 0.0;
    for (double x : data) {
        fourth_moment += std::pow((x - mean), 4);
    }
    fourth_moment /= n;

    double kurtosis_value = (fourth_moment / std::pow(std_dev, 4)) - 3.0;
    return kurtosis_value;
}

std::vector<double> DataStatistics4::pdf(const std::vector<double>& data, double mu, double sigma) {
    std::vector<double> pdf_values;
    pdf_values.reserve(data.size());

    for (double x : data) {
        double value = (1 / (sigma * std::sqrt(2 * pai))) * std::exp(-0.5 * std::pow((x - mu) / sigma, 2));
        pdf_values.push_back(value);
    }

    return pdf_values;
}
