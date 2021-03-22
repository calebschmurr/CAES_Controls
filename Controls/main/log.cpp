// log.cpp

#pragma once
#include "log.h"
#include <string.h>

Log::Log(){
  //  name = input.c_str();
 //   Serial.begin(115200);
}

int Log::WriteToLog(int level, const String msg){
    if (!Serial){
        return -1;
    }
    if (debug_level >= level){
        String s;
        s = millis();
        s += ": Level ";
        s += level;
        s += ": ";
        s += msg;
        Serial.println(s);
    }
    //Serial.printline(name.c_str()+" "+msg.c_str());
    return 0;
}

bool Log::closeLog(){
    Serial.end();
}
