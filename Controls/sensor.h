/* sensor.h
* A parent class for all of the sensor classes
* Calvin 2021 Senior Design Team 11
*/

class Sensor {

private:

    int pin;
    float multiplier;

public:
    virtual float getValue(); //Virtual makes a class abstract.
};