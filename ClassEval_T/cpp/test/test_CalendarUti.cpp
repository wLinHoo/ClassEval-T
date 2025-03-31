#include <gtest/gtest.h>
#include "pch.h" 

class CalendarTestAddEvent : public ::testing::Test {
protected:
    CalendarUtil calendar;
};

TEST_F(CalendarTestAddEvent, test_add_event) {
    calendar.add_event({
        time_from_timestamp(1672531200), 
        time_from_timestamp(1672531200),
        time_from_timestamp(1672534800), 
        "New Year"
        });
    EXPECT_EQ(calendar.events.size(), 1);
    EXPECT_EQ(calendar.events[0].date, time_from_timestamp(1672531200));
    EXPECT_EQ(calendar.events[0].start_time, time_from_timestamp(1672531200));
    EXPECT_EQ(calendar.events[0].end_time, time_from_timestamp(1672534800));
    EXPECT_EQ(calendar.events[0].description, "New Year");
}

TEST_F(CalendarTestAddEvent, test_add_event_2) {
    calendar.add_event({
        time_from_timestamp(1672531200), 
        time_from_timestamp(1672531200),
        time_from_timestamp(1672534800), 
        "New Year"
        });
    calendar.add_event({
        time_from_timestamp(1672531200), 
        time_from_timestamp(1672531200),
        time_from_timestamp(1672534800), 
        "New Year"
        });
    ASSERT_EQ(calendar.events.size(), 2);
    EXPECT_EQ(calendar.events[0].date, time_from_timestamp(1672531200));
    EXPECT_EQ(calendar.events[0].start_time, time_from_timestamp(1672531200));
    EXPECT_EQ(calendar.events[0].end_time, time_from_timestamp(1672534800));
    EXPECT_EQ(calendar.events[0].description, "New Year");
    EXPECT_EQ(calendar.events[1].date, time_from_timestamp(1672531200));
    EXPECT_EQ(calendar.events[1].start_time, time_from_timestamp(1672531200));
    EXPECT_EQ(calendar.events[1].end_time, time_from_timestamp(1672534800));
    EXPECT_EQ(calendar.events[1].description, "New Year");
}

TEST_F(CalendarTestAddEvent, test_add_event_3) {
    calendar.add_event({
        time_from_timestamp(1672531200), 
        time_from_timestamp(1672531200),
        time_from_timestamp(1672617600), 
        "New Year"
        });
    ASSERT_EQ(calendar.events.size(), 1);
    EXPECT_EQ(calendar.events[0].date, time_from_timestamp(1672531200));
    EXPECT_EQ(calendar.events[0].start_time, time_from_timestamp(1672531200));
    EXPECT_EQ(calendar.events[0].end_time, time_from_timestamp(1672617600));
    EXPECT_EQ(calendar.events[0].description, "New Year");
}

TEST_F(CalendarTestAddEvent, test_add_event_4) {
    calendar.add_event({
        time_from_timestamp(1672531200), 
        time_from_timestamp(1672531200),
        time_from_timestamp(1672614000), 
        "New Year"
        });
    ASSERT_EQ(calendar.events.size(), 1);
    EXPECT_EQ(calendar.events[0].date, time_from_timestamp(1672531200));
    EXPECT_EQ(calendar.events[0].start_time, time_from_timestamp(1672531200));
    EXPECT_EQ(calendar.events[0].end_time, time_from_timestamp(1672614000));
    EXPECT_EQ(calendar.events[0].description, "New Year");
}

TEST_F(CalendarTestAddEvent, test_add_event_5) {
    calendar.add_event({
        time_from_timestamp(1672531200), 
        time_from_timestamp(1672531200),
        time_from_timestamp(1672596000), 
        "New Year"
        });
    ASSERT_EQ(calendar.events.size(), 1);
    EXPECT_EQ(calendar.events[0].date, time_from_timestamp(1672531200));
    EXPECT_EQ(calendar.events[0].start_time, time_from_timestamp(1672531200));
    EXPECT_EQ(calendar.events[0].end_time, time_from_timestamp(1672596000));
    EXPECT_EQ(calendar.events[0].description, "New Year");
}


class CalendarTestRemoveEvent : public ::testing::Test {
protected:
    CalendarUtil calendar;
};

TEST_F(CalendarTestRemoveEvent, test_remove_event) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year"}
    };
    calendar.remove_event({ time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year" });
    ASSERT_TRUE(calendar.events.empty());
}

TEST_F(CalendarTestRemoveEvent, test_remove_event_2) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year"},
        {time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year"}
    };
    calendar.remove_event({ time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year" });
    ASSERT_EQ(calendar.events.size(), 1);
    ASSERT_EQ(calendar.events[0], (CalendarUtil::Event{ time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year" }));
}

TEST_F(CalendarTestRemoveEvent, test_remove_event_3) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year"},
        {time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year"}
    };
    calendar.remove_event({ time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year" });
    ASSERT_EQ(calendar.events.size(), 1);
    ASSERT_EQ(calendar.events[0], (CalendarUtil::Event{ time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year" }));
}

TEST_F(CalendarTestRemoveEvent, test_remove_event_4) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672610400), "New Year"},
        {time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year"}
    };
    calendar.remove_event({ time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year" });
    ASSERT_EQ(calendar.events.size(), 1);
    ASSERT_EQ(calendar.events[0], (CalendarUtil::Event{ time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672610400), "New Year" }));
}

TEST_F(CalendarTestRemoveEvent, test_remove_event_5) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672538400), "New Year"},
        {time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year"}
    };
    calendar.remove_event({ time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year" });
    ASSERT_EQ(calendar.events.size(), 1);
    ASSERT_EQ(calendar.events[0], (CalendarUtil::Event{ time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672538400), "New Year" }));
}

TEST_F(CalendarTestRemoveEvent, test_remove_event_6) {
    calendar.events = {};
    calendar.remove_event({ time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year" });
    ASSERT_TRUE(calendar.events.empty());
}


class CalendarTestGetEvents : public ::testing::Test {
protected:
    CalendarUtil calendar;
};

TEST_F(CalendarTestGetEvents, test_get_events) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year"}
    };
    auto events_on_date = calendar.get_events(time_from_timestamp(1672531200));
    ASSERT_EQ(events_on_date.size(), 1);
    ASSERT_EQ(events_on_date[0], (CalendarUtil::Event{ time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year" }));
}

TEST_F(CalendarTestGetEvents, test_get_events_2) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year"}
    };
    auto events_on_date = calendar.get_events(time_from_timestamp(1672617600));
    ASSERT_TRUE(events_on_date.empty());
}


class CalendarTestIsAvailable : public ::testing::Test {
protected:
    CalendarUtil calendar;
};

TEST_F(CalendarTestIsAvailable, test_is_available) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year"}
    };
    bool available = calendar.is_available(time_from_timestamp(1672531200), time_from_timestamp(1672534800));
    ASSERT_FALSE(available);
}

TEST_F(CalendarTestIsAvailable, test_is_available_2) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year"}
    };
    bool available = calendar.is_available(time_from_timestamp(1672534800), time_from_timestamp(1672538400));
    ASSERT_TRUE(available);
}

TEST_F(CalendarTestIsAvailable, test_is_available_3) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year"}
    };
    bool available = calendar.is_available(time_from_timestamp(1672531200), time_from_timestamp(1672531800));
    ASSERT_FALSE(available);
}

TEST_F(CalendarTestIsAvailable, test_is_available_4) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year"}
    };
    bool available = calendar.is_available(time_from_timestamp(1672531800), time_from_timestamp(1672534800));
    ASSERT_FALSE(available);
}

TEST_F(CalendarTestIsAvailable, test_is_available_5) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672534800), "New Year"}
    };
    bool available = calendar.is_available(time_from_timestamp(1672534800), time_from_timestamp(1672536000));
    ASSERT_TRUE(available);
}


class CalendarTestGetAvailableSlots : public ::testing::Test {
protected:
    CalendarUtil calendar;
};

TEST_F(CalendarTestGetAvailableSlots, test_get_available_slots) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672614000), "New Year"}
    };
    auto available_slots = calendar.get_available_slots(time_from_timestamp(1672531200));
    ASSERT_EQ(available_slots.size(), 1);
    ASSERT_EQ(available_slots[0].first, time_from_timestamp(1672614000));
    ASSERT_EQ(available_slots[0].second, time_from_timestamp(1672617600));
}

TEST_F(CalendarTestGetAvailableSlots, test_get_available_slots_2) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672534800), time_from_timestamp(1672538400), "New Year"}
    };
    auto available_slots = calendar.get_available_slots(time_from_timestamp(1672531200));
    ASSERT_EQ(available_slots.size(), 23);
}

TEST_F(CalendarTestGetAvailableSlots, test_get_available_slots_3) {
    calendar.events = {
        {time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year"}
    };
    auto available_slots = calendar.get_available_slots(time_from_timestamp(1672531200));
    ASSERT_EQ(available_slots.size(), 24);
}

TEST_F(CalendarTestGetAvailableSlots, test_get_available_slots_4) {
    calendar.events = {
        {time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year"}
    };
    auto available_slots = calendar.get_available_slots(time_from_timestamp(1672531200));
    ASSERT_EQ(available_slots.size(), 24);
}

TEST_F(CalendarTestGetAvailableSlots, test_get_available_slots_5) {
    calendar.events = {
        {time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year"}
    };
    auto available_slots = calendar.get_available_slots(time_from_timestamp(1672531200));
    ASSERT_EQ(available_slots.size(), 24);
}


class CalendarTestGetUpcomingEvents : public ::testing::Test {
protected:
    CalendarUtil calendar;
};

TEST_F(CalendarTestGetUpcomingEvents, test_get_upcoming_events) {
    calendar.events = {
        {time_from_timestamp(1672531200), time_from_timestamp(1672531200), time_from_timestamp(1672545600), "New Year"}
    };
    auto upcoming_events = calendar.get_upcoming_events(1);
    ASSERT_TRUE(upcoming_events.empty());
}

TEST_F(CalendarTestGetUpcomingEvents, test_get_upcoming_events_2) {
    calendar.events = {
        {time_from_timestamp(1672533600), time_from_timestamp(1672533600), time_from_timestamp(1672537200), "New Year"}
    };
    auto upcoming_events = calendar.get_upcoming_events(1);
    ASSERT_TRUE(upcoming_events.empty());
}

TEST_F(CalendarTestGetUpcomingEvents, test_get_upcoming_events_3) {
    calendar.events = {
        {time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year"}
    };
    auto upcoming_events = calendar.get_upcoming_events(1);
    ASSERT_TRUE(upcoming_events.empty());
}

TEST_F(CalendarTestGetUpcomingEvents, test_get_upcoming_events_4) {
    calendar.events = {
        {time_from_timestamp(1672617600), time_from_timestamp(1672617600), time_from_timestamp(1672621200), "New Year"}
    };
    auto upcoming_events = calendar.get_upcoming_events(2);
    ASSERT_TRUE(upcoming_events.empty());
}

TEST_F(CalendarTestGetUpcomingEvents, test_get_upcoming_events_5) {
    
    auto now = std::chrono::system_clock::now();
    calendar.events = {
        {now-std::chrono::months(6), now- std::chrono::months(6), now- std::chrono::months(6) + std::chrono::hours(23), "New Year"}, 
        {now + std::chrono::months(6), now + std::chrono::months(6), now + std::chrono::months(6) + std::chrono::hours(1), "New Year 2"} 
    };

    
    auto upcoming_events = calendar.get_upcoming_events(1);
    ASSERT_EQ(upcoming_events.size(), 1);
    ASSERT_EQ(upcoming_events[0].date, now + std::chrono::months(6)); 
    ASSERT_EQ(upcoming_events[0].start_time, now + std::chrono::months(6)); 
    ASSERT_EQ(upcoming_events[0].end_time, now + std::chrono::months(6) + std::chrono::hours(1)); 
    ASSERT_EQ(upcoming_events[0].description, "New Year 2");
}


class CalendarTestMain : public ::testing::Test {
protected:
    CalendarUtil calendar;
};

TEST_F(CalendarTestMain, test_main) {
    
    calendar.add_event({ std::chrono::system_clock::from_time_t(1672531200), 
                        std::chrono::system_clock::from_time_t(1672531200), 
                        std::chrono::system_clock::from_time_t(1672534800), 
                        "New Year" });

    auto events = calendar.get_events(std::chrono::system_clock::from_time_t(1672531200)); 
    ASSERT_EQ(events.size(), 1);
    ASSERT_EQ(events[0].date, std::chrono::system_clock::from_time_t(1672531200));
    ASSERT_EQ(events[0].start_time, std::chrono::system_clock::from_time_t(1672531200));
    ASSERT_EQ(events[0].end_time, std::chrono::system_clock::from_time_t(1672534800));
    ASSERT_EQ(events[0].description, "New Year");

    
    calendar.remove_event({ std::chrono::system_clock::from_time_t(1672531200), 
                           std::chrono::system_clock::from_time_t(1672531200), 
                           std::chrono::system_clock::from_time_t(1672534800), 
                           "New Year" });

    events = calendar.get_events(std::chrono::system_clock::from_time_t(1672531200)); 
    ASSERT_TRUE(events.empty());

    
    calendar.events = {
        {std::chrono::system_clock::from_time_t(1672531200), 
         std::chrono::system_clock::from_time_t(1672531200), 
         std::chrono::system_clock::from_time_t(1672531200) + std::chrono::hours(23), 
         "New Year"}
    };

    events = calendar.get_events(std::chrono::system_clock::from_time_t(1672531200)); 
    ASSERT_EQ(events.size(), 1);
    ASSERT_EQ(events[0].date, std::chrono::system_clock::from_time_t(1672531200));
    ASSERT_EQ(events[0].start_time, std::chrono::system_clock::from_time_t(1672531200));
    ASSERT_EQ(events[0].end_time, std::chrono::system_clock::from_time_t(1672531200) + std::chrono::hours(23));
    ASSERT_EQ(events[0].description, "New Year");

    
    ASSERT_FALSE(calendar.is_available(std::chrono::system_clock::from_time_t(1672531200), 
        std::chrono::system_clock::from_time_t(1672534800))); 

    
    auto slots = calendar.get_available_slots(std::chrono::system_clock::from_time_t(1672531200)); 
    ASSERT_EQ(slots.size(), 1);
    ASSERT_EQ(slots[0].first, std::chrono::system_clock::from_time_t(1672531200) + std::chrono::hours(23)); 
    ASSERT_EQ(slots[0].second, std::chrono::system_clock::from_time_t(1672531200) + std::chrono::hours(24)); 

    
    auto upcoming_events = calendar.get_upcoming_events(1);
    ASSERT_TRUE(upcoming_events.empty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}