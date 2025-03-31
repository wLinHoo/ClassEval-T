import java.util.regex.Pattern;
import java.util.regex.Matcher;
import java.util.ArrayList;
import java.util.List;

public class LongestWord {
    private String[] word_list;
    private List<String> wordList;

    public LongestWord() {
        this.word_list = new String[0];
        wordList = new ArrayList<>();
    }

    public String findLongestWord(String sentence) {
        String longestWord = "";
        sentence = sentence.toLowerCase();
        sentence = sentence.replaceAll("[^a-z0-9 ]", "");
        String[] words = sentence.split(" ");
        for (String word : words) {
            if (word.length() > longestWord.length()) {
                longestWord = word;
            }
        }
        return longestWord;
    }

    public void addWord(String word) {
        wordList.add(word);
    }

    public List<String> getWordList() {
        return wordList;
    }
}