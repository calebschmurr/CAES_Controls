/* VoltageSensor.h
* A class for reading from a voltage sensor
* Calvin 2021 Senior Design Team 11
*/

#include "log.h"

class VoltageSensor {
    
private:
    int pin;
    float baseVal = 0.0552f;
    //TODO: Verify the value of the multiplier.
    //TODO: Verify that values are consistent across different runs
    //Not necessarily accurate rn
    float multiplier = 0.0246f;
    Log * l;

public:
    VoltageSensor(const int pinVal);
    float getValue();
    void setLog(Log *_streamObject){ l = _streamObject; l->WriteToLog(2, "Voltage Sensor Stream initiated."); }
    void calibrateSensor();
};
