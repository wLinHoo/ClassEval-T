package to_be_tested;

import java.util.ArrayList;
import java.util.Random;

public class Snake {

    public int length;

    public int SCREEN_WIDTH;

    public int SCREEN_HEIGHT;

    public int BLOCK_SIZE;

    public Point foodPosition;

    public ArrayList<Point> positions;

    public int score;

    public Snake(int SCREEN_WIDTH, int SCREEN_HEIGHT, int BLOCK_SIZE, Point foodPosition) {
        this.length = 1;
        this.SCREEN_WIDTH = SCREEN_WIDTH;
        this.SCREEN_HEIGHT = SCREEN_HEIGHT;
        this.BLOCK_SIZE = BLOCK_SIZE;
        this.positions = new ArrayList<>();
        positions.add(new Point(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
        this.score = 0;
        this.foodPosition = foodPosition;
    }

    public void move(Direction direction) {
        Point cur = positions.get(0);
        int x = direction.getX();
        int y = direction.getY();
        Point newPoint = new Point(((cur.getX() + (x * BLOCK_SIZE)) % SCREEN_WIDTH), ((cur.getY() + (y * BLOCK_SIZE)) % SCREEN_HEIGHT));
        if (newPoint.equals(foodPosition)) {
            eatFood();
        }
        if (positions.size() > 2 && positions.contains(newPoint)) {
            reset();
        } else {
            positions.add(0, newPoint);
            if (positions.size() > length) {
                positions.remove(positions.size() - 1);
            }
        }
    }

    public void randomFoodPosition() {
        while (positions.contains(foodPosition)) {
            foodPosition = new Point(new Random().nextInt((SCREEN_WIDTH / BLOCK_SIZE) - 1) * BLOCK_SIZE, new Random().nextInt((SCREEN_HEIGHT / BLOCK_SIZE) - 1) * BLOCK_SIZE);
        }
    }

    public void reset() {
        length = 1;
        positions.clear();
        positions.add(new Point(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
        score = 0;
        randomFoodPosition();
    }

    public void eatFood() {
        length += 1;
        score += 100;
        randomFoodPosition();
    }
}

public class Point {

    public int x;

    public int y;

    public Point(int x, int y) {
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
        if (this == o)
            return true;
        if (o == null || getClass() != o.getClass())
            return false;
        Point point = (Point) o;
        return x == point.x && y == point.y;
    }
}

enum Direction {

    UP(0, -1), DOWN(0, 1), LEFT(-1, 0), RIGHT(1, 0);

    public final int x;

    public final int y;

    Direction(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }
}
