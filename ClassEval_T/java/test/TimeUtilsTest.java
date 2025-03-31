package org.example;

import org.junit.jupiter.api.Test;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import static org.junit.jupiter.api.Assertions.*;

public class TimeUtilsTest {

    @Test
    public void testGetCurrentTime1() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getCurrentTime(), timeutils.datetime.format(DateTimeFormatter.ofPattern("HH:mm:ss")));
    }

    @Test
    public void testGetCurrentTime2() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getCurrentTime(), timeutils.datetime.format(DateTimeFormatter.ofPattern("HH:mm:ss")));
    }

    @Test
    public void testGetCurrentTime3() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getCurrentTime(), timeutils.datetime.format(DateTimeFormatter.ofPattern("HH:mm:ss")));
    }

    @Test
    public void testGetCurrentTime4() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getCurrentTime(), timeutils.datetime.format(DateTimeFormatter.ofPattern("HH:mm:ss")));
    }

    @Test
    public void testGetCurrentTime5() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getCurrentTime(), timeutils.datetime.format(DateTimeFormatter.ofPattern("HH:mm:ss")));
    }

    @Test
    public void testGetCurrentDate1() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getCurrentDate(), timeutils.datetime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")));
    }

    @Test
    public void testGetCurrentDate2() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getCurrentDate(), timeutils.datetime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")));
    }

    @Test
    public void testGetCurrentDate3() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getCurrentDate(), timeutils.datetime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")));
    }

    @Test
    public void testGetCurrentDate4() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getCurrentDate(), timeutils.datetime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")));
    }

    @Test
    public void testGetCurrentDate5() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getCurrentDate(), timeutils.datetime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")));
    }

    @Test
    public void testAddSeconds1() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.addSeconds(600), timeutils.datetime.plusSeconds(600).format(DateTimeFormatter.ofPattern("HH:mm:ss")));
    }

    @Test
    public void testAddSeconds2() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.addSeconds(500), timeutils.datetime.plusSeconds(500).format(DateTimeFormatter.ofPattern("HH:mm:ss")));
    }

    @Test
    public void testAddSeconds3() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.addSeconds(400), timeutils.datetime.plusSeconds(400).format(DateTimeFormatter.ofPattern("HH:mm:ss")));
    }

    @Test
    public void testAddSeconds4() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.addSeconds(300), timeutils.datetime.plusSeconds(300).format(DateTimeFormatter.ofPattern("HH:mm:ss")));
    }

    @Test
    public void testAddSeconds5() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.addSeconds(200), timeutils.datetime.plusSeconds(200).format(DateTimeFormatter.ofPattern("HH:mm:ss")));
    }

    @Test
    public void testStringToDatetime1() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.stringToDatetime("2001-7-18 1:1:1"), LocalDateTime.of(2001, 7, 18, 1, 1, 1));
    }

    @Test
    public void testStringToDatetime2() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.stringToDatetime("2001-7-17 1:1:1"), LocalDateTime.of(2001, 7, 17, 1, 1, 1));
    }

    @Test
    public void testStringToDatetime3() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.stringToDatetime("2001-7-16 1:1:1"), LocalDateTime.of(2001, 7, 16, 1, 1, 1));
    }

    @Test
    public void testStringToDatetime4() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.stringToDatetime("2001-7-15 1:1:1"), LocalDateTime.of(2001, 7, 15, 1, 1, 1));
    }

    @Test
    public void testStringToDatetime5() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.stringToDatetime("2001-7-14 1:1:1"), LocalDateTime.of(2001, 7, 14, 1, 1, 1));
    }

    @Test
    public void testDatetimeToString1() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.datetimeToString(timeutils.datetime), timeutils.datetime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
    }

    @Test
    public void testDatetimeToString2() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.datetimeToString(timeutils.datetime), timeutils.datetime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
    }

    @Test
    public void testDatetimeToString3() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.datetimeToString(timeutils.datetime), timeutils.datetime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
    }

    @Test
    public void testDatetimeToString4() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.datetimeToString(timeutils.datetime), timeutils.datetime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
    }

    @Test
    public void testDatetimeToString5() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.datetimeToString(timeutils.datetime), timeutils.datetime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
    }

    @Test
    public void testGetMinutes1() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getMinutes("2001-7-18 1:1:1", "2001-7-18 2:1:1"), 60);
    }

    @Test
    public void testGetMinutes2() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getMinutes("2001-7-18 1:1:1", "2001-7-18 3:1:1"), 120);
    }

    @Test
    public void testGetMinutes3() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getMinutes("2001-7-18 1:1:1", "2001-7-18 4:1:1"), 180);
    }

    @Test
    public void testGetMinutes4() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getMinutes("2001-7-18 1:1:1", "2001-7-18 5:1:1"), 240);
    }

    @Test
    public void testGetMinutes5() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getMinutes("2001-7-18 1:1:1", "2001-7-18 6:1:1"), 300);
    }

    @Test
    public void testGetFormatTime1() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getFormatTime(2001, 7, 18, 1, 1, 1), "2001-07-18 01:01:01");
    }

    @Test
    public void testGetFormatTime2() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getFormatTime(2001, 7, 17, 1, 1, 1), "2001-07-17 01:01:01");
    }

    @Test
    public void testGetFormatTime3() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getFormatTime(2001, 7, 16, 1, 1, 1), "2001-07-16 01:01:01");
    }

    @Test
    public void testGetFormatTime4() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getFormatTime(2001, 7, 15, 1, 1, 1), "2001-07-15 01:01:01");
    }

    @Test
    public void testGetFormatTime5() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getFormatTime(2001, 7, 14, 1, 1, 1), "2001-07-14 01:01:01");
    }

    @Test
    public void testTimeUtils() {
        TimeUtils timeutils = new TimeUtils();
        assertEquals(timeutils.getCurrentTime(), timeutils.datetime.format(DateTimeFormatter.ofPattern("HH:mm:ss")));
        assertEquals(timeutils.getCurrentDate(), timeutils.datetime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd")));
        assertEquals(timeutils.addSeconds(600), timeutils.datetime.plusSeconds(600).format(DateTimeFormatter.ofPattern("HH:mm:ss")));
        assertEquals(timeutils.stringToDatetime("2001-7-18 1:1:1"), LocalDateTime.of(2001, 7, 18, 1, 1, 1));
        assertEquals(timeutils.datetimeToString(timeutils.datetime), timeutils.datetime.format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")));
        assertEquals(timeutils.getMinutes("2001-7-18 1:1:1", "2001-7-18 2:1:1"), 60);
        assertEquals(timeutils.getFormatTime(2001, 7, 18, 1, 1, 1), "2001-07-18 01:01:01");
    }
}