// PressureSensor.cpp

#include "PressureSensor.h"


PressureSensor::PressureSensor(const int pinVal) {
    pin = pinVal;
    pinMode(pin, INPUT);
}

float PressureSensor::getValue() {
    float value = (analogRead(pin)*multiplier) - baseVal;
    l->WriteToLog(3, (String) value);
    return value;
}
