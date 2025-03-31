import java.time.Instant;
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.AbstractMap.SimpleEntry;

public class CalendarUtil {
    private List<Event> events = new ArrayList<>();

    public static class Event {
        private Instant date;
        private Instant startTime;
        private Instant endTime;
        private String description;

        public Event(Instant date, Instant startTime, Instant endTime, String description) {
            this.date = date;
            this.startTime = startTime;
            this.endTime = endTime;
            this.description = description;
        }

        public Instant getDate() { return date; }
        public void setDate(Instant date) { this.date = date; }
        public Instant getStartTime() { return startTime; }
        public void setStartTime(Instant startTime) { this.startTime = startTime; }
        public Instant getEndTime() { return endTime; }
        public void setEndTime(Instant endTime) { this.endTime = endTime; }
        public String getDescription() { return description; }
        public void setDescription(String description) { this.description = description; }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Event event = (Event) o;
            return Objects.equals(date, event.date) &&
                   Objects.equals(startTime, event.startTime) &&
                   Objects.equals(endTime, event.endTime) &&
                   Objects.equals(description, event.description);
        }

        @Override
        public int hashCode() {
            return Objects.hash(date, startTime, endTime, description);
        }
    }

    public static class TimeSlot {
        private Instant startTime;
        private Instant endTime;

        public TimeSlot(Instant startTime, Instant endTime) {
            this.startTime = startTime;
            this.endTime = endTime;
        }

        public Instant getStartTime() { return startTime; }
        public Instant getEndTime() { return endTime; }
    }

    public void addEvent(Event event) {
        events.add(event);
    }

    public void removeEvent(Event event) {
        events.remove(event);
    }

    public List<Event> getEvents(Instant date) {
        List<Event> eventsOnDate = new ArrayList<>();
        LocalDateTime dateTime = LocalDateTime.ofInstant(date, ZoneId.systemDefault());

        for (Event event : events) {
            LocalDateTime eventDateTime = LocalDateTime.ofInstant(event.getDate(), ZoneId.systemDefault());

            if (dateTime.getYear() == eventDateTime.getYear() &&
                dateTime.getMonthValue() - 1 == eventDateTime.getMonthValue() - 1 &&
                dateTime.getDayOfMonth() == eventDateTime.getDayOfMonth()) {
                eventsOnDate.add(event);
            }
        }
        return eventsOnDate;
    }

    public boolean isAvailable(Instant startTime, Instant endTime) {
        for (Event event : events) {
            if (startTime.isBefore(event.getEndTime()) && endTime.isAfter(event.getStartTime())) {
                return false;
            }
        }
        return true;
    }

    public List<TimeSlot> getAvailableSlots(Instant date) {
        return new ArrayList<>();
    }

    public List<Event> getUpcomingEvents(int numEvents) {
        Instant now = Instant.now();
        List<Event> upcomingEvents = new ArrayList<>();

        for (Event event : events) {
            if (event.startTime.compareTo(now) >= 0) {
                upcomingEvents.add(event);
                if (upcomingEvents.size() == numEvents) {
                    break;
                }
            }
        }

        return upcomingEvents;
    }

    public static Instant timeFromTimestamp(long timestamp) {
        return Instant.ofEpochSecond(timestamp);
    }

    public List<SimpleEntry<LocalDateTime, LocalDateTime>> getAvailableSlots(LocalDateTime date) {
        List<SimpleEntry<LocalDateTime, LocalDateTime>> availableSlots = new ArrayList<>();
        LocalDateTime startTime = date;
        LocalDateTime endTime = date.plusHours(24).minusSeconds(1);

        while (startTime.isBefore(endTime)) {
            LocalDateTime slotEndTime = startTime.plusHours(1);
            if (isAvailable(startTime, slotEndTime)) {
                availableSlots.add(new SimpleEntry<>(startTime, slotEndTime));
            }
            startTime = slotEndTime;
        }

        return availableSlots;
    }

    private boolean isAvailable(LocalDateTime startTime, LocalDateTime endTime) {
        return true;
    }
}