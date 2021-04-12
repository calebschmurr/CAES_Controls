// PressureSensor.cpp

#include "PressureSensor.h"


PressureSensor::PressureSensor(const int pinVal) {
    pin = pinVal;
    pinMode(pin, INPUT);
}

float PressureSensor::getValue() {
    float value = (analogRead(pin)*multiplier) - baseVal;
    l->WriteToLog(2, (String) value);
    return value;
}

void PressureSensor::calibrateSensor() {
    for (int inc = 0; inc < 15; inc++) {
        baseVal += analogRead(pin);
        delay(100);
    }
    baseVal = baseVal / 15;
    l->WriteToLog(3, "Pressure Sensor: calibration complete.");
    // TODO: improve this algorithm
}
