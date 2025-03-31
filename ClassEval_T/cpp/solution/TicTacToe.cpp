#include <vector>
#include <string>

class TicTacToe {
public:
    TicTacToe(int N = 3);
    bool make_move(int row, int col);
    char check_winner();
    bool is_board_full();
    char get_current_player() const;

private:
    std::vector<std::vector<char>> board;
    char current_player;
};

TicTacToe::TicTacToe(int N) : board(3, std::vector<char>(N, ' ')), current_player('X') {}


bool TicTacToe::make_move(int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = current_player;
        current_player = (current_player == 'X') ? 'O' : 'X';
        return true;
    }
    else {
        return false;
    }
}


char TicTacToe::check_winner() {
    
    for (const auto& row : board) {
        if (row[0] != ' ' && row[0] == row[1] && row[1] == row[2]) {
            return row[0];
        }
    }
    
    for (int col = 0; col < 3; ++col) {
        if (board[0][col] != ' ' && board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            return board[0][col];
        }
    }
    
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    return '\0'; 
}



bool TicTacToe::is_board_full() {
    for (const auto& row : board) {
        if (std::find(row.begin(), row.end(), ' ') != row.end()) {
            return false;
        }
    }
    return true;
}


char TicTacToe::get_current_player() const {
    return current_player;
}
