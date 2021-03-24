// PressureSensor.cpp
#pragma once
#include <Arduino.h>
#include "PressureSensor.h"
#include <unistd.h>

PressureSensor::PressureSensor(const int pinVal){
    pin = pinVal;
    pinMode(pin, INPUT);

}

float PressureSensor::getValue(){
    return analogRead(pin)-baseVal;
}

void PressureSensor::CalibrateSensor(){
    for (int inc=0; inc<15; inc++){
        baseVal+=analogRead(pin);
        delay(100);
    }
    baseVal = baseVal/15;

}
