package org.example;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;

public class Chat {
    private Map<String, List<Message>> users;

    public Chat() {
        this.users = new HashMap<>();
    }

    public boolean addUser(String username) {
        if (users.containsKey(username)) {
            return false;
        } else {
            users.put(username, new ArrayList<>());
            return true;
        }
    }

    public boolean removeUser(String username) {
        if (users.containsKey(username)) {
            users.remove(username);
            return true;
        } else {
            return false;
        }
    }

    public boolean sendMessage(String sender, String receiver, String message) {
        if (!users.containsKey(sender) || !users.containsKey(receiver)) {
            return false;
        }

        String timestamp = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date());

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

    public Map<String, List<Message>> getUsers() {
        return users;
    }

    class Message {
        private String sender;
        private String receiver;
        private String message;
        private String timestamp;

        public Message(String sender, String receiver, String message, String timestamp) {
            this.sender = sender;
            this.receiver = receiver;
            this.message = message;
            this.timestamp = timestamp;
        }

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

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj == null || getClass() != obj.getClass()) return false;
            Message message1 = (Message) obj;
            return Objects.equals(sender, message1.sender) &&
                    Objects.equals(receiver, message1.receiver) &&
                    Objects.equals(message, message1.message) &&
                    Objects.equals(timestamp, message1.timestamp);
        }

        @Override
        public int hashCode() {
            return Objects.hash(sender, receiver, message, timestamp);
        }

        @Override
        public String toString() {
            return String.format("Message{sender='%s', receiver='%s', message='%s', timestamp='%s'}", sender, receiver, message, timestamp);
        }
    }
}
