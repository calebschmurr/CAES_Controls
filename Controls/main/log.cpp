// log.cpp

#include "log.h"
#include <string.h>

Log::Log() {
  // TODO: anything here?
  // Should the log tell us when it is properly initialized?
}

int Log::WriteToLog(int level, const String msg) {

    if (debug_level >= level) {
        String s;
        s = millis();
        s += ": Level ";
        s += level;
        s += ": ";
        s += msg;
        _StreamRef->println(s);
    }
    //Serial.printline(name.c_str()+" "+msg.c_str());
    return 0;
}

// Is this function actually needed? When would we use it?
bool Log::closeLog() {
    Serial.end();
}
