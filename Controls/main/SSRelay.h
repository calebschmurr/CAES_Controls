/* SSRelay.h
* A class for controlling the Solid State Relay
* that turns the compressor off and on
* Calvin 2021 Senior Design Team 11
*/


#pragma once
#include <Arduino.h>


class SSRelay {
private:
    int pin;
    enum StatesEnum { Off, On } state;
    // TODO: position tracking and/or ?fully_open

public:
    SSRelay(const int pinVal);
    int on();
    int off();
    StatesEnum GetState();
};