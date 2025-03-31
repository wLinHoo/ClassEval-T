package test_cases;
import to_be_tested.Snake;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class SnakeTest {

    @Test
    public void testMove1() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        snake.move(new Snake.Position(1, 1));
        assertEquals(2, snake.getLength());
        assertEquals(new Snake.Position(51, 51), snake.getPositions().get(0));
        assertEquals(new Snake.Position(50, 50), snake.getPositions().get(1));
        assertEquals(100, snake.getScore());
    }

    @Test
    public void testMove2() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(80, 80));
        snake.move(new Snake.Position(1, 1));
        assertEquals(1, snake.getLength());
        assertEquals(new Snake.Position(51, 51), snake.getPositions().get(0));
        assertEquals(0, snake.getScore());
    }

    @Test
    public void testMove3() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        snake.move(new Snake.Position(1, 0));
        assertEquals(1, snake.getLength());
        assertEquals(new Snake.Position(51, 50), snake.getPositions().get(0));
        assertEquals(0, snake.getScore());
    }

    @Test
    public void testMove4() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        snake.move(new Snake.Position(0, 0));
        assertEquals(1, snake.getLength());
        assertEquals(new Snake.Position(50, 50), snake.getPositions().get(0));
        assertEquals(0, snake.getScore());
    }

    @Test
    public void testMove5() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(99, 99));
        snake.move(new Snake.Position(1, 0));
        assertEquals(1, snake.getLength());
        assertEquals(new Snake.Position(51, 50), snake.getPositions().get(0));
        assertEquals(0, snake.getScore());
    }

    @Test
    public void testRandomFoodPosition1() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        assertEquals(new Snake.Position(51, 51), snake.getFoodPosition());
        snake.randomFoodPosition();
        assertFalse(snake.getPositions().contains(snake.getFoodPosition()));
        assertTrue(snake.getFoodPosition().getX() >= 0);
        assertTrue(snake.getFoodPosition().getY() >= 0);
        assertTrue(snake.getFoodPosition().getX() <= 100);
        assertTrue(snake.getFoodPosition().getY() <= 100);
    }

    @Test
    public void testRandomFoodPosition2() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(99, 99));
        assertEquals(new Snake.Position(99, 99), snake.getFoodPosition());
        snake.randomFoodPosition();
        assertFalse(snake.getPositions().contains(snake.getFoodPosition()));
        assertTrue(snake.getFoodPosition().getX() >= 0);
        assertTrue(snake.getFoodPosition().getY() >= 0);
        assertTrue(snake.getFoodPosition().getX() <= 100);
        assertTrue(snake.getFoodPosition().getY() <= 100);
    }

    @Test
    public void testRandomFoodPosition3() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(0, 0));
        assertEquals(new Snake.Position(0, 0), snake.getFoodPosition());
        snake.randomFoodPosition();
        assertFalse(snake.getPositions().contains(snake.getFoodPosition()));
        assertTrue(snake.getFoodPosition().getX() >= 0);
        assertTrue(snake.getFoodPosition().getY() >= 0);
        assertTrue(snake.getFoodPosition().getX() <= 100);
        assertTrue(snake.getFoodPosition().getY() <= 100);
    }

    @Test
    public void testRandomFoodPosition4() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(40, 40));
        assertEquals(new Snake.Position(40, 40), snake.getFoodPosition());
        snake.randomFoodPosition();
        assertFalse(snake.getPositions().contains(snake.getFoodPosition()));
        assertTrue(snake.getFoodPosition().getX() >= 0);
        assertTrue(snake.getFoodPosition().getY() >= 0);
        assertTrue(snake.getFoodPosition().getX() <= 100);
        assertTrue(snake.getFoodPosition().getY() <= 100);
    }

    @Test
    public void testRandomFoodPosition5() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(60, 60));
        assertEquals(new Snake.Position(60, 60), snake.getFoodPosition());
        snake.randomFoodPosition();
        assertFalse(snake.getPositions().contains(snake.getFoodPosition()));
        assertTrue(snake.getFoodPosition().getX() >= 0);
        assertTrue(snake.getFoodPosition().getY() >= 0);
        assertTrue(snake.getFoodPosition().getX() <= 100);
        assertTrue(snake.getFoodPosition().getY() <= 100);
    }

    @Test
    public void testReset1() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        snake.move(new Snake.Position(1, 1));
        snake.reset();
        assertEquals(1, snake.getLength());
        assertEquals(new Snake.Position(50, 50), snake.getPositions().get(0));
        assertEquals(0, snake.getScore());
    }

    @Test
    public void testReset2() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        snake.move(new Snake.Position(0, 1));
        snake.reset();
        assertEquals(1, snake.getLength());
        assertEquals(new Snake.Position(50, 50), snake.getPositions().get(0));
        assertEquals(0, snake.getScore());
    }

    @Test
    public void testReset3() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        snake.move(new Snake.Position(0, -1));
        snake.reset();
        assertEquals(1, snake.getLength());
        assertEquals(new Snake.Position(50, 50), snake.getPositions().get(0));
        assertEquals(0, snake.getScore());
    }

    @Test
    public void testReset4() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        snake.move(new Snake.Position(-1, 0));
        snake.reset();
        assertEquals(1, snake.getLength());
        assertEquals(new Snake.Position(50, 50), snake.getPositions().get(0));
        assertEquals(0, snake.getScore());
    }

    @Test
    public void testReset5() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        snake.move(new Snake.Position(1, 0));
        snake.reset();
        assertEquals(1, snake.getLength());
        assertEquals(new Snake.Position(50, 50), snake.getPositions().get(0));
        assertEquals(0, snake.getScore());
    }

    @Test
    public void testEatFood1() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        assertEquals(1, snake.getLength());
        assertEquals(0, snake.getScore());
        snake.eatFood();
        assertEquals(2, snake.getLength());
        assertEquals(100, snake.getScore());
    }

    @Test
    public void testEatFood2() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        assertEquals(1, snake.getLength());
        assertEquals(0, snake.getScore());
        snake.eatFood();
        snake.eatFood();
        assertEquals(3, snake.getLength());
        assertEquals(200, snake.getScore());
    }

    @Test
    public void testEatFood3() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        assertEquals(1, snake.getLength());
        assertEquals(0, snake.getScore());
        snake.eatFood();
        snake.eatFood();
        snake.eatFood();
        assertEquals(4, snake.getLength());
        assertEquals(300, snake.getScore());
    }

    @Test
    public void testEatFood4() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        assertEquals(1, snake.getLength());
        assertEquals(0, snake.getScore());
        snake.eatFood();
        snake.eatFood();
        snake.eatFood();
        snake.eatFood();
        assertEquals(5, snake.getLength());
        assertEquals(400, snake.getScore());
    }

    @Test
    public void testEatFood5() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        assertEquals(1, snake.getLength());
        assertEquals(0, snake.getScore());
        snake.eatFood();
        snake.eatFood();
        snake.eatFood();
        snake.eatFood();
        snake.eatFood();
        assertEquals(6, snake.getLength());
        assertEquals(500, snake.getScore());
    }

    @Test
    public void testSnake() {
        Snake snake = new Snake(100, 100, 1, new Snake.Position(51, 51));
        assertEquals(1, snake.getLength());
        assertEquals(100, snake.SCREEN_WIDTH);
        assertEquals(100, snake.SCREEN_HEIGHT);
        assertEquals(1, snake.BLOCK_SIZE);
        assertEquals(new Snake.Position(50, 50), snake.getPositions().get(0));
        assertEquals(0, snake.getScore());
        assertEquals(new Snake.Position(51, 51), snake.getFoodPosition());
        snake.move(new Snake.Position(1, 1));
        assertEquals(2, snake.getLength());
        assertEquals(new Snake.Position(51, 51), snake.getPositions().get(0));
        assertEquals(100, snake.getScore());
        snake.randomFoodPosition();
        assertFalse(snake.getPositions().contains(snake.getFoodPosition()));
        snake.reset();
        assertEquals(1, snake.getLength());
        assertEquals(new Snake.Position(50, 50), snake.getPositions().get(0));
        assertEquals(0, snake.getScore());
    }
}