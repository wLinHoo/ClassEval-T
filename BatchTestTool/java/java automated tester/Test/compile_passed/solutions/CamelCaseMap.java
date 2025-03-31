import java.util.HashMap;
import java.util.Map;
import java.util.Iterator;

public class CamelCaseMap {
    private Map<String, Object> _data = new HashMap<>();

    public CamelCaseMap() {
    }

    public Iterator<String> iterator() {
        return _data.keySet().iterator();
    }

    public int size() {
        return _data.size();
    }

    public Object get(String key) {
        return _data.get(_convertKey(key));
    }

    public void put(String key, Object value) {
        _data.put(_convertKey(key), value);
    }

    public void remove(String key) {
        _data.remove(_convertKey(key));
    }

    private String _convertKey(String key) {
        if (key != null && key.startsWith("_")) {
            return _toCamelCase(key);
        }
        return key;
    }

    private static String _toCamelCase(String key) {
        String[] parts = key.split("_");
        StringBuilder camelCase = new StringBuilder();
        camelCase.append(parts[0]);
        for (int i = 1; i < parts.length; i++) {
            camelCase.append(parts[i].substring(0, 1).toUpperCase());
            camelCase.append(parts[i].substring(1));
        }
        return camelCase.toString();
    }
}