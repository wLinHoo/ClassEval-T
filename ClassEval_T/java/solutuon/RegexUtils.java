package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

public class RegexUtils {

    public boolean match(String pattern, String text) {
        Pattern compiledPattern = Pattern.compile(pattern);
        return compiledPattern.matcher(text).matches();
    }

    public List<String> findall(String pattern, String text) {
        List<String> matches = new ArrayList<>();
        Pattern compiledPattern = Pattern.compile(pattern);
        var matcher = compiledPattern.matcher(text);
        while (matcher.find()) {
            matches.add(matcher.group());
        }
        return matches;
    }

    public List<String> split(String pattern, String text) {
        Pattern compiledPattern = Pattern.compile(pattern);
        String[] splitArray = compiledPattern.split(text, -1);
        List<String> splits = new ArrayList<>();
        for (String s : splitArray) {
            splits.add(s);
        }
        return splits;
    }

    public String sub(String pattern, String replacement, String text) {
        Pattern compiledPattern = Pattern.compile(pattern);
        return compiledPattern.matcher(text).replaceAll(replacement);
    }

    public String generateEmailPattern() {
        return "\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b";
    }

    public String generatePhoneNumberPattern() {
        return "\\b\\d{3}-\\d{3}-\\d{4}\\b";
    }

    public String generateSplitSentencesPattern() {
        return "[.!?][\\s]{1,2}(?=[A-Z])";
    }

    public List<String> splitSentences(String text) {
        String pattern = generateSplitSentencesPattern();
        return split(pattern, text);
    }

    public boolean validatePhoneNumber(String phoneNumber) {
        String pattern = generatePhoneNumberPattern();
        return match(pattern, phoneNumber);
    }

    public List<String> extractEmail(String text) {
        String pattern = generateEmailPattern();
        return findall(pattern, text);
    }
}
