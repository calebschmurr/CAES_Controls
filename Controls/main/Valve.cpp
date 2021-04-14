/* Valve.cpp
* 3/8/21
*/

#include "Valve.h"


Valve::Valve(const int openPinVal, const int closePinVal) {
    openPin = valve_open_pin;
    closePin = valve_close_pin;
    pinMode(openPin, OUTPUT);
    pinMode(closePin, OUTPUT);
    digitalWrite(openPin, HIGH);
    digitalWrite(closePin, HIGH);
}

int Valve::open() {
    digitalWrite(openPin, LOW);
    digitalWrite(closePin, HIGH);
    l->WriteToLog(2, "Valve: set to open.");
    return 0; // Success
}

int Valve::close() {
    digitalWrite(openPin, HIGH);
    digitalWrite(closePin, LOW);
    l->WriteToLog(2, "Valve: set to close.");
    return 0; // Success
}

int Valve::hold() {
    digitalWrite(openPin, HIGH);
    digitalWrite(closePin, HIGH);
    l->WriteToLog(2, "Valve: set to hold.");
    return 0; // Success
}
