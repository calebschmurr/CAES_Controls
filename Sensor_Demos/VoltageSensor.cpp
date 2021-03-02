//VoltageSensor.cpp

VoltageSensor::VoltageSensor(const int pinVal){
    pin = pinVal;
}

float VoltageSensor::getValue(){
    return analogRead(pin)*multiplier;
}