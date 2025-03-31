#include <vector>

class MetricsCalculator {
public:
    int true_positives;
    int false_positives;
    int false_negatives;
    int true_negatives;

    MetricsCalculator();

    void update(const std::vector<int>& predicted_labels, const std::vector<int>& true_labels);
    double precision(const std::vector<int>& predicted_labels, const std::vector<int>& true_labels);
    double recall(const std::vector<int>& predicted_labels, const std::vector<int>& true_labels);
    double f1_score(const std::vector<int>& predicted_labels, const std::vector<int>& true_labels);
    double accuracy(const std::vector<int>& predicted_labels, const std::vector<int>& true_labels);
};
MetricsCalculator::MetricsCalculator() {
    true_positives = 0;
    false_positives = 0;
    false_negatives = 0;
    true_negatives = 0;
}

void MetricsCalculator::update(const std::vector<int>& predicted_labels, const std::vector<int>& true_labels) {
    for (size_t i = 0; i < predicted_labels.size(); ++i) {
        int predicted = predicted_labels[i];
        int true_label = true_labels[i];

        if (predicted == 1 && true_label == 1) {
            true_positives++;
        }
        else if (predicted == 1 && true_label == 0) {
            false_positives++;
        }
        else if (predicted == 0 && true_label == 1) {
            false_negatives++;
        }
        else if (predicted == 0 && true_label == 0) {
            true_negatives++;
        }
    }
}

double MetricsCalculator::precision(const std::vector<int>& predicted_labels, const std::vector<int>& true_labels) {
    update(predicted_labels, true_labels);
    if (true_positives + false_positives == 0) {
        return 0.0;
    }
    return static_cast<double>(true_positives) / (true_positives + false_positives);
}

double MetricsCalculator::recall(const std::vector<int>& predicted_labels, const std::vector<int>& true_labels) {
    update(predicted_labels, true_labels);
    if (true_positives + false_negatives == 0) {
        return 0.0;
    }
    return static_cast<double>(true_positives) / (true_positives + false_negatives);
}

double MetricsCalculator::f1_score(const std::vector<int>& predicted_labels, const std::vector<int>& true_labels) {
    update(predicted_labels, true_labels);
    double precision_value = precision(predicted_labels, true_labels);
    double recall_value = recall(predicted_labels, true_labels);
    if (precision_value + recall_value == 0.0) {
        return 0.0;
    }
    return 2.0 * precision_value * recall_value / (precision_value + recall_value);
}

double MetricsCalculator::accuracy(const std::vector<int>& predicted_labels, const std::vector<int>& true_labels) {
    update(predicted_labels, true_labels);
    int total = true_positives + true_negatives + false_positives + false_negatives;
    if (total == 0) {
        return 0.0;
    }
    return static_cast<double>(true_positives + true_negatives) / total;
}
