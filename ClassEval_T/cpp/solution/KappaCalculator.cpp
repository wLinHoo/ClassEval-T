
#include <Eigen/Dense>
#include <numeric> 


#include <vector>

class KappaCalculator {
public:
    static double kappa(const std::vector<std::vector<int>>& testData, int k);
    static double fleiss_kappa(const std::vector<std::vector<int>>& testData, int N, int k, int n);
};

double KappaCalculator::kappa(const std::vector<std::vector<int>>& testData, int k) {
    Eigen::MatrixXd dataMat(testData.size(), k);

    for (size_t i = 0; i < testData.size(); ++i) {
        for (int j = 0; j < k; ++j) {
            dataMat(i, j) = testData[i][j];
        }
    }

    double P0 = 0.0;
    for (int i = 0; i < k; ++i) {
        P0 += dataMat(i, i);
    }

    Eigen::VectorXd xsum = dataMat.rowwise().sum();
    Eigen::VectorXd ysum = dataMat.colwise().sum();
    double sum = dataMat.sum();

    double Pe = (ysum.dot(xsum)) / (sum * sum);
    P0 /= sum;

    double cohens_coefficient = (P0 - Pe) / (1 - Pe);
    return cohens_coefficient;
}

double KappaCalculator::fleiss_kappa(const std::vector<std::vector<int>>& testData, int N, int k, int n) {
    Eigen::MatrixXd dataMat(testData.size(), k);

    for (size_t i = 0; i < testData.size(); ++i) {
        for (int j = 0; j < k; ++j) {
            dataMat(i, j) = testData[i][j];
        }
    }

    double sum = 0.0;
    double P0 = 0.0;

    for (int i = 0; i < N; ++i) {
        double temp = 0.0;
        for (int j = 0; j < k; ++j) {
            sum += dataMat(i, j);
            temp += std::pow(dataMat(i, j), 2);
        }
        temp -= n;
        temp /= (n - 1) * n;
        P0 += temp;
    }

    P0 /= N;

    Eigen::VectorXd ysum = dataMat.colwise().sum();
    ysum = ysum.array() / sum;
    ysum = ysum.array().square();

    double Pe = ysum.sum();

    double ans = (P0 - Pe) / (1 - Pe);
    return ans;
}
