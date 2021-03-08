//Log.h
//Handle log requests
#include <string>

class Log {
private:
    char name [20];

public:
    Log(char* input); //Open up a serial comms port
    int WriteToLog(const string msg);//Return  -1 if failed.
    bool closeLog();


};