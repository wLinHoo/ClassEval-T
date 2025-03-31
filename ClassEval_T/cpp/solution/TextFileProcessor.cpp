
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

class TextFileProcessor {
public:
    explicit TextFileProcessor(const string& filename);

    json read_file_as_json();
    virtual std::string read_file() const;
    virtual void write_file(const std::string& content);
    string process_file();

private:
    string filename_;
};


TextFileProcessor::TextFileProcessor(const string& filename) : filename_(filename) {}


json TextFileProcessor::read_file_as_json() {
    ifstream file(filename_);
    json j;
    file >> j;
    return j;
}



string TextFileProcessor::read_file() const{
    ifstream file(filename_);
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}


void TextFileProcessor::write_file(const string& content) {
    ofstream file(filename_);
    file << content;
}


string TextFileProcessor::process_file() {
    string content = read_file();
    string result;

    for (char c : content) {
        if (isalpha(c)) {
            result += c;
        }
    }

    write_file(result);
    return result;
}
