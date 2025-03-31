import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Server {

    private ArrayList<String> whiteList;
    private HashMap<String, Object> sendStruct;
    private HashMap<String, Object> receiveStruct;

    public Server() {
        this.whiteList = new ArrayList<>();
        this.sendStruct = new HashMap<>();
        this.receiveStruct = new HashMap<>();
    }

    public ArrayList<String> addWhiteList(String addr) {
        if (this.whiteList.contains(addr)) {
            return null;
        } else {
            this.whiteList.add(addr);
            return this.whiteList;
        }
    }

    public ArrayList<String> delWhiteList(String addr) {
        if (!this.whiteList.contains(addr)) {
            return null;
        } else {
            this.whiteList.remove(addr);
            return this.whiteList;
        }
    }

    public Object recv(HashMap<String, Object> info) {
        if (!(info instanceof HashMap) || !info.containsKey("addr") || !info.containsKey("content")) {
            return -1;
        }
        String addr = (String) info.get("addr");
        Object content = info.get("content");
        if (!this.whiteList.contains(addr)) {
            return false;
        } else {
            this.receiveStruct.put("addr", addr);
            this.receiveStruct.put("content", content);
            return this.receiveStruct.get("content");
        }
    }

    public String send(HashMap<String, Object> info) {
        if (!(info instanceof HashMap) || !info.containsKey("addr") || !info.containsKey("content")) {
            return "info structure is not correct";
        }
        this.sendStruct.put("addr", info.get("addr"));
        this.sendStruct.put("content", info.get("content"));
        return null;
    }

    public Object show(String type) {
        if (type.equals("send")) {
            return this.sendStruct;
        } else if (type.equals("receive")) {
            return this.receiveStruct;
        } else {
            return false;
        }
    }
}