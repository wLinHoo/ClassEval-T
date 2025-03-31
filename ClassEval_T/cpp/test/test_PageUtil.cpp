#include <gtest/gtest.h>
#include <vector>
#include <unordered_map>
#include <string>
#include "pch.h"

class PageUtilTestGetPage : public ::testing::Test {
protected:
    std::vector<int> data;
    int page_size;
    PageUtil* page_util;

    void SetUp() override {
        data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        page_size = 3;
        page_util = new PageUtil(data, page_size);
    }

    void TearDown() override {
        delete page_util;
    }
};

TEST_F(PageUtilTestGetPage, TestGetPage1) {
    int page_number = 1;
    std::vector<int> expected_page = { 1, 2, 3 };
    std::vector<int> actual_page = page_util->get_page(page_number);
    EXPECT_EQ(actual_page, expected_page);
}

TEST_F(PageUtilTestGetPage, TestGetPage2) {
    int page_number = 2;
    std::vector<int> expected_page = { 4, 5, 6 };
    std::vector<int> actual_page = page_util->get_page(page_number);
    EXPECT_EQ(actual_page, expected_page);
}

TEST_F(PageUtilTestGetPage, TestGetPage3) {
    int page_number = 3;
    std::vector<int> expected_page = { 7, 8, 9 };
    std::vector<int> actual_page = page_util->get_page(page_number);
    EXPECT_EQ(actual_page, expected_page);
}

TEST_F(PageUtilTestGetPage, TestGetPage4) {
    int page_number = 4;
    std::vector<int> expected_page = { 10 };
    std::vector<int> actual_page = page_util->get_page(page_number);
    EXPECT_EQ(actual_page, expected_page);
}

TEST_F(PageUtilTestGetPage, TestGetPage5) {
    int invalid_page_number = 0;
    std::vector<int> empty_page = {};
    std::vector<int> actual_page = page_util->get_page(invalid_page_number);
    EXPECT_EQ(actual_page, empty_page);
}

class PageUtilTestGetPageInfo : public ::testing::Test {
protected:
    std::vector<int> data;
    int page_size;
    PageUtil* page_util;

    void SetUp() override {
        data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        page_size = 3;
        page_util = new PageUtil(data, page_size);
    }

    void TearDown() override {
        delete page_util;
    }
};

TEST_F(PageUtilTestGetPageInfo, TestGetPageInfo1) {
    int page_number = 2;
    std::unordered_map<std::string, std::variant<int, std::vector<int>, bool>> expected_info;
    expected_info["current_page"] = 2;
    expected_info["per_page"] = 3;
    expected_info["total_pages"] = 4;
    expected_info["total_items"] = 10;
    expected_info["has_previous"] = true;
    expected_info["has_next"] = true;
    expected_info["data"] = std::vector<int>{ 4, 5, 6 };
    std::unordered_map<std::string, std::variant<int, std::vector<int>, bool>> actual_info = page_util->get_page_info(page_number);
    EXPECT_EQ(actual_info, expected_info);
}

TEST_F(PageUtilTestGetPageInfo, test_get_page_info_2) {
    int page_number = 1;

    std::unordered_map<std::string, std::variant<int, std::vector<int>, bool>> expected_info;
    expected_info["current_page"] = 1;
    expected_info["per_page"] = 3;
    expected_info["total_pages"] = 4;
    expected_info["total_items"] = 10;
    expected_info["has_previous"] = false;
    expected_info["has_next"] = true;
    expected_info["data"] = std::vector<int>{ 1, 2, 3 };

    auto actual_info = page_util->get_page_info(page_number);

    EXPECT_EQ(actual_info, expected_info);
}

TEST_F(PageUtilTestGetPageInfo, test_get_page_info_3) {
    int page_number = 3;

    std::unordered_map<std::string, std::variant<int, std::vector<int>, bool>> expected_info;
    expected_info["current_page"] = 3;
    expected_info["per_page"] = 3;
    expected_info["total_pages"] = 4;
    expected_info["total_items"] = 10;
    expected_info["has_previous"] = true;
    expected_info["has_next"] = true;
    expected_info["data"] = std::vector<int>{ 7, 8, 9 };

    auto actual_info = page_util->get_page_info(page_number);

    EXPECT_EQ(actual_info, expected_info);
}

TEST_F(PageUtilTestGetPageInfo, test_get_page_info_4) {
    int page_number = 4;

    std::unordered_map<std::string, std::variant<int, std::vector<int>, bool>> expected_info;
    expected_info["current_page"] = 4;
    expected_info["per_page"] = 3;
    expected_info["total_pages"] = 4;
    expected_info["total_items"] = 10;
    expected_info["has_previous"] = true;
    expected_info["has_next"] = false;
    expected_info["data"] = std::vector<int>{ 10 };

    auto actual_info = page_util->get_page_info(page_number);

    EXPECT_EQ(actual_info, expected_info);
}

TEST_F(PageUtilTestGetPageInfo, test_get_page_info_5) {
    int invalid_page_number = 5;

    std::unordered_map<std::string, std::variant<int, std::vector<int>, bool>> empty_info;

    auto actual_info = page_util->get_page_info(invalid_page_number);

    EXPECT_EQ(actual_info, empty_info);
}

class PageUtilTestSearch : public ::testing::Test {
protected:
    std::vector<int> data;
    int page_size;
    PageUtil* page_util;

    void SetUp() override {
        data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        page_size = 3;
        page_util = new PageUtil(data, page_size);
    }

    void TearDown() override {
        delete page_util;
    }
};

TEST_F(PageUtilTestSearch, TestSearch1) {
    std::string keyword = "1";
    std::unordered_map<std::string, std::variant<std::string, int, std::vector<int>>> expected_results;
    expected_results["keyword"] = "1";
    expected_results["total_results"] = 2;
    expected_results["total_pages"] = 1;
    expected_results["results"] = std::vector<int>{ 1, 10 };
    auto actual_results = page_util->search(keyword);
    EXPECT_EQ(actual_results, expected_results);
}

TEST_F(PageUtilTestSearch, TestSearch2) {
    std::string keyword = "2";
    std::unordered_map<std::string, std::variant<std::string, int, std::vector<int>>> expected_results;
    expected_results["keyword"] = "2";
    expected_results["total_results"] = 1;
    expected_results["total_pages"] = 1;
    expected_results["results"] = std::vector<int>{ 2 };
    auto actual_results = page_util->search(keyword);
    EXPECT_EQ(actual_results, expected_results);
}

TEST_F(PageUtilTestSearch, TestSearch3) {
    std::string keyword = "3";
    std::unordered_map<std::string, std::variant<std::string, int, std::vector<int>>> expected_results;
    expected_results["keyword"] = "3";
    expected_results["total_results"] = 1;
    expected_results["total_pages"] = 1;
    expected_results["results"] = std::vector<int>{ 3 }; 
    auto actual_results = page_util->search(keyword);
    EXPECT_EQ(actual_results, expected_results);
}

TEST_F(PageUtilTestSearch, TestSearch4) {
    std::string keyword = "4";
    std::unordered_map<std::string, std::variant<std::string, int, std::vector<int>>> expected_results;
    expected_results["keyword"] = "4";
    expected_results["total_results"] = 1;
    expected_results["total_pages"] = 1;
    expected_results["results"] = std::vector<int>{ 4 };
    auto actual_results = page_util->search(keyword);
    EXPECT_EQ(actual_results, expected_results);
}

TEST_F(PageUtilTestSearch, TestSearch5) {
    std::string keyword = "11";
    std::unordered_map<std::string, std::variant< std::string, int, std::vector<int>>> expected_results;
    expected_results["keyword"] = "11";
    expected_results["total_results"] = 0;
    expected_results["total_pages"] = 0;
    expected_results["results"] = std::vector<int>{  };
    auto actual_results = page_util->search(keyword);
    EXPECT_EQ(actual_results, expected_results);
}

class PageUtilTest : public ::testing::Test {
protected:
    std::vector<int> data;
    int page_size;
    PageUtil* page_util;

    void SetUp() override {
        data = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        page_size = 3;
        page_util = new PageUtil(data, page_size);
    }

    void TearDown() override {
        delete page_util;
    }
};

TEST_F(PageUtilTest, TestPageUtil) {
    int page_number = 1;
    std::vector<int> expected_page = { 1, 2, 3 };
    std::vector<int> actual_page = page_util->get_page(page_number);
    EXPECT_EQ(actual_page, expected_page);

    page_number = 2;
    std::unordered_map<std::string, std::variant<int, std::vector<int>, bool>> expected_info = {
        {"current_page", 2},
        {"per_page", 3},
        {"total_pages", 4},
        {"total_items", 10},
        {"has_previous", true},
        {"has_next", true},
        {"data", std::vector<int>{4, 5, 6}}
    };
    auto actual_info = page_util->get_page_info(page_number);
    EXPECT_EQ(actual_info, expected_info);

    std::string keyword = "4";
    std::unordered_map<std::string, std::variant< std::string, int, std::vector<int>>> expected_results;
    expected_results["keyword"] = "4";
    expected_results["total_results"] = 1;
    expected_results["total_pages"] = 1;
    expected_results["results"] = std::vector<int>{ 4 };
    auto actual_results = page_util->search(keyword);
    EXPECT_EQ(actual_results, expected_results);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}