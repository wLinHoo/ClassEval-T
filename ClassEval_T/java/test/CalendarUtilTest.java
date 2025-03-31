package org.example;

import org.apache.commons.math3.util.Pair;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Nested;
import org.junit.jupiter.api.Test;

import java.time.LocalDateTime;
import java.time.ZoneOffset;
import java.util.ArrayList;
import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class CalendarUtilTest {

    private CalendarUtil calendar;

    @BeforeEach
    void setUp() {
        calendar = new CalendarUtil();
    }

    private LocalDateTime timeFromTimestamp(long timestamp) {
        return LocalDateTime.ofEpochSecond(timestamp, 0, ZoneOffset.UTC);
    }

    @Nested
    class CalendarTestAddEvent {

        @Test
        void testAddEvent() {
            calendar.addEvent(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            ));
            assertEquals(1, calendar.events.size());
            assertEquals(timeFromTimestamp(1672531200), calendar.events.get(0).date);
            assertEquals(timeFromTimestamp(1672531200), calendar.events.get(0).start_time);
            assertEquals(timeFromTimestamp(1672534800), calendar.events.get(0).end_time);
            assertEquals("New Year", calendar.events.get(0).description);
        }

        @Test
        void testAddEvent2() {
            calendar.addEvent(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            ));
            calendar.addEvent(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            ));
            assertEquals(2, calendar.events.size());
            assertEquals(timeFromTimestamp(1672531200), calendar.events.get(0).date);
            assertEquals(timeFromTimestamp(1672531200), calendar.events.get(0).start_time);
            assertEquals(timeFromTimestamp(1672534800), calendar.events.get(0).end_time);
            assertEquals("New Year", calendar.events.get(0).description);
            assertEquals(timeFromTimestamp(1672531200), calendar.events.get(1).date);
            assertEquals(timeFromTimestamp(1672531200), calendar.events.get(1).start_time);
            assertEquals(timeFromTimestamp(1672534800), calendar.events.get(1).end_time);
            assertEquals("New Year", calendar.events.get(1).description);
        }

        @Test
        void testAddEvent3() {
            calendar.addEvent(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672617600),
                    "New Year"
            ));
            assertEquals(1, calendar.events.size());
            assertEquals(timeFromTimestamp(1672531200), calendar.events.get(0).date);
            assertEquals(timeFromTimestamp(1672531200), calendar.events.get(0).start_time);
            assertEquals(timeFromTimestamp(1672617600), calendar.events.get(0).end_time);
            assertEquals("New Year", calendar.events.get(0).description);
        }

        @Test
        void testAddEvent4() {
            calendar.addEvent(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672614000),
                    "New Year"
            ));
            assertEquals(1, calendar.events.size());
            assertEquals(timeFromTimestamp(1672531200), calendar.events.get(0).date);
            assertEquals(timeFromTimestamp(1672531200), calendar.events.get(0).start_time);
            assertEquals(timeFromTimestamp(1672614000), calendar.events.get(0).end_time);
            assertEquals("New Year", calendar.events.get(0).description);
        }

        @Test
        void testAddEvent5() {
            calendar.addEvent(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672596000),
                    "New Year"
            ));
            assertEquals(1, calendar.events.size());
            assertEquals(timeFromTimestamp(1672531200), calendar.events.get(0).date);
            assertEquals(timeFromTimestamp(1672531200), calendar.events.get(0).start_time);
            assertEquals(timeFromTimestamp(1672596000), calendar.events.get(0).end_time);
            assertEquals("New Year", calendar.events.get(0).description);
        }
    }

    @Nested
    class CalendarTestRemoveEvent {

        @Test
        void testRemoveEvent() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            )));
            calendar.removeEvent(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            ));
            assertTrue(calendar.events.isEmpty());
        }

        @Test
        void testRemoveEvent2() {
            calendar.events = new ArrayList<>(List.of(
                    new Event(
                            timeFromTimestamp(1672531200),
                            timeFromTimestamp(1672531200),
                            timeFromTimestamp(1672534800),
                            "New Year"
                    ),
                    new Event(
                            timeFromTimestamp(1672617600),
                            timeFromTimestamp(1672617600),
                            timeFromTimestamp(1672621200),
                            "New Year"
                    )
            ));
            calendar.removeEvent(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            ));
            assertEquals(1, calendar.events.size());
            assertEquals(new Event(
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672621200),
                    "New Year"
            ), calendar.events.get(0));
        }

        @Test
        void testRemoveEvent3() {
            calendar.events = new ArrayList<>(List.of(
                    new Event(
                            timeFromTimestamp(1672531200),
                            timeFromTimestamp(1672531200),
                            timeFromTimestamp(1672534800),
                            "New Year"
                    ),
                    new Event(
                            timeFromTimestamp(1672617600),
                            timeFromTimestamp(1672617600),
                            timeFromTimestamp(1672621200),
                            "New Year"
                    )
            ));
            calendar.removeEvent(new Event(
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672621200),
                    "New Year"
            ));
            assertEquals(1, calendar.events.size());
            assertEquals(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            ), calendar.events.get(0));
        }

        @Test
        void testRemoveEvent4() {
            calendar.events = new ArrayList<>(List.of(
                    new Event(
                            timeFromTimestamp(1672531200),
                            timeFromTimestamp(1672531200),
                            timeFromTimestamp(1672610400),
                            "New Year"
                    ),
                    new Event(
                            timeFromTimestamp(1672617600),
                            timeFromTimestamp(1672617600),
                            timeFromTimestamp(1672621200),
                            "New Year"
                    )
            ));
            calendar.removeEvent(new Event(
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672621200),
                    "New Year"
            ));
            assertEquals(1, calendar.events.size());
            assertEquals(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672610400),
                    "New Year"
            ), calendar.events.get(0));
        }

        @Test
        void testRemoveEvent5() {
            calendar.events = new ArrayList<>(List.of(
                    new Event(
                            timeFromTimestamp(1672531200),
                            timeFromTimestamp(1672531200),
                            timeFromTimestamp(1672538400),
                            "New Year"
                    ),
                    new Event(
                            timeFromTimestamp(1672617600),
                            timeFromTimestamp(1672617600),
                            timeFromTimestamp(1672621200),
                            "New Year"
                    )
            ));
            calendar.removeEvent(new Event(
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672621200),
                    "New Year"
            ));
            assertEquals(1, calendar.events.size());
            assertEquals(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672538400),
                    "New Year"
            ), calendar.events.get(0));
        }

        @Test
        void testRemoveEvent6() {
            calendar.events = new ArrayList<>();
            calendar.removeEvent(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            ));
            assertTrue(calendar.events.isEmpty());
        }
    }

    @Nested
    class CalendarTestGetEvents {

        @Test
        void testGetEvents() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            )));
            List<Event> eventsOnDate = calendar.getEvents(timeFromTimestamp(1672531200));
            assertEquals(1, eventsOnDate.size());
            assertEquals(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            ), eventsOnDate.get(0));
        }

        @Test
        void testGetEvents2() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            )));
            List<Event> eventsOnDate = calendar.getEvents(timeFromTimestamp(1672617600));
            assertTrue(eventsOnDate.isEmpty());
        }
    }

    @Nested
    class CalendarTestIsAvailable {

        @Test
        void testIsAvailable() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            )));
            assertFalse(calendar.isAvailable(timeFromTimestamp(1672531200), timeFromTimestamp(1672534800)));
        }

        @Test
        void testIsAvailable2() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            )));
            assertTrue(calendar.isAvailable(timeFromTimestamp(1672534800), timeFromTimestamp(1672538400)));
        }

        @Test
        void testIsAvailable3() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            )));
            assertFalse(calendar.isAvailable(timeFromTimestamp(1672531200), timeFromTimestamp(1672531800)));
        }

        @Test
        void testIsAvailable4() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            )));
            assertFalse(calendar.isAvailable(timeFromTimestamp(1672531800), timeFromTimestamp(1672534800)));
        }

        @Test
        void testIsAvailable5() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            )));
            assertTrue(calendar.isAvailable(timeFromTimestamp(1672534800), timeFromTimestamp(1672536000)));
        }
    }

    @Nested
    class CalendarTestGetAvailableSlots {

        @Test
        void testGetAvailableSlots() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672614000),
                    "New Year"
            )));
            List<Pair<LocalDateTime, LocalDateTime>> availableSlots = calendar.getAvailableSlots(timeFromTimestamp(1672531200));
            assertEquals(1, availableSlots.size());
            assertEquals(new Pair<>(timeFromTimestamp(1672614000), timeFromTimestamp(1672617600)), availableSlots.get(0));
        }

        @Test
        void testGetAvailableSlots2() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    timeFromTimestamp(1672538400),
                    "New Year"
            )));
            List<Pair<LocalDateTime, LocalDateTime>> availableSlots = calendar.getAvailableSlots(timeFromTimestamp(1672531200));
            assertEquals(23, availableSlots.size());
        }

        @Test
        void testGetAvailableSlots3() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672621200),
                    "New Year"
            )));
            List<Pair<LocalDateTime, LocalDateTime>> availableSlots = calendar.getAvailableSlots(timeFromTimestamp(1672531200));
            assertEquals(24, availableSlots.size());
        }

        @Test
        void testGetAvailableSlots4() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672621200),
                    "New Year"
            )));
            List<Pair<LocalDateTime, LocalDateTime>> availableSlots = calendar.getAvailableSlots(timeFromTimestamp(1672531200));
            assertEquals(24, availableSlots.size());
        }

        @Test
        void testGetAvailableSlots5() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672621200),
                    "New Year"
            )));
            List<Pair<LocalDateTime, LocalDateTime>> availableSlots = calendar.getAvailableSlots(timeFromTimestamp(1672531200));
            assertEquals(24, availableSlots.size());
        }
    }

    @Nested
    class CalendarTestGetUpcomingEvents {

        @Test
        void testGetUpcomingEvents() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672545600),
                    "New Year"
            )));
            List<Event> upcomingEvents = calendar.getUpcomingEvents(1);
            assertTrue(upcomingEvents.isEmpty());
        }

        @Test
        void testGetUpcomingEvents2() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672533600),
                    timeFromTimestamp(1672533600),
                    timeFromTimestamp(1672537200),
                    "New Year"
            )));
            List<Event> upcomingEvents = calendar.getUpcomingEvents(1);
            assertTrue(upcomingEvents.isEmpty());
        }

        @Test
        void testGetUpcomingEvents3() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672621200),
                    "New Year"
            )));
            List<Event> upcomingEvents = calendar.getUpcomingEvents(1);
            assertTrue(upcomingEvents.isEmpty());
        }

        @Test
        void testGetUpcomingEvents4() {
            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672617600),
                    timeFromTimestamp(1672621200),
                    "New Year"
            )));
            List<Event> upcomingEvents = calendar.getUpcomingEvents(2);
            assertTrue(upcomingEvents.isEmpty());
        }

        @Test
        void testGetUpcomingEvents5() {
            LocalDateTime now = LocalDateTime.now();
            calendar.events = new ArrayList<>(List.of(
                    new Event(
                            now.minusMonths(6),
                            now.minusMonths(6),
                            now.minusMonths(6).plusHours(23),
                            "New Year"
                    ),
                    new Event(
                            now.plusMonths(6),
                            now.plusMonths(6),
                            now.plusMonths(6).plusHours(1),
                            "New Year 2"
                    )
            ));
            List<Event> upcomingEvents = calendar.getUpcomingEvents(1);
            assertEquals(1, upcomingEvents.size());
            assertEquals(now.plusMonths(6), upcomingEvents.get(0).date);
            assertEquals(now.plusMonths(6), upcomingEvents.get(0).start_time);
            assertEquals(now.plusMonths(6).plusHours(1), upcomingEvents.get(0).end_time);
            assertEquals("New Year 2", upcomingEvents.get(0).description);
        }
    }

    @Nested
    class CalendarTestMain {

        @Test
        void testMain() {
            calendar.addEvent(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            ));
            List<Event> events = calendar.getEvents(timeFromTimestamp(1672531200));
            assertEquals(1, events.size());
            assertEquals(timeFromTimestamp(1672531200), events.get(0).date);
            assertEquals(timeFromTimestamp(1672531200), events.get(0).start_time);
            assertEquals(timeFromTimestamp(1672534800), events.get(0).end_time);
            assertEquals("New Year", events.get(0).description);

            calendar.removeEvent(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672534800),
                    "New Year"
            ));
            events = calendar.getEvents(timeFromTimestamp(1672531200));
            assertTrue(events.isEmpty());

            calendar.events = new ArrayList<>(List.of(new Event(
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200),
                    timeFromTimestamp(1672531200).plusHours(23),
                    "New Year"
            )));
            events = calendar.getEvents(timeFromTimestamp(1672531200));
            assertEquals(1, events.size());
            assertEquals(timeFromTimestamp(1672531200), events.get(0).date);
            assertEquals(timeFromTimestamp(1672531200), events.get(0).start_time);
            assertEquals(timeFromTimestamp(1672531200).plusHours(23), events.get(0).end_time);
            assertEquals("New Year", events.get(0).description);

            assertFalse(calendar.isAvailable(timeFromTimestamp(1672531200), timeFromTimestamp(1672534800)));

            List<Pair<LocalDateTime, LocalDateTime>> slots = calendar.getAvailableSlots(timeFromTimestamp(1672531200));
            assertEquals(1, slots.size());
            assertEquals(new Pair<>(timeFromTimestamp(1672531200).plusHours(23), timeFromTimestamp(1672531200).plusHours(24)), slots.get(0));

            List<Event> upcomingEvents = calendar.getUpcomingEvents(1);
            assertTrue(upcomingEvents.isEmpty());
        }
    }
}