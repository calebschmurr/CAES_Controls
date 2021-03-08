/* SSRelay.h
* A class for controlling the Solid State Relay
* that turns the compressor off and on
* Calvin 2021 Senior Design Team 11
* 3/8/21
*/

class SSRelay {
private:
    int pin;
    // TODO: position tracking and/or ?fully_open

public:
    Valve(const int pinVal);
    int MoveIncrement(int i);
};