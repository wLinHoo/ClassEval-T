import java.util.ArrayList;
import java.util.List;

public class NLPDataProcessor {

    public List<String> constructStopWordList() {
        List<String> stopWordList = new ArrayList<>();
        stopWordList.add("a");
        stopWordList.add("an");
        stopWordList.add("the");
        return stopWordList;
    }

    public List<List<String>> removeStopWords(List<List<String>> stringList, List<String> stopWordList) {
        List<List<String>> answer = new ArrayList<>();
        for (List<String> string : stringList) {
            List<String> stringSplit = new ArrayList<>(string);
            for (String word : stringSplit) {
                if (stopWordList.contains(word)) {
                    stringSplit.remove(word);
                }
            }
            answer.add(stringSplit);
        }
        return answer;
    }

    public List<List<String>> process(List<List<String>> stringList) {
        List<String> stopWordList = constructStopWordList();
        List<List<String>> wordsList = removeStopWords(stringList, stopWordList);
        return wordsList;
    }
}