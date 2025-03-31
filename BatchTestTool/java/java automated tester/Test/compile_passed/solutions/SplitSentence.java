import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class SplitSentence {

    public String[] splitSentences(String sentencesString) {
        String regex = "(?<!\\w\\.\\w.)(?<![A-Z][a-z]\\.)[.!?]+\\s";
        String[] sentences = sentencesString.split(regex);
        return sentences;
    }

    public int countWords(String sentence) {
        String regex = "[^a-zA-Z\\s]";
        sentence = sentence.replaceAll(regex, "");
        String[] words = sentence.split("\\s+");
        return words.length;
    }

    public int processTextFile(String sentencesString) {
        String[] sentences = splitSentences(sentencesString);
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