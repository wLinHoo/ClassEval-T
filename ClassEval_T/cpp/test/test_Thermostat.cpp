#include <gtest/gtest.h>
#include "pch.h" 

class ThermostatTestGetTargetTemperature : public ::testing::Test {
protected:
    Thermostat t;
    ThermostatTestGetTargetTemperature() : t(20, 25, "heat") {}
};

TEST_F(ThermostatTestGetTargetTemperature, test_get_target_temperature_1) {
    t = Thermostat(20, 25, "heat");
    EXPECT_EQ(t.get_target_temperature(), 25);
}

TEST_F(ThermostatTestGetTargetTemperature, test_get_target_temperature_2) {
    t = Thermostat(20, 25, "cool");
    EXPECT_EQ(t.get_target_temperature(), 25);
}

TEST_F(ThermostatTestGetTargetTemperature, test_get_target_temperature_3) {
    t = Thermostat(20, 25, "test");
    EXPECT_EQ(t.get_target_temperature(), 25);
}

TEST_F(ThermostatTestGetTargetTemperature, test_get_target_temperature_4) {
    t = Thermostat(25, 25, "cool");
    EXPECT_EQ(t.get_target_temperature(), 25);
}

TEST_F(ThermostatTestGetTargetTemperature, test_get_target_temperature_5) {
    t = Thermostat(25, 25, "heat");
    EXPECT_EQ(t.get_target_temperature(), 25);
}

class ThermostatTestSetTargetTemperature : public ::testing::Test {
protected:
    Thermostat t;
    ThermostatTestSetTargetTemperature() : t(20, 25, "heat") {}
};

TEST_F(ThermostatTestSetTargetTemperature, test_set_target_temperature_1) {
    t = Thermostat(20, 25, "heat");
    t.set_target_temperature(30);
    EXPECT_EQ(t.get_target_temperature(), 30);
}

TEST_F(ThermostatTestSetTargetTemperature, test_set_target_temperature_2) {
    t = Thermostat(20, 25, "cool");
    t.set_target_temperature(10);
    EXPECT_EQ(t.get_target_temperature(), 10);
}

TEST_F(ThermostatTestSetTargetTemperature, test_set_target_temperature_3) {
    t = Thermostat(20, 25, "test");
    t.set_target_temperature(10);
    EXPECT_EQ(t.get_target_temperature(), 10);
}

TEST_F(ThermostatTestSetTargetTemperature, test_set_target_temperature_4) {
    t = Thermostat(25, 25, "cool");
    t.set_target_temperature(10);
    EXPECT_EQ(t.get_target_temperature(), 10);
}

TEST_F(ThermostatTestSetTargetTemperature, test_set_target_temperature_5) {
    t = Thermostat(25, 25, "heat");
    t.set_target_temperature(10);
    EXPECT_EQ(t.get_target_temperature(), 10);
}

class ThermostatTestGetMode : public ::testing::Test {
protected:
    Thermostat t;
    ThermostatTestGetMode() : t(20, 25, "heat") {}
};

TEST_F(ThermostatTestGetMode, test_get_mode_1) {
    t = Thermostat(20, 25, "heat");
    EXPECT_EQ(t.get_mode(), "heat");
}

TEST_F(ThermostatTestGetMode, test_get_mode_2) {
    t = Thermostat(20, 25, "cool");
    EXPECT_EQ(t.get_mode(), "cool");
}

TEST_F(ThermostatTestGetMode, test_get_mode_3) {
    t = Thermostat(20, 25, "test");
    EXPECT_EQ(t.get_mode(), "test");
}

TEST_F(ThermostatTestGetMode, test_get_mode_4) {
    t = Thermostat(25, 25, "cool");
    EXPECT_EQ(t.get_mode(), "cool");
}

TEST_F(ThermostatTestGetMode, test_get_mode_5) {
    t = Thermostat(25, 25, "heat");
    EXPECT_EQ(t.get_mode(), "heat");
}

class ThermostatTestSetMode : public ::testing::Test {
protected:
    Thermostat t;
    ThermostatTestSetMode() : t(20, 25, "heat") {}
};

TEST_F(ThermostatTestSetMode, test_set_mode_1) {
    t = Thermostat(20, 25, "heat");
    t.set_mode("cool");
    EXPECT_EQ(t.get_mode(), "cool");
}

TEST_F(ThermostatTestSetMode, test_set_mode_2) {
    t = Thermostat(20, 25, "heat");
    EXPECT_FALSE(t.set_mode("test"));
}

TEST_F(ThermostatTestSetMode, test_set_mode_3) {
    t = Thermostat(20, 25, "cool");
    t.set_mode("heat");
    EXPECT_EQ(t.get_mode(), "heat");
}

TEST_F(ThermostatTestSetMode, test_set_mode_4) {
    t = Thermostat(20, 25, "test");
    t.set_mode("heat");
    EXPECT_EQ(t.get_mode(), "heat");
}

TEST_F(ThermostatTestSetMode, test_set_mode_5) {
    t = Thermostat(25, 25, "cool");
    t.set_mode("heat");
    EXPECT_EQ(t.get_mode(), "heat");
}

class ThermostatTestAutoSetMode : public ::testing::Test {
protected:
    Thermostat t;
    ThermostatTestAutoSetMode() : t(20, 25, "heat") {}
};

TEST_F(ThermostatTestAutoSetMode, test_auto_set_mode_1) {
    t = Thermostat(20, 25, "heat");
    t.auto_set_mode();
    EXPECT_EQ(t.get_mode(), "heat");
}

TEST_F(ThermostatTestAutoSetMode, test_auto_set_mode_2) {
    t = Thermostat(25, 20, "heat");
    t.auto_set_mode();
    EXPECT_EQ(t.get_mode(), "cool");
}

TEST_F(ThermostatTestAutoSetMode, test_auto_set_mode_3) {
    t = Thermostat(25, 20, "cool");
    t.auto_set_mode();
    EXPECT_EQ(t.get_mode(), "cool");
}

TEST_F(ThermostatTestAutoSetMode, test_auto_set_mode_4) {
    t = Thermostat(20, 25, "cool");
    t.auto_set_mode();
    EXPECT_EQ(t.get_mode(), "heat");
}

TEST_F(ThermostatTestAutoSetMode, test_auto_set_mode_5) {
    t = Thermostat(25, 25, "cool");
    t.auto_set_mode();
    EXPECT_EQ(t.get_mode(), "cool");
}

class ThermostatTestAutoCheckConflict : public ::testing::Test {
protected:
    Thermostat t;
    ThermostatTestAutoCheckConflict() : t(30, 25, "cool") {}
};

TEST_F(ThermostatTestAutoCheckConflict, test_auto_check_conflict_1) {
    t = Thermostat(30, 25, "cool");
    EXPECT_TRUE(t.auto_check_conflict());
}

TEST_F(ThermostatTestAutoCheckConflict, test_auto_check_conflict_2) {
    t = Thermostat(30, 25, "heat");
    EXPECT_FALSE(t.auto_check_conflict());
    EXPECT_EQ(t.get_mode(), "cool");
}

TEST_F(ThermostatTestAutoCheckConflict, test_auto_check_conflict_3) {
    t = Thermostat(25, 30, "heat");
    EXPECT_TRUE(t.auto_check_conflict());
}

TEST_F(ThermostatTestAutoCheckConflict, test_auto_check_conflict_4) {
    t = Thermostat(25, 30, "cool");
    EXPECT_FALSE(t.auto_check_conflict());
    EXPECT_EQ(t.get_mode(), "heat");
}

TEST_F(ThermostatTestAutoCheckConflict, test_auto_check_conflict_5) {
    t = Thermostat(25, 25, "cool");
    EXPECT_FALSE(t.auto_check_conflict());
    EXPECT_EQ(t.get_mode(), "cool");
}

class ThermostatTestSimulateOperation : public ::testing::Test {
protected:
    Thermostat t;
    ThermostatTestSimulateOperation() : t(20, 25, "heat") {}
};

TEST_F(ThermostatTestSimulateOperation, test_simulate_operation_1) {
    t = Thermostat(20, 25, "heat");
    EXPECT_EQ(t.simulate_operation(), 5);
    EXPECT_EQ(t.get_mode(), "heat");
    EXPECT_EQ(t.current_temperature, 25);
}

TEST_F(ThermostatTestSimulateOperation, test_simulate_operation_2) {
    t = Thermostat(25.7, 20, "cool");
    EXPECT_EQ(t.simulate_operation(), 6);
    EXPECT_EQ(t.get_mode(), "cool");
    EXPECT_EQ(t.current_temperature, 19.7);
}

TEST_F(ThermostatTestSimulateOperation, test_simulate_operation_3) {
    t = Thermostat(25, 25, "heat");
    EXPECT_EQ(t.simulate_operation(), 0);
    EXPECT_EQ(t.get_mode(), "cool");
    EXPECT_EQ(t.current_temperature, 25);
}

TEST_F(ThermostatTestSimulateOperation, test_simulate_operation_4) {
    t = Thermostat(25, 25, "cool");
    EXPECT_EQ(t.simulate_operation(), 0);
    EXPECT_EQ(t.get_mode(), "cool");
    EXPECT_EQ(t.current_temperature, 25);
}

TEST_F(ThermostatTestSimulateOperation, test_simulate_operation_5) {
    t = Thermostat(25, 25, "test");
    EXPECT_EQ(t.simulate_operation(), 0);
    EXPECT_EQ(t.get_mode(), "cool");
    EXPECT_EQ(t.current_temperature, 25);
}

class ThermostatTestMain : public ::testing::Test {
protected:
    Thermostat t;
    ThermostatTestMain() : t(20, 37.5, "cool") {}
};

TEST_F(ThermostatTestMain, test_main) {
    t = Thermostat(20, 37.5, "cool");
    EXPECT_EQ(t.get_target_temperature(), 37.5);

    t.set_target_temperature(37.6);
    EXPECT_EQ(t.get_target_temperature(), 37.6);

    EXPECT_EQ(t.get_mode(), "cool");
    EXPECT_FALSE(t.set_mode("test"));

    EXPECT_FALSE(t.auto_check_conflict());
    EXPECT_EQ(t.get_mode(), "heat");
    EXPECT_EQ(t.simulate_operation(), 18);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}