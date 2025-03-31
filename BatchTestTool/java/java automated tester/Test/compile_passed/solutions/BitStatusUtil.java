public class BitStatusUtil {

    public static void check(int[] args) {
        for (int arg : args) {
            if (arg < 0) {
                throw new IllegalArgumentException(arg + " must be greater than or equal to 0");
            }
            if (arg % 2 != 0) {
                throw new IllegalArgumentException(arg + " not even");
            }
        }
    }

    public static int add(int states, int stat) {
        check(new int[]{states, stat});
        return states | stat;
    }

    public static boolean has(int states, int stat) {
        check(new int[]{states, stat});
        return (states & stat) == stat;
    }

    public static int remove(int states, int stat) {
        check(new int[]{states, stat});
        if (has(states, stat)) {
            return states ^ stat;
        }
        return states;
    }
}