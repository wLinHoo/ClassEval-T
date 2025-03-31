package org.example;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.*;

public class MusicPlayerTest {

    @Test
    public void testAddSong() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.addSong("song1");
        assertEquals(List.of("song1"), musicPlayer.getPlaylist());
    }

    @Test
    public void testAddSong2() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.addSong("song1");
        musicPlayer.addSong("song2");
        assertEquals(List.of("song1", "song2"), musicPlayer.getPlaylist());
    }

    @Test
    public void testAddSong3() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.addSong("song1");
        musicPlayer.addSong("song2");
        musicPlayer.addSong("song3");
        assertEquals(List.of("song1", "song2", "song3"), musicPlayer.getPlaylist());
    }

    @Test
    public void testAddSong4() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.addSong("song1");
        musicPlayer.addSong("song2");
        musicPlayer.addSong("song3");
        musicPlayer.addSong("song4");
        assertEquals(List.of("song1", "song2", "song3", "song4"), musicPlayer.getPlaylist());
    }

    @Test
    public void testAddSong5() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.addSong("song1");
        musicPlayer.addSong("song2");
        musicPlayer.addSong("song3");
        musicPlayer.addSong("song4");
        musicPlayer.addSong("song5");
        assertEquals(List.of("song1", "song2", "song3", "song4", "song5"), musicPlayer.getPlaylist());
    }

    @Test
    public void testRemoveSong() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.removeSong("song1");
        assertEquals(List.of("song2"), musicPlayer.getPlaylist());
    }

    @Test
    public void testRemoveSong2() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setCurrentSong("song1");
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2", "song3")));
        musicPlayer.removeSong("song1");
        assertEquals(List.of("song2", "song3"), musicPlayer.getPlaylist());
    }

    @Test
    public void testRemoveSong3() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setCurrentSong("song1");
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2", "song3", "song4")));
        musicPlayer.removeSong("song1");
        assertEquals(List.of("song2", "song3", "song4"), musicPlayer.getPlaylist());
    }

    @Test
    public void testRemoveSong4() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2", "song3", "song4", "song5")));
        musicPlayer.removeSong("song1");
        assertEquals(List.of("song2", "song3", "song4", "song5"), musicPlayer.getPlaylist());
    }

    @Test
    public void testRemoveSong5() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2", "song3", "song4", "song5")));
        musicPlayer.removeSong("song1");
        musicPlayer.removeSong("song2");
        assertEquals(List.of("song3", "song4", "song5"), musicPlayer.getPlaylist());
    }

    @Test
    public void testRemoveSong6() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>());
        musicPlayer.removeSong("song1");
        assertEquals(List.of(), musicPlayer.getPlaylist());
    }

    @Test
    public void testPlay() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song1");
        assertEquals("song1", musicPlayer.play());
    }

    @Test
    public void testPlay2() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>());
        musicPlayer.setCurrentSong("song2");
        assertNull(musicPlayer.play());
    }

    @Test
    public void testPlay3() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        assertFalse(Boolean.parseBoolean(musicPlayer.play()));
    }

    @Test
    public void testPlay4() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song3");
        assertEquals("song1", musicPlayer.play());
    }

    @Test
    public void testPlay5() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song1");
        assertEquals("song1", musicPlayer.play());
    }

    @Test
    public void testStop() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song1");
        assertTrue(musicPlayer.stop());
    }

    @Test
    public void testStop2() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>());
        musicPlayer.setCurrentSong("song1");
        assertTrue(musicPlayer.stop());
    }

    @Test
    public void testStop3() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        assertFalse(musicPlayer.stop());
    }

    @Test
    public void testStop4() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song1");
        assertTrue(musicPlayer.stop());
    }

    @Test
    public void testStop5() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song2");
        assertTrue(musicPlayer.stop());
    }

    @Test
    public void testSwitchSong() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song1");
        assertTrue(musicPlayer.switchSong());
    }

    @Test
    public void testSwitchSong2() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song2");
        assertFalse(musicPlayer.switchSong());
    }

    @Test
    public void testSwitchSong3() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2", "song3")));
        musicPlayer.setCurrentSong("song3");
        assertFalse(musicPlayer.switchSong());
    }

    @Test
    public void testSwitchSong4() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        assertFalse(musicPlayer.switchSong());
    }

    @Test
    public void testSwitchSong5() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>());
        assertFalse(musicPlayer.switchSong());
    }

    @Test
    public void testPreviousSong() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2", "song3")));
        musicPlayer.setCurrentSong("song2");
        assertTrue(musicPlayer.previousSong());
    }

    @Test
    public void testPreviousSong2() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2", "song3")));
        musicPlayer.setCurrentSong("song1");
        assertFalse(musicPlayer.previousSong());
    }

    @Test
    public void testPreviousSong3() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2", "song3")));
        musicPlayer.setCurrentSong("song3");
        assertTrue(musicPlayer.previousSong());
    }

    @Test
    public void testPreviousSong4() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2", "song3")));
        assertFalse(musicPlayer.previousSong());
    }

    @Test
    public void testPreviousSong5() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>());
        assertFalse(musicPlayer.previousSong());
    }

    @Test
    public void testSetVolume() {
        MusicPlayer musicPlayer = new MusicPlayer();
        assertTrue(musicPlayer.setVolume(50));
        assertEquals(50, musicPlayer.getVolume());
    }

    @Test
    public void testSetVolume2() {
        MusicPlayer musicPlayer = new MusicPlayer();
        assertTrue(musicPlayer.setVolume(100));
        assertEquals(100, musicPlayer.getVolume());
    }

    @Test
    public void testSetVolume3() {
        MusicPlayer musicPlayer = new MusicPlayer();
        assertTrue(musicPlayer.setVolume(0));
        assertEquals(0, musicPlayer.getVolume());
    }

    @Test
    public void testSetVolume4() {
        MusicPlayer musicPlayer = new MusicPlayer();
        assertFalse(musicPlayer.setVolume(101));
        assertEquals(50, musicPlayer.getVolume());
    }

    @Test
    public void testSetVolume5() {
        MusicPlayer musicPlayer = new MusicPlayer();
        assertFalse(musicPlayer.setVolume(-1));
        assertEquals(50, musicPlayer.getVolume());
    }

    @Test
    public void testShuffle() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        assertTrue(musicPlayer.shuffle());
    }

    @Test
    public void testShuffle2() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>());
        musicPlayer.setCurrentSong("song1");
        assertFalse(musicPlayer.shuffle());
    }

    @Test
    public void testShuffle3() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song2");
        assertTrue(musicPlayer.shuffle());
    }

    @Test
    public void testShuffle4() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song3");
        assertTrue(musicPlayer.shuffle());
    }

    @Test
    public void testShuffle5() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song1");
        assertTrue(musicPlayer.shuffle());
    }

    @Test
    public void testMain() {
        MusicPlayer musicPlayer = new MusicPlayer();
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song1");
        assertEquals("song1", musicPlayer.play());
        assertTrue(musicPlayer.stop());
        musicPlayer.setPlaylist(new ArrayList<>(List.of("song1", "song2")));
        musicPlayer.setCurrentSong("song1");
        assertTrue(musicPlayer.switchSong());
        assertTrue(musicPlayer.previousSong());
        musicPlayer.setVolume(50);
        assertEquals(50, musicPlayer.getVolume());
    }
}