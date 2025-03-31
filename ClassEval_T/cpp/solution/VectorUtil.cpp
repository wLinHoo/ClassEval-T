
#include <cmath>
#include <stdexcept>

#include <array>
#include <vector>
#include <unordered_map>
#include <string>

class VectorUtil {
public:
    template<size_t N>
    static double similarity(const std::array<double, N>& vector_1, const std::array<double, N>& vector_2);

    template<size_t N>
    static std::vector<double> cosine_similarities(const std::array<double, N>& vector_1,
        const std::vector<std::array<double, N>>& vectors_all);

    template<size_t N>
    static double n_similarity(const std::vector<std::array<double, N>>& vector_list_1,
        const std::vector<std::array<double, N>>& vector_list_2);

    static std::unordered_map<std::string, double> compute_idf_weight_dict(int total_num,
        const std::unordered_map<std::string, double>& number_dict);

private:
    template<size_t N>
    static double norm(const std::array<double, N>& vec);

    template<size_t N>
    static std::array<double, N> normalize(const std::array<double, N>& vec);
};


template<size_t N>
double VectorUtil::norm(const std::array<double, N>& vec) {
    double sum = 0.0;
    for (double val : vec) {
        sum += val * val;
    }
    return std::sqrt(sum);
}


template<size_t N>
std::array<double, N> VectorUtil::normalize(const std::array<double, N>& vec) {
    std::array<double, N> normalized = {};
    double vec_norm = norm(vec);
    if (vec_norm == 0.0) {
        return normalized; 
    }
    for (size_t i = 0; i < N; ++i) {
        normalized[i] = vec[i] / vec_norm;
    }
    return normalized;
}


template<size_t N>
double VectorUtil::similarity(const std::array<double, N>& vector_1, const std::array<double, N>& vector_2) {
    auto norm_vec1 = normalize(vector_1);
    auto norm_vec2 = normalize(vector_2);
    double dot_product = 0.0;
    for (size_t i = 0; i < N; ++i) {
        dot_product += norm_vec1[i] * norm_vec2[i];
    }
    return dot_product;
}


template<size_t N>
std::vector<double> VectorUtil::cosine_similarities(const std::array<double, N>& vector_1,
    const std::vector<std::array<double, N>>& vectors_all) {
    std::vector<double> similarities;
    double norm_vec1 = norm(vector_1);

    for (const auto& vec : vectors_all) {
        double norm_vec_all = norm(vec);
        if (norm_vec_all == 0.0) {
            similarities.push_back(0.0); 
            continue;
        }
        double dot_product = 0.0;
        for (size_t i = 0; i < N; ++i) {
            dot_product += vec[i] * vector_1[i];
        }
        double similarity = dot_product / (norm_vec1 * norm_vec_all);
        similarities.push_back(similarity);
    }
    return similarities;
}


template<size_t N>
double VectorUtil::n_similarity(const std::vector<std::array<double, N>>& vector_list_1,
    const std::vector<std::array<double, N>>& vector_list_2) {
    if (vector_list_1.empty() || vector_list_2.empty()) {
        throw std::invalid_argument("At least one of the lists is empty.");
    }

    std::array<double, N> mean_vec1 = {};
    std::array<double, N> mean_vec2 = {};

    for (const auto& vec : vector_list_1) {
        for (size_t i = 0; i < N; ++i) {
            mean_vec1[i] += vec[i];
        }
    }
    for (const auto& vec : vector_list_2) {
        for (size_t i = 0; i < N; ++i) {
            mean_vec2[i] += vec[i];
        }
    }

    for (size_t i = 0; i < N; ++i) {
        mean_vec1[i] /= vector_list_1.size();
        mean_vec2[i] /= vector_list_2.size();
    }

    return similarity(mean_vec1, mean_vec2);
}


std::unordered_map<std::string, double> VectorUtil::compute_idf_weight_dict(int total_num,
    const std::unordered_map<std::string, double>& number_dict) {
    std::unordered_map<std::string, double> result;
    std::unordered_map<int, std::string> index_2_key_map;
    std::vector<double> count_list;
    int index = 0;

    for (const auto& [key, count] : number_dict) {
        index_2_key_map[index] = key;
        count_list.push_back(count);
        ++index;
    }

    std::vector<double> a(count_list.size());
    for (size_t i = 0; i < count_list.size(); ++i) {
        a[i] = std::log((total_num + 1.0) / (count_list[i] + 1.0));
    }

    for (size_t i = 0; i < a.size(); ++i) {
        result[index_2_key_map[i]] = a[i];
    }

    return result;
}


template double VectorUtil::similarity(const std::array<double, 2>& vector_1, const std::array<double, 2>& vector_2);
template double VectorUtil::similarity(const std::array<double, 8>& vector_1, const std::array<double, 8>& vector_2);
template std::vector<double> VectorUtil::cosine_similarities(const std::array<double, 2>& vector_1,
    const std::vector<std::array<double, 2>>& vectors_all);
template std::vector<double> VectorUtil::cosine_similarities(const std::array<double, 8>& vector_1,
    const std::vector<std::array<double, 8>>& vectors_all);
template double VectorUtil::n_similarity(const std::vector<std::array<double, 2>>& vector_list_1,
    const std::vector<std::array<double, 2>>& vector_list_2);
template double VectorUtil::n_similarity(const std::vector<std::array<double, 8>>& vector_list_1,
    const std::vector<std::array<double, 8>>& vector_list_2);
