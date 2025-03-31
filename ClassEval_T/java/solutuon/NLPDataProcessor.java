package org.example;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class NLPDataProcessor {

    public List<String> constructStopWordList() {
        return Arrays.asList("a", "an", "the");
    }

    public List<List<String>> removeStopWords(List<String> stringList, List<String> stopWordList) {
        List<List<String>> result = new ArrayList<>();
        for (String string : stringList) {
            List<String> words = new ArrayList<>(Arrays.asList(string.split(" ")));
            words.removeAll(stopWordList);
            result.add(words);
        }
        return result;
    }

    public List<List<String>> process(List<String> stringList) {
        List<String> stopWordList = constructStopWordList();
        return removeStopWords(stringList, stopWordList);
    }
}