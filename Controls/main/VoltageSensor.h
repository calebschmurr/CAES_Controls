/* VoltageSensor.h
* A class for reading from a voltage sensor
* Calvin 2021 Senior Design Team 11
*/

#include "log.h"

class VoltageSensor {
    
private:
    int pin;
    float baseVal = 0.0552f;
    float multiplier = 0.0246f;
    Log * l;

public:
    VoltageSensor(const int pinVal);
    float getValue();
    void setLog(Log * logPtr){ l = logPtr; l->WriteToLog(1, "Voltage Sensor logging initiated."); }
};
