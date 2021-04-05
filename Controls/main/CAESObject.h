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

    private:
        int cycleTime;
        Valve valve1;
        SSRelay ssRelay1;
        CurrentSensor iSensor;
        VoltageSensor vSensor;
        PressureSensor pSensor;
        States state;
        Modes mode;
        Log * l;

        void startCharging();
        void stopCharging();
        void startDischarging();
        void stopDischarging();


    public:
        CAESObject();
        int Charge();
        int Discharge();
        int TurnOff();
        const int getState();
        int getPressure();
        // Can we put the definition of this function in .cpp?
        
        void setLog(Log *_streamObject){ l = _streamObject; l->WriteToLog(2, "stream_test"); valve1.setLog(_streamObject); iSensor.setLog(_streamObject); ssRelay1.setLog(_streamObject); 
            vSensor.setLog(_streamObject); pSensor.setLog(_streamObject);}

};
