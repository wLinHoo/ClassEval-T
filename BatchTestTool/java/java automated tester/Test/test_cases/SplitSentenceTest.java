package test_cases;
import to_be_tested.SplitSentence;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.util.List;

public class SplitSentenceTest {

    @Test
    public void testSplitSentences1() {
        SplitSentence ss = new SplitSentence();
        List<String> lst = ss.splitSentences("aaa aaaa. bb bbbb bbb? cccc cccc. dd ddd?");
        assertEquals(lst, List.of("aaa aaaa.", "bb bbbb bbb?", "cccc cccc.", "dd ddd?"));
    }

    @Test
    public void testSplitSentences2() {
        SplitSentence ss = new SplitSentence();
        List<String> lst = ss.splitSentences("Who is Mr. Smith? He is a teacher.");
        assertEquals(lst, List.of("Who is Mr. Smith?", "He is a teacher."));
    }

    @Test
    public void testSplitSentences3() {
        SplitSentence ss = new SplitSentence();
        List<String> lst = ss.splitSentences("Who is A.B.C.? He is a teacher.");
        assertEquals(lst, List.of("Who is A.B.C.?", "He is a teacher."));
    }

    @Test
    public void testSplitSentences4() {
        SplitSentence ss = new SplitSentence();
        List<String> lst = ss.splitSentences("aaa aaaa. bb bbbb bbb? cccc cccc.");
        assertEquals(lst, List.of("aaa aaaa.", "bb bbbb bbb?", "cccc cccc."));
    }

    @Test
    public void testSplitSentences5() {
        SplitSentence ss = new SplitSentence();
        List<String> lst = ss.splitSentences("aaa aaaa. bb bbbb bbb?");
        assertEquals(lst, List.of("aaa aaaa.", "bb bbbb bbb?"));
    }

    @Test
    public void testCountWords1() {
        SplitSentence ss = new SplitSentence();
        int cnt = ss.countWords("abc def");
        assertEquals(cnt, 2);
    }

    @Test
    public void testCountWords2() {
        SplitSentence ss = new SplitSentence();
        int cnt = ss.countWords("abc def 1");
        assertEquals(cnt, 2);
    }

    @Test
    public void testCountWords3() {
        SplitSentence ss = new SplitSentence();
        int cnt = ss.countWords("abc 1");
        assertEquals(cnt, 1);
    }

    @Test
    public void testCountWords4() {
        SplitSentence ss = new SplitSentence();
        int cnt = ss.countWords("abc def bbb1");
        assertEquals(cnt, 3);
    }

    @Test
    public void testCountWords5() {
        SplitSentence ss = new SplitSentence();
        int cnt = ss.countWords("abc def 111");
        assertEquals(cnt, 2);
    }

    @Test
    public void testProcessTextFile1() {
        SplitSentence ss = new SplitSentence();
        int cnt = ss.processTextFile("aaa aaaa. bb bbbb bbb? cccc ccccccc cc ccc. dd ddd?");
        assertEquals(cnt, 4);
    }

    @Test
    public void testProcessTextFile2() {
        SplitSentence ss = new SplitSentence();
        int cnt = ss.processTextFile("Mr. Smith is a teacher. Yes.");
        assertEquals(cnt, 5);
    }

    @Test
    public void testProcessTextFile3() {
        SplitSentence ss = new SplitSentence();
        int cnt = ss.processTextFile("Mr. Smith is a teacher. Yes 1 2 3 4 5 6.");
        assertEquals(cnt, 5);
    }

    @Test
    public void testProcessTextFile4() {
        SplitSentence ss = new SplitSentence();
        int cnt = ss.processTextFile("aaa aaaa. bb bbbb bbb? cccc ccccccc cc ccc.");
        assertEquals(cnt, 4);
    }

    @Test
    public void testProcessTextFile5() {
        SplitSentence ss = new SplitSentence();
        int cnt = ss.processTextFile("aaa aaaa. bb bbbb bbb?");
        assertEquals(cnt, 3);
    }

    @Test
    public void testSplitSentence() {
        SplitSentence ss = new SplitSentence();
        List<String> lst = ss.splitSentences("aaa aaaa. bb bbbb bbb? cccc cccc. dd ddd?");
        assertEquals(lst, List.of("aaa aaaa.", "bb bbbb bbb?", "cccc cccc.", "dd ddd?"));

        int cnt = ss.countWords("abc def");
        assertEquals(cnt, 2);

        cnt = ss.processTextFile("aaa aaaa. bb bbbb bbb? cccc ccccccc cc ccc. dd ddd?");
        assertEquals(cnt, 4);
    }
}