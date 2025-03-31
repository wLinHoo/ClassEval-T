
#include <sstream>
#include <iostream>

#include <string>
#include <vector>

struct PlayItem {
    std::string Chord;
    std::string Tune;
};

class AutomaticGuitarSimulator {
public:
    AutomaticGuitarSimulator(const std::string& text);
    std::vector<PlayItem> interpret(bool display = false);
    std::string format_display(const std::string& key, const std::string& value);

private:
    std::string play_text;
};

AutomaticGuitarSimulator::AutomaticGuitarSimulator(const std::string& text) : play_text(text) {}

std::vector<PlayItem> AutomaticGuitarSimulator::interpret(bool display) {
    std::vector<PlayItem> play_list;
    if (play_text.empty()) {
        return play_list;
    }

    std::istringstream iss(play_text);
    std::string play_seg;

    while (iss >> play_seg) {
        size_t pos = 0;
        while (pos < play_seg.size() && isalpha(play_seg[pos])) {
            pos++;
        }

        std::string play_chord = play_seg.substr(0, pos);
        std::string play_value = play_seg.substr(pos);

        PlayItem item = { play_chord, play_value };
        play_list.push_back(item);

        if (display) {
            std::cout << format_display(play_chord, play_value) << std::endl;
        }
    }
    return play_list;
}

std::string AutomaticGuitarSimulator::format_display(const std::string& key, const std::string& value) {
    return "Normal Guitar Playing -- Chord: " + key + ", Play Tune: " + value;
}
