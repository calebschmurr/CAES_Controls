// CAESObject.cpp

#include "CAESObject.h"


CAESObject::CAESObject() :  
    valve1(valve_open_pin, valve_close_pin),
    iSensor(current_sensor_pin),
    ssRelay1(solid_state_relay_pin), 
    vSensor(voltage_sensor_pin),
    pSensor(pressure_sensor_pin),
    pidControl(&voltageIn, &voltage_target, &pidOut, -pid_window_time, pid_window_time, pid_p_val, pid_i_val, pid_d_val) {
    cycleTime = 0;
    state = Off;
    pidControl.setTimeStep(pid_window_time/4); // Sampling Frequency
    //Set PID BangBang to not allow past a max voltage defined in config.h.
    pidControl.setBangBang(0, pid_max_voltage);
    
    windowStartTime = millis();
}

const int CAESObject::getState() {
    l->WriteToLog(3, "CAES System: reading state.");
    return state;
}

int CAESObject::getPressure() {
    l->WriteToLog(3, "CAES System: reading pressure sensor.");
    return pSensor.getValue();
}

int CAESObject::startCharging() {
    if (millis() > cycleTime) {
        l->WriteToLog(2, "CAES System: Started charging.");
        ssRelay1.on();
        cycleTime = millis() + min_cycle_time;
        state = Charging;
        return 0;
    }
    l->WriteToLog(1, "CAES System: Failed to start charging due to cycle time.");
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
    l->WriteToLog(1, "CAES System: Failed to stop charging due to cycle time.");
    return -1;
}

int CAESObject::forceStopCharging() {
  l->WriteToLog(1, "CAES System: Stopped charging by force.");
  ssRelay1.off();
  cycleTime = millis() + min_cycle_time;
  state = Off;
  return 0;
}

int CAESObject::startDischarging() {
     
    valve1.open();
    while(vSensor.getValue() < 0.5) {
        delay(30);
        valve1.hold();
        delay(100);
        valve1.open();
    }
    valve1.hold();
    delay(100);//Previously 500.  
    
    pidControl.reset(); // Resets internal PID calculation values (integral, derivative)

    state = Discharging;
    l->WriteToLog(1, "CAES System: Started Discharging");
    return 0;
}

int CAESObject::stopDischarging() {
    valve1.close();
    pidControl.stop(); // Stops PID calculations and resets internal PID calculation values (integral, derivative)
    state = Off;
    l->WriteToLog(1, "CAES System: Stopped Discharging");
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

int CAESObject::Discharge() {
    voltageIn = vSensor.getValue();
    unsigned long now = millis();
    switch (state) {
        case Discharging :
            pidControl.run(); // Automatically runs PID calculations. Will only actually perform calculations when time interval has passed.
            if (now - windowStartTime > pid_window_time) {
                windowStartTime = now;
                l->WriteToLog(3, "CAES System: PID output is:");
                l->WriteToLog(3, (String) pidOut);
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
