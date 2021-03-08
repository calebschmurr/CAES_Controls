//Sensor class - 
//Used to define the format for the rest of the sensors


class Sensor{

private:

int pin;

float multiplier;

public:
virtual float getValue();//Virtual makes a class abstract.

};