package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Snake {
    private int length;
    final int SCREEN_WIDTH;
    final int SCREEN_HEIGHT;
    final int BLOCK_SIZE;
    private List<Position> positions;
    private int score;
    private Position foodPosition;
    private Random random;

    public Snake(int SCREEN_WIDTH, int SCREEN_HEIGHT, int BLOCK_SIZE, Position foodPosition) {
        this.length = 1;
        this.SCREEN_WIDTH = SCREEN_WIDTH;
        this.SCREEN_HEIGHT = SCREEN_HEIGHT;
        this.BLOCK_SIZE = BLOCK_SIZE;
        this.positions = new ArrayList<>();
        this.positions.add(new Position(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
        this.score = 0;
        this.foodPosition = foodPosition;
        this.random = new Random();
    }

    public void move(Position direction) {
        Position cur = positions.get(0);
        int x = direction.getX();
        int y = direction.getY();

        int newX = (cur.getX() + (x * BLOCK_SIZE)) % SCREEN_WIDTH;
        int newY = (cur.getY() + (y * BLOCK_SIZE)) % SCREEN_HEIGHT;

        Position newPosition = new Position(newX, newY);

        if (newPosition.equals(foodPosition)) {
            eatFood();
        }

        if (positions.size() > 2 && positions.subList(2, positions.size()).contains(newPosition)) {
            reset();
        } else {
            positions.add(0, newPosition);
            if (positions.size() > length) {
                positions.remove(positions.size() - 1);
            }
        }
    }

    public void randomFoodPosition() {
        do {
            int x = random.nextInt(SCREEN_WIDTH / BLOCK_SIZE) * BLOCK_SIZE;
            int y = random.nextInt(SCREEN_HEIGHT / BLOCK_SIZE) * BLOCK_SIZE;
            foodPosition = new Position(x, y);
        } while (positions.contains(foodPosition));
    }

    public void reset() {
        length = 1;
        positions.clear();
        positions.add(new Position(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
        score = 0;
        randomFoodPosition();
    }

    public void eatFood() {
        length++;
        score += 100;
        randomFoodPosition();
    }

    public int getLength() {
        return length;
    }

    public List<Position> getPositions() {
        return positions;
    }

    public int getScore() {
        return score;
    }

    public Position getFoodPosition() {
        return foodPosition;
    }

    public static class Position {
        private final int x;
        private final int y;

        public Position(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Position position = (Position) o;
            return x == position.x && y == position.y;
        }

        @Override
        public int hashCode() {
            return 31 * x + y;
        }
    }
}