
#include <string>
#include <unordered_map>
#include <stdexcept>

class BookManagement {
public:
    BookManagement();

    void add_book(const std::string& title, int quantity = 1);
    void remove_book(const std::string& title, int quantity);
    std::unordered_map<std::string, int> view_inventory() const;
    int view_book_quantity(const std::string& title) const;

private:
    std::unordered_map<std::string, int> inventory;
};

BookManagement::BookManagement() {}

void BookManagement::add_book(const std::string& title, int quantity) {
    if (inventory.find(title) != inventory.end()) {
        inventory[title] += quantity;
    }
    else {
        inventory[title] = quantity;
    }
}

void BookManagement::remove_book(const std::string& title, int quantity) {
    auto it = inventory.find(title);
    if (it == inventory.end() || it->second < quantity) {
        throw std::runtime_error("Insufficient quantity or book not found");
    }
    it->second -= quantity;
    if (it->second == 0) {
        inventory.erase(it);
    }
}

std::unordered_map<std::string, int> BookManagement::view_inventory() const {
    return inventory;
}

int BookManagement::view_book_quantity(const std::string& title) const {
    auto it = inventory.find(title);
    if (it == inventory.end()) {
        return 0;
    }
    return it->second;
}
