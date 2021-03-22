/* log.h
* A class for logging important information
* before during and after Arduino code execution
* Calvin 2021 Senior Design Team 11
*/
#pragma once
#include <string.h>
#include <Arduino.h>

class Log {
private:
    char name [20];

public:
    Log(char* input); //Open up a serial comms port
    int WriteToLog(const String msg);//Return  -1 if failed.
    bool closeLog();
};