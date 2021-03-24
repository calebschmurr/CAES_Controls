/* log.h
* A class for logging important information
* before during and after Arduino code execution
* Calvin 2021 Senior Design Team 11
*/
#pragma once
#include <string.h>
#include <Arduino.h>
#include "config.h"

using namespace std;

class Log {
private:
    char name [20];
    Stream* _StreamRef;
public:
    Log(); 
    void setStream(Stream *streamObject) { _StreamRef = streamObject; }
    int WriteToLog(int level, String msg);  //Return  -1 if failed.
    bool closeLog();
};
