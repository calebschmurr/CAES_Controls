/* PressureSensor.h
* A class for reading from a pressure sensor
* Calvin 2021 Senior Design Team 11
*/
#pragma once
#include "sensor.h"
//#include <unistd.h>


class PressureSensor : public Sensor {

private:

    int pin;
    int baseVal;
    float multiplier;
    Log * l;

public:
    PressureSensor(const int pinVal);
    float getValue();
    void setLog(Log *_streamObject){ l = _streamObject; l->WriteToLog(2, "Pressure Sensor Stream Initialized."); }
    void calibrateSensor();
};
