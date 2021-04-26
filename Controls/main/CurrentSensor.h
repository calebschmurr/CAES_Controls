/* CurrentSensor.h
* A class for reading from a current sensor
* Calvin 2021 Senior Design Team 11
*/

#include "log.h"

class CurrentSensor {
private:
    // If variables with these names will be used by every
    // sensor they should be declared in sensor.h right?
    int pin;
    //TODO: Determine multiplier.
    float multiplier = 0.5f;
    int baseVal;
    Log * l;
    
    
public:
    CurrentSensor(const int pinVal);
    float getValue();
    void setLog(Log * logPtr){ l = logPtr; l->WriteToLog(1, "Current Sensor logging initiated."); }
  };
