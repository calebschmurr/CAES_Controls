/* VoltageSensor.h
* A class for reading from a voltage sensor
* Calvin 2021 Senior Design Team 11
*/

#include "sensor.h"


class VoltageSensor: public Sensor {
private:
    int pin;
    int baseVal;
    //TODO: Verify the value of the multiplier.
    //TODO: Verify that values are consistent across different runs
    //Not necessarily accurate rn
    float multiplier = 0.0248868f;
    Log * l;

public:
    VoltageSensor(const int pinVal);
    float getValue();
    void setLog(Log *_streamObject){ l = _streamObject; l->WriteToLog(2, "Voltage Sensor Stream initiated."); }
    void calibrateSensor();
};
