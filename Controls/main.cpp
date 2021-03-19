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


CAESObject caesSystem;

int systemMode = 0;
int manualState = 0;

void setup() {
    // Start logging
    logFile.start();

    
}

void loop() {
    // Check and log sensor values
    updateSwitches();
    if (systemMode){
        //Auto
        if (caesSystem.getState()==state.Charging){
            if (caesSystem.getPressure() < max_pressure_auto){
                caesSystem.Charge();
            } else {
                caesSystem.Discharge();
            }
        } else {
            if (caesSystem.getState()==state.Discharging){
                if (caesSystem.getPressure() < min_pressure_auto){
                    caesSystem.Charge();
                } else {
                    caesSystem.Discharge();
                }
            }else {
                //Default Behavior.
                //For now - discharge.
                caesSystem.Discharge();
            }
        }

    } else {
        if (manualState==mode.Charging){
            caesSystem.Charge();
        }else if (manualState==mode.Discharging){
            caesSystem.Discharge();
        } else {
            caesSystem.TurnOff();
        }
    }
    //End of loop. Reloop.
}


void updateSwitches(){
    systemMode = digitalRead(mode_switch);
    
    if (digitalRead(manual_switch_charge)){
        manualState = mode.Charging;
    } else if (digitalRead(manual_switch_discharge)){
        manualState = mode.Discharging;
    } else {
        manualState = mode.Off;
    }
}