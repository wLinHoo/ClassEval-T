
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <locale>
#include <codecvt>

#include <string>
#include <vector>

class UrlPath {
public:
    UrlPath();

    void add(const std::string& segment);
    void parse(const std::string& path, const std::string& charset);
    static std::string fix_path(const std::string& path);

    const std::vector<std::string>& get_segments() const;
    bool with_end_tag() const;

private:
    std::vector<std::string> segments;
    bool _with_end_tag;
};


UrlPath::UrlPath() : _with_end_tag(false) {}

void UrlPath::add(const std::string& segment) {
    segments.push_back(fix_path(segment));
}

void UrlPath::parse(const std::string& path, const std::string& charset) {
    if (!path.empty()) {
        if (path.back() == '/') {
            _with_end_tag = true;
        }

        std::string fixed_path = fix_path(path);
        if (!fixed_path.empty()) {
            std::istringstream ss(fixed_path);
            std::string segment;
            while (std::getline(ss, segment, '/')) {
                std::string decoded_seg;
                std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
                std::wstring wide_segment = converter.from_bytes(segment);
                for (wchar_t ch : wide_segment) {
                    if (ch == '%') {

                    }
                    else {
                        decoded_seg.push_back(static_cast<char>(ch));
                    }
                }
                segments.push_back(decoded_seg);
            }
        }
    }
}

std::string UrlPath::fix_path(const std::string& path) {
    if (path.empty()) {
        return "";
    }

    std::string segment_str = path;
    if (segment_str.front() == '/') {
        segment_str.erase(segment_str.begin());
    }
    if (segment_str.back() == '/') {
        segment_str.pop_back();
    }
    return segment_str;
}

const std::vector<std::string>& UrlPath::get_segments() const {
    return segments;
}

bool UrlPath::with_end_tag() const {
    return _with_end_tag;
}
