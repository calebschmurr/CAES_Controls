/* Main.cpp
* The main code that executes when the
* Arduino boots up
* Calvin 2021 Senior Design Team 11
*/

// Custom classes
#include "config.h"
#include "CAESObject.h"
#include "log.h"

// Declare and initialize variables
Log l;
CAESObject caesSystem; 

Modes systemMode;
States manualState;
enum masterOnOff {MasterOff, MasterOn} systemMasterOnOff;


void setup() {
    // Start logging
    Serial.begin(9600);
    Serial.println("Serial_Start");
    l.setStream(&Serial);
    l.WriteToLog(1, "Log_Start");

    caesSystem.setLog(&l);

    // Digital pullup on all switch pins
    pinMode(mode_switch_pin, INPUT_PULLUP);
    pinMode(master_on_off_switch_pin, INPUT_PULLUP);
    pinMode(manual_switch_charge_pin, INPUT_PULLUP);
    pinMode(manual_switch_discharge_pin, INPUT_PULLUP);
    l.WriteToLog(2, "Set Pullup Pins");

}

void loop() {
    updateSwitches();
    l.WriteToLog(3, "Main: Reading Switch Values");

    if (systemMasterOnOff == MasterOn) { // TODO: fix indentation
    
    if (systemMode == Auto) {

        l.WriteToLog(3, "Main: Mode switch is set to Auto.");
        
        if (caesSystem.getState() == Charging) {
          
            l.WriteToLog(3, "Main.Auto: System state is Charging.");

            if (caesSystem.getPressure() < max_pressure_auto - 2) {
                l.WriteToLog(1, "Main.Auto: Sending charge command to system.");
                 caesSystem.Charge();
            } else {
                l.WriteToLog(1, "Main.Auto: Sending discharge command to system.");
                 caesSystem.Discharge();
            }
        } else if (caesSystem.getState() == Discharging) {
            if (caesSystem.getPressure() < min_pressure_auto) {
                l.WriteToLog(1, "Main.Auto: Sending charge command to system.");
                 caesSystem.Charge();
            } else {
                l.WriteToLog(1, "Main.Auto: Sending discharge command to system.");
                 caesSystem.Discharge();
            }
        } else {
            l.WriteToLog(3, "Main.Auto: System state is Off.");
            // Default Behavior - For now it is Discharge()
            if (caesSystem.getPressure() < max_pressure_auto) {
                l.WriteToLog(1, "Main.Auto: Sending charge command to system.");
                caesSystem.Charge();
            } else {
                l.WriteToLog(1, "Main.Auto: Sending discharge command to system.");
                caesSystem.Discharge();
            }
        }
    } else { // Manual Mode
        l.WriteToLog(3, "Main: Mode switch is set to Manual.");
        
        if (manualState == Charging) {
            l.WriteToLog(3, "Main.Manual: Manual state switch is set to Charge.");
            l.WriteToLog(3, "Main.Manual: Sending charge command to system.");
            caesSystem.Charge();
        } else if (manualState == Discharging) {
            l.WriteToLog(3, "Main.Manual: Manual state switch is set to Discharge.");
            l.WriteToLog(3, "Main.Manual: Sending discharge command to system.");
            caesSystem.Discharge();
        } else {
            l.WriteToLog(3, "Main.Manual: Manual state switch is set to Off.");
            l.WriteToLog(3, "Main.Manual: Sending off command to system.");
            caesSystem.TurnOff();
        }
    }
  } else { // Master switch is off:
  caesSystem.ForceOff();
  }
}


void updateSwitches() {

    if (digitalRead(mode_switch_pin) == 0) {
        l.WriteToLog(3, "Main: Mode switch is set to Manual");
        systemMode = Manual;
    } else {
        l.WriteToLog(3, "Main: Mode switch is set to Auto");
        systemMode = Auto;
    }

    // TODO: We should probably check for the possibility that 
    // both switches are high and raise an exception, 
    // or we could just default to Off in that case
    if (digitalRead(manual_switch_charge_pin) == LOW) {
        l.WriteToLog(3, "Main: State switch is set to Charging");
        manualState = Charging;
    } else if (digitalRead(manual_switch_discharge_pin) == LOW) {
        l.WriteToLog(3, "Main: State switch is set to Discharging");
        manualState = Discharging;
    } else {
        l.WriteToLog(3, "Main: State switch is set to Off");
        manualState = Off;
    }

    if(digitalRead(master_on_off_switch_pin) == HIGH) {
        l.WriteToLog(3, "Main: Master switch is set to Off");
        systemMasterOnOff = MasterOff;
    } else {
        l.WriteToLog(3, "Main: Master switch is set to On");
        systemMasterOnOff = MasterOn;
    }
}
