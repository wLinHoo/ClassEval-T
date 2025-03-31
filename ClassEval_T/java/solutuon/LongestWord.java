package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

public class LongestWord {
    List<String> wordList;

    public LongestWord() {
        wordList = new ArrayList<>();
    }

    public void addWord(String word) {
        wordList.add(word);
    }

    public String findLongestWord(String sentence) {
        String longestWord = "";
        sentence = sentence.toLowerCase();
        sentence = sentence.replaceAll("[" + Pattern.quote("!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~") + "]", "");
        String[] words = sentence.split(" ");
        for (String word : words) {
            if (wordList.contains(word) && word.length() > longestWord.length()) {
                longestWord = word;
            }
        }
        return longestWord;
    }

    public static void main(String[] args) {
        LongestWord longestWord = new LongestWord();
        longestWord.addWord("A");
        longestWord.addWord("aM");
        System.out.println(longestWord.findLongestWord("I am a student."));
    }
}