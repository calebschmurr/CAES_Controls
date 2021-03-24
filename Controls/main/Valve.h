/* Valve.h
* A class for controlling the motorized valve
* on the output of the compressed-air tank
* Calvin 2021 Senior Design Team 11
*/
#pragma once
#include "log.h"

class Valve {
private:
    int pin;
    // TODO: position tracking and/or ?fully_open ... not sure that's possible
    Log l;
public:
    Valve(const int pinVal);
    int open();
    int close();
    int hold();
    void setSerial(Stream *_streamObject){ l.setStream(_streamObject); l.WriteToLog(2, "Valve 1 Initialized."); }

};
