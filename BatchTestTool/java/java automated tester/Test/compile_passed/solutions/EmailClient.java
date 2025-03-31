import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class EmailClient {
    private String addr;
    private int capacity;
    private List<Map<String, String>> inbox;

    public EmailClient(String addr, int capacity) {
        this.addr = addr;
        this.capacity = capacity;
        this.inbox = new ArrayList<>();
    }

    public boolean sendTo(EmailClient recv, String content, int size) {
        if (!recv.isFullWithOneMoreEmail(size)) {
            Map<String, String> email = new HashMap<>();
            email.put("sender", this.addr);
            email.put("receiver", recv.addr);
            email.put("content", content);
            email.put("size", String.valueOf(size));
            email.put("time", getCurrentTime());
            email.put("state", "unread");

            recv.inbox.add(email);
            return true;
        } else {
            this.clearInbox(size);
            return false;
        }
    }

    public Map<String, String> fetch() {
        if (inbox.isEmpty()) {
            return null;
        }

        for (Map<String, String> email : inbox) {
            if ("unread".equals(email.get("state"))) {
                email.put("state", "read");
                return email;
            }
        }

        return null;
    }

    public boolean isFullWithOneMoreEmail(int size) {
        int occupiedSize = getOccupiedSize();
        return occupiedSize + size > capacity;
    }

    public int getOccupiedSize() {
        int occupiedSize = 0;
        for (Map<String, String> email : inbox) {
            occupiedSize += Integer.parseInt(email.get("size"));
        }
        return occupiedSize;
    }

    public void clearInbox(int size) {
        if (addr.isEmpty()) return;

        int freedSpace = 0;
        while (freedSpace < size && !inbox.isEmpty()) {
            freedSpace += Integer.parseInt(inbox.get(0).get("size"));
            inbox.remove(0);
        }
    }

    public String getCurrentTime() {
        LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-M-d H:m:s");
        return now.format(formatter);
    }

    public String getAddr() {
        return addr;
    }

    public void setAddr(String addr) {
        this.addr = addr;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public List<Map<String, String>> getInbox() {
        return inbox;
    }

    public void setInbox(List<Map<String, String>> inbox) {
        this.inbox = inbox;
    }
}