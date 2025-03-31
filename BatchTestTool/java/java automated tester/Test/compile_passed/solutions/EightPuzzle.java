import java.util.ArrayList;
import java.util.List;

public class EightPuzzle {
    private int[][] initial_state;
    private int[][] goal_state = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

    public EightPuzzle(int[][] initial_state) {
        this.initial_state = initial_state;
    }

    private int findBlank(int[][] state) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (state[i][j] == 0) {
                    return i * 3 + j;
                }
            }
        }
        return -1;
    }

    private int[][] move(int[][] state, String direction) {
        int blankIndex = findBlank(state);
        int row = blankIndex / 3;
        int col = blankIndex % 3;

        int[][] newState = new int[3][3];
        for (int i = 0; i < 3; i++) {
            System.arraycopy(state[i], 0, newState[i], 0, 3);
        }

        if (direction.equals("up") && row > 0) {
            newState[row][col] = newState[row - 1][col];
            newState[row - 1][col] = 0;
        } else if (direction.equals("down") && row < 2) {
            newState[row][col] = newState[row + 1][col];
            newState[row + 1][col] = 0;
        } else if (direction.equals("left") && col > 0) {
            newState[row][col] = newState[row][col - 1];
            newState[row][col - 1] = 0;
        } else if (direction.equals("right") && col < 2) {
            newState[row][col] = newState[row][col + 1];
            newState[row][col + 1] = 0;
        }

        return newState;
    }

    private List<String> getPossibleMoves(int[][] state) {
        List<String> moves = new ArrayList<>();
        int blankIndex = findBlank(state);
        int row = blankIndex / 3;
        int col = blankIndex % 3;

        if (row > 0) {
            moves.add("up");
        }
        if (row < 2) {
            moves.add("down");
        }
        if (col > 0) {
            moves.add("left");
        }
        if (col < 2) {
            moves.add("right");
        }

        return moves;
    }

    public List<String> solve() {
        List<int[][]> openList = new ArrayList<>();
        List<int[][]> closedList = new ArrayList<>();

        openList.add(initial_state);

        while (!openList.isEmpty()) {
            int[][] currentState = openList.remove(0);
            closedList.add(currentState);

            if (isGoalState(currentState)) {
                return reconstructPath(currentState);
            }

            for (String move : getPossibleMoves(currentState)) {
                int[][] newState = move(currentState, move);
                if (!closedList.contains(newState) && !openList.contains(newState)) {
                    openList.add(newState);
                }
            }
        }

        return null;
    }

    private boolean isGoalState(int[][] state) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (state[i][j] != goal_state[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    private List<String> reconstructPath(int[][] state) {
        List<String> path = new ArrayList<>();
        while (state != initial_state) {
            int blankIndex = findBlank(state);
            int row = blankIndex / 3;
            int col = blankIndex % 3;

            for (String move : getPossibleMoves(state)) {
                int[][] newState = move(state, move);
                if (findBlank(newState) == blankIndex) {
                    path.add(move);
                    state = newState;
                    break;
                }
            }
        }
        return path;
    }
}