package org.example;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Server {

    private List<Integer> whiteList;
    private Map<String, Object> sendStruct;
    private Map<String, Object> receiveStruct;

    public Server() {
        this.whiteList = new ArrayList<>();
        this.sendStruct = new HashMap<>();
        this.receiveStruct = new HashMap<>();
    }

    public List<Integer> addWhiteList(int addr) {
        if (whiteList.contains(addr)) {
            return null;
        } else {
            whiteList.add(addr);
            return whiteList;
        }
    }

    public List<Integer> delWhiteList(int addr) {
        if (!whiteList.contains(addr)) {
            return null;
        } else {
            whiteList.remove(Integer.valueOf(addr));
            return whiteList;
        }
    }

    public Object recv(Map<String, Object> info) {
        if (info == null || !info.containsKey("addr") || !info.containsKey("content")) {
            return -1;
        }
        int addr = (int) info.get("addr");
        String content = (String) info.get("content");
        if (!whiteList.contains(addr)) {
            return false;
        } else {
            receiveStruct.put("addr", addr);
            receiveStruct.put("content", content);
            return receiveStruct.get("content");
        }
    }

    public String send(Map<String, Object> info) {
        if (info == null || !info.containsKey("addr") || !info.containsKey("content")) {
            return "info structure is not correct";
        }
        sendStruct.put("addr", info.get("addr"));
        sendStruct.put("content", info.get("content"));
        return null;
    }

    public Map<String, Object> show(String type) {
        if ("send".equals(type)) {
            return sendStruct;
        } else if ("receive".equals(type)) {
            return receiveStruct;
        } else {
            return null;
        }
    }
}