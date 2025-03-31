package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class MahjongConnect {
    int[] BOARD_SIZE;
    List<String> ICONS;
    String[][] board;

    public MahjongConnect(int[] BOARD_SIZE, List<String> ICONS) {
        this.BOARD_SIZE = BOARD_SIZE;
        this.ICONS = ICONS;
        this.board = createBoard();
    }

    public String[][] createBoard() {
        String[][] board = new String[BOARD_SIZE[0]][BOARD_SIZE[1]];
        Random random = new Random();
        for (int i = 0; i < BOARD_SIZE[0]; i++) {
            for (int j = 0; j < BOARD_SIZE[1]; j++) {
                board[i][j] = ICONS.get(random.nextInt(ICONS.size()));
            }
        }
        return board;
    }

    public boolean isValidMove(int[] pos1, int[] pos2) {
        int x1 = pos1[0], y1 = pos1[1];
        int x2 = pos2[0], y2 = pos2[1];

        if (!isValidPosition(x1, y1) || !isValidPosition(x2, y2)) {
            return false;
        }

        if (x1 == x2 && y1 == y2) {
            return false;
        }

        if (!board[x1][y1].equals(board[x2][y2])) {
            return false;
        }

        return hasPath(pos1, pos2);
    }

    private boolean isValidPosition(int x, int y) {
        return x >= 0 && x < BOARD_SIZE[0] && y >= 0 && y < BOARD_SIZE[1];
    }

    public boolean hasPath(int[] pos1, int[] pos2) {
        int x1 = pos1[0], y1 = pos1[1];
        int x2 = pos2[0], y2 = pos2[1];

        if (!isValidPosition(x1, y1) || !isValidPosition(x2, y2)) {
            return false;
        }

        boolean[][] visited = new boolean[BOARD_SIZE[0]][BOARD_SIZE[1]];
        return dfs(x1, y1, pos2, visited);
    }

    private boolean dfs(int x, int y, int[] target, boolean[][] visited) {
        if (x == target[0] && y == target[1]) {
            return true;
        }

        if (visited[x][y]) {
            return false;
        }

        visited[x][y] = true;

        int[][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int[] dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            if (isValidPosition(newX, newY) && !visited[newX][newY] && board[newX][newY].equals(board[x][y])) {
                if (dfs(newX, newY, target, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    public void removeIcons(int[] pos1, int[] pos2) {
        board[pos1[0]][pos1[1]] = " ";
        board[pos2[0]][pos2[1]] = " ";
    }

    public boolean isGameOver() {
        for (int i = 0; i < BOARD_SIZE[0]; i++) {
            for (int j = 0; j < BOARD_SIZE[1]; j++) {
                if (!board[i][j].equals(" ")) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int[] boardSize = {4, 4};
        List<String> icons = new ArrayList<>();
        icons.add("a");
        icons.add("b");
        icons.add("c");

        MahjongConnect mc = new MahjongConnect(boardSize, icons);
        System.out.println(mc.isValidMove(new int[]{0, 0}, new int[]{1, 0}));
        mc.removeIcons(new int[]{0, 0}, new int[]{1, 0});
        System.out.println(mc.isGameOver());
    }
}