package org.example;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.BeforeEach;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import static org.junit.jupiter.api.Assertions.*;

class EmailClientTest {

    private EmailClient sender;
    private EmailClient receiver;
    private String timestamp;

    @BeforeEach
    void setUp() {
        sender = new EmailClient("sender@example.com", 100);
        receiver = new EmailClient("receiver@example.com", 50);
        timestamp = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));
    }

    @Test
    void testSendTo() {
        String timestamp = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));

        Map<String, Object> expectedEmail = Map.of(
                "sender", "sender@example.com",
                "receiver", "receiver@example.com",
                "content", "Hello",
                "size", 10.0, // Use Double here
                "time", timestamp,
                "state", "unread"
        );

        assertTrue(sender.sendTo(receiver, "Hello", 10));
        assertEquals(expectedEmail, receiver.getInbox().get(0));
    }


    @Test
    void testSendTo2() {
        EmailClient receiver = new EmailClient("receiver@example.com", 0);
        assertFalse(sender.sendTo(receiver, "Hello", 10));
    }

    @Test
    void testSendTo3() {
        receiver.setInbox(new ArrayList<>());
        Map<String, Object> existingEmail = new HashMap<>();
        existingEmail.put("sender", "sender@example.com");
        existingEmail.put("receiver", "receiver@example.com");
        existingEmail.put("content", "Hello");
        existingEmail.put("size", 50);
        existingEmail.put("time", "2021-01-01 00:00:00");
        existingEmail.put("state", "unread");
        receiver.getInbox().add(existingEmail);

        assertFalse(sender.sendTo(receiver, "Hello", 10));
        assertEquals(List.of(existingEmail), receiver.getInbox());
    }

    @Test
    void testSendTo4() {
        EmailClient sender = new EmailClient("sender@example.com", 50);
        EmailClient receiver = new EmailClient("receiver@example.com", 30);

        Map<String, Object> expectedEmail = Map.of(
                "sender", "sender@example.com",
                "receiver", "receiver@example.com",
                "content", "Hello",
                "size", 20.0, // Use Double here
                "time", LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")),
                "state", "unread"
        );

        assertTrue(sender.sendTo(receiver, "Hello", 20));
        assertEquals(expectedEmail, receiver.getInbox().get(0));
    }

    @Test
    void testSendTo5() {
        EmailClient sender = new EmailClient("sender@example.com", 50);
        EmailClient receiver = new EmailClient("receiver@example.com", 30);

        Map<String, Object> expectedEmail = Map.of(
                "sender", "sender@example.com",
                "receiver", "receiver@example.com",
                "content", "bye",
                "size", 20.0, // Use Double here
                "time", LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")),
                "state", "unread"
        );

        assertTrue(sender.sendTo(receiver, "bye", 20));
        assertEquals(expectedEmail, receiver.getInbox().get(0));
    }


    @Test
    void testFetch() {
        Map<String, Object> email = new HashMap<>();
        email.put("sender", "sender@example.com");
        email.put("receiver", "receiver@example.com");
        email.put("content", "Hello");
        email.put("size", 10);
        email.put("time", timestamp);
        email.put("state", "unread");
        receiver.setInbox(new ArrayList<>(List.of(email)));

        assertEquals(Map.of(
                "sender", "sender@example.com",
                "receiver", "receiver@example.com",
                "content", "Hello",
                "size", 10,
                "time", timestamp,
                "state", "read"
        ), receiver.fetch());
    }

    @Test
    void testFetch2() {
        assertNull(receiver.fetch());
    }

    @Test
    void testFetch3() {
        Map<String, Object> email = new HashMap<>();
        email.put("sender", "sender@example.com");
        email.put("receiver", "receiver@example.com");
        email.put("content", "Hello");
        email.put("size", 10);
        email.put("time", timestamp);
        email.put("state", "read");
        receiver.setInbox(new ArrayList<>(List.of(email)));

        assertNull(receiver.fetch());
    }

    @Test
    void testFetch4() {
        Map<String, Object> email1 = new HashMap<>();
        email1.put("sender", "sender@example.com");
        email1.put("receiver", "receiver@example.com");
        email1.put("content", "Hello");
        email1.put("size", 10);
        email1.put("time", "2021-01-01 00:00:00");
        email1.put("state", "unread");

        Map<String, Object> email2 = new HashMap<>();
        email2.put("sender", "sender@example.com");
        email2.put("receiver", "receiver@example.com");
        email2.put("content", "Hello");
        email2.put("size", 10);
        email2.put("time", timestamp);
        email2.put("state", "unread");

        receiver.setInbox(new ArrayList<>(List.of(email1, email2)));

        assertEquals(Map.of(
                "sender", "sender@example.com",
                "receiver", "receiver@example.com",
                "content", "Hello",
                "size", 10,
                "time", "2021-01-01 00:00:00",
                "state", "read"
        ), receiver.fetch());
    }

    @Test
    void testFetch5() {
        Map<String, Object> email1 = new HashMap<>();
        email1.put("sender", "sender@example.com");
        email1.put("receiver", "receiver@example.com");
        email1.put("content", "Hello");
        email1.put("size", 10);
        email1.put("time", "2021-01-01 00:00:00");
        email1.put("state", "read");

        Map<String, Object> email2 = new HashMap<>();
        email2.put("sender", "sender@example.com");
        email2.put("receiver", "receiver@example.com");
        email2.put("content", "Hello");
        email2.put("size", 10);
        email2.put("time", timestamp);
        email2.put("state", "unread");

        receiver.setInbox(new ArrayList<>(List.of(email1, email2)));

        assertEquals(Map.of(
                "sender", "sender@example.com",
                "receiver", "receiver@example.com",
                "content", "Hello",
                "size", 10,
                "time", timestamp,
                "state", "read"
        ), receiver.fetch());
    }

    @Test
    void testIsFullWithOneMoreEmail() {
        assertFalse(receiver.isFullWithOneMoreEmail(10));
    }

    @Test
    void testIsFullWithOneMoreEmail2() {
        receiver = new EmailClient("receiver@example.com", 0);
        assertTrue(receiver.isFullWithOneMoreEmail(10));
    }

    @Test
    void testIsFullWithOneMoreEmail3() {
        receiver = new EmailClient("receiver@example.com", 10);
        assertFalse(receiver.isFullWithOneMoreEmail(10));
    }

    @Test
    void testIsFullWithOneMoreEmail4() {
        receiver = new EmailClient("receiver@example.com", 10);
        assertTrue(receiver.isFullWithOneMoreEmail(20));
    }

    @Test
    void testIsFullWithOneMoreEmail5() {
        receiver = new EmailClient("receiver@example.com", 20);
        assertFalse(receiver.isFullWithOneMoreEmail(20));
    }

    @Test
    void testGetOccupiedSize() {
        Map<String, Object> email = new HashMap<>();
        email.put("sender", "sender@example.com");
        email.put("receiver", "receiver@example.com");
        email.put("content", "Hello");
        email.put("size", 10);
        email.put("time", timestamp);
        email.put("state", "unread");

        sender.setInbox(new ArrayList<>(List.of(email)));
        assertEquals(10, sender.getOccupiedSize());
    }

    @Test
    void testGetOccupiedSize2() {
        sender.setInbox(new ArrayList<>());
        assertEquals(0, sender.getOccupiedSize());
    }

    @Test
    void testGetOccupiedSize3() {
        Map<String, Object> email = new HashMap<>();
        email.put("sender", "sender@example.com");
        email.put("receiver", "receiver@example.com");
        email.put("content", "Hello");
        email.put("size", 20);
        email.put("time", timestamp);
        email.put("state", "unread");

        sender.setInbox(new ArrayList<>(List.of(email)));
        assertEquals(20, sender.getOccupiedSize());
    }

    @Test
    void testGetOccupiedSize4() {
        Map<String, Object> email1 = new HashMap<>();
        email1.put("sender", "sender@example.com");
        email1.put("receiver", "receiver@example.com");
        email1.put("content", "Hello");
        email1.put("size", 20);
        email1.put("time", timestamp);
        email1.put("state", "unread");

        Map<String, Object> email2 = new HashMap<>();
        email2.put("sender", "sender@example.com");
        email2.put("receiver", "receiver@example.com");
        email2.put("content", "Hi");
        email2.put("size", 30);
        email2.put("time", timestamp);
        email2.put("state", "unread");

        sender.setInbox(new ArrayList<>(List.of(email1, email2)));
        assertEquals(50, sender.getOccupiedSize());
    }

    @Test
    void testGetOccupiedSize5() {
        Map<String, Object> email1 = new HashMap<>();
        email1.put("sender", "sender@example.com");
        email1.put("receiver", "receiver@example.com");
        email1.put("content", "Hello");
        email1.put("size", 15);
        email1.put("time", timestamp);
        email1.put("state", "unread");

        Map<String, Object> email2 = new HashMap<>();
        email2.put("sender", "sender@example.com");
        email2.put("receiver", "receiver@example.com");
        email2.put("content", "Hi");
        email2.put("size", 20);
        email2.put("time", timestamp);
        email2.put("state", "unread");

        sender.setInbox(new ArrayList<>(List.of(email1, email2)));
        assertEquals(35, sender.getOccupiedSize());
    }
}
