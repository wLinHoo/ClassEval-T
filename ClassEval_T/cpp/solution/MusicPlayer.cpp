#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>

class MusicPlayer {
public:
    MusicPlayer();

    void add_song(const std::string& song);
    void remove_song(const std::string& song);
    std::string play();
    bool stop();
    bool switch_song();
    bool previous_song();
    bool set_volume(int volume);
    bool shuffle();

    
    std::vector<std::string> playlist;
    std::string current_song;
    int volume;

private:
    bool is_valid_volume(int volume) const;
};

MusicPlayer::MusicPlayer() : volume(50) {
    std::srand(static_cast<unsigned>(std::time(0))); 
}

void MusicPlayer::add_song(const std::string& song) {
    playlist.push_back(song);
}

void MusicPlayer::remove_song(const std::string& song) {
    auto it = std::find(playlist.begin(), playlist.end(), song);
    if (it != playlist.end()) {
        playlist.erase(it);
        if (current_song == song) {
            stop();
        }
    }
}

std::string MusicPlayer::play() {
    if (!playlist.empty()) {
        if (!current_song.empty()) {
            for (auto x : playlist)
            {
                if (x == current_song)
                {
                    return current_song;
                }
            }
            return *playlist.begin();
        }
        else {
            return playlist.front();
        }
    }
    return ""; 
}

bool MusicPlayer::stop() {
    if (!current_song.empty()) {
        current_song.clear();
        return true;
    }
    return false;
}

bool MusicPlayer::switch_song() {
    if (!current_song.empty()) {
        auto it = std::find(playlist.begin(), playlist.end(), current_song);
        if (it != playlist.end() && (it + 1) != playlist.end()) {
            current_song = *(it + 1);
            return true;
        }
        return false;
    }
    return false;
}

bool MusicPlayer::previous_song() {
    if (!current_song.empty()) {
        auto it = std::find(playlist.begin(), playlist.end(), current_song);
        if (it != playlist.begin()) {
            current_song = *(it - 1);
            return true;
        }
    }
    return false;
}


bool MusicPlayer::set_volume(int volume) {
    if (is_valid_volume(volume)) {
        this->volume = volume;
        return true;
    }
    return false;
}

bool MusicPlayer::shuffle() {
    if (!playlist.empty()) {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(playlist.begin(), playlist.end(), g);
        return true;
    }
    return false;
}

bool MusicPlayer::is_valid_volume(int volume) const {
    return volume >= 0 && volume <= 100;
}
