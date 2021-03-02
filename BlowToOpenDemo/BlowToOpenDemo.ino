
int inc = 0;
class Sensor {
  int pin;
  int baseVal;
public:
  void set_pin(int pin_val){ pin = pin_val;
  pinMode(pin, INPUT);
  delay(300);
  for (inc = 0; inc<15; inc++){
    baseVal += analogRead(pin);
    delay(100);
  }
      baseVal = baseVal/15;
  }
  int getValue(){return analogRead(pin)-baseVal;}
};
class Valve{
  int OpenPin, ClosePin;
  
  void start_open(){
    // Changes relays to state that opens valve
    digitalWrite(OpenPin, LOW);
    digitalWrite(ClosePin, HIGH);
  }
  void start_close(){
    // Changes relays to state that closes valve
    digitalWrite(OpenPin, HIGH);
    digitalWrite(ClosePin, LOW);
  }
  void hold_position(){
    // Changes relays to state that holds the 
    // valve in its current position
    digitalWrite(OpenPin, HIGH);
    digitalWrite(ClosePin, HIGH);
  }
public:
  void set_pins(int Open_Pin, int Close_Pin){
    OpenPin = Open_Pin;
    ClosePin = Close_Pin;
    pinMode(OpenPin, OUTPUT);
    pinMode(ClosePin, OUTPUT);
    hold_position();
  }
  void open(){
    // Open valve all the way
    start_open();
    delay(5000);
    hold_position();
  }
  void open(int time){
    // Open valve for a set amount of time
    // Input: time - the time in ms to open for
    start_open();
    delay(time);
    hold_position();
  }
  void close(){
    // Close valve all the way
    start_close();
    delay(5000);
    hold_position();
  }
  void close(int time){
    // Close valve for a set amount of time
    // Input: time - the time in ms to close for
    start_close();
    delay(time);
    hold_position();
  }
};

const int relay1 = 4;
const int relay2 = 5;

//TODO - Add a power sensor to determine state of valve

Valve v;
Sensor p;

void setup() {
  // Initialize the control system
  v.set_pins(relay1, relay2);
  p.set_pin(A0);
  Serial.begin(9600);
}
int pVal;
void loop() {
  // put your main code here, to run repeatedly:
  pVal = p.getValue();
  if(pVal>10){
    v.open(200);
  }else{
    v.close(100);
  }
  
  Serial.println(pVal);

  

/*
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, LOW);
  delay(2000);
  
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  delay(2000);
  
  digitalWrite(relay1, LOW);
  digitalWrite(relay2, HIGH);
  delay(2000);
   digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  delay(2000);
  */
}
