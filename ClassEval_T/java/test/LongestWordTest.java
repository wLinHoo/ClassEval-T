package org.example;

import org.junit.jupiter.api.Test;
import java.util.Arrays;
import static org.junit.jupiter.api.Assertions.*;

public class LongestWordTest {

    @Test
    public void testAddWord1() {
        LongestWord longestWord = new LongestWord();
        longestWord.addWord("hello");
        assertEquals(Arrays.asList("hello"), longestWord.wordList);
    }

    @Test
    public void testAddWord2() {
        LongestWord longestWord = new LongestWord();
        longestWord.addWord("hello");
        longestWord.addWord("world");
        assertEquals(Arrays.asList("hello", "world"), longestWord.wordList);
    }

    @Test
    public void testAddWord3() {
        LongestWord longestWord = new LongestWord();
        longestWord.addWord("hello");
        longestWord.addWord("world");
        longestWord.addWord("!");
        assertEquals(Arrays.asList("hello", "world", "!"), longestWord.wordList);
    }

    @Test
    public void testAddWord4() {
        LongestWord longestWord = new LongestWord();
        longestWord.addWord("hello");
        longestWord.addWord("world");
        longestWord.addWord("!");
        longestWord.addWord("!");
        assertEquals(Arrays.asList("hello", "world", "!", "!"), longestWord.wordList);
    }

    @Test
    public void testAddWord5() {
        LongestWord longestWord = new LongestWord();
        longestWord.addWord("hello");
        longestWord.addWord("world");
        longestWord.addWord("!");
        longestWord.addWord("!");
        longestWord.addWord("!");
        assertEquals(Arrays.asList("hello", "world", "!", "!", "!"), longestWord.wordList);
    }

    @Test
    public void testFindLongestWord1() {
        LongestWord longestWord = new LongestWord();
        longestWord.addWord("a");
        String sentence = "I am a student.";
        assertEquals("a", longestWord.findLongestWord(sentence));
    }

    @Test
    public void testFindLongestWord2() {
        LongestWord longestWord = new LongestWord();
        String sentence = "I am a student.";
        assertEquals("", longestWord.findLongestWord(sentence));
    }

    @Test
    public void testFindLongestWord3() {
        LongestWord longestWord = new LongestWord();
        longestWord.addWord("student");
        String sentence = "I am a student.";
        assertEquals("student", longestWord.findLongestWord(sentence));
    }

    @Test
    public void testFindLongestWord4() {
        LongestWord longestWord = new LongestWord();
        longestWord.addWord("apple");
        String sentence = "Apple is red.";
        assertEquals("apple", longestWord.findLongestWord(sentence));
    }

    @Test
    public void testFindLongestWord5() {
        LongestWord longestWord = new LongestWord();
        longestWord.addWord("apple");
        longestWord.addWord("red");
        String sentence = "Apple is red.";
        assertEquals("apple", longestWord.findLongestWord(sentence));
    }
}