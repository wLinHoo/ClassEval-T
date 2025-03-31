package org.example;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.temporal.ChronoUnit;

public class TimeUtils {

    LocalDateTime datetime;

    public TimeUtils() {
        this.datetime = LocalDateTime.now();
    }

    public String getCurrentTime() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss");
        return datetime.format(formatter);
    }

    public String getCurrentDate() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        return datetime.format(formatter);
    }

    public String addSeconds(int seconds) {
        LocalDateTime newDatetime = datetime.plusSeconds(seconds);
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss");
        return newDatetime.format(formatter);
    }

    public LocalDateTime stringToDatetime(String string) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-M-d H:m:s");
        return LocalDateTime.parse(string, formatter);
    }

    public String datetimeToString(LocalDateTime datetime) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        return datetime.format(formatter);
    }

    public int getMinutes(String stringTime1, String stringTime2) {
        LocalDateTime time1 = stringToDatetime(stringTime1);
        LocalDateTime time2 = stringToDatetime(stringTime2);
        long minutes = ChronoUnit.MINUTES.between(time1, time2);
        return Math.toIntExact(Math.round(minutes));
    }

    public String getFormatTime(int year, int month, int day, int hour, int minute, int second) {
        LocalDateTime timeItem = LocalDateTime.of(year, month, day, hour, minute, second);
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        return timeItem.format(formatter);
    }
}