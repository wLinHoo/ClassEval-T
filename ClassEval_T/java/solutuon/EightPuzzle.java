package org.example;

import java.util.*;

public class EightPuzzle {
    private int[][] initialState;
    private int[][] goalState;

    public EightPuzzle(int[][] initialState) {
        this.initialState = deepCopy(initialState);
        this.goalState = new int[][]{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    }

    public int[] findBlank(int[][] state) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (state[i][j] == 0) {
                    return new int[]{i, j};
                }
            }
        }
        return null;
    }

    public int[][] move(int[][] state, String direction) {
        int[] blank = findBlank(state);
        int i = blank[0], j = blank[1];
        int[][] newState = deepCopy(state);

        switch (direction) {
            case "up":
                if (i > 0) {
                    newState[i][j] = newState[i - 1][j];
                    newState[i - 1][j] = 0;
                }
                break;
            case "down":
                if (i < 2) {
                    newState[i][j] = newState[i + 1][j];
                    newState[i + 1][j] = 0;
                }
                break;
            case "left":
                if (j > 0) {
                    newState[i][j] = newState[i][j - 1];
                    newState[i][j - 1] = 0;
                }
                break;
            case "right":
                if (j < 2) {
                    newState[i][j] = newState[i][j + 1];
                    newState[i][j + 1] = 0;
                }
                break;
        }
        return newState;
    }

    public List<String> getPossibleMoves(int[][] state) {
        List<String> moves = new ArrayList<>();
        int[] blank = findBlank(state);
        int i = blank[0], j = blank[1];

        if (i > 0) moves.add("up");
        if (i < 2) moves.add("down");
        if (j > 0) moves.add("left");
        if (j < 2) moves.add("right");

        return moves;
    }

    public List<String> solve() {
        Queue<Node> openList = new LinkedList<>();
        Set<String> closedList = new HashSet<>();
        openList.add(new Node(initialState, new ArrayList<>()));

        while (!openList.isEmpty()) {
            Node currentNode = openList.poll();
            int[][] currentState = currentNode.state;
            List<String> path = currentNode.path;
            closedList.add(stateToString(currentState));

            if (Arrays.deepEquals(currentState, goalState)) {
                return path;
            }

            for (String move : getPossibleMoves(currentState)) {
                int[][] newState = move(currentState, move);
                if (!closedList.contains(stateToString(newState))) {
                    List<String> newPath = new ArrayList<>(path);
                    newPath.add(move);
                    openList.add(new Node(newState, newPath));
                }
            }
        }
        return null;
    }

    private String stateToString(int[][] state) {
        StringBuilder sb = new StringBuilder();
        for (int[] row : state) {
            for (int val : row) {
                sb.append(val);
            }
        }
        return sb.toString();
    }

    private int[][] deepCopy(int[][] original) {
        int[][] copy = new int[original.length][];
        for (int i = 0; i < original.length; i++) {
            copy[i] = Arrays.copyOf(original[i], original[i].length);
        }
        return copy;
    }

    private static class Node {
        int[][] state;
        List<String> path;

        Node(int[][] state, List<String> path) {
            this.state = state;
            this.path = path;
        }
    }
}