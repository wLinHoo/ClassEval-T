import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Chat {
    // Inner class for Message (equivalent to struct in C++)
    public static class Message {
        private String sender;
        private String receiver;
        private String message;
        private String timestamp;

        // Constructor
        public Message(String sender, String receiver, String message, String timestamp) {
            this.sender = sender;
            this.receiver = receiver;
            this.message = message;
            this.timestamp = timestamp;
        }

        // Getters and setters
        public String getSender() {
            return sender;
        }

        public String getReceiver() {
            return receiver;
        }

        public String getMessage() {
            return message;
        }

        public String getTimestamp() {
            return timestamp;
        }
    }

    // Private field
    private HashMap<String, List<Message>> users;

    // Constructor
    public Chat() {
        users = new HashMap<>();
    }

    // Methods
    public boolean addUser(String username) {
        if (users.containsKey(username)) {
            return false;
        }
        users.put(username, new ArrayList<>());
        return true;
    }

    public boolean removeUser(String username) {
        return users.remove(username) != null;
    }

    public boolean sendMessage(String sender, String receiver, String message) {
        if (!users.containsKey(sender) || !users.containsKey(receiver)) {
            return false;
        }

        String timestamp = getCurrentTime();
        Message messageInfo = new Message(sender, receiver, message, timestamp);

        users.get(sender).add(messageInfo);
        users.get(receiver).add(messageInfo);
        return true;
    }

    public List<Message> getMessages(String username) {
        if (!users.containsKey(username)) {
            return new ArrayList<>();
        }
        return users.get(username);
    }

    public HashMap<String, List<Message>> getUsers() {
        return users;
    }

    public String getCurrentTime() {
        LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        return now.format(formatter);
    }
}