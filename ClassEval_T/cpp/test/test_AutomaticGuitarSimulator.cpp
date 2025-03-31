#include "pch.h"
#include <gtest/gtest.h>

class AutomaticGuitarSimulatorTestInterpret : public ::testing::Test {};

TEST_F(AutomaticGuitarSimulatorTestInterpret, test_interpret_1) {
    AutomaticGuitarSimulator context("C53231323");
    auto play_list = context.interpret();
    ASSERT_EQ(play_list.size(), 1);
    EXPECT_EQ(play_list[0].Chord, "C");
    EXPECT_EQ(play_list[0].Tune, "53231323");
}

TEST_F(AutomaticGuitarSimulatorTestInterpret, test_interpret_2) {
    AutomaticGuitarSimulator context("F43231323");
    auto play_list = context.interpret();
    ASSERT_EQ(play_list.size(), 1);
    EXPECT_EQ(play_list[0].Chord, "F");
    EXPECT_EQ(play_list[0].Tune, "43231323");
}

TEST_F(AutomaticGuitarSimulatorTestInterpret, test_interpret_3) {
    AutomaticGuitarSimulator context("Em43231323");
    auto play_list = context.interpret();
    ASSERT_EQ(play_list.size(), 1);
    EXPECT_EQ(play_list[0].Chord, "Em");
    EXPECT_EQ(play_list[0].Tune, "43231323");
}

TEST_F(AutomaticGuitarSimulatorTestInterpret, test_interpret_4) {
    AutomaticGuitarSimulator context("G63231323");
    auto play_list = context.interpret();
    ASSERT_EQ(play_list.size(), 1);
    EXPECT_EQ(play_list[0].Chord, "G");
    EXPECT_EQ(play_list[0].Tune, "63231323");
}

TEST_F(AutomaticGuitarSimulatorTestInterpret, test_interpret_5) {
    AutomaticGuitarSimulator context("F43231323 G63231323");
    auto play_list = context.interpret();
    ASSERT_EQ(play_list.size(), 2);
    EXPECT_EQ(play_list[0].Chord, "F");
    EXPECT_EQ(play_list[0].Tune, "43231323");
    EXPECT_EQ(play_list[1].Chord, "G");
    EXPECT_EQ(play_list[1].Tune, "63231323");
}

TEST_F(AutomaticGuitarSimulatorTestInterpret, test_interpret_6) {
    AutomaticGuitarSimulator context(" ");
    auto play_list = context.interpret();
    EXPECT_TRUE(play_list.empty());
}

TEST_F(AutomaticGuitarSimulatorTestInterpret, test_interpret_7) {
    AutomaticGuitarSimulator context("ABC43231323 DEF63231323");
    auto play_list = context.interpret();
    ASSERT_EQ(play_list.size(), 2);
    EXPECT_EQ(play_list[0].Chord, "ABC");
    EXPECT_EQ(play_list[0].Tune, "43231323");
    EXPECT_EQ(play_list[1].Chord, "DEF");
    EXPECT_EQ(play_list[1].Tune, "63231323");
}

TEST_F(AutomaticGuitarSimulatorTestInterpret, test_interpret_8) {
    AutomaticGuitarSimulator context("C53231323");
    auto play_list = context.interpret(true);
    ASSERT_EQ(play_list.size(), 1);
    EXPECT_EQ(play_list[0].Chord, "C");
    EXPECT_EQ(play_list[0].Tune, "53231323");
}

TEST_F(AutomaticGuitarSimulatorTestInterpret, test_interpret_9) {
    AutomaticGuitarSimulator context("");
    auto play_list = context.interpret();
    EXPECT_TRUE(play_list.empty());
}

class AutomaticGuitarSimulatorTestDisplay : public ::testing::Test {};

TEST_F(AutomaticGuitarSimulatorTestDisplay, test_display_1) {
    AutomaticGuitarSimulator context("C53231323 Em43231323");
    auto play_list = context.interpret();
    std::string str = context.format_display(play_list[0].Chord, play_list[0].Tune);
    EXPECT_EQ(str, "Normal Guitar Playing -- Chord: C, Play Tune: 53231323");
}

TEST_F(AutomaticGuitarSimulatorTestDisplay, test_display_2) {
    AutomaticGuitarSimulator context("C53231323 Em43231323");
    auto play_list = context.interpret();
    std::string str = context.format_display(play_list[1].Chord, play_list[1].Tune);
    EXPECT_EQ(str, "Normal Guitar Playing -- Chord: Em, Play Tune: 43231323");
}

TEST_F(AutomaticGuitarSimulatorTestDisplay, test_display_3) {
    AutomaticGuitarSimulator context("F43231323 G63231323");
    auto play_list = context.interpret();
    std::string str = context.format_display(play_list[0].Chord, play_list[0].Tune);
    EXPECT_EQ(str, "Normal Guitar Playing -- Chord: F, Play Tune: 43231323");
}

TEST_F(AutomaticGuitarSimulatorTestDisplay, test_display_4) {
    AutomaticGuitarSimulator context("F43231323 G63231323");
    auto play_list = context.interpret();
    std::string str = context.format_display(play_list[1].Chord, play_list[1].Tune);
    EXPECT_EQ(str, "Normal Guitar Playing -- Chord: G, Play Tune: 63231323");
}

TEST_F(AutomaticGuitarSimulatorTestDisplay, test_display_5) {
    AutomaticGuitarSimulator context("");
    std::string str = context.format_display("", "");
    EXPECT_EQ(str, "Normal Guitar Playing -- Chord: , Play Tune: ");
}

class AutomaticGuitarSimulatorTest : public ::testing::Test {};

TEST_F(AutomaticGuitarSimulatorTest, test_AutomaticGuitarSimulator) {
    AutomaticGuitarSimulator context("C53231323");
    auto play_list = context.interpret();
    ASSERT_EQ(play_list.size(), 1);
    EXPECT_EQ(play_list[0].Chord, "C");
    EXPECT_EQ(play_list[0].Tune, "53231323");

    context = AutomaticGuitarSimulator("C53231323 Em43231323");
    play_list = context.interpret();
    std::string str = context.format_display(play_list[0].Chord, play_list[0].Tune);
    EXPECT_EQ(str, "Normal Guitar Playing -- Chord: C, Play Tune: 53231323");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
