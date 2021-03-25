// SSRelay.cpp

#include "SSRelay.h"


SSRelay::SSRelay(const int pinVal) {
    pin = pinVal;
    state = Off;
    digitalWrite(pin, LOW); // Is this needed?
    l.WriteToLog(3, "SSR: initialized and set to Off.");
};

int SSRelay::on() {
    state = On;
    digitalWrite(pin, HIGH);
    l.WriteToLog(3, "SSR: Set to On.");
    return 0; // Success
};

int SSRelay::off() {
    state = Off;
    digitalWrite(pin, LOW);
    l.WriteToLog(3, "SSR: Set to Off.");
    return 0; // Success
};
