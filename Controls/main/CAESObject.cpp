// CAESObject.cpp

#include "CAESObject.h"


CAESObject::CAESObject() :  
    valve1(valve_open_pin, valve_close_pin),
    iSensor(current_sensor_pin),
    ssRelay1(solid_state_relay_pin), 
    vSensor(voltage_sensor_pin),
    pSensor(pressure_sensor_pin) 
{
    cycleTime = min_cycle_time;
    state = Off;
}

void CAESObject::incrementCycleTime(){
  cycleTime += 1;
}

const int CAESObject::getState() {
    l->WriteToLog(3, "CAES System: reading state.");
    return state;
}

int CAESObject::getPressure() {
    l->WriteToLog(3, "CAES System: reading pressure sensor.");
    return pSensor.getValue();
    return 80;
}

void CAESObject::startCharging() {
    if (cycleTime > min_cycle_time) {
        l->WriteToLog(2, "CAES System: Started charging.");
        ssRelay1.on();
        cycleTime = 0;
        state = Charging;
    }
    l->WriteToLog(2, "CAES System: startCharging failed due to cycle time.");
   // cycleTime += 1;
}

void CAESObject::stopCharging() {
    if (cycleTime > min_cycle_time) {
        l->WriteToLog(2, "CAES System: Stopped charging.");
        ssRelay1.off();
        cycleTime = 0;
        state = Off;
    }
    l->WriteToLog(2, "CAES System: stopCharging failed due to cycle time..");

   // cycleTime += 1;
}

void CAESObject::startDischarging() {
    valve1.open();
    state = Discharging;
}

void CAESObject::stopDischarging() {
    valve1.close();
    state = Off;
}

int CAESObject::Charge() {
   //int pressure = pSensor.getValue();
   int pressure = 0;
    switch (state) {
        case Discharging :
            stopDischarging();
            if (pressure < max_pressure_auto) {
                startCharging();
            } break;
        case Charging :
            if (pressure >= max_pressure_auto) {
                stopCharging();
            } break;
        case Off :
            if (pressure < max_pressure_auto) {
                startCharging();
            } break;
    }
    return 0; // Success
}

int CAESObject::Discharge() {
    int voltage = vSensor.getValue();
    //int voltage = 0;
    switch (state) {
        case Discharging :
            stopDischarging();
            if (voltage < voltage_lower_bound) { 
                valve1.open();
            } else if (voltage > voltage_upper_bound) { // I used a string so that it is red and we remember to change it
                valve1.close();
            } else {
                valve1.hold();
            } break;
        case Charging :
            stopCharging();
            startDischarging();
            break;
        case Off :
            startDischarging();
            break;
    }
    return 0; // Success
}

int CAESObject::TurnOff() {
    switch (state) {
        case Discharging :
            stopDischarging();
            break;
        case Charging :
            stopCharging();
            break;
    }
    return 0; // Success
}
