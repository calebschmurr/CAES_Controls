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


// Define States and Modes as global enumerations
enum States {Off, Charging, Discharging};
enum Modes {Manual, Auto};

class CAESObject {

    private:
        long cycleTime;
        Valve valve1; //Initializer Works
        SSRelay ssRelay1;
        CurrentSensor iSensor; //Initializer Works
        VoltageSensor vSensor;
        PressureSensor pSensor;
        States state;
        Modes mode;
        Log * l;

        int startCharging();
        int stopCharging();
        int forceStopCharging(); //Only to be called when master switch is flipped.
        int startDischarging();
        int stopDischarging();

    public:
        CAESObject();
        int Charge();
        int Discharge();
        int TurnOff();
        void ForceOff();
        const int getState();
        int getPressure();
        void setLog(Log *_streamObject){ l = _streamObject; l->WriteToLog(2, "stream_test"); valve1.setLog(_streamObject); iSensor.setLog(_streamObject); ssRelay1.setLog(_streamObject); pSensor.setLog(_streamObject);}
};
