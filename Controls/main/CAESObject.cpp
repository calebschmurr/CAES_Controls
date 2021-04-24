// CAESObject.cpp

#include "CAESObject.h"


CAESObject::CAESObject() :  
    valve1(valve_open_pin, valve_close_pin),
    iSensor(current_sensor_pin),
    ssRelay1(solid_state_relay_pin), 
    vSensor(voltage_sensor_pin),
    pSensor(pressure_sensor_pin),
    pidControl(&voltageIn, &voltage_target, &pidOut, -pid_window_time, pid_window_time, 0.6, 0.2, 4.5) {
    cycleTime = 0;
    state = Off;
    //pidControl.setBangBang(8); //If the voltage is off by 6, then set to max or min.
    pidControl.setTimeStep(pid_window_time/4); // Sampling Frequency
    windowStartTime = millis();
    
}

const int CAESObject::getState() {
    l->WriteToLog(3, "CAES System: reading state.");
    return state;
}

int CAESObject::getPressure() {
    l->WriteToLog(3, "CAES System: reading pressure sensor.");
    return pSensor.getValue();
    //return 80;
}

int CAESObject::startCharging() {
    if (millis() > cycleTime) {
        l->WriteToLog(2, "CAES System: Started charging.");
        ssRelay1.on();
        cycleTime = millis() + min_cycle_time;
        state = Charging;
        return 0;
    }
    l->WriteToLog(2, "CAES System: startCharging failed due to cycle time.");
    return -1;
}

int CAESObject::stopCharging() {
    if (millis() > cycleTime) {
        l->WriteToLog(2, "CAES System: Stopped charging.");
        ssRelay1.off();
        cycleTime = millis() + min_cycle_time;
        state = Off;
        return 0;
    }
    l->WriteToLog(2, "CAES System: stopCharging failed due to cycle time.");
    return -1;
}

int CAESObject::forceStopCharging() {
  l->WriteToLog(2, "CAES System: forceStopCharging - charging system forced off.");
  ssRelay1.off();
  cycleTime = millis() + min_cycle_time;
  state = Off;
  return 0;
}

int CAESObject::startDischarging() {
    valve1.open();
    //Open the valve for 5 ms, delay 2 ms. Starter.
    /*
    int pressure = pSensor.getValue();
    if (pressure < 50){
      pressure = 50;
    }
    delay(40000/pressure);
    valve1.hold();
    delay(1000);
    */

    
    while(vSensor.getValue() < 2){
      delay(30);
      valve1.hold();
      delay(100);
      valve1.open();
    }
    valve1.hold();
    delay(500);
    
    pidControl.reset();
    pidControl.stop(); // Turn PID on

    state = Discharging;
    l->WriteToLog(2, "CAES System: startDischarging");
    return 0;
}

int CAESObject::stopDischarging() {
    valve1.close();
    pidControl.reset(); // Turn PID off
    state = Off;
    l->WriteToLog(2, "CAES System: stopDischarging");
    return 0;
}

int CAESObject::Charge() {
   int pressure = pSensor.getValue();
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

// https://playground.arduino.cc/Code/PIDLibraryRelayOutputExample/

int CAESObject::Discharge() {
    voltageIn = vSensor.getValue();
    String logMessage; // = "CAES System: PID output is: ";
    unsigned long now = millis();
    switch (state) {
        case Discharging :
            // PID Controlled Discharge
            if ( pidControl.run() ) {
                logMessage = (String) pidOut;
                l->WriteToLog(2, logMessage);
            }
            if (now - windowStartTime > pid_window_time) {
                windowStartTime = now;
            }
            if ( abs(pidOut) > now - windowStartTime ) {
                if ( pidOut > 0 ) {
                    valve1.open();
                } else if ( pidOut < 0 ) {
                    valve1.close();
                } else {
                    valve1.hold();
                }
            } else {
                valve1.hold();
            }
            break;
        case Charging :
            if (stopCharging() == 0) {
              startDischarging();
            }
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
            // Should add code to check for cycle time failure and not return 0 in that case
            break;
    }
    return 0; // Success
}

void CAESObject::ForceOff(){
  switch (state) {
    case Discharging : 
      stopDischarging();
      break;
    case Charging:
      forceStopCharging();
      break;
  }
}
