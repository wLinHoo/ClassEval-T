import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class CookiesUtil {
    private String cookiesFile;
    private Map<String, String> cookies = new HashMap<>();

    public CookiesUtil(String cookiesFile) {
        this.cookiesFile = cookiesFile;
    }

    public void getCookies(String response) {
        if (response.contains("cookies")) {
            cookies = getCookiesFromResponse(response);
        }
        saveCookies();
    }

    private Map<String, String> getCookiesFromResponse(String response) {
        Map<String, String> cookies = new HashMap<>();
        String[] cookiePairs = response.split(";");
        for (String cookiePair : cookiePairs) {
            String[] keyValue = cookiePair.split("=");
            cookies.put(keyValue[0], keyValue[1]);
        }
        return cookies;
    }

    public void saveCookies() {
        String cookiesJson = getCookiesJson();
        try (FileWriter fileWriter = new FileWriter(cookiesFile)) {
            fileWriter.write(cookiesJson);
        } catch (IOException e) {
            System.err.println("Error writing JSON file: " + e.getMessage());
        }
    }

    private String getCookiesJson() {
        StringBuilder cookiesJson = new StringBuilder("{");
        for (Map.Entry<String, String> cookie : cookies.entrySet()) {
            cookiesJson.append("\"").append(cookie.getKey()).append("\": \"").append(cookie.getValue()).append("\",");
        }
        cookiesJson.deleteCharAt(cookiesJson.length() - 1);
        cookiesJson.append("}");
        return cookiesJson.toString();
    }

    public void setCookies(String request) {
        request += "cookies: ";
        for (Map.Entry<String, String> cookie : cookies.entrySet()) {
            request += cookie.getKey() + "=" + cookie.getValue() + "; ";
        }
    }
}