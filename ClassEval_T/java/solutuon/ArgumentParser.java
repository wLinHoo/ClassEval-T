package org.example;

import java.util.*;

public class ArgumentParser {
    Map<String, Object> arguments;
    Set<String> required;
    Map<String, Class<?>> types;

    public ArgumentParser() {
        this.arguments = new HashMap<>();
        this.required = new HashSet<>();
        this.types = new HashMap<>();
    }

    public Tuple<Boolean, Set<String>> parseArguments(String commandString) {
        String[] args = commandString.split("\\s+");
        for (int i = 1; i < args.length; i++) {
            String arg = args[i];
            if (arg.startsWith("--")) {
                String[] keyValue = arg.substring(2).split("=");
                if (keyValue.length == 2) {
                    arguments.put(keyValue[0], convertType(keyValue[0], keyValue[1]));
                }
                else {
                    arguments.put(keyValue[0], true);
                }
            }
            else if (arg.startsWith("-")) {
                String key = arg.substring(1);
                if (i + 1 < args.length && !args[i + 1].startsWith("-")) {
                    arguments.put(key, convertType(key, args[i + 1]));
                    i++;
                }
                else {
                    arguments.put(key, true);
                }
            }
        }
        Set<String> missingArgs = new HashSet<>(required);
        missingArgs.removeAll(arguments.keySet());
        if (!missingArgs.isEmpty()) {
            return new Tuple<>(false, missingArgs);
        }
        return new Tuple<>(true, null);
    }

    public Object getArgument(String key) {
        return arguments.get(key);
    }

    public void addArgument(String arg, boolean required, Class<?> argType) {
        if (required) {
            this.required.add(arg);
        }
        this.types.put(arg, argType);
    }

    Object convertType(String arg, String value) {
        try {
            Class<?> type = types.get(arg);
            if (type == Integer.class) {
                return Integer.parseInt(value);
            }
            else if (type == Boolean.class) {
                return Boolean.parseBoolean(value);
            }
            else if (type == String.class) {
                return value;
            }
        } catch (Exception e) {
            return value;
        }
        return value;
    }

    public static class Tuple<X, Y> {
        public final X x;
        public final Y y;

        public Tuple(X x, Y y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) {
        ArgumentParser parser = new ArgumentParser();
        parser.addArgument("arg1", true, Integer.class);
        parser.addArgument("arg2", false, String.class);
        parser.addArgument("option1", false, Boolean.class);
        parser.addArgument("option2", false, Boolean.class);

        Tuple<Boolean, Set<String>> result = parser.parseArguments("python script.py --arg1=123 -arg2 value2 --option1 -option2");
        System.out.println(result.x);
        System.out.println(result.y);
        System.out.println(parser.arguments);
    }
}