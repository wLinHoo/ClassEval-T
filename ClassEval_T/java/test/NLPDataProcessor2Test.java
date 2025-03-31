package org.example;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.*;
import java.util.stream.Collectors;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class NLPDataProcessor2Test {

    private NLPDataProcessor2 processor;

    @BeforeEach
    public void setUp() {
        processor = new NLPDataProcessor2();
    }

    @Test
    public void testProcessData() {
        List<String> stringList = Arrays.asList("Hello World!", "This is a test.");
        List<List<String>> expectedOutput = Arrays.asList(
                new ArrayList<>(Arrays.asList("hello", "world")),
                new ArrayList<>(Arrays.asList("this", "is", "a", "test"))
        );
        List<List<String>> actualOutput = processor.processData(stringList);
        assertEquals(expectedOutput, actualOutput);
    }

    @Test
    public void testProcessData2() {
        List<String> stringList = Arrays.asList("12345", "Special@Characters");
        List<List<String>> expectedOutput = Arrays.asList(
                new ArrayList<>(),
                new ArrayList<>(Collections.singletonList("specialcharacters"))
        );
        List<List<String>> actualOutput = processor.processData(stringList);
        assertEquals(expectedOutput, actualOutput);
    }

    @Test
    public void testProcessData3() {
        List<String> stringList = Collections.emptyList();
        List<List<String>> expectedOutput = Collections.emptyList();
        List<List<String>> actualOutput = processor.processData(stringList);
        assertEquals(expectedOutput, actualOutput);
    }

    @Test
    public void testProcessData4() {
        List<String> stringList = Arrays.asList("Hello World!", "This is a test.", "12345", "Special@Characters");
        List<List<String>> expectedOutput = Arrays.asList(
                new ArrayList<>(Arrays.asList("hello", "world")),
                new ArrayList<>(Arrays.asList("this", "is", "a", "test")),
                new ArrayList<>(),
                new ArrayList<>(Collections.singletonList("specialcharacters"))
        );
        List<List<String>> actualOutput = processor.processData(stringList);
        assertEquals(expectedOutput, actualOutput);
    }

    @Test
    public void testProcessData5() {
        List<String> stringList = Arrays.asList(
                "Hello World!", "This is a test.", "12345", "Special@Characters",
                "Hello World!", "This is a test.", "12345", "Special@Characters"
        );
        List<List<String>> expectedOutput = Arrays.asList(
                new ArrayList<>(Arrays.asList("hello", "world")),
                new ArrayList<>(Arrays.asList("this", "is", "a", "test")),
                new ArrayList<>(),
                new ArrayList<>(Collections.singletonList("specialcharacters")),
                new ArrayList<>(Arrays.asList("hello", "world")),
                new ArrayList<>(Arrays.asList("this", "is", "a", "test")),
                new ArrayList<>(),
                new ArrayList<>(Collections.singletonList("specialcharacters"))
        );
        List<List<String>> actualOutput = processor.processData(stringList);
        assertEquals(expectedOutput, actualOutput);
    }

    @Test
    public void testCalculateWordFrequency() {
        List<List<String>> wordsList = Arrays.asList(
                Arrays.asList("hello", "world"),
                Arrays.asList("this", "is", "a", "test"),
                Arrays.asList("hello", "world", "this", "is", "another", "test"),
                Arrays.asList("hello", "hello", "world")
        );

        Vector<NLPDataProcessor2.WordFrequency> expectedOutput = new Vector<>(Arrays.asList(
                new NLPDataProcessor2.WordFrequency("hello", 4),
                new NLPDataProcessor2.WordFrequency("world", 3),
                new NLPDataProcessor2.WordFrequency("this", 2),
                new NLPDataProcessor2.WordFrequency("is", 2),
                new NLPDataProcessor2.WordFrequency("test", 2)
        ));

        Vector<NLPDataProcessor2.WordFrequency> actualOutput = processor.calculateWordFrequency(wordsList);

        expectedOutput.sort(NLPDataProcessor2.WordFrequency.byFrequencyThenWord());
        actualOutput.sort(NLPDataProcessor2.WordFrequency.byFrequencyThenWord());

        assertEquals(expectedOutput, actualOutput);
    }


    @Test
    public void testCalculateWordFrequency2() {
        List<List<String>> wordsList = Arrays.asList(
                Arrays.asList("hello", "world"),
                Arrays.asList("this", "is", "a", "test"),
                Arrays.asList("hello", "world", "this", "is", "another", "test"),
                Arrays.asList("hello", "hello", "world"),
                Arrays.asList("world", "world", "world")
        );

        Vector<NLPDataProcessor2.WordFrequency> expectedOutput = new Vector<>(Arrays.asList(
                new NLPDataProcessor2.WordFrequency("world", 6),
                new NLPDataProcessor2.WordFrequency("hello", 4),
                new NLPDataProcessor2.WordFrequency("this", 2),
                new NLPDataProcessor2.WordFrequency("is", 2),
                new NLPDataProcessor2.WordFrequency("test", 2)
        ));

        Vector<NLPDataProcessor2.WordFrequency> actualOutput = processor.calculateWordFrequency(wordsList);

        Comparator<NLPDataProcessor2.WordFrequency> comparator = Comparator
                .comparingInt((NLPDataProcessor2.WordFrequency wf) -> -wf.frequency)
                .thenComparing(wf -> wf.word);

        expectedOutput.sort(comparator);
        actualOutput.sort(comparator);

        assertEquals(expectedOutput, actualOutput);
    }



    @Test
    public void testCalculateWordFrequency3() {
        List<List<String>> wordsList = Arrays.asList(
                Arrays.asList("hello", "world"),
                Arrays.asList("hello", "hello", "world"),
                Arrays.asList("world", "world")
        );
        Vector<NLPDataProcessor2.WordFrequency> expectedOutput = new Vector<>(Arrays.asList(
                new NLPDataProcessor2.WordFrequency("world", 4),
                new NLPDataProcessor2.WordFrequency("hello", 3)
        ));
        Vector<NLPDataProcessor2.WordFrequency> actualOutput = processor.calculateWordFrequency(wordsList);
        assertEquals(expectedOutput, actualOutput);
    }

    @Test
    public void testCalculateWordFrequency4() {
        List<List<String>> wordsList = Arrays.asList(
                Arrays.asList("hello", "world"),
                Arrays.asList("this", "is", "a", "%%%"),
                Arrays.asList("hello", "world", "this", "is", "another", "%%%"),
                Arrays.asList("hello", "hello", "world"),
                Arrays.asList("%%%", "world", "a", "%%%"),
                Arrays.asList("%%%", "hello", "%%%")
        );
        Vector<NLPDataProcessor2.WordFrequency> expectedOutput = new Vector<>(Arrays.asList(
                new NLPDataProcessor2.WordFrequency("%%%", 6),
                new NLPDataProcessor2.WordFrequency("hello", 5),
                new NLPDataProcessor2.WordFrequency("world", 4),
                new NLPDataProcessor2.WordFrequency("a", 2), // Adjusted this line
                new NLPDataProcessor2.WordFrequency("is", 2),
                new NLPDataProcessor2.WordFrequency("this", 2)
        ));
        Vector<NLPDataProcessor2.WordFrequency> actualOutput = processor.calculateWordFrequency(wordsList);

        Comparator<NLPDataProcessor2.WordFrequency> comparator = Comparator
                .comparingInt((NLPDataProcessor2.WordFrequency wf) -> -wf.frequency)
                .thenComparing(wf -> wf.word);

        expectedOutput.sort(comparator);
        actualOutput.sort(comparator);

        assertEquals(expectedOutput, actualOutput);
    }

    @Test
    public void testCalculateWordFrequency5() {
        List<List<String>> wordsList = Arrays.asList(
                Arrays.asList("hello", "world"),
                Arrays.asList("this", "is", "a", "%%%"),
                Arrays.asList("hello", "world", "this", "is", "another", "%%%"),
                Arrays.asList("hello", "hello", "world"),
                Arrays.asList("%%%", "world", "a", "%%%"),
                Arrays.asList("%%%", "hello", "%%%"),
                Arrays.asList("hello", "world"),
                Arrays.asList("this", "is", "a", "%%%"),
                Arrays.asList("hello", "world", "this", "is", "another", "%%%"),
                Arrays.asList("hello", "hello", "world"),
                Arrays.asList("%%%", "world", "a", "%%%"),
                Arrays.asList("%%%", "hello", "%%%")
        );

        Vector<NLPDataProcessor2.WordFrequency> actualOutput = processor.calculateWordFrequency(wordsList);

        Vector<NLPDataProcessor2.WordFrequency> expectedOutput = new Vector<>(Arrays.asList(
                new NLPDataProcessor2.WordFrequency("%%%", 12),
                new NLPDataProcessor2.WordFrequency("hello", 10),
                new NLPDataProcessor2.WordFrequency("world", 8),
                new NLPDataProcessor2.WordFrequency("this", 4),
                new NLPDataProcessor2.WordFrequency("is", 4)
        ));

        Vector<NLPDataProcessor2.WordFrequency> limitedActualOutput = actualOutput.stream()
                .limit(5)
                .collect(Collectors.toCollection(Vector::new));

        assertEquals(expectedOutput, limitedActualOutput);
    }
    @Test
    public void testProcess() {
        List<String> stringList = Arrays.asList("Hello World!", "This is a test.", "Hello World, this is a test.");

        List<NLPDataProcessor2.WordFrequency> expectedOutput = Arrays.asList(
                new NLPDataProcessor2.WordFrequency("a", 2),
                new NLPDataProcessor2.WordFrequency("hello", 2),
                new NLPDataProcessor2.WordFrequency("is", 2),
                new NLPDataProcessor2.WordFrequency("test", 2),
                new NLPDataProcessor2.WordFrequency("this", 2),
                new NLPDataProcessor2.WordFrequency("world", 2)
        );


        List<NLPDataProcessor2.WordFrequency> actualOutput = processor.process(stringList);


        Comparator<NLPDataProcessor2.WordFrequency> comparator = Comparator
                .comparingInt((NLPDataProcessor2.WordFrequency wf) -> -wf.frequency)
                .thenComparing(wf -> wf.word);

        Collections.sort(expectedOutput, comparator);
        Collections.sort(actualOutput, comparator);

        assertEquals(expectedOutput, actualOutput);
    }


    @Test
    public void testProcess2() {
        List<String> stringList = Collections.emptyList();
        List<List<String>> expectedOutput = Collections.emptyList();
        List<List<String>> actualOutput = processor.processData(stringList);
        assertEquals(expectedOutput, actualOutput);
    }

    @Test
    public void testCalculate3() {
        List<List<String>> wordsList = Collections.emptyList();
        Vector<NLPDataProcessor2.WordFrequency> expectedOutput = new Vector<>();
        Vector<NLPDataProcessor2.WordFrequency> actualOutput = processor.calculateWordFrequency(wordsList);
        assertEquals(expectedOutput, actualOutput);
    }

    @Test
    public void testProcess4() {
        List<String> stringList = Arrays.asList("@#$%^&*", "Special_Characters", "12345");
        List<List<String>> expectedOutput = Arrays.asList(
                new ArrayList<>(),
                new ArrayList<>(Collections.singletonList("specialcharacters")),
                new ArrayList<>()
        );
        List<List<String>> actualOutput = processor.processData(stringList);
        assertEquals(expectedOutput, actualOutput);
    }

    @Test
    public void testProcess5() {
        List<String> stringList = Arrays.asList(
                "Hello World! %%%", "This is a %%% test. %%% ", "Hello World, this is a test. %%%"
        );
        Vector<NLPDataProcessor2.WordFrequency> expectedOutput = new Vector<>(Arrays.asList(
                new NLPDataProcessor2.WordFrequency("a", 2),
                new NLPDataProcessor2.WordFrequency("hello", 2),
                new NLPDataProcessor2.WordFrequency("is", 2),
                new NLPDataProcessor2.WordFrequency("test", 2),
                new NLPDataProcessor2.WordFrequency("this", 2),
                new NLPDataProcessor2.WordFrequency("world", 2)
        ));
        Vector<NLPDataProcessor2.WordFrequency> actualOutput = processor.process(stringList);

        Comparator<NLPDataProcessor2.WordFrequency> comparator = Comparator
                .comparingInt((NLPDataProcessor2.WordFrequency wf) -> -wf.frequency)
                .thenComparing(wf -> wf.word);

        expectedOutput.sort(comparator);
        actualOutput.sort(comparator);

        assertEquals(expectedOutput, actualOutput);
    }

    @Test
    public void testProcess6() {
        List<String> stringList = Arrays.asList("12345", "67890", "98765");
        List<List<String>> expectedOutput = Arrays.asList(
                new ArrayList<>(),
                new ArrayList<>(),
                new ArrayList<>()
        );
        List<List<String>> actualOutput = processor.processData(stringList);
        assertEquals(expectedOutput, actualOutput);
    }
}
