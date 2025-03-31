
#include <fstream>
#include <sstream>
#include <iostream>

#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp> 

class CookiesUtil {
public:
    explicit CookiesUtil(const std::string& cookiesFile);

    void get_cookies(const nlohmann::json& response);
    nlohmann::json load_cookies();
    bool _save_cookies();
    void set_cookies(nlohmann::json& request);

    std::string cookies_file;
    std::unordered_map<std::string, std::string> cookies;
};

using json = nlohmann::json;

CookiesUtil::CookiesUtil(const std::string& cookiesFile) : cookies_file(cookiesFile) {}

void CookiesUtil::get_cookies(const nlohmann::json& response) {
    if (response.contains("cookies")) {
        cookies = response["cookies"].get<std::unordered_map<std::string, std::string>>();
    }
    _save_cookies();
}


json CookiesUtil::load_cookies() {
    json cookiesData;
    std::ifstream file(cookies_file);

    if (file.is_open()) {
        try {
            file >> cookiesData;
        }
        catch (const std::exception& e) {
            std::cerr << "Error reading JSON file: " << e.what() << std::endl;
        }
    }

    return cookiesData;
}

bool CookiesUtil::_save_cookies() {
    json cookiesJson(cookies);
    std::ofstream file(cookies_file);

    if (file.is_open()) {
        try {
            file << cookiesJson.dump(4); 
            return true;
        }
        catch (const std::exception& e) {
            std::cerr << "Error writing JSON file: " << e.what() << std::endl;
            return false;
        }
    }

    return false;
}

void CookiesUtil::set_cookies(json& request) {
    std::ostringstream oss;
    for (const auto& [key, value] : cookies) {
        if (oss.tellp() > 0) {
            oss << "; ";
        }
        oss << key << "=" << value;
    }
    request["cookies"] = oss.str();
}
