package org.example;

import java.util.*;

public class PushBoxGame {
    private char[][] map;
    private int playerRow;
    private int playerCol;
    private List<int[]> targets;
    private List<int[]> boxes;
    private int targetCount;
    private boolean isGameOver;

    public PushBoxGame(char[][] map) {
        this.map = new char[map.length][];
        for (int i = 0; i < map.length; i++) {
            this.map[i] = map[i].clone();
        }
        this.playerRow = 0;
        this.playerCol = 0;
        this.targets = new ArrayList<>();
        this.boxes = new ArrayList<>();
        this.targetCount = 0;
        this.isGameOver = false;
        initGame();
    }

    private void initGame() {
        for (int row = 0; row < map.length; row++) {
            for (int col = 0; col < map[row].length; col++) {
                if (map[row][col] == 'O') {
                    this.playerRow = row;
                    this.playerCol = col;
                } else if (map[row][col] == 'G') {
                    this.targets.add(new int[]{row, col});
                    this.targetCount++;
                } else if (map[row][col] == 'X') {
                    this.boxes.add(new int[]{row, col});
                }
            }
        }
    }

    public boolean checkWin() {
        int boxOnTargetCount = 0;
        for (int[] box : boxes) {
            for (int[] target : targets) {
                if (Arrays.equals(box, target)) {
                    boxOnTargetCount++;
                }
            }
        }
        isGameOver = (boxOnTargetCount == targetCount);
        return isGameOver;
    }

    public boolean move(char direction) {
        int newPlayerRow = playerRow;
        int newPlayerCol = playerCol;

        if (direction == 'w') {
            newPlayerRow -= 1;
        } else if (direction == 's') {
            newPlayerRow += 1;
        } else if (direction == 'a') {
            newPlayerCol -= 1;
        } else if (direction == 'd') {
            newPlayerCol += 1;
        }

        if (isValidMove(newPlayerRow, newPlayerCol)) {
            if (isBoxAt(newPlayerRow, newPlayerCol)) {
                int[] boxPosition = getBoxPosition(newPlayerRow, newPlayerCol);
                int newBoxRow = newPlayerRow + (newPlayerRow - playerRow);
                int newBoxCol = newPlayerCol + (newPlayerCol - playerCol);

                if (isValidMove(newBoxRow, newBoxCol) && !isBoxAt(newBoxRow, newBoxCol)) {
                    moveBox(boxPosition, newBoxRow, newBoxCol);
                    playerRow = newPlayerRow;
                    playerCol = newPlayerCol;
                }
            } else {
                playerRow = newPlayerRow;
                playerCol = newPlayerCol;
            }
        }

        return checkWin();
    }

    private boolean isValidMove(int row, int col) {
        return row >= 0 && row < map.length && col >= 0 && col < map[row].length && map[row][col] != '#';
    }

    private boolean isBoxAt(int row, int col) {
        for (int[] box : boxes) {
            if (Arrays.equals(box, new int[]{row, col})) {
                return true;
            }
        }
        return false;
    }

    private int[] getBoxPosition(int row, int col) {
        for (int[] box : boxes) {
            if (Arrays.equals(box, new int[]{row, col})) {
                return box;
            }
        }
        return null;
    }

    private void moveBox(int[] boxPosition, int newRow, int newCol) {
        for (int i = 0; i < boxes.size(); i++) {
            if (Arrays.equals(boxes.get(i), boxPosition)) {
                boxes.set(i, new int[]{newRow, newCol});
                break;
            }
        }
    }

    public boolean isGameOver() {
        return isGameOver;
    }

    public int getPlayerCol() {
        return playerCol;
    }

    public int getPlayerRow() {
        return playerRow;
    }

    public List<int[]> getTargets() {
        return new ArrayList<>(targets);
    }

    public int getTargetCount() {
        return targetCount;
    }

    public char[][] getMap() {
        return map;
    }

    public List<int[]> getBoxes() {
        return new ArrayList<>(boxes);
    }
}
