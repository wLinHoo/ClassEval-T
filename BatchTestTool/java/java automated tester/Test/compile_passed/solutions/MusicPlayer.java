import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class MusicPlayer {
    // Public members for testing (equivalent to the public variables in C++)
    public List<String> playlist;
    public String currentSong;
    public int volume;

    // Constructor
    public MusicPlayer() {
        playlist = new ArrayList<>();
        currentSong = "";
        volume = 0;
    }

    // Public methods
    public void addSong(String song) {
        playlist.add(song);
    }

    public void removeSong(String song) {
        int index = playlist.indexOf(song);
        if (index != -1) {
            playlist.remove(index);
            if (currentSong != null && currentSong.equals(song)) {
                stop();
            }
        }
    }

    public String play() {
        if (!playlist.isEmpty()) {
            if (currentSong != null && !currentSong.isEmpty()) {
                for (String x : playlist) {
                    if (x.equals(currentSong)) {
                        return currentSong;
                    }
                }
                return playlist.get(0);
            } else {
                return playlist.get(0);
            }
        }
        return "";
    }

    public boolean stop() {
        if (currentSong != null && !currentSong.isEmpty()) {
            currentSong = "";  // or currentSong = null;
            return true;
        }
        return false;
    }

    public boolean switchSong() {
        if (currentSong != null && !currentSong.isEmpty()) {
            int currentIndex = playlist.indexOf(currentSong);
            if (currentIndex != -1 && currentIndex < playlist.size() - 1) {
                currentSong = playlist.get(currentIndex + 1);
                return true;
            }
            return false;
        }
        return false;
    }

    public boolean previousSong() {
        if (!currentSong.isEmpty()) {
            int index = playlist.indexOf(currentSong);
            if (index > 0) {
                currentSong = playlist.get(index - 1);
                return true;
            }
        }
        return false;
    }

    public boolean setVolume(int volume) {
        if (isValidVolume(volume)) {
            this.volume = volume;
            return true;
        }
        return false;
    }

    public boolean shuffle() {
        if (!playlist.isEmpty()) {
            Collections.shuffle(playlist);
            return true;
        }
        return false;
    }

    // Private helper method
    private boolean isValidVolume(int volume) {
        return volume >= 0 && volume <= 100;
    }
}