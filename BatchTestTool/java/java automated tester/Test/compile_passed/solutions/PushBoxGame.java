import java.util.ArrayList;
import java.util.List;

class PushBoxGame {
    private char[][] map;
    private int playerRow;
    private int playerCol;
    private List<int[]> targets;
    private List<int[]> boxes;
    private int targetCount;
    private boolean isGameover;

    public PushBoxGame(char[][] map) {
        this.map = map;
        this.playerRow = 0;
        this.playerCol = 0;
        this.targets = new ArrayList<>();
        this.boxes = new ArrayList<>();
        this.targetCount = 0;
        this.isGameover = false;

        initGame();
    }

    private void initGame() {
        for (int row = 0; row < map.length; row++) {
            for (int col = 0; col < map[row].length; col++) {
                if (map[row][col] == 'O') {
                    playerRow = row;
                    playerCol = col;
                } else if (map[row][col] == 'G') {
                    targets.add(new int[]{row, col});
                    targetCount++;
                } else if (map[row][col] == 'X') {
                    boxes.add(new int[]{row, col});
                }
            }
        }
    }

    public boolean checkWin() {
        int boxOnTargetCount = 0;
        for (int[] box : boxes) {
            if (targets.contains(box)) {
                boxOnTargetCount++;
            }
        }
        if (boxOnTargetCount == targetCount) {
            isGameover = true;
        }
        return isGameover;
    }

    public boolean move(String direction) {
        int newRow = playerRow;
        int newCol = playerCol;

        switch (direction) {
            case "w":
                newRow--;
                break;
            case "s":
                newRow++;
                break;
            case "a":
                newCol--;
                break;
            case "d":
                newCol++;
                break;
        }

        if (map[newRow][newCol] != '#') {
            if (boxes.contains(new int[]{newRow, newCol})) {
                int[] newBox = new int[2];
                newBox[0] = newRow + (newRow - playerRow);
                newBox[1] = newCol + (newCol - playerCol);

                if (map[newBox[0]][newBox[1]] != '#') {
                    boxes.remove(new int[]{newRow, newCol});
                    boxes.add(newBox);
                    playerRow = newRow;
                    playerCol = newCol;
                }
            } else {
                playerRow = newRow;
                playerCol = newCol;
            }
        }

        return checkWin();
    }
}