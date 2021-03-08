/* Valve.h
* A class for controlling the motorized valve
* on the output of the compressed-air tank
* Calvin 2021 Senior Design Team 11
* 3/8/21
*/

class Valve {
private:
    int pin;
    // TODO: position tracking and/or ?fully_open

public:
    Valve(const int pinVal);
    int MoveIncrement(int i);
};