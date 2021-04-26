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
#include <AutoPID.h>


// Define States and Modes as global enumerations
enum States {Off, Charging, Discharging};
enum Modes {Manual, Auto};

class CAESObject {

    private:
        long cycleTime;
        Valve valve1;
        SSRelay ssRelay1;
        CurrentSensor iSensor;
        VoltageSensor vSensor;
        PressureSensor pSensor;
        States state;
        Modes mode;
        Log * l;
        AutoPID pidControl;
        double voltageIn;
        double pidOut;
        double voltage_target = pid_voltage_target;
        unsigned long windowStartTime;

        int startCharging();
        int stopCharging();
        int forceStopCharging(); // Only to be called when master switch is flipped.
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
        void setLog(Log * logPtr) {l = logPtr; l->WriteToLog(1, "CAESObject logging initiated."); valve1.setLog(logPtr); ssRelay1.setLog(logPtr); iSensor.setLog(logPtr); vSensor.setLog(logPtr); pSensor.setLog(logPtr);
}
};
