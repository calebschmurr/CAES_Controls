

#include "sensor.h"

class PressureSensor: public Sensor {

private:

    int pin;
    int baseVal;
    float multiplier;

public:
    PressureSensor(const int pinVal);
    float getValue();

}