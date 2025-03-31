#include <iostream>
#include <ctime>
#include <string>
#include <sstream> 

#include <string>
#include <unordered_map>

struct User {
    std::string name;
    int level;
    std::string address;
};

struct Authorization {
    User user;
    std::string jwt;
};

struct Request {
    std::string path;
    std::string method;
    Authorization auth;
};

class AccessGatewayFilter {
public:
    AccessGatewayFilter() {}
    bool filter(const Request& request);
    bool is_start_with(const std::string& request_uri);
    Authorization get_jwt_user(const Request& request);
    void set_current_user_info_and_log(const User& user);
};


bool AccessGatewayFilter::filter(const Request& request) {
    const std::string& request_uri = request.path;
    const std::string& method = request.method;

    if (is_start_with(request_uri)) {
        return true;
    }

    try {
        Authorization token = get_jwt_user(request);
        User user = token.user;
        if (user.level > 2) {
            set_current_user_info_and_log(user);
            return true;
        }
    }
    catch (...) {
        return false;
    }
    return false;
}

bool AccessGatewayFilter::is_start_with(const std::string& request_uri) {
    static const std::string start_with[] = { "/api", "/login" };
    for (const auto& s : start_with) {
        if (request_uri.find(s) == 0) {
            return true;
        }
    }
    return false;
}

Authorization AccessGatewayFilter::get_jwt_user(const Request& request) {
    Authorization token = request.auth;
    const User& user = token.user;

    if (token.jwt.find(user.name) == 0) {
        std::string jwt_str_date = token.jwt.substr(user.name.size());

        std::time_t jwt_timestamp;
        std::istringstream ss(jwt_str_date);
        ss >> jwt_timestamp;

        if (ss.fail()) {
            return Authorization{};
        }

        std::time_t now = std::time(nullptr);
        if (std::difftime(now, jwt_timestamp) >= 3 * 24 * 60 * 60) { 
            return Authorization{};
        }
    }
    return token;
}

void AccessGatewayFilter::set_current_user_info_and_log(const User& user) {
    std::cout << user.name << " " << user.address << " " << std::time(nullptr) << std::endl;
}
