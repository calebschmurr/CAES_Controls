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
    void setLog(Log *_streamObject){ l = _streamObject; l->WriteToLog(2, "Pressure Sensor Stream Initialized."); }
};
