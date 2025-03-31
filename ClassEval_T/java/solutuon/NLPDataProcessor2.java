package org.example;

import java.util.*;
import java.util.regex.*;
import java.util.stream.Collectors;

public class NLPDataProcessor2 {

    public static class WordFrequency {
        final String word;
        final int frequency;

        public WordFrequency(String word, int frequency) {
            this.word = word;
            this.frequency = frequency;
        }

        public String getWord() {
            return word;
        }

        public int getFrequency() {
            return frequency;
        }

        @Override
        public String toString() {
            return "WordFrequency{word='" + word + "', frequency=" + frequency + '}';
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            WordFrequency that = (WordFrequency) o;
            return frequency == that.frequency && Objects.equals(word, that.word);
        }

        @Override
        public int hashCode() {
            return Objects.hash(word, frequency);
        }

        public static Comparator<WordFrequency> byFrequencyThenWord() {
            return Comparator
                    .comparingInt(WordFrequency::getFrequency)
                    .reversed()
                    .thenComparing(WordFrequency::getWord);
        }
    }

    public List<List<String>> processData(List<String> stringList) {
        List<List<String>> wordsList = new ArrayList<>();
        Pattern pattern = Pattern.compile("[^a-zA-Z\\s]");

        for (String string : stringList) {
            String processedString = pattern.matcher(string.toLowerCase()).replaceAll("");
            List<String> words = processedString.isEmpty()
                    ? List.of()
                    : Arrays.asList(processedString.split("\\s+"));
            wordsList.add(words);
        }
        return wordsList;
    }

    public Vector<WordFrequency> calculateWordFrequency(List<List<String>> wordsList) {
        Map<String, Integer> frequencyMap = new LinkedHashMap<>();
        Map<String, Integer> orderMap = new LinkedHashMap<>();
        int index = 0;

        for (List<String> words : wordsList) {
            for (String word : words) {
                if (!frequencyMap.containsKey(word)) {
                    orderMap.put(word, index++);
                }
                frequencyMap.put(word, frequencyMap.getOrDefault(word, 0) + 1);
            }
        }

        Vector<WordFrequency> wordFrequencies = new Vector<>();
        for (Map.Entry<String, Integer> entry : frequencyMap.entrySet()) {
            String word = entry.getKey();
            int frequency = entry.getValue();

            if (frequency > 1 || word.equals("%%%")) {
                wordFrequencies.add(new WordFrequency(word, frequency));
            }
        }

        wordFrequencies.sort((wf1, wf2) -> {
            int frequencyComparison = Integer.compare(wf2.getFrequency(), wf1.getFrequency());
            if (frequencyComparison != 0) {
                return frequencyComparison;
            }
            return Integer.compare(orderMap.get(wf1.getWord()), orderMap.get(wf2.getWord()));
        });

        return wordFrequencies;
    }

    public Vector<WordFrequency> process(List<String> stringList) {
        List<List<String>> wordsList = processData(stringList);
        return calculateWordFrequency(wordsList);
    }
}
