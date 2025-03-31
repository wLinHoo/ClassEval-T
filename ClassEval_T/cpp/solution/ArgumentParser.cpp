
#include <sstream>
#include <utility>


#include <string>
#include <map>
#include <set>
#include <tuple>
#include <functional>

class ArgumentParser {
public:
    ArgumentParser();
    std::tuple<bool, std::set<std::string>> parse_arguments(const std::string& command_string);
    std::string get_argument(const std::string& key) const;
    void add_argument(const std::string& arg, bool required = false, const std::string& type = "string");

    std::map<std::string, std::string> arguments;
    std::set<std::string> required;
    std::map<std::string, std::string> types;
    std::map<std::string, std::function<std::string(const std::string&)>> type_converters;

    std::string convert_type(const std::string& arg, const std::string& value) const;
    void initialize_converters();
};

ArgumentParser::ArgumentParser()
{
    initialize_converters();
}

std::tuple<bool, std::set<std::string>> ArgumentParser::parse_arguments(const std::string &command_string)
{
    std::istringstream iss(command_string);
    std::string word;
    std::getline(iss, word, ' '); 

    while (iss >> word)
    {
        if (word.find("--") == 0)
        {
            auto key_value = word.substr(2);
            size_t pos = key_value.find('=');
            std::string key = key_value.substr(0, pos);
            std::string value = pos == std::string::npos ? "" : key_value.substr(pos + 1);
            arguments[key] = convert_type(key, value.empty() ? "1" : value);
        }
        else if (word.find("-") == 0)
        {
            std::string key = word.substr(1);
            std::string value;
            char nxt = iss.peek();
            if (!iss.eof() && iss.peek() != '-')
            {
                iss >> value;
                arguments[key] = convert_type(key, value);
            }
            else
            {
                arguments[key] = convert_type(key, "1");
            }
        }
    }

    std::set<std::string> missing_args;
    for (const auto &req : required)
    {
        if (arguments.find(req) == arguments.end())
        {
            missing_args.insert(req);
        }
    }

    return {missing_args.empty(), missing_args};
}

std::string ArgumentParser::get_argument(const std::string &key) const
{
    auto it = arguments.find(key);
    if (it != arguments.end())
    {
        return it->second;
    }
    return "";
}

void ArgumentParser::add_argument(const std::string &arg, bool required, const std::string &type)
{
    if (required)
    {
        this->required.insert(arg);
    }
    types[arg] = type;
}

std::string ArgumentParser::convert_type(const std::string &arg, const std::string &value) const
{
    if (types.find(arg) == types.end())
    {
        return value;
    }
    auto it = type_converters.find(types.at(arg));
    if (it != type_converters.end())
    {
        return it->second(value);
    }
    return value;
}

void ArgumentParser::initialize_converters()
{
    type_converters["int"] = [](const std::string &value)
    {
        try
        {
            return std::to_string(std::stoi(value));
        }
        catch (...)
        {
            return value;
        }
    };

    type_converters["bool"] = [](const std::string &value)
    {
        std::string tmp = value;
        if (tmp == "True")
            tmp = "1";
        if (tmp == "False")
            tmp = "0";
        return tmp;
    };
}
