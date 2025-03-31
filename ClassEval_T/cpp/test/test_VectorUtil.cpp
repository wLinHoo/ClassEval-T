#include <gtest/gtest.h>
#include "pch.h" 

#include <vector>
#include <array>
#include <cmath>
#include <unordered_map>
#include <string>

class VectorUtilTest : public ::testing::Test {
protected:
    void SetUp() override {
       
    }

    void TearDown() override {
        
    }
};

TEST_F(VectorUtilTest, test_vectorutil) {
    
    std::array<double, 2> vector_1 = { 1.0, 1.0 };
    std::array<double, 2> vector_2 = { 1.0, 0.0 };
    double similarity = VectorUtil::similarity(vector_1, vector_2);
    EXPECT_NEAR(similarity, 0.7071067811865475, 1e-9);

    
    std::array<double, 2> vector1 = { 1.0, 1.0 };
    std::vector<std::array<double, 2>> vectors_all = {
        {1.0, 0.0},
        {1.0, 1.0}
    };
    std::vector<double> similarities = VectorUtil::cosine_similarities(vector1, vectors_all);
    std::vector<double> res = { 0.7071067811865475, 1.0 };

    for (size_t index = 0; index < similarities.size(); ++index) {
        EXPECT_NEAR(similarities[index], res[index], 1e-9);
    }

    
    std::vector<std::array<double, 2>> vector_list1 = {
        {1.0, 0.0},
        {0.0, 1.0}
    };
    std::vector<std::array<double, 2>> vector_list2 = {
        {0.0, 0.0},
        {1.0, 1.0}
    };
    double similarity_n = VectorUtil::n_similarity(vector_list1, vector_list2);
    EXPECT_NEAR(similarity_n, 1.0, 1e-9);

    
    std::unordered_map<std::string, double> num_dict = {
        {"key1", 0.1},
        {"key2", 0.5}
    };
    std::unordered_map<std::string, double> res_idf = VectorUtil::compute_idf_weight_dict(2, num_dict);

    EXPECT_NEAR(res_idf["key1"], 1.0033021088637848, 1e-9);
    EXPECT_NEAR(res_idf["key2"], 0.6931471805599453, 1e-9);
}


template<size_t N>
std::array<double, N> to_std_array(const std::vector<double>& vec) {
    std::array<double, N> arr;
    std::copy(vec.begin(), vec.begin() + N, arr.begin());
    return arr;
}

class VectorUtilTestSimilarity : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(VectorUtilTestSimilarity, test_similarity_1) {
    std::array<double, 2> vector_1 = { 1.0, 1.0 };
    std::array<double, 2> vector_2 = { 1.0, 0.0 };
    double similarity = VectorUtil::similarity(vector_1, vector_2);
    EXPECT_NEAR(similarity, 0.7071067811865475, 1e-9);
}

TEST_F(VectorUtilTestSimilarity, test_similarity_2) {
    std::array<double, 2> vector_1 = { 1.0, 1.0 };
    std::array<double, 2> vector_2 = { 0.0, 0.0 };
    double similarity = VectorUtil::similarity(vector_1, vector_2);
    EXPECT_NEAR(similarity, 0.0, 1e-9);
}

TEST_F(VectorUtilTestSimilarity, test_similarity_3) {
    std::array<double, 2> vector_1 = { 1.0, 1.0 };
    std::array<double, 2> vector_2 = { 1.0, 1.0 };
    double similarity = VectorUtil::similarity(vector_1, vector_2);
    EXPECT_NEAR(similarity, 1.0, 1e-9);
}

TEST_F(VectorUtilTestSimilarity, test_similarity_4) {
    std::array<double, 8> vector_1 = { 1.0, 1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0 };
    std::array<double, 8> vector_2 = { 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 1.0 };
    double similarity = VectorUtil::similarity(vector_1, vector_2);
    EXPECT_NEAR(similarity, 0.8944271909999159, 1e-9);
}

TEST_F(VectorUtilTestSimilarity, test_similarity_5) {
    std::array<double, 8> vector_1 = { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };
    std::array<double, 8> vector_2 = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
    double similarity = VectorUtil::similarity(vector_1, vector_2);
    EXPECT_NEAR(similarity, 0.0, 1e-9);
}

class VectorUtilTestCosineSimilarities : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(VectorUtilTestCosineSimilarities, test_cosine_similarities_1) {
    std::array<double, 2> vector1 = { 1.0, 1.0 };
    std::vector<std::array<double, 2>> vectors_all = {
        {1.0, 0.0},
        {1.0, 1.0}
    };
    std::vector<double> similarities = VectorUtil::cosine_similarities(vector1, vectors_all);
    std::vector<double> res = { 0.7071067811865475, 1.0 };

    for (size_t index = 0; index < similarities.size(); ++index) {
        EXPECT_NEAR(similarities[index], res[index], 1e-9);
    }
}

TEST_F(VectorUtilTestCosineSimilarities, test_cosine_similarities_2) {
    std::array<double, 8> vector1 = { 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0 };
    std::vector<std::array<double, 8>> vectors_all = {
        {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0},
        {1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0}
    };
    std::vector<double> similarities = VectorUtil::cosine_similarities(vector1, vectors_all);
    std::vector<double> res = { 0.8660254037844387, 0.8164965809277261 };

    for (size_t index = 0; index < similarities.size(); ++index) {
        EXPECT_NEAR(similarities[index], res[index], 1e-9);
    }
}

TEST_F(VectorUtilTestCosineSimilarities, test_cosine_similarities_3) {
    std::array<double, 8> vector1 = { 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0 };
    std::vector<std::array<double, 8>> vectors_all = {
        {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0},
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0}
    };
    std::vector<double> similarities = VectorUtil::cosine_similarities(vector1, vectors_all);
    std::vector<double> res = { 0.8660254037844387, 0.7559289460184544 };

    for (size_t index = 0; index < similarities.size(); ++index) {
        EXPECT_NEAR(similarities[index], res[index], 1e-9);
    }
}

TEST_F(VectorUtilTestCosineSimilarities, test_cosine_similarities_4) {
    std::array<double, 8> vector1 = { 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0 };
    std::vector<std::array<double, 8>> vectors_all = {
        {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0},
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}
    };
    std::vector<double> similarities = VectorUtil::cosine_similarities(vector1, vectors_all);
    std::vector<double> res = { 0.8660254037844387, 0.7071067811865475 };

    for (size_t index = 0; index < similarities.size(); ++index) {
        EXPECT_NEAR(similarities[index], res[index], 1e-9);
    }
}

TEST_F(VectorUtilTestCosineSimilarities, test_cosine_similarities_5) {
    std::array<double, 8> vector1 = { 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0 };
    std::vector<std::array<double, 8>> vectors_all = {
        {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0},
        {0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0}
    };
    std::vector<double> similarities = VectorUtil::cosine_similarities(vector1, vectors_all);
    std::vector<double> res = { 0.8660254037844387, 0.5669467095138409 };

    for (size_t index = 0; index < similarities.size(); ++index) {
        EXPECT_NEAR(similarities[index], res[index], 1e-9);
    }
}

class VectorUtilTestNSimilarity : public ::testing::Test {};

TEST_F(VectorUtilTestNSimilarity, test_n_similarity_1) {
    std::vector<std::array<double, 2>> vector_list1 = { { 1.0, 0.0 }, { 0.0, 1.0 } };
    std::vector<std::array<double, 2>> vector_list2 = { { 0.0, 0.0 }, { 1.0, 1.0 } };
    double similarity = VectorUtil::n_similarity(vector_list1, vector_list2);
    EXPECT_NEAR(similarity, 1.0, 1e-9);
}

TEST_F(VectorUtilTestNSimilarity, test_n_similarity_2) {
    std::vector<std::array<double, 2>> vector_list1 = { { 1.0, 1.0 }, { 0.0, 1.0 } };
    std::vector<std::array<double, 2>> vector_list2 = { { 0.0, 0.0 }, { 1.0, 1.0 } };
    double similarity = VectorUtil::n_similarity(vector_list1, vector_list2);
    EXPECT_NEAR(similarity, 0.9486832980505137, 1e-9);
}

TEST_F(VectorUtilTestNSimilarity, test_n_similarity_3) {
    std::vector<std::array<double, 2>> vector_list1 = { { 1.0, 0.0 }, { 1.0, 1.0 } };
    std::vector<std::array<double, 2>> vector_list2 = { { 0.0, 0.0 }, { 1.0, 1.0 } };
    double similarity = VectorUtil::n_similarity(vector_list1, vector_list2);
    EXPECT_NEAR(similarity, 0.9486832980505137, 1e-9);
}

TEST_F(VectorUtilTestNSimilarity, test_n_similarity_4) {
    std::vector<std::array<double, 2>> vector_list1 = { { 1.0, 0.0 }, { 0.0, 1.0 } };
    std::vector<std::array<double, 2>> vector_list2 = { { 1.0, 0.0 }, { 1.0, 1.0 } };
    double similarity = VectorUtil::n_similarity(vector_list1, vector_list2);
    EXPECT_NEAR(similarity, 0.9486832980505137, 1e-9);
}

TEST_F(VectorUtilTestNSimilarity, test_n_similarity_5) {
    std::vector<std::array<double, 2>> vector_list1 = { { 1.0, 0.0 }, { 0.0, 1.0 } };
    std::vector<std::array<double, 2>> vector_list2 = { { 0.0, 1.0 }, { 1.0, 1.0 } };
    double similarity = VectorUtil::n_similarity(vector_list1, vector_list2);
    EXPECT_NEAR(similarity, 0.9486832980505137, 1e-9);
}

TEST_F(VectorUtilTestNSimilarity, test_n_similarity_6) {
    std::vector<std::array<double, 2>> vector_list1;
    std::vector<std::array<double, 2>> vector_list2;
    EXPECT_THROW(VectorUtil::n_similarity(vector_list1, vector_list2), std::invalid_argument);
}


class VectorUtilTestComputeIdfWeightDict : public ::testing::Test {};

TEST_F(VectorUtilTestComputeIdfWeightDict, test_compute_idf_weight_dict_1) {
    std::unordered_map<std::string, double> num_dict = { {"key1", 0.1}, {"key2", 0.5} };
    auto res = VectorUtil::compute_idf_weight_dict(2, num_dict);
    EXPECT_NEAR(res["key1"], 1.0033021088637848, 1e-9);
    EXPECT_NEAR(res["key2"], 0.6931471805599453, 1e-9);
}

TEST_F(VectorUtilTestComputeIdfWeightDict, test_compute_idf_weight_dict_2) {
    std::unordered_map<std::string, double> num_dict = { {"key1", 0.2}, {"key2", 0.5} };
    auto res = VectorUtil::compute_idf_weight_dict(2, num_dict);
    EXPECT_NEAR(res["key1"], 0.9162907318741551, 1e-9);
    EXPECT_NEAR(res["key2"], 0.6931471805599453, 1e-9);
}

TEST_F(VectorUtilTestComputeIdfWeightDict, test_compute_idf_weight_dict_3) {
    std::unordered_map<std::string, double> num_dict = { {"key1", 0.3}, {"key2", 0.5} };
    auto res = VectorUtil::compute_idf_weight_dict(2, num_dict);
    EXPECT_NEAR(res["key1"], 0.8362480242006185, 1e-9);
    EXPECT_NEAR(res["key2"], 0.6931471805599453, 1e-9);
}

TEST_F(VectorUtilTestComputeIdfWeightDict, test_compute_idf_weight_dict_4) {
    std::unordered_map<std::string, double> num_dict = { {"key1", 0.4}, {"key2", 0.5} };
    auto res = VectorUtil::compute_idf_weight_dict(2, num_dict);
    EXPECT_NEAR(res["key1"], 0.7621400520468967, 1e-9);
    EXPECT_NEAR(res["key2"], 0.6931471805599453, 1e-9);
}

TEST_F(VectorUtilTestComputeIdfWeightDict, test_compute_idf_weight_dict_5) {
    std::unordered_map<std::string, double> num_dict = { {"key1", 0.5}, {"key2", 0.5} };
    auto res = VectorUtil::compute_idf_weight_dict(2, num_dict);
    EXPECT_NEAR(res["key1"], 0.6931471805599453, 1e-9);
    EXPECT_NEAR(res["key2"], 0.6931471805599453, 1e-9);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}