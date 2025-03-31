#include <string>

class PersonRequest {
public:
    PersonRequest(const std::string& name, const std::string& sex, const std::string& phoneNumber);

    std::string name;
    std::string sex;
    std::string phoneNumber;

private:
    std::string validate_name(const std::string& name);
    std::string validate_sex(const std::string& sex);
    std::string validate_phone_number(const std::string& phoneNumber);
    bool is_all_digits(const std::string& s);
};


PersonRequest::PersonRequest(const std::string& name, const std::string& sex, const std::string& phoneNumber)
    : name(validate_name(name)), sex(validate_sex(sex)), phoneNumber(validate_phone_number(phoneNumber)) {}


std::string PersonRequest::validate_name(const std::string& name) {
    if (name.empty() || name.length() > 33) {
        return "";
    }
    return name;
}


std::string PersonRequest::validate_sex(const std::string& sex) {
    if (sex != "Man" && sex != "Woman" && sex != "UGM") {
        return "";
    }
    return sex;
}


std::string PersonRequest::validate_phone_number(const std::string& phoneNumber) {
    if (phoneNumber.empty() || phoneNumber.length() != 11 || !is_all_digits(phoneNumber)) {
        return "";
    }
    return phoneNumber;
}


bool PersonRequest::is_all_digits(const std::string& s) {
    for (char c : s) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
