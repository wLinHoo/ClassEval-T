
#include <fstream>
#include <iostream>
#include <sys/stat.h>

#include <string>
#include <nlohmann/json.hpp>

class JSONProcessor {
public:
    
    int read_json(const std::string& file_path, nlohmann::json& output);

    
    int write_json(const nlohmann::json& data, const std::string& file_path);

    
    int process_json(const std::string& file_path, const std::string& remove_key);
};


int JSONProcessor::read_json(const std::string& file_path, nlohmann::json& output) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        return 0;  
    }

    try {
        file >> output;
        if (output.is_null()) {
            return -1;  
        }
    }
    catch (...) {
        return -1;  
    }

    return 1;  
}


int JSONProcessor::write_json(const nlohmann::json& data, const std::string& file_path) {
    std::ofstream file(file_path);
    if (!file.is_open()) {
        return -1;  
    }

    try {
        file << data.dump(4);  
    }
    catch (...) {
        return -1;  
    }

    return 1;
}


int JSONProcessor::process_json(const std::string& file_path, const std::string& remove_key) {
    nlohmann::json data;
    int result = read_json(file_path, data);

    if (result != 1) {
        return 0;  
    }

    if (data.contains(remove_key)) {
        data.erase(remove_key);
        return write_json(data, file_path);  
    }
    else {
        return 0;  
    }
}
