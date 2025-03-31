#include <string>
#include <map>
#include <algorithm>

class URLHandler {
public:
    explicit URLHandler(const std::string& url);

    std::string get_scheme() const;
    std::string get_host() const;
    std::string get_path() const;
    std::map<std::string, std::string> get_query_params() const;
    std::string get_fragment() const;

private:
    std::string url;
};

URLHandler::URLHandler(const std::string& url) : url(url) {}

std::string URLHandler::get_scheme() const {
    size_t scheme_end = url.find("://");
    if (scheme_end != std::string::npos) {
        return url.substr(0, scheme_end);
    }
    return "";
}

std::string URLHandler::get_host() const {
    size_t scheme_end = url.find("://");
    if (scheme_end != std::string::npos) {
        std::string url_without_scheme = url.substr(scheme_end + 3);
        size_t host_end = url_without_scheme.find("/");
        if (host_end != std::string::npos) {
            return url_without_scheme.substr(0, host_end);
        }
        return url_without_scheme;
    }
    return "";
}

std::string URLHandler::get_path() const {
    size_t scheme_end = url.find("://");
    if (scheme_end != std::string::npos) {
        std::string url_without_scheme = url.substr(scheme_end + 3);
        size_t host_end = url_without_scheme.find("/");
        if (host_end != std::string::npos) {
            return url_without_scheme.substr(host_end);
        }
    }
    return "";
}

std::map<std::string, std::string> URLHandler::get_query_params() const {
    std::map<std::string, std::string> params;
    size_t query_start = url.find("?");
    size_t fragment_start = url.find("#");
    if (query_start != std::string::npos) {
        std::string query_string = url.substr(query_start + 1, fragment_start - query_start - 1);
        if (!query_string.empty()) {
            size_t pos = 0;
            std::string token;
            while ((pos = query_string.find("&")) != std::string::npos) {
                token = query_string.substr(0, pos);
                size_t equal_pos = token.find("=");
                if (equal_pos != std::string::npos) {
                    std::string key = token.substr(0, equal_pos);
                    std::string value = token.substr(equal_pos + 1);
                    params[key] = value;
                }
                query_string.erase(0, pos + 1);
            }
            size_t equal_pos = query_string.find("=");
            if (equal_pos != std::string::npos) {
                std::string key = query_string.substr(0, equal_pos);
                std::string value = query_string.substr(equal_pos + 1);
                params[key] = value;
            }
        }
    }
    return params;
}

std::string URLHandler::get_fragment() const {
    size_t fragment_start = url.find("#");
    if (fragment_start != std::string::npos) {
        return url.substr(fragment_start + 1);
    }
    return "";
}
