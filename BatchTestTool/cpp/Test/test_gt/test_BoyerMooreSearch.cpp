#include <gtest/gtest.h>
#include "pch.h"

class BoyerMooreSearchTestMatchInPattern : public ::testing::Test {
protected:
    void SetUp() override {
        
    }
};

TEST_F(BoyerMooreSearchTestMatchInPattern, TestMatchInPattern) {
    BoyerMooreSearch bms("ABAABA", "AB");
    EXPECT_EQ(bms.match_in_pattern('A'), 0);

    bms = BoyerMooreSearch("ABAABA", "ABAB");
    EXPECT_EQ(bms.match_in_pattern('B'), 3);

    bms = BoyerMooreSearch("ABAABA", "ABCABC");
    EXPECT_EQ(bms.match_in_pattern('C'), 5);

    bms = BoyerMooreSearch("ABAABA", "ABCABC");
    EXPECT_EQ(bms.match_in_pattern('D'), -1);

    bms = BoyerMooreSearch("ABAABA", "ABCABC");
    EXPECT_EQ(bms.match_in_pattern('E'), -1);
}

class BoyerMooreSearchTestMismatchInText : public ::testing::Test {
protected:
    void SetUp() override {
        
    }
};

TEST_F(BoyerMooreSearchTestMismatchInText, TestMismatchInText) {
    BoyerMooreSearch bms("ABAABA", "AB");
    EXPECT_EQ(bms.mismatch_in_text(0), -1);

    bms = BoyerMooreSearch("ABAABA", "ABC");
    EXPECT_EQ(bms.mismatch_in_text(0), 2);

    bms = BoyerMooreSearch("AAAA", "ABC");
    EXPECT_EQ(bms.mismatch_in_text(0), 2);

    bms = BoyerMooreSearch("ABAABA", "");
    EXPECT_EQ(bms.mismatch_in_text(0), -1);

    bms = BoyerMooreSearch("ABAABA", "ABC");
    EXPECT_EQ(bms.mismatch_in_text(3), 5);
}

class BoyerMooreSearchTestTestBadCharacterHeuristic : public ::testing::Test {
protected:
    void SetUp() override {
        
    }
};

TEST_F(BoyerMooreSearchTestTestBadCharacterHeuristic, TestBadCharacterHeuristic) {
    BoyerMooreSearch bms("ABAABA", "AB");
    EXPECT_EQ(bms.bad_character_heuristic(), (std::vector<int>{0, 3}));

    bms = BoyerMooreSearch("ABAABA", "ABC");
    EXPECT_EQ(bms.bad_character_heuristic(), std::vector<int>{});

    bms = BoyerMooreSearch("ABAABA", "");
    EXPECT_EQ(bms.bad_character_heuristic(), (std::vector<int>{0, 1, 2, 3, 4, 5, 6}));

    bms = BoyerMooreSearch("ABACABA", "ABA");
    EXPECT_EQ(bms.bad_character_heuristic(), (std::vector<int>{0, 4}));

    bms = BoyerMooreSearch("ABACABA", "ABAC");
    EXPECT_EQ(bms.bad_character_heuristic(), (std::vector<int>{0}));
}

class BoyerMooreSearchTestMain : public ::testing::Test {
protected:
    void SetUp() override {
        
    }
};

TEST_F(BoyerMooreSearchTestMain, TestMain) {
    BoyerMooreSearch bms("ABAABA", "AB");
    EXPECT_EQ(bms.match_in_pattern('A'), 0);
    EXPECT_EQ(bms.mismatch_in_text(0), -1);
    EXPECT_EQ(bms.bad_character_heuristic(), (std::vector<int>{0, 3}));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
