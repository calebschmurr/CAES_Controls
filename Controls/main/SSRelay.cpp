// SSRelay.cpp

#include "SSRelay.h"


SSRelay::SSRelay(const int pinVal) {
    pin = pinVal;
    state = Off;
    l.WriteToLog(3, "SSR initialized and set to Off.");
};

int SSRelay::on() {
    state = On;
    l.WriteToLog(3, "SSR Set to On.");
    // TODO: set gpio pin
    return 0; // Success
};

int SSRelay::off() {
    state = Off;
    l.WriteToLog(3, "SSR Set to Off.");
    // TODO: set gpio pin
    return 0; // Success
};
