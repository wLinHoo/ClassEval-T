package org.example;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

public class CookiesUtil {
    private String cookiesFile;
    private Map<String, String> cookies;

    public CookiesUtil(String cookiesFile) {
        this.cookiesFile = cookiesFile;
        this.cookies = null;
    }

    public void getCookies(Map<String, Map<String, String>> response) {
        this.cookies = response.get("cookies");
        _saveCookies();
    }

    public Map<String, String> loadCookies() {
        JSONParser parser = new JSONParser();
        try (FileReader reader = new FileReader(cookiesFile)) {
            JSONObject jsonObject = (JSONObject) parser.parse(reader);
            Map<String, String> cookiesData = new HashMap<>();
            jsonObject.forEach((key, value) -> cookiesData.put((String) key, (String) value));
            return cookiesData;
        } catch (IOException | ParseException e) {
            return new HashMap<>();
        }
    }

    boolean _saveCookies() {
        try (FileWriter file = new FileWriter(cookiesFile)) {
            JSONObject jsonObject = new JSONObject();
            if (cookies != null) {
                cookies.forEach(jsonObject::put);
            }
            file.write(jsonObject.toJSONString());
            file.flush();
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    public void setCookies(Map<String, String> request) {
        StringBuilder cookiesString = new StringBuilder();
        if (cookies != null) {
            cookies.forEach((key, value) -> {
                if (cookiesString.length() > 0) {
                    cookiesString.append("; ");
                }
                cookiesString.append(key).append("=").append(value);
            });
        }
        request.put("cookies", cookiesString.toString());
    }
}
