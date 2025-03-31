package test_cases;
import to_be_tested.BoyerMooreSearch;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

class BoyerMooreSearchTestMatchInPattern {

    @Test
    void testMatchInPattern() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "AB");
        assertEquals(0, boyerMooreSearch.matchInPattern('A'));
    }

    @Test
    void testMatchInPattern2() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "ABAB");
        assertEquals(3, boyerMooreSearch.matchInPattern('B'));
    }

    @Test
    void testMatchInPattern3() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "ABCABC");
        assertEquals(5, boyerMooreSearch.matchInPattern('C'));
    }

    @Test
    void testMatchInPattern4() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "ABCABC");
        assertEquals(-1, boyerMooreSearch.matchInPattern('D'));
    }

    @Test
    void testMatchInPattern5() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "ABCABC");
        assertEquals(-1, boyerMooreSearch.matchInPattern('E'));
    }
}

class BoyerMooreSearchTestMismatchInText {

    @Test
    void testMismatchInText() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "AB");
        assertEquals(-1, boyerMooreSearch.mismatchInText(0));
    }

    @Test
    void testMismatchInText2() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "ABC");
        assertEquals(2, boyerMooreSearch.mismatchInText(0));
    }

    @Test
    void testMismatchInText3() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("AAAA", "ABC");
        assertEquals(2, boyerMooreSearch.mismatchInText(0));
    }

    @Test
    void testMismatchInText4() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "");
        assertEquals(-1, boyerMooreSearch.mismatchInText(0));
    }

    @Test
    void testMismatchInText5() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "ABC");
        assertEquals(5, boyerMooreSearch.mismatchInText(3));
    }
}

class BoyerMooreSearchTestBadCharacterHeuristic {

    @Test
    void testBadCharacterHeuristic() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "AB");
        assertEquals(List.of(0, 3), boyerMooreSearch.badCharacterHeuristic());
    }

    @Test
    void testBadCharacterHeuristic2() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "ABC");
        assertEquals(List.of(), boyerMooreSearch.badCharacterHeuristic());
    }

    @Test
    void testBadCharacterHeuristic3() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "");
        assertEquals(List.of(0, 1, 2, 3, 4, 5, 6), boyerMooreSearch.badCharacterHeuristic());
    }

    @Test
    void testBadCharacterHeuristic4() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABACABA", "AB");
        assertEquals(List.of(0, 4), boyerMooreSearch.badCharacterHeuristic());
    }

    @Test
    void testBadCharacterHeuristic5() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABACABA", "ABAC");
        assertEquals(List.of(0), boyerMooreSearch.badCharacterHeuristic());
    }
}

class BoyerMooreSearchTestMain {

    @Test
    void testMain() {
        BoyerMooreSearch boyerMooreSearch = new BoyerMooreSearch("ABAABA", "AB");
        assertEquals(0, boyerMooreSearch.matchInPattern('A'));
        assertEquals(-1, boyerMooreSearch.mismatchInText(0));
        assertEquals(List.of(0, 3), boyerMooreSearch.badCharacterHeuristic());
    }
}
