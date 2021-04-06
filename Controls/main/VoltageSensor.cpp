//VoltageSensor.cpp

#include "VoltageSensor.h"


VoltageSensor::VoltageSensor(const int pinVal) {
    pin = pinVal;
}

float VoltageSensor::getValue() {
    return analogRead(pin) * multiplier - baseVal;
    l->WriteToLog(3, "Voltage Sensor: reading value.");
}

void VoltageSensor::calibrateSensor() {
    for (int inc = 0; inc < 15; inc++) {
        baseVal += analogRead(pin);
        delay(100);
    }
    baseVal = baseVal / 15;
    l->WriteToLog(3, "Voltage Sensor: calibration complete.");
    // TODO: improve this algorithm
}