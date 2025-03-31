package org.example;

import org.apache.commons.math3.util.Pair;

import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.*;
import java.util.stream.Collectors;

class Event {
    LocalDateTime date;
    LocalDateTime start_time;
    LocalDateTime end_time;
    String description;

    public Event(LocalDateTime date, LocalDateTime start_time, LocalDateTime end_time, String description) {
        this.date = date;
        this.start_time = start_time;
        this.end_time = end_time;
        this.description = description;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Event event = (Event) obj;
        return date.equals(event.date) &&
                start_time.equals(event.start_time) &&
                end_time.equals(event.end_time) &&
                description.equals(event.description);
    }

    @Override
    public int hashCode() {
        return Objects.hash(date, start_time, end_time, description);
    }
}

class CalendarUtil {
    List<Event> events = new ArrayList<>();

    public void addEvent(Event event) {
        events.add(event);
    }

    public void removeEvent(Event event) {
        events.remove(event);
    }

    public List<Event> getEvents(LocalDateTime date) {
        return events.stream()
                .filter(event -> event.date.toLocalDate().equals(date.toLocalDate()))
                .collect(Collectors.toList());
    }

    public boolean isAvailable(LocalDateTime start_time, LocalDateTime end_time) {
        return events.stream()
                .noneMatch(event -> start_time.isBefore(event.end_time) && end_time.isAfter(event.start_time));
    }

    public List<Pair<LocalDateTime, LocalDateTime>> getAvailableSlots(LocalDateTime date) {
        List<Pair<LocalDateTime, LocalDateTime>> availableSlots = new ArrayList<>();
        LocalDateTime start_time = date.withHour(0).withMinute(0);
        LocalDateTime end_time = date.withHour(23).withMinute(59);

        while (start_time.isBefore(end_time)) {
            LocalDateTime slot_end_time = start_time.plus(1, ChronoUnit.HOURS);
            if (isAvailable(start_time, slot_end_time)) {
                availableSlots.add(new Pair<>(start_time, slot_end_time));
            }
            start_time = slot_end_time;
        }

        return availableSlots;
    }

    public List<Event> getUpcomingEvents(int num_events) {
        LocalDateTime now = LocalDateTime.now();
        return events.stream()
                .filter(event -> event.start_time.isAfter(now))
                .limit(num_events)
                .collect(Collectors.toList());
    }
}