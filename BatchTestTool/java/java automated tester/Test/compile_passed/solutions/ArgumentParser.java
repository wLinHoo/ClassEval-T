import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.*;

public class ArgumentParser {
    private Map<String, Object> arguments;
    private Set<String> required;
    private Map<String, Class<?>> types;

    public ArgumentParser() {
        this.arguments = new HashMap<>();
        this.required = new HashSet<>();
        this.types = new HashMap<>();
    }

    public void addArgument(String arg, boolean required, Class<?> argType) {
        if (required) {
            this.required.add(arg);
        }
        this.types.put(arg, argType);
    }

    public ParseResult parseArguments(String commandString) {
        String[] args = commandString.split("\\s+");
        for (int i = 1; i < args.length; i++) {  // Start from 1 to skip the program name
            String arg = args[i];
            if (arg.startsWith("--")) {
                String[] keyValue = arg.substring(2).split("=", 2);
                if (keyValue.length == 2) {
                    arguments.put(keyValue[0], convertType(keyValue[0], keyValue[1]));
                } else {
                    arguments.put(keyValue[0], true);
                }
            } else if (arg.startsWith("-")) {
                String key = arg.substring(1);
                if (i + 1 < args.length && !args[i + 1].startsWith("-")) {
                    arguments.put(key, convertType(key, args[i + 1]));
                    i++; // Skip the next element as it is a value
                } else {
                    arguments.put(key, true);
                }
            }
        }

        Set<String> missingArgs = new HashSet<>(required);
        missingArgs.removeAll(arguments.keySet());
        if (!missingArgs.isEmpty()) {
            return new ParseResult(false, missingArgs);
        }

        return new ParseResult(true, null);
    }

    private Object convertType(String arg, String value) {
        Class<?> type = types.get(arg);
        if (type != null) {
            try {
                if (type == Integer.class) {
                    return Integer.parseInt(value);
                } else if (type == Boolean.class) {
                    return Boolean.parseBoolean(value);
                } else if (type == Double.class) {
                    return Double.parseDouble(value);
                }
                // Add more types as needed
            } catch (NumberFormatException e) {
                // Handle the exception, maybe log it or ignore
            }
        }
        return value;
    }

    public void addRequired(String arg) {
        required.add(arg);
    }

    public void addType(String arg, Class<?> type) {
        types.put(arg, type);
    }

    public Object getArgument(String key) {
        return arguments.get(key);
    }

    public static class ParseResult {
        public final boolean success;
        public final Set<String> missingArgs;

        public ParseResult(boolean success, Set<String> missingArgs) {
            this.success = success;
            this.missingArgs = missingArgs;
        }
    }

    public static void main(String[] args) {
        ArgumentParser parser = new ArgumentParser();
        parser.addArgument("example", true, String.class);
    }
}