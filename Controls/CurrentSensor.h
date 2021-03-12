//CurrentSensor.h
//Handle current CurrentSensor
//Caleb Schmurr
//2-26-21
#include "sensor.h"
#include <Arduino.h>

class CurrentSensor: public Sensor {
private:
    int pin;
    //TODO: Determine multiplier.
    float multiplier = 0.5f;

public:
    CurrentSensor(const int pinVal);
    float getValue();

};