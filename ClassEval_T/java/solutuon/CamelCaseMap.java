package org.example;

import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Set;

public class CamelCaseMap {
    private final Map<String, Object> data = new LinkedHashMap<>();

    public Object get(String key) {
        return data.get(_convertKey(key));
    }

    public void put(String key, Object value) {
        data.put(_convertKey(key), value);
    }

    public void remove(String key) {
        data.remove(_convertKey(key));
    }

    String _convertKey(String key) {
        if (key == null) {
            return null;
        }
        return _toCamelCase(key);
    }

    static String _toCamelCase(String key) {
        String[] parts = key.split("_");
        StringBuilder camelCaseString = new StringBuilder(parts[0]);
        for (int i = 1; i < parts.length; i++) {
            camelCaseString.append(parts[i].substring(0, 1).toUpperCase()).append(parts[i].substring(1).toLowerCase());
        }
        return camelCaseString.toString();
    }

    public Set<String> keySet() {
        return data.keySet();
    }

    public int size() {
        return data.size();
    }
}
