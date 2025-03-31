import java.util.HashMap;
import java.util.Map;

public class FitnessTracker {
    private double height;
    private double weight;
    private int age;
    private String sex;
    private Map<String, Map<String, int[]>> BMI_std;

    public FitnessTracker(double height, double weight, int age, String sex) {
        this.height = height;
        this.weight = weight;
        this.age = age;
        this.sex = sex;
        this.BMI_std = new HashMap<>();
        BMI_std.put("male", new HashMap<>());
        BMI_std.put("female", new HashMap<>());
        BMI_std.get("male").put("male", new int[]{20, 25});
        BMI_std.get("female").put("female", new int[]{19, 24});
    }

    public double getBMI() {
        return weight / Math.pow(height, 2);
    }

    public int conditionJudge() {
        double BMI = getBMI();
        int[] BMI_range;
        if (sex.equals("male")) {
            BMI_range = BMI_std.get("male").get("male");
        } else {
            BMI_range = BMI_std.get("female").get("female");
        }
        if (BMI > BMI_range[1]) {
            return 1;
        } else if (BMI < BMI_range[0]) {
            return -1;
        } else {
            return 0;
        }
    }

    public double calculateCalorieIntake() {
        double BMR;
        if (sex.equals("male")) {
            BMR = 10 * weight + 6.25 * height - 5 * age + 5;
        } else {
            BMR = 10 * weight + 6.25 * height - 5 * age - 161;
        }
        int condition = conditionJudge();
        if (condition == 1) {
            return BMR * 1.2;
        } else if (condition == -1) {
            return BMR * 1.6;
        } else {
            return BMR * 1.4;
        }
    }
}