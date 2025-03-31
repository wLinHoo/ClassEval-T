#include <vector>
#include <string>
#include <utility>

class PushBoxGame {
public:
    PushBoxGame(const std::vector<std::string>& map);
    PushBoxGame();

    std::vector<std::string> gat_map() const;
    bool is_game_over() const;
    int get_player_col() const;
    int get_player_row() const;
    std::vector<std::pair<int, int>> get_targets() const;
    std::vector<std::pair<int, int>> get_boxes() const;
    int get_target_count() const;
    bool check_win();
    bool move(char direction);

    void init_game();

    std::vector<std::string> map;
    int player_row;
    int player_col;
    std::vector<std::pair<int, int>> targets;
    std::vector<std::pair<int, int>> boxes;
    int target_count;
    bool _is_game_over;
};


PushBoxGame::PushBoxGame(const std::vector<std::string>& map)
    : map(map), player_row(0), player_col(0), target_count(0), _is_game_over(false) {
    init_game();
}

PushBoxGame::PushBoxGame()
    : map({}), player_row(0), player_col(0), target_count(0), _is_game_over(false) {
    init_game();
}

std::vector<std::string> PushBoxGame::gat_map() const {
    return map;
}

bool PushBoxGame::is_game_over() const {
    return _is_game_over;
}

int PushBoxGame::get_player_col() const {
    return player_col;
}

int PushBoxGame::get_player_row() const {
    return player_row;
}

std::vector<std::pair<int, int>> PushBoxGame::get_targets() const {
    return targets;
}

std::vector<std::pair<int, int>> PushBoxGame::get_boxes() const {
    return boxes;
}

int PushBoxGame::get_target_count() const {
    return target_count;
}

void PushBoxGame::init_game() {
    for (size_t row = 0; row < map.size(); ++row) {
        for (size_t col = 0; col < map[row].size(); ++col) {
            if (map[row][col] == 'O') {
                player_row = static_cast<int>(row);
                player_col = static_cast<int>(col);
            }
            else if (map[row][col] == 'G') {
                targets.emplace_back(row, col);
                ++target_count;
            }
            else if (map[row][col] == 'X') {
                boxes.emplace_back(row, col);
            }
        }
    }
}

bool PushBoxGame::check_win() {
    int box_on_target_count = 0;
    for (const auto& box : boxes) {
        if (std::find(targets.begin(), targets.end(), box) != targets.end()) {
            ++box_on_target_count;
        }
    }
    if (box_on_target_count == target_count) {
        _is_game_over = true;
    }
    return _is_game_over;
}

bool PushBoxGame::move(char direction) {
    int new_player_row = player_row;
    int new_player_col = player_col;

    if (direction == 'w') {
        --new_player_row;
    }
    else if (direction == 's') {
        ++new_player_row;
    }
    else if (direction == 'a') {
        --new_player_col;
    }
    else if (direction == 'd') {
        ++new_player_col;
    }

    if (map[new_player_row][new_player_col] != '#') {
        if (std::find(boxes.begin(), boxes.end(), std::make_pair(new_player_row, new_player_col)) != boxes.end()) {
            int new_box_row = new_player_row + (new_player_row - player_row);
            int new_box_col = new_player_col + (new_player_col - player_col);

            if (map[new_box_row][new_box_col] != '#') {
                auto box_it = std::find(boxes.begin(), boxes.end(), std::make_pair(new_player_row, new_player_col));
                if (box_it != boxes.end()) {
                    boxes.erase(box_it);
                }
                boxes.emplace_back(new_box_row, new_box_col);
                player_row = new_player_row;
                player_col = new_player_col;
            }
        }
        else {
            player_row = new_player_row;
            player_col = new_player_col;
        }
    }

    return check_win();
}
