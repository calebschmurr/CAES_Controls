// SSRelay.cpp

#include "SSRelay.h"


SSRelay::SSRelay(const int pinVal) {
    pin = pinVal;
    state = Off;
};

int SSRelay::on() {
    state = On;
    l.WriteToLog(3, "SSR Set to On.");
    // TODO: set gpio pin
    return 0; // Success
};

int SSRelay::off() {
    state = Off;
    // TODO: set gpio pin
    return 0; // Success
};


SSRelay::StatesEnum SSRelay::GetState() { // Our flowchart does not require this method
    return state;
};
