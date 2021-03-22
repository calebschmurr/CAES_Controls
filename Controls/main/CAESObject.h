/* CAESObject.h
* A class for reading from a current sensor
* Calvin 2021 Senior Design Team 11
*/
#pragma once
#include "CurrentSensor.h"
#include "VoltageSensor.h"
#include "PressureSensor.h"
#include "log.h"
#include "Valve.h"
#include "SSRelay.h"
#include "config.h"


    enum States{Off, Charging, Discharging};
    enum Modes{Manual, Auto};


class CAESObject {

    public:
        CAESObject();
        int Charge();
        int Discharge();
        int TurnOff();
        const int getState();
        int getPressure();

    private:
        int cycleTime;
        Valve valve1;
        SSRelay ssRelay1;
        CurrentSensor iSensor;
        VoltageSensor vSensor;
        PressureSensor pSensor;
        //log LogFile;
        States state;
        Modes mode;
        Log l;
        void startCharging();
        void stopCharging();
        void startDischarging();
        void stopDischarging();

};
