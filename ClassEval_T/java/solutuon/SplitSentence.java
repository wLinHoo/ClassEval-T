package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SplitSentence {

    public List<String> splitSentences(String sentencesString) {
        List<String> sentences = new ArrayList<>();
        Pattern pattern = Pattern.compile("(?<!\\w\\.\\w.)(?<![A-Z][a-z]\\.)(?<=\\.|\\?)\\s");
        Matcher matcher = pattern.matcher(sentencesString);
        int lastEnd = 0;
        while (matcher.find()) {
            sentences.add(sentencesString.substring(lastEnd, matcher.end() - 1));
            lastEnd = matcher.end();
        }
        if (lastEnd < sentencesString.length()) {
            sentences.add(sentencesString.substring(lastEnd));
        }
        return sentences;
    }

    public int countWords(String sentence) {
        String cleanedSentence = sentence.replaceAll("[^a-zA-Z\\s]", "");
        String[] words = cleanedSentence.split("\\s+");
        return words.length;
    }

    public int processTextFile(String sentencesString) {
        List<String> sentences = splitSentences(sentencesString);
        int maxCount = 0;
        for (String sentence : sentences) {
            int count = countWords(sentence);
            if (count > maxCount) {
                maxCount = count;
            }
        }
        return maxCount;
    }
}