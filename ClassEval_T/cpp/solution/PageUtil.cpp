
#include <algorithm>
#include <cmath>

#include <vector>
#include <unordered_map>
#include <string>
#include <variant>

class PageUtil {
public:
    PageUtil(const std::vector<int>& data, int page_size);

    std::vector<int> get_page(int page_number) const;

    std::unordered_map<std::string, std::variant<int, std::vector<int>, bool>> get_page_info(int page_number) const;

    std::unordered_map<std::string, std::variant<std::string, int, std::vector<int>>> search(const std::string& keyword) const;

    std::vector<int> data;
    int page_size;
    int total_items;
    int total_pages;
};

PageUtil::PageUtil(const std::vector<int>& data, int page_size)
    : data(data), page_size(page_size) {
    total_items = data.size();
    total_pages = (total_items + page_size - 1) / page_size;
}

std::vector<int> PageUtil::get_page(int page_number) const {
    if (page_number < 1 || page_number > total_pages) {
        return {};
    }

    int start_index = (page_number - 1) * page_size;
    int end_index = start_index + page_size;
    if (end_index > total_items) {
        end_index = total_items;
    }
    return std::vector<int>(data.begin() + start_index, data.begin() + end_index);
}

std::unordered_map<std::string, std::variant<int, std::vector<int>, bool>> PageUtil::get_page_info(int page_number) const {
    if (page_number < 1 || page_number > total_pages) {
        return {};
    }

    int start_index = (page_number - 1) * page_size;
    int end_index = std::min(start_index + page_size, total_items);
    std::vector<int> page_data(data.begin() + start_index, data.begin() + end_index);

    std::unordered_map<std::string, std::variant<int, std::vector<int>, bool>> page_info = {
        {"current_page", page_number},
        {"per_page", page_size},
        {"total_pages", total_pages},
        {"total_items", total_items},
        {"has_previous", page_number > 1},
        {"has_next", page_number < total_pages},
        {"data", page_data}
    };

    return page_info;
}

std::unordered_map<std::string, std::variant<std::string, int, std::vector<int>>> PageUtil::search(const std::string& keyword) const {
    std::vector<int> results;
    for (int item : data) {
        if (std::to_string(item).find(keyword) != std::string::npos) {
            results.push_back(item);
        }
    }

    int num_results = results.size();
    int num_pages = (num_results + page_size - 1) / page_size;

    std::unordered_map<std::string, std::variant<std::string, int, std::vector<int>>> search_info = {
        {"keyword", keyword},
        {"total_results", num_results},
        {"total_pages", num_pages},
        {"results", results}
    };

    return search_info;
}
