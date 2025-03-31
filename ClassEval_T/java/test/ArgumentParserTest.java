package org.example;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import static org.junit.jupiter.api.Assertions.*;

public class ArgumentParserTest {

    private ArgumentParser parser;

    @BeforeEach
    public void setUp() {
        parser = new ArgumentParser();
    }

    @Test
    public void testParseArguments1() {
        String commandStr = "script --name=John --age=25";
        parser.addArgument("name", false, String.class);
        parser.addArgument("age", false, Integer.class);

        ArgumentParser.Tuple<Boolean, Set<String>> result = parser.parseArguments(commandStr);

        assertTrue(result.x);
        assertNull(result.y);
        assertEquals("John", parser.getArgument("name"));
        assertEquals(25, parser.getArgument("age"));
    }

    @Test
    public void testParseArguments2() {
        String commandStr = "script --verbose -d";
        parser.addArgument("verbose", false, Boolean.class);
        parser.addArgument("d", false, Boolean.class);

        ArgumentParser.Tuple<Boolean, Set<String>> result = parser.parseArguments(commandStr);

        assertTrue(result.x);
        assertNull(result.y);
        assertEquals(true, parser.getArgument("verbose"));
        assertEquals(true, parser.getArgument("d"));
    }

    @Test
    public void testParseArguments3() {
        String commandStr = "script --name=John";
        parser.addArgument("name", false, String.class);
        parser.addArgument("age", true, Integer.class);

        ArgumentParser.Tuple<Boolean, Set<String>> result = parser.parseArguments(commandStr);

        assertFalse(result.x);
        assertEquals(Set.of("age"), result.y);
    }

    @Test
    public void testParseArguments4() {
        String commandStr = "script --name=John";
        parser.addArgument("name", false, String.class);
        parser.addArgument("age", false, Integer.class);

        ArgumentParser.Tuple<Boolean, Set<String>> result = parser.parseArguments(commandStr);

        assertTrue(result.x);
        assertNull(result.y);
    }

    @Test
    public void testParseArguments5() {
        String commandStr = "script --name=John";
        parser.addArgument("name", false, String.class);
        parser.addArgument("age", false, Integer.class);

        ArgumentParser.Tuple<Boolean, Set<String>> result = parser.parseArguments(commandStr);

        assertTrue(result.x);
        assertNull(result.y);
    }

    @Test
    public void testGetArgument1() {
        parser.arguments = new HashMap<>(Map.of("name", "John"));
        Object result = parser.getArgument("name");
        assertEquals("John", result);
    }

    @Test
    public void testGetArgument2() {
        parser.arguments = new HashMap<>(Map.of("name", "John", "age", 25));
        Object result = parser.getArgument("age");
        assertEquals(25, result);
    }

    @Test
    public void testGetArgument3() {
        parser.arguments = new HashMap<>(Map.of("name", "John", "age", "25", "verbose", true));
        Object result = parser.getArgument("verbose");
        assertEquals(true, result);
    }

    @Test
    public void testGetArgument4() {
        parser.arguments = new HashMap<>(Map.of("name", "Amy", "age", 25, "verbose", true, "d", true));
        Object result = parser.getArgument("d");
        assertEquals(true, result);
    }

    @Test
    public void testGetArgument5() {
        parser.arguments = new HashMap<>(Map.of("name", "John", "age", 25, "verbose", true, "d", true, "option", "value"));
        Object result = parser.getArgument("option");
        assertEquals("value", result);
    }

    @Test
    public void testAddArgument() {
        parser.addArgument("name", false, String.class);
        parser.addArgument("age", true, Integer.class);

        assertEquals(Set.of("age"), parser.required);
        assertEquals(Map.of("name", String.class, "age", Integer.class), parser.types);
    }

    @Test
    public void testAddArgument2() {
        parser.addArgument("name", false, String.class);
        parser.addArgument("age", false, Integer.class);
        parser.addArgument("verbose", false, Boolean.class);

        assertEquals(Set.of(), parser.required);
        assertEquals(Map.of("name", String.class, "age", Integer.class, "verbose", Boolean.class), parser.types);
    }

    @Test
    public void testAddArgument3() {
        parser.addArgument("name", false, String.class);
        parser.addArgument("age", false, Integer.class);
        parser.addArgument("verbose", false, Boolean.class);
        parser.addArgument("d", false, String.class);

        assertEquals(Set.of(), parser.required);
        assertEquals(Map.of("name", String.class, "age", Integer.class, "verbose", Boolean.class, "d", String.class), parser.types);
    }

    @Test
    public void testAddArgument4() {
        parser.addArgument("name", false, String.class);
        parser.addArgument("age", false, Integer.class);
        parser.addArgument("verbose", false, Boolean.class);
        parser.addArgument("d", false, String.class);
        parser.addArgument("option", false, String.class);

        assertEquals(Set.of(), parser.required);
        assertEquals(Map.of("name", String.class, "age", Integer.class, "verbose", Boolean.class, "d", String.class, "option", String.class), parser.types);
    }

    @Test
    public void testAddArgument5() {
        parser.addArgument("name", false, String.class);
        parser.addArgument("age", false, Integer.class);
        parser.addArgument("verbose", false, Boolean.class);
        parser.addArgument("d", false, String.class);
        parser.addArgument("option", false, String.class);
        parser.addArgument("option2", false, Boolean.class);

        assertEquals(Set.of(), parser.required);
        assertEquals(Map.of("name", String.class, "age", Integer.class, "verbose", Boolean.class, "d", String.class, "option", String.class, "option2", Boolean.class), parser.types);
    }

    @Test
    public void testConvertType1() {
        parser.types = new HashMap<>(Map.of("age", Integer.class));
        Object result = parser.convertType("age", "25");
        assertEquals(25, result);
    }

    @Test
    public void testConvertType2() {
        parser.types = new HashMap<>(Map.of("age", Integer.class));
        Object result = parser.convertType("age", "twenty-five");
        assertEquals("twenty-five", result);
    }

    @Test
    public void testConvertType3() {
        parser.types = new HashMap<>(Map.of("age", Integer.class));
        Object result = parser.convertType("age", "25");
        assertEquals(25, result);
    }

    @Test
    public void testConvertType4() {
        parser.types = new HashMap<>(Map.of("age", Integer.class, "verbose", Boolean.class));
        Object result = parser.convertType("verbose", "True");
        assertEquals(true, result);
    }

    @Test
    public void testConvertType5() {
        parser.types = new HashMap<>(Map.of("age", Integer.class, "verbose", Boolean.class));
        Object result = parser.convertType("verbose", "False");
        assertEquals(false, result);
    }

    @Test
    public void testMain() {
        ArgumentParser parser = new ArgumentParser();
        String command = "script --arg1=21 --option1 -arg2 value -option2";

        parser.addArgument("arg1", true, Integer.class);
        parser.addArgument("arg2", false, String.class);

        assertEquals(Set.of("arg1"), parser.required);
        assertEquals(Map.of("arg1", Integer.class, "arg2", String.class), parser.types);
        assertEquals(new HashMap<>(), parser.arguments);

        parser.parseArguments(command);
        Map<String, Object> arguments = new HashMap<>(Map.of("arg1", 21, "option1", true, "arg2", "value", "option2", true));
        assertEquals(arguments, parser.arguments);
    }
}