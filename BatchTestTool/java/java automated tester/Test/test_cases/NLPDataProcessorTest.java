package test_cases;
import to_be_tested.NLPDataProcessor;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.Arrays;
import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class NLPDataProcessorTest {

    private NLPDataProcessor processor;

    @BeforeEach
    public void setUp() {
        processor = new NLPDataProcessor();
    }

    @Test
    public void testConstructStopWordList() {
        List<String> stopWordList = processor.constructStopWordList();
        List<String> expectedStopWords = Arrays.asList("a", "an", "the");
        assertEquals(expectedStopWords, stopWordList);
    }

    @Test
    public void testRemoveStopWords() {
        List<String> stringList = Arrays.asList("This is a test", "This is an apple", "This is the dog");
        List<String> stopWordList = Arrays.asList("a", "an", "the");
        List<List<String>> wordsList = processor.removeStopWords(stringList, stopWordList);
        List<List<String>> expectedWordsList = Arrays.asList(
                Arrays.asList("This", "is", "test"),
                Arrays.asList("This", "is", "apple"),
                Arrays.asList("This", "is", "dog")
        );
        assertEquals(expectedWordsList, wordsList);
    }

    @Test
    public void testRemoveStopWords2() {
        List<String> stringList = Arrays.asList("a", "an", "the");
        List<String> stopWordList = Arrays.asList("a", "an", "the");
        List<List<String>> wordsList = processor.removeStopWords(stringList, stopWordList);
        assertEquals(Arrays.asList(Arrays.asList(), Arrays.asList(), Arrays.asList()), wordsList);
    }

    @Test
    public void testRemoveStopWords3() {
        List<String> stringList = Arrays.asList();
        List<String> stopWordList = Arrays.asList("a", "an", "the");
        List<List<String>> wordsList = processor.removeStopWords(stringList, stopWordList);
        assertEquals(Arrays.asList(), wordsList);
    }

    @Test
    public void testRemoveStopWords4() {
        List<String> stringList = Arrays.asList("This is a test", "This is an apple", "This is the dog");
        List<String> stopWordList = Arrays.asList();
        List<List<String>> wordsList = processor.removeStopWords(stringList, stopWordList);
        List<List<String>> expectedWordsList = Arrays.asList(
                Arrays.asList("This", "is", "a", "test"),
                Arrays.asList("This", "is", "an", "apple"),
                Arrays.asList("This", "is", "the", "dog")
        );
        assertEquals(expectedWordsList, wordsList);
    }

    @Test
    public void testRemoveStopWords5() {
        List<String> stringList = Arrays.asList("This is a test", "This is an apple", "This is the dog");
        List<String> stopWordList = Arrays.asList("a", "an", "the", "This", "is");
        List<List<String>> wordsList = processor.removeStopWords(stringList, stopWordList);
        List<List<String>> expectedWordsList = Arrays.asList(
                Arrays.asList("test"),
                Arrays.asList("apple"),
                Arrays.asList("dog")
        );
        assertEquals(expectedWordsList, wordsList);
    }

    @Test
    public void testProcess() {
        List<String> stringList = Arrays.asList("This is a test.", "This is an apple.", "This is the dog.");
        List<List<String>> wordsList = processor.process(stringList);
        List<List<String>> expectedWordsList = Arrays.asList(
                Arrays.asList("This", "is", "test."),
                Arrays.asList("This", "is", "apple."),
                Arrays.asList("This", "is", "dog.")
        );
        assertEquals(expectedWordsList, wordsList);
    }

    @Test
    public void testProcessWithEmptyStringList() {
        List<String> stringList = Arrays.asList();
        List<List<String>> wordsList = processor.process(stringList);
        assertEquals(Arrays.asList(), wordsList);
    }

    @Test
    public void testProcessWithSingleWordSentences() {
        List<String> stringList = Arrays.asList("Hello aa", "World");
        List<List<String>> wordsList = processor.process(stringList);
        List<List<String>> expectedWordsList = Arrays.asList(
                Arrays.asList("Hello", "aa"),
                Arrays.asList("World")
        );
        assertEquals(expectedWordsList, wordsList);
    }

    @Test
    public void testProcessWithStopWordsOnly() {
        List<String> stringList = Arrays.asList("a", "an", "the");
        List<List<String>> wordsList = processor.process(stringList);
        assertEquals(Arrays.asList(Arrays.asList(), Arrays.asList(), Arrays.asList()), wordsList);
    }

    @Test
    public void testProcessWithStopWordsOnly2() {
        List<String> stringList = Arrays.asList("a", "an", "the", "This");
        List<List<String>> wordsList = processor.process(stringList);
        assertEquals(Arrays.asList(Arrays.asList(), Arrays.asList(), Arrays.asList(), Arrays.asList("This")), wordsList);
    }
}