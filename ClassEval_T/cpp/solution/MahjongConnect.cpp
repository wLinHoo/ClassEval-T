
#include <algorithm>

#include <vector>
#include <utility>
#include <set>
#include <cstdlib>

class MahjongConnect {
public:
    MahjongConnect(const std::pair<int, int>& boardSize, const std::vector<char>& icons);

    bool is_valid_move(const std::pair<int, int>& pos1, const std::pair<int, int>& pos2);
    void remove_icons(const std::pair<int, int>& pos1, const std::pair<int, int>& pos2);
    bool is_game_over() const;

    std::pair<int, int> BOARD_SIZE;
    std::vector<char> ICONS;
    std::vector<std::vector<char>> board;

    std::vector<std::vector<char>> create_board();
    bool has_path(const std::pair<int, int>& pos1, const std::pair<int, int>& pos2) const;
};


MahjongConnect::MahjongConnect(const std::pair<int, int>& boardSize, const std::vector<char>& icons)
    : BOARD_SIZE(boardSize), ICONS(icons), board(create_board()) {}

std::vector<std::vector<char>> MahjongConnect::create_board() {
    std::vector<std::vector<char>> newBoard(BOARD_SIZE.first, std::vector<char>(BOARD_SIZE.second));

    for (int i = 0; i < BOARD_SIZE.first; ++i) {
        for (int j = 0; j < BOARD_SIZE.second; ++j) {
            newBoard[i][j] = ICONS[rand() % ICONS.size()];
        }
    }

    return newBoard;
}

bool MahjongConnect::is_valid_move(const std::pair<int, int>& pos1, const std::pair<int, int>& pos2) {
    int x1 = pos1.first, y1 = pos1.second;
    int x2 = pos2.first, y2 = pos2.second;

    
    if (!(0 <= x1 && x1 < BOARD_SIZE.first && 0 <= y1 && y1 < BOARD_SIZE.second &&
        0 <= x2 && x2 < BOARD_SIZE.first && 0 <= y2 && y2 < BOARD_SIZE.second)) {
        return false;
    }

    
    if (pos1 == pos2) {
        return false;
    }

    
    if (board[x1][y1] != board[x2][y2]) {
        return false;
    }

    
    return has_path(pos1, pos2);
}

bool MahjongConnect::has_path(const std::pair<int, int>& pos1, const std::pair<int, int>& pos2) const {
    std::set<std::pair<int, int>> visited;
    std::vector<std::pair<int, int>> stack;
    stack.push_back(pos1);

    while (!stack.empty()) {
        std::pair<int, int> currentPos = stack.back();
        stack.pop_back();

        if (currentPos == pos2) {
            return true;
        }

        if (visited.find(currentPos) != visited.end()) {
            continue;
        }

        visited.insert(currentPos);
        int x = currentPos.first, y = currentPos.second;

        
        for (const auto& direction : std::vector<std::pair<int, int>>{ {0, 1}, {0, -1}, {1, 0}, {-1, 0} }) {
            int newX = x + direction.first, newY = y + direction.second;
            if (0 <= newX && newX < BOARD_SIZE.first && 0 <= newY && newY < BOARD_SIZE.second) {
                if (visited.find({ newX, newY }) == visited.end() && board[newX][newY] == board[x][y]) {
                    stack.push_back({ newX, newY });
                }
            }
        }
    }

    return false;
}

void MahjongConnect::remove_icons(const std::pair<int, int>& pos1, const std::pair<int, int>& pos2) {
    board[pos1.first][pos1.second] = ' ';
    board[pos2.first][pos2.second] = ' ';
}

bool MahjongConnect::is_game_over() const {
    for (const auto& row : board) {
        if (std::any_of(row.begin(), row.end(), [](char icon) { return icon != ' '; })) {
            return false;
        }
    }
    return true;
}
