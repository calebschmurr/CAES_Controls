//VoltageSensor.cpp
#include "VoltageSensor.h"

VoltageSensor::VoltageSensor(const int pinVal) {
    pin = pinVal;
}

float VoltageSensor::getValue() {
    return analogRead(pin)*multiplier;
}

void VoltageSensor::calibrateSensor() {
    for (int inc=0; inc<15; inc++) {
        baseVal+=analogRead(pin);
        delay(100);
    }
    baseVal = baseVal/15;
    l.WriteToLog(3, "Voltage Sensor calibration complete.");
    // TODO: evaluate this algorithm
}