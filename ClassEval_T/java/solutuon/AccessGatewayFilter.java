package org.example;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Map;

public class AccessGatewayFilter {

    public AccessGatewayFilter() {
    }

    public boolean filter(Map<String, Object> request) {
        String requestUri = (String) request.get("path");
        String method = (String) request.get("method");

        if (isStartWith(requestUri)) {
            return true;
        }

        try {
            Map<String, Object> token = getJwtUser(request);
            Map<String, Object> user = (Map<String, Object>) token.get("user");
            if ((int) user.get("level") > 2) {
                setCurrentUserInfoAndLog(user);
                return true;
            }
        } catch (Exception e) {
            return false;
        }
        return false;
    }

    public boolean isStartWith(String requestUri) {
        String[] startWith = {"/api", "/login"};
        for (String s : startWith) {
            if (requestUri.startsWith(s)) {
                return true;
            }
        }
        return false;
    }

    public Map<String, Object> getJwtUser(Map<String, Object> request) {
        Map<String, Object> token = (Map<String, Object>) ((Map<String, Object>) request.get("headers")).get("Authorization");
        Map<String, Object> user = (Map<String, Object>) token.get("user");
        String jwt = (String) token.get("jwt");

        if (jwt.startsWith((String) user.get("name"))) {
            String jwtStrDate = jwt.substring(((String) user.get("name")).length());
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
            LocalDate jwtDate = LocalDate.parse(jwtStrDate, formatter);
            if (LocalDate.now().minusDays(3).isAfter(jwtDate)) {
                return null;
            }
        }
        return token;
    }

    public void setCurrentUserInfoAndLog(Map<String, Object> user) {
        String host = (String) user.get("address");
        String message = user.get("name") + host + LocalDate.now();
        System.out.println(message);
    }
}
