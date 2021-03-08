// SSRelay.cpp

#include "SSRelay.h"

SSRelay::SSRelay(const int pinVal) {
    pin = pinVal;
    state = false;
};

int SSRelay::SetState(bool stateVal) {
    state = stateVal;
    return 0; // Success
};

bool SSRelay::GetState() {
    return state;
};