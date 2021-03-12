/*
*  Main.c - Main arduino file.
*
*
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
#include <Arduino.h>
#include "Thread.h"

// Declare and initialize variables

Valve valve1(1);
Log logFile;
SSRelay ssRelay1(2);
CurrentSensor iSensor(3);
VoltageSensor vSensor(4);
PressureSensor pSensor(5);


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
}