/* SSRelay.h
* A class for controlling the Solid State Relay
* that turns the compressor off and on
* Calvin 2021 Senior Design Team 11
*/

class SSRelay {
private:
    int pin;
    bool state;
    // TODO: position tracking and/or ?fully_open

public:
    SSRelay(const int pinVal);
    int SetState(bool stateVal);
    bool GetState();
};