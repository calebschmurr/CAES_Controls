/* Main.cpp
* The main code that executes when the
* Arduino boots up
* Calvin 2021 Senior Design Team 11
*/


// Custom classes
#include "CurrentSensor.h"
#include "VoltageSensor.h"
#include "PressureSensor.h"
#include "log.h"
#include "Valve.h"
#include "SSRelay.h"
#include "config.h"

// External classes
#include <Arduino.h> // Arduino Library
//#include <TimedAction.h> // Threading Library


// Declare and initialize variables
Valve valve1(1);
Log logFile;
SSRelay ssRelay1(2);
CurrentSensor iSensor(3);
VoltageSensor vSensor(4);
PressureSensor pSensor(5);


//https://create.arduino.cc/projecthub/reanimationxp/how-to-multithread-an-arduino-protothreading-tutorial-dd2c37

// Threading stuff commented out for now
//TimedAction ssrThread = TimedAction(200, SSR_Loop);
//TimedAction valveThread = TimedAction(200, Valve_Control_Loop);



void setup() {
    // Start logging
    logFile.start();

    // Initialize the valve, sensors, and relay
    valve1.initialize();
    ssRelay1.initialize();
    iSensor.initialize();
    vSensor.initialize();
    pSensor.initialize();
    
    // Start a bunch of threads
}

void loop() {
    // Check and log sensor values
    // Send messages to threads with mutex or some kind of interprocess communication
    ssrThread.check();
    valveThread.check();

}
