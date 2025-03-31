package test_cases;
import to_be_tested.UserLoginDB;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import java.io.File;
import java.nio.file.Files;

import static org.junit.jupiter.api.Assertions.*;

public class UserLoginDBTest {
    private String dbPath;
    private UserLoginDB db;

    @BeforeEach
    public void setUp() throws Exception {
        dbPath = Files.createTempFile("test_db", ".db").toString();
        db = new UserLoginDB(dbPath);
    }

    @AfterEach
    public void tearDown() {
        db.close();
        new File(dbPath).delete();
    }

    @Test
    public void testInsertUser1() {
        db.insertUser("user1", "pass1");
        String user = db.searchUserByUsername("user1");
        assertNotNull(user);
        assertEquals("user1,pass1", user);
    }

    @Test
    public void testInsertUser2() {
        db.insertUser("user2", "pass2");
        String user = db.searchUserByUsername("user2");
        assertNotNull(user);
        assertEquals("user2,pass2", user);
    }

    @Test
    public void testInsertUser3() {
        db.insertUser("user3", "pass3");
        String user = db.searchUserByUsername("user3");
        assertNotNull(user);
        assertEquals("user3,pass3", user);
    }

    @Test
    public void testInsertUser4() {
        db.insertUser("user4", "pass4");
        String user = db.searchUserByUsername("user4");
        assertNotNull(user);
        assertEquals("user4,pass4", user);
    }

    @Test
    public void testInsertUser5() {
        db.insertUser("user5", "pass5");
        String user = db.searchUserByUsername("user5");
        assertNotNull(user);
        assertEquals("user5,pass5", user);
    }

    @Test
    public void testSearchUserByUsername1() {
        db.insertUser("user1", "pass1");
        String user = db.searchUserByUsername("user1");
        assertNotNull(user);
        assertEquals("user1,pass1", user);
    }

    @Test
    public void testSearchUserByUsername2() {
        db.insertUser("user2", "pass2");
        String user = db.searchUserByUsername("user2");
        assertNotNull(user);
        assertEquals("user2,pass2", user);
    }

    @Test
    public void testSearchUserByUsername3() {
        db.insertUser("user3", "pass3");
        String user = db.searchUserByUsername("user3");
        assertNotNull(user);
        assertEquals("user3,pass3", user);
    }

    @Test
    public void testSearchUserByUsername4() {
        db.insertUser("user4", "pass4");
        String user = db.searchUserByUsername("user4");
        assertNotNull(user);
        assertEquals("user4,pass4", user);
    }

    @Test
    public void testSearchUserByUsername5() {
        db.insertUser("user5", "pass5");
        String user = db.searchUserByUsername("user5");
        assertNotNull(user);
        assertEquals("user5,pass5", user);
    }

    @Test
    public void testDeleteUserByUsername1() {
        db.insertUser("user1", "pass1");
        db.deleteUserByUsername("user1");
        String user = db.searchUserByUsername("user1");
        assertNull(user);
    }

    @Test
    public void testDeleteUserByUsername2() {
        db.insertUser("user2", "pass2");
        db.deleteUserByUsername("user2");
        String user = db.searchUserByUsername("user2");
        assertNull(user);
    }

    @Test
    public void testDeleteUserByUsername3() {
        db.insertUser("user3", "pass3");
        db.deleteUserByUsername("user3");
        String user = db.searchUserByUsername("user3");
        assertNull(user);
    }

    @Test
    public void testDeleteUserByUsername4() {
        db.insertUser("user4", "pass4");
        db.deleteUserByUsername("user4");
        String user = db.searchUserByUsername("user4");
        assertNull(user);
    }

    @Test
    public void testDeleteUserByUsername5() {
        db.insertUser("user5", "pass5");
        db.deleteUserByUsername("user5");
        String user = db.searchUserByUsername("user5");
        assertNull(user);
    }

    @Test
    public void testValidateUserLogin1() {
        db.insertUser("user1", "pass1");
        boolean valid = db.validateUserLogin("user1", "pass1");
        assertTrue(valid);
    }

    @Test
    public void testValidateUserLogin2() {
        db.insertUser("user1", "pass1");
        boolean invalid = db.validateUserLogin("user1", "wrongpass");
        assertFalse(invalid);
    }

    @Test
    public void testValidateUserLogin3() {
        boolean valid = db.validateUserLogin("nonexistentuser", "somepass");
        assertFalse(valid);
    }

    @Test
    public void testValidateUserLogin4() {
        db.insertUser("user2", "pass2");
        boolean valid = db.validateUserLogin("user2", "pass2");
        assertTrue(valid);
    }

    @Test
    public void testValidateUserLogin5() {
        db.insertUser("user3", "pass3");
        boolean valid = db.validateUserLogin("user3", "pass3");
        assertTrue(valid);
    }

    @Test
    public void testUserLoginDB() {
        db.insertUser("user1", "pass1");
        String user = db.searchUserByUsername("user1");
        assertNotNull(user);
        assertEquals("user1,pass1", user);
        db.deleteUserByUsername("user1");
        user = db.searchUserByUsername("user1");
        assertNull(user);
        db.insertUser("user1", "pass1");
        boolean valid = db.validateUserLogin("user1", "pass1");
        assertTrue(valid);
    }
}