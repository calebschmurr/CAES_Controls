/* PressureSensor.h
* A class for reading from a pressure sensor
* Calvin 2021 Senior Design Team 11
*/
#pragma once
#include "sensor.h"


class PressureSensor: public Sensor {

private:

    int pin;
    int baseVal;
    float multiplier;

public:
    PressureSensor();
    PressureSensor(const int pinVal);
    float getValue();

};