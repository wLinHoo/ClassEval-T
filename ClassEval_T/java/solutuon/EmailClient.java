package org.example;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.HashMap;

class EmailClient {
    private String addr;
    private double capacity;
    private List<Map<String, Object>> inbox;

    public EmailClient(String addr, double capacity) {
        this.addr = addr;
        this.capacity = capacity;
        this.inbox = new ArrayList<>();
    }

    public boolean sendTo(EmailClient recv, String content, double size) {
        if (!recv.isFullWithOneMoreEmail(size)) {
            String timestamp = LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));
            Map<String, Object> email = new HashMap<>();
            email.put("sender", this.addr);
            email.put("receiver", recv.addr);
            email.put("content", content);
            email.put("size", size);
            email.put("time", timestamp);
            email.put("state", "unread");
            recv.inbox.add(email);
            return true;
        }
        else {
            this.clearInbox(size);
            if (recv.isFullWithOneMoreEmail(size)) {
                return false;
            }
            return sendTo(recv, content, size); // Retry sending after clearing
        }
    }

    public Map<String, Object> fetch() {
        if (this.inbox.isEmpty()) {
            return null;
        }
        for (Map<String, Object> email : this.inbox) {
            if ("unread".equals(email.get("state"))) {
                email.put("state", "read");
                return email;
            }
        }
        return null;
    }

    public boolean isFullWithOneMoreEmail(double size) {
        double occupiedSize = this.getOccupiedSize();
        return occupiedSize + size > this.capacity;
    }

    public double getOccupiedSize() {
        double occupiedSize = 0;
        for (Map<String, Object> email : this.inbox) {
            Object sizeObj = email.get("size");
            if (sizeObj instanceof Number) {
                occupiedSize += ((Number) sizeObj).doubleValue();
            }
        }
        return occupiedSize;
    }

    public void clearInbox(double size) {
        if (this.addr.isEmpty()) {
            return;
        }
        double freedSpace = 0;
        while (freedSpace < size && !this.inbox.isEmpty()) {
            Map<String, Object> email = this.inbox.remove(0);
            Object sizeObj = email.get("size");
            if (sizeObj instanceof Number) {
                freedSpace += ((Number) sizeObj).doubleValue();
            }
        }
    }

    public List<Map<String, Object>> getInbox() {
        return this.inbox;
    }

    public void setInbox(List<Map<String, Object>> inbox) {
        this.inbox = inbox;
    }
}
