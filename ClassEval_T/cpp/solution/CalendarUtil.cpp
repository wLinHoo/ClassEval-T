
#include <ctime>
#include <vector>
#include <utility>
#include <iostream>
#include <iomanip>

#include <chrono>
#include <string>
#include <vector>
#include <map>

class CalendarUtil {
public:
    struct Event {
        std::chrono::system_clock::time_point date;
        std::chrono::system_clock::time_point start_time;
        std::chrono::system_clock::time_point end_time;
        std::string description;

        bool operator==(const Event& other) const {
            return date == other.date &&
                start_time == other.start_time &&
                end_time == other.end_time &&
                description == other.description;
        }
    };

    void add_event(const Event& event);
    void remove_event(const Event& event);
    std::vector<Event> get_events(const std::chrono::system_clock::time_point& date);
    bool is_available(const std::chrono::system_clock::time_point& start_time,
        const std::chrono::system_clock::time_point& end_time);
    std::vector<std::pair<std::chrono::system_clock::time_point, std::chrono::system_clock::time_point>> get_available_slots(const std::chrono::system_clock::time_point& date);
    std::vector<Event> get_upcoming_events(size_t num_events);
    std::vector<Event> events;
};

std::chrono::system_clock::time_point time_from_timestamp(time_t timestamp);

void CalendarUtil::add_event(const Event& event) {
    events.push_back(event);
}

void CalendarUtil::remove_event(const Event& event) {
    auto it = std::find(events.begin(), events.end(), event);
    if (it != events.end()) {
        events.erase(it);
    }
}

std::vector<CalendarUtil::Event> CalendarUtil::get_events(const std::chrono::system_clock::time_point& date) {
    std::vector<Event> events_on_date;
    auto date_tm = std::chrono::system_clock::to_time_t(date);
    std::tm date_tm_struct;
    localtime_s(&date_tm_struct, &date_tm);
    for (const auto& event : events) {
        auto event_date_tm = std::chrono::system_clock::to_time_t(event.date);
        std::tm event_date_tm_struct;
        localtime_s(&event_date_tm_struct, &event_date_tm);
        if (date_tm_struct.tm_year == event_date_tm_struct.tm_year &&
            date_tm_struct.tm_mon == event_date_tm_struct.tm_mon &&
            date_tm_struct.tm_mday == event_date_tm_struct.tm_mday) {
            events_on_date.push_back(event);
        }
    }
    return events_on_date;
}

bool CalendarUtil::is_available(const std::chrono::system_clock::time_point& start_time,
    const std::chrono::system_clock::time_point& end_time) {
    for (const auto& event : events) {
        if (start_time < event.end_time && end_time > event.start_time) {
            return false;
        }
    }
    return true;
}

std::vector<std::pair<std::chrono::system_clock::time_point, std::chrono::system_clock::time_point>> CalendarUtil::get_available_slots(const std::chrono::system_clock::time_point& date) {
    std::vector<std::pair<std::chrono::system_clock::time_point, std::chrono::system_clock::time_point>> available_slots;
    auto start_time = date;
    auto end_time = date + std::chrono::hours(24) - std::chrono::seconds(1);

    while (start_time < end_time) {
        auto slot_end_time = start_time + std::chrono::hours(1);
        if (is_available(start_time, slot_end_time)) {
            available_slots.emplace_back(start_time, slot_end_time);
        }
        start_time = slot_end_time;
    }

    return available_slots;
}

std::vector<CalendarUtil::Event> CalendarUtil::get_upcoming_events(size_t num_events) {
    auto now = std::chrono::system_clock::now();
    std::vector<Event> upcoming_events;
    for (const auto& event : events) {
        if (event.start_time >= now) {
            upcoming_events.push_back(event);
            if (upcoming_events.size() == num_events) {
                break;
            }
        }
    }
    return upcoming_events;
}

std::chrono::system_clock::time_point time_from_timestamp(time_t timestamp) {
    std::tm tm;
    localtime_s(&tm, &timestamp);
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}
