//CurrentSensor.h

#include "CurrentSensor.h"

CurrentSensor::CurrentSensor(const int pinVal){
    pin = pinVal;
}

float CurrentSensor::getValue(){
    return analogRead(pin)*multiplier;

}