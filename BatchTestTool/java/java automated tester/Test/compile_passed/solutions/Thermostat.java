import java.time.Instant;
import java.util.Date;
import java.util.Scanner;

public class Thermostat {
    private double currentTemperature;
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
        if (mode.equalsIgnoreCase("heat") || mode.equalsIgnoreCase("cool")) {
            this.mode = mode;
            return true;
        } else {
            return false;
        }
    }

    public void autoSetMode() {
        if (currentTemperature < targetTemperature) {
            mode = "heat";
        } else {
            mode = "cool";
        }
    }

    public boolean autoCheckConflict() {
        if (currentTemperature > targetTemperature) {
            if (mode.equals("cool")) {
                return true;
            } else {
                autoSetMode();
                return false;
            }
        } else {
            if (mode.equals("heat")) {
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
        while (currentTemperature != targetTemperature) {
            if (mode.equals("heat")) {
                currentTemperature += 1;
            } else {
                currentTemperature -= 1;
            }
            useTime++;
        }
        return useTime;
    }
}