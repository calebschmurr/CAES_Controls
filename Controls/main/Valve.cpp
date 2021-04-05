/* Valve.cpp
* 3/8/21
*/

#include "Valve.h"


Valve::Valve(const int openPinVal, const int closePinVal) {
    openPin = valve_open_pin;
    closePin = valve_close_pin;
}

int Valve::open() {
    digitalWrite(openPin, HIGH);
    digitalWrite(closePin, LOW);
    l->WriteToLog(3, "Valve: set to open.");
    return 0; // Success
}

int Valve::close() {
    digitalWrite(openPin, LOW);
    digitalWrite(closePin, HIGH);
    l->WriteToLog(3, "Valve: set to close.");
    return 0; // Success
}

int Valve::hold() {
    digitalWrite(openPin, LOW);
    digitalWrite(closePin, LOW);
    l->WriteToLog(3, "Valve: set to hold.");
    return 0; // Success
}
