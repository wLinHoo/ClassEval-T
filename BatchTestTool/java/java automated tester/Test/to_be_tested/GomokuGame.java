package to_be_tested;

public class GomokuGame {

    public int boardSize;

    public char[][] board;

    public char currentPlayer;

    public GomokuGame(int boardSize) {
        this.boardSize = boardSize;
        this.board = new char[boardSize][boardSize];
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                board[i][j] = ' ';
            }
        }
        this.currentPlayer = 'X';
    }

    public boolean makeMove(int row, int col) {
        if (board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            return true;
        }
        return false;
    }

    public char checkWinner() {
        int[][] directions = { { 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, -1 } };
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                if (board[i][j] != ' ') {
                    for (int[] direction : directions) {
                        if (checkFiveInARow(i, j, direction)) {
                            return board[i][j];
                        }
                    }
                }
            }
        }
        return ' ';
    }

    public boolean checkFiveInARow(int row, int col, int[] direction) {
        int dx = direction[0];
        int dy = direction[1];
        int count = 1;
        char symbol = board[row][col];
        for (int i = 1; i < 5; i++) {
            int new_row = row + dx * i;
            int new_col = col + dy * i;
            if (new_row < 0 || new_row >= boardSize || new_col < 0 || new_col >= boardSize) {
                return false;
            }
            if (board[new_row][new_col] != symbol) {
                return false;
            }
            count++;
        }
        return count == 5;
    }
}
