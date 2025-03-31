package org.example;

public class BitStatusUtil {

    public static int add(int states, int stat) {
        check(states, stat);
        return states | stat;
    }

    public static boolean has(int states, int stat) {
        check(states, stat);
        return (states & stat) == stat;
    }

    public static int remove(int states, int stat) {
        check(states, stat);
        if (has(states, stat)) {
            return states ^ stat;
        }
        return states;
    }

    public static void check(int... args) {
        for (int arg : args) {
            if (arg < 0) {
                throw new IllegalArgumentException(arg + " must be greater than or equal to 0");
            }
            if (arg % 2 != 0) {
                throw new IllegalArgumentException(arg + " not even");
            }
        }
    }

    public static void main(String[] args) {
        System.out.println(add(2, 4));
        System.out.println(has(6, 2));
        System.out.println(remove(6, 2));
        try {
            check(2, 3, 4);
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }
}