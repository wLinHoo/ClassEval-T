#include "pch.h"
#include <gtest/gtest.h>

class BookManagementTestAddBook : public ::testing::Test {
protected:
    BookManagement bookManagement;
};

TEST_F(BookManagementTestAddBook, test_add_book_1) {
    bookManagement.add_book("book1");
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{{"book1", 1}}));
}

TEST_F(BookManagementTestAddBook, test_add_book_2) {
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{}));
}

TEST_F(BookManagementTestAddBook, test_add_book_3) {
    bookManagement.add_book("book1");
    bookManagement.add_book("book1", 2);
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{{"book1", 3}}));
}

TEST_F(BookManagementTestAddBook, test_add_book_4) {
    bookManagement.add_book("book1", 2);
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{{"book1", 2}}));
}

TEST_F(BookManagementTestAddBook, test_add_book_5) {
    bookManagement.add_book("book1", 2);
    bookManagement.add_book("book1");
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{{"book1", 3}}));
}

class BookManagementTestRemoveBook : public ::testing::Test {
protected:
    void SetUp() override {
        bookManagement.add_book("book1", 2);
        bookManagement.add_book("book2");
    }

    BookManagement bookManagement;
};

TEST_F(BookManagementTestRemoveBook, test_remove_book_1) {
    bookManagement.remove_book("book1", 2);
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{{"book2", 1}}));
}

TEST_F(BookManagementTestRemoveBook, test_remove_book_2) {
    bookManagement.remove_book("book1", 1);
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{{"book1", 1}, { "book2", 1 }}));
}

TEST_F(BookManagementTestRemoveBook, test_remove_book_3) {
    EXPECT_THROW(bookManagement.remove_book("book3", 1), std::runtime_error);
}

TEST_F(BookManagementTestRemoveBook, test_remove_book_4) {
    EXPECT_THROW(bookManagement.remove_book("book2", 2), std::runtime_error);
}

TEST_F(BookManagementTestRemoveBook, test_remove_book_5) {
    EXPECT_THROW(bookManagement.remove_book("book2", 5), std::runtime_error);
}

class BookManagementTestViewInventory : public ::testing::Test {
protected:
    BookManagement bookManagement;
};

TEST_F(BookManagementTestViewInventory, test_view_inventory_1) {
    bookManagement.add_book("book1", 2);
    bookManagement.add_book("book2");
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{{"book1", 2}, { "book2", 1 }}));
}

TEST_F(BookManagementTestViewInventory, test_view_inventory_2) {
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{}));
}

TEST_F(BookManagementTestViewInventory, test_view_inventory_3) {
    bookManagement.add_book("book1", 2);
    bookManagement.add_book("book2");
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{{"book1", 2}, { "book2", 1 }}));
}

TEST_F(BookManagementTestViewInventory, test_view_inventory_4) {
    bookManagement.add_book("book1", 2);
    bookManagement.add_book("book2");
    bookManagement.remove_book("book1", 2);
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{{"book2", 1}}));
}

TEST_F(BookManagementTestViewInventory, test_view_inventory_5) {
    bookManagement.add_book("book1", 2);
    bookManagement.add_book("book2", 1);
    bookManagement.remove_book("book1", 2);
    bookManagement.remove_book("book2", 1);
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{}));
}

class BookManagementTestViewBookQuantity : public ::testing::Test {
protected:
    BookManagement bookManagement;
};

TEST_F(BookManagementTestViewBookQuantity, test_view_book_quantity_1) {
    bookManagement.add_book("book1", 2);
    EXPECT_EQ(bookManagement.view_book_quantity("book1"), 2);
}

TEST_F(BookManagementTestViewBookQuantity, test_view_book_quantity_2) {
    EXPECT_EQ(bookManagement.view_book_quantity("book1"), 0);
}

TEST_F(BookManagementTestViewBookQuantity, test_view_book_quantity_3) {
    bookManagement.add_book("book1", 2);
    EXPECT_EQ(bookManagement.view_book_quantity("book1"), 2);
}

TEST_F(BookManagementTestViewBookQuantity, test_view_book_quantity_4) {
    bookManagement.add_book("book1", 2);
    bookManagement.remove_book("book1", 2);
    EXPECT_EQ(bookManagement.view_book_quantity("book1"), 0);
}

TEST_F(BookManagementTestViewBookQuantity, test_view_book_quantity_5) {
    bookManagement.add_book("book1", 3);
    bookManagement.remove_book("book1", 2);
    EXPECT_EQ(bookManagement.view_book_quantity("book1"), 1);
}

class BookManagementTestMain : public ::testing::Test {
protected:
    BookManagement bookManagement;
};

TEST_F(BookManagementTestMain, test_main) {
    bookManagement.add_book("book1", 2);
    bookManagement.add_book("book2");
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{{"book1", 2}, { "book2", 1 }}));

    bookManagement.remove_book("book2", 1);
    EXPECT_EQ(bookManagement.view_inventory(), (std::unordered_map<std::string, int>{{"book1", 2}}));
    EXPECT_EQ(bookManagement.view_book_quantity("book2"), 0);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}