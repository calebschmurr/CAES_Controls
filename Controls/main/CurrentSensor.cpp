// CurrentSensor.cpp

#include "CurrentSensor.h"

CurrentSensor::CurrentSensor(const int pinVal) {
    pin = pinVal;
}

float CurrentSensor::getValue() {
    return analogRead(pin)*multiplier;
}

void CurrentSensor::calibrateSensor() {
    for (int inc=0; inc<15; inc++) {
        baseVal+=analogRead(pin);
        delay(100);
    }
    baseVal = baseVal/15;
    l.WriteToLog(3, "Current Sensor calibration complete.");
    // TODO: evaluate this algorithm
}