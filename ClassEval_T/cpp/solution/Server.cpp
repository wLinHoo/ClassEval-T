
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <map>
#include <string>

class Server {
public:
    Server();

    std::vector<int> add_white_list(int addr);
    std::vector<int> del_white_list(int addr);
    int recv(const std::map<std::string, std::string>& info);
    std::string send(const std::map<std::string, std::string>& info);
    std::map<std::string, std::string> show(const std::string& type) const;

    std::vector<int> white_list;
    std::map<std::string, std::string> send_struct;
    std::map<std::string, std::string> receive_struct;
};

Server::Server() {
    white_list = {};
    send_struct = {};
    receive_struct = {};
}

std::vector<int> Server::add_white_list(int addr) {
    if (std::find(white_list.begin(), white_list.end(), addr) != white_list.end()) {
        return {};
    }
    else {
        white_list.push_back(addr);
        return white_list;
    }
}

std::vector<int> Server::del_white_list(int addr) {
    auto it = std::find(white_list.begin(), white_list.end(), addr);
    if (it == white_list.end()) {
        return {};
    }
    else {
        white_list.erase(it);
        return white_list;
    }
}

int Server::recv(const std::map<std::string, std::string>& info) {
    if (info.find("addr") == info.end() || info.find("content") == info.end()) {
        return -1;
    }
    int addr = std::stoi(info.at("addr"));
    std::string content = info.at("content");

    if (std::find(white_list.begin(), white_list.end(), addr) == white_list.end()) {
        return 0;  
    }
    else {
        receive_struct = { {"addr", std::to_string(addr)}, {"content", content} };
        return 1;  
    }
}

std::string Server::send(const std::map<std::string, std::string>& info) {
    if (info.find("addr") == info.end() || info.find("content") == info.end()) {
        return "info structure is not correct";
    }
    send_struct = { {"addr", info.at("addr")}, {"content", info.at("content")} };
    return "";
}

std::map<std::string, std::string> Server::show(const std::string& type) const {
    if (type == "send") {
        return send_struct;
    }
    else if (type == "receive") {
        return receive_struct;
    }
    else {
        return {};
    }
}
