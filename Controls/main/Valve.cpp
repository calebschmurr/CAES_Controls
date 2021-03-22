/* Valve.cpp
* 3/8/21
*/

#include "Valve.h"


Valve::Valve(const int pinVal) {
    l.WriteToLog(3, "Valve Initialized.");
    Serial.println("This_Test");

    pin = pinVal;
}

int Valve::open() {
    // TODO: set gpio pins
    return 0; // Success
}

int Valve::close() {
    // TODO: set gpio pins
    return 0; // Success
}

int Valve::hold() {
    // TODO: set gpio pins
    return 0; // Success
}
