package org.example;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.*;

public class SignInSystemTest {

    private SignInSystem signInSystem;

    @BeforeEach
    public void setUp() {
        signInSystem = new SignInSystem();
    }

    @Test
    public void testAddUser1() {
        boolean result = signInSystem.addUser("user1");
        assertTrue(result);
    }

    @Test
    public void testAddUser2() {
        signInSystem.addUser("user1");
        boolean result = signInSystem.addUser("user1");
        assertFalse(result);
    }

    @Test
    public void testAddUser3() {
        boolean result = signInSystem.addUser("aaa");
        assertTrue(result);
    }

    @Test
    public void testAddUser4() {
        boolean result = signInSystem.addUser("bbb");
        assertTrue(result);
    }

    @Test
    public void testAddUser5() {
        boolean result = signInSystem.addUser("ccc");
        assertTrue(result);
    }

    @Test
    public void testSignIn1() {
        signInSystem.addUser("user1");
        boolean result = signInSystem.signIn("user1");
        assertTrue(result);
    }

    @Test
    public void testSignIn2() {
        boolean result = signInSystem.signIn("user1");
        assertFalse(result);
    }

    @Test
    public void testSignIn3() {
        signInSystem.addUser("aaa");
        boolean result = signInSystem.signIn("aaa");
        assertTrue(result);
    }

    @Test
    public void testSignIn4() {
        signInSystem.addUser("bbb");
        boolean result = signInSystem.signIn("bbb");
        assertTrue(result);
    }

    @Test
    public void testSignIn5() {
        boolean result = signInSystem.signIn("ccc");
        assertFalse(result);
    }

    @Test
    public void testCheckSignIn1() {
        signInSystem.addUser("user1");
        signInSystem.signIn("user1");
        boolean result = signInSystem.checkSignIn("user1");
        assertTrue(result);
    }

    @Test
    public void testCheckSignIn2() {
        signInSystem.addUser("user1");
        boolean result = signInSystem.checkSignIn("user1");
        assertFalse(result);
    }

    @Test
    public void testCheckSignIn3() {
        boolean result = signInSystem.checkSignIn("user1");
        assertFalse(result);
    }

    @Test
    public void testCheckSignIn4() {
        signInSystem.addUser("aaa");
        signInSystem.signIn("aaa");
        boolean result = signInSystem.checkSignIn("aaa");
        assertTrue(result);
    }

    @Test
    public void testCheckSignIn5() {
        signInSystem.addUser("bbb");
        signInSystem.signIn("bbb");
        boolean result = signInSystem.checkSignIn("bbb");
        assertTrue(result);
    }

    @Test
    public void testAllSignedIn1() {
        signInSystem.addUser("user1");
        signInSystem.signIn("user1");
        boolean result = signInSystem.allSignedIn();
        assertTrue(result);
    }

    @Test
    public void testAllSignedIn2() {
        signInSystem.addUser("user1");
        boolean result = signInSystem.allSignedIn();
        assertFalse(result);
    }

    @Test
    public void testAllSignedIn3() {
        signInSystem.addUser("aaa");
        signInSystem.signIn("aaa");
        boolean result = signInSystem.allSignedIn();
        assertTrue(result);
    }

    @Test
    public void testAllSignedIn4() {
        signInSystem.addUser("bbb");
        signInSystem.signIn("bbb");
        boolean result = signInSystem.allSignedIn();
        assertTrue(result);
    }

    @Test
    public void testAllSignedIn5() {
        signInSystem.addUser("aaa");
        signInSystem.addUser("bbb");
        signInSystem.signIn("aaa");
        boolean result = signInSystem.allSignedIn();
        assertFalse(result);
    }

    @Test
    public void testAllNotSignedIn1() {
        signInSystem.addUser("user1");
        signInSystem.signIn("user1");
        List<String> result = signInSystem.allNotSignedIn();
        assertEquals(0, result.size());
    }

    @Test
    public void testAllNotSignedIn2() {
        signInSystem.addUser("user1");
        signInSystem.addUser("user2");
        List<String> result = signInSystem.allNotSignedIn();
        assertEquals(2, result.size());
        assertTrue(result.contains("user1"));
        assertTrue(result.contains("user2"));
    }

    @Test
    public void testAllNotSignedIn3() {
        signInSystem.addUser("aaa");
        signInSystem.signIn("aaa");
        List<String> result = signInSystem.allNotSignedIn();
        assertEquals(0, result.size());
    }

    @Test
    public void testAllNotSignedIn4() {
        signInSystem.addUser("user1");
        signInSystem.addUser("aaa");
        signInSystem.signIn("user1");
        List<String> result = signInSystem.allNotSignedIn();
        assertEquals(1, result.size());
        assertTrue(result.contains("aaa"));
    }

    @Test
    public void testAllNotSignedIn5() {
        List<String> result = signInSystem.allNotSignedIn();
        assertEquals(0, result.size());
    }

    @Test
    public void testMain() {
        boolean result = signInSystem.addUser("user1");
        result = signInSystem.addUser("user2");
        assertTrue(result);

        result = signInSystem.signIn("user1");
        assertTrue(result);

        result = signInSystem.checkSignIn("user1");
        assertTrue(result);

        result = signInSystem.allSignedIn();
        assertFalse(result);

        List<String> notSignedInUsers = signInSystem.allNotSignedIn();
        assertEquals(1, notSignedInUsers.size());
        assertTrue(notSignedInUsers.contains("user2"));
    }
}