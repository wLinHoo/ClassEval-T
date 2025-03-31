#include <gtest/gtest.h>
#include "pch.h"  

class MusicPlayerTest : public ::testing::Test {
protected:
    MusicPlayer musicPlayer;

    void SetUp() override {
        musicPlayer.playlist = { "song1", "song2" };
        musicPlayer.current_song = "song1";
    }
};

TEST_F(MusicPlayerTest, PlayTest) {
    EXPECT_EQ(musicPlayer.play(), "song1");
    EXPECT_TRUE(musicPlayer.stop());
    musicPlayer.playlist = { "song1", "song2" };
    musicPlayer.current_song = "song1";
    EXPECT_TRUE(musicPlayer.switch_song());
    EXPECT_TRUE(musicPlayer.previous_song());
    musicPlayer.set_volume(50);
    EXPECT_EQ(musicPlayer.volume, 50);
}

class MusicPlayerTestAddSong : public ::testing::Test {
protected:
    MusicPlayer musicPlayer;

    void SetUp() override {
        musicPlayer = MusicPlayer();
    }
};

TEST_F(MusicPlayerTestAddSong, TestAddSong1) {
    musicPlayer.add_song("song1");
    EXPECT_EQ(musicPlayer.playlist, std::vector<std::string>{"song1"});
}

TEST_F(MusicPlayerTestAddSong, TestAddSong2) {
    musicPlayer.add_song("song1");
    musicPlayer.add_song("song2");
    EXPECT_EQ(musicPlayer.playlist, (std::vector<std::string>{"song1", "song2"}));
}

TEST_F(MusicPlayerTestAddSong, TestAddSong3) {
    musicPlayer.add_song("song1");
    musicPlayer.add_song("song2");
    musicPlayer.add_song("song3");
    EXPECT_EQ(musicPlayer.playlist, (std::vector<std::string>{"song1", "song2", "song3"}));
}

TEST_F(MusicPlayerTestAddSong, TestAddSong4) {
    musicPlayer.add_song("song1");
    musicPlayer.add_song("song2");
    musicPlayer.add_song("song3");
    musicPlayer.add_song("song4");
    EXPECT_EQ(musicPlayer.playlist, (std::vector<std::string>{"song1", "song2", "song3", "song4"}));
}

TEST_F(MusicPlayerTestAddSong, TestAddSong5) {
    musicPlayer.add_song("song1");
    musicPlayer.add_song("song2");
    musicPlayer.add_song("song3");
    musicPlayer.add_song("song4");
    musicPlayer.add_song("song5");
    EXPECT_EQ(musicPlayer.playlist, (std::vector<std::string>{"song1", "song2", "song3", "song4", "song5"}));
}

class MusicPlayerTestRemoveSong : public ::testing::Test {
protected:
    MusicPlayer musicPlayer;

    void SetUp() override {
    }
};

TEST_F(MusicPlayerTestRemoveSong, TestRemoveSong) {
    musicPlayer.playlist = { "song1", "song2" };
    musicPlayer.remove_song("song1");
    EXPECT_EQ(musicPlayer.playlist, (std::vector<std::string>{"song2"}));
}

TEST_F(MusicPlayerTestRemoveSong, TestRemoveSong2) {
    musicPlayer.current_song = "song1";
    musicPlayer.playlist = { "song1", "song2", "song3" };
    musicPlayer.remove_song("song1");
    EXPECT_EQ(musicPlayer.playlist, (std::vector<std::string>{"song2", "song3"}));
}

TEST_F(MusicPlayerTestRemoveSong, TestRemoveSong3) {
    musicPlayer.current_song = "song1";
    musicPlayer.playlist = { "song1", "song2", "song3", "song4" };
    musicPlayer.remove_song("song1");
    EXPECT_EQ(musicPlayer.playlist, (std::vector<std::string>{"song2", "song3", "song4"}));
}

TEST_F(MusicPlayerTestRemoveSong, TestRemoveSong4) {
    musicPlayer.playlist = { "song1", "song2", "song3", "song4", "song5" };
    musicPlayer.remove_song("song1");
    EXPECT_EQ(musicPlayer.playlist, (std::vector<std::string>{"song2", "song3", "song4", "song5"}));
}

TEST_F(MusicPlayerTestRemoveSong, TestRemoveSong5) {
    musicPlayer.playlist = { "song1", "song2", "song3", "song4", "song5" };
    musicPlayer.remove_song("song1");
    musicPlayer.remove_song("song2");
    EXPECT_EQ(musicPlayer.playlist, (std::vector<std::string>{"song3", "song4", "song5"}));
}

TEST_F(MusicPlayerTestRemoveSong, TestRemoveSong6) {
    musicPlayer.playlist = {};
    musicPlayer.remove_song("song1");
    EXPECT_EQ(musicPlayer.playlist, (std::vector<std::string>{}));
}

class MusicPlayerTestPlay : public ::testing::Test {
protected:
    MusicPlayer musicPlayer;
};

TEST_F(MusicPlayerTestPlay, TestPlay) {
    musicPlayer.playlist = { "song1", "song2" };
    musicPlayer.current_song = "song1";
    EXPECT_EQ(musicPlayer.play(), "song1");
}

TEST_F(MusicPlayerTestPlay, TestPlay2) {
    musicPlayer.playlist = {};
    musicPlayer.current_song = "song2";
    EXPECT_EQ(musicPlayer.play(), "");
}

TEST_F(MusicPlayerTestPlay, TestPlay3) {
    musicPlayer.playlist = { "song1", "song2" };
    EXPECT_EQ(musicPlayer.play(), "song1");
}

TEST_F(MusicPlayerTestPlay, TestPlay4) {
    musicPlayer.playlist = { "song1", "song2" };
    musicPlayer.current_song = "song3";
    EXPECT_EQ(musicPlayer.play(), "song1");
}

TEST_F(MusicPlayerTestPlay, TestPlay5) {
    musicPlayer.playlist = { "song1", "song2" };
    musicPlayer.current_song = "song1";
    EXPECT_EQ(musicPlayer.play(), "song1");
}

class MusicPlayerTestStop : public ::testing::Test {
protected:
    MusicPlayer musicPlayer;
};

TEST_F(MusicPlayerTestStop, TestStop) {
    musicPlayer.playlist = {"song1", "song2"};
    musicPlayer.current_song = "song1";
    EXPECT_EQ(musicPlayer.stop(), true);
}

TEST_F(MusicPlayerTestStop, TestStop2) {
    musicPlayer.playlist = {};
    musicPlayer.current_song = "song1";
    EXPECT_EQ(musicPlayer.stop(), true);
}

TEST_F(MusicPlayerTestStop, TestStop3) {
    musicPlayer.playlist = {"song1", "song2"};
    EXPECT_EQ(musicPlayer.stop(), false);
}

TEST_F(MusicPlayerTestStop, TestStop4) {
    musicPlayer.playlist = {"song1", "song2"};
    musicPlayer.current_song = "song1";
    EXPECT_EQ(musicPlayer.stop(), true);
}

TEST_F(MusicPlayerTestStop, TestStop5) {
    musicPlayer.playlist = {"song1", "song2"};
    musicPlayer.current_song = "song2";
    EXPECT_EQ(musicPlayer.stop(), true);
}

class MusicPlayerTestSwitchSong : public ::testing::Test {
protected:
    MusicPlayer musicPlayer;
};

TEST_F(MusicPlayerTestSwitchSong, TestSwitchSong) {
    musicPlayer.playlist = { "song1", "song2" };
    musicPlayer.current_song = "song1";
    EXPECT_EQ(musicPlayer.switch_song(), true);
}

TEST_F(MusicPlayerTestSwitchSong, TestSwitchSong2) {
    musicPlayer.playlist = { "song1", "song2" };
    musicPlayer.current_song = "song2";
    EXPECT_EQ(musicPlayer.switch_song(), false);
}

TEST_F(MusicPlayerTestSwitchSong, TestSwitchSong3) {
    musicPlayer.playlist = { "song1", "song2", "song3" };
    musicPlayer.current_song = "song3";
    EXPECT_EQ(musicPlayer.switch_song(), false);
}

TEST_F(MusicPlayerTestSwitchSong, TestSwitchSong4) {
    musicPlayer.playlist = { "song1", "song2" };
    EXPECT_EQ(musicPlayer.switch_song(), false);
}

TEST_F(MusicPlayerTestSwitchSong, TestSwitchSong5) {
    musicPlayer.playlist = {};
    EXPECT_EQ(musicPlayer.switch_song(), false);
}

class MusicPlayerTestPreviousSong : public ::testing::Test {
protected:
    MusicPlayer musicPlayer;
};

TEST_F(MusicPlayerTestPreviousSong, TestPreviousSong) {
    musicPlayer.playlist = { "song1", "song2", "song3" };
    musicPlayer.current_song = "song2";
    EXPECT_EQ(musicPlayer.previous_song(), true);
}

TEST_F(MusicPlayerTestPreviousSong, TestPreviousSong2) {
    musicPlayer.playlist = { "song1", "song2", "song3" };
    musicPlayer.current_song = "song1";
    EXPECT_EQ(musicPlayer.previous_song(), false);
}

TEST_F(MusicPlayerTestPreviousSong, TestPreviousSong3) {
    musicPlayer.playlist = { "song1", "song2", "song3" };
    musicPlayer.current_song = "song3";
    EXPECT_EQ(musicPlayer.previous_song(), true);
}

TEST_F(MusicPlayerTestPreviousSong, TestPreviousSong4) {
    musicPlayer.playlist = { "song1", "song2", "song3" };
    EXPECT_EQ(musicPlayer.previous_song(), false);
}

TEST_F(MusicPlayerTestPreviousSong, TestPreviousSong5) {
    musicPlayer.playlist = {};
    EXPECT_EQ(musicPlayer.previous_song(), false);
}

class MusicPlayerTestSetVolume : public ::testing::Test {
protected:
    MusicPlayer musicPlayer;
};

TEST_F(MusicPlayerTestSetVolume, TestSetVolume) {
    EXPECT_EQ(musicPlayer.set_volume(50), true);
    EXPECT_EQ(musicPlayer.volume, 50);
}

TEST_F(MusicPlayerTestSetVolume, TestSetVolume2) {
    EXPECT_EQ(musicPlayer.set_volume(100), true);
    EXPECT_EQ(musicPlayer.volume, 100);
}

TEST_F(MusicPlayerTestSetVolume, TestSetVolume3) {
    EXPECT_EQ(musicPlayer.set_volume(0), true);
    EXPECT_EQ(musicPlayer.volume, 0);
}

TEST_F(MusicPlayerTestSetVolume, TestSetVolume4) {
    EXPECT_EQ(musicPlayer.set_volume(101), false);
    EXPECT_EQ(musicPlayer.volume, 50);
}

TEST_F(MusicPlayerTestSetVolume, TestSetVolume5) {
    EXPECT_EQ(musicPlayer.set_volume(-1), false);
    EXPECT_EQ(musicPlayer.volume, 50);
}

class MusicPlayerTestShuffle : public ::testing::Test {
protected:
    MusicPlayer musicPlayer;
};

TEST_F(MusicPlayerTestShuffle, TestShuffle) {
    musicPlayer.playlist = { "song1", "song2" };
    EXPECT_EQ(musicPlayer.shuffle(), true);
}

TEST_F(MusicPlayerTestShuffle, TestShuffle2) {
    musicPlayer.playlist = {};
    musicPlayer.current_song = "song1";
    EXPECT_EQ(musicPlayer.shuffle(), false);
}

TEST_F(MusicPlayerTestShuffle, TestShuffle3) {
    musicPlayer.playlist = { "song1", "song2" };
    musicPlayer.current_song = "song2";
    EXPECT_EQ(musicPlayer.shuffle(), true);
}

TEST_F(MusicPlayerTestShuffle, TestShuffle4) {
    musicPlayer.playlist = { "song1", "song2" };
    musicPlayer.current_song = "song3";
    EXPECT_EQ(musicPlayer.shuffle(), true);
}

TEST_F(MusicPlayerTestShuffle, TestShuffle5) {
    musicPlayer.playlist = { "song1", "song2" };
    musicPlayer.current_song = "song1";
    EXPECT_EQ(musicPlayer.shuffle(), true);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
