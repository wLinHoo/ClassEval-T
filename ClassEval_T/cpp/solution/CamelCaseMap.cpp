#include <algorithm>
#include <cctype>

#include <unordered_map>
#include <string>
#include <vector>

class CamelCaseMap {
public:
    std::unordered_map<std::string, std::string> data;
    std::vector<std::string> insertion_order;
    static std::string to_camel_case(const std::string& key);
    std::string convert_key(const std::string& key) const;
    void set_item(const std::string& key, const std::string& value);
    std::string get_item(const std::string& key) const;
    void del_item(const std::string& key);
    size_t len() const;
    std::vector<std::string>::const_iterator begin() const;
    std::vector<std::string>::const_iterator end() const;
};

std::string CamelCaseMap::to_camel_case(const std::string& key) {
    std::string camel_case_key;
    bool capitalize = false;
    for (char c : key) {
        if (c == '_') {
            capitalize = true;
        }
        else {
            camel_case_key += capitalize ? std::toupper(c) : c;
            capitalize = false;
        }
    }
    return camel_case_key;
}

std::string CamelCaseMap::convert_key(const std::string& key) const {
    return to_camel_case(key);
}

void CamelCaseMap::set_item(const std::string& key, const std::string& value) {
    std::string camel_key = convert_key(key);
    if (data.find(camel_key) == data.end()) {
        insertion_order.push_back(camel_key);
    }
    data[camel_key] = value;
}

std::string CamelCaseMap::get_item(const std::string& key) const {
    return data.at(convert_key(key));
}

void CamelCaseMap::del_item(const std::string& key) {
    std::string camel_key = convert_key(key);
    data.erase(camel_key);
    insertion_order.erase(std::remove(insertion_order.begin(), insertion_order.end(), camel_key), insertion_order.end());
}

size_t CamelCaseMap::len() const {
    return data.size();
}

std::vector<std::string>::const_iterator CamelCaseMap::begin() const {
    return insertion_order.begin();
}

std::vector<std::string>::const_iterator CamelCaseMap::end() const {
    return insertion_order.end();
}
