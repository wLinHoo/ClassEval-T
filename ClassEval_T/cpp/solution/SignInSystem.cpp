#include <unordered_map>
#include <vector>
#include <string>

class SignInSystem {
public:
    SignInSystem();
    bool add_user(const std::string& username);
    bool sign_in(const std::string& username);
    bool check_sign_in(const std::string& username);
    bool all_signed_in();
    std::vector<std::string> all_not_signed_in();

private:
    std::unordered_map<std::string, bool> users;
};

SignInSystem::SignInSystem() {}

bool SignInSystem::add_user(const std::string& username) {
    auto result = users.find(username);
    if (result != users.end()) {
        return false;
    }
    else {
        users[username] = false;
        return true;
    }
}

bool SignInSystem::sign_in(const std::string& username) {
    auto result = users.find(username);
    if (result == users.end()) {
        return false;
    }
    else {
        users[username] = true;
        return true;
    }
}

bool SignInSystem::check_sign_in(const std::string& username) {
    auto result = users.find(username);
    if (result == users.end()) {
        return false;
    }
    else {
        return result->second;
    }
}

bool SignInSystem::all_signed_in() {
    for (const auto& pair : users) {
        if (!pair.second) {
            return false;
        }
    }
    return true;
}

std::vector<std::string> SignInSystem::all_not_signed_in() {
    std::vector<std::string> not_signed_in_users;
    for (const auto& pair : users) {
        if (!pair.second) {
            not_signed_in_users.push_back(pair.first);
        }
    }
    return not_signed_in_users;
}
