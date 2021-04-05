/* Valve.h
* A class for controlling the motorized valve
* on the output of the compressed-air tank
* Calvin 2021 Senior Design Team 11
*/
#pragma once
#include "log.h"

class Valve {
private:
    int openPin;
    int closePin;
    // TODO: position tracking and/or ?fully_open ... not sure that's possible
    Log * l;
    
public:
    Valve(const int openPinVal, const int closePinVal);
    int open();
    int close();
    int hold();
    void setLog(Log *_streamObject){ l = _streamObject; l->WriteToLog(2, "Valve 1 Initialized."); }

};
