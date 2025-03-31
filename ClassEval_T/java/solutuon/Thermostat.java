package org.example;

import java.util.Objects;

public class Thermostat {
    double currentTemperature;
    private double targetTemperature;
    private String mode;

    public Thermostat(double currentTemperature, double targetTemperature, String mode) {
        this.currentTemperature = currentTemperature;
        this.targetTemperature = targetTemperature;
        this.mode = mode;
    }

    public double getTargetTemperature() {
        return targetTemperature;
    }

    public void setTargetTemperature(double temperature) {
        this.targetTemperature = temperature;
    }

    public String getMode() {
        return mode;
    }

    public boolean setMode(String mode) {
        if (Objects.equals(mode, "heat") || Objects.equals(mode, "cool")) {
            this.mode = mode;
            return true;
        } else {
            return false;
        }
    }

    public void autoSetMode() {
        if (currentTemperature < targetTemperature) {
            this.mode = "heat";
        } else {
            this.mode = "cool";
        }
    }

    public boolean autoCheckConflict() {
        if (currentTemperature > targetTemperature) {
            if (Objects.equals(mode, "cool")) {
                return true;
            } else {
                autoSetMode();
                return false;
            }
        } else {
            if (Objects.equals(mode, "heat")) {
                return true;
            } else {
                autoSetMode();
                return false;
            }
        }
    }

    public int simulateOperation() {
        autoSetMode();
        int useTime = 0;
        if (Objects.equals(mode, "heat")) {
            while (currentTemperature < targetTemperature) {
                currentTemperature += 1;
                useTime += 1;
            }
        } else {
            while (currentTemperature > targetTemperature) {
                currentTemperature -= 1;
                useTime += 1;
            }
        }
        return useTime;
    }
}