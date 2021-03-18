// CAESObject.cpp

#include "CAESObject.h"
#include "CurrentSensor.h"
#include "VoltageSensor.h"
#include "PressureSensor.h"
#include "log.h"
#include "Valve.h"
#include "SSRelay.h"
#include "config.h"


CAESObject::CAESObject() {
    cycleTime = 0;
    logFile = Log(); // TODO: use correct constructor
    valve1 = Valve(Valve_Pin);
    ssRelay1 = SSRelay(Solid_State_Relay_Pin);
    iSensor = CurrentSensor(Current_Sensor_Pin);
    vSensor = VoltageSensor(Voltage_Sensor_Pin);
    pSensor = PressureSensor(Pressure_Sensor_Pin);
    state = Off;
}

void CAESObject::startCharging() {
    if (cycleTime > Min_Cycle_Time) {
        ssRelay1.on();
        cycleTime = 0;
        state = Charging;
    }
}

void CAESObject::stopCharging() {
    if (cycleTime > Min_Cycle_Time) {
        ssRelay1.off();
        cycleTime = 0;
        state = Off;
    }
}

void CAESObject::startDischarging() {
    valve1.open();
    state = Discharging;
}

void CAESObject::stopDischarging() {
    valve1.close();
}

int CAESObject::Charge() {
    switch (state) {
        case Discharging :
            stopDischarging();
            if (pSensor.getValue() < max_pressure_auto) {
                startCharging();
            } break;
        case Charging :
            if (pSensor.getValue() >= max_pressure_auto) {
                stopCharging();
            } break;
        case Off :
            if (pSensor.getValue() < max_pressure_auto) {
                startCharging();
            } break;
    }
    return o; // Success
}

int CAESObject::Discharge() {
    int voltage = vSensor.getValue();
    switch (state) {
        case Discharging :
            stopDischarging();
            if (voltage < "voltage_lower_bound") { // TODO: define these as variables?
                valve1.open();
            } else if (voltage > "voltage_upper bound") { // I used a string so that it is red and we remember to change it
                valve1.close();
            } else {
                valve1.hold();
            } break;
        case Charging :
            stopCharging();
            startDischarging();
            break;
        case Off :
            startDischarging();
            break;
    }
    return o; // Success
}

int CAESObject::TurnOff() {
    switch (state) {
        case Discharging :
            stopDischarging();
            break;
        case Charging :
            stopCharging();
            break;
    }
    return o; // Success
}