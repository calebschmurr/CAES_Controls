// log.cpp

#include "log.h"
#include <string.h>

Log::Log() {}

int Log::WriteToLog(int level, String msg) {
    if (debug_level >= level) {
        String s;
        s += level;
        s += ": ";
        s += msg;
        Serial.println(s);
        // Here is a line of debugging code for when memory is low and logging messages don't print. When that is happening, this still prints.
        //Serial.println("^ Should be a logging message here...");
    }
    return 0;
}
