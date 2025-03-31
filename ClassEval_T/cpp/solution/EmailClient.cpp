
#include <iostream>
#include <sstream>

#include <string>
#include <vector>
#include <map>
#include <ctime>

class EmailClient {
public:
    EmailClient(const std::string& addr, int capacity);
    bool send_to(EmailClient& recv, const std::string& content, int size);
    std::map<std::string, std::string> fetch();
    bool is_full_with_one_more_email(int size);
    int get_occupied_size();
    void clear_inbox(int size);
    std::string addr;
    int capacity;
    std::vector<std::map<std::string, std::string>> inbox;

    std::string get_current_time();
};


EmailClient::EmailClient(const std::string& addr, int capacity)
    : addr(addr), capacity(capacity) {}


std::string EmailClient::get_current_time() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    std::ostringstream oss;
    oss << 1900 + ltm->tm_year << "-"
        << 1 + ltm->tm_mon << "-"
        << ltm->tm_mday << " "
        << ltm->tm_hour << ":"
        << ltm->tm_min << ":"
        << ltm->tm_sec;
    return oss.str();
}


bool EmailClient::send_to(EmailClient& recv, const std::string& content, int size) {
    if (!recv.is_full_with_one_more_email(size)) {
        std::map<std::string, std::string> email = {
            {"sender", this->addr},
            {"receiver", recv.addr},
            {"content", content},
            {"size", std::to_string(size)},
            {"time", get_current_time()},
            {"state", "unread"}
        };
        recv.inbox.push_back(email);
        return true;
    }
    else {
        this->clear_inbox(size);
        return false;
    }
}


std::map<std::string, std::string> EmailClient::fetch() {
    if (inbox.empty()) {
        return {};
    }
    for (auto& email : inbox) {
        if (email["state"] == "unread") {
            email["state"] = "read";
            return email;
        }
    }
    return {};
}


bool EmailClient::is_full_with_one_more_email(int size) {
    int occupied_size = get_occupied_size();
    return occupied_size + size > capacity;
}


int EmailClient::get_occupied_size() {
    int occupied_size = 0;
    for (const auto& email : inbox) {
        occupied_size += std::stoi(email.at("size"));
    }
    return occupied_size;
}


void EmailClient::clear_inbox(int size) {
    if (addr.empty()) return;

    int freed_space = 0;
    while (freed_space < size && !inbox.empty()) {
        freed_space += std::stoi(inbox.front()["size"]);
        inbox.erase(inbox.begin());
    }
}

