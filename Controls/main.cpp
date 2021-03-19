/* Main.cpp
* The main code that executes when the
* Arduino boots up
* Calvin 2021 Senior Design Team 11
*/


// Custom classes
#include "config.h"

#include "CAESObject.h"

// External classes
#include <Arduino.h> // Arduino Library
//#include <TimedAction.h> // Threading Library


// Declare and initialize variables


CAESObject caes_system;

int _mode = 0;
int _man_mode = 0;

void setup() {
    // Start logging
    logFile.start();

    
}

void loop() {
    // Check and log sensor values
    updateSwitches();
    if (_mode){
        //Auto
        if (caes_system.getState()==state.Charging){
            if (caes_system.getPressure() < max_pressure_auto){
                caes_system.Charge();
            } else {
                caes_system.Discharge();
            }
        } else {
            if (caes_system.getState()==state.Discharging){
                if (caes_system.getPressure() < min_pressure_auto){
                    caes_system.Charge();
                } else {
                    caes_system.Discharge();
                }
            }else {
                //Default Behavior.
                //For now - discharge.
                caes_system.Discharge();
            }
        }

    } else {
        if (_man_mode==mode.Charging){
            caes_system.Charge();
        }else if (_man_mode==mode.Discharging){
            caes_system.Discharge();
        } else {
            caes_system.TurnOff();
        }
    }
    //End of loop. Reloop.
}


void updateSwitches(){
    _mode = digitalRead(mode_switch);
    
    if (digitalRead(manual_switch_charge)){
        _man_mode = mode.Charging;
    } else if (digitalRead(manual_switch_discharge)){
        _man_mode = mode.Discharging;
    } else {
        _man_mode = mode.Off;
    }
}