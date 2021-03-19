// CAESObject.cpp

#pragma once
#include "CAESObject.h"



CAESObject::CAESObject() : valve1(valve_pin), ssRelay1(current_sensor_pin),
        iSensor(current_sensor_pin), vSensor(voltage_sensor_pin),
        pSensor(pressure_sensor_pin) {
    cycleTime = 0;
    // TODO: use correct constructor (Fixed 3/18/21)


    state = Off;
}

const int CAESObject::getState(){
    return state;
}

int CAESObject::getPressure(){
    return pSensor.getValue();
}

void CAESObject::startCharging() {
    if (cycleTime > min_cycle_time) {
        ssRelay1.on();
        cycleTime = 0;
        state = Charging;
    }
}

void CAESObject::stopCharging() {
    if (cycleTime > min_cycle_time) {
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
    return 0; // Success
}

int CAESObject::Discharge() {
    int voltage = vSensor.getValue();
    switch (state) {
        case Discharging :
            stopDischarging();
            if (voltage < voltage_lower_bound) { 
                valve1.open();
            } else if (voltage > voltage_upper_bound) { // I used a string so that it is red and we remember to change it
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
    return 0; // Success
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
    return 0; // Success
}