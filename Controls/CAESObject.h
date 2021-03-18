/* CAESObject.h
* A class for reading from a current sensor
* Calvin 2021 Senior Design Team 11
*/

#include "CurrentSensor.h"
#include "VoltageSensor.h"
#include "PressureSensor.h"
#include "log.h"
#include "Valve.h"
#include "SSRelay.h"
#include "config.h"


class CAESObject {
    private:
        int cycleTime;
        Valve valve1;
        Log logFile;
        SSRelay ssRelay1;
        CurrentSensor iSensor;
        VoltageSensor vSensor;
        PressureSensor pSensor;
        enum States{ Off, Charging, Discharging } state;
        void startCharging();
        void stopCharging();
        void startDischarging();
        void stopDischarging();

    public:
        CAESObject();
        int Charge();
        int Discharge();
        int TurnOff();
};