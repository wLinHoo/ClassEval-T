package org.example;

import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;
import java.util.List;

public class SignInSystem {
    private Map<String, Boolean> users;

    public SignInSystem() {
        this.users = new HashMap<>();
    }

    public boolean addUser(String username) {
        if (users.containsKey(username)) {
            return false;
        } else {
            users.put(username, false);
            return true;
        }
    }

    public boolean signIn(String username) {
        if (!users.containsKey(username)) {
            return false;
        } else {
            users.put(username, true);
            return true;
        }
    }

    public boolean checkSignIn(String username) {
        if (!users.containsKey(username)) {
            return false;
        } else {
            return users.get(username);
        }
    }

    public boolean allSignedIn() {
        for (boolean signedIn : users.values()) {
            if (!signedIn) {
                return false;
            }
        }
        return true;
    }

    public List<String> allNotSignedIn() {
        List<String> notSignedInUsers = new ArrayList<>();
        for (Map.Entry<String, Boolean> entry : users.entrySet()) {
            if (!entry.getValue()) {
                notSignedInUsers.add(entry.getKey());
            }
        }
        return notSignedInUsers;
    }
}