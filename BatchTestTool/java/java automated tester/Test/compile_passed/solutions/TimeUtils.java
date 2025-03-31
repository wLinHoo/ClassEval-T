import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.Duration;

public class TimeUtils {

    private LocalDateTime dateTime;
    private LocalDateTime datetime;

    public TimeUtils() {
        this.dateTime = LocalDateTime.now();
        this.datetime = LocalDateTime.now();
    }

    public String getCurrentTime() {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss");
        return this.dateTime.format(formatter);
    }

    public String getCurrentDate() {
        DateTimeFormatter format = DateTimeFormatter.ofPattern("yyyy-MM-dd");
        return this.dateTime.format(format);
    }

    public String addSeconds(long seconds) {
        LocalDateTime newDateTime = dateTime.plusSeconds(seconds);
        DateTimeFormatter format = DateTimeFormatter.ofPattern("HH:mm:ss");
        return newDateTime.format(format);
    }

    public String datetimeToString(LocalDateTime datetime) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        return datetime.format(formatter);
    }

    public String getCurrentDatetimeAsString() {
        return datetimeToString(this.datetime);
    }

    public String getFormatTime(int year, int month, int day, int hour, int minute, int second) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        LocalDateTime timeItem = LocalDateTime.of(year, month, day, hour, minute, second);
        return timeItem.format(formatter);
    }

    public LocalDateTime stringToDateTime(String string) {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        return LocalDateTime.parse(string, formatter);
    }

    public long getMinutes(String stringTime1, String stringTime2) {
        LocalDateTime time1 = stringToDateTime(stringTime1);
        LocalDateTime time2 = stringToDateTime(stringTime2);
        Duration duration = Duration.between(time1, time2);
        return Math.round(duration.getSeconds() / 60.0);
    }

    public static void main(String[] args) {
        TimeUtils timeUtils = new TimeUtils();
        System.out.println("Current Time: " + timeUtils.getCurrentTime());
        System.out.println(timeUtils.getCurrentDate());
        System.out.println(timeUtils.addSeconds(60)); // Example: Add 60 seconds
        System.out.println("Current DateTime: " + timeUtils.getCurrentDatetimeAsString());
        String formattedTime = timeUtils.getFormatTime(2023, 10, 5, 14, 30, 0);
        System.out.println(formattedTime); // Example usage
        System.out.println(timeUtils.getMinutes("2023-10-01 12:00:00", "2023-10-01 12:30:00"));
    }
}