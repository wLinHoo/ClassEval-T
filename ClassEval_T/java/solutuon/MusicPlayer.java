package org.example;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class MusicPlayer {
    private List<String> playlist;
    private String currentSong;
    private int volume;

    public MusicPlayer() {
        this.playlist = new ArrayList<>();
        this.currentSong = null;
        this.volume = 50;
    }

    public void addSong(String song) {
        playlist.add(song);
    }

    public void removeSong(String song) {
        if (playlist.contains(song)) {
            playlist.remove(song);
            if (currentSong != null && currentSong.equals(song)) {
                stop();
            }
        }
    }

    public String play() {
        if (playlist.isEmpty()) {
            return null;
        }
        if (currentSong != null) {
            for (String song : playlist) {
                if (song.equals(currentSong)) {
                    return currentSong;
                }
            }
        }
        return playlist.get(0);
    }

    public boolean stop() {
        if (currentSong != null) {
            currentSong = null;
            return true;
        } else {
            return false;
        }
    }

    public boolean switchSong() {
        if (currentSong == null) {
            return false;
        }
        int currentIndex = playlist.indexOf(currentSong);
        if (currentIndex < playlist.size() - 1) {
            currentSong = playlist.get(currentIndex + 1);
            return true;
        } else {
            return false;
        }
    }

    public boolean previousSong() {
        if (currentSong == null) {
            return false;
        }
        int currentIndex = playlist.indexOf(currentSong);
        if (currentIndex > 0) {
            currentSong = playlist.get(currentIndex - 1);
            return true;
        } else {
            return false;
        }
    }

    public boolean setVolume(int volume) {
        if (volume >= 0 && volume <= 100) {
            this.volume = volume;
            return true;
        } else {
            return false;
        }
    }

    public boolean shuffle() {
        if (playlist.isEmpty()) {
            return false;
        }
        Collections.shuffle(playlist);
        return true;
    }

    public List<String> getPlaylist() {
        return playlist;
    }

    public void setPlaylist(List<String> playlist) {
        this.playlist = playlist;
    }

    public String getCurrentSong() {
        return currentSong;
    }

    public void setCurrentSong(String currentSong) {
        this.currentSong = currentSong;
    }

    public int getVolume() {
        return volume;
    }
}