
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <fstream>
#include <iostream>

#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <zip.h>

struct ZipFileInfo {
    std::string filename;
    std::string mode;
};

class ZipFileProcessor {
public:
    explicit ZipFileProcessor(const std::string& zip_file_path);

    bool extract_all(const std::string& output_directory);
    bool extract_file(const std::string& file_name, const std::string& output_directory);
    bool create_zip_file(const std::vector<std::string>& files, const std::string& output_zip_file);
    ZipFileInfo read_zip_file();  

private:
    bool extract_file_from_zip(zip_t* archive, zip_int64_t index, const std::string& output_file_path);
    bool create_directory_if_not_exists(const std::string& dir_path);
    zip_t* open_zip_file(int flags);

    std::string zip_file_path_;
};


ZipFileProcessor::ZipFileProcessor(const std::string& zip_file_path)
    : zip_file_path_(zip_file_path) {}

ZipFileInfo ZipFileProcessor::read_zip_file() {
    zip_t* archive = open_zip_file(ZIP_RDONLY);
    ZipFileInfo info;
    if (archive) {
        info.filename = zip_file_path_;  
        info.mode = "r";  
        zip_close(archive);
    }
    return info;
}


bool ZipFileProcessor::extract_all(const std::string& output_directory) {
    
    if (output_directory.empty()) {
        return false; 
    }
    
    if (!create_directory_if_not_exists(output_directory)) {
        
        return false;
    }

    
    zip_t* archive = open_zip_file(ZIP_RDONLY);
    if (!archive) return false;

    
    bool success = true;
    zip_int64_t num_entries = zip_get_num_entries(archive, ZIP_FL_UNCHANGED);
    for (zip_int64_t i = 0; i < num_entries; ++i) {
        zip_stat_t stat;
        if (zip_stat_index(archive, i, ZIP_FL_ENC_UTF_8, &stat) == 0) {
            std::string output_file_path = output_directory + "/" + stat.name;
            if (!extract_file_from_zip(archive, i, output_file_path)) {
                success = false;
            }
        }
    }

    zip_close(archive);
    return success;
}

bool ZipFileProcessor::extract_file(const std::string& file_name, const std::string& output_directory) {
    
    if (output_directory.empty()) {
        return false;
    }

    if (!create_directory_if_not_exists(output_directory)) {
        std::cerr << "Failed to create output directory: " << output_directory << std::endl;
        return false;
    }

    
    zip_t* archive = open_zip_file(ZIP_RDONLY);
    if (!archive) return false;

    
    zip_int64_t index = zip_name_locate(archive, file_name.c_str(), ZIP_FL_ENC_UTF_8);
    if (index < 0) {
        std::cerr << "File not found in zip: " << file_name << std::endl;
        zip_close(archive);
        return false;
    }

    std::string output_file_path = output_directory + "/" + file_name;
    bool success = extract_file_from_zip(archive, index, output_file_path);

    zip_close(archive);
    return success;
}

bool ZipFileProcessor::create_zip_file(const std::vector<std::string>& files, const std::string& output_zip_file) {
    zip_t* archive = zip_open(output_zip_file.c_str(), ZIP_CREATE | ZIP_TRUNCATE, nullptr);
    if (!archive) {
        std::cerr << "Error opening zip file: " << output_zip_file << std::endl;
        return false;
    }

    for (const auto& file_path : files) {
        zip_source_t* source = zip_source_file(archive, file_path.c_str(), 0, 0);
        if (!source) {
            std::cerr << "Error creating zip source for file: " << file_path << std::endl;
            zip_close(archive);
            return false;
        }
        
        if (zip_file_add(archive, file_path.c_str(), source, ZIP_FL_ENC_UTF_8) < 0) {
            std::cerr << "Error adding file to zip: " << file_path << std::endl;
            zip_source_free(source);
            zip_close(archive);
            return false;
        }
    }

    if (zip_close(archive) < 0) {
        std::cerr << "Error closing zip file: " << output_zip_file << std::endl;
        return false;
    }

    return true;
}


bool ZipFileProcessor::extract_file_from_zip(zip_t* archive, zip_int64_t index, const std::string& output_file_path) {
    zip_file_t* file = zip_fopen(archive, zip_get_name(archive, index, ZIP_FL_ENC_UTF_8), ZIP_FL_UNCHANGED);
    if (!file) {
        std::cerr << "Failed to open file in zip: " << zip_get_name(archive, index, ZIP_FL_ENC_UTF_8) << std::endl;
        return false;
    }

    std::ofstream out_file(output_file_path, std::ios::binary);
    if (!out_file.is_open()) {
        std::cerr << "Failed to open output file: " << output_file_path << std::endl;
        zip_fclose(file);
        return false;
    }

    char buffer[4096];
    zip_int64_t bytes_read;
    while ((bytes_read = zip_fread(file, buffer, sizeof(buffer))) > 0) {
        out_file.write(buffer, bytes_read);
        if (!out_file) {
            std::cerr << "Failed to write to file: " << output_file_path << std::endl;
            zip_fclose(file);
            return false;
        }
    }

    zip_fclose(file);
    return true;
}

bool ZipFileProcessor::create_directory_if_not_exists(const std::string& dir_path) {
    namespace fs = boost::filesystem;
    if (!fs::exists(dir_path)) {
        return fs::create_directories(dir_path);
    }
    return true;
}



zip_t* ZipFileProcessor::open_zip_file(int flags) {
    zip_t* archive = zip_open(zip_file_path_.c_str(), flags, nullptr);
    if (!archive) {
        std::cerr << "Failed to open zip file: " << zip_file_path_ << std::endl;
    }
    return archive;
}
