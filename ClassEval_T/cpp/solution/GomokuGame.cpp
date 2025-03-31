#include <vector>
#include <optional>

class GomokuGame {
public:
    explicit GomokuGame(int board_size);
    bool make_move(int row, int col);
    std::optional<char> check_winner() const;
    std::vector<std::vector<char>> getBoard() const;
    bool _check_five_in_a_row(int row, int col, std::pair<int, int> direction) const;
    int board_size;
    std::vector<std::vector<char>> board;
    char current_player;
};

GomokuGame::GomokuGame(int board_size)
    : board_size(board_size),
    board(board_size, std::vector<char>(board_size, ' ')),
    current_player('X')
{}

bool GomokuGame::make_move(int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = current_player;
        current_player = (current_player == 'X') ? 'O' : 'X';
        return true;
    }
    return false;
}

std::optional<char> GomokuGame::check_winner() const {
    const std::vector<std::pair<int, int>> directions = { {0, 1}, {1, 0}, {1, 1}, {1, -1} };
    for (int row = 0; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            if (board[row][col] != ' ') {
                for (const auto& direction : directions) {
                    if (_check_five_in_a_row(row, col, direction)) {
                        return board[row][col];
                    }
                }
            }
        }
    }
    return std::nullopt;
}

std::vector<std::vector<char>> GomokuGame::getBoard() const {
    return board;
}

bool GomokuGame::_check_five_in_a_row(int row, int col, std::pair<int, int> direction) const {
    int dx = direction.first;
    int dy = direction.second;
    int count = 1;
    char symbol = board[row][col];
    for (int i = 1; i < 5; ++i) {
        int new_row = row + dx * i;
        int new_col = col + dy * i;
        if (!(0 <= new_row && new_row < board_size && 0 <= new_col && new_col < board_size)) {
            return false;
        }
        if (board[new_row][new_col] != symbol) {
            return false;
        }
        ++count;
    }
    return count == 5;
}
