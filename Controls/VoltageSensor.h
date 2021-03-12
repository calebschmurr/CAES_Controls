//VoltageSensor.h
//Handle voltage sensor.

#include "sensor.h"

class VoltageSensor: public Sensor {
private:
    int pin;
    int baseVal;
    //TODO: Verify the value of the multiplier.
    //TODO: Verify that values are consistent across different runs
    //Not necessarily accurate rn
    float multiplier = 0.0248868f;

public:
    VoltageSensor(const int pinVal);
    float getValue();
};