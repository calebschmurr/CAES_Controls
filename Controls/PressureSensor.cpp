// PressureSensor.cpp
#pragma once
#include "PressureSensor.h"


PressureSensor::PressureSensor(const int pinVal){
    pin = pinVal;
    pinMode(pin, INPUT);
    delay(300);
    for (int inc=0; inc<15; inc++){
        baseVal+=analogRead(pin);
        delay(100);
    }
    baseVal = baseVal/15;

}

float PressureSensor::getValue(){
    return analogRead(pin)-baseVal;
}