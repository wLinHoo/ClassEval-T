package org.example;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class FitnessTrackerTest {

    @Test
    public void testGetBMI() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.8, 70.0, 20, "male");
        assertEquals(21.604938271604937, fitnessTracker.getBMI());
    }

    @Test
    public void testGetBMI2() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.8, 50.0, 20, "male");
        assertEquals(15.432098765432098, fitnessTracker.getBMI());
    }

    @Test
    public void testGetBMI3() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.72, 53.0, 20, "male");
        assertEquals(17.915089237425637, fitnessTracker.getBMI());
    }

    @Test
    public void testGetBMI4() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.72, 60.0, 20, "male");
        assertEquals(20.281233098972418, fitnessTracker.getBMI());
    }

    @Test
    public void testGetBMI5() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.72, 65.0, 20, "male");
        assertEquals(21.971335857220122, fitnessTracker.getBMI());
    }

    @Test
    public void testConditionJudge() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.8, 45.0, 20, "female");
        assertEquals(-1, fitnessTracker.conditionJudge());
    }

    @Test
    public void testConditionJudge2() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.72, 80.0, 22, "female");
        assertEquals(1, fitnessTracker.conditionJudge());
    }

    @Test
    public void testConditionJudge3() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.72, 53.0, 22, "male");
        assertEquals(-1, fitnessTracker.conditionJudge());
    }

    @Test
    public void testConditionJudge4() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.72, 60.0, 22, "male");
        assertEquals(0, fitnessTracker.conditionJudge());
    }

    @Test
    public void testConditionJudge5() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.72, 75.0, 22, "male");
        assertEquals(1, fitnessTracker.conditionJudge());
    }

    @Test
    public void testCalculateCalorieIntake() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.8, 70.0, 20, "female");
        assertEquals(630.3499999999999, fitnessTracker.calculateCalorieIntake());
    }

    @Test
    public void testCalculateCalorieIntake2() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.72, 80.0, 22, "female");
        assertEquals(647.6999999999999, fitnessTracker.calculateCalorieIntake());
    }

    @Test
    public void testCalculateCalorieIntake3() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.72, 53.0, 22, "male");
        assertEquals(697.2, fitnessTracker.calculateCalorieIntake());
    }

    @Test
    public void testCalculateCalorieIntake4() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.72, 60.0, 22, "male");
        assertEquals(708.05, fitnessTracker.calculateCalorieIntake());
    }

    @Test
    public void testCalculateCalorieIntake5() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.72, 75.0, 22, "male");
        assertEquals(786.9, fitnessTracker.calculateCalorieIntake());
    }

    @Test
    public void testMain() {
        FitnessTracker fitnessTracker = new FitnessTracker(1.8, 70.0, 20, "male");
        assertEquals(21.604938271604937, fitnessTracker.getBMI());
        assertEquals(0, fitnessTracker.conditionJudge());
        assertEquals(862.75, fitnessTracker.calculateCalorieIntake());
    }
}