public class AccessGatewayFilter {
    // User class
    public static class User {
        private String name;
        private int level;
        private String address;

        // Getters and setters
        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public int getLevel() {
            return level;
        }

        public void setLevel(int level) {
            this.level = level;
        }

        public String getAddress() {
            return address;
        }

        public void setAddress(String address) {
            this.address = address;
        }
    }

    // Authorization class
    public static class Authorization {
        private User user;
        private String jwt;

        // Getters and setters
        public User getUser() {
            return user;
        }

        public void setUser(User user) {
            this.user = user;
        }

        public String getJwt() {
            return jwt;
        }

        public void setJwt(String jwt) {
            this.jwt = jwt;
        }
    }

    // Request class
    public static class Request {
        private String path;
        private String method;
        private Authorization auth;

        // Getters and setters
        public String getPath() {
            return path;
        }

        public void setPath(String path) {
            this.path = path;
        }

        public String getMethod() {
            return method;
        }

        public void setMethod(String method) {
            this.method = method;
        }

        public Authorization getAuth() {
            return auth;
        }

        public void setAuth(Authorization auth) {
            this.auth = auth;
        }
    }

    // Constructor
    public AccessGatewayFilter() {
    }

    // Methods
    public boolean filter(Request request) {
        String requestUri = request.getPath();
        String method = request.getMethod();

        if (isStartWith(requestUri)) {
            return true;
        }

        try {
            Authorization token = getJwtUser(request);
            User user = token.getUser();
            if (user.getLevel() > 2) {
                setCurrentUserInfoAndLog(user);
                return true;
            }
        }
        catch (Exception e) {
            return false;
        }
        return false;
    }

    public Authorization getJwtUser(Request request) {
        Authorization token = request.getAuth();
        User user = token.getUser();

        // Check if JWT token starts with username
        if (token.getJwt().indexOf(user.getName()) == 0) {
            String jwtStrDate = token.getJwt().substring(user.getName().length());

            // Parse JWT timestamp
            long jwtTimestamp;
            try {
                jwtTimestamp = Long.parseLong(jwtStrDate.trim());
            } catch (NumberFormatException e) {
                // Return empty Authorization if parsing fails
                return new Authorization();
            }

            // Get current time
            long now = System.currentTimeMillis() / 1000; // Convert to seconds

            // Check if token has expired (3 days)
            if ((now - jwtTimestamp) >= 3 * 24 * 60 * 60) { // 3 days in seconds
                return new Authorization();
            }
        }
        return token;
    }

    private static final String[] START_WITH = {"/api", "/login"};

    public boolean isStartWith(String requestUri) {
        for (String s : START_WITH) {
            if (requestUri.startsWith(s)) {
                return true;
            }
        }
        return false;
    }

    public void setCurrentUserInfoAndLog(User user) {
        System.out.println(user.getName() + " " + user.getAddress() + " " + System.currentTimeMillis()/1000L);
    }
}