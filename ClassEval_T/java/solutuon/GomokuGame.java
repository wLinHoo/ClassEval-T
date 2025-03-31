package org.example;

import java.util.Arrays;

public class GomokuGame {
    private int boardSize;
    char[][] board;
    private char currentPlayer;

    public GomokuGame(int boardSize) {
        this.boardSize = boardSize;
        this.board = new char[boardSize][boardSize];
        for (char[] row : this.board) {
            Arrays.fill(row, ' ');
        }
        this.currentPlayer = 'X';
    }

    public boolean makeMove(int row, int col) {
        if (this.board[row][col] == ' ') {
            this.board[row][col] = this.currentPlayer;
            this.currentPlayer = (this.currentPlayer == 'X') ? 'O' : 'X';
            return true;
        }
        return false;
    }

    public Character checkWinner() {
        int[][] directions = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
        for (int row = 0; row < this.boardSize; row++) {
            for (int col = 0; col < this.boardSize; col++) {
                if (this.board[row][col] != ' ') {
                    for (int[] direction : directions) {
                        if (checkFiveInARow(row, col, direction)) {
                            return this.board[row][col];
                        }
                    }
                }
            }
        }
        return null;
    }

    boolean checkFiveInARow(int row, int col, int[] direction) {
        int dx = direction[0];
        int dy = direction[1];
        int count = 1;
        char symbol = this.board[row][col];
        for (int i = 1; i < 5; i++) {
            int newRow = row + dx * i;
            int newCol = col + dy * i;
            if (newRow < 0 || newRow >= this.boardSize || newCol < 0 || newCol >= this.boardSize) {
                break;
            }
            if (this.board[newRow][newCol] != symbol) {
                break;
            }
            count++;
        }
        for (int i = 1; i < 5; i++) {
            int newRow = row - dx * i;
            int newCol = col - dy * i;
            if (newRow < 0 || newRow >= this.boardSize || newCol < 0 || newCol >= this.boardSize) {
                break;
            }
            if (this.board[newRow][newCol] != symbol) {
                break;
            }
            count++;
        }
        return count >= 5;
    }

    public static void main(String[] args) {
        GomokuGame gomokuGame = new GomokuGame(10);
        int[][] moves = {{5, 5}, {0, 0}, {5, 4}, {0, 1}, {5, 3}, {0, 2}, {5, 2}, {0, 3}, {5, 1}};
        for (int[] move : moves) {
            gomokuGame.makeMove(move[0], move[1]);
        }
        System.out.println(gomokuGame.checkWinner());
    }
}