/* log.h
* A class for logging important information
* before during and after Arduino code execution
* Calvin 2021 Senior Design Team 11
*/

#include <string.h>


class Log {
private:
    char name [20];

public:
    Log(char* input); //Open up a serial comms port
    int WriteToLog(const string msg);//Return  -1 if failed.
    bool closeLog();


};