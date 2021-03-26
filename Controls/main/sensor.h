/* sensor.h
* A parent class for all of the sensor classes
* Calvin 2021 Senior Design Team 11
*/
#pragma once
#include <Arduino.h>
#include "log.h"

class Sensor {

private:

    int pin;
    float multiplier;
    Log l;

public:
    virtual float getValue(); // Virtual makes a class abstract.
};
