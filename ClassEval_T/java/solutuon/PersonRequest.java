package org.example;

public class PersonRequest {
    private String name;
    private String sex;
    private String phoneNumber;

    public PersonRequest(String name, String sex, String phoneNumber) {
        this.name = validateName(name);
        this.sex = validateSex(sex);
        this.phoneNumber = validatePhoneNumber(phoneNumber);
    }

    private String validateName(String name) {
        if (name == null || name.isEmpty() || name.length() > 33) {
            return null;
        }
        return name;
    }

    private String validateSex(String sex) {
        if (sex == null || (!sex.equals("Man") && !sex.equals("Woman") && !sex.equals("UGM"))) {
            return null;
        }
        return sex;
    }

    private String validatePhoneNumber(String phoneNumber) {
        if (phoneNumber == null || phoneNumber.isEmpty() || phoneNumber.length() != 11 || !phoneNumber.matches("\\d{11}")) {
            return null;
        }
        return phoneNumber;
    }

    public String getName() {
        return name;
    }

    public String getSex() {
        return sex;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }
}