//log.cpp
//3-8-21
#include "log.h"

Log::Log(char* input){
    name = input.c_str();
    Serial.begin(9600);
}

int Log::WriteToLog(const string msg){
    if (!Serial){
        return -1;
    }
    Serial.printline(name.c_str()+" "+msg.c_str());
    return 0;
}

bool Log::closeLog(){
    Serial.end()
}