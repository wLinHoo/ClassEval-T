#include <gtest/gtest.h>
#include <boost/filesystem.hpp>
#include <fstream>
#include <string>
#include "pch.h"

class ZipFileProcessorTest : public ::testing::Test {
protected:
    void SetUp() override {
        test_folder = "test_folder";
        output_directory = "output_directory";
        zip_file_name = "example.zip";
        new_zip_file = "new_zip_file.zip";

        boost::filesystem::create_directory(test_folder);
        example_file_path = test_folder + "/example1.txt";
        std::ofstream file(example_file_path);
        file << "This is an example file.";
        file.close();
    }

    void TearDown() override {
        boost::filesystem::remove_all(test_folder);
        boost::filesystem::remove(zip_file_name);
        boost::filesystem::remove(new_zip_file);
    }

    std::string test_folder;
    std::string output_directory;
    std::string zip_file_name;
    std::string new_zip_file;
    std::string example_file_path;
};

TEST_F(ZipFileProcessorTest, TestZipFileProcessor) {
    std::string test_folder = "test_folder";
    boost::filesystem::create_directory(test_folder);
    std::string example_file_path = test_folder + "/example1.txt";
    std::ofstream file(example_file_path);
    file << "This is an example file.";
    file.close();

    std::string zip_file_name = "example.zip";
    {
        zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
        zip_file_add(archive, "example1.txt", source, ZIP_FL_ENC_UTF_8);
        zip_close(archive);
    }

    ZipFileProcessor processor(zip_file_name);
    ZipFileInfo zip_file = processor.read_zip_file();

    ASSERT_EQ(zip_file.filename, "example.zip");
    ASSERT_EQ(zip_file.mode, "r");

    std::string output_directory = "output_directory";
    ASSERT_TRUE(processor.extract_all(output_directory));
    ASSERT_TRUE(boost::filesystem::exists(output_directory + "/example1.txt"));

    std::vector<std::string> files_to_zip = { example_file_path };
    std::string new_zip_file = "new_zip_file.zip";
    ASSERT_TRUE(processor.create_zip_file(files_to_zip, new_zip_file));
    ASSERT_TRUE(boost::filesystem::exists(new_zip_file));

    ASSERT_TRUE(processor.extract_file("example1.txt", output_directory));
    ASSERT_TRUE(boost::filesystem::exists(output_directory + "/example1.txt"));

    boost::filesystem::remove_all(output_directory);
    boost::filesystem::remove(zip_file_name);
    boost::filesystem::remove(example_file_path);
    boost::filesystem::remove(new_zip_file);
    boost::filesystem::remove(test_folder);
}

class ZipFileProcessorTestReadZipFile : public ::testing::Test {
protected:
    void SetUp() override {
        test_folder = "test_folder";
        boost::filesystem::create_directory(test_folder);
    }

    void TearDown() override {
        boost::filesystem::remove_all(test_folder);
    }

    std::string test_folder;
};

TEST_F(ZipFileProcessorTestReadZipFile, test_read_zip_file_1) {
    std::string example_file_path = test_folder + "/example1.txt";
    {
        std::ofstream file(example_file_path);
        file << "This is an example file.";
    }

    std::string zip_file_name = "example1.zip";
    {
        zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
        zip_file_add(archive, "example1.txt", source, ZIP_FL_OVERWRITE);
        zip_close(archive);
    }

    ZipFileProcessor processor(zip_file_name);
    auto zip_file = processor.read_zip_file();

    EXPECT_EQ(zip_file.filename, "example1.zip");
    EXPECT_EQ(zip_file.mode, "r");
}

TEST_F(ZipFileProcessorTestReadZipFile, test_read_zip_file_2) {
    std::string example_file_path = test_folder + "/example.txt";
    {
        std::ofstream file(example_file_path);
        file << "This is an example file.";
    }

    std::string zip_file_name = "example2.zip";
    {
        zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
        zip_file_add(archive, "example.txt", source, ZIP_FL_OVERWRITE);
        zip_close(archive);
    }

    ZipFileProcessor processor(zip_file_name);
    auto zip_file = processor.read_zip_file();

    EXPECT_EQ(zip_file.filename, "example2.zip");
    EXPECT_EQ(zip_file.mode, "r");
}

TEST_F(ZipFileProcessorTestReadZipFile, test_read_zip_file_3) {
    std::string example_file_path = test_folder + "/example.txt";
    {
        std::ofstream file(example_file_path);
        file << "This is an example file.";
    }

    std::string zip_file_name = "example3.zip";
    {
        zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
        zip_file_add(archive, "example.txt", source, ZIP_FL_OVERWRITE);
        zip_close(archive);
    }

    ZipFileProcessor processor(zip_file_name);
    auto zip_file = processor.read_zip_file();

    EXPECT_EQ(zip_file.filename, "example3.zip");
    EXPECT_EQ(zip_file.mode, "r");
}

TEST_F(ZipFileProcessorTestReadZipFile, test_read_zip_file_4) {
    std::string example_file_path = test_folder + "/example.txt";
    {
        std::ofstream file(example_file_path);
        file << "This is an example file.";
    }

    std::string zip_file_name = "example4.zip";
    {
        zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
        zip_file_add(archive, "example.txt", source, ZIP_FL_OVERWRITE);
        zip_close(archive);
    }

    ZipFileProcessor processor(zip_file_name);
    auto zip_file = processor.read_zip_file();

    EXPECT_EQ(zip_file.filename, "example4.zip");
    EXPECT_EQ(zip_file.mode, "r");
}

TEST_F(ZipFileProcessorTestReadZipFile, test_read_zip_file_5) {
    std::string example_file_path = test_folder + "/example.txt";
    {
        std::ofstream file(example_file_path);
        file << "This is an example file.";
    }

    std::string zip_file_name = "example5.zip";
    {
        zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
        zip_file_add(archive, "example.txt", source, ZIP_FL_OVERWRITE);
        zip_close(archive);
    }

    ZipFileProcessor processor(zip_file_name);
    auto zip_file = processor.read_zip_file();

    EXPECT_EQ(zip_file.filename, "example5.zip");
    EXPECT_EQ(zip_file.mode, "r");
}

TEST_F(ZipFileProcessorTestReadZipFile, test_read_zip_file_6) {
    ZipFileProcessor processor("");

    auto zip_file = processor.read_zip_file();
    EXPECT_EQ(zip_file.filename, "");
    EXPECT_EQ(zip_file.mode, "");
}

class ZipFileProcessorTestExtractAll : public ::testing::Test {
protected:
    void SetUp() override {
        test_folder = "test_folder";
        boost::filesystem::create_directory(test_folder);
    }

    void TearDown() override {
        boost::filesystem::remove_all(test_folder);
    }

    std::string test_folder;
};

TEST_F(ZipFileProcessorTestExtractAll, test_extract_all_1) {
    std::string example_file_path = test_folder + "/example1.txt";
    {
        std::ofstream file(example_file_path);
        file << "This is an example file.";
    }

    std::string zip_file_name = "example.zip";
    {
        zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
        zip_file_add(archive, "example1.txt", source, ZIP_FL_OVERWRITE);
        zip_close(archive);
    }

    ZipFileProcessor processor(zip_file_name);
    std::string output_directory = "output_directory";
    boost::filesystem::create_directory(output_directory);

    bool success = processor.extract_all(output_directory);
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists(output_directory + "/example1.txt"));

    boost::filesystem::remove_all(output_directory);
    boost::filesystem::remove(zip_file_name);
}

TEST_F(ZipFileProcessorTestExtractAll, test_extract_all_2) {
    std::string example_file_path = test_folder + "/example2.txt";
    {
        std::ofstream file(example_file_path);
        file << "This is an example file.";
    }

    std::string zip_file_name = "example.zip";
    {
        zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
        zip_file_add(archive, "example2.txt", source, ZIP_FL_OVERWRITE);
        zip_close(archive);
    }

    ZipFileProcessor processor(zip_file_name);
    std::string output_directory = "output_directory";
    boost::filesystem::create_directory(output_directory);

    bool success = processor.extract_all(output_directory);
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists(output_directory + "/example2.txt"));

    boost::filesystem::remove_all(output_directory);
    boost::filesystem::remove(zip_file_name);
}

TEST_F(ZipFileProcessorTestExtractAll, test_extract_all_3) {
    std::string example_file_path = test_folder + "/example3.txt";
    {
        std::ofstream file(example_file_path);
        file << "This is an example file.";
    }

    std::string zip_file_name = "example.zip";
    {
        zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
        zip_file_add(archive, "example3.txt", source, ZIP_FL_OVERWRITE);
        zip_close(archive);
    }

    ZipFileProcessor processor(zip_file_name);
    std::string output_directory = "output_directory";
    boost::filesystem::create_directory(output_directory);

    bool success = processor.extract_all(output_directory);
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists(output_directory + "/example3.txt"));

    boost::filesystem::remove_all(output_directory);
    boost::filesystem::remove(zip_file_name);
}

TEST_F(ZipFileProcessorTestExtractAll, test_extract_all_4) {
    std::string example_file_path = test_folder + "/example4.txt";
    {
        std::ofstream file(example_file_path);
        file << "This is an example file.";
    }

    std::string zip_file_name = "example.zip";
    {
        zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
        zip_file_add(archive, "example4.txt", source, ZIP_FL_OVERWRITE);
        zip_close(archive);
    }

    ZipFileProcessor processor(zip_file_name);
    std::string output_directory = "output_directory";
    boost::filesystem::create_directory(output_directory);

    bool success = processor.extract_all(output_directory);
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists(output_directory + "/example4.txt"));

    boost::filesystem::remove_all(output_directory);
    boost::filesystem::remove(zip_file_name);
}

TEST_F(ZipFileProcessorTestExtractAll, test_extract_all_5) {
    std::string example_file_path = test_folder + "/example5.txt";
    {
        std::ofstream file(example_file_path);
        file << "This is an example file.";
    }

    std::string zip_file_name = "example.zip";
    {
        zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
        zip_file_add(archive, "example5.txt", source, ZIP_FL_OVERWRITE);
        zip_close(archive);
    }

    ZipFileProcessor processor(zip_file_name);
    std::string output_directory = "output_directory";
    boost::filesystem::create_directory(output_directory);

    bool success = processor.extract_all(output_directory);
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists(output_directory + "/example5.txt"));

    boost::filesystem::remove_all(output_directory);
    boost::filesystem::remove(zip_file_name);
}

TEST_F(ZipFileProcessorTestExtractAll, test_extract_all_6) {
    ZipFileProcessor processor("");

    bool success = processor.extract_all("");
    EXPECT_FALSE(success);
}

class ZipFileProcessorTestExtractFile : public ::testing::Test {
protected:
    void SetUp() override {
        
        if (!boost::filesystem::exists("output_directory")) {
            boost::filesystem::create_directory("output_directory");
        }
    }

    void TearDown() override {
        
        if (boost::filesystem::exists("output_directory")) {
            boost::filesystem::remove_all("output_directory");
        }
    }
};

TEST_F(ZipFileProcessorTestExtractFile, test_extract_file_1) {
    std::string test_folder = "test_folder";
    boost::filesystem::create_directory(test_folder);

    std::string example_file_path = test_folder + "/example1.txt";
    std::ofstream out_file(example_file_path, std::ios::binary);
    out_file << "This is an example file.";
    out_file.close();

    std::string zip_file_name = "example.zip";
    zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE, nullptr);
    zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
    zip_file_add(archive, "example1.txt", source, ZIP_FL_ENC_UTF_8);
    zip_close(archive);

    ZipFileProcessor processor(zip_file_name);

    bool success = processor.extract_file("example1.txt", "output_directory");
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists("output_directory/example1.txt"));

    boost::filesystem::remove(zip_file_name);
    boost::filesystem::remove(example_file_path);
    boost::filesystem::remove_all(test_folder);
}

TEST_F(ZipFileProcessorTestExtractFile, test_extract_file_2) {
    std::string test_folder = "test_folder";
    boost::filesystem::create_directory(test_folder);

    std::string example_file_path = test_folder + "/example2.txt";
    std::ofstream out_file(example_file_path, std::ios::binary);
    out_file << "This is an example file.";
    out_file.close();

    std::string zip_file_name = "example.zip";
    zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE, nullptr);
    zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
    zip_file_add(archive, "example2.txt", source, ZIP_FL_ENC_UTF_8);
    zip_close(archive);

    ZipFileProcessor processor(zip_file_name);

    bool success = processor.extract_file("example2.txt", "output_directory");
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists("output_directory/example2.txt"));

    boost::filesystem::remove(zip_file_name);
    boost::filesystem::remove(example_file_path);
    boost::filesystem::remove_all(test_folder);
}

TEST_F(ZipFileProcessorTestExtractFile, test_extract_file_3) {
    std::string test_folder = "test_folder";
    boost::filesystem::create_directory(test_folder);

    std::string example_file_path = test_folder + "/example3.txt";
    std::ofstream out_file(example_file_path, std::ios::binary);
    out_file << "This is an example file.";
    out_file.close();

    std::string zip_file_name = "example.zip";
    zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE, nullptr);
    zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
    zip_file_add(archive, "example3.txt", source, ZIP_FL_ENC_UTF_8);
    zip_close(archive);

    ZipFileProcessor processor(zip_file_name);

    bool success = processor.extract_file("example3.txt", "output_directory");
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists("output_directory/example3.txt"));

    boost::filesystem::remove(zip_file_name);
    boost::filesystem::remove(example_file_path);
    boost::filesystem::remove_all(test_folder);
}

TEST_F(ZipFileProcessorTestExtractFile, test_extract_file_4) {
    std::string test_folder = "test_folder";
    boost::filesystem::create_directory(test_folder);

    std::string example_file_path = test_folder + "/example4.txt";
    std::ofstream out_file(example_file_path, std::ios::binary);
    out_file << "This is an example file.";
    out_file.close();

    std::string zip_file_name = "example.zip";
    zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE, nullptr);
    zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
    zip_file_add(archive, "example4.txt", source, ZIP_FL_ENC_UTF_8);
    zip_close(archive);

    ZipFileProcessor processor(zip_file_name);

    bool success = processor.extract_file("example4.txt", "output_directory");
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists("output_directory/example4.txt"));

    boost::filesystem::remove(zip_file_name);
    boost::filesystem::remove(example_file_path);
    boost::filesystem::remove_all(test_folder);
}

TEST_F(ZipFileProcessorTestExtractFile, test_extract_file_5) {
    std::string test_folder = "test_folder";
    boost::filesystem::create_directory(test_folder);

    std::string example_file_path = test_folder + "/example5.txt";
    std::ofstream out_file(example_file_path, std::ios::binary);
    out_file << "This is an example file.";
    out_file.close();

    std::string zip_file_name = "example.zip";
    zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE, nullptr);
    zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
    zip_file_add(archive, "example5.txt", source, ZIP_FL_ENC_UTF_8);
    zip_close(archive);

    ZipFileProcessor processor(zip_file_name);

    bool success = processor.extract_file("example5.txt", "output_directory");
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists("output_directory/example5.txt"));

    boost::filesystem::remove(zip_file_name);
    boost::filesystem::remove(example_file_path);
    boost::filesystem::remove_all(test_folder);
}

TEST_F(ZipFileProcessorTestExtractFile, test_extract_file_6) {
    ZipFileProcessor processor("");

    bool success = processor.extract_file("", "");
    EXPECT_FALSE(success);  
}

class ZipFileProcessorTestCreateZipFile : public ::testing::Test {
protected:
    void SetUp() override {
        
        if (!boost::filesystem::exists("output_directory")) {
            boost::filesystem::create_directory("output_directory");
        }
    }

    void TearDown() override {
        
        if (boost::filesystem::exists("output_directory")) {
            boost::filesystem::remove_all("output_directory");
        }
    }
};

TEST_F(ZipFileProcessorTestCreateZipFile, test_create_zip_file_1) {
    std::string test_folder = "test_folder";
    boost::filesystem::create_directory(test_folder);

    std::string example_file_path = test_folder + "/example1.txt";
    std::ofstream out_file(example_file_path, std::ios::binary);
    out_file << "This is an example file.";
    out_file.close();

    std::string zip_file_name = "example.zip";
    zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE, nullptr);
    zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
    zip_file_add(archive, "example1.txt", source, ZIP_FL_ENC_UTF_8);
    zip_close(archive);

    ZipFileProcessor processor(zip_file_name);

    std::string new_zip_file = "new_zip_file.zip";
    std::vector<std::string> files_to_zip = { example_file_path };

    bool success = processor.create_zip_file(files_to_zip, new_zip_file);
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists(new_zip_file));

    boost::filesystem::remove(example_file_path);
    boost::filesystem::remove_all(test_folder);
    boost::filesystem::remove(new_zip_file);
}

TEST_F(ZipFileProcessorTestCreateZipFile, test_create_zip_file_2) {
    std::string test_folder = "test_folder";
    boost::filesystem::create_directory(test_folder);

    std::string example_file_path = test_folder + "/example2.txt";
    std::ofstream out_file(example_file_path, std::ios::binary);
    out_file << "This is an example file.";
    out_file.close();

    std::string zip_file_name = "example.zip";
    zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE, nullptr);
    zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
    zip_file_add(archive, "example2.txt", source, ZIP_FL_ENC_UTF_8);
    zip_close(archive);

    ZipFileProcessor processor(zip_file_name);

    std::string new_zip_file = "new_zip_file.zip";
    std::vector<std::string> files_to_zip = { example_file_path };

    bool success = processor.create_zip_file(files_to_zip, new_zip_file);
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists(new_zip_file));

    boost::filesystem::remove(example_file_path);
    boost::filesystem::remove_all(test_folder);
    boost::filesystem::remove(new_zip_file);
}

TEST_F(ZipFileProcessorTestCreateZipFile, test_create_zip_file_3) {
    std::string test_folder = "test_folder";
    boost::filesystem::create_directory(test_folder);

    std::string example_file_path = test_folder + "/example3.txt";
    std::ofstream out_file(example_file_path, std::ios::binary);
    out_file << "This is an example file.";
    out_file.close();

    std::string zip_file_name = "example.zip";
    zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE, nullptr);
    zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
    zip_file_add(archive, "example3.txt", source, ZIP_FL_ENC_UTF_8);
    zip_close(archive);

    ZipFileProcessor processor(zip_file_name);

    std::string new_zip_file = "new_zip_file.zip";
    std::vector<std::string> files_to_zip = { example_file_path };

    bool success = processor.create_zip_file(files_to_zip, new_zip_file);
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists(new_zip_file));

    boost::filesystem::remove(example_file_path);
    boost::filesystem::remove_all(test_folder);
    boost::filesystem::remove(new_zip_file);
}

TEST_F(ZipFileProcessorTestCreateZipFile, test_create_zip_file_4) {
    std::string test_folder = "test_folder";
    boost::filesystem::create_directory(test_folder);

    std::string example_file_path = test_folder + "/example4.txt";
    std::ofstream out_file(example_file_path, std::ios::binary);
    out_file << "This is an example file.";
    out_file.close();

    std::string zip_file_name = "example.zip";
    zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE, nullptr);
    zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
    zip_file_add(archive, "example4.txt", source, ZIP_FL_ENC_UTF_8);
    zip_close(archive);

    ZipFileProcessor processor(zip_file_name);

    std::string new_zip_file = "new_zip_file.zip";
    std::vector<std::string> files_to_zip = { example_file_path };

    bool success = processor.create_zip_file(files_to_zip, new_zip_file);
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists(new_zip_file));

    boost::filesystem::remove(example_file_path);
    boost::filesystem::remove_all(test_folder);
    boost::filesystem::remove(new_zip_file);
}

TEST_F(ZipFileProcessorTestCreateZipFile, test_create_zip_file_5) {
    std::string test_folder = "test_folder";
    boost::filesystem::create_directory(test_folder);

    std::string example_file_path = test_folder + "/example5.txt";
    std::ofstream out_file(example_file_path, std::ios::binary);
    out_file << "This is an example file.";
    out_file.close();

    std::string zip_file_name = "example.zip";
    zip_t* archive = zip_open(zip_file_name.c_str(), ZIP_CREATE, nullptr);
    zip_source_t* source = zip_source_file(archive, example_file_path.c_str(), 0, 0);
    zip_file_add(archive, "example5.txt", source, ZIP_FL_ENC_UTF_8);
    zip_close(archive);

    ZipFileProcessor processor(zip_file_name);

    std::string new_zip_file = "new_zip_file.zip";
    std::vector<std::string> files_to_zip = { example_file_path };

    bool success = processor.create_zip_file(files_to_zip, new_zip_file);
    EXPECT_TRUE(success);
    EXPECT_TRUE(boost::filesystem::exists(new_zip_file));

    boost::filesystem::remove(example_file_path);
    boost::filesystem::remove_all(test_folder);
    boost::filesystem::remove(new_zip_file);
}

TEST_F(ZipFileProcessorTestCreateZipFile, test_create_zip_file_6) {
    ZipFileProcessor processor("");

    std::vector<std::string> files_to_zip;
    std::string new_zip_file = "";

    bool success = processor.create_zip_file(files_to_zip, new_zip_file);
    EXPECT_FALSE(success);  
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}