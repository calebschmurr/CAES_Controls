// CurrentSensor.cpp

#include "CurrentSensor.h"

CurrentSensor::CurrentSensor(const int pinVal) {
    pin = pinVal;
    pinMode(pin, INPUT);
}

float CurrentSensor::getValue() {
    return analogRead(pin) * multiplier - baseVal;
    l->WriteToLog(3, "Current Sensor: reading value.");
}
