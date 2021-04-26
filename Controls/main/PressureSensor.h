/* PressureSensor.h
* A class for reading from a pressure sensor
* Calvin 2021 Senior Design Team 11
*/
#pragma once
//#include <unistd.h>
#include "log.h"

class PressureSensor {

private:

    int pin;
    float baseVal = 19.59;
    float multiplier = 0.1861;
    Log * l;

public:
    PressureSensor(const int pinVal);
    float getValue();
    void setLog(Log * logPtr){ l = logPtr; l->WriteToLog(1, "Pressure Sensor logging initiated."); }
};
