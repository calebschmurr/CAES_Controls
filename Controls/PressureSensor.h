/* PressureSensor.h
* A class for reading from a pressure sensor
* Calvin 2021 Senior Design Team 11
*/

#include "sensor.h"


class PressureSensor: public Sensor {

private:

    int pin;
    int baseVal;
    float multiplier;

public:
    PressureSensor(const int pinVal);
    float getValue();

};