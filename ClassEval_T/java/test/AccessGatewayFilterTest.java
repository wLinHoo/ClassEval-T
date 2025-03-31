package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

import java.time.LocalDate;
import java.util.HashMap;
import java.util.Map;

public class AccessGatewayFilterTest {

    private final AccessGatewayFilter agf = new AccessGatewayFilter();

    @Test
    public void testFilter1() {
        Map<String, Object> request = new HashMap<>();
        request.put("path", "/api/data");
        request.put("method", "GET");
        boolean res = agf.filter(request);
        assertTrue(res);
    }

    @Test
    public void testFilter2() {
        Map<String, Object> request = new HashMap<>();
        request.put("path", "/api/data");
        request.put("method", "POST");
        boolean res = agf.filter(request);
        assertTrue(res);
    }

    @Test
    public void testFilter3() {
        Map<String, Object> request = new HashMap<>();
        request.put("path", "/login/data");
        request.put("method", "GET");
        boolean res = agf.filter(request);
        assertTrue(res);
    }

    @Test
    public void testFilter4() {
        Map<String, Object> request = new HashMap<>();
        request.put("path", "/login/data");
        request.put("method", "POST");
        boolean res = agf.filter(request);
        assertTrue(res);
    }

    @Test
    public void testFilter5() {
        Map<String, Object> request = new HashMap<>();
        Map<String, Object> user = new HashMap<>();
        user.put("name", "user1");
        user.put("level", 5);
        user.put("address", "address1");
        Map<String, Object> token = new HashMap<>();
        token.put("user", user);
        token.put("jwt", "user1" + LocalDate.now().toString());

        Map<String, Object> headers = new HashMap<>();
        headers.put("Authorization", token);

        request.put("path", "/abc");
        request.put("method", "POST");
        request.put("headers", headers);

        boolean res = agf.filter(request);
        assertTrue(res);
    }

    @Test
    public void testFilter6() {
        Map<String, Object> request = new HashMap<>();
        Map<String, Object> user = new HashMap<>();
        user.put("name", "user1");
        user.put("level", 3);
        user.put("address", "address1");
        Map<String, Object> token = new HashMap<>();
        token.put("user", user);
        token.put("jwt", "user1" + LocalDate.now().minusDays(365).toString());

        Map<String, Object> headers = new HashMap<>();
        headers.put("Authorization", token);

        request.put("path", "/abc");
        request.put("method", "POST");
        request.put("headers", headers);

        boolean res = agf.filter(request);
        assertFalse(res);
    }

    @Test
    public void testFilter7() {
        Map<String, Object> request = new HashMap<>();
        Map<String, Object> user = new HashMap<>();
        user.put("name", "user1");
        user.put("level", 1);
        user.put("address", "address1");
        Map<String, Object> token = new HashMap<>();
        token.put("user", user);
        token.put("jwt", "user1" + LocalDate.now().toString());

        Map<String, Object> headers = new HashMap<>();
        headers.put("Authorization", token);

        request.put("path", "/abc");
        request.put("method", "POST");
        request.put("headers", headers);

        boolean res = agf.filter(request);
        assertFalse(res);
    }

    @Test
    public void testFilter8() {
        Map<String, Object> request = new HashMap<>();
        Map<String, Object> user = new HashMap<>();
        user.put("name", "user1");
        user.put("level", 3);
        user.put("address", "address1");
        Map<String, Object> token = new HashMap<>();
        token.put("user", user);
        token.put("jwt", "user2" + LocalDate.now().minusDays(365).toString());

        Map<String, Object> headers = new HashMap<>();
        headers.put("Authorization", token);

        request.put("path", "/abc");
        request.put("method", "POST");
        request.put("headers", headers);

        boolean res = agf.filter(request);
        assertTrue(res);
    }

    @Test
    public void testIsStartWith1() {
        String requestUri = "/api/data";
        boolean res = agf.isStartWith(requestUri);
        assertTrue(res);
    }

    @Test
    public void testIsStartWith2() {
        String requestUri = "/admin/settings";
        boolean res = agf.isStartWith(requestUri);
        assertFalse(res);
    }

    @Test
    public void testIsStartWith3() {
        String requestUri = "/login/data";
        boolean res = agf.isStartWith(requestUri);
        assertTrue(res);
    }

    @Test
    public void testIsStartWith4() {
        String requestUri = "/abc/data";
        boolean res = agf.isStartWith(requestUri);
        assertFalse(res);
    }

    @Test
    public void testIsStartWith5() {
        String requestUri = "/def/data";
        boolean res = agf.isStartWith(requestUri);
        assertFalse(res);
    }

    @Test
    public void testGetJwtUser1() {
        Map<String, Object> request = new HashMap<>();
        Map<String, Object> user = new HashMap<>();
        user.put("name", "user1");
        Map<String, Object> token = new HashMap<>();
        token.put("user", user);
        token.put("jwt", "user1" + LocalDate.now().toString());

        Map<String, Object> headers = new HashMap<>();
        headers.put("Authorization", token);

        request.put("headers", headers);

        Map<String, Object> res = agf.getJwtUser(request);
        assertNotNull(res);
    }

    @Test
    public void testGetJwtUser2() {
        Map<String, Object> request = new HashMap<>();
        Map<String, Object> user = new HashMap<>();
        user.put("name", "user2");
        Map<String, Object> token = new HashMap<>();
        token.put("user", user);
        token.put("jwt", "user2" + LocalDate.now().toString());

        Map<String, Object> headers = new HashMap<>();
        headers.put("Authorization", token);

        request.put("headers", headers);

        Map<String, Object> res = agf.getJwtUser(request);
        assertNotNull(res);
    }

    @Test
    public void testGetJwtUser3() {
        Map<String, Object> request = new HashMap<>();
        Map<String, Object> user = new HashMap<>();
        user.put("name", "user3");
        Map<String, Object> token = new HashMap<>();
        token.put("user", user);
        token.put("jwt", "user3" + LocalDate.now().toString());

        Map<String, Object> headers = new HashMap<>();
        headers.put("Authorization", token);

        request.put("headers", headers);

        Map<String, Object> res = agf.getJwtUser(request);
        assertNotNull(res);
    }

    @Test
    public void testGetJwtUser4() {
        Map<String, Object> request = new HashMap<>();
        Map<String, Object> user = new HashMap<>();
        user.put("name", "user4");
        Map<String, Object> token = new HashMap<>();
        token.put("user", user);
        token.put("jwt", "user4" + LocalDate.now().toString());

        Map<String, Object> headers = new HashMap<>();
        headers.put("Authorization", token);

        request.put("headers", headers);

        Map<String, Object> res = agf.getJwtUser(request);
        assertNotNull(res);
    }

    @Test
    public void testGetJwtUser5() {
        Map<String, Object> request = new HashMap<>();
        Map<String, Object> user = new HashMap<>();
        user.put("name", "user1");
        Map<String, Object> token = new HashMap<>();
        token.put("user", user);
        token.put("jwt", "user1" + LocalDate.now().minusDays(5).toString());

        Map<String, Object> headers = new HashMap<>();
        headers.put("Authorization", token);

        request.put("headers", headers);

        Map<String, Object> res = agf.getJwtUser(request);
        assertNull(res);
    }
}
