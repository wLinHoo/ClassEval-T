package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class PersonRequestTest {

    @Test
    public void testValidateName1() {
        PersonRequest pr = new PersonRequest("", "Man", "12345678901");
        assertNull(pr.getName());
    }

    @Test
    public void testValidateName2() {
        PersonRequest pr = new PersonRequest("This is a very long name that exceeds the character limit", "Man", "12345678901");
        assertNull(pr.getName());
    }

    @Test
    public void testValidateName3() {
        PersonRequest pr = new PersonRequest("aaa", "Man", "12345678901");
        assertEquals("aaa", pr.getName());
    }

    @Test
    public void testValidateName4() {
        PersonRequest pr = new PersonRequest("bbb", "Man", "12345678901");
        assertEquals("bbb", pr.getName());
    }

    @Test
    public void testValidateName5() {
        PersonRequest pr = new PersonRequest("ccc", "Man", "12345678901");
        assertEquals("ccc", pr.getName());
    }

    @Test
    public void testValidateSex1() {
        PersonRequest pr = new PersonRequest("John Doe", "Unknown", "12345678901");
        assertNull(pr.getSex());
    }

    @Test
    public void testValidateSex2() {
        PersonRequest pr = new PersonRequest("John Doe", "UGM", "12345678901");
        assertEquals("UGM", pr.getSex());
    }

    @Test
    public void testValidateSex3() {
        PersonRequest pr = new PersonRequest("John Doe", "Man", "12345678901");
        assertEquals("Man", pr.getSex());
    }

    @Test
    public void testValidateSex4() {
        PersonRequest pr = new PersonRequest("John Doe", "Woman", "12345678901");
        assertEquals("Woman", pr.getSex());
    }

    @Test
    public void testValidateSex5() {
        PersonRequest pr = new PersonRequest("John Doe", "khsigy", "12345678901");
        assertNull(pr.getSex());
    }

    @Test
    public void testValidatePhoneNumber1() {
        PersonRequest pr = new PersonRequest("John Doe", "Man", "");
        assertNull(pr.getPhoneNumber());
    }

    @Test
    public void testValidatePhoneNumber2() {
        PersonRequest pr = new PersonRequest("John Doe", "Man", "12345");
        assertNull(pr.getPhoneNumber());
    }

    @Test
    public void testValidatePhoneNumber3() {
        PersonRequest pr = new PersonRequest("John Doe", "Man", "jgdjrj");
        assertNull(pr.getPhoneNumber());
    }

    @Test
    public void testValidatePhoneNumber4() {
        PersonRequest pr = new PersonRequest("John Doe", "Man", "12345678901");
        assertEquals("12345678901", pr.getPhoneNumber());
    }

    @Test
    public void testValidatePhoneNumber5() {
        PersonRequest pr = new PersonRequest("John Doe", "Man", "11111111111");
        assertEquals("11111111111", pr.getPhoneNumber());
    }

    @Test
    public void testPersonRequest() {
        PersonRequest pr = new PersonRequest("", "Man", "12345678901");
        assertNull(pr.getName());

        pr = new PersonRequest("John Doe", "Unknown", "12345678901");
        assertNull(pr.getSex());

        pr = new PersonRequest("John Doe", "Man", "");
        assertNull(pr.getPhoneNumber());
    }
}