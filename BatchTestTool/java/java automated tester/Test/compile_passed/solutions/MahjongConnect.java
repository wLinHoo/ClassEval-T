import java.util.*;

class MahjongConnect {
    private int[] BOARD_SIZE;
    private char[] ICONS;
    private char[][] board;

    public MahjongConnect(int[] BOARD_SIZE, char[] ICONS) {
        this.BOARD_SIZE = BOARD_SIZE;
        this.ICONS = ICONS;
        this.board = createBoard();
    }

    private char[][] createBoard() {
        char[][] board = new char[BOARD_SIZE[0]][BOARD_SIZE[1]];
        Random random = new Random();
        for (int i = 0; i < BOARD_SIZE[0]; i++) {
            for (int j = 0; j < BOARD_SIZE[1]; j++) {
                board[i][j] = ICONS[random.nextInt(ICONS.length)];
            }
        }
        return board;
    }

    public boolean isValidMove(int[] pos1, int[] pos2) {
        int x1 = pos1[0];
        int y1 = pos1[1];
        int x2 = pos2[0];
        int y2 = pos2[1];

        // Check if positions are within the game board range
        if (!(0 <= x1 && x1 < BOARD_SIZE[0] && 0 <= y1 && y1 < BOARD_SIZE[1] && 0 <= x2 && x2 < BOARD_SIZE[0] && 0 <= y2 && y2 < BOARD_SIZE[1])) {
            return false;
        }

        // Check if the two positions are the same
        if (Arrays.equals(pos1, pos2)) {
            return false;
        }

        // Check if the two positions have the same icon
        if (board[x1][y1] != board[x2][y2]) {
            return false;
        }

        // Check if there is a valid path between the two positions
        if (!hasPath(pos1, pos2)) {
            return false;
        }

        return true;
    }

    private boolean hasPath(int[] pos1, int[] pos2) {
        Set<int[]> visited = new HashSet<>();
        Stack<int[]> stack = new Stack<>();
        stack.push(pos1);

        while (!stack.isEmpty()) {
            int[] currentPos = stack.pop();
            if (Arrays.equals(currentPos, pos2)) {
                return true;
            }

            if (visited.contains(currentPos)) {
                continue;
            }

            visited.add(currentPos);
            int x = currentPos[0];
            int y = currentPos[1];

            // Check adjacent positions (up, down, left, right)
            for (int[] delta : new int[][]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                int newX = x + delta[0];
                int newY = y + delta[1];
                if (0 <= newX && newX < BOARD_SIZE[0] && 0 <= newY && newY < BOARD_SIZE[1]) {
                    int[] newPos = new int[]{newX, newY};
                    if (!visited.contains(newPos) && board[newX][newY] == board[x][y]) {
                        stack.push(newPos);
                    }
                }
            }
        }

        return false;
    }

    public boolean isGameOver() {
        for (char[] row : board) {
            for (char icon : row) {
                if (icon != ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    public void removeIcons(int[] pos1, int[] pos2) {
        int x1 = pos1[0];
        int y1 = pos1[1];
        int x2 = pos2[0];
        int y2 = pos2[1];
        board[x1][y1] = ' ';
        board[x2][y2] = ' ';
    }
}