/* SSRelay.h
* A class for controlling the Solid State Relay
* that turns the compressor off and on
* Calvin 2021 Senior Design Team 11
*/

#pragma once
#include "log.h"


class SSRelay {
private:

    int pin;
    enum StatesEnum { Off, On } state;
    // TODO: position tracking and/or ?fully_open
    Log * l;
    
public:
    SSRelay(const int pinVal);
    int on();
    int off();
    void setLog(Log * logPtr){ l = logPtr; l->WriteToLog(1, "SSR logging initiated."); }
};
