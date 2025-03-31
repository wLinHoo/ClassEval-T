
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

#include <string>
#include <unordered_map>
#include <vector>

class Chat {
public:
    struct Message {
        std::string sender;
        std::string receiver;
        std::string message;
        std::string timestamp;
    };

    bool add_user(const std::string& username);
    bool remove_user(const std::string& username);
    bool send_message(const std::string& sender, const std::string& receiver, const std::string& message);
    std::vector<Message> get_messages(const std::string& username) const;
    std::unordered_map<std::string, std::vector<Message>> get_users() const;
    std::string get_current_time() const;

private:
    std::unordered_map<std::string, std::vector<Message>> users;
};

bool Chat::add_user(const std::string& username) {
    if (users.find(username) != users.end()) {
        return false;
    }
    users[username] = {};
    return true;
}

bool Chat::remove_user(const std::string& username) {
    return users.erase(username) > 0;
}

bool Chat::send_message(const std::string& sender, const std::string& receiver, const std::string& message) {
    if (users.find(sender) == users.end() || users.find(receiver) == users.end()) {
        return false;
    }

    std::string timestamp = get_current_time();
    Message message_info = { sender, receiver, message, timestamp };
    users[sender].push_back(message_info);
    users[receiver].push_back(message_info);
    return true;
}

std::vector<Chat::Message> Chat::get_messages(const std::string& username) const {
    if (users.find(username) == users.end()) {
        return {};
    }
    return users.at(username);
}

std::unordered_map<std::string, std::vector<Chat::Message>> Chat::get_users() const {
    return users;
}

std::string Chat::get_current_time() const {
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_c);

    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}
