//VoltageSensor.cpp

#include "VoltageSensor.h"


VoltageSensor::VoltageSensor(const int pinVal) {
    pin = pinVal;
    pinMode(pin, INPUT);
}

float VoltageSensor::getValue() {
    //int retInt = analogRead(pin)*multiplier - baseVal;
    //String retString = "Voltage Sensor: reading value.";
    //retString = retString + retInt;
    //l->WriteToLog(3, "Voltage Sensor: reading value." + (analogRead(pin)*multiplier-baseVal));
      //l->WriteToLog(2, retString);
      return analogRead(pin) * multiplier - baseVal;
    
}

void VoltageSensor::calibrateSensor() {
    for (int inc = 0; inc < 15; inc++) {
        baseVal += analogRead(pin);
        delay(100);
    }
    baseVal = baseVal / 15;
    l->WriteToLog(3, "Voltage Sensor: calibration complete.");
    // TODO: improve this algorithm
}
