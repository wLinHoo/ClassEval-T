package org.example;

public class BigNumCalculator {

    public static String add(String num1, String num2) {
        int maxLength = Math.max(num1.length(), num2.length());
        num1 = String.format("%" + maxLength + "s", num1).replace(' ', '0');
        num2 = String.format("%" + maxLength + "s", num2).replace(' ', '0');

        int carry = 0;
        StringBuilder result = new StringBuilder();
        for (int i = maxLength - 1; i >= 0; i--) {
            int digitSum = Character.getNumericValue(num1.charAt(i)) + Character.getNumericValue(num2.charAt(i)) + carry;
            carry = digitSum / 10;
            int digit = digitSum % 10;
            result.insert(0, digit);
        }

        if (carry > 0) {
            result.insert(0, carry);
        }

        return result.toString();
    }

    public static String subtract(String num1, String num2) {
        boolean negative = false;
        if (num1.length() < num2.length() || (num1.length() == num2.length() && num1.compareTo(num2) < 0)) {
            String temp = num1;
            num1 = num2;
            num2 = temp;
            negative = true;
        }

        int maxLength = Math.max(num1.length(), num2.length());
        num1 = String.format("%" + maxLength + "s", num1).replace(' ', '0');
        num2 = String.format("%" + maxLength + "s", num2).replace(' ', '0');

        int borrow = 0;
        StringBuilder result = new StringBuilder();
        for (int i = maxLength - 1; i >= 0; i--) {
            int digitDiff = Character.getNumericValue(num1.charAt(i)) - Character.getNumericValue(num2.charAt(i)) - borrow;

            if (digitDiff < 0) {
                digitDiff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result.insert(0, digitDiff);
        }

        while (result.length() > 1 && result.charAt(0) == '0') {
            result.deleteCharAt(0);
        }

        if (negative) {
            result.insert(0, '-');
        }

        return result.toString();
    }

    public static String multiply(String num1, String num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        int[] result = new int[len1 + len2];

        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = Character.getNumericValue(num1.charAt(i)) * Character.getNumericValue(num2.charAt(j));
                int p1 = i + j;
                int p2 = i + j + 1;
                int total = mul + result[p2];

                result[p1] += total / 10;
                result[p2] = total % 10;
            }
        }

        StringBuilder sb = new StringBuilder();
        int start = 0;
        while (start < result.length - 1 && result[start] == 0) {
            start++;
        }

        for (int i = start; i < result.length; i++) {
            sb.append(result[i]);
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(add("12345678901234567890", "98765432109876543210"));
        System.out.println(subtract("12345678901234567890", "98765432109876543210"));
        System.out.println(multiply("12345678901234567890", "98765432109876543210"));
    }
}