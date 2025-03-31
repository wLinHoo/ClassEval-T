package to_be_tested;

import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class RegexUtils {

    public String[] findall(String pattern, String text) {
        Pattern p = Pattern.compile(pattern);
        Matcher m = p.matcher(text);
        String[] matches = new String[m.groupCount() + 1];
        for (int i = 0; i <= m.groupCount(); i++) {
            matches[i] = m.group(i);
        }
        return matches;
    }

    public String generateEmailPattern() {
        return "\\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Z|a-z]{2,}\\b";
    }

    public String[] extractEmail(String text) {
        String pattern = generateEmailPattern();
        return findall(pattern, text);
    }

    public String sub(String pattern, String replacement, String text) {
        Pattern p = Pattern.compile(pattern);
        Matcher m = p.matcher(text);
        return m.replaceAll(replacement);
    }

    public boolean match(String pattern, String text) {
        Pattern regex = Pattern.compile(pattern);
        Matcher matcher = regex.matcher(text);
        return matcher.find();
    }

    public String[] split(String pattern, String text) {
        Pattern regex = Pattern.compile(pattern);
        return regex.split(text);
    }

    public String generatePhoneNumberPattern() {
        return "\\b\\d{3}-\\d{3}-\\d{4}\\b";
    }

    public String generateSplitSentencesPattern() {
        return "[.!?][\\s]{1,2}(?=[A-Z])";
    }

    public String[] splitSentences(String text) {
        String pattern = generateSplitSentencesPattern();
        return split(pattern, text);
    }

    public boolean validatePhoneNumber(String phone_number) {
        String pattern = generatePhoneNumberPattern();
        return match(pattern, phone_number);
    }
}
