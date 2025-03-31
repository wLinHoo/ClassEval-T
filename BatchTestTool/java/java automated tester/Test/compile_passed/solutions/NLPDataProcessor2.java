import java.util.*;

public class NLPDataProcessor2 {

    public Map<String, Integer> process(String[] stringList) {
        List<List<String>> wordsList = new ArrayList<>();
        for (String string : stringList) {
            String processedString = string.toLowerCase();
            processedString = processedString.replaceAll("[^a-zA-Z\\s]", "");
            List<String> words = Arrays.asList(processedString.split("\\s+"));
            wordsList.add(words);
        }

        Map<String, Integer> wordFrequency = new HashMap<>();
        for (List<String> words : wordsList) {
            for (String word : words) {
                wordFrequency.put(word, wordFrequency.getOrDefault(word, 0) + 1);
            }
        }

        List<Map.Entry<String, Integer>> sortedList = new ArrayList<>(wordFrequency.entrySet());
        Collections.sort(sortedList, (o1, o2) -> o2.getValue().compareTo(o1.getValue()));
        Map<String, Integer> top5WordFrequency = new LinkedHashMap<>();
        for (int i = 0; i < 5 && i < sortedList.size(); i++) {
            top5WordFrequency.put(sortedList.get(i).getKey(), sortedList.get(i).getValue());
        }

        return top5WordFrequency;
    }
}