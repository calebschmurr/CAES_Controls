//CurrentSensor.h
//Handle current CurrentSensor
//Caleb Schmurr
//2-26-21

class CurrentSensor: public Sensor {
private:
    int pin;
    //TODO: Determine multiplier.
    float multiplier = 0.5;

public:
    CurrentSensor(const int pinVal);
    float getValue();

}