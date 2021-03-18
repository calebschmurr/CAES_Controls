/* CurrentSensor.h
* A class for reading from a current sensor
* Calvin 2021 Senior Design Team 11
*/

#include "sensor.h"


class CurrentSensor: public Sensor {
private:
    int pin;
    //TODO: Determine multiplier.
    float multiplier = 0.5f;

public:
    CurrentSensor(const int pinVal);
    float getValue();
    
};