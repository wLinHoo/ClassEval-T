#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <time.h>

class TimeUtils {
public:
    TimeUtils();

    std::string get_current_time() const;
    std::string get_current_date() const;
    std::string add_seconds(int seconds);
    std::tm string_to_datetime(const std::string& str) const;
    std::string datetime_to_string(const std::tm& datetime) const;
    int get_minutes(const std::string& string_time1, const std::string& string_time2) const;
    std::string get_format_time(int year, int month, int day, int hour, int minute, int second) const;

    std::tm datetime;

};

TimeUtils::TimeUtils() {
    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);
    datetime = *std::localtime(&time_t_now);
}

std::string TimeUtils::get_current_time() const {
    std::stringstream ss;
    ss << std::put_time(&datetime, "%H:%M:%S");
    return ss.str();
}

std::string TimeUtils::get_current_date() const {
    std::stringstream ss;
    ss << std::put_time(&datetime, "%Y-%m-%d");
    return ss.str();
}

std::string TimeUtils::add_seconds(int seconds) {
    auto time_t_now = std::mktime(const_cast<std::tm*>(&datetime));
    time_t_now += seconds;
    std::tm new_datetime = *std::localtime(&time_t_now);
    datetime = new_datetime;
    std::stringstream ss;
    ss << std::put_time(&new_datetime, "%H:%M:%S");
    return ss.str();
}

std::tm TimeUtils::string_to_datetime(const std::string& str) const {
    std::tm tm = {};
    std::istringstream ss(str);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    return tm;
}

std::string TimeUtils::datetime_to_string(const std::tm& datetime) const {
    std::stringstream ss;
    ss << std::put_time(&datetime, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

int TimeUtils::get_minutes(const std::string& string_time1, const std::string& string_time2) const {
    std::tm time1 = string_to_datetime(string_time1);
    std::tm time2 = string_to_datetime(string_time2);

    auto time_t1 = std::mktime(&time1);
    auto time_t2 = std::mktime(&time2);

    return std::difftime(time_t2, time_t1) / 60;
}

std::string TimeUtils::get_format_time(int year, int month, int day, int hour, int minute, int second) const {
    std::tm tm = {};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;

    std::stringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}
