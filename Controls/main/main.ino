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
    caesSystem.setLog(&l); // TODO? Context pass the Log variable, not the stream object to make it easier.

    pinMode(mode_switch_pin, INPUT);
    pinMode(manual_switch_charge_pin, INPUT);
    pinMode(manual_switch_discharge_pin, INPUT);
}

void loop() {
    // Check and log sensor values
    updateSwitches();
    if (systemMode) { // Auto Mode

        l.WriteToLog(3, "Main: Mode switch is set to Auto.");

        if (caesSystem.getState() == Charging) { // Charging State
            
            l.WriteToLog(3, "Main.Auto: System state is Charging.");

            if (caesSystem.getPressure() < max_pressure_auto) {
                l.WriteToLog(2, "Main.Auto: Sending charge command to system.");
                // caesSystem.Charge();
            } else {
                l.WriteToLog(2, "Main.Auto: Sending discharge command to system.");
                // caesSystem.Discharge();
            }
        } else {
            if (caesSystem.getState() == Discharging) {
                if (caesSystem.getPressure() < min_pressure_auto) {
                    l.WriteToLog(2, "Main.Auto: Sending charge command to system.");
                    // caesSystem.Charge();
                } else {
                    l.WriteToLog(2, "Main.Auto: Sending discharge command to system.");
                    // caesSystem.Discharge();
                }
            } else {
                l.WriteToLog(3, "Main.Auto: System state is Off.");
                // Default Behavior - For now it is Discharge()
                l.WriteToLog(2, "Main.Auto: Sending discharge command to system.");
                // caesSystem.Discharge();
            }
        }

    } else { // Manual Mode

        l.WriteToLog(3, "Main: Mode switch is set to Manual.");

        if (manualState == Charging) {
            l.WriteToLog(3, "Main.Manual: Manual state switch is set to Charge.");
            l.WriteToLog(2, "Main.Manual: Sending charge command to system.");
            // caesSystem.Charge();
        } else if (manualState == Discharging) {
            l.WriteToLog(3, "Main.Manual: Manual state switch is set to Discharge.");
            l.WriteToLog(2, "Main.Manual: Sending discharge command to system.");
            // caesSystem.Discharge();
        } else {
            l.WriteToLog(3, "Main.Manual: Manual state switch is set to Off.");
            l.WriteToLog(2, "Main.Manual: Sending off command to system.");
            // caesSystem.TurnOff();
        }
    }
}


void updateSwitches() {

    systemMode = digitalRead(mode_switch_pin);
    
    // TODO: We should probably check for the possibility that 
    // both switches are high and raise an exception
    if ( digitalRead(manual_switch_charge_pin) ) {
        manualState = Charging;
    } else if ( digitalRead(manual_switch_discharge_pin) ) {
        manualState = Discharging;
    } else {
        manualState = Off;
    }
}
