package test_cases;
import to_be_tested.Chat;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

class ChatTest {
    private Chat chat;

    @BeforeEach
    void setUp() {
        chat = new Chat();
    }

    @Test
    void testAddUser() {
        assertTrue(chat.addUser("John"));
        assertEquals(0, chat.getMessages("John").size());
    }

    @Test
    void testAddUser2() {
        chat.addUser("John");
        assertFalse(chat.addUser("John"));
        assertEquals(0, chat.getMessages("John").size());
    }

    @Test
    void testAddUser3() {
        chat.addUser("John");
        assertTrue(chat.addUser("Mary"));
        assertEquals(0, chat.getMessages("John").size());
        assertEquals(0, chat.getMessages("Mary").size());
    }

    @Test
    void testAddUser4() {
        chat.addUser("John");
        assertTrue(chat.addUser("Mary"));
        assertEquals(0, chat.getMessages("John").size());
        assertEquals(0, chat.getMessages("Mary").size());
    }

    @Test
    void testAddUser5() {
        assertTrue(chat.addUser("John"));
        assertTrue(chat.addUser("Mary"));
        assertEquals(0, chat.getMessages("John").size());
        assertEquals(0, chat.getMessages("Mary").size());
    }

    @Test
    void testRemoveUser() {
        chat.addUser("John");
        assertTrue(chat.removeUser("John"));
        assertTrue(chat.getMessages("John").isEmpty());
    }

    @Test
    void testRemoveUser2() {
        assertFalse(chat.removeUser("John"));
        assertTrue(chat.getMessages("John").isEmpty());
    }

    @Test
    void testRemoveUser3() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertTrue(chat.removeUser("John"));
        assertEquals(0, chat.getMessages("Mary").size());
    }

    @Test
    void testRemoveUser4() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertTrue(chat.removeUser("Mary"));
        assertTrue(chat.removeUser("John"));
        assertTrue(chat.getMessages("John").isEmpty());
        assertTrue(chat.getMessages("Mary").isEmpty());
    }

    @Test
    void testRemoveUser5() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertFalse(chat.removeUser("Amy"));
        assertEquals(0, chat.getMessages("John").size());
        assertEquals(0, chat.getMessages("Mary").size());
    }

    @Test
    void testSendMessage() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertTrue(chat.sendMessage("John", "Mary", "Hello"));
        assertEquals(1, chat.getMessages("John").size());
        assertEquals(1, chat.getMessages("Mary").size());
    }

    @Test
    void testSendMessage2() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertFalse(chat.sendMessage("John", "Tom", "Hello"));
        assertEquals(0, chat.getMessages("John").size());
        assertEquals(0, chat.getMessages("Mary").size());
    }

    @Test
    void testSendMessage3() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertFalse(chat.sendMessage("Amy", "Mary", "Hello"));
        assertEquals(0, chat.getMessages("John").size());
        assertEquals(0, chat.getMessages("Mary").size());
    }

    @Test
    void testSendMessage4() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertFalse(chat.sendMessage("Amy", "Tom", "Hello"));
        assertEquals(0, chat.getMessages("John").size());
        assertEquals(0, chat.getMessages("Mary").size());
    }

    @Test
    void testSendMessage5() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertFalse(chat.sendMessage("Amy", "Amy", "Hello"));
        assertEquals(0, chat.getMessages("John").size());
        assertEquals(0, chat.getMessages("Mary").size());
    }

    @Test
    void testGetMessages() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertTrue(chat.sendMessage("John", "Mary", "Hello"));
        List<Chat.Message> messages = chat.getMessages("John");
        assertEquals(1, messages.size());
        assertEquals("John", messages.get(0).getSender());
        assertEquals("Mary", messages.get(0).getReceiver());
        assertEquals("Hello", messages.get(0).getMessage());
    }

    @Test
    void testGetMessages2() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertTrue(chat.getMessages("John").isEmpty());
    }

    @Test
    void testGetMessages3() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertTrue(chat.getMessages("Amy").isEmpty());
    }

    @Test
    void testGetMessages4() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertTrue(chat.sendMessage("John", "Mary", "Hello"));
        List<Chat.Message> messages = chat.getMessages("Mary");
        assertEquals(1, messages.size());
        assertEquals("John", messages.get(0).getSender());
        assertEquals("Mary", messages.get(0).getReceiver());
        assertEquals("Hello", messages.get(0).getMessage());
    }

    @Test
    void testGetMessages5() {
        chat.addUser("John");
        chat.addUser("Mary");
        assertTrue(chat.sendMessage("John", "Mary", "Hello"));
        assertTrue(chat.getMessages("Amy").isEmpty());
    }

    @Test
    void testMain() {
        assertTrue(chat.addUser("John"));
        assertTrue(chat.addUser("Mary"));
        assertTrue(chat.addUser("Amy"));
        assertEquals(0, chat.getMessages("John").size());
        assertEquals(0, chat.getMessages("Mary").size());
        assertEquals(0, chat.getMessages("Amy").size());
        assertTrue(chat.removeUser("Amy"));
        assertEquals(0, chat.getMessages("John").size());
        assertEquals(0, chat.getMessages("Mary").size());
        assertTrue(chat.sendMessage("John", "Mary", "Hello"));
        assertFalse(chat.sendMessage("John", "Tom", "Hello"));
        List<Chat.Message> messagesJohn = chat.getMessages("John");
        List<Chat.Message> messagesMary = chat.getMessages("Mary");
        assertEquals(1, messagesJohn.size());
        assertEquals(1, messagesMary.size());
        assertEquals("John", messagesJohn.get(0).getSender());
        assertEquals("Mary", messagesJohn.get(0).getReceiver());
        assertEquals("Hello", messagesJohn.get(0).getMessage());
        assertEquals("John", messagesMary.get(0).getSender());
        assertEquals("Mary", messagesMary.get(0).getReceiver());
        assertEquals("Hello", messagesMary.get(0).getMessage());
    }

    @Test
    void testMain2() {
        assertFalse(chat.removeUser("Amy"));
        assertTrue(chat.addUser("John"));
        assertTrue(chat.addUser("Mary"));
        assertTrue(chat.addUser("Amy"));
        assertEquals(0, chat.getMessages("John").size());
        assertEquals(0, chat.getMessages("Mary").size());
        assertEquals(0, chat.getMessages("Amy").size());
        assertTrue(chat.sendMessage("John", "Mary", "Hello"));
        assertFalse(chat.sendMessage("John", "Tom", "Hello"));
        assertTrue(chat.removeUser("Amy"));
        List<Chat.Message> messagesJohn = chat.getMessages("John");
        List<Chat.Message> messagesMary = chat.getMessages("Mary");
        assertEquals(1, messagesJohn.size());
        assertEquals(1, messagesMary.size());
        assertEquals("John", messagesJohn.get(0).getSender());
        assertEquals("Mary", messagesJohn.get(0).getReceiver());
        assertEquals("Hello", messagesJohn.get(0).getMessage());
        assertEquals("John", messagesMary.get(0).getSender());
        assertEquals("Mary", messagesMary.get(0).getReceiver());
        assertEquals("Hello", messagesMary.get(0).getMessage());
    }
}