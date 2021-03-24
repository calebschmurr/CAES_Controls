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
        Log l;

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
        void setSerial(Stream *_streamObject){ l.setStream(_streamObject); l.WriteToLog(2, "stream_test"); valve1.setSerial(_streamObject); iSensor.setSerial(_streamObject); ssRelay1.setSerial(_streamObject); 
            vSensor.setSerial(_streamObject); pSensor.setSerial(_streamObject);}

};
