/* Main.cpp
* The main code that executes when the
* Arduino boots up
* Calvin 2021 Senior Design Team 11
*/


// Custom classes
#pragma once
#include "config.h"
#include "CAESObject.h"

#include "log.h"

// External classes
#include <Arduino.h> // Arduino Library
//#include <TimedAction.h> // Threading Library

// Declare and initialize variables


Log l;
CAESObject caesSystem;

int systemMode = 0;
int manualState = 0;

void setup() {
    // Start logging
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Serial_Start");
    l.setStream(&Serial);
    
    l.WriteToLog(1, "Test_File");
    caesSystem.setSerial(&Serial);
}

void loop() {
    /*// Check and log sensor values
    updateSwitches();
    if (systemMode){

        l.WriteToLog(3, "System Mode is Auto.");

        //Auto
        if (caesSystem.getState()==Charging){
            
            l.WriteToLog(3, "System is read as in mode charging.");

            if (caesSystem.getPressure() < max_pressure_auto){
                caesSystem.Charge();
                l.WriteToLog(2, "System mode is set to charging.");

            } else {
                caesSystem.Discharge();
                l.WriteToLog(2, "System mode is set to discharging.");
            }
        } else {
            if (caesSystem.getState()==Discharging){
                if (caesSystem.getPressure() < min_pressure_auto){
                    caesSystem.Charge();
                    l.WriteToLog(2, "System set to charge.");
                } else {
                    caesSystem.Discharge();
                    l.WriteToLog(2, "System set to discharge.");
                }
            }else {
                //Default Behavior.
                //For now - discharge.
                caesSystem.Discharge();
                l.WriteToLog(2, "System set to discharge.");
            }
        }

    } else {
        l.WriteToLog(3, "System read as in manual mode.");
        if (manualState==Charging){
            caesSystem.Charge();
            l.WriteToLog(2, "System mode is set to Charging in manual mode.");
        }else if (manualState==Discharging){
            caesSystem.Discharge();
            l.WriteToLog(2, "System mode is set to Discharging in manual mode.");

        } else {
            caesSystem.TurnOff();
            l.WriteToLog(2, "System is off in manual mode.");
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
    */
}
