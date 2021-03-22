/* Main.cpp
* The main code that executes when the
* Arduino boots up
* Calvin 2021 Senior Design Team 11
*/


// Custom classes
#pragma once
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
    //logFile.start();
    Serial.begin(115200);
    
}

void loop() {
    // Check and log sensor values
    updateSwitches();
    if (systemMode){

        if (debug_level > 2){
            Serial.println(millis() + ": LEVEL 3: loop auto_mode is on.");
        }

        //Auto
        if (caesSystem.getState()==Charging){
        
         if (debug_level > 2){
            Serial.println(millis() + ": LEVEL 3: Loop state is in charging.");
        }
            if (caesSystem.getPressure() < max_pressure_auto){
                caesSystem.Charge();
                if (debug_level > 1){
                    Serial.println(millis() + ": LEVEL 2: System told to charge.");
                }

            } else {
                caesSystem.Discharge();
                if (debug_level > 1){
                    Serial.println(millis() + ": LEVEL 2: System told to discharge.");
                }


            }
        } else {
            if (caesSystem.getState()==Discharging){
                if (caesSystem.getPressure() < min_pressure_auto){
                    caesSystem.Charge();
                    if (debug_level > 1){
                        Serial.println(millis() + ": LEVEL 2: System told to charge.");
                    }
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
        if (manualState==Charging){
            caesSystem.Charge();
        }else if (manualState==Discharging){
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
        manualState = Charging;
    } else if (digitalRead(manual_switch_discharge)){
        manualState = Discharging;
    } else {
        manualState = Off;
    }
}