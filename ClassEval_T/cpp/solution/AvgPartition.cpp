
#include <vector>

class AvgPartition {
public:
    AvgPartition(const std::vector<int>& lst, int limit);
    std::pair<int, int> set_num() const;
    std::vector<int> get(int index) const;

private:
    std::vector<int> lst;
    int limit;
};
AvgPartition::AvgPartition(const std::vector<int>& lst, int limit)
    : lst(lst), limit(limit) {}

std::pair<int, int> AvgPartition::set_num() const {
    int size = lst.size() / limit;
    int remainder = lst.size() % limit;
    return { size, remainder };
}

std::vector<int> AvgPartition::get(int index) const {
    auto [size, remainder] = set_num();
    int start = index * size + std::min(index, remainder);
    int end = start + size;
    if (index + 1 <= remainder) {
        end += 1;
    }
    return std::vector<int>(lst.begin() + start, lst.begin() + end);
}
