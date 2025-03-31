import java.util.Random;

public class MinesweeperGame {
    private int n;
    private int k;
    private char[][] minesweeperMap;
    private char[][] playerMap;
    private int score;

    public MinesweeperGame(int n, int k) {
        this.n = n;
        this.k = k;
        this.minesweeperMap = generateMinesweeperMap();
        this.playerMap = generatePlayerMap();
        this.score = 0;
    }

    private char[][] generateMinesweeperMap() {
        char[][] arr = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = '0';
            }
        }
        Random random = new Random();
        for (int num = 0; num < k; num++) {
            int x = random.nextInt(n);
            int y = random.nextInt(n);
            arr[y][x] = 'X';
            if ((x >= 0 && x <= n - 2) && (y >= 0 && y <= n - 1)) {
                if (arr[y][x + 1] != 'X') {
                    arr[y][x + 1]++;
                }
            }
            if ((x >= 1 && x <= n - 1) && (y >= 0 && y <= n - 1)) {
                if (arr[y][x - 1] != 'X') {
                    arr[y][x - 1]++;
                }
            }
            if ((x >= 1 && x <= n - 1) && (y >= 1 && y <= n - 1)) {
                if (arr[y - 1][x - 1] != 'X') {
                    arr[y - 1][x - 1]++;
                }
            }
            if ((x >= 0 && x <= n - 2) && (y >= 1 && y <= n - 1)) {
                if (arr[y - 1][x + 1] != 'X') {
                    arr[y - 1][x + 1]++;
                }
            }
            if ((x >= 0 && x <= n - 1) && (y >= 1 && y <= n - 1)) {
                if (arr[y - 1][x] != 'X') {
                    arr[y - 1][x]++;
                }
            }
            if ((x >= 0 && x <= n - 2) && (y >= 0 && y <= n - 2)) {
                if (arr[y + 1][x + 1] != 'X') {
                    arr[y + 1][x + 1]++;
                }
            }
            if ((x >= 1 && x <= n - 1) && (y >= 0 && y <= n - 2)) {
                if (arr[y + 1][x - 1] != 'X') {
                    arr[y + 1][x - 1]++;
                }
            }
            if ((x >= 0 && x <= n - 1) && (y >= 0 && y <= n - 2)) {
                if (arr[y + 1][x] != 'X') {
                    arr[y + 1][x]++;
                }
            }
        }
        return arr;
    }

    private char[][] generatePlayerMap() {
        char[][] arr = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = '-';
            }
        }
        return arr;
    }

    private boolean checkWon(char[][] map) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == '-' && minesweeperMap[i][j] != 'X') {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean sweep(int x, int y) {
        if (minesweeperMap[x][y] == 'X') {
            return false;
        } else {
            playerMap[x][y] = minesweeperMap[x][y];
            score++;
            if (checkWon(playerMap)) {
                return true;
            }
            return true;
        }
    }
}